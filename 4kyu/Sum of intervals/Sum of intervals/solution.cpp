#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

int sum_intervals(std::vector<std::pair<int, int>> intervals);

bool rule(pair<int, int> n1, pair<int, int> n2);

int main() {
	vector<pair<int, int> > n(2);
	for (int i = 0; i < 2; ++i) {
		cin >> n[i].first >> n[i].second;
	}
	cout << sum_intervals(n);
	return 0;
}

int sum_intervals(std::vector<std::pair<int, int>> intervals){
	int sum = 0;
	int a = 0, b = 0;
	sort(intervals.begin(), intervals.end(), rule);
	a = intervals[0].first;
	b = intervals[0].second;
	for (int i = 1; i < intervals.size(); ++i) {
		if (b > intervals[i].first) {
			b = max(b, intervals[i].second);
		}
		else {
			sum += b - a;
			a = intervals[i].first;
			b = intervals[i].second;
		}
	}
	sum += b - a;
	return sum;
}

bool rule(pair<int, int> n1, pair<int, int> n2){
	return n1.first < n2.first;
}

/*best kata:
int sum_intervals(std::vector<std::pair<int, int>> intervals) {

  std::unordered_set<int> ints;
  for (auto interv = intervals.begin(); interv != intervals.end(); ++interv){
	for (int i = interv->first; i < interv->second; i++){
	  ints.insert(i);
	}
  }

return ints.size();
}*/