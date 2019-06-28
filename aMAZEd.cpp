//
// Created by Gang-Ryung Uh
//
// Student project source code template
//       for aMazed programming assignment
//
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <random>
#include "maze.h"

using namespace std;


// 2 Function Prototypes - you are only required to
//     define (implement) the following 2 functions
//
void readMaze(ifstream &fin, int states[][MAX_GRID_COL],
               int rows, int cols, int &startRow, int &startCol,
               int &exitRow, int &exitCol);
void solveMaze(Maze &maze, int states[][MAX_GRID_COL],int rows, int cols,
               int startRow, int startCol, int exitRow, int exitCol);

// main entry for aMazed application
int main(int argc, char *argv[]) {

    int rows, cols;
    int states[MAX_GRID_ROW][MAX_GRID_COL]; // maze state
    int startRow;          // row of starting position
    int startCol;          // column of starting position
    int exitRow;           // row of exit position
    int exitCol;           // column of exit position

    startRow = startCol = exitRow = exitCol = -1;

    // Get the maze filename and open the file.
    cout << "Enter the maze data filename: " << flush;
    string Filename;
    cin >> Filename;
    ifstream fin(Filename.c_str());

    // Read the number of rows and cols.
    fin >> rows;
    fin >> cols;

    if (rows >= MAX_GRID_ROW || cols >= MAX_GRID_ROW) {
        cerr << "Invalid grid size" << endl;
        exit(EXIT_FAILURE);
    }

    // Read maze configuration from the input file stream object
    readMaze(fin, states, rows, cols, startRow, startCol, exitRow, exitCol);
    fin.close();

    sf::RenderWindow window(sf::VideoMode(600, 800), "I am aMAZEd!!");
    float width = (window.getSize().x * 1.0) / cols;
    float height = (window.getSize().y * 1.0) / rows;
    Maze maze(rows, cols, width, height, states);
    maze.createMaze();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::KeyPressed:
                    if (event.key.code == sf::Keyboard::Escape)
                        solveMaze(maze, states, rows, cols, startRow,
                              startCol, exitRow, exitCol);
                    break;
                default:
                    window.clear();
                    window.draw(maze);
                    window.display();
                    break;
            }
        }
    }
    return 0;
}

//
// YOU NEED TO IMPLEMENT THIS FUNCTION
//    processing the input file stream fin and initialize,
//          startRow, startCol
//          exitRow, exitCol
//          2 dimensional states[][] arrays
//
void readMaze(ifstream &fin, int states[][MAX_GRID_COL],
              int rows, int cols, int &startRow, int &startCol,
              int &exitRow, int &exitCol)
{
    // Initialize the starting and exit points.
    startRow = -1;
    startCol = -1;
    exitRow = -1;
    exitCol = -1;

    // read in the characters of the maze
    char c;
    fin.get(c);

    cout << "***YOU NEED TO IMPLEMENT readMaze function***" << endl;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
        }
    }
}

//
//  YOU NEED TO IMPLEMENT THIS FUNCTION
//  Using the states[][] array, find the path from (startRow, startCol)
//                                              to (exitRow, exitCol)
//  While finding the path, update the maze color by invoking
//  maze.updateMazeCellColorCellColor() routine
//
void solveMaze(Maze &maze, int states[][MAX_GRID_COL],int rows, int cols,
               int startRow, int startCol, int exitRow, int exitCol) {
    int steps = 1;
    states[startRow][startCol] = steps;
    states[exitRow][exitCol] = SPACE;
    int row = startRow;
    int col = startCol;

    cout << "***YOU NEED TO IMPLEMENT solveMaze function**!" << endl;

    // restore start and exit value
    states[startRow][startCol] = START_M;
    states[exitRow][exitCol] = EXIT_M;
    maze.updateMazeCellColor(exitRow,exitCol,EXIT_M);
    return;
}


