# Push_swap

A sorting algorithm project that sorts data on two stacks with a limited set of operations.

## Overview

Push_swap is a School 42 project that requires implementing an efficient sorting algorithm using two stacks (A and B) and a limited set of operations. The goal is to sort the stack of integers with the minimum number of operations.

## Installation

```bash
git clone <repository-url>
cd push_swap
make
```

## Usage

```bash
./push_swap [list of integers]
```

Example:
```bash
./push_swap 5 2 9 1 5
```

## Sorting Operations

The program uses the following operations to sort the stacks:

- `sa`: Swap the first two elements of stack A
- `sb`: Swap the first two elements of stack B
- `ss`: Perform `sa` and `sb` simultaneously
- `pa`: Push the top element from stack B to stack A
- `pb`: Push the top element from stack A to stack B
- `ra`: Rotate stack A (shift all elements up by 1, the first element becomes the last)
- `rb`: Rotate stack B
- `rr`: Perform `ra` and `rb` simultaneously
- `rra`: Reverse rotate stack A (shift all elements down by 1, the last element becomes the first)
- `rrb`: Reverse rotate stack B
- `rrr`: Perform `rra` and `rrb` simultaneously

## Algorithm

The project implements a chunk-based sorting algorithm:

1. For small stacks (≤5 elements), specific optimized strategies are used
2. For larger stacks, the algorithm:
   - Divides the numbers into chunks
   - Sends numbers from each chunk to stack B in an optimized order
   - Returns numbers to stack A in sorted order

The chunk-based approach significantly reduces the number of operations needed for larger datasets.

## Project Structure

```
.
├── LIBFT/           # Custom C library with helper functions
├── srcs/            # Source files
│   ├── main.c       # Entry point
│   ├── init.c       # Stack initialization
│   ├── parsing.c    # Input parsing
│   ├── push.c       # Push operations (pa, pb)
│   ├── swap.c       # Swap operations (sa, sb, ss)
│   ├── rotate.c     # Rotate operations (ra, rb, rr)
│   ├── rev_rotate.c # Reverse rotate operations (rra, rrb, rrr)
│   ├── sort_small.c # Algorithms for sorting small stacks
│   ├── sort_large.c # Algorithm for sorting large stacks
│   ├── utils.c      # Utility functions
│   ├── help_norm1.c # Helper functions
│   ├── help_norm2.c # Helper functions
│   └── help_norm3.c # Helper functions
├── Makefile         # Build system
└── README.md        # Project documentation
```

## Features

- Efficient sorting of integer stacks
- Different strategies based on stack size
- Error handling for invalid inputs
- Memory management to prevent leaks

## Testing

You can test the program with random number generators:

```bash
# Example with 100 random numbers
ARG=$(ruby -e "puts (1..100).to_a.shuffle.join(' ')"); ./push_swap $ARG | wc -l
```

## License

This project is part of the curriculum at School 42.

## Author

[Jazailac]
