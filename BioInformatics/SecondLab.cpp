#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool Amin(char chr) {
	return (chr == 'A' || chr == 'U' || chr == 'C' || chr == 'G');
}

string TransfortToRNA(string defSTR) {
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

	switch (Str_3D[0])
	{
	case 'A': {
		switch (Str_3D[1])
		{
		case 'A': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'K';
			else return 'N';

		}
		case 'C': {
			return 'T';
			break;
		}
		case 'U': {
			if (Str_3D[2] == 'G') return 'M';
			else return 'I';
		}
		case 'G': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'R';
			else return 'S';
		}
		default:
			return '0';
		}
		break;
	}
	case 'C': {
		switch (Str_3D[1])
		{
		case 'A': {
			switch (Str_3D[2]) {
			case 'A': {}
			case 'G': {
				return 'Q';
				break;
			}
			default: {
				return 'H';
			}
			}
			break;
		}
		case 'C': {
			return 'P';
			break;
		}
		case 'U': {
			return 'L';
			break;
		}
		case 'G': {
			return 'R';
			break;
		}
		default:
			return '0';
			break;
		}
		break;
	}
	case 'U': {
		switch (Str_3D[1])
		{
		case 'A': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return ' ';
			else return 'Y';
			break;
		}
		case 'C': {
			return 'S';
			break;
		}
		case 'U': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'L';
			else return 'F';
			break;
		}
		case 'G': {
			switch (Str_3D[2]) {
			case 'U': {}
			case'C': {return 'C'; }
			case 'A': return ' ';
			case 'G': return 'W';
			default: return '0';
			}
			break;
		}
		default:
			return '0';
			break;
		}
		break;
	}
	case 'G': {
		switch (Str_3D[1])
		{
		case 'A': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'E';
			else return 'D';
			return '0';
			break;
		}
		case 'C': {
			if (Amin(Str_3D[2]))
				return 'A';
			else return '0';
			break;
		}
		case 'U': {
			if (Amin(Str_3D[2]))
				return 'V';
			else return '0';
			break;
		}
		case 'G': {
			if (Amin(Str_3D[2]))
				return 'G';
			else return '0';
			break;
		}
		default:
			return '0';
			break;
		}
		break;
	}
	default:
		return '0';
		break;
	}
	return '0';
}

void Add(char& a) {
	switch (a) {
	case 'A': {
		a = 'C';
		break;
	}
	case 'C': {
		a = 'G';
		break;
	}
	case 'G': {
		a = 'U';
		break;
	}
	case 'U': {
		a = '0';
		break;
	}
	}
}

int main() {

	ofstream fout;
	fout.open("AminoToRNA.txt");

	string Str;
	string str_3d = "";
	string result = "";	

	for (char a = 'A'; a!='0'; Add(a)) {
		for (char b = 'A'; b != '0'; Add(b)) {
			for (char c = 'A'; c != '0'; Add(c)) {
				str_3d = "";
				str_3d += a;
				str_3d += b;
				str_3d += c;
				fout << Transform(str_3d) << ' ' << str_3d << endl;
			}
		}
	}

	fout.close();

	return 0;
}

//////////////////////////////////////////////////////////////////////////
/*
	ÇÀÄÀÍÈÅ 1

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool Amin(char chr) {
	return (chr == 'A' || chr == 'U' || chr == 'C' || chr == 'G');
}

string TransfortToRNA(string defSTR) {
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

	switch (Str_3D[0])
	{
	case 'A': {
		switch (Str_3D[1])
		{
		case 'A': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'K';
			else return 'N';

		}
		case 'C': {
			return 'T';
			break;
		}
		case 'U': {
			if (Str_3D[2] == 'G') return 'M';
			else return 'I';
		}
		case 'G': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'R';
			else return 'S';
		}
		default:
			return '0';
		}
		break;
	}
	case 'C': {
		switch (Str_3D[1])
		{
		case 'A': {
			switch (Str_3D[2]) {
			case 'A': {}
			case 'G': {
				return 'Q';
				break;
			}
			default: {
				return 'H';
			}
			}
			break;
		}
		case 'C': {
			return 'P';
			break;
		}
		case 'U': {
			return 'L';
			break;
		}
		case 'G': {
			return 'R';
			break;
		}
		default:
			return '0';
			break;
		}
		break;
	}
	case 'U': {
		switch (Str_3D[1])
		{
		case 'A': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return ' ';
			else return 'Y';
			break;
		}
		case 'C': {
			return 'S';
			break;
		}
		case 'U': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'L';
			else return 'F';
			break;
		}
		case 'G': {
			switch (Str_3D[2]) {
			case 'U': {}
			case'C': {return 'C'; }
			case 'A': return ' ';
			case 'G': return 'W';
			default: return '0';
			}
			break;
		}
		default:
			return '0';
			break;
		}
		break;
	}
	case 'G': {
		switch (Str_3D[1])
		{
		case 'A': {
			if (Str_3D[2] == 'A' || Str_3D[2] == 'G') return 'E';
			else return 'D';
			return '0';
			break;
		}
		case 'C': {
			if (Amin(Str_3D[2]))
				return 'A';
			else return '0';
			break;
		}
		case 'U': {
			if (Amin(Str_3D[2]))
				return 'V';
			else return '0';
			break;
		}
		case 'G': {
			if (Amin(Str_3D[2]))
				return 'G';
			else return '0';
			break;
		}
		default:
			return '0';
			break;
		}
		break;
	}
	default:
		return '0';
		break;
	}
	return '0';
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

*/

