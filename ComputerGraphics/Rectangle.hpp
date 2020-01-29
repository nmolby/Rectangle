//
//  Rectangle.hpp
//  Lab1Rectangle
//
//  Created by David M Reed on 11/20/19.
//  Additional features added by Nathan Molby on 1/27/20
//  Copyright © 2019 David M Reed. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <iostream>

#include "graphics.hpp"

class MyRectangle {
public:
    /// create Rectangle with specified values
    /// @param x1 x-coordinate of one corner of Rectangle
    /// @param y1 y-coordinate of one corner of Rectangle
    /// @param x2 x-coordinate of diagonally opposite corner of Rectangle
    /// @param y2 y-coordinate of diagonally opposite corner of Rectangle
    /// @param color color for Rectangle
    /// @param scaleX x scale factor for Rectangle
    /// @param scaleY y scale factor for Rectangle
    /// @param translateX x translation for Rectangle
    /// @param translateY y translation for Rectangle
    /// @param rotateDeg degrees of rotation for Rectangle
    MyRectangle(const int x1 = 0, const int y1 = 0, const int x2 = 0, const int y2 = 0, const Color &color = Color(0, 0, 0),
                const float scaleX = 0, const float scaleY  = 0, const float translateX = 0, const float translateY = 0, const float rotateDeg = 0);

    /// set Rectangle to specified values
    /// @param x1 x-coordinate of one corner of Rectangle
    /// @param y1 y-coordinate of one corner of Rectangle
    /// @param x2 x-coordinate of diagonally opposite corner of Rectangle
    /// @param y2 y-coordinate of diagonally opposite corner of Rectangle
    /// @param color color for Rectangle
    /// @param scaleX x scale factor for Rectangle
    /// @param scaleY y scale factor for Rectangle
    /// @param translateX x translation for Rectangle
    /// @param translateY y translation for Rectangle
    /// @param rotateDeg degrees of rotation for Rectangle
    void set(const int x1, const int y1, const int x2, const int y2, const Color &color,
             const float scaleX = 0, const float scaleY  = 0, const float translateX = 0,
             const float translateY = 0, const float rotateDeg = 0);

    /// sets Rectangle up to be drawn as a filled Rectangle for its coordinate and color
    /// @param renderer the Renderer to use to draw the Rectangle
    void render(Renderer *renderer);

    /// returns lower left corner of Rectangle
    Point3D lowerLeft() const { return _lowerLeft; }

    /// returns upper right corner of Rectangle
    Point3D upperRight() const { return _upperRight; }

    /// returns center point of Rectangle
    Point3D centerPoint() const;

private:
    size_t _renderID;
    Point3D _lowerLeft, _upperRight;
    float scaleX, scaleY, translateX, translateY, rotateDeg;
    Color _color;
};

inline Point3D MyRectangle::centerPoint() const {
    float x1 = _lowerLeft.x;
    float y1 = _lowerLeft.y;
    float z1 = _lowerLeft.z;
    float x2 = _upperRight.x;
    float y2 = _upperRight.y;
    float z2 = _upperRight.z;
    // center point is average of two corners
    return Point3D((x1 + x2) / 2.0, (y1 + y2) / 2.0, (z1 + z2) / 2.0);
}

/// input operator for Rectangle
/// @param is input stream
/// @param rectangle rectangle store data from stream in
std::istream& operator>>(std::istream &is, MyRectangle &rectangle);

#endif /* Rectangle_hpp */
