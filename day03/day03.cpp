#include "day03.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using std::vector;
using std::string;
using std::stringstream;
using std::endl;
using std::count;


using namespace std;

struct notableJoltage {
	int64_t joltage;
	int64_t index;
};

notableJoltage findBiggestNumber(string numberString, int excludeLastN) {
	notableJoltage result;
	result.joltage = -1;
	result.index = -1;
	size_t maxNumberToCheck = numberString.length() - excludeLastN;
	for (size_t i = 0; i < maxNumberToCheck; i++) {
		int64_t currentNumber = numberString[i] - '0';
		if (currentNumber > result.joltage) {
			result.joltage = currentNumber;
			result.index = i;
		}
	}
	return result;
}

int64_t day03A(vector<string> input) {
	int64_t maxJoltage = 0;
	for (string row: input) {
		notableJoltage biggestJoltage = findBiggestNumber(row, 1);
		notableJoltage secondJoltage = findBiggestNumber(row.substr(biggestJoltage.index+1), 0);
		int64_t maximumRowJoltage = (biggestJoltage.joltage*10) + secondJoltage.joltage;
		maxJoltage += maximumRowJoltage;
	}
	return maxJoltage;
}

int64_t day03B(vector<string> input) {
	int64_t maxJoltage = 0;

	for (string row : input) {
		int64_t startIndex = 0;
		int64_t runningJoltage = 0;
		for (int64_t i = 11; i >= 0; i--) {
			notableJoltage biggestJoltage = findBiggestNumber(row.substr(startIndex), i);
			runningJoltage = (runningJoltage * 10) + biggestJoltage.joltage;
			startIndex = startIndex + biggestJoltage.index + 1;
		}
		maxJoltage += runningJoltage;
	}
	return maxJoltage;
}