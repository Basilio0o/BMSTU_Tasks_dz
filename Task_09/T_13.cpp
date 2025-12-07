#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
	int n;
	cout << "Введите n: ";
	cin >> n;
	for(int i = n; i > 0; i--){
	cout << "Осталось: " << i << " сек" << endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	cout << "Время вышло!" << endl;
	return 0;
}
