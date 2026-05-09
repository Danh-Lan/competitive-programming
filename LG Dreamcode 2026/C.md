## Problem

We have a rectangular cake of size `R x C`.

Alice wants to divide the cake among her `N` friends using exactly `N - 1` cuts.

Each cut must go through the entire remaining cake and divide it into two rectangles with size not smaller than `1`.

There are two possible types of cuts:

- **Horizontal cut**
  - The top part is given to the current friend
  - The bottom part is used for the next cut

- **Vertical cut**
  - The left part is given to the current friend
  - The right part is used for the next cut

After the final cut, the remaining piece is given to the `N`-th friend.

---

## Cake Description

Each cell of the cake may contain:

- `S` : strawberry
- `B` : blueberry
- `R` : raspberry
- `.` : cream only

Alice knows the favorite fruit of each friend.

She wants to perform the cuts so that every friend receives a piece containing **at least one fruit they like**.

---

## Task

Calculate the number of valid ways to perform the cuts.

Since the answer may be large, output it modulo:

\[
10^9 + 7
\]

---

## Constraints

```text
Number of test cases : 1 <= t <= 10
1 <= R, C <= 100
1 <= N <= min(10, R + C - 1)
```

## Input Format

For each test case:

- First line contains `R`, `C`, `N`
- Next `R` lines describe the cake
- Last line contains a string of length `N`: The `i`-th character represents the favorite fruit of the `i`-th friend

---

## Sample Input

```text
6
2 2 3
S.
BR
SBR
2 2 3
S.
BR
SRB
1 6 3
SBRSBR
SBR
3 4 4
S...
.SR.
...B
SSRB
3 3 2
SBS
BSB
SBS
SB
1 50 10
SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
SSSSSSSSSS
```

## Sample Output

```text
1
0
7
4
4
54455620
```