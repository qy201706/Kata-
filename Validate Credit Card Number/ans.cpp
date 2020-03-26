#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//Luhn Algorithm
bool Validate(long long n) {
	int tmp, nf = 0;
	string str = to_string(n);
	cout << str << endl;
	for (int i = 1; i < str.size(); i = i + 2) {
		cout << str[i] << endl;
		str[i] = (char)((int)(str[i] - '0') * 2 + '0');
		if ((int)(str[i] - '0') > 9) {
			str[i] = (char)((int)(str[i] - '0') - 9 + '0');
		}
	}
	cout << str << endl;
	for (int i = 0; i < str.size(); ++i) {
		nf += (int)(str[i] - '0');

	}
	tmp = nf % 10;
	if (!tmp)
		return true;
	else
		return false;
}

int main() {
	long long n;
	cin >> n;
	int tmp, nf = 0;
	string str = to_string(n);
	for (int i = str.size() - 2; i >= 0; i = i - 2) {
		str[i] = (char)((int)(str[i] - '0') * 2 + '0');
		if ((int)(str[i] - '0') > 9) {
			str[i] = (char)((int)(str[i] - '0') - 9 + '0');
		}
	}
	for (int i = 0; i < str.size(); ++i) {
		nf += (int)(str[i] - '0');
		//cout << str[i] << endl;
	}
	tmp = nf % 10;
	if (!tmp)
		cout << "You are right";
	else
		cout << "There is something wrong";
	return 0;
}