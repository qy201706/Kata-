#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//mine:   =(  It can be shortened sharply!! best practice is under mine.
string factors(int lst) {
	stringstream ss;
	string ans;
	for (int i = 2; lst != 1; ++i) {
		if (lst % i == 0) {
			ss << (to_string(i) + " ");
			lst /= i;
			i -= 1;
		}
	}
	int i = 1, j = 0;
	for (string str; ss >> str; ) {
		if(ans.size() == 0){
			ans.push_back('(');
			ans += str;
			j = str.size();
			continue;
		}
		else if (str.size() == j && str == ans.substr(ans.size() - str.size(), str.size())) {
			++i;
			continue;
		}
		if (i > 1) {
			ans += "**";
			ans += to_string(i);
			i = 1;
		}
		ans.push_back(')');
		ans.push_back('(');
		ans += str;

		j = str.size();
	}
	if (i > 1)
		ans += to_string(i);
	ans.push_back(')');
	return ans;
}

//best_practice:
//std::string factor(int n) {
//	std::ostringstream res;
//	for (int i = 2; n > 1; i++) {
//		int k = 0;
//		while (n % i == 0) {
//			n /= i;
//			k++;
//		}
//		if (k == 1)
//			res << '(' << i << ')';
//		else if (k > 1)
//			res << '(' << i << "**" << k << ')';
//	}
//	return res.str();
//}

int main() {
	int lst = 718167069;
	cout << factors(lst);
	/*stringstream ss;
	ss << to_string(11) + " " + to_string(12);
	string str;
	cout << str;*/
	return 0;
}
