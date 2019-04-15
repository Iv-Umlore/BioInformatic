//////////////////////////////////////// Задача 5.2 ///////////////////////////////////////////

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

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
	default:  return -1;

	}
}


// Обнуляет оба профиля
void ResetProfile(int** IntProfile, int size) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size; j++) {
			IntProfile[i][j] = 0;
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

void PrintHelpProfile(int** Profile, int size) {
	cout << endl;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < size; j++)
			cout << Profile[i][j] << " ";
		cout << endl;
	}
}

double GetScore(string str, double** MyArray) {
	double res = 1.0;

	for (int i = 0; i < str.length(); i++)
		res = res * (MyArray[GetArrayPos(str[i])][i]);

	return res;
}

double GetBestScore(string OurStr, int ProfileSize, double** Profile, string& BestStr) {
	double score = 0.0;
	string that;
	double tmp;
	for (int SPoint = 0; SPoint < OurStr.length() - ProfileSize + 1; SPoint++) {
		that = GetStr(OurStr, SPoint, ProfileSize);
		tmp = GetScore(that, Profile);
		if (tmp > score) {
			score = tmp;
			BestStr = that;
		}
	}
	return score;
}

// Меняет HelpProfil в зависимости от str
void SetHelpProfile(string str, int** HelpProfile) {
	for (int i = 0; i < str.length(); i++)
		HelpProfile[GetArrayPos(str[i])] [i]++;
}

// Изменяет профиль основываясь на HelpProfil
void SetProfile(int** HelpProfile, double** MyProfile, int size) {
	
	int summ = 0;
	bool flag = false;
	for (int i = 0; i < size; i++) {
		summ = 0;
		flag = false;
		for (int j = 0; j < 4; j++)
			summ += HelpProfile[j][i]/* + 1*/;	/* <------ Здесь*/			// Для решения задачи 5.3
		for (int j = 0; j < 4; j++)											// Необходимо убрать комментарии у "+1"
			MyProfile[j][i] = (double)(HelpProfile[j][i]/* + 1*/ ) / summ;	/* <----- и Здесь*/
	}
}

double GetFavoriteScore(double** Profile, int ProfileSize) {
	double res = 0.0;
	double best;

	for (int i = 0; i < ProfileSize; i++) {
		best = Profile[0][i];
		for (int j = 1; j < 4; j++)
			if (best < Profile[j][i]) best = Profile[j][i];
		res += best;
	}

	return res;
}

struct Record
{
	string Str;
	double Score;
};

int main() {

	string* OurStr;
	string str;
	int ProfileSize;
	int HMstrings;
	double** Profile;
	int** ProfileHelp;
	cin >> ProfileSize >> HMstrings;
	cin.ignore(100, '\n');
	OurStr = new string[HMstrings];

	for (int i = 0; i < HMstrings; i++)
		getline(cin, OurStr[i]);
	

	Profile = new double*[4];
	ProfileHelp = new int*[4];
	for (int i = 0; i < 4; i++) {
		Profile[i] = new double[ProfileSize];
		ProfileHelp[i] = new int[ProfileSize];
		for (int j = 0; j < ProfileSize; j++) {
			ProfileHelp[i][j] = 0;
		}
	}
	
	vector<Record> VRec;
	vector<Record> Motifs;
	Record tmpRec;
	double TheBesterScore = 0.0;
	double score = 0.0;
	double BestSumm = 0.0;
	double summ = 0.0;
	double tmp;
	string MyFavorite;
	string tmpStr = "";

	for (int i = 0; i < OurStr[0].length() - ProfileSize + 1; i++) {

		tmpRec.Str = (GetStr(OurStr[0], i, ProfileSize));
		tmpRec.Score = GetScore(tmpRec.Str, Profile);

		SetHelpProfile(tmpRec.Str, ProfileHelp);
		SetProfile(ProfileHelp, Profile, ProfileSize);
				
		Motifs.push_back(tmpRec);

		for (int j = 1; j < HMstrings; j++) {
			//////////////////
			MyFavorite = GetStr(OurStr[j], 0, ProfileSize);
			score = 0.0;
			////////////////

			score = GetBestScore(OurStr[j], ProfileSize, Profile, MyFavorite);
			
			SetHelpProfile(MyFavorite, ProfileHelp);
			SetProfile(ProfileHelp, Profile, ProfileSize);			

			tmpRec.Str = MyFavorite;
			tmpRec.Score = score;

			Motifs.push_back(tmpRec);

		}
		
		double thisScore = 1.0;

		thisScore = GetFavoriteScore(Profile, ProfileSize);

		if ((TheBesterScore + 0.0000001 < thisScore)) {
			TheBesterScore = thisScore;
			VRec = Motifs;
		}

		ResetProfile(ProfileHelp, ProfileSize);
		Motifs.clear();
	}


	for (int i = 0; i < VRec.size(); i++) {
		cout << VRec.at(i).Str << endl;
	}
	
	std::system("pause");
	
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