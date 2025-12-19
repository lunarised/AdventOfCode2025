#include "day04.h"
#include <vector>
#include <string>
#include <iostream>
using namespace std;



int64_t day04A( vector<string> input) {

    size_t rows = input.size();
    size_t cols = input.front().length();
    vector<vector<int64_t>> grid(rows, vector<int64_t>(cols, 0)); // Dynamically allocated 2D grid

   // int64_t grid[input.size()][input.front().length()];
    int64_t lineCounter = 0;
    int64_t lineLength = input.front().length();
    for(string line : input) {
        for(size_t i = 0; i < line.length(); i++) {
            grid[lineCounter][i] = line[i] == '@' ? 1 : 0;
        }
        lineCounter++;
    }

    int64_t tpCounter = 0;
    for(int row = 0; row < input.size(); row++) {
        for (int column = 0; column < lineLength; column++) {
            int64_t count = 0;
            if(column > 0){
                if(row > 0){
                    count+=grid[row-1][column-1];//Top Left
                }
                count+=grid[row][column-1]; //Left
                if(row < input.size() - 1){
                    count+=grid[row+1][column-1]; //Bottom Left
                }
            }

            if (row > 0){
                count+=grid[row-1][column]; //Top

            }
            if (row < input.size() - 1){
                count+=grid[row+1][column]; //Bottom
            }

            if(column < lineLength - 1){
                if(row > 0){
                    count+=grid[row-1][column+1]; //Top Right
                }
                count+=grid[row][column+1];  // Right
                if(row < input.size() - 1){
                    count+=grid[row+1][column+1];  //Bottom Right
                }
            }

            if (count < 4 && grid[row][column] == 1){
                tpCounter++;
            }
        }
    }
    return tpCounter;
}

int64_t day04B( vector<string> input) {
    size_t rows = input.size();
    size_t cols = input.front().length();
    vector<vector<int64_t>> grid(rows, vector<int64_t>(cols, 0)); // Dynamically allocated 2D grid

    int64_t lineCounter = 0;
    int64_t lineLength = input.front().length();
    for(string line : input) {
        for(size_t i = 0; i < line.length(); i++) {
            grid[lineCounter][i] = line[i] == '@' ? 1 : 0;
        }
        lineCounter++;
    }
    int64_t tpRun = -1;

    int64_t tpCounter = 0;
    vector<vector<int64_t>> successGrid(rows, vector<int64_t>(cols, 0)); // Dynamically allocated 2D grid
    while(tpRun != 0){
    tpRun = 0;
    for(int row = 0; row < input.size(); row++) {
        for (int column = 0; column < lineLength; column++) {
            int64_t count = 0;
            if(column > 0){
                if(row > 0){
                    count+=grid[row-1][column-1];//Top Left
                }
                count+=grid[row][column-1]; //Left
                if(row < input.size() - 1){
                    count+=grid[row+1][column-1]; //Bottom Left
                }
            }
            if (row > 0){
                count+=grid[row-1][column]; //Top

            }
            if (row < input.size() - 1){
                count+=grid[row+1][column]; //Bottom
            }
            if(column < lineLength - 1){
                if(row > 0){
                    count+=grid[row-1][column+1]; //Top Right
                }
                count+=grid[row][column+1];  // Right
                if(row < input.size() - 1){
                    count+=grid[row+1][column+1];  //Bottom Right
                }
            }
            if (count < 4 && grid[row][column] == 1){
                tpRun++;
                successGrid[row][column] = 0;
            }
            else{
                successGrid[row][column] = grid[row][column];
            }
        }
    }
    for(int row = 0; row < input.size(); row++) {
        for (int column = 0; column < lineLength; column++) {
            grid[row][column] = successGrid[row][column];
        }
    }
    tpCounter+=tpRun;
}
    return tpCounter;
}