#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> Lines;
	string word = "timeout=";
	string value = "60";
	ifstream inFile("config.txt");
	if(inFile.is_open()){
		string line;
		string value_old;
		while(getline(inFile, line)){
			 size_t pos = line.find(word);
			 if(pos != string::npos){
				 value_old = line.substr(pos + word.size());
				 line.replace(pos + word.size(), value_old.size(), value);
			 }
			 Lines.push_back(line);
		}
		inFile.close();
		ofstream outFile("config.txt");
		if(outFile.is_open()){
			for(const auto& l : Lines){
				outFile << l << endl;
			}
			outFile.close();
		}
		if(outFile.good()){
			cout << "Замена прошла успешно" << endl;
		}
	}else{
		cerr << "Ошибка! Не удалось открыть файл" << endl;
	}
	return 0;
}
