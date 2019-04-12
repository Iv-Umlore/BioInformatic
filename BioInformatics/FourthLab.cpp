////////////////////////////////// ЗАДАНИЕ 1 ///////////////////////////////////////////////////

/*

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

void Add(char* a) {
	switch (*a) {
	case 'A': {
		*a = 'T';
		break;
	}
	case 'T': {
		*a = 'C';
		break;
	}
	case 'C': {
		*a = 'G';
		break;
	}
	case 'G': {
		*a = '0';
		break;
	}
	{
	default:
		break;
	}
	}

}

bool GetDifference(string vect, string second, int Maxdifference) {
	int diff = 0;
	bool flag  = true;
		for (int i = 0; i < vect.length(); i++)
			if (vect[i] != second[i]) {
				diff++;
				if (Maxdifference < diff) {
					flag = false;
					break;
				}
			}

	return flag;
}

int GetDiffValue(vector<string> vect, string second, int Maxdifference) {
	int diff = 0;
	bool flag = true;
	for (auto str = vect.begin(); str != vect.end(); str++) {
		for (int i = 0; i < (*str).length(); i++)
			if ((*str)[i] != second[i]) diff++;
		if (Maxdifference < diff) {
			flag = false;
			break;
		}
		diff = 0;

	}
	return flag;
}

string GetStr(string father, int startpoint, int length) {
	string result = "";
	for (int i = startpoint; i < startpoint + length; i++)
		result += father[i];
	return result;
}


vector<string> GetAllKmers(int size) {
	string oops = "";
	vector<string> result;
	result.push_back("A");
	result.push_back("T");
	result.push_back("G");
	result.push_back("C");

	char Tokens[4];
	char a = 'A';
	for (int i = 0; i < 4; i++) {
		Tokens[i] = a;
		Add(&a);
	}


	int sizecopy = size;
	int secondsize = result.size();
	for (int i = 1; i < size; i++) {
		sizecopy = size;
		while (sizecopy != 1) {
			sizecopy--;
			for (int point = 0; point < secondsize; point++)
				result.push_back(result.at(point));
		}

		int numberOfStr = 0;
		for (auto str = result.begin(); str != result.end(); str++) {
			(*str) += Tokens[numberOfStr / secondsize];
			numberOfStr++;
		}

		secondsize = result.size();

	}

	sort(result.begin(), result.end());

	return result;
}

void Insert(vector<string>& Last, string MyStr) {
	bool flag = true;
	for (auto str = Last.begin(); str != Last.end(); str++)
		if (MyStr == (*str)) {
			flag = false;
			break;
		}
	if (flag) Last.push_back(MyStr);
}
*/


////////////////////////////////////// MAIN ///////////////////////////////


/*
int main() {



	string str;
	string secondSTR;
	vector<string> allSTR;
	vector<string> Patterns;
	vector<string> Helper;
	int length, diff;
	cin >> length >> diff;

	cin.ignore(10, '\n');

	// ВВод всех строк( работает и на сайте )
	while (getline(std::cin, str))
	{
		if (str.length() <= 0) break;
		allSTR.push_back(str);
		str.clear();

	}

	vector<string> AllKMERS;
	AllKMERS = GetAllKmers(length);
	bool flag = false;
	bool good = false;
	for (auto Kmers = AllKMERS.begin(); Kmers != AllKMERS.end(); Kmers++) {
		for (auto HStr = allSTR.begin(); HStr != allSTR.end(); HStr++) {
			flag = false;
			for (int i = 0; i < (*HStr).length() - length + 1; i++) {
				if (GetDifference(GetStr((*HStr), i, length), (*Kmers), diff)) {
					flag = true;
					break;
				}
			}
			if (!flag) break;
		}
		if (flag) {
			Helper.push_back((*Kmers));
		}
	}


vector<string> lastVector;

lastVector.push_back(Helper.at(0));

for (auto str = Helper.begin(); str != Helper.end(); str++) {
	Insert(lastVector, (*str));
}

std::sort(lastVector.begin(), lastVector.end());

for (auto str = lastVector.begin(); str != lastVector.end(); str++) {
	cout << (*str) << endl;
}
system("pause");

return 0;
}


/////////////////////////////////////// ЗАДАНИЕ 2 ///////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

void Add(char* a) {
	switch (*a) {
	case 'A': {
		*a = 'T';
		break;
	}
	case 'T': {
		*a = 'C';
		break;
	}
	case 'C': {
		*a = 'G';
		break;
	}
	case 'G': {
		*a = '0';
		break;
	}
	{
	default:
		break;
	}
	}

}

bool GetDifference(string vect, string second, int Maxdifference) {
	int diff = 0;
	bool flag  = true;
		for (int i = 0; i < vect.length(); i++)
			if (vect[i] != second[i]) {
				diff++;
				if (Maxdifference < diff) {
					flag = false;
					break;
				}
			}

	return flag;
}

int GetDiffValue(string vect, string second) {
	int res = 0;
	for (int i = 0; i < vect.length(); i++) {
			if (vect[i] != second[i]) res++;
	}
	return res;
}

string GetStr(string father, int startpoint, int length) {
	string result = "";
	for (int i = startpoint; i < startpoint + length; i++)
		result += father[i];
	return result;
}

vector<string> GetAllKmers(int size) {
	string oops = "";
	vector<string> result;
	result.push_back("A");
	result.push_back("T");
	result.push_back("G");
	result.push_back("C");

	char Tokens[4];
	char a = 'A';
	for (int i = 0; i < 4; i++) {
		Tokens[i] = a;
		Add(&a);
	}


	int sizecopy = size;
	int secondsize = result.size();
	for (int i = 1; i < size; i++) {
		sizecopy = size;
		while (sizecopy != 1) {
			sizecopy--;
			for (int point = 0; point < secondsize; point++)
				result.push_back(result.at(point));
		}

		int numberOfStr = 0;
		for (auto str = result.begin(); str != result.end(); str++) {
			(*str) += Tokens[numberOfStr / secondsize];
			numberOfStr++;
		}

		secondsize = result.size();

	}

	sort(result.begin(), result.end());

	return result;
}

int GetScore(string Kmers, vector<string> allStr) {
	int res = 0;
	int minScore = 1000;
	int tmp = 0;
	for (auto point = allStr.begin(); point != allStr.end(); point++) {

		for (int i = 0; i < (*point).length() - Kmers.length() + 1; i++) {
			tmp = GetDiffValue(Kmers,GetStr((*point),i,Kmers.length()));
			if (tmp < minScore) minScore = tmp;
		}
		res += minScore;
		minScore = 1000;

	}

	return res;
}

void Insert(vector<string>& Last, string MyStr) {
	bool flag = true;
	for (auto str = Last.begin(); str != Last.end();str++)
		if (MyStr == (*str)) {
			flag = false;
			break;
		}
	if (flag) Last.push_back(MyStr);
}

///////////////////////////////////////////// MAIN //////////////////////////////////////////

int main() {



	string str;
	string secondSTR;
	vector<string> allSTR;
	string Patterns;
	int length, diff;
	int tmp;
	cin >> length;

	cin.ignore(10,'\n');

	// ВВод всех строк( работает и на сайте )
	while (getline(std::cin, str))
	{
		if (str.length() <= 0) break;
		allSTR.push_back(str);
		str.clear();

	}
	diff = 100000;

	vector<string> AllKMERS;
	AllKMERS = GetAllKmers(length);
	bool flag = false;
	for (auto Kmers = AllKMERS.begin(); Kmers != AllKMERS.end(); Kmers++) {

		tmp = GetScore((*Kmers), allSTR);
		if (tmp < diff) {
			diff = tmp;
			Patterns = (*Kmers);
		}

	}

	cout << Patterns;

	system("pause");

	return 0;
}





*/