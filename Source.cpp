#include <iostream>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <streambuf>
#include <string>
#include "checker.h"
using namespace std;




ifstream myfile;
ofstream DB;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);



string is_okay(string &current, int &valid_passwords) {
	string callback;
	
	if (password_checker(current)) {
		cout << "\033[0;32m[ACCEPTED]\033[0m\t";
		callback = current;
		valid_passwords++;
		DB << current << endl;

	}
	else {
		cout<< "\033[0;31m[DENIED]  \033[0m\t";
		callback = current;
	}
	return callback;
}

int main() {
	SetConsoleTextAttribute(color, 3);
	system("chcp 1251>nul");
	int total = 0;
	int valid_passwords = 0;
	string path_to_file;
	string database_path;
	cout << "#################################################################" << endl;
	cout << "#\t\t\t\t\t\t\t\t#" << endl;
	cout << "#\t\t\t\t\t\t\t\t#" << endl;
	cout << "#\t\t\t\t\t\t\t\t#" << endl;
	cout << "#\t������� ���� � ����� � ��������\t\t\t\t#" << endl;
	cout << "#\t(������ �� ������ ��������� ����.�������)\t\t#" << endl;
	cout << "#\t������ ����� �����(���������, ��������) � �����\t\t#" << endl;;
	cout << "#\t\t\t8 <= ����� <= 32\t\t\t#" << endl;
	cout << "#\t\t\t\t\t\t\t\t#" << endl;
	cout << "#################################################################\n" << endl;
	
	cout << "���� � �����: " << endl;
	


	cin >> path_to_file; cout << "\n\n";
	cout << "������� ���� � ��������� ������� ����� ��������: " << endl;
	cin >> database_path;
	myfile.open(path_to_file);

	if (myfile.fail()) {
		
		cout << "File cannot be readen";

	}

	else {
		DB.open(database_path);
		string current;
		while (getline(myfile, current)) {
			cout << is_okay(current, valid_passwords) << endl;
			total++;
		}
	}
	DB.close();
	cout << "\n\n ���������� ������� : " << valid_passwords << " �� " << total << "\n\n";
	_getch();
	return 0;
}