# Lecture 02_functions_and_arrays

## 01_functions.cc
[link to file](./01_functions.cc)

A function is a named sequence of statements. A function can return a result (return value).

PPP: 4.5


## 02_overloading.cc

[link to file](./02_overloading.cc)

This program contains an example of *function overloading*. You can give two
functions the same name provided that they differ by the types and/or the
number of arguments.

CPL: 12.3



## 03_templates.cc

[link to file](./03_templates)

This program introduces the usage of *templates* for the function of the previous
example. The template allows the function to work with different kinds of types, thus
avoiding code repetitions (from the programmer).

PPP: 19.3
CPL: 3.4.1, 3.4.2



## 04_wrong_args.cc

[link to file](./04_wrong_args.cc)

This is an example of how arguments are passed in C++, the paradigm used is the *pass by value*.

PPP: 8.5.3



## 05_swaps.cc

[link to file](./05_swaps.cc)

How to actually swap two numbers in C++ using pointers and references. Can we do something better here?


## 06_static_arrays.cc

[link to file](./06_static_arrays.cc)

Brief introduction to arrays in C++, examples of declaration and various initializations.
There is also a demonstration of their consecutive representation in memory.
The `std::string` class is a good alternative for `char` arrays.

PPP: 17.2 arrays, 18.6 array and pointers
CPL: 7.3 arrays



## 07_dynamic_arrays.cc

[link to file](./07_dynamic_arrays.cc)

Usage of the `new` function to allocate memory on the *heap* (also called free-store or dynamic memory)
and consequent usage of `delete` to free it.

PPP: 17.4
CPL: 11.2








### References:

[PPP]  Programming: Principles and Practice using C++ (Second Edition), Bjarne Stroustrup, Addison-Wesley 2014, ISBN 978-0-321-99278-9

[CPL]  The C++ Programming Language, Bjarne Stroustrup, Addison-Wesley 2013, ISBN 978-0321563842
