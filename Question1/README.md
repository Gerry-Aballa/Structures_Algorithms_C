# Question 1

This program returns fibonacci sequence numbers based on the (+, -, *, /) arithmetic operations and conditions.

## How to compile and run
This program can be run on any terminal or C/C++ supporting IDEs like CodeBlocks or Visual Studio Code.
You will need a C compiler like gcc to create an executable file and run the program in the terminal.

Follow these steps to complie and run the program in a terminal.

1. Clone this repositiory to your local machine.
2. Navigate to directory `/Question1` through the terminal.
3. Use your preferred C compiler to generate an executable file. Using gcc run `gcc question1.c -o question1` on the terminal.
4. Run the program using this command `./question1`.

## How it works
In this code, the `generateFibonacci` function uses dynamic programming to generate the Fibonacci sequence up to a specified length `n`. The `calculate` and `calc` functions are adapted to use the `fibo` array to calculate and print the result based on the given structure.