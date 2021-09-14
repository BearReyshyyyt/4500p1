#include "helper.h"
#include <iostream>
#include <vector>

int main()
{
	std::string temp_input;
	int slots_size = -1;
	int zeros;
	int visits;
	int dollars;
	std::vector<int> slots;
	

	slots_size = size_prompt(2, 200, "How many slots there will be in your roulette wheel?\nthis must be an integer between 2 and 200, inclusive");
	zeros = size_prompt(0, 2, "How many of the slots will be labeled with 0 or 00?\nthis must be an integer 0-2, inclusive");
	visits = size_prompt(1, 100000, "How many times do you want to visit the casino,\n an integer 1-100,000, inclusive");
	dollars = size_prompt(1, 1000000, "How many dollars you want to start with each time\n you visit the casino 1-1,000,000 inclusive");

	 
	 

}