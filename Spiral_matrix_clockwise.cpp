#include <cmath>
#include <iostream>
#include <random>
#include <vector>

using std::cin;
using std::cout;
using std::default_random_engine;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;
using std::vector;

void PrintMatrixClockwise(const vector<vector<int>> &A, int offset);

void PrintMatrixInSpiralOrder(const vector<vector<int>> &A) {
	int xMin = 0, xMax = A.size() - 1, yMin = 0, yMax = A.size() - 1, xIncrement = 0, yIncrement = 1; // initial goes right
	int x = xMin, y = yMin;
	while (xMin <= x && x <= xMax && yMin <= y && y <= yMax) {
		cout << A[x][y] << ' ';

		if (x == xMin && y == yMin && xIncrement == -1) { // finished one circle, go right
			xIncrement = 0;
			yIncrement = 1;
			++yMin;
		}
		else if (x == xMin && y == yMax && yIncrement == 1) { // go down
			xIncrement = 1;
			yIncrement = 0;
			++xMin;
		}
		else if (x == xMax && y == yMax && xIncrement == 1) { // go left
			xIncrement = 0;
			yIncrement = -1;
			--yMax;
		}
		else if (x == xMax && y == yMin && yIncrement == -1) { // go up
			xIncrement = -1;
			yIncrement = 0;
			--xMax;
		}

		x += xIncrement;
		y += yIncrement;
	}
}

int main(int argc, char *argv[]) {
	int N;
	while (1) {
		cin >> N;

		if (N == -1) {
			break;
		}

		vector<vector<int>> A(N, vector<int>(N));
		int x = 1;
		for (size_t i = 0; i < N; ++i) {
			for (size_t j = 0; j < N; ++j) {
				A[i][j] = x++;
			}
		}
		PrintMatrixInSpiralOrder(A);
		cout << endl;
	}

	return 0;
}
