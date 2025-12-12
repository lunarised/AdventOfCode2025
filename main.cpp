#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "day01/day01.h"
#include "day02/day02.h"
#include "day03/day03.h"
#include "day04/day04.h"

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
	std::chrono::steady_clock::time_point startTime;
	std::chrono::steady_clock::time_point endTime;
	startTime = std::chrono::steady_clock::now();
	cout << "Day 01A: " << day01A(day1Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;

	startTime = std::chrono::steady_clock::now();
	cout << "Day 01B: " << day01B(day1Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;


	vector<range> day2Input = parseRanges(readPuzzleInput("day02/input02.txt"));
	startTime = std::chrono::steady_clock::now();
	cout << "Day 02A: " << day02A(day2Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;

	startTime = std::chrono::steady_clock::now();
	cout << "Day 02B: " << day02B(day2Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;

	vector<string> day3Input = readPuzzleInput("day03/input03.txt");
	startTime = std::chrono::steady_clock::now();
	cout << "Day 03A: " << day03A(day3Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;

	startTime = std::chrono::steady_clock::now();
	cout << "Day 03B: " << day03B(day3Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;


	vector<string> day4Input = readPuzzleInput("day04/input04.txt");
	startTime = std::chrono::steady_clock::now();
	cout << "Day 04A: " << day04A(day4Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;

		startTime = std::chrono::steady_clock::now();
	cout << "Day 04A: " << day04B(day4Input);
	endTime = std::chrono::steady_clock::now();
	cout << " (Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime).count() << " ms)" << endl;
	return 0;
}

