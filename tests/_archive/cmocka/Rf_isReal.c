#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>

#include <Rinternals.h>
#include <R_ext/Parse.h>
#include <Rembedded.h>

// #include "../../src/simple.c"

// // #define TEST(name)  {#name, (DL_FUNC) &name, n}

// /* A test case that does nothing and succeeds. */
// static void null_test_success(void **state)
// {
//     (void)state; /* unused */
//     PROTECT(Rf_allocVector(REALSXP, 1));

// }

// INTSXP

// LGLSXP
// NILSXP
// RAWSXP
// CPLXSXP
// STRSXP
// EXPRSXP
// VECSXP
// LANGSXP
// LISTSXP
// intCHARSXP

static void zero_is_zero() { return assert_true(0 == 0); }
static void one_is_one() { return assert_true(1 == 1); }
static void sexp_is_real() {
    SEXP x = PROTECT(Rf_allocVector(REALSXP, 1));
    // Rf_PrintValue(x);
    UNPROTECT(1);
    return assert_true(Rf_isReal(x));
}

int main(int argc, char **argv) {
    Rf_initEmbeddedR(argc, argv);

    const struct CMUnitTest tests[] = {
        cmocka_unit_test(zero_is_zero),
        cmocka_unit_test(one_is_one),
        cmocka_unit_test(sexp_is_real)};

    Rf_endEmbeddedR(0);

    return cmocka_run_group_tests(tests, NULL, NULL);
}


