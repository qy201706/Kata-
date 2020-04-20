#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

//try use recursion:failed

//void ggg(int i, int j, string &observed, string &xn_1, vector<string> &ans) {
//	if (j > 5) {
//		return;
//	}
//	int key = int(observed[i] - '0');
//	switch (j) {
//	case 0:
//		break;
//	case 1:
//		if (key - 1 > 0 && (key - 1) % 3 != 0) {
//			xn_1[i] = char(key - 1 + '0');
//		}
//		break;
//	case 2:
//		if (key - 3 > 0) {
//			xn_1[i] = char(key - 3 + '0');
//		}
//		break;
//	case 3:
//		if (key + 1 != 4 or 7) {
//			xn_1[i] = char(key + 1 + '0');
//		}
//		break;
//	case 4:
//		if (key + 3 < 9) {
//			xn_1[i] = char(key + 3 + '0');
//		}
//		break;
//	case 5:
//		if (key == 0)
//			xn_1[i] = char(8 + '0');
//	}
//	ans.push_back(xn_1);
//	ggg(i, j + 1, observed, xn_1, ans);
//	j = 0;
//	if (i == 0)
//		return;
//	ggg(i - 1, j, observed, xn_1, ans);
//}
//
//std::vector<std::string> get_pins(std::string observed) {
//	int j = 0; //j for switch
//	vector<string> ans;
//	string tmp = observed;
//	int key = 0; //key for observed[i]
//	if (observed.size() == 0)
//		return ans;
//	
//	for (int i = observed.size() - 1; i >= 0; --i) {
//		//ggg(i + 1, j, observed, tmp, ans);
//		ggg(i, j, observed, tmp, ans);
//		tmp = observed;
//	}
//	auto new_end = unique(ans.begin(), ans.end());
//	ans.erase(new_end, ans.end());
//	//ggg(0, observed.size() - 1, ans, observed, tmp);
//	return ans;
//}

//vector<string> dict = { "08", "124", "1235", "236", "1457", "24568", "3569", "478", "57890", "689" };
//
//std::vector<std::string> get_pins(std::string observed) {
//	vector<string> ans;
//	string tmp;
//	if (observed.size() == 0) {
//		ans.push_back(observed);
//		return ans;
//	}
//	for (int i = 0; i < observed.size(); ++i) {
//		int key = int(observed[i] - '0');
//		tmp += dict[key];
//	}
//	while (next_permutation(tmp.begin(), tmp.end())) {
//		ans.push_back(tmp);
//	}
//	auto new_end = unique(ans.begin(), ans.end());
//	ans.erase(new_end, ans.end());
//	return ans;
//}

// base5:
static std::vector< std::vector<std::string> > combinations = {
	 {"0","8","#","#","#"},
	 {"1","2","4","#","#"},
	 {"2","1","3","5","#"},
	 {"3","2","6","#","#"},
	 {"4","1","5","7","#"},
	 {"5","2","4","6","8"},
	 {"6","3","5","9","#"},
	 {"7","4","8","#","#"},
	 {"8","5","7","9","0"},
	 {"9","6","8","#","#"}
};

std::string to_base5(unsigned int n) {
	std::string result;
	static const char alphabet[] = "01234";
	while (n) { result += alphabet[n % 5]; n /= 5; }
	return std::string(result.rbegin(), result.rend());
}

unsigned int getIteration(unsigned int length) {
	unsigned int n = 0;
	for (int i = 0; i < length; n += 4 * pow(5, i++));
		return n;
}

std::vector<std::string> get_pins(std::string observed) {
	std::vector<std::string> possible_pins;

	for (int i = 0; i <= getIteration(observed.length()); i++) {
		std::string base5 = to_base5(i), temp = "";
		while (base5.length() != observed.length()) base5 = "0" + base5;
		cout << base5 << endl;
		for (int j = 0; j < observed.length(); j++) {
			temp += combinations[observed[j] - 48][base5[j] - 48];
			cout << temp << endl;
		}
		if (temp.find('#') == std::string::npos)
			possible_pins.push_back(temp);
	}
	return possible_pins;
}

int main() {
	for (auto x : get_pins("123")) {
		for (auto y : x) {
			cout << y;
		}
		cout << ",";
	}
	//vector<string> str = get_pins("12");
	return 0;
}

/*#include <string>
#include <vector>
using namespace std;
static bool isInRange(int num, int org)
 {
  switch (org)
  {
  case 11:
  case 5:
  case 8:
  case 2:
    return ((num > 0 && num < 10) || num == 11);
  case 1:
  case 4:
  case 7:
    return ((num - org != -1) && ((num > 0 && num < 10) || num == 11));
  case 3:
  case 6:
  case 9:
    return ((num - org != 1) && ((num > 0 && num < 10) || num == 11));
  default:
    return false;
  }
 }
 static int getNum(char c)
 {
  if (c == '0')
    return 11;
  return (c - '0');
 }

 vector<string> get_pins(const string & observe)
 {
  int tmpInt = 1;
  int addnum[] = {0, -1, 1, -3, 3}; 
  int n = observe.size();
  vector<int> p(n, 0);
  string tmpStr(n, '-');
  vector<string> res;
  int k = 1;
  
  while (k > 0)
  {
    if (p[k - 1] <= 4){
      tmpInt = getNum(observe[k - 1])+ addnum[p[k - 1]]; 
      if (tmpInt == 11) tmpInt = 0; 
      
      tmpStr[k - 1] = (char(tmpInt + '0'));
      k++; // go to next line
      
      if (k > n){ // get the answer
        res.push_back(tmpStr);
        k = n;
        // get the next number within a reasonable range
        do{
          p[k - 1]++;
          tmpInt = getNum(observe[k - 1])+ addnum[p[k - 1]];
        }while((!isInRange(tmpInt, getNum(observe[k - 1]))) && p[k - 1] < 5);
      }
    }
    else{ // go back last Line
      p[k - 1] = 0;
      k --;
      if (k <= 0) break;
       // get the next number within a reasonable range
      do{
          p[k - 1]++; 
          tmpInt = getNum(observe[k - 1])+ addnum[p[k - 1]];
      }while((!isInRange(tmpInt, getNum(observe[k - 1]))) && p[k - 1] < 5);
    }

  } // end while
  return res;

 }*/