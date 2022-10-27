# SUDOKU SOLVER

### Problem
Given a sudoku puzzle, the algorithm finds the first solution using backtracking.

The form acceptable by the program is the following:

```
x x 3 6 x x x x x
9 x x 8 x x 2 x 7
x x x x x x x x x
x 4 x 1 5 x 8 3 x
x 7 x 2 x 4 x x x
8 2 x x x x x x x
x 9 x x x 5 3 x 8
5 x x 7 6 x 4 x x
x x x x x x 5 6 x
```

Where the `x` is a blank position, and the numbers are the already filled positions in the board.

### Compile and run

```
g++ main.cpp -o main && ./main < sudoku-input.txt
```

### Output

The output for the example input is the following:

```
1 5 3   6 7 2   9 8 4   
9 6 4   8 3 1   2 5 7   
7 8 2   5 4 9   6 1 3   

6 4 9   1 5 7   8 3 2   
3 7 5   2 8 4   1 9 6   
8 2 1   3 9 6   7 4 5   

2 9 6   4 1 5   3 7 8   
5 1 8   7 6 3   4 2 9   
4 3 7   9 2 8   5 6 1 
```
