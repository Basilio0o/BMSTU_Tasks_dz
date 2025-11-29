#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

vector<double> Calculations(map<string, vector<double>>& Sensors, const string& sen){
	vector<double> sensor = Sensors[sen];
	vector<double> outputs(3);
	double min = *min_element(sensor.begin(), sensor.end());
	double max = *max_element(sensor.begin(), sensor.end());
	double avg = accumulate(sensor.begin(), sensor.end(), 0.0) / sensor.size();
	outputs[0] = min;
	outputs[1] = max;
	outputs[2] = avg;
	return outputs;
}

int main()
{
	vector<double> v1, v2, v3;
	map<string, vector<double>> Sensors = { {"Sensor1", v1}, {"Sensor2", v2}, {"Sensor3", v3} };

	ifstream inFile("temperature_data.txt");
	if(inFile.is_open()){
		string line;
		string sen;
		double value;
		while(getline(inFile, line)){
			istringstream stream(line);
			stream >> sen >> value;
			Sensors[sen].push_back(value);
		}

		vector<double> sen1 = Calculations(Sensors, "Sensor1");
		vector<double> sen2 = Calculations(Sensors, "Sensor2");
		vector<double> sen3 = Calculations(Sensors, "Sensor3");

		ofstream outFile("report.txt");
		if(outFile.is_open()){
			outFile << "Sensor1: min = " << sen1[0] << ", max = " << sen1[1] << ", avg = " << sen1[2] << endl;
			outFile << "Sensor2: min = " << sen2[0] << ", max = " << sen2[1] << ", avg = " << sen2[2] << endl;
			outFile << "Sensor3: min = " << sen3[0] << ", max = " << sen3[1] << ", avg = " << sen3[2] << endl;
			if(outFile.good()){
				cout << "Отчёт о температурных данных сохранён в report.txt" << endl;
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
