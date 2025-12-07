#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<double> ReadFile(const string& FileName){
	vector<double> values;
	ifstream inFile(FileName);
	if(!inFile.is_open()){
		cerr << "Ошибка! Не удалось открыть файл для чтения" << endl;
		return values;
	}
	double value;
	while(inFile >> value){
		values.push_back(value);
	}
	return values;
}

void WriteFile(const string& FileName, const vector<double>& num){
	ofstream outFile(FileName);
	if(!outFile.is_open()){
		cerr << "Ошибка! Не удалось открыть файл для чтения" << endl;
	}
	for(size_t i = 0; i < num.size(); i++){
		outFile << num[i] << endl;
	}
	outFile.close();
}

int main()
{
	string FileName = "sensor_data.txt ";
	string FileName2 = "sensor_data_filtred.txt ";
	vector<double> Temperature = ReadFile(FileName);

	auto filter = [Temperature](){
		vector<double> filtred_temperature;
		copy_if(Temperature.begin(), Temperature.end(), back_inserter(filtred_temperature),
				[](double a){return -50 < a && a < 50;});
		return filtred_temperature;
	};

	vector<double> filtred_temperature = filter();

	auto avg = [filtred_temperature](){
		return accumulate(filtred_temperature.begin(), filtred_temperature.end(), 0.0) / filtred_temperature.size();
	};

	double avg_temp = avg();

	cout << "Средняя температура: " << avg_temp << endl;
	WriteFile(FileName2, filtred_temperature);

	return 0;
}
