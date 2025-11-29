#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	int count = 0;
	ifstream inFile("text.txt");
	if(inFile.is_open()){
		string word;
		while(inFile >> word){
			if(word != "—") count++;
		}
		cout << "Количество слов в файле: " << count;
		inFile.close();
	}else{
		cerr << "Не удалось открыть файл для чтения." << endl;
	}
	return 0;
}
