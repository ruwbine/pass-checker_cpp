#include <iostream>
#include <string>
#include "checker.h"
using namespace std;

bool password_checker(string pass) {
	if (pass.size() < 8 || pass.size() > 32) {
		return false;
	}
	int lowercase = 0;
	int uppercase = 0;
	int digit = 0;
	
	for (char c : pass) {
		if (c < 33 || c > 126) {
			return false;
		}
		else if (c <= '9' && c >= '0') {
			digit = 1;
		}
		else if (c >= 'a' && c <= 'z') {
			lowercase = 1;
		}
		else if (c >= 'A' && c <= 'Z') {
			uppercase = 1;
		}
	}
	return uppercase + lowercase + digit == 3;
}