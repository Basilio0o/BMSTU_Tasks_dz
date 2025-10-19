#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
   char str[100];
   cout << "Enter the string: ";
   cin.getline(str, 100);
   const char det[] = " ";
   char* tok = strtok(str, det);
   while(tok != nullptr)
   {
	   reverse(tok, tok + strlen(tok));
	   cout << tok << " ";
	   tok = strtok(nullptr, det);
   }
   return 0;
}
