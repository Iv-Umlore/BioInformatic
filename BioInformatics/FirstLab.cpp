#include <iostream>
#include <string>
#include <vector>
#include <iostream>
using namespace std;



int main() {


	system("pause");

	return 0;
}
	/*
///////////////////////////////////////////////////////////////////////////////
	«¿ƒ¿Õ»≈ 1

	#include <iostream>
	#include <string>

/////////////////////////// MAIN ///////////////////////////////////
	string FullStr;
	string partOfStr;

	int count = 0;
	bool flag = true;
	cin >> partOfStr;
	cin >> FullStr;
	
	for (int i = 0; i < FullStr.length() - partOfStr.length()+2; i++) {
		flag = true;
		if (partOfStr[0] == FullStr[i])
			for (int j = 0; j < partOfStr.length(); j++) {
				if (partOfStr[j] != FullStr[i + j]) {
					flag = false;
					break;
				}
			}
		else flag = false;
		if (flag) count++;
	}

	cout << count;
/////////////////////////////////////////////////////////////////////////
	«¿ƒ¿Õ»≈ 2

#include <iostream>
#include <string>
#include <vector>
using namespace std;

string GetWord(string Str, int firstSumb ,int length) {
	string result = "";
	for (int i = firstSumb; i < firstSumb + length; i++)
		result = result + Str[i];
	return result;
}

bool StrEqual(string right, string left) {
	if ((int)right.length() != left.length()) return false;
	for (int i = 0; i < right.length(); i++)
		if (right[i] != left[i]) return false;
	return true;
}

void addWord(vector<string>* str, vector<int>* count, string word) {
	int temp = 0;
	bool flag = true;
	while (!StrEqual((*str)[temp], "")) {
		if (StrEqual((*str)[temp],word)) {
			(*count)[temp]++;
			flag = false;
			break;
		}
		temp++;
	}
	if (flag) {
		(*str)[temp] = word;
		(*count)[temp] = 1;
	}
}

/////////////////////////// MAIN ///////////////////////////////////
	string FullStr;
	int length;
	int size;
	vector<string> lib;
	vector<int> word_count;
	cin >> FullStr;
	cin >> length;

	size = FullStr.length() - length + 1;

	lib.resize(size);
	word_count.resize(size);


	for (int i = 0; i < size; i++) {
		lib[i] = "";
		word_count[i] = 0;
	}

	string temp;

	for (int i = 0; i < size; i++) {
		temp = GetWord(FullStr, i, length);
		addWord(&lib, &word_count, temp);
	}

	length = 0;
	for (int i = 0; i < size; i++) {
		if (length < word_count[i]) length = word_count[i];
	}

	for (int i = 0; i < size; i++) {
		if (length == word_count[i]) cout << lib[i] << " ";
	}

////////////////////////////////////////////////////////////////////
	«¿ƒ¿Õ»≈ 3


	char Reverce(char a) {
	switch (a) {
	case 'A': return 'T';
	case 'C': return 'G';
	case 'G': return 'C';
	case 'T': return 'A';
	default: return 'F';
	}
}

	/////////////////////////// MAIN ///////////////////////////////////

	string FullStr;
	string result;
	cin >> FullStr;

	result = "";

	for (int i = FullStr.length()-1; i > -1; i--) {
		result += Reverce(FullStr[i]);
	}

	cout << result;

	*/