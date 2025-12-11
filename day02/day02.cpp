#include "day02.h"

#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <chrono>
using std::vector;
using std::string;
using std::stringstream;
using std::endl;
using std::count;


using namespace std;


vector<range> parseRanges(vector<string> input) {
		vector<range> puzzleInputs;
	for (string _ : input) {
		stringstream individualInputs(_);
		string word;
		while (getline(individualInputs, word, ',')) {

			stringstream idRange(word);
			string lowerString;
			string upperString;

			getline(idRange, lowerString, '-');
			getline(idRange, upperString);


			int64_t lower = stoll(lowerString);
			int64_t upper = stoll(upperString);

			range range;
			range.upper = upper;
			range.lower = lower;

			puzzleInputs.push_back(range);
		}
	}
	return puzzleInputs;
}
int64_t day02A(vector<range> input) {
	auto t1 = std::chrono::high_resolution_clock::now();
	int64_t sumOfInvalidIDs = 0;
	for (range r : input) {
		for (int64_t id = r.lower; id <= r.upper; id++) {
			string stringID = std::to_string(id);
			if (stringID.substr(0, stringID.length() / 2) == stringID.substr(stringID.length() / 2)) {
				sumOfInvalidIDs += id;
			}

		}
	}
	auto t2 = std::chrono::high_resolution_clock::now();
	auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	cout << "Day 02A took " << ms_int.count() << " milliseconds" << endl;
	return sumOfInvalidIDs;
}