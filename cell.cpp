//
// Created by Gang-Ryung Uh for aMazed programming assignment
//

#include "cell.h"

Cell::Cell() {
    // nothing
}

void Cell::addCell(float size_x, float size_y, float pos_x, float pos_y, sf::Color color)
{
    curCell.setSize(sf::Vector2f(size_x,size_y));
    curCell.setFillColor(color);
    curCell.setOutlineColor(sf::Color::White);
    curCell.setOutlineThickness(-1);
    curCell.setPosition(sf::Vector2f(pos_x,pos_y));
    cellContainer.push_back(curCell);
}

void Cell::draw(sf::RenderTarget &target, sf::RenderStates) const
{
    for (int i = 0; i < cellContainer.size(); i++)
        target.draw(cellContainer[i]);
}