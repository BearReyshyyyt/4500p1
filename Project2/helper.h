#pragma once
#include <string>
#include <vector>


bool valid_size(std::string input, int min, int max);
bool martingale(long long &money, std::vector<std::string> wheel);
bool random_strat(long long &money, std::vector<std::string> wheel); \
bool fixed_strat(long long &money, long long bet, std::vector<std::string> wheel);
int size_prompt(int min, int max, std::string prompt);
bool is_int(std::string myString);
void populate_wheel(std::vector<std::string> &wheel, int slots, int zeros = 0);
long long max(long long x, long long y);