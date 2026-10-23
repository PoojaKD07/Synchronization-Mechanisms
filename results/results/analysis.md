# Experimental Results and Analysis

## Experiment Setup

The benchmark evaluates 10,000,000 shared counter increments using 1, 2, 4, and 8 threads.

## Results

The recorded benchmark shows that the unsynchronized implementation can produce an incorrect final counter when multiple threads update shared data concurrently. Critical sections, atomic operations, and locks produce the expected final count.

## Observations

- **No synchronization:** The fastest measured approach, but it loses updates under concurrent execution.
- **Critical section:** Correctly protects shared updates, with increasing overhead as thread count increases.
- **Atomic operation:** Produces the correct counter and has the lowest recorded time among the protected mechanisms in the multi-thread runs.
- **Lock:** Maintains correctness but incurs synchronization overhead.
- **Barrier:** Coordinates thread progress between phases. A barrier alone does not protect shared variables.

## Conclusion

Synchronization mechanisms are essential for correctness in shared-memory parallel programs. The recorded results demonstrate a trade-off between execution time and safe access to shared data. Atomic operations performed particularly well in the tested multi-thread runs.

## Reproducibility Note

Execution times depend on hardware, compiler settings, scheduling, and system load. The CSV contains the measurements recorded during this experiment and should not be interpreted as guaranteed performance on other systems.
