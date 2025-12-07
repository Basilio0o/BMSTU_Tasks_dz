#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	cout << "Начало..." << endl;
	auto start = std::chrono::high_resolution_clock::now();
	int sm = 0;
	for(int i = 0; i < 100000000; i++) sm += i;

	auto end = std::chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<std::chrono::milliseconds>(end - start);
	cout << duration.count() << endl;
	cout << "Конец..." << endl;
	return 0;
}
