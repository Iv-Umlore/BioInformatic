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


// �������� ��� �������
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

// ������ HelpProfil � ����������� �� str
void SetHelpProfile(string str, int** HelpProfile) {
	for (int i = 0; i < str.length(); i++)
		HelpProfile[GetArrayPos(str[i])] [i]++;
}

// �������� ������� ����������� �� HelpProfil
void SetProfile(int** HelpProfile, double** MyProfile, int size) {
	
	int summ = 0;
	bool flag = false;
	for (int i = 0; i < size; i++) {
		summ = 0;
		flag = false;
		for (int j = 0; j < 4; j++)
			summ += HelpProfile[j][i];
		for (int j = 0; j < 4; j++) {
			MyProfile[j][i] = (double)((double)HelpProfile[j][i]) / (double)summ;
			if (MyProfile[j][i] == 0.0) flag = true;
		}
		
		if (flag) {
			double Chance = 0.0;
			double littleChance = 0.0;
			int count = 0;
			for (int j = 0; j < 4; j++) {
				if (MyProfile[j][i] > 0.0) {
					littleChance = (double)(size - HelpProfile[j][i]) * 0.002;
					if (littleChance == 0.0) littleChance = 0.002;
					MyProfile[j][i] -= littleChance;
					Chance += littleChance;	 	
				}
				else count++;
			}
			Chance = Chance / count;

			for (int j = 0; j < 4; j++) {
				if (MyProfile[j][i] == 0.0)
					MyProfile[j][i] += Chance;
			}

		}
	}
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
			tmpStr = "";
			//////////////////
			for (int SPoint = 0; SPoint < OurStr[j].length() - ProfileSize + 1; SPoint++) {
				tmpStr = GetStr(OurStr[j], SPoint, ProfileSize);
				tmp = GetScore(tmpStr, Profile);
				if (tmp > score) {
					score = tmp;
					MyFavorite = tmpStr;
				}
			}
			
			SetHelpProfile(MyFavorite, ProfileHelp);
			SetProfile(ProfileHelp, Profile, ProfileSize);			

			tmpRec.Str = MyFavorite;
			tmpRec.Score = GetScore(tmpRec.Str,Profile);

			Motifs.push_back(tmpRec);

		}


		double thisScore = 1.0;
		for (auto iter = Motifs.begin(); iter != Motifs.end(); iter++) {
			(*iter).Score = GetScore((*iter).Str, Profile);
			thisScore *= (*iter).Score;
		}


		if (TheBesterScore < thisScore) {
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
////////////////////////////////////// ������� 1 /////////////////////////////////////////


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
		tmpStr = GetStr(OurStr, SPoint, ProfileSize);			// ��������, ��� �� �����������
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