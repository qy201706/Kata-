#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <regex>
#include <sstream>

using namespace std;

class WhichAreIn
{
public:
	static vector<string> inArray(vector<string> &array1, vector<string> &array2);
};

//首次构思：运行时间太长
//vector<string> WhichAreIn::inArray(vector<string> &array1, vector<string> &array2) {
//	int num = 0;
//	stringstream ss;
//	string tmp;
//	vector<string>::iterator lt = array1.begin();
//	vector<string>::iterator it = array2.begin();
//	while (lt != array1.end()) {
//		while (it != array2.end()) {
//			ss << *it;
//			tmp = ss.str();
//			ss.str("");
//			if (tmp.find(*lt) != tmp.npos) {
//				++lt;
//				++num;
//				break;
//			}
//			else if (it + 1 == array2.end()) {
//				array1.erase(lt);
//				lt = array1.begin() + num;
//			}
//			++it;
//		}
//		it = array2.begin();
//		
//	}
//	sort(array1.begin(), array1.end());
//	return array1;
//}

//第二种想法：(和评论里最优解一致nice!)
vector<string> WhichAreIn::inArray(vector<string> &array1, vector<string> &array2) {
	string str1;
	stringstream ss;
	for (auto x : array2) {
		ss << x;
	}
	str1 = ss.str();
	ss.str("");
	int num = 0;
	for (vector<string>::iterator y = array1.begin(); y != array1.end(); ) {
		if (str1.find(*y) != str1.npos) {
			++y;
			++num;
			continue;
		}
		else {
			array1.erase(y);
			y = array1.begin() + num;
		}
	}
	sort(array1.begin(), array1.end());
	return array1;
}

int main() {
	std::vector<std::string> arr1 = { "tarp", "mice", "bull" };
	std::vector<std::string> arr2 = { "lively", "alive", "harp", "sharp", "armstrong" };
	std::vector<std::string> sol1 = { "arp", "live", "strong" };
	std::vector<std::string> ans1 = WhichAreIn::inArray(arr1, arr2);
	for (auto x : ans1)
		cout << x << " ";
	//cout << endl;
	//cout << "yeah" << endl;
	return 0;
}