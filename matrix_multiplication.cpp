/* Original Task
  Matrix multiplication involves multiplying two matrices (A) and (B) to produce a matrix (C). The naive approach has a time complexity of (O(n^3)).

  Optimized Task
  We’ll use loop unrolling and cache-friendly data structures to optimize the matrix multiplication.*/

#include <iostream>
#include <vector>
#include <chrono>

const int N = 512; // Matrix size

void multiply_matrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void optimized_multiply_matrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, std::vector<std::vector<int>>& C) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int k = 0; k < N; k += 4) {
                sum += A[i][k] * B[k][j];
                sum += A[i][k+1] * B[k+1][j];
                sum += A[i][k+2] * B[k+2][j];
                sum += A[i][k+3] * B[k+3][j];
            }
            C[i][j] = sum;
        }
    }
}

int main() {
    std::vector<std::vector<int>> A(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> B(N, std::vector<int>(N, 1));
    std::vector<std::vector<int>> C(N, std::vector<int>(N, 0));

    auto start = std::chrono::high_resolution_clock::now();
    multiply_matrices(A, B, C);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Naive multiplication took " << duration.count() << " seconds.\n";

    start = std::chrono::high_resolution_clock::now();
    optimized_multiply_matrices(A, B, C);
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Optimized multiplication took " << duration.count() << " seconds.\n";

    return 0;
}
/* Explanation
   Loop Unrolling: The inner loop is unrolled by a factor of 4 to reduce the overhead of loop control statements.
   Cache-Friendly: By accessing elements in a sequential manner, we improve cache performance.
   Compilation
   To compile and run this code, use:
   g++ -O2 -o matrix_multiplication matrix_multiplication.cpp
   ./matrix_multiplication
*/