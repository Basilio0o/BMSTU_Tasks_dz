#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Command {
	string name;
	int value;
};

void parseCommand(const char* input, vector<Command>& buffer)
{
	const char* start = input;
	while (*input != ' ' && *input != '\0') input++;
	string cmd_name(start, input - start);
	int cmd_value = 0;
	if(*input == ' ')
	{
		input++;
		bool isneg = false;
		if(*input == '-')
		{
			isneg = true;
			input++;
		}
		while(*input >= '0' && *input <= '9')
		{
			cmd_value = cmd_value * 10 + (*input - '0');
			input++;
		}

		if(isneg) cmd_value = -cmd_value;
	}
	Command cmd;
	cmd.name = cmd_name;
	cmd.value = cmd_value;
	buffer.push_back(cmd);
}

void OutputCommand(const vector<Command>& buffer)
{
	for (const auto& cmd : buffer) cout << "Command: " << cmd.name << ", Value: " << cmd.value << endl;
}

int main()
{
	vector<Command> buffer;
	parseCommand("FORWARD 10", buffer);
	parseCommand("TURN 90", buffer);
	parseCommand("STOP", buffer);
	OutputCommand(buffer);
	return 0;
}
