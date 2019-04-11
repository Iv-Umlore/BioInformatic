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

/*vector<string> GetCorrectPattern(vector<string> Helper, int Max) {

	/*vector<string> res;

	int count[4]; // 0 - A, 1 - T, 2 - G, 3 - C.
	
	for (int pos = 0; pos < Helper.at(0).length(); pos++) {
		count[0] = count[1] = count[2] = count[3] = 0;

		for (auto iter = Helper.begin(); iter != Helper.end(); iter++) {
			switch ((*iter)[pos])
			{
			case 'A': {
				count[0]++;
				break;
			}
			case 'T': {
				count[1]++;
				break;
			}
			case 'G': {
				count[2]++;
				break;
			}
			case 'C': {
				count[3]++;
				break;
			}
			default:
				break;
			}
		}

		int MaxPos = 0;				// позиция максимумов
		int MaxValue = count[0];	// значение
		int MaxCount = 1;			// количество максимумов

		for (int i = 1; i < 4; i++) {
			if (count[i] == MaxValue) MaxCount++;
			if (count[i] > MaxValue) {
				MaxPos = i;
				MaxCount = 1;
				MaxValue = count[i];
			}
		}
		
		if (pos > 0) {
			if (MaxCount == 1) {
				char nextToken;
				switch (MaxPos)
				{
				case 0: {
					nextToken = 'A';
					break;
				}
				case 1: {
					nextToken = 'T';
					break;
				}
				case 2: {
					nextToken = 'G';
					break;
				}
				case 3: {
					nextToken = 'C';
					break;
				}
				default:
					break;
				}

				for (auto str = res.begin(); str != res.end(); str++)
					(*str) += nextToken;
			}
			if (MaxCount > 1) {
				char* Tokens = new char[MaxCount];
				int tmp = 0;
				for (int i = MaxPos; i < 4; i++) {
					if (count[i] == MaxValue)
						switch (i)
						{
						case 0: {
							Tokens[tmp] = 'A';
							tmp++;
							break;
						}
						case 1: {
							Tokens[tmp] = 'T';
							tmp++;
							break;
						}
						case 2: {
							Tokens[tmp] = 'G';
							tmp++;
							break;
						}
						case 3: {
							Tokens[tmp] = 'C';
							tmp++;
							break;
						}
						default:
							break;
						}
				}

				tmp = res.size();

				while (MaxCount != 1) {
					MaxCount--;
					for (int point = 0; point < tmp; point++)
						res.push_back(res.at(point));
				}

				int numberOfStr = 0;
				for (auto str = res.begin(); str != res.end(); str++)
					(*str) += Tokens[numberOfStr / tmp];

			}
		}
		else {
			if (MaxCount == 1) {
				switch (MaxPos)
				{
				case 0: {
					res.push_back("A");
					break;
				}
				case 1: {
					res.push_back("T");
					break;
				}
				case 2: {
					res.push_back("G");
					break;
				}
				case 3: {
					res.push_back("C");
					break;
				}
				default:
					break;
				}
			}
			if (MaxCount > 1) {
				for (int i = MaxPos; i < 4; i++) {
					if (count[i] == MaxValue)
						switch (i)
						{
						case 0: {
							res.push_back("A");
							break;
						}
						case 1: {
							res.push_back("T");
							break;
						}
						case 2: {
							res.push_back("G");
							break;
						}
						case 3: {
							res.push_back("C");
							break;
						}
						default:
							break;
						}
				}
			}

		}

	}
	*//*string oops = "";
	vector<string> result;
	for (char a = 'A'; a != '0'; Add(&a)) {
		for (char b = 'A'; b != '0'; Add(&b)) {
			for (char c = 'A'; c != '0'; Add(&c)) {
				for (char d = 'A'; d != '0'; Add(&d)) {
					oops += a;
					oops += b;
					oops += c;
					oops += d;
					//cout << oops << " ";
					if (GetDifference(Helper, oops, Max))
						result.push_back(oops);
					oops = "";
				}
			}
		}
	}
	for (auto stings = res.begin(); stings != res.end(); stings++) {
		if (GetDifference(Helper, (*stings), Max))
			result.push_back((*stings));
	}

	return result;
}*/

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
	for (auto str = Last.begin(); str != Last.end();str++)
		if (MyStr == (*str)) {
			flag = false;
			break;
		}
	if (flag) Last.push_back(MyStr);
}

int main() {

	

	string str;
	string secondSTR;
	vector<string> allSTR;
	vector<string> Patterns;
	vector<string> Helper;
	int length, diff;
	cin >> length >> diff;

	cin.ignore(10,'\n');
	
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

	/*for (auto op = Helper.begin(); op != Helper.end(); op++) {
		cout << (*op) << " ";
	}*/

	// перебор первой строки
	/*
	for (int i1 = 0; i1 < allSTR.at(0).length() - length + 1; i1++) {
		str = GetStr(allSTR.at(0),i1,length);
		Helper.push_back(str);

		for (int i2 = 1; i2 < allSTR.size(); i2++) {

			for (int i3 = 0; i3 < allSTR.at(i2).length() - length + 1; i3++) {
				secondSTR = GetStr(allSTR.at(i2), i3, length);
				if (GetDifference(Helper, secondSTR, diff * 2)) {
					Helper.push_back(secondSTR);
					break;
				}
			}

		}

		if (Helper.size() == allSTR.size()) {
			vector<string> Helper2 = GetCorrectPattern(Helper,diff);
			for (auto str = Helper2.begin(); str != Helper2.end(); str++)
				Patterns.push_back(*str);
		}
		Helper.clear();

	}
	*/
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
*/