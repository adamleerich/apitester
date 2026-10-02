# API Tester Package

Goal: write a package that uses every part of the R API to understand how it works.
Documentation via usage perhaps?

## Reference Material

Core R Manuals: 
* https://rstudio.github.io/r-manuals/r-lang/
* https://rstudio.github.io/r-manuals/r-exts/
* https://rstudio.github.io/r-manuals/r-ints/

Advanced R Book:
* http://adv-r.had.co.nz/
* http://adv-r.had.co.nz/C-interface.html

R Packages Book:
* https://r-pkgs.org/



## All environment variables that R cares about

1. R_MAKEVARS_SITE
1. R_MAKEVARS_USER
1. R_PACKAGE_NAME 
1. R_PACKAGE_SOURCE 
1. R_PACKAGE_DIR 
1. R_ARCH 
1. SHLIB_EXT 
1. WINDOWS 
1. R_HOME
1. R_PLATFORM
1. R_PAPERSIZE_USER
1. R_PAPERSIZE
1. R_PRINTCMD
1. R_RD4PDF
1. R_TEXI2DVICMD
1. R_GZIPCMD
1. R_UNZIPCMD
1. R_ZIPCMD
1. R_BZIPCMD
1. R_BROWSER
1. EDITOR
1. PAGER
1. R_PDFVIEWER
1. LN_S
1. MAKE
1. SED
1. TAR
1. R_STRIP_SHARED_LIB
1. R_STRIP_STATIC_LIB
1. R_LIBS_USER
1. R_LIBS_SITE
1. LD_LIBRARY_PATH 
1. TMPDIR 




## Other things to learn about

* IGNORE_RDIFF
* zapsmall
* loading package namespaces but not attaching them by using requireNamespace(pkg, quietly = TRUE) and using pkg:: to refer to objects in the namespace
* Learn more about Autoconf: https://rstudio.github.io/r-manuals/r-exts/Creating-R-packages.html#FOOT30
* Static libraries, dynamic libraries, shared libraries, etc.
* unsatisfied entry points in compiled code





## Packages to learn from 

WriteXLS/inst/Perl
NMF/inst/m-files
RnavGraph/inst/tcl
RProtoBuf/inst/python
emdbook/inst/BUGS
gridSVG/inst/js
tiff for pkg-config
RSiena for src/ organization and including other code






## How R CMD Install builds packages

Flags set when building:
* CC 
* CFLAGS
* CXX
* CXXFLAGS
* CPPFLAGS
* LDFLAGS
* FC
* FCFLAGS
* PKG_CPPFLAGS
* PKG_CFLAGS
* PKG_CXXFLAGS
* PKG_FFLAGS
* PKG_FCFLAGS
* PKG_LIBS
* BLAS_LIBS
* NDEBUG



## Header Files

https://rstudio.github.io/r-manuals/r-exts/The-R-API.html#organization-of-header-files

| Header               | Description                                                                                   | 
|----------------------|-----------------------------------------------------------------------------------------------| 
| R.h                  | includes many other files                                                                     | 
| Rinternals.h         | definitions for using R’s internal structures                                                 | 
| Rdefines.h           | macros for an S-like interface to the above (no longer maintained)                            | 
| Rmath.h              | standalone math library                                                                       | 
| Rversion.h           | R version information                                                                         | 
| Rinterface.h         | for add-on front-ends (Unix-alikes only)                                                      | 
| Rembedded.h          | for add-on front-ends                                                                         | 
| R_ext/Applic.h       | optimization, integration and some LAPACK ones)                                               | 
| R_ext/BLAS.h         | C definitions for BLAS routines                                                               | 
| R_ext/Callbacks.h    | C (and R function) top-level task handlers                                                    | 
| R_ext/GetX11Image.h  | X11Image interface used by package trkplot                                                    | 
| R_ext/Lapack.h       | C definitions for some LAPACK routines                                                        | 
| R_ext/Linpack.h      | C definitions for some LINPACK routines, not all of which are included in R                   | 
| R_ext/Parse.h        | a small part of R’s parse interface: not part of the stable API.                              | 
| R_ext/RStartup.h     | for add-on front-ends                                                                         | 
| R_ext/Rdynload.h     | needed to register compiled code in packages                                                  | 
| R_ext/Riconv.h       | interface to iconv                                                                            | 
| R_ext/Visibility.h   | definitions controlling visibility                                                            | 
| R_ext/eventloop.h    | for add-on front-ends and for packages that need to share in the R event loops (not Windows)  | 

| R.h Includes       | Description                                                            | 
|--------------------|------------------------------------------------------------------------| 
| Rconfig.h          | configuration info that is made available                              | 
| R_ext/Arith.h      | handling for NAs, NaNs, Inf/-Inf                                       | 
| R_ext/Boolean.h    | TRUE/FALSE type                                                        | 
| R_ext/Complex.h    | C typedefs for R’s complex                                             | 
| R_ext/Constants.h  | constants                                                              | 
| R_ext/Error.h      | error signaling                                                        | 
| R_ext/Memory.h     | memory allocation                                                      | 
| R_ext/Print.h      | Rprintf and variations.                                                | 
| R_ext/RS.h         | definitions common to R.h and the former S.h, including F77_CALL etc.  | 
| R_ext/Random.h     | random number generation                                               | 
| R_ext/Utils.h      | sorting and other utilities                                            | 
| R_ext/libextern.h  | definitions for exports from R.dll on Windows.                         | 

R_ext/GraphicsEngine.h
R_ext/GraphicsDevice.h
R_ext/QuartzDevice.h
R_ext/Connections.h


## Tons of compile options, where are they documented?

USE_RINTERNALS
COMPILING_R
TESTING_WRITE_BARRIER
STRICT_TYPECHECK
CATCH_ZERO_LENGTH_ACCESS


## DLL notes

> It is good practice for DLLs to register their symbols 
(see Section 5.4 [Registering native routines], page 128),
restrict visibility (see Section 6.16 [Controlling visibility], page 188) and
not allow symbol search (see Section 5.4 [Registering native routines], page 128).
It should be possible for a DLL to have only one visible symbol, R_init_pkgname, 
on suitable platforms, which would completely avoid symbol conflicts.





## From Chat GPT


The **R API** is vast, as it encompasses functions for evaluating R expressions, creating/manipulating R objects, interacting with the R runtime, and more. The functions are defined in the R source code, primarily under `Rinternals.h`, `R_ext/*.h`, and other headers.

Below is a categorized overview of key function groups commonly used in the R API:

---

### **1. Initialization and Cleanup**
- **`Rf_initEmbeddedR`**: Initialize an embedded R session.
- **`Rf_endEmbeddedR`**: Terminate an embedded R session.
- **`R_CStackLimit`**: Set the stack limit for embedded R.

---

### **2. Evaluating R Code**
- **`Rf_eval`**: Evaluate an R expression.
- **`Rf_findVar`**: Find a variable in an environment.
- **`Rf_lang2`, `Rf_lang3`, etc.**: Create function calls with 2, 3, etc., arguments.
- **`Rf_applyClosure`**: Apply a closure (function).
- **`R_tryEval`**: Safely evaluate an R expression.

---

### **3. Creating and Manipulating R Objects**
#### **Vectors**
- **`allocVector`**: Allocate a generic vector.
- **`Rf_allocMatrix`**: Allocate a matrix.
- **`Rf_length`**: Get the length of a vector.
- **`Rf_nrows`, `Rf_ncols`**: Get the number of rows/columns of a matrix.
- **`Rf_isReal`, `Rf_isInteger`, etc.**: Check the type of an object.

#### **Lists**
- **`Rf_allocList`**: Allocate a list.
- **`SET_VECTOR_ELT`**: Set an element in a list.
- **`VECTOR_ELT`**: Get an element from a list.

#### **Attributes**
- **`Rf_setAttrib`**: Set an attribute of an object.
- **`Rf_getAttrib`**: Get an attribute of an object.
- **`Rf_classgets`**: Set the class attribute.

#### **Strings**
- **`Rf_mkChar`**: Create an R character object.
- **`Rf_mkString`**: Create a string vector.
- **`CHAR`**: Access the C string from an R character.

---

### **4. Environments**
- **`Rf_NewEnvironment`**: Create a new environment.
- **`Rf_defineVar`**: Define a variable in an environment.
- **`Rf_findVarInFrame`**: Find a variable in a specific environment.

---

### **5. Memory Management**
- **`PROTECT`, `UNPROTECT`**: Manage garbage collection safety.
- **`Rf_allocVector`**: Allocate memory for an object.
- **`Rf_realloc`**: Resize memory.

---

### **6. Error Handling**
- **`Rf_error`**: Signal an error.
- **`Rf_warning`**: Signal a warning.
- **`Rf_tryCatch`**: Implement error catching.

---

### **7. I/O and Printing**
- **`Rprintf`**: Print formatted output to the R console.
- **`REprintf`**: Print formatted output to the R error stream.
- **`Rf_translateChar`**: Translate an R character to the native encoding.

---

### **8. Mathematics**
- **`Rf_fround`**: Round a number to a specified precision.
- **`Rf_choose`**: Compute combinations.
- **`Rf_dnorm4`, `Rf_pnorm5`**: Probability functions (e.g., normal distribution).

---

### **9. Parsing R Code**
- **`R_ParseVector`**: Parse R code into expressions.
- **`Rf_deparse1`**: Convert an R object to a string representation.

---

### **10. External Interface**
- **`R_RegisterCFinalizer`**: Register a finalizer for an R object.
- **`Rf_install`**: Install a symbol for use in R.
- **`Rf_findFun`**: Find a function in an environment.

---

### **11. Threading and Multithreading**
- **`R_CheckUserInterrupt`**: Check for user interrupts.
- **`R_ToplevelExec`**: Run code safely in a separate context.
- **`R_compute_identical`**: Check object equality.

---

### **12. Interfacing with Packages**
- **`R_loadNamespace`**: Load a namespace.
- **`R_NamespaceRegistry`**: Access the registry of namespaces.

---

### **Documentation**
You can view the full list of R API functions in the R source code headers, specifically:
- `Rinternals.h`: Core R API for object creation and manipulation.
- `Rdefines.h`: Macros and utilities for easier API use.
- `R_ext/Parse.h`: Parsing R code.
- `R_ext/Utils.h`: Miscellaneous utilities.

To get the complete list, you can look at these headers directly in the R source code (available on [CRAN](https://cran.r-project.org/) or GitHub at [R source code](https://github.com/wch/r-source)). Would you like help navigating the headers or exploring specific functions?



## API Index

From https://rstudio.github.io/r-manuals/r-exts/The-R-API.html

We can classify the entry points as

### API
Entry points which are documented in this manual and declared in an installed header file. These can be used in distributed packages and ideally will only be changed after deprecation. See API index.

### public
Entry points declared in an installed header file that are exported on all R platforms but are not documented and subject to change without notice. Do not use these in distributed code. Their declarations will eventually be moved out of installed header files.

### private
Entry points that are used when building R and exported on all R platforms but are not declared in the installed header files. Do not use these in distributed code.

### hidden
Entry points that are where possible (Windows and some modern Unix-alike compilers/loaders when using R as a shared library) not exported.

### experimental
Entry points declared in an installed header file that are part of an experimental API, such as R_ext/Altrep.h. These are subject to change, so package authors wishing to use these should be prepared to adapt. See Experimental API index.

### embedding
Entry points intended primarily for embedding and creating new front-ends. It is not clear that this needs to be a separate category but it may be useful to keep it separate for now. See Embedding API index.


| API Level     | Function                      | Doc Section                                   | 
|---------------|-------------------------------|-----------------------------------------------| 
| Embedding     | addInputHandler               | Meshing event loops                           | 
| Experimental  | ALTREP                        | Writing compact-representation-friendly code  | 
| Experimental  | ALTREP_CLASS                  | Writing compact-representation-friendly code  | 
| Core          | ANY_ATTRIB                    | Named objects and copying                     | 
| Core          | bessel_i                      | Mathematical functions                        | 
| Core          | bessel_j                      | Mathematical functions                        | 
| Core          | bessel_k                      | Mathematical functions                        | 
| Core          | bessel_y                      | Mathematical functions                        | 
| Core          | beta                          | Mathematical functions                        | 
| Core          | CAAR                          | Calling .External                             | 
| Core          | CAD4R                         | Calling .External                             | 
| Core          | CAD5R                         | Calling .External                             | 
| Core          | CADDDR                        | Calling .External                             | 
| Core          | CADDR                         | Calling .External                             | 
| Core          | CADR                          | Calling .External                             | 
| Core          | CAR                           | Calling .External                             | 
| Core          | CDAR                          | Calling .External                             | 
| Core          | CDDDR                         | Calling .External                             | 
| Core          | CDDR                          | Calling .External                             | 
| Core          | CDR                           | Calling .External                             | 
| Core          | cgmin                         | Optimization                                  | 
| Core          | CHAR                          | Calculating numerical derivatives             | 
| Core          | choose                        | Mathematical functions                        | 
| Embedding     | CleanEd                       | Setting R callbacks                           | 
| Core          | CLEAR_ATTRIB                  | Named objects and copying                     | 
| Core          | COMPLEX                       | Vector accessor functions                     | 
| Core          | COMPLEX_ELT                   | Vector accessor functions                     | 
| Experimental  | COMPLEX_GET_REGION            | Writing compact-representation-friendly code  | 
| Experimental  | COMPLEX_OR_NULL               | Writing compact-representation-friendly code  | 
| Core          | COMPLEX_RO                    | Vector accessor functions                     | 
| Core          | CONS                          | Some convenience functions                    | 
| Core          | cospi                         | Numerical Utilities                           | 
| Core          | d1mach                        | Utility functions                             | 
| Experimental  | DATAPTR_OR_NULL               | Writing compact-representation-friendly code  | 
| Core          | DATAPTR_RO                    | Vector accessor functions                     | 
| Core          | digamma                       | Mathematical functions                        | 
| Core          | dpsifn                        | Mathematical functions                        | 
| Core          | DUPLICATE_ATTRIB              | Named objects and copying                     | 
| Core          | exp_rand                      | Random numbers                                | 
| Core          | expm1                         | Numerical Utilities                           | 
| Core          | FALSE                         | Mathematical constants                        | 
| Core          | findInterval                  | Utility functions                             | 
| Core          | findInterval2                 | Utility functions                             | 
| Core          | fmax2                         | Numerical Utilities                           | 
| Core          | fmin2                         | Numerical Utilities                           | 
| Core          | fprec                         | Numerical Utilities                           | 
| Embedding     | fpu_setup                     | Setting R callbacks                           | 
| Core          | fround                        | Numerical Utilities                           | 
| Core          | fsign                         | Numerical Utilities                           | 
| Core          | ftrunc                        | Numerical Utilities                           | 
| Core          | gammafn                       | Mathematical functions                        | 
| Embedding     | getInputHandler               | Meshing event loops                           | 
| Core          | GetRNGstate                   | Random numbers                                | 
| Core          | i1mach                        | Utility functions                             | 
| Core          | imax2                         | Numerical Utilities                           | 
| Core          | imin2                         | Numerical Utilities                           | 
| Core          | INTEGER                       | Vector accessor functions                     | 
| Core          | INTEGER_ELT                   | Vector accessor functions                     | 
| Experimental  | INTEGER_GET_REGION            | Writing compact-representation-friendly code  | 
| Experimental  | INTEGER_IS_SORTED             | Writing compact-representation-friendly code  | 
| Experimental  | INTEGER_NO_NA                 | Writing compact-representation-friendly code  | 
| Experimental  | INTEGER_OR_NULL               | Writing compact-representation-friendly code  | 
| Core          | INTEGER_RO                    | Vector accessor functions                     | 
| Core          | integr_fn                     | Integration                                   | 
| Core          | interv                        | Utility functions                             | 
| Experimental  | IS_LONG_VEC                   | Some convenience functions                    | 
| Experimental  | IS_SCALAR                     | Some convenience functions                    | 
| Core          | ISNA                          | Missing and special values                    | 
| Core          | ISNA                          | Missing and IEEE values                       | 
| Core          | ISNAN                         | Missing and special values                    | 
| Core          | ISNAN                         | Missing and IEEE values                       | 
| Core          | lbeta                         | Mathematical functions                        | 
| Core          | lbfgsb                        | Optimization                                  | 
| Core          | lchoose                       | Mathematical functions                        | 
| Core          | LCONS                         | Some convenience functions                    | 
| Core          | LCONS                         | Evaluating R expressions from C               | 
| Core          | LENGTH                        | Calculating numerical derivatives             | 
| Core          | lgamma1p                      | Numerical Utilities                           | 
| Core          | lgammafn                      | Mathematical functions                        | 
| Core          | log1mexp                      | Numerical Utilities                           | 
| Core          | log1p                         | Numerical Utilities                           | 
| Core          | log1pexp                      | Numerical Utilities                           | 
| Core          | log1pmx                       | Numerical Utilities                           | 
| Core          | LOGICAL                       | Vector accessor functions                     | 
| Core          | LOGICAL_ELT                   | Vector accessor functions                     | 
| Experimental  | LOGICAL_GET_REGION            | Writing compact-representation-friendly code  | 
| Experimental  | LOGICAL_NO_NA                 | Writing compact-representation-friendly code  | 
| Experimental  | LOGICAL_OR_NULL               | Writing compact-representation-friendly code  | 
| Core          | LOGICAL_RO                    | Vector accessor functions                     | 
| Core          | logspace_add                  | Numerical Utilities                           | 
| Core          | logspace_sub                  | Numerical Utilities                           | 
| Core          | logspace_sum                  | Numerical Utilities                           | 
| Core          | M_E                           | Mathematical constants                        | 
| Core          | M_PI                          | Mathematical constants                        | 
| Core          | MARK_NOT_MUTABLE              | Named objects and copying                     | 
| Core          | MAYBE_REFERENCED              | Named objects and copying                     | 
| Core          | MAYBE_SHARED                  | Named objects and copying                     | 
| Core          | NA_REAL                       | Missing and IEEE values                       | 
| Core          | nmmin                         | Optimization                                  | 
| Core          | NO_REFERENCES                 | Named objects and copying                     | 
| Core          | norm_rand                     | Random numbers                                | 
| Core          | NOT_SHARED                    | Named objects and copying                     | 
| Core          | optimfn                       | Optimization                                  | 
| Core          | optimgr                       | Optimization                                  | 
| Core          | pentagamma                    | Mathematical functions                        | 
| Core          | pow1p                         | Numerical Utilities                           | 
| Core          | PRINTNAME                     | Calling .External                             | 
| Core          | PROTECT                       | Garbage Collection                            | 
| Core          | PROTECT_WITH_INDEX            | Garbage Collection                            | 
| Core          | psigamma                      | Mathematical functions                        | 
| Core          | PutRNGstate                   | Random numbers                                | 
| Experimental  | R_ActiveBindingFunction       | Semi-internal convenience functions           | 
| Embedding     | R_addhistory                  | Setting R callbacks                           | 
| Core          | R_alloc                       | Allocating storage                            | 
| Core          | R_alloc                       | Transient storage allocation                  | 
| Core          | R_allocLD                     | Transient storage allocation                  | 
| Experimental  | R_altrep_data1                | Writing compact-representation-friendly code  | 
| Experimental  | R_altrep_data2                | Writing compact-representation-friendly code  | 
| Core          | R_atof                        | Utility functions                             | 
| Experimental  | R_BindingIsActive             | Semi-internal convenience functions           | 
| Experimental  | R_BindingIsLocked             | Semi-internal convenience functions           | 
| Embedding     | R_Busy                        | Setting R callbacks                           | 
| Core          | R_BytecodeExpr                | Working with closures                         | 
| Core          | R_Calloc                      | User-controlled memory                        | 
| Core          | R_CHAR                        | Calculating numerical derivatives             | 
| Experimental  | R_check_class_etc             | S4 objects                                    | 
| Core          | R_CheckStack                  | C stack checking                              | 
| Core          | R_CheckStack2                 | C stack checking                              | 
| Core          | R_CheckUserInterrupt          | Allowing interrupts                           | 
| Experimental  | R_chk_calloc                  | User-controlled memory                        | 
| Experimental  | R_chk_free                    | User-controlled memory                        | 
| Experimental  | R_chk_realloc                 | User-controlled memory                        | 
| Embedding     | R_ChooseFile                  | Setting R callbacks                           | 
| Embedding     | R_CleanTempDir                | Setting R callbacks                           | 
| Embedding     | R_CleanUp                     | Setting R callbacks                           | 
| Embedding     | R_ClearerrConsole             | Setting R callbacks                           | 
| Core          | R_ClearExternalPtr            | External pointers and weak references         | 
| Core          | R_ClosureBody                 | Working with closures                         | 
| Core          | R_ClosureEnv                  | Working with closures                         | 
| Core          | R_ClosureExpr                 | Working with closures                         | 
| Core          | R_ClosureFormals              | Working with closures                         | 
| Experimental  | R_compute_identical           | Semi-internal convenience functions           | 
| Core          | R_ContinueUnwind              | Condition handling and cleanup code           | 
| Core          | R_csort                       | Utility functions                             | 
| Embedding     | R_DefParams                   | Calling R.dll directly                        | 
| Embedding     | R_DefParamsEx                 | Calling R.dll directly                        | 
| Core          | R_DimNamesSymbol              | Attributes                                    | 
| Experimental  | R_do_MAKE_CLASS               | S4 objects                                    | 
| Experimental  | R_do_new_object               | S4 objects                                    | 
| Experimental  | R_do_slot                     | S4 objects                                    | 
| Experimental  | R_do_slot_assign              | S4 objects                                    | 
| Embedding     | R_dot_Last                    | Setting R callbacks                           | 
| Embedding     | R_EditFile                    | Setting R callbacks                           | 
| Embedding     | R_EditFiles                   | Setting R callbacks                           | 
| Experimental  | R_EnvironmentIsLocked         | Semi-internal convenience functions           | 
| Core          | R_ExecWithCleanup             | Condition handling and cleanup code           | 
| Experimental  | R_existsVarInFrame            | Semi-internal convenience functions           | 
| Core          | R_ExpandFileName              | Utility functions                             | 
| Experimental  | R_ext/Altrep.h                | Writing compact-representation-friendly code  | 
| Experimental  | R_ext/Altrep.h                | The R API                                     | 
| Core          | R_ext/Arith.h                 | Missing and special values                    | 
| Core          | R_ext/BLAS.h                  | Numerical analysis subroutines                | 
| Core          | R_ext/Boolean.h               | Mathematical constants                        | 
| Core          | R_ext/Complex.h               | Interface functions .C and .Fortran           | 
| Core          | R_ext/Constants.h             | Mathematical constants                        | 
| Core          | R_ext/Error.h                 | The R API                                     | 
| Experimental  | R_ext/GraphicsDevice.h        | Organization of header files                  | 
| Experimental  | R_ext/GraphicsEngine.h        | Organization of header files                  | 
| Core          | R_ext/Lapack.h                | Numerical analysis subroutines                | 
| Core          | R_ext/Linpack.h               | Numerical analysis subroutines                | 
| Core          | R_ext/Memory.h                | Organization of header files                  | 
| Experimental  | R_ext/QuartzDevice.h          | Organization of header files                  | 
| Core          | R_ext/Random.h                | Organization of header files                  | 
| Core          | R_ext/Riconv.h                | Re-encoding                                   | 
| Embedding     | R_ext/RStartup.h              | Calling R.dll directly                        | 
| Core          | R_ext/Visibility.h            | Converting a package to use registration      | 
| Core          | R_ExternalPtrAddr             | External pointers and weak references         | 
| Core          | R_ExternalPtrAddrFn           | External pointers and weak references         | 
| Core          | R_ExternalPtrProtected        | External pointers and weak references         | 
| Core          | R_ExternalPtrTag              | External pointers and weak references         | 
| Experimental  | R_FindNamespace               | Semi-internal convenience functions           | 
| Core          | R_FindSymbol                  | Linking to native routines in other packages  | 
| Core          | R_FINITE                      | Missing and IEEE values                       | 
| Embedding     | R_FlushConsole                | Setting R callbacks                           | 
| Experimental  | R_forceAndCall                | Semi-internal convenience functions           | 
| Core          | R_forceSymbols                | Registering native routines                   | 
| Core          | R_Free                        | User-controlled memory                        | 
| Core          | R_free_tmpnam                 | Utility functions                             | 
| Core          | R_GetCCallable                | Linking to native routines in other packages  | 
| Experimental  | R_getClassDef                 | S4 objects                                    | 
| Core          | R_GetCurrentSrcref            | Accessing source references                   | 
| Embedding     | R_getEmbeddingDllInfo         | Registering symbols                           | 
| Core          | R_GetSrcFilename              | Accessing source references                   | 
| Core          | R_getVar                      | Finding and setting variables                 | 
| Core          | R_getVarEx                    | Finding and setting variables                 | 
| Experimental  | R_GetX11Image                 | Organization of header files                  | 
| Experimental  | R_has_slot                    | S4 objects                                    | 
| Experimental  | R_InitFileInPStream           | Custom serialization input and output         | 
| Experimental  | R_InitFileOutPStream          | Custom serialization input and output         | 
| Experimental  | R_InitInPStream               | Custom serialization input and output         | 
| Experimental  | R_InitOutPStream              | Custom serialization input and output         | 
| Core          | R_INLINE                      | Inlining C functions                          | 
| Embedding     | R_InputHandlers               | Meshing event loops                           | 
| Embedding     | R_Interactive                 | Embedding R under Unix-alikes                 | 
| Experimental  | R_IsNamespaceEnv              | Semi-internal convenience functions           | 
| Core          | R_IsNaN                       | Missing and IEEE values                       | 
| Core          | R_isnancpp                    | Missing and special values                    | 
| Core          | R_isort                       | Utility functions                             | 
| Experimental  | R_IsPackageEnv                | Semi-internal convenience functions           | 
| Embedding     | R_loadhistory                 | Setting R callbacks                           | 
| Experimental  | R_LockBinding                 | Semi-internal convenience functions           | 
| Experimental  | R_LockEnvironment             | Semi-internal convenience functions           | 
| Experimental  | R_lsInternal3                 | Semi-internal convenience functions           | 
| Experimental  | R_MakeActiveBinding           | Semi-internal convenience functions           | 
| Core          | R_MakeExternalPtr             | External pointers and weak references         | 
| Core          | R_MakeExternalPtrFn           | External pointers and weak references         | 
| Core          | R_MakeUnwindCont              | Condition handling and cleanup code           | 
| Core          | R_MakeWeakRef                 | External pointers and weak references         | 
| Core          | R_MakeWeakRefC                | External pointers and weak references         | 
| Core          | R_max_col                     | Utility functions                             | 
| Core          | R_mkClosure                   | Working with closures                         | 
| Experimental  | R_NamespaceEnvSpec            | Semi-internal convenience functions           | 
| Core          | R_NamesSymbol                 | Attributes                                    | 
| Core          | R_NegInf                      | Missing and IEEE values                       | 
| Core          | R_NewEnv                      | Finding and setting variables                 | 
| Core          | R_NewPreciousMSet             | Garbage Collection                            | 
| Core          | R_NilValue                    | Handling lists                                | 
| Core          | R_orderVector                 | Utility functions                             | 
| Core          | R_orderVector1                | Utility functions                             | 
| Experimental  | R_PackageEnvName              | Semi-internal convenience functions           | 
| Core          | R_ParentEnv                   | Semi-internal convenience functions           | 
| Core          | R_ParseEvalString             | Parsing R code from C                         | 
| Core          | R_ParseString                 | Parsing R code from C                         | 
| Core          | R_ParseVector                 | Parsing R code from C                         | 
| Embedding     | R_PolledEvents                | Meshing event loops                           | 
| Core          | R_PosInf                      | Missing and IEEE values                       | 
| Core          | R_pow                         | Numerical Utilities                           | 
| Core          | R_pow_di                      | Numerical Utilities                           | 
| Core          | R_PreserveInMSet              | Garbage Collection                            | 
| Core          | R_PreserveObject              | Garbage Collection                            | 
| Embedding     | R_ProcessEvents               | Calling R.dll directly                        | 
| Core          | R_ProtectWithIndex            | Garbage Collection                            | 
| Core          | R_PV                          | Inspecting R objects                          | 
| Core          | R_qsort                       | Utility functions                             | 
| Core          | R_qsort_I                     | Utility functions                             | 
| Core          | R_qsort_int                   | Utility functions                             | 
| Core          | R_qsort_int_I                 | Utility functions                             | 
| Embedding     | R_ReadConsole                 | Setting R callbacks                           | 
| Core          | R_Realloc                     | User-controlled memory                        | 
| Core          | R_RegisterCCallable           | Linking to native routines in other packages  | 
| Core          | R_RegisterCFinalizer          | External pointers and weak references         | 
| Core          | R_RegisterCFinalizerEx        | External pointers and weak references         | 
| Core          | R_RegisterFinalizer           | External pointers and weak references         | 
| Core          | R_RegisterFinalizerEx         | External pointers and weak references         | 
| Core          | R_registerRoutines            | Registering native routines                   | 
| Core          | R_ReleaseFromMSet             | Garbage Collection                            | 
| Core          | R_ReleaseObject               | Garbage Collection                            | 
| Experimental  | R_removeVarFromFrame          | Semi-internal convenience functions           | 
| Embedding     | R_ReplDLLdo1                  | Embedding R under Unix-alikes                 | 
| Embedding     | R_ReplDLLinit                 | Embedding R under Unix-alikes                 | 
| Core          | R_Reprotect                   | Garbage Collection                            | 
| Embedding     | R_ResetConsole                | Setting R callbacks                           | 
| Core          | R_rsort                       | Utility functions                             | 
| Embedding     | R_RunExitFinalizers           | Setting R callbacks                           | 
| Embedding     | R_RunPendingFinalizers        | Setting R callbacks                           | 
| Core          | R_RunWeakRefFinalizer         | External pointers and weak references         | 
| Embedding     | R_SaveGlobalEnv               | Setting R callbacks                           | 
| Embedding     | R_savehistory                 | Setting R callbacks                           | 
| Experimental  | R_Serialize                   | Custom serialization input and output         | 
| Experimental  | R_set_altrep_data1            | Writing compact-representation-friendly code  | 
| Experimental  | R_set_altrep_data2            | Writing compact-representation-friendly code  | 
| Embedding     | R_set_command_line_arguments  | Calling R.dll directly                        | 
| Core          | R_SetExternalPtrAddr          | External pointers and weak references         | 
| Core          | R_SetExternalPtrProtected     | External pointers and weak references         | 
| Core          | R_SetExternalPtrTag           | External pointers and weak references         | 
| Embedding     | R_SetParams                   | Calling R.dll directly                        | 
| Embedding     | R_setStartTime                | Calling R.dll directly                        | 
| Embedding     | R_ShowFiles                   | Setting R callbacks                           | 
| Core          | R_ShowMessage                 | Setting R callbacks                           | 
| Core          | R_strtod                      | Utility functions                             | 
| Embedding     | R_TempDir                     | Embedding R under Unix-alikes                 | 
| Core          | R_tmpnam                      | Utility functions                             | 
| Core          | R_tmpnam2                     | Utility functions                             | 
| Core          | R_ToplevelExec                | Condition handling and cleanup code           | 
| Core          | R_tryCatch                    | Condition handling and cleanup code           | 
| Core          | R_tryCatchError               | Condition handling and cleanup code           | 
| Core          | R_tryEval                     | Condition handling and cleanup code           | 
| Core          | R_tryEvalSilent               | Condition handling and cleanup code           | 
| Core          | R_unif_index                  | Random numbers                                | 
| Experimental  | R_unLockBinding               | Semi-internal convenience functions           | 
| Experimental  | R_Unserialize                 | Custom serialization input and output         | 
| Core          | R_UnwindProtect               | Condition handling and cleanup code           | 
| Core          | R_useDynamicSymbols           | Registering native routines                   | 
| Core          | R_Version                     | Platform and version information              | 
| Embedding     | R_wait_usec                   | Meshing event loops                           | 
| Core          | R_WeakRefKey                  | External pointers and weak references         | 
| Core          | R_WeakRefValue                | External pointers and weak references         | 
| Core          | R_withCallingErrorHandler     | Condition handling and cleanup code           | 
| Embedding     | R_WriteConsole                | Setting R callbacks                           | 
| Embedding     | R_WriteConsoleEx              | Setting R callbacks                           | 
| Core          | RAW                           | Vector accessor functions                     | 
| Core          | RAW_ELT                       | Vector accessor functions                     | 
| Experimental  | RAW_GET_REGION                | Writing compact-representation-friendly code  | 
| Experimental  | RAW_OR_NULL                   | Writing compact-representation-friendly code  | 
| Core          | RAW_RO                        | Vector accessor functions                     | 
| Core          | Rdqagi                        | Integration                                   | 
| Core          | Rdqags                        | Integration                                   | 
| Core          | REAL                          | Vector accessor functions                     | 
| Core          | REAL_ELT                      | Vector accessor functions                     | 
| Experimental  | REAL_GET_REGION               | Writing compact-representation-friendly code  | 
| Experimental  | REAL_IS_SORTED                | Writing compact-representation-friendly code  | 
| Experimental  | REAL_NO_NA                    | Writing compact-representation-friendly code  | 
| Experimental  | REAL_OR_NULL                  | Writing compact-representation-friendly code  | 
| Core          | REAL_RO                       | Vector accessor functions                     | 
| Embedding     | Rembedded.h                   | Embedding R under Unix-alikes                 | 
| Embedding     | removeInputHandler            | Meshing event loops                           | 
| Core          | REprintf                      | Printing                                      | 
| Core          | REPROTECT                     | Garbage Collection                            | 
| Core          | REvprintf                     | Printing                                      | 
| Core          | Rf_alloc3DArray               | Allocating storage                            | 
| Core          | Rf_allocArray                 | Allocating storage                            | 
| Core          | Rf_allocLang                  | Evaluating R expressions from C               | 
| Core          | Rf_allocList                  | Handling lists                                | 
| Core          | Rf_allocList                  | Evaluating R expressions from C               | 
| Core          | Rf_allocMatrix                | Allocating storage                            | 
| Core          | Rf_allocMatrix                | Calculating numerical derivatives             | 
| Experimental  | Rf_allocS4Object              | S4 objects                                    | 
| Core          | Rf_allocVector                | Allocating storage                            | 
| Experimental  | Rf_any_duplicated             | Semi-internal convenience functions           | 
| Experimental  | Rf_any_duplicated3            | Semi-internal convenience functions           | 
| Core          | Rf_asChar                     | Some convenience functions                    | 
| Core          | Rf_asCharacterFactor          | Some convenience functions                    | 
| Core          | Rf_asComplex                  | Some convenience functions                    | 
| Core          | Rf_asInteger                  | Some convenience functions                    | 
| Core          | Rf_asLogical                  | Some convenience functions                    | 
| Core          | Rf_asReal                     | Some convenience functions                    | 
| Experimental  | Rf_asS4                       | S4 objects                                    | 
| Experimental  | Rf_charIsASCII                | Character encoding issues                     | 
| Experimental  | Rf_charIsLatin1               | Character encoding issues                     | 
| Experimental  | Rf_charIsUTF8                 | Character encoding issues                     | 
| Core          | Rf_classgets                  | Classes                                       | 
| Core          | Rf_coerceVector               | Details of R types                            | 
| Core          | Rf_cons                       | Some convenience functions                    | 
| Experimental  | Rf_copyListMatrix             | Semi-internal convenience functions           | 
| Core          | Rf_copyMatrix                 | Allocating storage                            | 
| Core          | Rf_copyMostAttrib             | Allocating storage                            | 
| Core          | Rf_copyVector                 | Allocating storage                            | 
| Core          | Rf_cPsort                     | Utility functions                             | 
| Core          | Rf_defineVar                  | Finding and setting variables                 | 
| Core          | Rf_dimgets                    | Attributes                                    | 
| Core          | Rf_dimnamesgets               | Attributes                                    | 
| Core          | Rf_duplicate                  | Named objects and copying                     | 
| Experimental  | Rf_duplicated                 | Semi-internal convenience functions           | 
| Core          | Rf_elt                        | Some convenience functions                    | 
| Embedding     | Rf_endEmbeddedR               | Embedding R under Unix-alikes                 | 
| Core          | Rf_error                      | Error signaling                               | 
| Core          | Rf_errorcall                  | Error signaling                               | 
| Core          | Rf_eval                       | Evaluating R expressions from C               | 
| Core          | Rf_findFun                    | Evaluating R expressions from C               | 
| Core          | Rf_GetArrayDimnames           | Attributes                                    | 
| Core          | Rf_getAttrib                  | Attributes                                    | 
| Core          | Rf_getCharCE                  | Character encoding issues                     | 
| Core          | Rf_GetColNames                | Attributes                                    | 
| Core          | Rf_GetMatrixDimnames          | Attributes                                    | 
| Core          | Rf_GetOption1                 | Semi-internal convenience functions           | 
| Core          | Rf_GetOptionWidth             | Semi-internal convenience functions           | 
| Core          | Rf_GetRowNames                | Attributes                                    | 
| Core          | Rf_inherits                   | Semi-internal convenience functions           | 
| Embedding     | Rf_initEmbeddedR              | Embedding R under Unix-alikes                 | 
| Core          | Rf_install                    | Attributes                                    | 
| Core          | Rf_installChar                | Attributes                                    | 
| Core          | Rf_installChar                | Finding and setting variables                 | 
| Core          | Rf_installTrChar              | Attributes                                    | 
| Core          | Rf_iPsort                     | Utility functions                             | 
| Core          | Rf_isArray                    | Some convenience functions                    | 
| Experimental  | Rf_isBlankString              | Some convenience functions                    | 
| Core          | Rf_isComplex                  | Details of R types                            | 
| Core          | Rf_isDataFrame                | Some convenience functions                    | 
| Core          | Rf_isEnvironment              | Details of R types                            | 
| Core          | Rf_isExpression               | Details of R types                            | 
| Core          | Rf_isFactor                   | Some convenience functions                    | 
| Core          | Rf_isFunction                 | Some convenience functions                    | 
| Core          | Rf_isInteger                  | Details of R types                            | 
| Core          | Rf_isLanguage                 | Some convenience functions                    | 
| Core          | Rf_isList                     | Some convenience functions                    | 
| Core          | Rf_isLogical                  | Details of R types                            | 
| Core          | Rf_isMatrix                   | Some convenience functions                    | 
| Core          | Rf_isNewList                  | Some convenience functions                    | 
| Core          | Rf_isNull                     | Details of R types                            | 
| Core          | Rf_isNumber                   | Some convenience functions                    | 
| Core          | Rf_isNumeric                  | Some convenience functions                    | 
| Core          | Rf_isObject                   | Some convenience functions                    | 
| Core          | Rf_isOrdered                  | Some convenience functions                    | 
| Core          | Rf_isPairList                 | Some convenience functions                    | 
| Core          | Rf_isPrimitive                | Some convenience functions                    | 
| Core          | Rf_isReal                     | Details of R types                            | 
| Core          | Rf_isS4                       | Some convenience functions                    | 
| Core          | Rf_isString                   | Details of R types                            | 
| Core          | Rf_isSymbol                   | Details of R types                            | 
| Core          | Rf_isTs                       | Some convenience functions                    | 
| Core          | Rf_isUnordered                | Some convenience functions                    | 
| Experimental  | Rf_isUnsorted                 | Semi-internal convenience functions           | 
| Core          | Rf_isVector                   | Some convenience functions                    | 
| Core          | Rf_isVectorAtomic             | Some convenience functions                    | 
| Experimental  | Rf_isVectorizable             | Semi-internal convenience functions           | 
| Core          | Rf_isVectorList               | Some convenience functions                    | 
| Embedding     | Rf_KillAllDevices             | Setting R callbacks                           | 
| Core          | Rf_lang1                      | Some convenience functions                    | 
| Core          | Rf_lang2                      | Some convenience functions                    | 
| Core          | Rf_lang3                      | Some convenience functions                    | 
| Core          | Rf_lang4                      | Some convenience functions                    | 
| Core          | Rf_lang5                      | Some convenience functions                    | 
| Core          | Rf_lang6                      | Some convenience functions                    | 
| Core          | Rf_lastElt                    | Some convenience functions                    | 
| Core          | Rf_lcons                      | Some convenience functions                    | 
| Core          | Rf_length                     | Calculating numerical derivatives             | 
| Core          | Rf_lengthgets                 | Allocating storage                            | 
| Core          | Rf_list1                      | Some convenience functions                    | 
| Core          | Rf_list2                      | Some convenience functions                    | 
| Core          | Rf_list3                      | Some convenience functions                    | 
| Core          | Rf_list4                      | Some convenience functions                    | 
| Core          | Rf_list5                      | Some convenience functions                    | 
| Core          | Rf_list6                      | Some convenience functions                    | 
| Experimental  | Rf_listAppend                 | Semi-internal convenience functions           | 
| Experimental  | Rf_match                      | Semi-internal convenience functions           | 
| Core          | Rf_mkChar                     | Handling character data                       | 
| Core          | Rf_mkCharCE                   | Character encoding issues                     | 
| Core          | Rf_mkCharLen                  | Handling character data                       | 
| Core          | Rf_mkCharLenCE                | Character encoding issues                     | 
| Core          | Rf_mkNamed                    | Attributes                                    | 
| Core          | Rf_mkString                   | Some convenience functions                    | 
| Core          | Rf_namesgets                  | Attributes                                    | 
| Core          | Rf_ncols                      | Transient storage allocation                  | 
| Experimental  | Rf_nlevels                    | Semi-internal convenience functions           | 
| Core          | Rf_nrows                      | Transient storage allocation                  | 
| Core          | Rf_nthcdr                     | Some convenience functions                    | 
| Core          | Rf_onintr                     | Calling R.dll directly                        | 
| Experimental  | Rf_PairToVectorList           | Semi-internal convenience functions           | 
| Experimental  | Rf_pmatch                     | Semi-internal convenience functions           | 
| Core          | Rf_PrintValue                 | Inspecting R objects                          | 
| Core          | Rf_protect                    | Garbage Collection                            | 
| Experimental  | Rf_psmatch                    | Semi-internal convenience functions           | 
| Core          | Rf_reEnc                      | Character encoding issues                     | 
| Core          | Rf_revsort                    | Utility functions                             | 
| Core          | Rf_rPsort                     | Utility functions                             | 
| Core          | Rf_ScalarComplex              | Some convenience functions                    | 
| Core          | Rf_ScalarInteger              | Some convenience functions                    | 
| Core          | Rf_ScalarLogical              | Some convenience functions                    | 
| Core          | Rf_ScalarRaw                  | Some convenience functions                    | 
| Core          | Rf_ScalarReal                 | Some convenience functions                    | 
| Core          | Rf_ScalarString               | Some convenience functions                    | 
| Core          | Rf_setAttrib                  | Attributes                                    | 
| Core          | Rf_setVar                     | Finding and setting variables                 | 
| Core          | Rf_shallow_duplicate          | Named objects and copying                     | 
| Core          | Rf_str2type                   | Some convenience functions                    | 
| Experimental  | Rf_StringBlank                | Some convenience functions                    | 
| Experimental  | Rf_StringFalse                | Some convenience functions                    | 
| Experimental  | Rf_StringTrue                 | Some convenience functions                    | 
| Core          | Rf_topenv                     | Semi-internal convenience functions           | 
| Core          | Rf_translateChar              | Character encoding issues                     | 
| Core          | Rf_translateCharUTF8          | Character encoding issues                     | 
| Core          | Rf_type2char                  | Some convenience functions                    | 
| Core          | Rf_type2str                   | Some convenience functions                    | 
| Core          | Rf_type2str_nowarn            | Some convenience functions                    | 
| Core          | Rf_unprotect                  | Garbage Collection                            | 
| Core          | Rf_unprotect_ptr              | Garbage Collection                            | 
| Experimental  | Rf_VectorToPairList           | Semi-internal convenience functions           | 
| Core          | Rf_warning                    | Error signaling                               | 
| Core          | Rf_warningcall                | Error signaling                               | 
| Core          | Rf_warningcall_immediate      | Error signaling                               | 
| Core          | Rf_xlength                    | Portable C and C++ code                       | 
| Core          | Rf_xlengthgets                | Allocating storage                            | 
| Core          | Riconv                        | Re-encoding                                   | 
| Core          | Riconv_close                  | Re-encoding                                   | 
| Core          | Riconv_open                   | Re-encoding                                   | 
| Embedding     | Rinterface.h                  | Embedding R under Unix-alikes                 | 
| Core          | Rmath.h                       | Numerical analysis subroutines                | 
| Core          | rmultinom                     | Distribution functions                        | 
| Core          | Rprintf                       | Printing                                      | 
| Core          | rsort_with_index              | Utility functions                             | 
| Core          | Rtanpi                        | Numerical Utilities                           | 
| Embedding     | run_Rmainloop                 | Embedding R under Unix-alikes                 | 
| Core          | Rvprintf                      | Printing                                      | 
| Core          | S_alloc                       | Transient storage allocation                  | 
| Core          | S_realloc                     | Transient storage allocation                  | 
| Core          | samin                         | Optimization                                  | 
| Core          | SET_COMPLEX_ELT               | Vector accessor functions                     | 
| Core          | SET_INTEGER_ELT               | Vector accessor functions                     | 
| Core          | SET_LOGICAL_ELT               | Vector accessor functions                     | 
| Core          | SET_RAW_ELT                   | Vector accessor functions                     | 
| Core          | SET_REAL_ELT                  | Vector accessor functions                     | 
| Core          | SET_STRING_ELT                | Handling character data                       | 
| Core          | SET_TAG                       | Evaluating R expressions from C               | 
| Core          | SET_VECTOR_ELT                | Vector accessor functions                     | 
| Core          | SETCAD4R                      | Calling .External                             | 
| Core          | SETCADDDR                     | Calling .External                             | 
| Core          | SETCADDR                      | Calling .External                             | 
| Core          | SETCADR                       | Calling .External                             | 
| Core          | SETCAR                        | Calling .External                             | 
| Core          | SETCDR                        | Calling .External                             | 
| Embedding     | setup_Rmainloop               | Calling R.dll directly                        | 
| Core          | SHALLOW_DUPLICATE_ATTRIB      | Named objects and copying                     | 
| Core          | sign                          | Numerical Utilities                           | 
| Core          | signrank_free                 | Distribution functions                        | 
| Core          | sinpi                         | Numerical Utilities                           | 
| Core          | STRING_ELT                    | Handling character data                       | 
| Experimental  | STRING_IS_SORTED              | Writing compact-representation-friendly code  | 
| Experimental  | STRING_NO_NA                  | Writing compact-representation-friendly code  | 
| Core          | STRING_PTR_RO                 | Vector accessor functions                     | 
| Core          | TAG                           | Calling .External                             | 
| Core          | tanpi                         | Numerical Utilities                           | 
| Core          | tetragamma                    | Mathematical functions                        | 
| Core          | trigamma                      | Mathematical functions                        | 
| Core          | TRUE                          | Mathematical constants                        | 
| Core          | TYPEOF                        | Calling .External                             | 
| Core          | unif_rand                     | Random numbers                                | 
| Core          | UNPROTECT                     | Garbage Collection                            | 
| Core          | UNPROTECT_PTR                 | Garbage Collection                            | 
| Core          | VECTOR_ELT                    | Vector accessor functions                     | 
| Core          | VECTOR_PTR_RO                 | Vector accessor functions                     | 
| Core          | vmaxget                       | Transient storage allocation                  | 
| Core          | vmaxset                       | Transient storage allocation                  | 
| Core          | vmmin                         | Optimization                                  | 
| Core          | wilcox_free                   | Distribution functions                        | 
| Core          | XLENGTH                       | Portable C and C++ code                       | 


