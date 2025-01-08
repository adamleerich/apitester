#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "../../src/simple.c"



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


static void zero_is_zero() {return assert_true(0 == 0);}
static void one_is_one() {return assert_true(1 == 1);}

int main(void)
{
    const struct CMUnitTest tests[] = {
        cmocka_unit_test(zero_is_zero),
        cmocka_unit_test(one_is_one)
    };

    return cmocka_run_group_tests(tests, NULL, NULL);
}

