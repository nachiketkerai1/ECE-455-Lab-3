#include <iostream>
#include <vector>
#include <omp.h>

int main() {
	const in N = 1024;
	std::vector<std::vector<int>> A(N , std::vector<int>(N , 1));
	std::vector<std::vector<int>> A(N , std::vector<int>(N , 2));
	std::vector<std::vector<int>> A(N , std::vector<int>(N , 3));

	#pragma omp parallel for 
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			int sum = 0;
			for (int k = 0; k < N; ++k) {
				sum += A[i][k] * B[k][j];
			}
			C[i][j] = sum;
		}
	}
	std::cout << "C[0][0] = " << C[0][0] << std:endl;
	return 0;
}
