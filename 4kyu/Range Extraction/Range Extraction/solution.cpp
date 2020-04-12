#include <iostream>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>

using namespace std;

std::string range_extraction(std::vector<int> args) {
	string s = "";
	int j = 0;
	for (auto it = args.begin(); it != args.end(); ++it) {
		if (it == args.end() - 1) {
			if (j > 1)
				s += '-';
			else if (j == 1)
				s += ',';
			s += to_string(*it);
			break;
		}
		if (*it + 1 == *(it + 1)) {
			++j;
			if (j == 1) {
				s += to_string(*it);
			}
			continue;
		}
		else if(j > 1){
			s += '-';
		}
		else if(j == 1){
			s += ',';
		}
		s += to_string(*it);
		s += ',';
		j = 0;
	}
	return s;
}

//Best trainning on Kata:

//#include <string>
//#include <set>
//
//std::string range_extraction(std::vector<int> args)
//{
//	using Range = std::pair<int, int>;
//	std::vector<Range> ranges;
//	for (auto &i : args)
//		if (ranges.empty() || ranges.back().second + 1 != i)
//			ranges.push_back({ i, i });
//		else
//			++ranges.back().second;
//
//	std::string result;
//	for (auto &r : ranges)
//		if (r.first == r.second)
//			result.append(std::to_string(r.first) + ",");
//		else
//			result.append(std::to_string(r.first) +
//			((r.first + 1 == r.second) ? ',' : '-') +
//				std::to_string(r.second) +
//				",");
//	result.pop_back();
//	return result;
//}

int main() {
	vector<int> range = { 18,19,20,22,23 };
	//cout << *range.end();
	cout << range_extraction(range);
	return 0;
}