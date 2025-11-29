#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int count = 0;
	ifstream inFile("input.txt");
	if(inFile.is_open()){
		char ch;
		while(inFile.get(ch)){
			count++;
		}
		cout << "Количество символов в файле: " << count;
		inFile.close();
	}else{
		cerr << "Не удалось открыть файл для чтения." << endl;
	}
	return 0;
}
