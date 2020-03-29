#include <iostream>
#include <string>
#include <cstring>

using namespace std;

//mine:
string pig_it(string str) {
	int tmp, i = 0;
	string ay = "ay";
	while (i <= str.size()) {
		tmp = distance(str.begin(), find(str.begin() + i, str.end(), ' '));
		if (isalpha(str[i])) {
			str.insert(str.begin() + tmp, str[i]);
			str.insert(tmp + 1, ay);
			str.erase(str.begin() + i);
			i = tmp + 3;
		}
		else {
			++i;
		}
	}
	return str;
}

//best for 2:
/*
string pig_it(string str){
  
  string punctuation = "!.,:;?";
  string result = "";
  stringstream ss;
  ss << str;

  for (char ch; ss.get(ch);) { //read char and whitespace
    
    if (isspace(ch))
      result += ch;
        
    else {
      ss.putback(ch); //read a word from the stream
      string word;
      ss >> word;
      
      if (find(punctuation.begin(), punctuation.end(), word[0]) == punctuation.end()) {
        word.push_back(word[0]);
        word.erase(word.begin());
        word.push_back('a');
        word.push_back('y');
      }
      result += word;
    }
  }

  return result;
}

//ÕýÔò£º
#include <string>
#include <regex>
using namespace std;
string pig_it(string Z) {
	regex reg(("(\\w)(\\w*)(\\s|$)"));
	return regex_replace(Z, reg, "$2$1ay$3");
}
*/

int main() {
	string str = " Pig latin is cool";
	cout << pig_it(str);
	return 0;
}