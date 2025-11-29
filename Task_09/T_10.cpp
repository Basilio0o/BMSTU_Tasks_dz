#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <numeric>

using namespace std;

vector<double> Calculations(map<string, vector<double>>& Devices, const string& dev){
	vector<double> device = Devices[dev];
	vector<double> outputs(3);
	int measurements = device.size();
	double total = accumulate(device.begin(), device.end(), 0.0);
	outputs[0] = measurements;
	outputs[1] = total;
	outputs[2] = total / measurements;
	return outputs;
}

int main()
{
	vector<double> v1, v2, v3;
	map<string, vector<double>> Devices = { {"MotorA", v1}, {"PumpB", v2} };

	ifstream inFile("power_log.txt");
	if(inFile.is_open()){
		string line;
		string time;
		string dev;
		double value;
		while(getline(inFile, line)){
			istringstream stream(line);
			stream >> time >> dev >> value;
			Devices[dev].push_back(value);
		}

		vector<double> dev1 = Calculations(Devices, "MotorA");
		vector<double> dev2 = Calculations(Devices, "PumpB");

		ofstream outFile("energy_report.txt");
		if(outFile.is_open()){
			outFile << "MotorA: measurements = " << dev1[0] << ", total = " << dev1[1] << " kWh, average = " << dev1[2] << " kW" << endl;
			outFile << "PumpB: measurements = " << dev2[0] << ", total = " << dev2[1] << " kWh, average = " << dev2[2] << " kW" << endl;
			if(outFile.good()){
				cout << "Анализ завершён. Результаты сохранены в energy_report.txt" << endl;
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
