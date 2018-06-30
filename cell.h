//
// Created by Gang-Ryung Uh for aMazed programming assignment.
//

#ifndef GUI_MAZE_CELL_H
#define GUI_MAZE_CELL_H
#include <SFML/Graphics.hpp>

class Cell: public sf::Drawable
{
public:
    Cell();
    sf::FloatRect getCell(sf::RectangleShape rect) const;
    void addCell(float size_x, float size_y, float pos_x, float pos_y, sf::Color color);
    std::vector<sf::RectangleShape> getContainer() {
        return cellContainer;
    };
private:
    sf::RectangleShape curCell;
    std::vector<sf::RectangleShape> cellContainer;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};
#endif //GUI_MAZE_CELL_H
