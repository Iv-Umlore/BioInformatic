/*
--------------------------------------------------------------------------------------------------------
									Gloabal AlignmentProblem
--------------------------------------------------------------------------------------------------------
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

enum VectorPath {
	VERTICAL,
	HORIZONTAL,
	DIAGONAL
};

const int tildaPenalty = -5;
const int bigUnderZeroValue = -5000;

struct wordPath {
	int value;
	string first;
	string second;
};

#pragma region useless_Function

int GetScore(char ch1, char ch2, const map<string, int>& penaltyMap) {
	string str = "";
	str += ch1;
	str += ch2;
	return penaltyMap.find(str)->second;
}

void WriteArray(wordPath** arr, int downSize, int distSize) {
	for (int i = 0; i < downSize; i++) {
		for (int j = 0; j < distSize; j++) {
			std::cout << arr[i][j].value << '\t';
		}
		std::cout << endl;
	}
}

void FillArray(wordPath** arr, string& str1, string& str2, int downSize, int distSize) {
	arr[0][0].value = 0;
	arr[0][0].first = "";
	arr[0][0].second = "";

	int i = 1;

	string tilda = "";
	string firstTmp = "";
	string secondTmp = "";

	while (i < distSize && i < downSize) {

		firstTmp += str1[i];
		secondTmp += str2[i];
		tilda += "-";

		arr[0][i].value = arr[0][i - 1].value - 5;
		arr[0][i].first = tilda;
		arr[0][i].second = secondTmp;

		arr[i][0].value = arr[i - 1][0].value - 5;
		arr[i][0].first = firstTmp;
		arr[i][0].second = tilda;
		i++;
	}

	int k = i;
	while (i < downSize) {

		arr[i][0].value = arr[i - 1][0].value - 5;
		arr[i][0].first = arr[i - 1][0].first + str1[i];
		arr[i][0].second = arr[i - 1][0].second + "-";

		i++;
	}

	i = k;
	while (i < distSize) {

		arr[0][i].value = arr[0][i - 1].value - 5;
		arr[0][i].first = arr[0][i - 1].first + "-";
		arr[0][i].second = arr[0][i - 1].second + str2[i];

		i++;
	}
		
}

void Split(string str, vector<string>& res) {
	string tmp;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ' ') {
			if (tmp != "")
				res.push_back(tmp);
			tmp = "";
		}
		else
			tmp += str[i];
	}

	if (tmp != "")
		res.push_back(tmp);
}

void GetMap(vector<string> vect, map<string, int>& penaltyMap, ifstream& in) {
	char tmpChar;
	int tmpInt;

	for (int i = 0; i < vect.size() - 1; i++) {
		in >> tmpChar;
		for (int j = 0; j < vect.size() - 1; j++) {
			in >> tmpInt;
			if (j >= i) {
				if (i == j)
					penaltyMap.insert(pair<string, int>(vect[i] + vect[i], tmpInt));
				else {

					penaltyMap.insert(pair<string, int>(vect[i] + vect[j], tmpInt));
					penaltyMap.insert(pair<string, int>(vect[j] + vect[i], tmpInt));
				}
			}
		}
		penaltyMap.insert(pair<string, int>(vect[i] + "-", tildaPenalty));
		penaltyMap.insert(pair<string, int>("-" + vect[i], tildaPenalty));
	}
}

int get_maximum(int vertical, int horizontal, int diagonal, char chr1, char chr2, VectorPath& vect) {

	if (horizontal >= vertical && horizontal > diagonal) {
		vect = HORIZONTAL;
		return horizontal;
	}

	if (vertical >= horizontal && vertical > diagonal) {
		vect = VERTICAL;
		return vertical;
	}

	if (diagonal >= horizontal && diagonal >= vertical) {
		vect = DIAGONAL;
		return diagonal;
	}
}

#pragma endregion

void math_current_distance(wordPath** arr, string& str1, string& str2, const map<string,int>& penaltyMap) {
	VectorPath tmp;
	int value;

	for (int i = 1; i < str1.length(); i++) {
		for (int j = 1; j < str2.length(); j++) {
			value = get_maximum(
				arr[i - 1][j].value + GetScore(str1[i], '-', penaltyMap),
				arr[i][j - 1].value + GetScore('-', str2[j], penaltyMap),
				arr[i - 1][j - 1].value + GetScore(str1[i], str2[j], penaltyMap),
				str1[i],
				str2[j],
				tmp);

			// ѕрисваиваем наибольшее значение
			arr[i][j].value = value;

			switch (tmp)
			{
			case VERTICAL:
				arr[i][j].second = arr[i - 1][j].second + "-";
				arr[i][j].first = arr[i - 1][j].first + str1[i];
				break;

			case HORIZONTAL:
				arr[i][j].first = arr[i][j - 1].first + "-";
				arr[i][j].second = arr[i][j - 1].second + str2[j];
				break;

			case DIAGONAL:
				arr[i][j].first = arr[i - 1][j - 1].first + str1[i];
				arr[i][j].second = arr[i - 1][j - 1].second + str2[j];
				break;

			default:
				break;
			}
		}
	}
}

wordPath edit_distance(string &str1, string &str2, const map<string, int>& penaltyMap) {
	//write your code here
	int result = 0;

	str1 = " " + str1;
	str2 = " " + str2;

	int downSize = str1.size();
	int distSize = str2.size();
	wordPath** arr = new wordPath*[downSize];
	for (int i = 0; i < downSize; i++)
		arr[i] = new wordPath[distSize];

	FillArray(arr, str1, str2, str1.length(), str2.length());
	math_current_distance(arr, str1, str2, penaltyMap);

	//WriteArray(arr, downSize, distSize);

	return arr[downSize - 1][distSize - 1];
};

int main() {
	string str1;
	string str2;
	vector<string> tmpStringArray;
	map<string, int> penaltyMap;
	ifstream in("BLOSUM62.txt");
	ifstream in2("dataset_216071_1.txt");
	
	ofstream out("output.txt");

	getline(in, str1);

	Split(str1, tmpStringArray);
	tmpStringArray.push_back("-");
	GetMap(tmpStringArray, penaltyMap, in);

	getline(in2, str1);
	getline(in2, str2);

	auto editResult = edit_distance(str1, str2, penaltyMap);
	out << editResult.value << endl;

	out << editResult.first << endl;
	out << editResult.second;

	system("pause");
	return 0;
}

*/


/*

--------------------------------------------------------------------------------------------------------
									Edit distance
--------------------------------------------------------------------------------------------------------


#include <iostream>
#include <string>

using std::string;

int get_minimal(const int& a, const int& b, const int& c) {
	if (a <= b && a <= c) return a;
	if (b <= a && b <= c) return b;
	if (c <= b && c <= a) return c;
}

int get_current_distance(int** arr, int currPosX, int currPosY, string& str1, string& str2) {
	// проверки
	if (currPosX == 0 && currPosY == 0) {
		arr[currPosY][currPosX] = (str1[currPosY] == str2[currPosX]) ? 0 : 1;
		return arr[currPosY][currPosX];
	}
	if (arr[currPosY][currPosX] < str1.length() + str2.length()) return arr[currPosY][currPosX];
	
	int tmpHorizontal = (currPosX > 0) ? get_current_distance(arr, currPosX - 1, currPosY, str1, str2) + 1 : str1.length() + str2.length();
	int tmpVerical = (currPosY > 0) ? get_current_distance(arr, currPosX, currPosY - 1, str1, str2) + 1 : str1.length() + str2.length();
	int tmpDioganal = (currPosX > 0 && currPosY > 0) ? get_current_distance(arr, currPosX - 1, currPosY - 1, str1, str2) : str1.length() + str2.length();
	
	if (str1[currPosY] == str2[currPosX]) {
		if (currPosX == 0 && tmpVerical == currPosY + 1) 
			tmpVerical--;
		if (currPosY == 0 && tmpHorizontal == currPosX + 1)
			tmpHorizontal--;
		arr[currPosY][currPosX] = get_minimal(tmpVerical, tmpHorizontal, tmpDioganal);
		return arr[currPosY][currPosX];
	}
	else {
		arr[currPosY][currPosX] = get_minimal(tmpVerical, tmpHorizontal, tmpDioganal + 1);
		return arr[currPosY][currPosX];
	}
}

int edit_distance(string &str1, string &str2) {
  //write your code here
	int result = 0;

	int downSize = str1.size();
	int distSize = str2.size();
	int** arr = new int*[downSize];
	for (int i = 0; i < downSize; i++) {
		arr[i] = new int[distSize];
		for (int j = 0; j < distSize; j++)
			arr[i][j] = str1.length() + str2.length();
	}
	
	downSize--;
	distSize--;
	result = get_current_distance(arr, distSize, downSize, str1, str2);
  return result;
}

int main() {
  string str1;
  string str2;
  std::getline(std::cin, str1);
  std::getline(std::cin, str2);
  if (str1 == "" && str2 == "")
	  std::cout << 0;
  else
	  if (str1 == "")
		  std::cout << str2.length();
	  else if (str2 == "")
		  std::cout << str1.length();
	  else
		std::cout << edit_distance(str1, str2) << std::endl;

  system("pause");
  return 0;
}
*/