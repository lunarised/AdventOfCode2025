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

			range a;
			a.upper = upper;
			a.lower = lower;

			puzzleInputs.push_back(a);
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
	return sumOfInvalidIDs;
}

bool checkRepeats(int64_t id, size_t run) {
	string stringID = std::to_string(id);
	size_t nRepeats = stringID.length() / run;
	string pattern = stringID.substr(0, run);
	for (size_t repeat = 1; repeat < nRepeats; repeat++) {
		if (stringID.substr(repeat * run, run) != pattern) {
			return false;
		}
	}
	return true;
}

int64_t day02B(vector<range> input) {
	int64_t sumOfInvalidIDs = 0;
	for (range r : input) {
		for (int64_t id = r.lower; id <= r.upper; id++) {
			size_t idLength = std::to_string(id).length();
			for (size_t run = 1; run <= idLength / 2; run++) {
				
				if (idLength % run == 0) {
					if (checkRepeats(id, run)) {
						sumOfInvalidIDs += id;
						break;
					}
				}
			}
		}
	}
	return sumOfInvalidIDs;
}

