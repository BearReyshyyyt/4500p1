#include "helper.h"
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

int main()
{
	srand((unsigned)time(0));

	std::string temp_input;
	int slots_size = -1;
	int zeros;
	long long visits;
	long long dollars;
	int strategy;
	std::vector<std::string> slots;
	bool winning = false;

	// calculated variables
	long long total_walkaway = 0;
	int most_dollars_won = 0;
	int bankrupt_count = 0;
	int total_change = 0;
	int profit_count = 0;

	

	slots_size = size_prompt(2, 200, "How many slots there will be in your roulette wheel?\nthis must be an integer between 2 and 200, inclusive");
	zeros = size_prompt(0, 2, "How many of the slots will be labeled with 0 or 00?\nthis must be an integer 0-2, inclusive");
	visits = size_prompt(1, 100000, "How many times do you want to visit the casino,\n an integer 1-100,000, inclusive");
	dollars = size_prompt(1, 1000000, "How many dollars you want to start with each time\n you visit the casino 1-1,000,000 inclusive");
	
	std::cout << "here are three strategies for betting:" << std::endl;

	std::cout << "	1- you will start by betting $1. If you win your bet, you quit and go home happy. (Not that happy,\n";
	std::cout << "		for reasons that will be obvious after you watch the video.) If you lose, you double the bet and\n";
	std::cout << "		go again. You continue that process until you either run out of money (and your visit is over),\n";
	std::cout << "		or you win, and you voluntarily quit, slightly ahead.\n";

	std::cout << "  2- A random strategy: each time you bet, you bet a random amount from $1 to all the money you have.\n";
	std::cout << "		Each time you bet, each of the possible bets should be equally likely when you pick the amount to.\n";
	std::cout << "		You finish with this strategy when you either run out of money, or you have bet 50 times,\n";
	std::cout << "		whichever comes first.\n";

	std::cout << "	3- A fixed bet strategy: each time you bet, you bet a fixed amount, from $1 to the amount of money you\n";
	std::cout << "		start with.If the user picks this strategy, you have to also get that fixed amount from the user.\n";
	std::cout << "		You finish with this strategy when you either run out of money(that is, your money dips below the\n";
	std::cout << "		bet size), or you have bet 50 times.\n";
	
	strategy = size_prompt(1, 3, "Now please choose one of the three strategies by entering a number 1-3");

	populate_wheel(slots, slots_size, zeros);

	if (strategy == 1)
	{
		for (int i = 0; i < visits; i++)
		{
			long long balance = dollars;
			winning = martingale(balance, slots);
			total_walkaway += balance;
			most_dollars_won = max(most_dollars_won, balance - dollars);
			total_change += (balance - dollars);

			if (!balance)
				bankrupt_count++;

			if (balance > dollars)
				profit_count++;
		}	
	}
	else if (strategy == 2)
	{
		for (int i = 0; i < visits; i++)
		{
			long long balance = dollars;
			winning = random_strat(balance, slots);
			total_walkaway += balance;
			most_dollars_won = max(most_dollars_won, balance - dollars);
			total_change += (balance - dollars);

			if (!balance)
				bankrupt_count++;

			if (balance > dollars)
				profit_count++;
		}
	}
	else if (strategy == 3)
	{
		std::string str_money = std::to_string(dollars);
		std::string prompt = "please enter a dollar value between 1 and " + str_money;
		long long bet = size_prompt(1, dollars, prompt);

		for (int i = 0; i < visits; i++)
		{
			long long balance = dollars;
			winning = fixed_strat(balance, bet, slots);
			total_walkaway += balance;
			most_dollars_won = max(most_dollars_won, balance - dollars);
			total_change += (balance - dollars);

			if (!balance)
				bankrupt_count++;

			if (balance > dollars)
				profit_count++;
		}
	}

	

	std::cout << "Total number of slots on wheel: " << slots_size << std::endl;
	std::cout << "Total number of zero slots: " << zeros << std::endl;
	std::cout << "Total visits to the casino: " << visits << std::endl;
	std::cout << "Total dollars at the start of each visit: " << dollars << std::endl;
	std::cout << "Total dollars put at rick of all visits combined: " << dollars * visits << std::endl;
	std::cout << "Total dollars walked away with over all visits: " << total_walkaway << std::endl;
	std::cout << "The most dollars ever won out of all visits is: " << most_dollars_won << std::endl;
	std::cout << "The total amount of times you went bankrupt is: " << bankrupt_count << std::endl;
	std::cout << "On average the change in your dollar amount is: " << total_change / (double)visits << std::endl;
	std::cout << "the total amount of time you made a profit is: " << profit_count << std::endl;


}