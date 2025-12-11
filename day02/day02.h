#pragma once

#include <vector>
#include <string>

struct range {
	int64_t upper;
	int64_t lower;
};
std::vector<range> parseRanges(std::vector<std::string> input);
int64_t day02A(std::vector<range> input);