#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>

using namespace std;


class CircleSearcher {
private: 
	vector<vector<int> > _graph;
	vector<vector<int>> _circles;
public:
	CircleSearcher() {};

	void SetGraph(vector<vector<int> > newGraph) {
		_graph = newGraph;
	}

	// Есть ли ещё циклы?
	bool IsDone(int& startPositionNext) {
		bool flag = false;
		startPositionNext = 0;
		for (int i = 0; i < _circles.size(); i++) {
			flag = true;
			for (int j = 0; j < _circles[i].size(); j++) {
				if (IsHaveMoreCircle(_circles[i][j])) {
					flag = false;
					startPositionNext = _circles[i][j];
					break;
				}
			}
			if (!flag)
				break;
		}
		return flag;
	}
	
	// Содержит ли цикл вершину
	bool CircleHaveThis(int circleNumber, int vertexNumber) {
		bool res = false;
		for (int i = 0; i < _circles[circleNumber].size(); i++)
			if (_circles[circleNumber][i] == vertexNumber) {
				res = true;
				break;
			}

		return res;
	}
	
	// Сущуствуют ли неизвестные пути в вершине
	bool IsHaveMoreCircle(int vertexNumber) {
		for (int i = 0; i < _graph[vertexNumber].size(); i++)
			if (_graph[vertexNumber][i] != -1)
				return true;

		return false;
	}

	// Пометить ребро как пройденное
	void DeletePathFromFreeWay(int currVertex, int pathVertex) {
		for (int i = 0; i < _graph[currVertex].size(); i++)
			if (_graph[currVertex][i] == pathVertex) {
				_graph[currVertex][i] = -1;
				break;
			}
	}

	// Пройтись по известному циклу
	void GoToCircleNumber(int numberOfCircle, int startPosition) {
		int pos = 0;

		while (_circles[numberOfCircle][pos] != startPosition)
			pos++;
		
		int nextPos = pos + 1;
		if (nextPos >= _circles[numberOfCircle].size())
			nextPos = 0;

		do {
			// Удаляем ребра, которые знаем
			DeletePathFromFreeWay(_circles[numberOfCircle][pos], _circles[numberOfCircle][nextPos]);

			pos = nextPos;
			CloseAllFamousCircle(_circles[numberOfCircle][pos], numberOfCircle);

			nextPos++; 
			if (nextPos >= _circles[numberOfCircle].size())
				nextPos = 0;
		} while (_circles[numberOfCircle][pos] != startPosition);
	}

	void CloseAllFamousCircle(int numberVertex, int callCircle = -1) {
		for (int i = 0; i < _circles.size(); i++) {
			if (callCircle != i && CircleHaveThis(i, numberVertex))
				GoToCircleNumber(i, numberVertex);
		}
	}

	void SearchAndSaveNewCircleFrom(int position) {
		CloseAllFamousCircle(position);

		vector<int> newCircle;		
		int nextVertex = -1;
		int currentPos = position;
		while (nextVertex != position) {

			newCircle.push_back(currentPos);
			// Ищем неизвестный путь
			for (int i = 0; i < _graph[currentPos].size(); i++)
				if (_graph[currentPos][i] != -1) {
					nextVertex = _graph[currentPos][i];
					break;
				}
			DeletePathFromFreeWay(currentPos, nextVertex);
			currentPos = nextVertex;
		}
		newCircle.push_back(position);

		_circles.push_back(newCircle);		
	}

	// Печать
	void WritePath() {
		cout << "Circle count: " << _circles.size() << endl << endl;

		for (int i = 0; i < _circles.size(); i++) {
			cout << i << " : ";
			for (int j = 0; j < _circles[i].size(); j++)
				cout << _circles[i][j] << "->";
			cout << endl;
		}
	}

};

int GetNumber(string str, int& startPos) {
	string value = "";
	int result = 0;
	while (startPos < str.length() && str[startPos] <= '9' && str[startPos] >= '0') {
		value += str[startPos];
		startPos++;
	}
	for (int i = 0; i < value.length(); i++) {
		result += pow(10, value.length() - i - 1) * (value[i] - '0');
	}
	startPos++;
	return result;
}

void AddPairToMap(map<int, vector<int>>& mapa, string str) {
	int position = 0;
	vector<int> vertexes;
	int key = GetNumber(str, position);

	while (position < str.length()) {
		if (str[position] > '9' || str[position] < '0')
			position++;
		else
			vertexes.push_back(GetNumber(str, position));
	}

	mapa.insert(pair<int, vector<int>>(key, vertexes));
}

int main() {
	int tmpPosition;
	string str1;
	map<int, vector<int>> mapa;

	for (int i = 0; i < 16; i++) {
		getline(cin, str1);
		AddPairToMap(mapa, str1);
	}
	
	vector<vector<int>> graph;

	for (auto iter = mapa.begin(); iter != mapa.end(); iter++)
		graph.push_back(iter->second);

	CircleSearcher searcher;
	searcher.SetGraph(graph);

	while (!searcher.IsDone(tmpPosition)) {
		searcher.SetGraph(graph);
		searcher.SearchAndSaveNewCircleFrom(tmpPosition);
	}

	searcher.WritePath();

	return 0;
}