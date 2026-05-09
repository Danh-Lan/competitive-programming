## Problem

Given a `3 x 3` sudoku-like grid containing distinct characters and a string `s` representing the sequence of moves played.

Each move places/selects one character from the grid.

A move gives a score equal to the number of newly completed:

- rows
- columns
- diagonals

after that move is played.

For a string `s`:

1. Compute the score sequence produced by each move
2. Find the lexicographically smallest string that produces the same score sequence

There are `t` test cases (1 <= t <= 10)

## Example

```
Input:
1
ABC
DEF
GHI
GHABFCDIE
```

For:

```
s = GHABFCDIE
```

the score sequence is:

```text
000001124
```

The lexicographically smallest string producing the same score sequence is:

```text
ABDFHCGIE
```

Output:

```text
000001124 ABDFHCGIE
```