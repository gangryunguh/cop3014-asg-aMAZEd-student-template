#include <SFML/Graphics.hpp>
#include "maze.h"
#include <iostream>

void Maze::createSFMLMaze(std::vector<std::vector<int> > &matrix) {
    int r = matrix.size();
    int c = matrix[0].size();

    std::cout << "row: " << r << std::endl;
    std::cout << "col: " << c << std::endl;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[0].size(); j++) {
            sf::Color color;
            switch (gridStates[i][j]) {
                case SPACE:
                    color = sf::Color(100,150,200);
                    break;
                case WALL:
                    color = sf::Color::Black;
                    break;
                case TRIED:
                    color = sf::Color(125,125,0);
                    break;
                case START_M:
                    color = sf::Color(200,200,0);
                    break;
                case EXIT_M:
                    color = sf::Color(255,255,0);
                    break;
                default:
                    color = sf::Color(255,0,0); // default RED color
                    break;
            }
            grid.addCell(cellSizeX, cellSizeY, cellSizeX * j, cellSizeY * i, color);
        }
    }
}

void Maze::updateMazeCellColor(int r, int c, int state) {
    switch (state) {
        case TRIED:
            sfmlMaze[r*col+c].setFillColor(sf::Color(125,125,125));
            break;
        case SPACE:
            sfmlMaze[r*col+c].setFillColor(sf::Color(100,150,200));
            break;
        case START_M:
            sfmlMaze[r*col+c].setFillColor(sf::Color(200,200,0));
            break;
        case EXIT_M:
            sfmlMaze[r*col+c].setFillColor(sf::Color(255,255,0));
            break;
        default:
            if (state > SPACE)
                sfmlMaze[r*col+c].setFillColor(sf::Color(0,255,0));
            break;
    }
}

void Maze::genMaze(std::vector<std::vector<int> > &matrix, int r, int c) {
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) {
            // TODO: this needs to be set randomly
            matrix[i][j] = 1;
        }
}

void Maze::createMaze() {
    std::vector<std::vector<int> > matrix(row, std::vector<int>(col));
    genMaze(matrix,0,0);   // generate maze starting from uppper
    createSFMLMaze(matrix);
    sfmlMaze = grid.getContainer();
}

void Maze::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    for (int i = 0; i < sfmlMaze.size(); i++)
        target.draw(sfmlMaze[i]);
}
