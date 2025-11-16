#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main()
{
	vector<string> logs = {
	 "INFO: Start",
	 "ERROR: Disk failure",
	 "WARNING: Low memory",
	 "ERROR: Disk failure",
	 "INFO: Stop"
	};

	shared_ptr<vector<string>> pLogs = make_shared<vector<string>>(logs);

	vector<string> errors;

	auto isError = [](const string& str){
		return str.find("ERROR:") != string::npos;
	};

	copy_if(pLogs->begin(), pLogs->end(), back_inserter(errors), isError);

	sort(errors.begin(), errors.end());
	errors.erase(unique(errors.begin(), errors.end()), errors.end());

	cout << "Исходный журнал:" << endl;
	for(const string& i : logs) cout << i << endl;
	cout << endl;
	cout << "Ошибки:" << endl;
	for(const string& i : errors) cout << i << endl;

	return 0;
}
