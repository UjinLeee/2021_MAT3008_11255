# HW 1 : Machine Accuracy

## 0. Goal

Obtain the machine accuracy (the machine epsilon) of "float" and "double" of  my computer in two ways.

Environment
- OS: Windows
- Compiler: gcc version 8.1.0
- platform: x86_64-posix-seh-rev0

## 1. Implementation

### 1) Method 1 by machar( )

machar( ) is a function which provides machine epsilon of "float". machar_double( ) is a function which provides machine epsilon of "double".

Result

'''

The result of Method 1,,,
The Epsilon of float by machar() : 1.19209e-007 (0.00000011920928955078125)
The Epsilon of double by machar_double(): 2.22045e-016 (0.0000000000000002220446049250313100000000000000000000)

'''

### 2) Method 2 by get_eps( )

functions get_float_eps( ) and get_double_eps( ) in main.c are functions which provides machine epsilon by using 1+2^(-n) = 1.

Result

'''

The result of Method 2,,,
The Epsilon of float by get_float_eps() : 1.19209e-007 (0.00000011920928955078125)
The Epsilon of double by get_double_eps(): 2.22045e-016 (0.0000000000000002220446049250313100000000000000000000)

'''

## 2. Result

Each epsilon of float and double is same both of Method 1 and Method 2.