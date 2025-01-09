// gcc -o test_r_api test_r_api.c -I/path/to/R/include -L/path/to/R/lib -lR

#include <R.h>
#include <Rinternals.h>
#include <Rembedded.h>  // For initializing the R environment
#include "unity.h"

// Setup and teardown functions for R
void setUp(void) {
    char *argv[] = {"R", "--vanilla"};
    Rf_initEmbeddedR(2, argv);  // Initialize an embedded R session
}

void tearDown(void) {
    Rf_endEmbeddedR(0);  // Clean up the R session
}

// Test creating an integer vector
void test_create_integer_vector(void) {
    SEXP vec = PROTECT(allocVector(INTSXP, 3));
    INTEGER(vec)[0] = 10;
    INTEGER(vec)[1] = 20;
    INTEGER(vec)[2] = 30;

    TEST_ASSERT_EQUAL_INT(10, INTEGER(vec)[0]);
    TEST_ASSERT_EQUAL_INT(20, INTEGER(vec)[1]);
    TEST_ASSERT_EQUAL_INT(30, INTEGER(vec)[2]);

    UNPROTECT(1);
}

// Test creating a character vector
void test_create_character_vector(void) {
    SEXP vec = PROTECT(allocVector(STRSXP, 2));
    SET_STRING_ELT(vec, 0, mkChar("Hello"));
    SET_STRING_ELT(vec, 1, mkChar("World"));

    TEST_ASSERT_EQUAL_STRING("Hello", CHAR(STRING_ELT(vec, 0)));
    TEST_ASSERT_EQUAL_STRING("World", CHAR(STRING_ELT(vec, 1)));

    UNPROTECT(1);
}

// Test evaluating a simple R expression
void test_evaluate_expression(void) {
    SEXP expr = PROTECT(Rf_mkString("1 + 1"));
    SEXP parsed = PROTECT(R_ParseVector(expr, -1, NULL, R_NilValue));
    SEXP result = PROTECT(Rf_eval(VECTOR_ELT(parsed, 0), R_GlobalEnv));

    TEST_ASSERT_EQUAL_INT(2, INTEGER(result)[0]);

    UNPROTECT(3);
}

// Main function to run all tests
int main(void) {
    UNITY_BEGIN();

    RUN_TEST(test_create_integer_vector);
    RUN_TEST(test_create_character_vector);
    RUN_TEST(test_evaluate_expression);

    return UNITY_END();
}

