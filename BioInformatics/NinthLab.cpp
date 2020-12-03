//////////////////////////////////////////////////////////////////////////////////////
//							9.1 Eulerian Cycle Problem
//////////////////////////////////////////////////////////////////////////////////////


/*
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
	void WritePath(int startCircle, int startValue = -1) {
		int position = 0;
		if (startValue != -1) {
			while (_circles[startCircle][position] != startValue)
				position++;
		}

		int i = position;

		if (startValue == -1) {
			cout << _circles[startCircle][i] << "->";
		}

		for (int j = startCircle + 1; j < _circles.size(); j++) {
			if (CircleHaveThis(j, _circles[startCircle][i]))
				WritePath(j, _circles[startCircle][i]);
		}

		i++;
		if (i >= _circles[startCircle].size())
			i = 0;

		while (i != position) {
			cout << _circles[startCircle][i] << "->";
			for (int j = startCircle + 1; j < _circles.size(); j++) {
				if (CircleHaveThis(j, _circles[startCircle][i]))
					WritePath(j, _circles[startCircle][i]);
			}
			i++;
			if ((startCircle == 0 && i >= _circles[startCircle].size() - 1) || i >= _circles[startCircle].size())
				i = 0;
		}
		if (startCircle == 0)
			cout << _circles[startCircle][0];

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
	
	while (getline(cin, str1))
		AddPairToMap(mapa, str1);

	vector<vector<int>> graph;

	for (auto iter = mapa.begin(); iter != mapa.end(); iter++)
		graph.push_back(iter->second);

	CircleSearcher searcher;
	searcher.SetGraph(graph);

	while (!searcher.IsDone(tmpPosition)) {
		// searcher.SetGraph(graph);
		searcher.SearchAndSaveNewCircleFrom(tmpPosition);
	}

	searcher.WritePath(0);

	return 0;
}
*/

//////////////////////////////////////////////////////////////////////////////////////
//						9.2 Eulerian Path Problem
//////////////////////////////////////////////////////////////////////////////////////

/*

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
	vector<int> _activeCircles;

	bool IsActiveCircle(int numberOfCircle) {
		for (int i = 0; i < _activeCircles.size(); i++)
			if (_activeCircles[i] == numberOfCircle)
				return true;

		return false;
	}

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
	void WritePath(int startCircle, int startValue = -1) {
		_activeCircles.push_back(startCircle);
		int position = 0;
		if (startValue != -1) {
			while (_circles[startCircle][position] != startValue)
				position++;
		}

		int i = position;

		if (startCircle == _activeCircles[0]) {
			cout << _circles[startCircle][i] << "->";
		}

		for (int j = 0; j < _circles.size(); j++) {
			if (!IsActiveCircle(j) && CircleHaveThis(j, _circles[startCircle][i]))
				WritePath(j, _circles[startCircle][i]);
		}

		i++;
		if (i >= _circles[startCircle].size())
			i = 0;

		while (i != position) {
			cout << _circles[startCircle][i] << "->";
			for (int j = startCircle + 1; j < _circles.size(); j++) {
				if (!IsActiveCircle(j) && CircleHaveThis(j, _circles[startCircle][i]))
					WritePath(j, _circles[startCircle][i]);
			}
			i++;
			if ((startCircle == _activeCircles[0] && i >= _circles[startCircle].size() - 1) || i >= _circles[startCircle].size())
				i = 0;
		}
		if (startCircle == _activeCircles[0])
			cout << _circles[startCircle][_circles[startCircle].size()-1];
		_circles[startCircle].clear();

	}

	// Удаляем ребро (необходимо для удаления "придуманного" ребра)
	int DeleteEgdeFromCircle(int startEdge, int finishEdge) {

		for (int i = 0; i < _circles.size(); i++) {
			for (int j = 0; j < _circles[i].size()-1; j++)
				if (_circles[i][j] == startEdge && _circles[i][j + 1] == finishEdge) {
					int position = j + 2;

					if (position >= _circles[i].size())
						position = 0;

					vector<int> newCircle;
					while (position != j + 1) {
						newCircle.push_back(_circles[i][position]);
						position++;
						if (position >= _circles[i].size())
							position = 0;
					}

					_circles[i] = newCircle;
					return i;
				}
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

// Узнаём вершину у которой больше выходных рёбер. И вершину у которой больше входных ребер. (Начала и конец графа)
void GetFirstAndLastElement(vector<vector<int> > vect, int &startPos, int &endPos) {
	vector<int> inputEdgeCount;
	vector<int> outputEdgeCount;
	
	int size = vect.size();

	for (int i = 0; i < size; i++) {
		inputEdgeCount.push_back(0);
		outputEdgeCount.push_back(0);
	}

	for (int i = 0; i < size; i++) {
		outputEdgeCount[i] = vect[i].size();
		for (int j = 0; j < vect[i].size(); j++)
			inputEdgeCount[vect[i][j]]++;
	}

	for (int i = 0; i < size; i++) {
		if (inputEdgeCount[i] > outputEdgeCount[i])
			endPos = i;

		if (inputEdgeCount[i] < outputEdgeCount[i])
			startPos = i;
	}
}

// Преобразование отсортированной мапы к вектору(учитываются возможные пропуски)
vector<vector<int>> ConvertMapToVector(map <int, vector<int> > mapa) {
	
	//vector<int> number;

	int max = 0;

	for (auto iter = mapa.begin(); iter != mapa.end(); iter++) {
		
		if (iter->first > max) 
			max = iter->first;

		for (int j = 0; j < iter->second.size(); j++) {
			if (iter->second[j] > max)
				max = iter->second[j];
		}
	}

	vector<vector<int> > result;
	vector<int> tmp;

	for (int i = 0; i <= max; i++)
		result.push_back(tmp);

	for (auto iter = mapa.begin(); iter != mapa.end(); iter++)
		result[iter->first] = iter->second;
	
	return result;
}


int main() {
	int tmpPosition;
	string str1;
	map<int, vector<int>> mapa;

	while(getline(cin, str1))
		AddPairToMap(mapa, str1);

	vector<vector<int>> graph = ConvertMapToVector(mapa);

	// Добавляем ребро конец-начало, для циклов
	int start, finish;
	GetFirstAndLastElement(graph, start, finish);
	graph[finish].push_back(start);

	CircleSearcher searcher;
	searcher.SetGraph(graph);

	bool isFirst = true;

	while (!searcher.IsDone(tmpPosition)) {
		// searcher.SetGraph(graph);
		if (isFirst) {
			tmpPosition = start;
			isFirst = false;
		}

		searcher.SearchAndSaveNewCircleFrom(tmpPosition);
	}

	auto tmp = searcher.DeleteEgdeFromCircle(finish, start);

	searcher.WritePath(tmp, start);

	return 0;
}

*/