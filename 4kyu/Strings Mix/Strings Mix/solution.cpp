#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//Mine:

//void get_max(string &num, string &result) {
//	string equel("");
//	int size = 0;
//	int tmp = num.find_first_not_of('0');
//	while (tmp != num.npos) {
//		for (int i = tmp + 1; i < 52; ++i) {
//			if (num[tmp] < num[i]) {
//				tmp = i;
//			}
//		}
//		
//		if (equel.size() != 0 && int(num[tmp] - '0') < size) {
//			if (result.back() == '/')
//				result.erase(result.end() - 1);
//			result += "/" + equel;
//			equel = "";
//			size = 0;
//		}
//		if (result.size() != 0 && result.back() == '/')
//			result.erase(result.end() - 1);
//		if (result.size() > 0)
//			result += "/";
//		if (tmp >= 26) {
//			result += "2:";
//		}
//		else if (num[tmp + 26] == num[tmp]) {
//			if (equel.size() != 0)
//				equel += "/";
//			equel += "=:";
//			for (int i = 0; i < int(num[tmp] - '0'); ++i) {
//				equel += char(tmp + 97);
//			}
//			if(equel.find('/') == equel.npos)
//				size = distance(equel.begin() + 2, find(equel.begin() + 1, equel.end(), '='));
//			num[tmp] = '0';
//			num[tmp + 26] = '0';
//			tmp = num.find_first_not_of('0');
//			continue;
//		}
//		else {
//			result += "1:";
//		}
//		for (int i = 0; i < int(num[tmp] - '0'); ++i) {
//			if (tmp > 25)
//				result += char(tmp - 26 + 97);
//			else
//				result += char(tmp + 97);
//		}
//		num[tmp] = '0';
//		tmp = num.find_first_not_of('0');
//	}
//	if (result.back() == '/')
//		result.erase(result.end() - 1);
//	if (equel.size() > 0)
//		result += "/" + equel;
//}
//
//static std::string mix(const std::string &s1, const std::string &s2) {
//	string s1t(s1), s2t(s2);
//	sort(s1t.begin(), s1t.end());
//	sort(s2t.begin(), s2t.end());
//	string num, result;
//	for (int i = 0; i < 52; ++i)
//		num += '0';
//	int f1 = 0, f2 = 0, tmp = 0;
//	int key = 97; // a
//	int ff = 0; // iterator for num
//	for (int i = 0; i < s1t.size(); ++i) {
//		if (s1t[i] < 97)
//			continue;
//		f1 = i;
//		break;
//	}
//	for (int i = 0; i < s2t.size(); ++i) {
//		if (s2t[i] < 97)
//			continue;
//		f2 = i;
//		break;
//	}
//	for (int k = 0; f1 < s1t.size(); ++k, ++key) {
//		if (find(s1t.begin() + f1, s1t.end(), char(key)) == s1t.end())
//			continue;
//		tmp = s1t.find_last_of(char(key)) - f1 + 1;
//		f1 += tmp;
//		if (tmp < 2)
//			tmp = 0;
//		num[k] += tmp;
//	}
//	key = 97;
//	for (int k = 26; f2 < s2t.size(); ++k, ++key) {
//		if (find(s2t.begin() + f2, s2t.end(), char(key)) == s2t.end())
//			continue;
//		tmp = s2t.find_last_of(char(key)) - f2 + 1;
//		f2 += tmp;
//		if (tmp < 2)
//			tmp = 0;
//		num[k] += tmp;
//	}
//	for (int i = 0; i < 26; ++i) {
//		if (num[i] > num[i + 26]) {
//			num[i + 26] = '0';
//		}
//		else if (num[i] < num[i + 26]) {
//			num[i] = '0';
//		}
//	}
//	get_max(num, result);
//	return result;
//}

//best practice:

static std::string mix(const std::string &s1, const std::string &s2) {
	string rv;
	int aFreq[26] = { 0 }, bFreq[26] = { 0 };
	vector<pair<string, string>> table;
	for (auto c : s1) if (islower(c)) aFreq[c - 'a']++;
	for (auto c : s2) if (islower(c)) bFreq[c - 'a']++;
	for (int i = 0; i < 26; i++) {
		int frequency = max(aFreq[i], bFreq[i]);
		if (frequency <= 1) continue;
		string stringLoc = "=";
		if (aFreq[i] != bFreq[i]) stringLoc = ((aFreq[i] > bFreq[i]) ? "1" : "2");
		table.push_back(make_pair(string(frequency, ((char)('a' + i))), stringLoc));
	}
	sort(table.begin(), table.end(), [](pair<string, string> a, pair<string, string> b) {
		if (a.first.length() != b.first.length()) return (a.first.length() > b.first.length());
		return (a.second + ":" + a.first < b.second + ":" + b.first);
	});
	for (auto x : table)
		rv += x.second + ":" + x.first + "/";
	return rv.substr(0, rv.length() - 1);
}

int main() {
	string s1 = "my&friend&Paul has heavy hats! &";
	string s2 = "my friend John has many many friends &";
	cout << mix(s1, s2); //-- > "2:nnnnn/1:aaaa/1:hhh/2:mmm/2:yyy/2:dd/2:ff/2:ii/2:rr/=:ee/=:ss"
	return 0;
}