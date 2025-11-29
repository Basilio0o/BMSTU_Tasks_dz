#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile("data.txt");
	if(inFile.is_open()){
		int count = 0;
		string line;
		while(getline(inFile, line)){
			count++;
		}
		cout << "Количество строк в файле: " << count;
		inFile.close();
	}
	else{
		cerr << "Не удалось открыть файл для чтения." << endl;
	}
	return 0;
}
