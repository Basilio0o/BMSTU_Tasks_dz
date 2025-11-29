#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	cout << "Введите строки (пустая строка завершает ввод):" << endl;
	ofstream outFile("output.txt");
	if(outFile.is_open()){
		string line;
		getline(cin, line);
		while(!line.empty()){
			outFile << line << endl;
			getline(cin, line);
		}
		if(outFile.good()){
			cout << "Данные записаны в файл output.txt." << endl;
		}
		outFile.close();
	}else{
		cerr << "Не удалось открыть файл для записи." << endl;
	}
	return 0;
}
