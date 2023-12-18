# Minimalist-Lexer

## Description
This C program is designed to analyze a text file containing a mixture of numbers and character strings. The numbers can be integers or decimal values with decimal points, and they may be separated by spaces, tabs, or new lines. The program identifies integers, decimal numbers, and strings in the file and outputs the results.

## Input
The input file should be provided as a parameter when executing the program. The input file contains a mixture of numbers and strings, separated by spaces, tabs, or new lines.

### Example 

#### Input File
```plaintext
1234 stringx 56
78.5 stringy
stringx 67.67.87
6 string 28
```

#### Output
```plaintext
<INTEGER,1234><STRING,stringx><INTEGER,56><FLOAT,78.5 >
<STRING, stringy><STRING,stringx><ERROR,67.67.87><INTEGER,6>
<STRING,string><INTEGER,28>
```

## Usage
