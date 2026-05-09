## Problem

Given an array `a` of length `n` (all element of `a` are distinct) and `m` segments `(x[i], y[i])` where:

\[ 1 <= x[i] <= y[i] <= n \]

For each segment `j`, define:

\[
S_j = \sum_{k=x[j]}^{y[j]} a[k]
\]

Let:

\[
S = \sum_{j=1}^{m} S_j
\]

We may rearrange the elements of array `a` in any order.

Find:

1. The maximum possible value of `S`
2. The number of different rearrangements of `a` that achieve this maximum value

Since the number of arrangements may be large, output it modulo: 10^9 + 7