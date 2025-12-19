#include <vector>
#include <string>
#include "day05.h"
#include <set>
#include <iostream>
using std::vector;
using std::string;
using std::set;
#include <algorithm>
#include <limits>

void extendOrAddRange(day05Range newRange, vector<day05Range> ranges){
    bool hasExtendedRange = false;
    for (day05Range r : ranges){
        //Extend to the bottom
        if(r.low < newRange.high && newRange.low < r.low){
            r.low = newRange.low;
            hasExtendedRange = true;
        }
        //extend the top
        if (r.high > newRange.low && newRange.high > r.high){
            r.high = newRange.high;
            hasExtendedRange = true;
        }
    }
    if (!hasExtendedRange){
        ranges.push_back(newRange);
    }
}

int isInRange(int64_t ingredient, vector<day05Range> ranges){
    for (day05Range r : ranges){
        if(ingredient >= r.low && ingredient <= r.high){
            return 1;
        }
    }
    return 0;
}


vector<day05Range> collapseRanges(vector<day05Range> oldRanges) {
    vector<day05Range> collapsedRanges;
	collapsedRanges.push_back(oldRanges[0]);
	for (size_t i = 1; i < oldRanges.size(); i++) {
		if (oldRanges[i].low <= collapsedRanges.back().high + 1) {
			collapsedRanges.back().high = std::max(collapsedRanges.back().high, oldRanges[i].high);
		}
		else {
			collapsedRanges.push_back(oldRanges[i]);
		}	
	}
	return collapsedRanges;
}

int64_t day05A(vector<string> input){
    vector<day05Range> ranges;
    vector<int64_t> ingredients;
    int64_t nFresh = 0;
    for (string value : input){
    int hyphenPos = value.find('-');
    if (hyphenPos == std::string::npos) {
        if (value.length() == 0) continue;
        ingredients.push_back(stoll(value));
    }
    else{
        day05Range newRange;
        newRange.low = stoll(value.substr(0, hyphenPos));
        newRange.high = stoll(value.substr(hyphenPos + 1));
        ranges.push_back(newRange);
    }
    }

    for (int64_t ingredient : ingredients){
        nFresh += isInRange(ingredient, ranges);
    }

    return nFresh;
}




void extendOrAddRange(day05Range newRange, vector<day05Range> ranges) {
    bool hasExtendedRange = false;
    for (day05Range r : ranges) {
        //Extend to the bottom
        if (r.low < newRange.high && newRange.low < r.low) {
            r.low = newRange.low;
            hasExtendedRange = true;
        }
        //extend the top
        if (r.high > newRange.low && newRange.high > r.high) {
            r.high = newRange.high;
            hasExtendedRange = true;
        }
    }
    if (!hasExtendedRange) {
        ranges.push_back(newRange);
    }
}
vector<day05Range> collapseRanges(vector<day05Range> oldRanges) {
    vector<day05Range> collapsedRanges;
    collapsedRanges.push_back(oldRanges[0]);
    for (size_t i = 1; i < oldRanges.size(); i++) {
        if (oldRanges[i].low <= collapsedRanges.back().high + 1) {
            collapsedRanges.back().high = std::max(collapsedRanges.back().high, oldRanges[i].high);
        }
        else {
            collapsedRanges.push_back(oldRanges[i]);
        }
    }
    return collapsedRanges;
}
int64_t day05B(vector<string> input) {
    vector<day05Range> ranges;
    vector<int64_t> ingredients;
	int64_t freshIDs =  0;
    int64_t nFresh = 0;
    for (string value : input) {
        int hyphenPos = value.find('-');
        if (hyphenPos == std::string::npos) {
            if (value.length() == 0) continue;
            ingredients.push_back(stoll(value));
        }
        else {
            day05Range newRange;
            newRange.low = stoll(value.substr(0, hyphenPos));
            newRange.high = stoll(value.substr(hyphenPos + 1));
            ranges.push_back(newRange);
        }
    }
    std::sort(ranges.begin(), ranges.end(), [](const day05Range& a, const day05Range& b) {
        return a.low < b.low;
        });

    vector<day05Range> collRanges = collapseRanges(ranges);


	for (day05Range r : collRanges) {
		freshIDs += (r.high - r.low + 1);
	}
    return freshIDs;
}