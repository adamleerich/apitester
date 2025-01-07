#' @export
isReal <- function(x) {
  .Call("Rapi__isReal", x)
}

#' @export
TYPEOF <- function(x) {
  .Call("Rapi__TYPEOF", x)
}

#' @export
type2str <- function(x) {
  .Call("Rapi__type2str", x)
}

#' @export
TYPEOF_list <- function(x) {
  .Call("Rapi__TYPEOF_list", x)
}

new_SEXP <- function(x) {
  .Call("new_SEXP", x)
}
