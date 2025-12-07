#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void OutputIntoFile(int array[], size_t size, const string& FileName){

	ofstream outFile(FileName, ios::binary);

	if(outFile.is_open()){

		outFile.write(reinterpret_cast<char* >(&size), sizeof(size));
		outFile.write(reinterpret_cast<const char*>(array), size * sizeof(int));
		outFile.close();

	}else{
		cerr << "Ошибка! Не удалось открыть файл для записи" << endl;
	}
}

vector<int> InputFromFile(const string& FileName){
	vector<int> num;
	ifstream inFile(FileName, ios::binary);

	if(inFile.is_open()){

        size_t size;
        inFile.read(reinterpret_cast<char*>(&size), sizeof(size));

		num.resize(size);
		inFile.read(reinterpret_cast<char*>(num.data()), size * sizeof(int));

		inFile.close();
	}else{
		cerr << "Ошибка! Не удалось открыть файл для чтения" << endl;
	}
	return num;
}

int main(){
	string FileName = "numbers.bin";
	int numbers[] = {15, 23, 7, 42, 18, 91, 3, 56, 77, 10};
	size_t size = sizeof(numbers) / sizeof(numbers[0]);
	OutputIntoFile(numbers, size, FileName);
	vector<int> num = InputFromFile(FileName);
	for(int i : num){
		cout << i << " ";
	}
    return 0;
}
