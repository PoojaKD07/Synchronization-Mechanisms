# Experiment 5: Analysis of Synchronization Mechanisms in Parallel Programs

## Overview

This project investigates synchronization mechanisms used in shared-memory parallel programming. It demonstrates how race conditions affect correctness and compares critical sections, atomic operations, locks, barriers, and semaphores.

The experiment uses C, OpenMP, and POSIX threads/semaphores on Ubuntu Linux.

## Objectives

- Understand race conditions in parallel programs.
- Implement critical sections and atomic operations.
- Demonstrate barrier synchronization.
- Implement mutual exclusion using semaphores and locks.
- Compare execution time and correctness for different thread counts.
- Analyze the impact of synchronization overhead on parallel performance.

## Technologies Used

- C programming language
- Ubuntu Linux
- GCC compiler
- OpenMP
- POSIX threads and semaphores

## Project Structure

```text
Synchronization-Mechanisms/
├── README.md
├── .gitignore
├── src/
│   ├── race.c
│   ├── cs.c
│   ├── atomic.c
│   ├── barrier.c
│   ├── semaphore.c
│   └── compare_sync.c
├── results/
│   ├── benchmark_results.csv
│   └── analysis.md
└── evidence/
    ├── race_and_individual_programs.png
    └── benchmark_execution.png
```

## Compilation and Execution

Run these commands from the project root directory on Ubuntu.

### 1. Compile and run the race-condition example

```bash
gcc -O2 -fopenmp src/race.c -o race
./race
```

### 2. Compile and run the critical-section example

```bash
gcc -O2 -fopenmp src/cs.c -o cs
./cs
```

### 3. Compile and run the atomic-operation example

```bash
gcc -O2 -fopenmp src/atomic.c -o atomic
./atomic
```

### 4. Compile and run the barrier example

```bash
gcc -O2 -fopenmp src/barrier.c -o barrier
./barrier
```

### 5. Compile and run the semaphore example

```bash
gcc -O2 src/semaphore.c -pthread -o semaphore
./semaphore
```

### 6. Compile and run the synchronization benchmark

```bash
gcc -O2 -fopenmp src/compare_sync.c -o compare_sync
./compare_sync
```

## Experimental Results

The benchmark evaluates 10,000,000 shared increments with 1, 2, 4, and 8 threads.

| Mechanism | Threads | Final count | Correctness | Time (seconds) |
|---|---:|---:|---|---:|
| None | 1 | 10,000,000 | Correct | 0.0066 |
| Critical | 1 | 10,000,000 | Correct | 0.0937 |
| Atomic | 1 | 10,000,000 | Correct | 0.0549 |
| Lock | 1 | 10,000,000 | Correct | 0.0927 |
| None | 2 | 5,794,422 | Incorrect | 0.0082 |
| Critical | 2 | 10,000,000 | Correct | 0.2901 |
| Atomic | 2 | 10,000,000 | Correct | 0.0798 |
| Lock | 2 | 10,000,000 | Correct | 0.2842 |
| None | 4 | 2,590,393 | Incorrect | 0.0097 |
| Critical | 4 | 10,000,000 | Correct | 0.6168 |
| Atomic | 4 | 10,000,000 | Correct | 0.0832 |
| Lock | 4 | 10,000,000 | Correct | 0.5706 |
| None | 8 | 1,336,503 | Incorrect | 0.0105 |
| Critical | 8 | 10,000,000 | Correct | 0.9715 |
| Atomic | 8 | 10,000,000 | Correct | 0.0855 |
| Lock | 8 | 10,000,000 | Correct | 0.8776 |

*Note: Execution times are machine- and run-dependent. These are the recorded results from this experiment, not guaranteed timings on other systems.*

## Observations

- **No synchronization:** Concurrent updates can be lost because of race conditions. The single-thread run is correct because there is no concurrent access.
- **Critical sections:** Protect shared updates and produce the expected final count, but the measured execution time increases with thread count.
- **Atomic operations:** Produce the expected count and were the fastest of the tested synchronization mechanisms in the recorded multi-thread runs.
- **Locks:** Ensure mutual exclusion but introduce synchronization overhead.
- **Barriers:** Coordinate when threads proceed between phases; they do not independently protect shared variables.
- **Semaphores:** Can control access to shared resources and protect critical operations when used correctly.

## Conclusion

The experiment demonstrates that synchronization is essential for correctness when multiple threads modify shared data. Unsynchronized updates may be faster but can produce incorrect results. Critical sections, atomic operations, and locks protect shared updates with different performance costs. In the recorded benchmark, atomic operations offered the best performance among the tested protected mechanisms.

## Reproducibility

The recorded timings describe one execution environment and can vary with processor architecture, compiler version, thread scheduling, and system load. The source files and benchmark results should be considered together when interpreting the experiment..

