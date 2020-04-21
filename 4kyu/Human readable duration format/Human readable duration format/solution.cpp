#include <iostream>
#include <string>

using namespace std;

std::string format_duration(int seconds) {
	string mod("");
	string result("");
	if (seconds == 0)
		return "now";
	if (seconds >= 31536000) {
		mod = to_string(seconds / 31536000);
		seconds %= 31536000;
		
		if (mod == to_string(1))
				result += mod + " year";
		else
			result = mod + " years";
	}
	if (seconds >= 86400) {
		mod = to_string(seconds / 86400);
		seconds %= 86400;
		
		if (result.length() > 0) {
			if(seconds != 0)
				result += ", ";
			else
				result += " and ";
		}
		if (mod == to_string(1))
			result += mod + " day";
		else
			result += mod + " days";
	}
	if (seconds >= 3600) {
		mod = to_string(seconds / 3600);
		seconds %= 3600;

		if (result.length() > 0) {
			if (seconds != 0)
				result += ", ";
			else
				result += " and ";
		}
		if (mod == to_string(1))
			result += mod + " hour";
		else
			result += mod + " hours";
	}
	if(seconds >= 60){
		mod = to_string(seconds / 60);
		seconds %= 60;

		if (result.length() > 0) {
			if (seconds != 0)
				result += ", ";
			else
				result += " and ";
		}
		if (mod == to_string(1))
			result += mod + " minute";
		else
			result += mod + " minutes";
	}
	if (seconds > 0) {
		mod = to_string(seconds);

		if (mod == to_string(1)) {
			if (result.length() > 0)
				result = result + " and " + mod + " second";
			else
				result += mod + " second";
			return result;
		}
		if (result.length() > 0)
			result = result + " and " + mod + " seconds";
		else
			result += mod + " seconds";
	}
	return result;
}

int main() {
	cout << format_duration(62);
	return 0;
}