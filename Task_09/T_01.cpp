#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile("input.txt");
	if(inFile.is_open()){
		string line;
		cout << "Содержимое файла:" << endl;
		while(getline(inFile, line)){
			cout << line << endl;
		}
		inFile.close();
	}
	else cerr << "Не удалось открыть файл для чтения." << endl;
	return 0;
}
