#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>
#include <cmath>

using namespace std;

long long show_inverse(string &str) {
	int t = 0;
	for (int i = 0, j = 0; i < str.size(); ++i) {
		char original = char(i + '0');
		while (i + j < str.size()) {
			char test = char(i + j + '0');
			if(find(str.begin(), str.end(), test) - find(str.begin(), str.end(), original)< 0)
				++t;
			++j;
		}
		j = 1;
	}
	return t;
}

long long determinant(vector< vector<long long> > m) {
	vector<string> result;
	long long sum = 0, key = 0, lamda = 1, t = 0;//key is num of row, lamda is a temp num, t is inverse number 
	string tmp("");
	for (int i = 0; i < m.size(); ++i)
		tmp += to_string(i);
	result.push_back(tmp);
	while (next_permutation(tmp.begin(), tmp.end()))
		result.push_back(tmp);
	
	for (int i = 0; i < result.size(); ++i) {
		t = show_inverse(result[i]);
		//cout << t << endl;
		for (int j = 0; j < tmp.size(); ++j) {
			key = int(result[i][j] - '0');
			lamda *= m[key][j];
		}
		sum += (lamda * pow(-1, t));
		lamda = 1;
	}
	return sum;
}

int main() {
	vector< vector<long long> > m = { {1,2,}, {3, 4} };
	cout << determinant(m);
	return 0;
}