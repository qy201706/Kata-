#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

std::string brainLuck(const std::string &code, const std::string &input) {
	string ans = "";
	stringstream ss;
	char ch = '0';
	for (int i = 0,j = 0; i < code.size(); ++i) {
		if (code[i] == ',') {
			ss.str("");
			ss << input[j];
			++j;
			continue;
		}
		if (code[i] == '[' && input[j] == 0) {
			i = distance(code.begin(), find(code.begin() + i, code.end(), ']'));
			continue;
		}
		if (code[i] == ']' && input[j] != 0) {
			i = distance(code.begin(), find(code.begin(), code.begin() + i, '['));
			continue;
		}
		if (code[i] == '>') {
			++j;
			continue;
		}
		if (code[i] == '<') {
			--j;
			continue;
		}
		ss >> ch;
		ss.str("");
		if (code[i] == '+') {
			ch += 1;
		}
		if (code[i] == '-'){
			ch -= 1;
		}
		if (code[i] == '.') {
			ans.push_back(ch);
		}
		ss << ch;
	}
	return ans;
}

int main() {
	/*string tw = "codewars";
	tw.append(1, (char)255);
	cout << brainLuck(",+[-.,+]", tw);*/
	std::string dw;
	dw.append(1, (char)7);
	dw.append(1, (char)3);
	cout << brainLuck(",>,<[>[->+>+<<]>>[-<<+>>]<<<-]>>.", dw);
	return 0;
}