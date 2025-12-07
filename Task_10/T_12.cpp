#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <chrono>
#include <random>

using namespace std;

void Operation1(const vector<double>& num, const string& FileName){
	ofstream file(FileName, ios::binary);
	if(!file.is_open()){
		cerr << "Ошибка! Не удалось открыть файл для записи" << endl;
		return;
	}
    for (const auto& i : num) {
        file.write(reinterpret_cast<const char*>(&i), sizeof(i));
    }

	file.close();
	cout << "Данные успешно записаны в файл " << FileName << endl;
}

void Operation2(const vector<double>& num, const string& FileName){
	ofstream file(FileName, ios::binary);
	if(!file.is_open()){
		cerr << "Ошибка! Не удалось открыть файл для записи" << endl;
		return;
	}
	size_t count = num.size();
	file.write(reinterpret_cast<const char*>(num.data()), count * sizeof(double));
	file.close();
	cout << "Данные успешно записаны в файл " << FileName << endl;
}

int main()
{
	int n = 10000000;
	string FileName1 = "1.txt";
	string FileName2 = "2.txt";

	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<double> dis(0.0, 1000.0);

	vector<double> num(n);

	for(int i = 0; i < n; i++) num[i] = dis(gen);

	auto time1 = [num](const string& FileName){
	    auto start = chrono::steady_clock::now();
	    Operation1(num, FileName);
	    auto end = chrono::steady_clock::now();
	    auto duration = std::chrono::duration_cast<chrono::milliseconds>(end - start);
	    cout << "Запись первым способом заняла: " << duration.count() << " мс" << endl;
	    return duration;
	}(FileName1);

	auto time2 = [num](const string& FileName){
	    auto start = chrono::steady_clock::now();
	    Operation2(num, FileName);
	    auto end = chrono::steady_clock::now();
	    auto duration = std::chrono::duration_cast<chrono::milliseconds>(end - start);
	    cout << "Запись вторым способом заняла: " << duration.count() << " мс" << endl;
	    return duration;
	}(FileName2);

	return 0;
}
