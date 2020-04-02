#include <iostream>
#include <string>

using namespace std;

int solution(int number) {
	int ans = 0;
	for (int i = 3; i < number; ++i) {
		if (i % 5 == 0 || i % 3 == 0) {
			ans += i;
		}
	}
	return ans;
}

int main() {
	cout << solution(10);
	return 0;
}