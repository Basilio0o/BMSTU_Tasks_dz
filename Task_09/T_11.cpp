#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	vector<double> vib;
	ifstream inFile("vibration_log.txt");
	if(inFile.is_open()){
		double value;
		while(inFile >> value){
			vib.push_back(value);
		}

		auto Calc = [](vector<double>& vib){
			size_t measurements = vib.size();
			vib.erase(remove_if(vib.begin(), vib.end(), [](double a){return a <= 0.05;}), vib.end());
			vector<double> outputs(4);
			double avg = accumulate(vib.begin(), vib.end(), 0.0) / vib.size();
			double mx = *(max_element(vib.begin(), vib.end()));
			double mn = *(min_element(vib.begin(), vib.end()));
			outputs[0] = measurements;
			outputs[1] = avg;
			outputs[2] = mn;
			outputs[3] = mx;
			return outputs;
		};
		vector<double> outputs = Calc(vib);

		ofstream outFile("vibration_report.txt");
		if(outFile.is_open()){
			outFile << "Количество измерений: " << outputs[0] << endl;
			outFile << "Фильтрованные значения (>0.05): ";
			for(double i : vib){
				outFile << i << " ";
			}
			outFile << endl;
			outFile << "Среднее значение: " << outputs[1] << endl;
			outFile << "Минимум: " << outputs[2] << endl;
			outFile << "Максимум: " << outputs[3] << endl;
			if(outFile.good()){
				cout << "Анализ вибрационных данных завершён. Отчёт сохранён в vibration_report.txt" << endl;
			}
			outFile.close();
		}else{
			cerr << "Не удалось открыть файлы для записи." << endl;
		}
		inFile.close();
	}else{
		cerr << "Не удалось открыть файлы для чтения." << endl;
	}
	return 0;
}
