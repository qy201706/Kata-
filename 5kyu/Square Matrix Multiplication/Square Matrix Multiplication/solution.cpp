#include <iostream>
#include <vector>


using namespace std;

std::vector<std::vector<int>> matrix_multiplication(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, size_t n) {
	vector<vector<int>> ans(n);
	int tmp = 0;
	for (int i = 0; i < a.size(); ++i) {
		for (int j = 0; j < b[0].size(); ++j) {
			for (int k = 0; k < b.size(); ++k) {
				tmp += a[i][k] * b[k][j];
			}
			ans[i].push_back(tmp);
			tmp = 0;
		}
	}
	return ans;
}

int main() {
	vector<vector<int>> a = { {1,2}, {3,4} };
	vector<vector<int>> b = { {1,1}, {1,1} };
	for (auto x : matrix_multiplication(a, b, 2)) {
		for (auto y : x) {
			cout << y << " ";
		}
		cout << endl;
	}
	return 0;
}