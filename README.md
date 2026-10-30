# Experiment 5: Analysis of Synchronization Mechanisms in Parallel Programs

## 1. Overview

This experiment analyzes synchronization mechanisms used in parallel programming. It demonstrates race conditions and explores different synchronization techniques, including critical sections, atomic operations, barriers, semaphores, and locks.

The experiment is implemented using C, OpenMP, and POSIX threads/semaphores on Ubuntu Linux.

## 2. Objectives

- Understand race conditions in parallel programs.
- Implement critical sections and atomic operations.
- Demonstrate barrier synchronization.
- Implement mutual exclusion using semaphores and locks.
- Compare execution time and correctness for different thread counts.
- Analyze synchronization overhead and parallel performance.

## 3. Technologies Used

- C Programming Language
- Ubuntu Linux
- GCC Compiler
- OpenMP
- POSIX Threads
- POSIX Semaphores

## 4. Project Structure

```text
Synchronization-Mechanisms/
│
├── README.md
├── .gitignore
│
├── src/
│   ├── race.c
│   ├── cs.c
│   ├── atomic.c
│   ├── barrier.c
│   ├── semaphore.c
│   └── compare_sync.c
│
├── results/
│   ├── analysis.md
│   └── benchmark_results.csv
│
└── evidence/
    ├── individual_programs.png
    └── benchmark_execution.png
```

## 5. Compilation and Execution

Run all commands from the project root directory on Ubuntu Linux.

### 5.1 Race Condition

```bash
gcc -O2 -fopenmp src/race.c -o race
./race
```

### 5.2 Critical Section

```bash
gcc -O2 -fopenmp src/cs.c -o cs
./cs
```

### 5.3 Atomic Operation

```bash
gcc -O2 -fopenmp src/atomic.c -o atomic
./atomic
```

### 5.4 Barrier Synchronization

```bash
gcc -O2 -fopenmp src/barrier.c -o barrier
./barrier
```

### 5.5 Semaphore

```bash
gcc -O2 -pthread src/semaphore.c -o semaphore
./semaphore
```

*Note: This semaphore compilation command assumes that the source uses POSIX threads and semaphores. Use the command matching your actual source implementation.*

### 5.6 Synchronization Benchmark

```bash
gcc -O2 -fopenmp src/compare_sync.c -o compare_sync
./compare_sync
```

## 6. Experimental Results

The benchmark performs 10,000,000 shared increments using 1, 2, 4, and 8 threads.

| Mechanism | Threads | Final Count | Correctness | Time (seconds) |
|---|---:|---:|---|---:|
| None | 1 | 10000000 | Correct | 0.0066 |
| Critical | 1 | 10000000 | Correct | 0.0937 |
| Atomic | 1 | 10000000 | Correct | 0.0549 |
| Lock | 1 | 10000000 | Correct | 0.0927 |
| None | 2 | 5794422 | Incorrect | 0.0082 |
| Critical | 2 | 10000000 | Correct | 0.2901 |
| Atomic | 2 | 10000000 | Correct | 0.0798 |
| Lock | 2 | 10000000 | Correct | 0.2842 |
| None | 4 | 2590393 | Incorrect | 0.0097 |
| Critical | 4 | 10000000 | Correct | 0.6168 |
| Atomic | 4 | 10000000 | Correct | 0.0832 |
| Lock | 4 | 10000000 | Correct | 0.5706 |
| None | 8 | 1336503 | Incorrect | 0.0105 |
| Critical | 8 | 10000000 | Correct | 0.9715 |
| Atomic | 8 | 10000000 | Correct | 0.0855 |
| Lock | 8 | 10000000 | Correct | 0.8776 |

**Expected Final Count:** 10,000,000

*Note: These are the recorded measurements from this experiment. Execution times may vary depending on hardware, compiler, operating system, and system load.*

## 7. Analysis and Observations

### 7.1 Race Condition

Without synchronization, multiple threads can update the same shared variable simultaneously. This can cause lost updates and an incorrect final count.

The single-thread execution is correct because there is no concurrent access. In multi-thread executions, the final count was less than the expected value.

### 7.2 Critical Section

A critical section allows only one thread at a time to execute the protected code. It ensures correctness by preventing simultaneous access to the shared counter.

However, it introduces waiting and synchronization overhead. In the recorded benchmark, its execution time increased with the number of threads.

### 7.3 Atomic Operation

Atomic operations perform shared-variable updates as indivisible operations. They prevent race conditions during the protected update.

In the recorded benchmark, atomic operations were the fastest among the tested protected mechanisms for the multi-thread configurations.

### 7.4 Locks

Locks provide mutual exclusion by allowing only one thread at a time to access a protected critical section.

They maintain correctness but introduce locking and unlocking overhead. In the recorded benchmark, locks were slower than atomic operations.

### 7.5 Barrier Synchronization

A barrier makes participating threads wait until all threads reach a synchronization point before continuing.

The order of thread output can vary because thread scheduling is nondeterministic. A barrier coordinates execution phases but does not independently protect shared-variable updates.

### 7.6 Semaphore

A semaphore controls access to shared resources using wait and post operations.

When correctly implemented, it can prevent simultaneous access to a protected resource. The individual semaphore program produced:

```text
Counter=200000
```

## 8. Performance Analysis

The recorded benchmark demonstrates the following:

- The unsynchronized mechanism was the fastest but produced incorrect results with multiple threads.
- Critical sections maintained correctness but had higher execution times.
- Atomic operations maintained correctness and showed the best performance among the tested protected mechanisms in the recorded multi-thread runs.
- Locks maintained correctness but introduced synchronization overhead.
- Increasing the number of threads does not necessarily improve performance when access to a shared variable must be serialized.

## 9. Screenshots of Execution

### 9.1 Individual Synchronization Programs

The screenshot below shows the execution of the race-condition, critical-section, atomic-operation, barrier, and semaphore programs.

![Individual Synchronization Programs](evidence/individual_programs.png)

### 9.2 Synchronization Benchmark Results

The screenshot below shows the benchmark output comparing None, Critical, Atomic, and Lock mechanisms for 1, 2, 4, and 8 threads.

![Synchronization Benchmark Execution](evidence/benchmark_execution.png)

## 10. Conclusion

This experiment demonstrates the importance of synchronization in parallel programming.

Unsynchronized access to shared variables can cause race conditions and incorrect results. Critical sections, atomic operations, and locks help protect shared resources, while barriers coordinate the execution of threads and semaphores control access to shared resources.

Based on the recorded benchmark, atomic operations provided the best performance among the tested protected mechanisms for the multi-thread configurations.

Therefore, selecting an appropriate synchronization mechanism is important for achieving both correctness and performance in parallel applications.

## 11. Reproducibility

The source code, compilation commands, benchmark measurements, and execution screenshots are provided in this repository.

The programs can be compiled and executed on an Ubuntu Linux system with GCC and the required OpenMP or POSIX thread support.

Execution times may differ depending on hardware configuration, compiler version, thread scheduling, and system load.
