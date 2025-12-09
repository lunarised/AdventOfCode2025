#include "day01.h"

#include <vector>
#include <string>

using std::vector;
using std::string;

int day01A(vector<string> input) {
	int position = 50;
	int zeroLands = 0;
	for (string data : input) {
		int direction = data[0] == 'R' ? 1 : -1;
		int distance = stoi(data.substr(1));
		position += direction * distance;
		position %= 100;
		if (position == 0) {
			zeroLands++;
		}
	}
	return zeroLands;
}

int day01B(vector<string> input) {
	int position = 50;

	int zeroPasses = 0;
	for (string data : input) {
		int startingPosition = position;
		int direction = data[0] == 'R' ? 1 : -1;
		int distance = stoi(data.substr(1));
		int fullTurns = distance / 100;
		zeroPasses += fullTurns;

		int change = direction * (distance % 100);
		position += change;


		if (distance % 100 == 0) continue;


		if (direction == 1 && (position) > 99) {
			zeroPasses++;
			position = position % 100;
		}
		if (direction == -1 && startingPosition == 0) {
			position = (position + 100) % 100;
		}
		else if (direction == -1 && (position) <= 0) {
			zeroPasses++;
			position = (position + 100) % 100;
		}
	}
	return zeroPasses;
}