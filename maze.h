//
// Created by Gang-Ryung Uh for aMazed programming assignment
//
// DON'T CHANGE THE CODE
//

#ifndef GUI_MAZE_GRID_H
#define GUI_MAZE_GRID_H
#include "cell.h"
#include <SFML/Graphics.hpp>

// global constants for maze project
const int MAX_GRID_ROW = 50;
const int MAX_GRID_COL = 50;
const int START_M =  -2;
const int EXIT_M  =  -3;
const int SPACE =  0;
const int WALL  = -1;
const int TRIED = -4;

class Maze: public sf::Drawable {
public:
    Maze(){};
    Maze(int r, int c, float sizeX, float sizeY, int state[][MAX_GRID_COL]):
            row(r),col(c),cellSizeX(sizeX), cellSizeY(sizeY) {
        for (int i = 0; i < row; ++i)
            for (int j = 0; j < col; ++j)
                gridStates[i][j] = state[i][j];
    };

    ~Maze() {};
    void createMaze();

    std::vector<sf::RectangleShape> sfmlMaze;
    void updateMazeCellColor(int r, int c, int state);

private:
    int row, col;
    float cellSizeX, cellSizeY;
    int gridStates[MAX_GRID_ROW][MAX_GRID_COL];
    Cell  grid;   // Rectangle grid

    void createSFMLMaze(std::vector<std::vector<int> >& matrix);
    void genMaze(std::vector<std::vector<int> >& matrix, int x, int y);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif //GUI_MAZE_GRID_H
