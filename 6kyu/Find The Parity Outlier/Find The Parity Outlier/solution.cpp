#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int FindOutlier(vector<int> &arr){
	vector<int> test;
	vector<int>::iterator it = arr.begin();
	while (it != arr.end()) {
		test.push_back(abs(*it % 2));
		++it;
	}
	vector<int>::iterator et = find(test.begin(), test.end(), 0);
	vector<int>::iterator ot = find(test.begin(), test.end(), 1);
	vector<int>::iterator ett = find(et + 1, test.end(), 0);
	it = arr.begin();
	if (ett == test.end())
		return *(it + distance(test.begin(), et));
	else
		return *(it + distance(test.begin(), ot));
}

//succinctest:
/*
int FindOutlier(std::vector<int> arr)
{
    int even;
    int odd;
  
    int evenCount = 0;
    int oddCount = 0;
  
    for (auto a : arr)
        a % 2 == 0 ? (evenCount++, even = a) : (oddCount++, odd = a);
  
    return evenCount < oddCount ? even : odd;
}*/

int main() {
	vector<int> arr = { 1,2,3 };
	int x = FindOutlier(arr);
	cout << x << endl;
	
	return 0;
}