Mini-Compiler for C
=======================

This is a step by step making of a mini C compiler.

Input:

A basic C program.

Output:

The assembly program corresponding to the input.

Steps to run:

>> flex be11302011.l
>> bison be11302011.y
>> gcc be11302011.tab.c
>> a.exe input.c output.i output.s

* The output.i file is the intermediate code (three address code) and the output.s is the assembly file, corresponding to the input file.
* The output.s file can be assembled and run using 
 >> gcc -m32 output.s
 >> a.exe


Tech Used:

flex
bison
