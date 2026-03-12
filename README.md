<h1 align="center">push_swap</h1>

<p align="center">
  <img src="https://img.shields.io/badge/language-C-blue.svg" alt="Language">
  <img src="https://img.shields.io/badge/42-School-black.svg" alt="42 School">
  <img src="https://img.shields.io/badge/status-complete-brightgreen.svg" alt="Status">
</p>

<p align="center">
  A sorting algorithm challenge — sort a stack of numbers using the minimum possible number of operations with only two stacks and a restricted set of moves.
</p>

<p align="center">
  <a href="README.pt-br.md">🇧🇷 Leia em Português</a>
</p>

---

## Why this project matters

> "This project taught me how to think algorithmically under constraints — not just 'sort this', but 'sort this with the fewest possible moves, using only these specific operations'. I learned how indexing simplifies comparisons, when to apply small-sort vs. radix-sort strategies, and how to measure and optimize algorithmic complexity. These are exactly the skills tested in technical interviews and applied in high-performance systems."

Algorithm design and complexity analysis are core skills for any software engineering role. This project goes beyond implementing a known algorithm — it requires selecting and combining strategies to hit performance targets.

---

## How it works

Two stacks — **A** and **B** — and 11 allowed operations:

| Operation | Description |
|---|---|
| `sa` | Swap the top 2 elements of stack A |
| `sb` | Swap the top 2 elements of stack B |
| `ss` | Execute `sa` and `sb` simultaneously |
| `pa` | Push top of B to top of A |
| `pb` | Push top of A to top of B |
| `ra` | Rotate A — top element goes to bottom |
| `rb` | Rotate B — top element goes to bottom |
| `rr` | Execute `ra` and `rb` simultaneously |
| `rra` | Reverse rotate A — bottom element goes to top |
| `rrb` | Reverse rotate B — bottom element goes to top |
| `rrr` | Execute `rra` and `rrb` simultaneously |

**Goal:** Sort stack A in ascending order (smallest on top) with the fewest operations. Stack B must be empty at the end.

---

## The algorithm

### 1. Input validation
Verifies that all inputs are valid integers within the `int` range and that there are no duplicates.

### 2. Indexing
Before sorting, all numbers are replaced by their sorted index (0, 1, 2...). This eliminates the need to handle negative numbers and large values during sorting, simplifying all comparisons.

### 3. Sorting strategy

**Small sort (≤ 5 elements)**
A hardcoded decision tree optimized for the minimum number of moves in each possible case.

**Radix sort (> 5 elements)**
Numbers are sorted bit by bit using a binary radix sort over their indexes — pushing elements to B based on the current bit, then pulling them back. This guarantees O(n log n) complexity with a consistent and predictable number of operations.

---

## A standout technical detail

The use of **indexing as a preprocessing step** before sorting is an elegant engineering decision. By converting arbitrary integers into a contiguous index sequence, the radix sort can operate on bits directly without worrying about sign bits, large values, or comparison edge cases. This pattern — normalizing data before processing — is a recurring technique in real-world data pipelines and competitive programming.

---

## Demo

![Sorting demo](https://github.com/GSousa101/pushswap_42/blob/main/sort.gif)

![5 elements sort](https://github.com/GSousa101/pushswap_42/blob/main/gifde5.gif)

![100 elements sort](https://github.com/GSousa101/pushswap_42/blob/main/gifde100.gif)

---

## Getting Started

```bash
git clone https://github.com/gustavofsousa/pushswap_42.git
cd pushswap_42
make
```

### Running

```bash
# Sort a list of numbers
./push_swap 3 1 4 1 5 9 2 6

# Pipe to count operations
./push_swap 3 1 4 1 5 9 2 6 | wc -l

# Use the checker to verify correctness
./push_swap 3 1 4 1 5 9 2 6 | ./checker 3 1 4 1 5 9 2 6
```

---

## Project structure

```
pushswap_42/
├── src/
│   ├── push_swap.c    # Entry point + input validation
│   ├── sort_small.c   # Optimized sort for ≤5 elements
│   ├── sort_big.c     # Radix sort for large inputs
│   ├── push.c         # pa / pb operations
│   ├── swap.c         # sa / sb / ss operations
│   ├── rotate.c       # ra / rb / rr operations
│   ├── reverse_rotate.c # rra / rrb / rrr operations
│   ├── checker.c      # Validates sorted output
│   └── ft_atol.c      # Integer parsing
├── include/           # Headers
├── libft/             # Personal C library
└── Makefile
```

---

## References

- [15 Sorting Algorithms Visualized](https://youtu.be/kPRA0W1kECg)
- [Push Swap Visualizer](https://github.com/o-reo/push_swap_visualizer)
- [Why is Radix Sort so Fast?](https://www.youtube.com/watch?v=ujb2CIWE8zY)

---

## Skills demonstrated

- Algorithm design and optimization under constraints
- Complexity analysis (O(n log n) target)
- Data indexing and normalization
- Bitwise operations (binary radix sort)
- Linked list stack implementation
- Handling edge cases in input parsing

---

## License

This project was developed as part of the [42 School](https://42.fr) curriculum.

---

<p align="center">Made with ☕ at 42 Rio de Janeiro</p>
