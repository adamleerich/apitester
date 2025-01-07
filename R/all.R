#' Wrapper of Rf_isReal
#'
#' @description
#' Interact with Rf_isReal from R
#'
#' @param	x      any SEXP object
#'
#' @return
#' A logical vector of length one
#' TRUE if x is real, FALSE otherwise
#'
#' @examples
#' isReal(1L)
#' isReal(-12.3)
#' isReal("A String")
#'
isReal <- function(x) {
  .Call(Cinternal__isReal, x)
}

#' Wrapper of TYPEOF
#'
#' @description
#' Interact with TYPEOF from R
#'
#' @param	x      any SEXP object
#'
#' @return
#' An integer vector of length one
#' encoding the numeric type value of x as an SEXP
#'
#' @examples
#' TYPEOF(1L)
#' TYPEOF(-12.3)
#' TYPEOF("A String")
#'
TYPEOF <- function(x) {
  .Call(Cinternal__TYPEOF, x)
}

#' Wrapper of Rf_type2str
#'
#' @description
#' Interact with Rf_type2str from R
#'
#' @param	x      any SEXP object
#'
#' @return
#' A character vector of length one
#' with the value returned by Rf_type2str.
#'
#' @examples
#' type2str(1L)
#' type2str(-12.3)
#' type2str("A String")
#'
type2str <- function(x) {
  .Call(Cinternal__type2str, x)
}

#' Wrapper of TYPEOF with extras
#'
#' @description
#' Get information about the type of an R object
#'
#' @param	x      any SEXP object
#'
#' @return
#' A list of TYPEOF, Rf_type2str, and the constant symbol representing TYPEOF
#'
#' @examples
#' TYPEOF_list(1L)
#' TYPEOF_list(-12.3)
#' TYPEOF_list("A String")
#'
TYPEOF_list <- function(x) {
  .Call(Cinternal__TYPEOF_list, x)
}

#' #' Get a new object
#' #'
#' #' @description
#' #' Get a SEXP by integer value corresponding to SEXPTYPE
#' #'
#' #' @param	x      an integer
#' #'
#' #' @return
#' #' A simple object of the correct type
#' #'
#' #' @examples
#' #' new_SEXP(1)
#' #' new_SEXP(2)
#' #' new_SEXP(3)
#' #'
#' new_SEXP <- function(x) {
#'   .Call(Cinternal__new_SEXP, x)
#' }
