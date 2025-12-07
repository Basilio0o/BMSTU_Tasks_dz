#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main()
{
  int n;
  cout << "Введите количество секунд: ";
  cin >> n;
  std::chrono::seconds sec(n);
  auto hours = std::chrono::duration_cast<std::chrono::hours>(sec);
  auto minutes = std::chrono::duration_cast<std::chrono::minutes>(sec % chrono::hours(1));
  std::chrono::seconds seconds = sec % chrono::minutes(1);
  cout << hours.count() << " h, " << minutes.count() << " m, " << seconds.count() << " s" << endl;
  return 0;
}
