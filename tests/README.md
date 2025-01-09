# Testing Frameworks

## testthat

For R testing.

## minunit

* https://github.com/adamleerich/minunit
* Fork of https://github.com/siu/minunit
* Originally based on https://jera.com/techinfo/jtns/jtn002 which is just two macros and a counter

```c
#define mu_assert(message, test) do { 
    if (!(test)) return message;
} while (0)

#define mu_run_test(test) do {
    char *message = test(); 
    tests_run++; 
    if (message) return message;
} while (0)

extern int tests_run;
```

## check

```sh
pacman -S mingw-w64-x86_64-check
```

## unity

* https://www.throwtheswitch.org/unity
* https://github.com/ThrowTheSwitch/Unity


## cmocka

```sh
# cmocka does not come with Rtools44
# https://packages.msys2.org/base/mingw-w64-cmocka
pacman -S mingw-w64-x86_64-cmocka
```

Further reading on `cmocka`

* https://cmocka.org/
* https://api.cmocka.org/
* https://re-ws.pl/2018/10/using-cmocka-for-unit-testing-c-code/
* https://www.slideshare.net/slideshow/test-driven-development-in-c/603733#122


## Criterion
 
* https://github.com/Snaipe/Criterion?tab=readme-ov-file
* https://criterion.readthedocs.io/en/latest/setup.html#installation


## munit

Last updated in 2020.

https://nemequ.github.io/munit/#download


## Classic HWUT

https://sourceforge.net/projects/hwut/


## Google Test

* https://github.com/google/googletest
* https://github.com/google/cmockery


## seatest

https://github.com/keithn/seatest
