//
//  Rectangle.cpp
//  Lab1Rectangle
//
//  Created by Nathan Molby on 1/21/20.
//  Copyright © 2020 Nathan Molby All rights reserved.
//

#include "Rectangle.hpp"



///Constructs a rectangle with two points and r g b values
Rectangle::Rectangle(int x1, int y1, int x2, int y2, int r, int g, int b) {
    this->blX = x1 > x2 ? x2 : x1;
    this->trX = x1 > x2 ? x1 : x2;
    this->blY = y1 > y2 ? y2 : y1;
    this->trY = y1 > y2 ? y1 : y2;
    this->r = r;
    this->g = g;
    this->b = b;
    
}

///draws the rectangle into the renderer that is passed
void Rectangle::Draw(Renderer& renderer) {
    std::vector<Point3D> pts;

    //add every point in between bottom left point and top right point to pts vector
    for(int currentX = blX; currentX <= trX; currentX++){
        for(int currentY = blY; currentY <= trY; currentY++){
            pts.push_back(Point3D(currentX, currentY));
        }
    }
    
    //draw these points to the renderer with the desired color
    renderer.addPoints(pts, Color(r, g, b));
}
