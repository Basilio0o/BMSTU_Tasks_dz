#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	string word = "hero";
	vector<pair<int, int>> positions;
	int count_lines = 1;
	ifstream inFile("book.txt", ios::in);
	ofstream outFile("search_report.txt", ios::out);
	if(inFile.is_open() && outFile.is_open()){
		string line;
		string temp;
		while(getline(inFile, line)){
			istringstream ss(line);
			int word_pos = 1;
			while(ss >> temp){
				if(temp.find(word) != string::npos){
					positions.push_back(make_pair(count_lines, word_pos));
				}
				word_pos += temp.length() + 1;
			}
			count_lines++;
		}
		cout << "Найдено " << positions.size() << " совпадений:" << endl;
		for(const auto& i : positions){
		  outFile << "Строка " << i.first << ", позиция " << i.second << "\n";
		}
		cout << "Результат работы программы записан в файл search_report.txt" << endl;

		inFile.close();
		outFile.close();
	}else{
		cerr << "Ошибка! Не удалось выполнить операцию копирования" << endl;
	}
	return 0;
}
