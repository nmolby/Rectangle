//
//  Rectangle.hpp
//  Lab1Rectangle
//
//  Created by David M Reed on 11/20/19.
//  Copyright © 2019 David M Reed. All rights reserved.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <iostream>

#include "graphics.hpp"

class Rectangle {
public:
    Rectangle(int x1, int y1, int x2, int y2, int r, int g, int b);
    int blX, blY, trX, trY, r, g, b;
    
    void Draw(Renderer& renderer);

};

#endif /* Rectangle_hpp */
