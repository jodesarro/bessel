# Bessel functions <img src="https://github.com/jodesarro/bessel-library/blob/master/cyl-j0.gif" height=30px>

<p align="right"><a href="https://github.com/jodesarro/bessel-library/blob/master/README.pt-br.md">Leia isto em Português</a></p>

A C++ library with routines to evaluate Bessel functions for real or complex arguments.

## How to use

The library is in a header-only library style, i.e., there is nothing to build, you only have to include the *bessel-library.hpp* file to your project.
See <a href="https://github.com/jodesarro/bessel-library/blob/master/usage-example.cpp">usage-example.cpp</a> as an example of usage.

## Features

Available features
- Cylindrical Bessel function of ordinary order for real and complex arguments, *J*<sub>0</sub>(*z*);
  - `bessel::cyl_j0(z)`

Features under development
- Cylindrical Bessel function of integer order for real and complex arguments, *J<sub>n</sub>*(*z*);

## Accuracy

It was built to achieve (without guarantee) sufficient accuracy for the types `float` (six digits), `double` (fifteen digits) and `long double` (nineteen digits) within *MinGW-W64-builds-4.3.5* compiler.

#### *J*<sub>0</sub>(*z*)

For `long double` type, `bessel::cyl_j0(z)` does not reach enough accuracy only when <nobr>5 ≤ Re{*z*} ≤ 20</nobr>, where Re{*z*} is the real part of the argument *z*.

For <nobr>Re{*z*} > 20</nobr>, `bessel::cyl_j0(z)` strongly depends on the accuracy of functions `std::sin(z)` and `std::cos(z)`.

## Licensing

This project is protected under <a href="https://github.com/jodesarro/bessel-library/blob/master/LICENSE">MIT License</a> and [@jodesarro]( https://github.com/jodesarro ) is the principal author.
