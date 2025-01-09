// gcc -o test_r_api test_r_api.c -I/path/to/R/include -L/path/to/R/lib -lR -lcheck

#include <R.h>
#include <Rinternals.h>
#include <Rembedded.h>
#include <check.h>

// Setup function to initialize the R environment
void setup(void) {
    char *argv[] = {"R", "--vanilla"};
    Rf_initEmbeddedR(2, argv);
}

// Teardown function to clean up the R environment
void teardown(void) {
    Rf_endEmbeddedR(0);
}

// Test creating an integer vector
START_TEST(test_create_integer_vector) {
    SEXP vec = PROTECT(allocVector(INTSXP, 3));
    INTEGER(vec)[0] = 10;
    INTEGER(vec)[1] = 20;
    INTEGER(vec)[2] = 30;

    ck_assert_int_eq(INTEGER(vec)[0], 10);
    ck_assert_int_eq(INTEGER(vec)[1], 20);
    ck_assert_int_eq(INTEGER(vec)[2], 30);

    UNPROTECT(1);
}
END_TEST

// Test creating a character vector
START_TEST(test_create_character_vector) {
    SEXP vec = PROTECT(allocVector(STRSXP, 2));
    SET_STRING_ELT(vec, 0, mkChar("Hello"));
    SET_STRING_ELT(vec, 1, mkChar("World"));

    ck_assert_str_eq(CHAR(STRING_ELT(vec, 0)), "Hello");
    ck_assert_str_eq(CHAR(STRING_ELT(vec, 1)), "World");

    UNPROTECT(1);
}
END_TEST

// Test evaluating a simple R expression
START_TEST(test_evaluate_expression) {
    SEXP expr = PROTECT(Rf_mkString("1 + 1"));
    SEXP parsed = PROTECT(R_ParseVector(expr, -1, NULL, R_NilValue));
    SEXP result = PROTECT(Rf_eval(VECTOR_ELT(parsed, 0), R_GlobalEnv));

    ck_assert_int_eq(INTEGER(result)[0], 2);

    UNPROTECT(3);
}
END_TEST

// Suite creation
Suite *r_api_suite(void) {
    Suite *s = suite_create("R API");

    TCase *tc_core = tcase_create("Core");
    tcase_add_checked_fixture(tc_core, setup, teardown);

    tcase_add_test(tc_core, test_create_integer_vector);
    tcase_add_test(tc_core, test_create_character_vector);
    tcase_add_test(tc_core, test_evaluate_expression);

    suite_add_tcase(s, tc_core);
    return s;
}

// Main function to run the tests
int main(void) {
    int number_failed;
    Suite *s = r_api_suite();
    SRunner *sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? 0 : 1;
}
