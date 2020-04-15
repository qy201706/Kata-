#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <Windows.h>

using namespace std;

void ppp(string &s, int start, int end, vector<string> &ans) {
	char ch;
	if (start == end) {
		ans.push_back(s);
	}
	else {
		for (int i = start; i <= end; ++i) {
			ch = s[start];
			s[start] = s[i];
			s[i] = ch;
			ppp(s, start + 1, end, ans);
			ch = s[start];
			s[start] = s[i];
			s[i] = ch;
		}
	}
}

vector<string> permutations(string s) {
	vector<string> ans;
	int start = 0;
	int end = s.size() - 1;
	if (s == "") {                //Notifying!!
		ans.push_back(s);
		return ans;
	}
	ppp(s, start, end, ans);
	for (auto it = ans.begin(); it != ans.end(); ++it) {
		for (auto lt = it + 1; lt != ans.end(); ) {
			if (*lt == *it) {
				lt = ans.erase(lt);
				continue;
			}
			++lt;
		}
	}
	return ans;
}

//int srand_own() {
//	LARGE_INTEGER seed;
//	QueryPerformanceFrequency(&seed);
//	QueryPerformanceCounter(&seed);
//	srand(seed.QuadPart);//初始化一个以微秒为单位的时间种子
//	int index = rand() % 10;//产生一个随机数
//	return index;
//}

int main() {
	cout << "result:";
	for (auto x : permutations("")) {
		cout << x;
	}
	return 0;
}

//Record best trainning:
/*string getStringWithSwappedChars(string str, int i, int j) {
  string res = "";
  for (int k = 0; k < str.length(); k++) {
    res += k == i ? str[j] : k == j ? str[i] : str[k];
  }
  return res;
}

void fillSet(string str, int left, int right, set<string> &set) {
  if (left == right) {
    set.insert(str);
  }
  else {
    for (int i = left; i <= right; i++) {
      fillSet(getStringWithSwappedChars(str, left, i), left + 1, right, set);
    }
  }
}

vector<string> permutations(string s) {
  if (s.length() == 0) {
    return vector<string>{""};
  }
  set<string> set;
  fillSet(s, 0, s.size() - 1, set);
  return vector<string> (set.begin(), set.end());
}*/