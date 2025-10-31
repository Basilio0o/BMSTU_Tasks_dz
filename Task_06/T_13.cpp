#include <iostream>

using namespace std;

void parseTelemetry(const char* data)
{
	while(*data != '\0')
	{
		switch (*data)
		{
			case 'T':
				if(*(data+3) == 'P') cout << "Temperature: ";
				break;
			case 'P':
				if(*(data+4) == 'S') cout << "Pressure: ";
				break;
			case 'H':
				cout << "Humidity: ";
				break;
		}

		if(*data == ':')
		{
			data++;
			while(*data != ';' && *data != '\0') cout << *(data++);
			cout << "\n";
		}
		data++;
	}
}

int main()
{
	char str[] = "TEMP:24.5;PRESS:101.3;HUM:55.2";
	char* ptr = str;
	parseTelemetry(ptr);
	return 0;
}
