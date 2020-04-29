#include <iostream>
#include <string>

using namespace std;

bool validSolution(unsigned int board[9][9]) {
	/* Write your solution here */
	string str = "123456789";
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (str.find(to_string(board[i][j])) == str.npos || board[i][j] == 0)
				return false;
			str[str.find(to_string(board[i][j]))] = '0';
		}
		str = "123456789";
	}
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			if (str.find(to_string(board[j][i])) == str.npos || board[j][i] == 0)
				return false;
			str[str.find(to_string(board[j][i]))] = '0';
		}
		str = "123456789";
	}
	for (int i = 0, j = 3; j <= 9; i += 3, j += 3) {
			for (int k = 0, l = 3; l <= 9; k += 3, l += 3) {
					for (int m = i; m < j; ++m) {
						for (int n = k; n < l; ++n) {
							if (board[m][n] == 0 || str.find(to_string(board[m][n])) == str.npos)
								return false;
							str[str.find(to_string(board[m][n]))] = '0';
						}
					}
					str = "123456789";
			}
	}
	return true;
}

int main() {
	unsigned int example1[9][9] = { {5, 3, 4, 6, 7, 8, 9, 1, 2},
							 {6, 7, 2, 1, 9, 5, 3, 4, 8},
							 {1, 9, 8, 3, 4, 2, 5, 6, 7},
							 {8, 5, 9, 7, 6, 1, 4, 2, 3},
							 {4, 2, 6, 8, 5, 3, 7, 9, 1},
							 {7, 1, 3, 9, 2, 4, 8, 5, 6},
							 {9, 6, 1, 5, 3, 7, 2, 8, 4},
							 {2, 8, 7, 4, 1, 9, 6, 3, 5},
							 {3, 4, 5, 2, 8, 6, 1, 7, 9} };
	cout << validSolution(example1);
	return 0;
}