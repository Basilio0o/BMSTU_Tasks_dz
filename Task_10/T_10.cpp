#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void CreateConfig(const string& FileName){
	ofstream file(FileName);
	file << "{\n";
	file << " \"app_name\": \"My Application\",\n";
	file << " \"version\": \"1.0.0\",\n";
	file << " \"settings\": {\n";
	file << " \"max_connections\": 100,\n";
	file << " \"timeout\": 30,\n";
	file << " \"debug_mode\": true\n";
	file << " },\n";
	file << " \"database\": {\n";
	file << " \"host\": \"localhost\",\n";
	file << " \"port\": 5432,\n";
	file << " \"username\": \"admin\"\n";
	file << " }\n";
	file << "}";
	file.close();
	cout << "Конфигурационный файл создан\n";
}

void ReadConfig(const string& FileName){
	ifstream file(FileName);
	if(!file.is_open()){
		cerr << "Ошибка! Не удалось открыть файл для чтения" << endl;
	}
	string line;
	while(getline(file, line)){
		cout << line << endl;
	}
	file.close();
}

void EditConfig(const string& FileName, const string& key, const string& value){
	vector<string> lines;
	ifstream infile(FileName);
	if(!infile.is_open()){
		cerr << "Ошибка! Не удалось открыть файл для чтения" << endl;
	}
	string line;
	while(getline(infile, line)){
		 size_t pos = line.find(key);
		 if(pos != string::npos){
			 string value_old = line.substr(pos + key.size() + 3);
			 line.replace(pos + key.size() + 3, value_old.size(), value + ",");
		 }
		 lines.push_back(line);
	}
	infile.close();
	ofstream outfile(FileName);
	if(!outfile.is_open()){
		cerr << "Ошибка! Не удалось открыть файл для записи" << endl;
	}
	for(string i : lines){
		outfile << i << endl;
	}
}

int main()
{
	string FileName = "config.json";
	string key = "timeout";
	string value = "60";
	CreateConfig(FileName);
	ReadConfig(FileName);
	EditConfig(FileName, key, value);
	return 0;
}
