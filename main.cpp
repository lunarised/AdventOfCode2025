#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "day01/day01.h"
#include "day02/day02.h"

using std::string;
using std::vector;

using std::endl;
using std::cout;
using std::ifstream;


vector<string> readPuzzleInput(string fileName) {
	vector<string> data;
	ifstream inputFile(fileName);
	string line;
	while (getline(inputFile, line)) {
		data.push_back(line);
	}
	return data;
}

int main() {
	vector<string> day1Input = readPuzzleInput("day01/input01.txt");
	cout << "Day 01A: " << day01A(day1Input) << endl;
	cout << "Day 01B: " << day01B(day1Input) << endl;

	vector<range> day2Input = parseRanges(readPuzzleInput("day02/input02.txt"));
	cout << "Day 02A: " << day02A(day2Input) << endl;
	cout << "Day 02B: " << day02B(day2Input) << endl;
	return 0;
}

