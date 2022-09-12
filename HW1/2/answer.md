# 2 a) 

|           | CPU-1             | CPU-2                         |
| --------- | ----------------- | ----------------------------- |
| Processor | AMD Ryzen 5 3550H | 12th Gen Intel Core i7 12650H |
| Cores     | 4                 | 10                            |
| Frequency | 2.1GHz            |  4.5GHz                       |
| RAM       | 16 GB             | 16gb                          |
| OS        | Windows           | Linux                         |
| Price     | $650              | $1000                         |

## CPU - 1

| Matrix-1    | Matrix-2    | CPU-time (Int) | CPU-time  (Double) |
| ----------- | ----------- | -------------- | ------------------ |
| 1145 x 1458 | 1458 x 2361 | 25.503         | 21.744             |
| ---         | ---         | ---            | ---                |
| 4500 x 2500 | 2500 x 6000 | 189.753        | 110.207            |
| ---         | ---         | ---            | ---                |
| 1568 x 3656 | 3656 x 2787 | 82.512         | 37.527             |
| ---         | ---         | ---            | ---                |
| 9855 x 4568 | 4568 x 3677 | 410.5853       | 248.969            |
| ---         | ---         | ---            | ---                |
| 235 x 157   | 157 x 658   | 35.89          | 15.074             |
| ---         | ---         | ---            | ---                |
| 895 x 258   | 258 x 478   | 30.771         | 17.13              |
| ---         | ---         | ---            | ---                |
|             | Avg         | 129.16905      | 75.1085            |

## CPU - 2

| Matrix-1    | Matrix-2    | CPU-time (Int) | CPU-time  (Double) |
| ----------- | ----------- | -------------- | ------------------ |
| 1145 x 1458 | 1458 x 2361 | 45.503         | 18.379             |
| 4500 x 2500 | 2500 x 6000 | 133.103        | 74.424             |
| 1568 x 3656 | 3656 x 2787 | 56.393         | 39.963             |
| 9855 x 4568 | 4568 x 3677 | 270.404        | 172.052            |
| 235 x 157   | 157 x 658   | 13.405         | 20.067             |
| 895 x 258   | 258 x 478   | 22.154         | 19.283             |
|             | Avg         | 90.16033333    | 57.36133333        |

# 2 b) 

## CPU - 1

| Matrix-1    | Matrix-2    | CPU-time (Int) | CPU-time  (Double) |
| ----------- | ----------- | -------------- | ------------------ |
| 1145 x 1458 | 1458 x 2361 | 22.206         | 21.746             |
| ---         | ---         | ---            | ---                |
| 4500 x 2500 | 2500 x 6000 | 179.238        | 109.563            |
| ---         | ---         | ---            | ---                |
| 1568 x 3656 | 3656 x 2787 | 48.659         | 38.305             |
| ---         | ---         | ---            | ---                |
| 9855 x 4568 | 4568 x 3677 | 359.74         | 249.573            |
| ---         | ---         | ---            | ---                |
| 235 x 157   | 157 x 658   | 27.466         | 33.155             |
| ---         | ---         | ---            | ---                |
| 895 x 258   | 258 x 478   | 26.312         | 26.82              |
| ---         | ---         | ---            | ---                |
|             | Avg         | 110.6035       | 79.86033333        |
| ---         | ---         | ---            | ---                |

## CPU - 2

| Matrix-1    | Matrix-2    | CPU-time (Int) | CPU-time  (Double) |
| ----------- | ----------- | -------------- | ------------------ |
| 1145 x 1458 | 1458 x 2361 | 25.657         | 21.746             |
| ---         | ---         | ---            | ---                |
| 4500 x 2500 | 2500 x 6000 | 127.985        | 65.268             |
| ---         | ---         | ---            | ---                |
| 1568 x 3656 | 3656 x 2787 | 46.145         | 34.589             |
| ---         | ---         | ---            | ---                |
| 9855 x 4568 | 4568 x 3677 | 283.268        | 138.68             |
| ---         | ---         | ---            | ---                |
| 235 x 157   | 157 x 658   | 14.658         | 26.358             |
| ---         | ---         | ---            | ---                |
| 895 x 258   | 258 x 478   | 16.354         | 15.368             |
| ---         | ---         | ---            | ---                |
|             | Avg         | 85.67783333    | 50.33483333        |
| ---         | ---         | ---            | ---                |

## 2 a)

Measure the time it takes each program to complete (2x5)
Performance of CPU-1 (int) = 129.16905 s
Performance of CPU-1 (double) = 75.1085 s

Performance of CPU-2 (int) = 90.16033333 s
Performance of CPU-2 (double) = 57.36133333 s

compare the performance of the two systems (5)
CPU-1/ CPU-2 (int) = 1.43

CPU-2 is 43% faster than CPU-1

CPU-1 / CPU-2 (double) = 1.3

CPU-2 is 30% faster than CPU-1

Is the performance ratio the same as the clock rate ratio of the two systems (5)?

Clock ratio
CPU-2 / CPU-1 = 2.14

CPU -2 is 114% faster than CPU-1

The clock rate is not the same as performance ratio. The real time performance depends on various factors such as the memory type (faster the memory faster the access time), background processes.

Based on the retail price of the two systems, which one is more cost effective (5)?

Based on the retail price, CPU-2 is more cost effective since you get 40% (avg of all the performance ratios) more performance for difference of $350

## 2 b)

Performance of CPU-1 (int) = 110.6035 s
Performance of CPU-1 (double) = 79.86033333 s

Performance of CPU-2 (int) = 85.67783333 s
Performance of CPU-2 (double) = 50.33483333 s

CPU-1/ CPU-2 (int) = 1.29

CPU-2 is 29% faster than CPU-1

CPU-1 / CPU-2 (double) = 1.58

CPU-2 is 58% faster than CPU-1

s = time in seconds
