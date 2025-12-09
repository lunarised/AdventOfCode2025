#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "day01.h"

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
	vector<string> day1Input = readPuzzleInput("input01.txt");
	cout << "Day 01A: " << day01A(day1Input) << endl;
	cout << "Day 01B: " << day01B(day1Input) << endl;
	return 0;
}

