#include <Rinternals.h>
#include <R_ext/Visibility.h>
#include <R_ext/Rdynload.h>
#include "simple.h"

#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}

static const R_CallMethodDef R_CallDef[] = {
    CALLDEF(internal__isReal, 1),
    CALLDEF(internal__TYPEOF, 1),
    CALLDEF(internal__type2str, 1),
    CALLDEF(internal__TYPEOF_list, 1),
    // CALLDEF(internal__new_SEXP, 1),
    {NULL, NULL, 0}
};

void attribute_visible R_init_apitester(DllInfo *dll)
{
    R_registerRoutines(dll, NULL, R_CallDef, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
    R_forceSymbols(dll, TRUE);
}
