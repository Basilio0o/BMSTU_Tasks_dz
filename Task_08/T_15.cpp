#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> routes = {
	 "Moscow-Berlin",
	 "Berlin-Paris",
	 "Paris-Rome",
	 "Rome-Moscow"
	};

	shared_ptr<vector<string>> ptrRoutes = make_shared<vector<string>>(routes);

	auto countCit = [](const shared_ptr<vector<string>>& ptrRoutes, string str){
		int count = 0;
		for(const string& route : *ptrRoutes){
			if(route.find(str) != string::npos) count++;
		}
		return count;
	};

	auto sortByLength = [](const shared_ptr<vector<string>>& ptrRoutes){
		sort(ptrRoutes->begin(), ptrRoutes->end(), [](const string& a, const string& b){
			size_t posA = a.find('-');
			size_t posB = b.find('-');
			return a.substr(0, posA) < b.substr(0, posB);
		});
	};

	auto concat = [](const shared_ptr<vector<string>>& ptrRoutes){
		string genroute = (*ptrRoutes)[0];
		for_each(ptrRoutes->begin() + 1, ptrRoutes->end(), [&genroute](string& str){genroute += " -> " + str;});
		return genroute;
	};

	int count_Paris = countCit(ptrRoutes, "Paris");
	sortByLength(ptrRoutes);
	string str = concat(ptrRoutes);

	cout << "Количество маршрутов с 'Paris': " << count_Paris << endl;
	cout << "Отсортированные маршруты:" << endl;
	for(string i : *ptrRoutes) cout << i << endl;
	cout << endl;
	cout << "Общий маршрут:\n" << str;

	return 0;
}
