//
//  Rectangle.cpp
//  Lab1Rectangle
//
//  Created by David M Reed on 11/20/19.
//  Additional features added by Nathan Molby on 1/27/20
//  Copyright © 2019 David M Reed. All rights reserved.
//

#include "Rectangle.hpp"

MyRectangle::MyRectangle(const int x1, const int y1, const int x2, const int y2, const Color &color,
                         const float scaleX, const float scaleY, const float translateX, const float translateY, const float rotateDeg) {
    set(x1, y1, x2, y2, color, scaleX, scaleY, translateX, translateY, rotateDeg);
}

void MyRectangle::set(const int x1, const int y1, const int x2, const int y2, const Color &color,
                      const float scaleX, const float scaleY, const float translateX, const float translateY, const float rotateDeg) {
    _lowerLeft = Point3D(x1, y1, 0.0);
    _upperRight = Point3D(x2, y2, 0.0);
    if (x2 < x1) {
        _lowerLeft.x = x2;
        _upperRight.x = x1;
    }
    if (y2 < y1) {
        _lowerLeft.y = y2;
        _upperRight.y = y1;
    }
    _color = color;
    this->scaleX = scaleX;
    this->scaleY = scaleY;
    this->translateX = translateX;
    this->translateY = translateY;
    this->rotateDeg = rotateDeg;
}

void MyRectangle::render(Renderer *renderer) {
    
    mat3 transtoOrig = mat3(1, 0, -1 * centerPoint().x,
                            0, 1, -1 * centerPoint().y,
                            0, 0, 1);
    
    mat3 scale = mat3(scaleX, 0, 0,
                      0, scaleY, 0,
                      0, 0, 1);
    
    mat3 rot = mat3(cos(DegreesToRadians * rotateDeg), -1*sin(DegreesToRadians * rotateDeg), 0,
                    sin(DegreesToRadians * rotateDeg), cos(DegreesToRadians * rotateDeg), 0,
                    0, 0, 1);
    
    mat3 transFromUser = mat3(1, 0, translateX,
                      0, 1, translateY,
                      0, 0, 1);
    
    mat3 transBack = mat3(1, 0, centerPoint().x,
                            0, 1, centerPoint().y,
                            0, 0, 1);
    
    mat3 finalTrans = transBack * transFromUser * rot * scale * transtoOrig;
    
    std::cout << transtoOrig << std::endl << scale << std::endl << rot << std::endl << transFromUser << std::endl << transBack;
    
    
    std::vector<Point3D> pts;
    for (int y =_lowerLeft.y; y <= _upperRight.y; ++y) {
        for (int x = _lowerLeft.x; x <= _upperRight.x; ++x) {
            vec3 initialPoint = vec3(x, y, 1);
            vec3 finalPoint = finalTrans * initialPoint;
            
            
            pts.push_back(Point3D(float(finalPoint[0]), float(finalPoint[1]), 0.0));
        }
    }
    _renderID = renderer->addPoints(pts, _color);
}


std::istream& operator>>(std::istream &is, MyRectangle &rectangle) {
    float x1, y1, x2, y2, r, g, b, xScale, yScale, xTranslate, yTranslate, rotateAmount;

    is >> x1 >> y1 >> x2 >> y2 >> r >> g >> b >> xScale >> yScale >> xTranslate >> yTranslate >> rotateAmount;
    Color color(r, g, b);
    rectangle.set(x1, y1, x2, y2, color, xScale, yScale, xTranslate, yTranslate, rotateAmount);
    return is;
}
