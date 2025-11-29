#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	ifstream inFile("source.txt");
	ofstream outFile("copy.txt");
	if(inFile.is_open() && outFile.is_open()){
		string line;
		while(getline(inFile, line)){
			outFile << line << endl;
			count++;
		}
		if(outFile.good()){
			cout << "Файл успешно скопирован." << endl;
			cout << "Количество скопированных строк: " << count;
		}
		inFile.close();
		outFile.close();
	}else{
		cerr << "Не удалось совершить операцию копирования." << endl;
	}
	return 0;
}
