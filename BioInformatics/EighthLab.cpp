/*

/////////////////////////////////////////////////////////////////////////////////////
//							8.1 String Composition Problem
/////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string getSubstring(string str, int pos, int size) {
	string res;
	for (int i = pos; i < pos + size; i++)
		res += str[i];

	return res;
}

int main() {
	int size;
	string str1;
	
	set<string> kmers;

	cin >> size;
	cin >> str1;

	for (int i = 0; i < str1.length() - size + 1; i++) {
		kmers.insert(getSubstring(str1, i, size));
	}

	for (auto iter = kmers.begin(); iter != kmers.end(); iter++)
		cout << *iter << endl;

	return 0;
}

*/

///////////////////////////////////////////////////////////////////////////////////////////
//						8.2 String Spelled by a Genome Path Problem
///////////////////////////////////////////////////////////////////////////////////////////

/*

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string getSubstring(string str, int pos, int size) {
	string res;
	for (int i = pos; i < pos + size; i++)
		res += str[i];

	return res;
}

int main() {
	int size;
	string str1;
	string resString;

	getline(cin, str1);
	resString = str1;

	while (getline(cin, str1)) {
		resString += str1[str1.length() - 1];
	}

	cout << resString;
	return 0;
}

*/

///////////////////////////////////////////////////////////////////////////////////////////
//								8.3 Overlap Graph Problem
///////////////////////////////////////////////////////////////////////////////////////////

/*

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string getSubstring(string str, int pos, int size) {
	string res;
	for (int i = pos; i < pos + size; i++)
		res += str[i];

	return res;
}


map<string, string> GetGraph(vector<string> vect) {
	map<string, string> result;
	
	int kmerSize = vect[0].size() - 1;
	for (int i = 0; i < vect.size(); i++)
		for (int j = i + 1; j < vect.size(); j++) {
			if (getSubstring(vect[i], 1, kmerSize) == getSubstring(vect[j], 0, kmerSize))
				result.insert(pair<string, string>(vect[i], vect[j]));

			if (getSubstring(vect[i], 0, kmerSize) == getSubstring(vect[j], 1, kmerSize))
				result.insert(pair<string, string>(vect[j], vect[i]));
		}

	return result;
}

void PrintElemtntOfMaps(map<string, string>& mapa) {
	string currentString;
	for (auto iter = mapa.begin(); iter != mapa.end(); iter++)
		cout << iter->first << " -> " << iter->second << endl;
		
}

int main() {
	int size;
	string str1;
	vector<string> strings;
	map<string, string> mapa;

	
	while(getline(cin, str1))
		strings.push_back(str1);

	mapa = GetGraph(strings);

	PrintElemtntOfMaps(mapa);

	return 0;
}

*/

///////////////////////////////////////////////////////////////////////////////////////////
//							8.4 De Bruijn Graph from a String Problem
///////////////////////////////////////////////////////////////////////////////////////////


/*

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

string getSubstring(string str, int pos, int size) {
	string res;
	for (int i = pos; i < pos + size; i++)
		res += str[i];

	return res;
}

map<string, vector<string>> GetGraph(string str, int sizeKMers) {
	map<string, vector<string>> result;
	
	string first = getSubstring(str, 0, sizeKMers);
	string second;

	
	for (int i = 1; i < str.size() - sizeKMers + 1; i++) {
		second = getSubstring(str, i, sizeKMers);
		result[first].push_back(second);

		first = second;
	}

	return result;
}

void PrintVector(vector<string> set) {
	
	for (auto iter = set.begin(); iter != set.end(); iter++) {
		if (iter != set.begin()) cout << ",";
		cout << *iter;
	}
}

void PrintElemtntOfMaps(map<string, vector<string>>& mapa) {
	string currentString;
	for (auto iter = mapa.begin(); iter != mapa.end(); iter++) {
		cout << iter->first << " -> ";
		PrintVector(iter->second);
		cout << endl;
	}
		
}

int main() {
	int size;
	string str1;
	map<string, vector<string>> mapa;

	cin >> size;
	cin >> str1;
	
	mapa = GetGraph(str1, size-1);

	PrintElemtntOfMaps(mapa);

	return 0;
}

*/
