#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream inFile1("file1.txt");
	ifstream inFile2("file2.txt");
	if(inFile1.is_open() && inFile2.is_open()){
		string line1;
		string line2;
		bool f = true;
		while(getline(inFile1, line1) && getline(inFile2, line2)){
			if(line1 != line2){
				cout << "Файлы различаются." << endl;
				cout << line1 << endl;
				cout << line2 << endl;
				f = false;
				break;
			}
		}
		if(f && (!line1.empty() || !line2.empty())){
			cout << "Файлы различаются." << endl;
			f = false;
		}
		if(f) cout << "Файлы идентичны." << endl;
		inFile1.close();
		inFile2.close();
	}else{
		cerr << "Не удалось открыть файлы для сравнения." << endl;
	}
	return 0;
}
