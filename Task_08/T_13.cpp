#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	unique_ptr<string> part1 = make_unique<string>("Sensor data:");
	unique_ptr<string> part2 = make_unique<string>("Voltage stable.");
	unique_ptr<string> part3 = make_unique<string>("System nominal.");

	vector<unique_ptr<string>> reportParts;
	reportParts.push_back(move(part1));
	reportParts.push_back(move(part2));
	reportParts.push_back(move(part3));

	string report = "";

	auto concatParts = [&report](vector<unique_ptr<string>>& repParts){
		for_each(repParts.begin(), repParts.end(), [&report](unique_ptr<string>& str){report += *str + "\n";});
	};

	auto countWord = [&report](string word){
		int count = 0;
		size_t pos = 0;
		while ((pos = report.find(word, pos)) != string::npos){
			count++;
			pos++;
		}
		return count;
	};

	concatParts(reportParts);

	int count_data = countWord("data");

	cout << "Отчёт:" << endl;
	cout << report;
	cout << "Слово 'data' встречается " << count_data << " раз(а)";

	return 0;
}
