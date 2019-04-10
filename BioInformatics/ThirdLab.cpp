/*
/////////////////////////////////////////////////////////////////////////

////////////////////////// Задание 1 ////////////////////////////////////
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int Stepen(int i) {
	int res = 1;
	for (int j = 0; j < i; j++) {
		res *= 10;
	}
	return res;
}

int GetInt(string numb) {
	int res = 0;
	for (int i = 0; i < numb.length(); i++) {
		res += (numb[i] - '0') * Stepen(numb.length() - i - 1);
	}
	return res;
}

int GetPSize(int length) {
	int i = 2;
	while (((i*(i - 1) + 2) != length) && i < length)
		i++;
	return i;
}

bool Find(vector<int> & vect, int value) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect.at(i) == value) {
			return true;
		}
	}
	return false;
}

// модифицированное согласование
bool IsItGood(vector<int> testPeptide, int testValue, vector<int> Spectrum) {
	int sum = 0;
	for (auto iterator = testPeptide.begin(); iterator != testPeptide.end(); iterator++) {
		sum += (*iterator);
	}
	if (Find(Spectrum, testValue) && Find(Spectrum, testValue + sum)) return true;
	else return false;
}

vector<int> GetMassesArray() {
	vector<int> result;
	result.push_back(57);
	result.push_back(71);
	result.push_back(87);
	result.push_back(97);
	result.push_back(99);
	result.push_back(101);
	result.push_back(103);
	result.push_back(113);
	result.push_back(114);
	result.push_back(115);
	result.push_back(128);
	result.push_back(129);
	result.push_back(131);
	result.push_back(137);
	result.push_back(147);
	result.push_back(156);
	result.push_back(163);
	result.push_back(186);
	return result;
}

void PrintVector(vector<int> Peptide) {
	for (int i = 0; i < Peptide.size(); i++) {
		cout << Peptide.at(i);
		if (i + 1 < Peptide.size()) cout << '-';
	}
}

void DeleteVector(vector<vector<int> > & Peptides, int pos) {
	swap(Peptides.at(Peptides.size() - 1), Peptides.at(pos));
	Peptides.pop_back();
}
// вернуть массу эллеметнов с startPos длинны length
int GetValue(int startPos, int length, vector<int> Peptide) {
	int result = 0;
	for (int i = startPos; (i < Peptide.size()) && (length > 0); i++) {
		result += Peptide.at(i);
		length--;
	}

	for (int i = 0; (length > 0); i++) {
		length--;
		result += Peptide.at(i);
	}

	return result;
}

vector<int> GetSpectr(vector<int> Peptide) {
	vector<int> result;
	result.push_back(0);
	for (int i = 0; i < Peptide.size(); i++) {
		if (i + 1 == Peptide.size()) {
			result.push_back(GetValue(1, i, Peptide));
			break;
		}
		for (int j = 0; j < Peptide.size(); j++)
			result.push_back(GetValue(j, i, Peptide));
	}
	return result;
}

bool IsItPart(vector<int> InputV, vector<int> resV) {
	int i = 0;
	if (InputV.size() != resV.size()) return false;
	while ((i < resV.size()) && Find(InputV, resV.at(i)) ) {
		i++;
	}
	if (i == resV.size()) return true;
	else return false;
}
////////////////////////////// MAIN /////////////////////////////////////////
int main() {

	vector<int> Specrum;
	vector<int> copy;
	string line;
	string tmp = "";
	getline(cin, line);

	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			Specrum.push_back(GetInt(tmp));
			tmp = "";
		}
		else tmp += line[i];
	}
	Specrum.push_back(GetInt(tmp));

	copy = Specrum;
	int maxValue = Specrum.at(Specrum.size() - 1);		// вес пептида

	vector<int> Masses = GetMassesArray();			// все массы

	//////////////////////////////////////// в идеале это вектор векторов( для следующих задач ) /////////////////

	vector<vector<int> > Peptides;							// итоговый пептид
	int PeptideSize = GetPSize(Specrum.size());		// число символов в пептиде(good)

	int tmpSize = 0;
	int count = 0;
	vector<int> test;

	for (int j = 0; j < Masses.size(); j++) {
		if (Find(Specrum, Masses.at(j))) {
			test.push_back(Masses.at(j));
			Peptides.push_back(test);
			test.pop_back();
		}
	}

	for (int i = 1; i < PeptideSize; i++) {
		tmpSize = Peptides.size();
		for (int iterator = 0; (iterator < tmpSize) && (iterator < Peptides.size() && (Peptides.at(iterator).size() < PeptideSize)); iterator++) {
			for (int j = 0; j < Masses.size(); j++) {

				if (IsItGood(Peptides.at(iterator), Masses.at(j), Specrum)) {
					test = Peptides.at(iterator);
					test.push_back(Masses.at(j));
					Peptides.push_back(test);
					count++;
				}
			}
			if (count == 0) {
				DeleteVector(Peptides, iterator);
				iterator--;
			}
			else DeleteVector(Peptides, iterator);
			count = 0;
		}
	}

	for (int iterator = 0; iterator < Peptides.size(); iterator++) {
		if (Peptides.at(iterator).size() != PeptideSize) {
			DeleteVector(Peptides,iterator);
			iterator--;
		}
		else
			if (!IsItPart(Specrum, GetSpectr(Peptides.at(iterator)))) {
				DeleteVector(Peptides, iterator);
				iterator--;
			}
	}

	for (auto iterator = Peptides.begin(); iterator != Peptides.end(); iterator++) {
		PrintVector(*iterator);
		cout << " ";
	}

	system("pause");

	return 0;
}


/////////////////////////////////////////////////////////////////////////////////////////////

////////////////////// ЗАДАНИЕ 2 ////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

int Stepen(int i) {
	int res = 1;
	for (int j = 0; j < i; j++) {
		res *= 10;
	}
	return res;
}

int GetInt(string numb) {
	int res = 0;
	for (int i = 0; i < numb.length(); i++) {
		res += (numb[i] - '0') * Stepen(numb.length() - i - 1);
	}
	return res;
}

bool Find(vector<int> & vect, int value) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect.at(i) == value) {
			vect.at(i) = -1;
			return true;
		}
	}
	return false;
}

// вернуть массу эллеметнов с startPos длинны length
int GetValue(int startPos, int length, vector<int> Peptide) {
	int result = 0;

	for (int i = startPos; (i < Peptide.size()) && (length > 0); i++) {
		result += Peptide.at(i);
		length--;
	}

	for (int i = 0; (length > 0); i++) {
		length--;
		result += Peptide.at(i);
	}

	return result;
}

vector<int> GetSpectr(vector<int> Peptide) {
	vector<int> result;
	result.push_back(0);
	for (int i = 0; i < Peptide.size(); i++) {
		if (i + 1 == Peptide.size()) {
			result.push_back(GetValue(1, i + 1, Peptide));
			break;
		}
		for (int j = 0; j < Peptide.size(); j++)
			result.push_back(GetValue(j, i + 1, Peptide));
	}
	return result;
}

/////////////////////////////////////////// MAIN /////////////////////////////////////////////////

int main() {

	unordered_map<char, int> Mass;
	{
		Mass.insert(pair<char, int>('G', 57));
		Mass.insert(pair<char, int>('A', 71));
		Mass.insert(pair<char, int>('S', 87));
		Mass.insert(pair<char, int>('P', 97));
		Mass.insert(pair<char, int>('V', 99));
		Mass.insert(pair<char, int>('T', 101));
		Mass.insert(pair<char, int>('C', 103));
		Mass.insert(pair<char, int>('I', 113));
		Mass.insert(pair<char, int>('L', 113));
		Mass.insert(pair<char, int>('N', 114));
		Mass.insert(pair<char, int>('D', 115));
		Mass.insert(pair<char, int>('K', 128));
		Mass.insert(pair<char, int>('Q', 128));
		Mass.insert(pair<char, int>('E', 129));
		Mass.insert(pair<char, int>('M', 131));
		Mass.insert(pair<char, int>('H', 137));
		Mass.insert(pair<char, int>('F', 147));
		Mass.insert(pair<char, int>('R', 156));
		Mass.insert(pair<char, int>('Y', 163));
		Mass.insert(pair<char, int>('W', 186));
	}

	vector<int> Specrum;
	vector<int> TeoreticSpectrum;

	string Peptide;
	getline(cin, Peptide);

	string line;
	string tmp = "";
	getline(cin, line);

	int temp = 0;
	for (int i = 0; i < Peptide.length(); i++) {
		temp = Mass.at(Peptide[i]);
		TeoreticSpectrum.push_back(temp);
	}

	TeoreticSpectrum = GetSpectr(TeoreticSpectrum);

	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			Specrum.push_back(GetInt(tmp));
			tmp = "";
		}
		else tmp += line[i];
	}
	Specrum.push_back(GetInt(tmp));

	int res = 0;

	vector<int> copy = Specrum;

	for (int i = 0; i < TeoreticSpectrum.size(); i++) {
		if (Find(Specrum, TeoreticSpectrum.at(i)))
			res++;
	}

	cout << res;
	system("pause");
	return 0;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////// Задание 3 ///////////////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

int Stepen(int i) {
	int res = 1;
	for (int j = 0; j < i; j++) {
		res *= 10;
	}
	return res;
}

int GetInt(string numb) {
	int res = 0;
	for (int i = 0; i < numb.length(); i++) {
		res += (numb[i] - '0') * Stepen(numb.length() - i - 1);
	}
	return res;
}

int GetPSize(int length) {
	int i = 2;
	while (((i*(i - 1) + 2) != length) && i < length)
		i++;
	return i;
}

bool Find(vector<int> & vect, int value) {
	for (int i = 0; i < vect.size(); i++) {
		if (vect.at(i) == value) {
			vect.at(i) = -1;
			return true;
		}
	}
	return false;
}

// модифицированное согласование
bool IsItGood(vector<int> testPeptide, int testValue, vector<int> Spectrum) {
	int sum = 0;
	for (auto iterator = testPeptide.begin(); iterator != testPeptide.end(); iterator++) {
		sum += (*iterator);
	}
	if (Find(Spectrum, testValue) && Find(Spectrum, testValue + sum)) return true;
	else return false;
}

vector<int> GetMassesArray() {
	vector<int> result;
	result.push_back(57);
	result.push_back(71);
	result.push_back(87);
	result.push_back(97);
	result.push_back(99);
	result.push_back(101);
	result.push_back(103);
	result.push_back(113);
	result.push_back(114);
	result.push_back(115);
	result.push_back(128);
	result.push_back(129);
	result.push_back(131);
	result.push_back(137);
	result.push_back(147);
	result.push_back(156);
	result.push_back(163);
	result.push_back(186);
	return result;
}

void PrintVector(vector<int> Peptide) {
	for (int i = 0; i < Peptide.size(); i++) {
		cout << Peptide.at(i);
		if (i + 1 < Peptide.size()) cout << '-';
	}
}

void DeleteVector(vector<vector<int> > & Peptides, int pos) {
	swap(Peptides.at(Peptides.size() - 1), Peptides.at(pos));
	Peptides.pop_back();
}
// вернуть массу эллеметнов с startPos длинны length
int GetValue(int startPos, int length, vector<int> Peptide) {
	int result = 0;
	for (int i = startPos; (i < Peptide.size()) && (length > 0); i++) {
		result += Peptide.at(i);
		length--;
	}

	for (int i = 0; (length > 0); i++) {
		length--;
		result += Peptide.at(i);
	}

	return result;
}

vector<int> GetSpectr(vector<int> Peptide) {
	vector<int> result;
	result.push_back(0);
	for (int i = 1; i < Peptide.size() + 1; i++) {
		if (i + 1 == Peptide.size() + 1) {
			result.push_back(GetValue(1, i, Peptide));
			break;
		}
		for (int j = 0; j < Peptide.size(); j++)
			result.push_back(GetValue(j, i, Peptide));
	}
	return result;
}

int Score(const vector<int> ExperSpectr, vector<int> TeoreticSpectrum) {
	int res = 0;
	vector<int> tmp = ExperSpectr;
	for (int i = 0; i < TeoreticSpectrum.size(); i++) {
		if (Find(tmp, TeoreticSpectrum.at(i)))
			res++;
	}
	return res;
}

struct Record
{
	vector<int> word;
	int Score;
};

void DeleteTrash(list<Record> & Leaders, int Maxsize) {
	if (Leaders.size() > Maxsize) {
		auto iter = Leaders.begin();
		int count = 0;
		while (count < Maxsize) {
			count++;
			iter++;
		}

		int value = (*iter).Score;

		while ((iter != Leaders.end()) && ((*iter).Score == value)) {
			iter++;
			count++;
		}
		count--;
		while (Leaders.size() > count)
			Leaders.pop_back();
	}

}

bool InsertRecord(list<Record> & Leaders, Record rec, int Maxsize) {

	auto iterator = Leaders.end();
	iterator--;

	if (((*iterator).Score > rec.Score) && Leaders.size() >= Maxsize)
		return true;

	iterator = Leaders.begin();

	while ((iterator != Leaders.end()) && ((*iterator).Score >= rec.Score)) {
		iterator++;
	}
	if (iterator == Leaders.end()) iterator--;

	if (((*iterator).Score == rec.Score) && (*iterator).word.size() < rec.word.size()) return true;

	if ((*iterator).Score <= rec.Score) {
		Leaders.insert(iterator, rec);
		return true;
	}

	if (Leaders.size() < Maxsize) {
		Leaders.insert(iterator, rec);
		return true;
	}
	else return true;

}

/////////////////////////////////////////// MAIN /////////////////////////////////////////////////

int main() {

	vector<int> Specrum;
	int size;
	string line;
	string tmp = "";
	cin >> size;
	getline(cin, line);
	getline(cin, line);


	for (int i = 0; i < line.length(); i++) {
		if (line[i] == ' ') {
			Specrum.push_back(GetInt(tmp));
			tmp = "";
		}
		else tmp += line[i];
	}
	Specrum.push_back(GetInt(tmp));

	int maxValue = Specrum.at(Specrum.size() - 1);		// вес пептида

	vector<int> Masses = GetMassesArray();				// все массы
	int PeptideSize = size;
	if (size < 9) size = 9;
	list<Record> LeaderBoard;				// итоговый пептид


	int number = 0;
	int count = 0;
	Record test;

	vector<int> temp = Specrum;
	vector<int> GoodMasses;

	for (int j = 0; j < Masses.size(); j++) {
		if (Find(temp, Masses.at(j))) {
			test.word.push_back(Masses.at(j));
			test.Score = 2;
			LeaderBoard.push_back(test);
			GoodMasses.push_back(Masses.at(j)); // пусть хоть тут будет немного оптимизации
			test.word.pop_back();
		}
	}


	for (int i = 1; i < PeptideSize; i++) {
		for (auto iterator = LeaderBoard.begin(); iterator != LeaderBoard.end(); iterator++) {

			for (auto j = GoodMasses.begin(); j != GoodMasses.end(); j++) {

				test = *iterator;
				if (test.word.size() == i) {
					test.word.push_back(*j);
					test.Score = Score(Specrum, GetSpectr(test.word));
					InsertRecord(LeaderBoard, test, size);
				}
			}

			(*iterator).Score = 0;
		}
		DeleteTrash(LeaderBoard, size);
	}

	PrintVector((*LeaderBoard.begin()).word);

	system("pause");

	return 0;
}


*/