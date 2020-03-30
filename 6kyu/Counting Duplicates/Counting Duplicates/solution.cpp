#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

//2020/3/30 mine
size_t duplicateCount(const string& in) {
	int i = 0, ans = 0;
	while (in.begin() + i != in.end()) {
		//dist = distance(in.begin(), find(in.begin() + i + 1, in.end(), in[i]));
		if (find(in.begin(), in.begin() + i, in[i]) != in.begin() + i || find(in.begin(), in.begin() + i, in[i] + 32) != in.begin() + i || 
			find(in.begin(), in.begin() + i, in[i] - 32) != in.begin() + i) {
			++i;
			continue;
		}
		if (find(in.begin() + i + 1, in.end(), in[i]) != in.end() || find(in.begin() + i + 1, in.end(), in[i] + 32) != in.end() ||
			find(in.begin() + i + 1, in.end(), in[i] - 32) != in.end()) {
			++ans;
		}
		++i;
	}
	return ans;
}

int main() {
	cout<< duplicateCount("aA11"); //����const�����޸��ַ�����...ͨ����test���ǳ��˵��ض������⣬��֪����ô����
	return 0;
}