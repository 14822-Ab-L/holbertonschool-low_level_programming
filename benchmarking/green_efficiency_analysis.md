# Green Efficiency Analysis

## Measurement Methodology

This project measured program execution time using the `clock()` function from the C standard library. All programs were compiled with the required GCC flags and executed three consecutive times under the same development environment to reduce the effect of normal timing variation.

The first activity established a baseline by timing a deterministic loop with 100,000,000 iterations. The recorded execution times were 0.226884 seconds, 0.227041 seconds, and 0.227927 seconds, showing only small differences between runs.

The second activity compared two implementations solving the same problem. The naive algorithm recorded execution times of 2.777511 seconds, 2.754693 seconds, and 2.755271 seconds, giving an average of approximately 2.762492 seconds. The single-pass algorithm consistently completed in 0.000106 seconds across all three runs.

The final activity added timing instrumentation to a program with three separate phases. Using `clock()` before and after each phase made it possible to measure the time spent building the dataset, processing it, reducing it into a checksum, and the total runtime. This approach identified where execution time was spent without changing the program's behaviour.

## Observed Performance Differences

The baseline experiment showed that repeated executions of the same program produced very similar execution times. Although the measurements were not identical, the variation was small, indicating that short timing differences are normal even when the workload remains unchanged.

The largest performance difference was observed in the algorithm comparison. The naive implementation averaged approximately 2.762492 seconds, while the single-pass implementation averaged 0.000106 seconds. This means the naive implementation was approximately 26,061 times slower than the single-pass version. Although both programs solved the same problem, the nested-loop approach performed significantly more work than the single-pass implementation, which explains the large difference in execution time.

The instrumentation experiment also provided useful information about where time was spent within a single program. Across the three runs, the BUILD_DATA phase took approximately 0.000297 seconds on average, PROCESS averaged 0.000310 seconds, and REDUCE averaged 0.000131 seconds, with the total runtime averaging approximately 0.000743 seconds. The PROCESS phase consistently required the most time, while the REDUCE phase required the least.

## Relation Between Runtime and Energy Consumption

Although this project did not directly measure electrical power usage, the recorded execution times provide evidence that programs requiring more processing time also require the CPU to remain active for longer. The comparison experiment demonstrated this clearly, with the naive algorithm running for approximately 2.76 seconds compared with 0.000106 seconds for the single-pass implementation.

The instrumentation activity also showed that not every part of a program contributes equally to the total runtime. Since the PROCESS phase consistently consumed the largest portion of execution time, it would likely be the first area to investigate if performance improvements were required.

## Limitations of the Experiment

Several factors may influence the recorded timings. Background operating system tasks, CPU scheduling, and differences in hardware can all introduce small variations between runs. This was visible in the baseline experiment, where the three execution times differed slightly despite using the same program and input.

Another limitation is that execution time alone does not directly measure energy consumption. The conclusions in this report are based on runtime measurements, which provide an indication of computational work but do not quantify actual electrical power usage.

## Practical Engineering Takeaway

These experiments demonstrated that measuring execution time is a practical way to evaluate software performance. The baseline activity showed that repeated measurements naturally vary slightly, making multiple runs important for obtaining reliable results. The algorithm comparison demonstrated that selecting an efficient algorithm has a much greater impact on performance than minor timing differences, with the single-pass implementation performing substantially better than the naive approach. Finally, the instrumentation activity showed that measuring individual phases helps identify where execution time is spent, making it easier to focus optimisation efforts on the parts of a program that contribute most to the overall runtime.
