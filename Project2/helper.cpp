#include "helper.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <time.h>


bool martingale(long long &money, std::vector<std::string> wheel)
{	
	if (wheel.empty())
	{
		std::cout << "wheel empty" << std::endl;
		return false;
	}

	
	long long bet = 1;

	while (bet <= money) 
	{
		money -= bet;

		int slot = rand() % wheel.size();

		if (wheel.at(slot) == "black")
		{
			money += bet * 2;
			return true;
		}
		else
		{
			bet *= 2;
		}
	}
	return false;
}

bool random_strat(long long &money, std::vector<std::string> wheel)
{
	int bet_counter = 0;

	if (wheel.empty())
	{
		std::cout << "wheel empty" << std::endl;
		return false;
	}

	
	long long bet = 1;

	while (bet <= money && bet_counter < 50) 
	{
		bet = rand() % money + 1;
		bet_counter++;

		int slot = rand() % wheel.size();

		if (wheel.at(slot) == "black")
		{
			money += bet;
		}
		else
		{
			money -= bet;
		}
	}

}

bool fixed_strat(long long &money, long long bet, std::vector<std::string> wheel)
{
	int bet_counter = 0;

	if (wheel.empty())
	{
		std::cout << "wheel empty" << std::endl;
		return false;
	}

	while (bet <= money && bet_counter < 50)
	{
		bet_counter++;

		int slot = rand() % wheel.size();

		if (wheel.at(slot) == "black")
		{
			money += bet;
		}
		else
		{
			money -= bet;
		}
	}

}

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

void populate_wheel(std::vector<std::string> &wheel, int slots, int zeros)
{
	int current_zeros = 0;

	for (int i = 0; i < slots; i++)
	{
		if ((i == 0 || i == slots / 2) && current_zeros < zeros)
		{
			wheel.push_back("green");
			current_zeros++;
		}
		else if (i % 2)
		{
			wheel.push_back("red");
		} 
		else
		{
			wheel.push_back("black");
		}
	}
}

long long max(long long x, long long y)
{
	if (x > y)
		return x;
	else
		return y;
}