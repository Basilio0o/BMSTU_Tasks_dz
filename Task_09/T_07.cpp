#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	int sum, count;
	ifstream inFile("numbers.txt");
	if(inFile.is_open()){
		int num;
		while(inFile >> num){
			sum += num;
			count++;
		}
		cout << "Количество чисел: " << count << endl;
		cout << "Сумма: " << sum << endl;
		cout << "Среднее: " << fixed << setprecision(2) << (double)sum/count << endl;
		inFile.close();
	}else{
		cerr << "Не удалось открыть файл для чтения." << endl;
	}
	return 0;
}
