# Custom `malloc` Implementation in C

A custom C implementation of the standard dynamic memory management functions (`malloc`, `calloc`, `realloc`, and `free`), built to explore how heap memory allocation works.

## Features

- **`malloc`** (`malloc.c`) — Allocates a block of memory of a requested size in bytes.
- **`calloc`** (`calloc.c`) — Allocates memory for an array of elements and initializes all bytes to zero.
- **`realloc`** (`realloc.c`) — Resizes a previously allocated memory block while preserving its existing contents.
- **`free`** (`free.c`) — Releases a previously allocated memory block so it can be reused or returned to the system.

## Project Structure

```text
malloc/
├── include/       # Header files for malloc, calloc, realloc, and free
├── malloc.c       # Implementation of malloc
├── calloc.c       # Implementation of calloc
├── realloc.c      # Implementation of realloc
├── free.c         # Implementation of free
├── main.c         # Driver program / test suite
├── .gitignore
└── README.md
```

## Getting Started

### Prerequisites

- A C compiler such as `gcc` or `clang`

### Clone the Repository

```bash
git clone https://github.com/Mazinghorab/malloc.git
cd malloc
```

### Build and Run

Compile all source files together while pointing the compiler to the `include/` directory:

```bash
gcc -Wall -Wextra -Iinclude main.c malloc.c calloc.c realloc.c free.c -o malloc_demo
./malloc_demo
```

## Implementation Details

- **System Call Interface:** Uses `sbrk()` / `brk()` ` to request memory from the operating system.
- **Block Management:** Tracks allocated and free memory blocks using a block header structure *(e.g., linked list with size, free flag, and next/previous pointers)*.
- **Allocation Strategy:** *(e.g., First-Fit)*
- **Memory Alignment & Coalescing:** *(e.g., 8-byte or 16-byte alignment, block splitting, and coalescing adjacent free blocks)*