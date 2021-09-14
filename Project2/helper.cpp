#include "helper.h"
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>


bool valid_size(std::string input, int min, int max)
{
	if (is_int(input))
	{
		int num = stoi(input);

		if (num < min || num > max)
		{
			std::cout << "your number is not between "<< min << " and " << max << " inclusive" << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << "you did not enter an integer" << std::endl;
		return false;
	}
	return true;
}

int size_prompt(int min, int max, std::string prompt)
{
	int num = -1;
	std::string temp_input;
	do
	{
		std::cout << prompt << std::endl;
		std::cin >> temp_input;
		if (valid_size(temp_input, min, max))
		{
			return stoi(temp_input);
		}
	} while (num == -1);
}

bool is_int(std::string myString) {
	std::istringstream iss(myString);
	int f;
	iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
	// Check the entire string was consumed and if either failbit or badbit is set
	return iss.eof() && !iss.fail();
}