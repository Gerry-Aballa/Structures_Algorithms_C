# Question 2

This is the Fibonacci-like sequence `F(n) = F(n-3) + F(n-2)` using three different approaches. The interger `n` has to be positive.

## How to compile and run
This program can be run on any terminal or C/C++ supporting IDEs like CodeBlocks or Visual Studio Code.
You will need a C compiler like gcc to create an executable file and run the program in the terminal.

Follow these steps to complie and run the program in a terminal.

1. Clone this repositiory to your local machine.
2. Navigate to directory `/Question2` through the terminal.
3. Use your preferred C compiler to generate an executable file. Using gcc run `gcc question2.c -o question2` on the terminal.
4. Run the program using this command `./question2`.


## Advantages and Disadvantages of Each Approach:

### Recursive Approach: Approach 1

Advantages: Simple and easy to understand. Represents the mathematical definition of the sequence.
Disadvantages: Exponential time complexity due to redundant calculations. Inefficient for larger values of n.

### Memoization (Top-Down Dynamic Programming): Approach 2

Advantages: Avoids redundant calculations through memoization. Can handle larger values of n efficiently.
Disadvantages: Uses extra space for the memoization table. Recursive calls might still lead to stack overflow for very large n.

### Iterative (Bottom-Up Dynamic Programming): Approach 3

Advantages: Efficiently computes the sequence iteratively without the risk of stack overflow. Space-efficient as it only requires an array for dynamic programming.
Disadvantages: Requires some additional code complexity compared to the recursive approach.

