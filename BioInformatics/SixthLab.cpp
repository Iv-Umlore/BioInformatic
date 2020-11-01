// ----------------------------------------------------------------------------------------------------
//									ChangeMoney
// ----------------------------------------------------------------------------------------------------

/*
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

long Parse(string str) {
	long result = 0;
	for (long i = 0; i < str.length(); i++) {
		result += (str[i] - '0') * pow(10, str.length() - i - 1);
	}
	return result;
}

vector<long> ParseString(long firstValue, string str) {
	vector<long> result;
	result.push_back(firstValue);
	long i = 0;
	string tmp = "";
	while (i < str.length()) {
		if (str[i] != ',' && str[i] != ' ') {
			tmp += str[i];
		}
		else {
			if (tmp != "") {
				result.push_back(Parse(tmp));
				tmp = "";
			}
		}

		i++;
	}

	if (tmp != "") {
		result.push_back(Parse(tmp));
		tmp = "";
	}

	return result;
}

void get_minimal_coin_count(long* arr, long currentValue, long neededValue, vector<long> value) {

	for (long i = 0; i < value.size(); i++) {
		if (currentValue + value[i] <= neededValue) {
			if (arr[currentValue] + 1 < arr[currentValue + value[i]]) {
				arr[currentValue + value[i]] = arr[currentValue] + 1;
				get_minimal_coin_count(arr, currentValue + value[i], neededValue, value);
			}
		}
	}
}

long get_change(long m, vector<long> value) {
	//write your code here
	long* arr = new long[m + 1];
	for (long i = 0; i < m + 1; i++)
		arr[i] = 10000;
	arr[0] = 0;

	get_minimal_coin_count(arr, 0, m, value);
	return arr[m];
}

int main() {
	long m;
	long value;
	vector<long> tmp;
	string inputStr;
	cin >> m;
	cin >> value;
	getline(cin, inputStr);

	tmp = ParseString(value, inputStr);
	cout << get_change(m, tmp);

	return 0;
}
*/


//	-------------------------------------------------------------------------------------------------
//									Tourist
//  -------------------------------------------------------------------------------------------------


/*

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int GetMax(const int& first, const int& second) {
	if (first >= second)
		return first;
	else return second;
}

int GetBestPointValue(int** downValues, int** rightValues, int** besterValueInPoint, const int& Y, const int& X) {
	// cout << "\nCoord X = " << X << " Y = " << Y << " : ";
	if (Y < 1) {
		// cout << besterValueInPoint[Y][X - 1] + rightValues[Y][X - 1];
		return besterValueInPoint[Y][X - 1] + rightValues[Y][X - 1];
	}
	if (X < 1) {
		// cout << besterValueInPoint[Y - 1][X] + downValues[Y - 1][X];
		return besterValueInPoint[Y - 1][X] + downValues[Y - 1][X];
	}

	int tmp1 = besterValueInPoint[Y][X - 1] + rightValues[Y][X - 1];
	int tmp2 = besterValueInPoint[Y - 1][X] + downValues[Y - 1][X];

	// cout << "Chose between " << tmp1 << " " << tmp2;

	return GetMax(
		tmp1,
		tmp2
	);
}

int GetBestTouristValues(int** downValues, int** rightValues, int downSize, int rightSize) {
	int** besterValueInPoint = new int*[downSize + 1];
	for (int i = 0; i <= downSize; i++) {
		besterValueInPoint[i] = new int[rightSize + 1];
		for (int j = 0; j <= rightSize; j++) {
			if (i != 0 || j != 0) {
				besterValueInPoint[i][j] = GetBestPointValue(downValues, rightValues, besterValueInPoint, i, j);
			}
			else
				besterValueInPoint[i][j] = 0;
		}
	}

	return besterValueInPoint[downSize][rightSize];
}

int main() {
	
	int downSize;
	int rightSize;
	int tmp;

	char rudiment;

	cin >> downSize >> rightSize;

	int** downValues = new int*[downSize];
	for (int i = 0; i < downSize; i++) {
		downValues[i] = new int[rightSize + 1];
		for (int j = 0; j < rightSize + 1; j++)
			cin >> downValues[i][j];
	}

	cin >> rudiment;

	int** rightValues = new int*[downSize + 1];
	for (int i = 0; i < downSize + 1; i++) {
		rightValues[i] = new int[rightSize];
		for (int j = 0; j < rightSize; j++)
			cin >> rightValues[i][j];
	}

	cout << GetBestTouristValues(downValues, rightValues, downSize, rightSize);

	system("pause");
	return 0;
}

*/



//	-------------------------------------------------------------------------------------------------
//									GetLongestSubstring
//  -------------------------------------------------------------------------------------------------


/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum VectorPath {
	VERTICAL,
	HORIZONTAL,
	DIAGONAL
};

struct wordPath {
	int charCount;
	vector<VectorPath> path;
};

int get_maximum(int& vertical, int& horizontal, int& diagonal, char chr1, char chr2, VectorPath& vect) {
	if (chr1 == chr2) diagonal++;
	if (diagonal >= horizontal && diagonal >= vertical) {
		vect = DIAGONAL;
		return diagonal;
	}

	if (vertical >= horizontal && vertical >= diagonal) {
		vect = VERTICAL;
		return vertical;
	}
	if (horizontal >= vertical && horizontal >= diagonal) {
		vect = HORIZONTAL;
		return horizontal;
	}
}

void math_current_distance(wordPath** arr, string& str1, string& str2) {
	VectorPath tmp;
	int value;
	for (int i = 1; i < str1.length(); i++) {
		for (int j = 1; j < str2.length(); j++) {
			value = get_maximum(
				arr[i - 1][j].charCount,
				arr[i][j - 1].charCount,
				arr[i - 1][j - 1].charCount,
				str1[i],
				str2[j],
				tmp);

			// Присваиваем наибольшее значение
			arr[i][j].charCount = value;

			switch (tmp)
			{
			case VERTICAL:
				arr[i][j].path = arr[i - 1][j].path;

				break;

			case HORIZONTAL:
				arr[i][j].path = arr[i][j - 1].path;
				break;

			case DIAGONAL:
				arr[i][j].path = arr[i - 1][j - 1].path;
				break;

			default:
				break;
			}

			arr[i][j].path.push_back(tmp);
		}
	}
}

string GetCorrectsubstring(vector<VectorPath> path, string str1, string str2) {
	int firstCount = 0;
	int secondCount = 0;

	string result = "";

	for (int i = 0; i < path.size() - 1; i++)
		switch (path[i])
		{
		case VERTICAL: {
			firstCount++;
			break;
		}
		case HORIZONTAL: {
			secondCount++;
			break;
		}
		case DIAGONAL: {
			firstCount++;
			secondCount++;
			if (str1[firstCount] == str2[secondCount])
				result += str1[firstCount];
			break;
		}
		default:
			break;
		}

	return result;
}

string edit_distance(string &str1, string &str2) {
	//write your code here
	int result = 0;

	str1 = " " + str1;
	str2 = " " + str2;

	int downSize = str1.size();
	int distSize = str2.size();
	wordPath** arr = new wordPath*[downSize];
	for (int i = 0; i < downSize; i++) {
		arr[i] = new wordPath[distSize];
		for (int j = 0; j < distSize; j++) {
			arr[i][j].charCount = 0;
			arr[i][j].path = vector<VectorPath>();
		}
	}

	math_current_distance(arr, str1, str2);
	return GetCorrectsubstring(arr[downSize - 1][distSize - 1].path, str1, str2);
};

int main() {
	string str1;
	string str2;
	getline(cin, str1);
	getline(cin, str2);
	if (str1 == "" && str2 == "")
		cout << 0;
	else
		if (str1 == "")
			cout << str2.length();
		else if (str2 == "")
			cout << str1.length();
		else
			cout << edit_distance(str1, str2) << endl;

	system("pause");
	return 0;
}
*/
