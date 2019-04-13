#include <iostream>
#include <string>

using namespace std;

string GetStr(string father, int startpoint, int length) {
	string result = "";
	for (int i = startpoint; i < startpoint + length; i++)
		result += father[i];
	return result;
}

int GetArrayPos(char ch) {
	switch (ch)
	{
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	default:
		return -1;
	}
}

double GetScore(string str, double** MyArray) {
	double res = 1.0;

	for (int i = 0; i < str.length(); i++)
		res = res * (MyArray[GetArrayPos(str[i])][i]);

	return res;
}

double GetBestScore(string OurStr, int ProfileSize, double** Profile) {
	double score = 0.0;
	double tmp;
	for (int SPoint = 0; SPoint < OurStr.length() - ProfileSize + 1; SPoint++) {
		tmp = GetScore(GetStr(OurStr, SPoint, ProfileSize), Profile);
		if (tmp > score) {
			score = tmp;
		}
	}
	return score;
}

void SetProfile(string str, double** MyProfile, int size) {

}

void ResetProfile(double** MyProfile, int size) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size; j++) {
			MyProfile[i][j] = 0.25;
		}
	}
}

void PrintProfile(double** Profile, int size) {
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size; j++)
			cout << Profile[i][j] << " ";
		cout << endl;
	}
}

int main() {

	string* OurStr;
	string str;
	int ProfileSize;
	int HMstrings;
	double** Profile;

	cin >> ProfileSize >> HMstrings;
	cin.ignore(100, '\n');
	OurStr = new string[HMstrings];

	for (int i = 0; i < HMstrings; i++)
		getline(cin, OurStr[i]);

	Profile = new double*[4];
	for (int i = 0; i < 4; i++) {
		Profile[i] = new double[ProfileSize];
		for (int j = 0; j < ProfileSize; j++) {
			Profile[i][j] = 0.25;
		}
	}

	for (int i = 0; i < OurStr[0].length() - ProfileSize + 1; i++) {

		SetProfile(GetStr(OurStr[0], i, ProfileSize), Profile, ProfileSize);

		for (int j = 0; j < HMstrings; j++) {

			double score = 0.0;
			double tmp;
			string MyFavorite = "";
			string tmpStr = "";
			for (int SPoint = 0; SPoint < OurStr[j].length() - ProfileSize + 1; SPoint++) {
				tmpStr = GetStr(OurStr[j], SPoint, ProfileSize);
				tmp = GetScore(tmpStr, Profile);
				if (tmp > score) {
					score = tmp;
					MyFavorite = tmpStr;
				}
			}
			SetProfile(MyFavorite, Profile, ProfileSize);
		}

		/*
		
		Что-то ещё
		
		*/

		ResetProfile(Profile, ProfileSize);

	}

	system("pause");
	
	return 0;
}


/*
////////////////////////////////////// ЗАДАНИЕ 1 /////////////////////////////////////////


#include <iostream>
#include <string>

using namespace std;

string GetStr(string father, int startpoint, int length) {
	string result = "";
	for (int i = startpoint; i < startpoint + length; i++)
		result += father[i];
	return result;
}

int GetArrayPos(char ch) {
	switch (ch)
	{
	case 'A': return 0;
	case 'C': return 1;
	case 'G': return 2;
	case 'T': return 3;
	default:
		return -1;
	}
}

double GetScore(string str, double** MyArray) {
	double res = 1.0;

	for (int i = 0; i < str.length(); i++)
		res = res * (MyArray[GetArrayPos(str[i])][i]);

	return res;
}

///////////////////////////////////////// MAIN //////////////////////////////////////////////

int main() {

	string OurStr;
	int ProfileSize;
	double** Profile;

	getline(cin, OurStr);
	cin >> ProfileSize;

	Profile = new double*[4];

	for (int i = 0; i < 4; i++) {
		Profile[i] = new double[ProfileSize];
		for (int j = 0; j < ProfileSize; j++)
			cin >> Profile[i][j];
	}

	double score = 0.0;
	double tmp;
	string MyFavorite = "";
	string tmpStr = "";
	for (int SPoint = 0; SPoint < OurStr.length() - ProfileSize + 1; SPoint++) {
		tmpStr = GetStr(OurStr, SPoint, ProfileSize);			// возможно, что он циклический
		tmp = GetScore(tmpStr, Profile);		
		if (tmp > score) {
			score = tmp;
			MyFavorite = tmpStr;
		}
	}

	cout << MyFavorite;

	system("pause");
	
	return 0;
}*/