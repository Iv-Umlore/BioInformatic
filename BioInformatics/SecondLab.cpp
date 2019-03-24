#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;
// patrOfString + FullString
bool Search(string str, string FullStr) {
	bool flag;
	for (int i = 0; i < FullStr.length() - str.length() + 1; i++) {
		flag = true;
		if (str[0] == FullStr[i])
			for (int j = 0; j < str.length(); j++) {
				if (str[j] != FullStr[i + j]) {
					flag = false;
					break;
				}
			}
		else flag = false;
		if (flag) return true;
	}
	return false;
}

char ReverceSumb(char a) {
	switch (a) {
	case 'A': return 'T';
	case 'C': return 'G';
	case 'G': return 'C';
	case 'T': return 'A';
	default: return 'F';
	}
}

string ReverceWord(string FullStr) {
	string result = "";
	for (int i = FullStr.length() - 1; i > -1; i--) {
		result += ReverceSumb(FullStr[i]);
	}
	return result;
}

bool Amin(char chr) {
	return (chr == 'A' || chr == 'U' || chr == 'C' || chr == 'G');
}

string Transcrib(string defSTR) {
	string result = "";
	for (int i = 0; i < defSTR.length(); i++)
		if (defSTR[i] == 'T') result += 'U';
		else result += defSTR[i];
	return result;
}

// transform 3*char from RNA to 1 char of AMINO.... 
// sorry It's HARDCODE
char Transform(string Str_3D) {

	if (!Amin(Str_3D[0]) || !Amin(Str_3D[1]) || !Amin(Str_3D[2])) return '0';
	// it's autocode, don't worry )
	{
			if (Str_3D == "AAA") return 'K';
			if (Str_3D == "AAC") return 'N';
			if (Str_3D == "AAG") return 'K';
			if (Str_3D == "AAU") return 'N';
			if (Str_3D == "ACA") return 'T';
			if (Str_3D == "ACC") return 'T';
			if (Str_3D == "ACG") return 'T';
			if (Str_3D == "ACU") return 'T';
			if (Str_3D == "AGA") return 'R';
			if (Str_3D == "AGC") return 'S';
			if (Str_3D == "AGG") return 'R';
			if (Str_3D == "AGU") return 'S';
			if (Str_3D == "AUA") return 'I';
			if (Str_3D == "AUC") return 'I';
			if (Str_3D == "AUG") return 'M';
			if (Str_3D == "AUU") return 'I';
			if (Str_3D == "CAA") return 'Q';
			if (Str_3D == "CAC") return 'H';
			if (Str_3D == "CAG") return 'Q';
			if (Str_3D == "CAU") return 'H';
			if (Str_3D == "CCA") return 'P';
			if (Str_3D == "CCC") return 'P';
			if (Str_3D == "CCG") return 'P';
			if (Str_3D == "CCU") return 'P';
			if (Str_3D == "CGA") return 'R';
			if (Str_3D == "CGC") return 'R';
			if (Str_3D == "CGG") return 'R';
			if (Str_3D == "CGU") return 'R';
			if (Str_3D == "CUA") return 'L';
			if (Str_3D == "CUC") return 'L';
			if (Str_3D == "CUG") return 'L';
			if (Str_3D == "CUU") return 'L';
			if (Str_3D == "GAA") return 'E';
			if (Str_3D == "GAC") return 'D';
			if (Str_3D == "GAG") return 'E';
			if (Str_3D == "GAU") return 'D';
			if (Str_3D == "GCA") return 'A';
			if (Str_3D == "GCC") return 'A';
			if (Str_3D == "GCG") return 'A';
			if (Str_3D == "GCU") return 'A';
			if (Str_3D == "GGA") return 'G';
			if (Str_3D == "GGC") return 'G';
			if (Str_3D == "GGG") return 'G';
			if (Str_3D == "GGU") return 'G';
			if (Str_3D == "GUA") return 'V';
			if (Str_3D == "GUC") return 'V';
			if (Str_3D == "GUG") return 'V';
			if (Str_3D == "GUU") return 'V';
			if (Str_3D == "UAA") return ' ';
			if (Str_3D == "UAC") return 'Y';
			if (Str_3D == "UAG") return ' ';
			if (Str_3D == "UAU") return 'Y';
			if (Str_3D == "UCA") return 'S';
			if (Str_3D == "UCC") return 'S';
			if (Str_3D == "UCG") return 'S';
			if (Str_3D == "UCU") return 'S';
			if (Str_3D == "UGA") return ' ';
			if (Str_3D == "UGC") return 'C';
			if (Str_3D == "UGG") return 'W';
			if (Str_3D == "UGU") return 'C';
			if (Str_3D == "UUA") return 'L';
			if (Str_3D == "UUC") return 'F';
			if (Str_3D == "UUG") return 'L';
			if (Str_3D == "UUU") return 'F';

	}
}

void Add(char* a) {
	switch (*a) {
	case 'A': {
		*a = 'U';
		break;
	}
	case 'U': {
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

bool IsOur(string amino, string test) {
	string reverse = Transcrib(test);	

	if (Search(amino, reverse))		
		return true;
	reverse = Transcrib(ReverceWord(test));

	if (Search(amino, reverse))
		return true;
	return false;
}

void SearchAmino(string mystr, string FullString) {
	string temp = "";
	for (int i = 0; i < FullString.length() - mystr.length(); i++) {
		temp = "";
		for (int j = 0; j < mystr.length(); j++)
			temp += FullString[i + j];
		if (IsOur(mystr, temp)) std::cout << temp << endl;
	}
}

bool KeyIsLive(unordered_map<char, vector<string> > MyMap, char Key) {
	for (auto iter = MyMap.begin(); iter != MyMap.end(); iter++)
		if (iter->first == Key) return true;
	return false;
}

bool IHaveThis(vector<string> VS, string myStr) {
	for (auto iter = VS.begin(); iter != VS.end(); iter++)
		if (iter->data() == myStr) return true;
	return false;
}

void HardRecursion(unordered_map<char,vector<string> > UM, string Word, string Protein, string myCombo, int count) {
	string temp = myCombo;

	for (auto iter = UM.at(Protein.at(Protein.length() - count)).begin(); iter != UM.at(Protein.at(Protein.length() - count)).end(); iter++) {
		temp = myCombo;
		temp += iter->data();
		if (count > 1) HardRecursion(UM, Word, Protein, temp, count - 1);
		else SearchAmino(temp, Word);

	}
}

int main() {

	string str3;

	std::unordered_map<char, vector<string> > MyMap;

	string FirstLine;
	string Protein;
	
	cin >> FirstLine;
	cin >> Protein;

	char chr;

	int size = Protein.length();
	for (int i = 0; i < size; i++)
	for (char a = 'A'; a != '0'; Add(&a))
		for (char b = 'A'; b != '0'; Add(&b))
			for (char c = 'A'; c != '0'; Add(&c)) {
				str3 = "";
				str3 += a;
				str3 += b;
				str3 += c;
				chr = Protein.at(i);
				if (Transform(str3) == chr)
					if (!KeyIsLive(MyMap,chr))
					{
						vector<string> vect;
						vect.push_back(str3);
						MyMap.insert(pair<char, vector<string> >(Protein.at(i), vect));
					}
					else {
						IHaveThis(MyMap.at(chr), str3);
						MyMap.at(chr).push_back(str3);
					}

				// ���������� ������� �� ������
			}
	
	string str = "";

	HardRecursion(MyMap, FirstLine, Protein, str, Protein.length());

	std::system("pause");

	return 0;
}

//////////////////////////////////////////////////////////////////////////
/*
	������� 1

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool Amin(char chr) {
	return (chr == 'A' || chr == 'U' || chr == 'C' || chr == 'G');
}

string Transcrib(string defSTR) {
	string result = "";
	for (int i = 0; i < defSTR.length(); i++)
		if (defSTR[i] == 'T') result += 'U';
		else result += defSTR[i];
	return result;
}

// transform 3*char from RNA to 1 char of AMINO....
// sorry It's HARDCODE
char Transform(string Str_3D) {

	if (!Amin(Str_3D[0]) || !Amin(Str_3D[1]) || !Amin(Str_3D[2])) return '0';
	// it's autocode, don't worry )
	{
			if (Str_3D == "AAA") return 'K';
			if (Str_3D == "AAC") return 'N';
			if (Str_3D == "AAG") return 'K';
			if (Str_3D == "AAU") return 'N';
			if (Str_3D == "ACA") return 'T';
			if (Str_3D == "ACC") return 'T';
			if (Str_3D == "ACG") return 'T';
			if (Str_3D == "ACU") return 'T';
			if (Str_3D == "AGA") return 'R';
			if (Str_3D == "AGC") return 'S';
			if (Str_3D == "AGG") return 'R';
			if (Str_3D == "AGU") return 'S';
			if (Str_3D == "AUA") return 'I';
			if (Str_3D == "AUC") return 'I';
			if (Str_3D == "AUG") return 'M';
			if (Str_3D == "AUU") return 'I';
			if (Str_3D == "CAA") return 'Q';
			if (Str_3D == "CAC") return 'H';
			if (Str_3D == "CAG") return 'Q';
			if (Str_3D == "CAU") return 'H';
			if (Str_3D == "CCA") return 'P';
			if (Str_3D == "CCC") return 'P';
			if (Str_3D == "CCG") return 'P';
			if (Str_3D == "CCU") return 'P';
			if (Str_3D == "CGA") return 'R';
			if (Str_3D == "CGC") return 'R';
			if (Str_3D == "CGG") return 'R';
			if (Str_3D == "CGU") return 'R';
			if (Str_3D == "CUA") return 'L';
			if (Str_3D == "CUC") return 'L';
			if (Str_3D == "CUG") return 'L';
			if (Str_3D == "CUU") return 'L';
			if (Str_3D == "GAA") return 'E';
			if (Str_3D == "GAC") return 'D';
			if (Str_3D == "GAG") return 'E';
			if (Str_3D == "GAU") return 'D';
			if (Str_3D == "GCA") return 'A';
			if (Str_3D == "GCC") return 'A';
			if (Str_3D == "GCG") return 'A';
			if (Str_3D == "GCU") return 'A';
			if (Str_3D == "GGA") return 'G';
			if (Str_3D == "GGC") return 'G';
			if (Str_3D == "GGG") return 'G';
			if (Str_3D == "GGU") return 'G';
			if (Str_3D == "GUA") return 'V';
			if (Str_3D == "GUC") return 'V';
			if (Str_3D == "GUG") return 'V';
			if (Str_3D == "GUU") return 'V';
			if (Str_3D == "UAA") return ' ';
			if (Str_3D == "UAC") return 'Y';
			if (Str_3D == "UAG") return ' ';
			if (Str_3D == "UAU") return 'Y';
			if (Str_3D == "UCA") return 'S';
			if (Str_3D == "UCC") return 'S';
			if (Str_3D == "UCG") return 'S';
			if (Str_3D == "UCU") return 'S';
			if (Str_3D == "UGA") return ' ';
			if (Str_3D == "UGC") return 'C';
			if (Str_3D == "UGG") return 'W';
			if (Str_3D == "UGU") return 'C';
			if (Str_3D == "UUA") return 'L';
			if (Str_3D == "UUC") return 'F';
			if (Str_3D == "UUG") return 'L';
			if (Str_3D == "UUU") return 'F';

	}
}



///////////////////////////////////////////// MAIN ////////////////////////////////

	string Str;
	string str_3d = "";
	string result = "";

	Str = TransfortToRNA(Str);

	for (int i = 0; i < Str.length(); i++) {
		str_3d += Str[i];
		if (i % 3 == 2) {
			result += Transform(str_3d);
			str_3d = "";
		}
	}

	cout << result;



/////////////////////////////////////////////////////////////////////////////////

	������� 2


/////////////////////////////////////// MAIN ///////////////////////////////////

*/