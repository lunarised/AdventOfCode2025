#pragma once
#include <string>
#include <vector>
struct day05Range {
	int64_t low;
	int64_t high;
};
using std::vector;
using std::string;
void extendOrAddRange(day05Range newRange, vector<day05Range> ranges);
int isInRange(int64_t ingredient, const vector<day05Range> ranges);
int64_t day05A(const vector<string> input);
int64_t day05B(const vector<string> input); 