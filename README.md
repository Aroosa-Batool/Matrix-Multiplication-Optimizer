#Matrix multiplication

Matrix multiplication is a common operation in many applications, and optimizing it can lead to significant performance gains.

##Original Task
Matrix multiplication involves multiplying two matrices (A) and (B) to produce a matrix (C). The naive approach has a time complexity of (O(n^3)).

##Optimized Task
We’ll use loop unrolling and cache-friendly data structures to optimize the matrix multiplication.

#Explanation
Loop Unrolling: The inner loop is unrolled by a factor of 4 to reduce the overhead of loop control statements.
Cache-Friendly: By accessing elements in a sequential manner, we improve cache performance.

#Compilation
To compile and run this code, use:  
g++ -O2 -o matrix_multiplication matrix_multiplication.cpp
./matrix_multiplication
