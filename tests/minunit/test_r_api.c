#include <R.h>
#include <Rinternals.h>
#include <Rembedded.h>
#include "minunit.h"

// Global variables for setup/teardown
char *argv[] = {"R", "--vanilla"};

// Setup function to initialize the R environment
void test_setup(void) {
    Rf_initEmbeddedR(2, argv);
}

// Teardown function to clean up the R environment
void test_teardown(void) {
    Rf_endEmbeddedR(0);
}

// Test creating an integer vector
MU_TEST(test_create_integer_vector) {
    SEXP vec = PROTECT(allocVector(INTSXP, 3));
    INTEGER(vec)[0] = 10;
    INTEGER(vec)[1] = 20;
    INTEGER(vec)[2] = 30;

    mu_assert_int_eq(10, INTEGER(vec)[0]);
    mu_assert_int_eq(20, INTEGER(vec)[1]);
    mu_assert_int_eq(30, INTEGER(vec)[2]);

    UNPROTECT(1);
}

// Test creating a character vector
MU_TEST(test_create_character_vector) {
    SEXP vec = PROTECT(allocVector(STRSXP, 2));
    SET_STRING_ELT(vec, 0, mkChar("Hello"));
    SET_STRING_ELT(vec, 1, mkChar("World"));

    mu_assert_string_eq("Hello", CHAR(STRING_ELT(vec, 0)));
    mu_assert_string_eq("World", CHAR(STRING_ELT(vec, 1)));

    UNPROTECT(1);
}

// // Test evaluating a simple R expression
// MU_TEST(test_evaluate_expression) {
//     SEXP expr = PROTECT(Rf_mkString("1 + 1"));
//     SEXP parsed = PROTECT(R_ParseVector(expr, -1, NULL, R_NilValue));
//     SEXP result = PROTECT(Rf_eval(VECTOR_ELT(parsed, 0), R_GlobalEnv));

//     mu_assert_int_eq(2, INTEGER(result)[0]);

//     UNPROTECT(3);
// }

// Test suite
MU_TEST_SUITE(test_suite) {
    test_setup();

    MU_RUN_TEST(test_create_integer_vector);
    MU_RUN_TEST(test_create_character_vector);
    // MU_RUN_TEST(test_evaluate_expression);

    test_teardown();
}

// Main function to run the tests
int main(void) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
