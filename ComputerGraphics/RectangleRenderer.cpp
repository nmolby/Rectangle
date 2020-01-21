//
//  RectangleRenderer.cpp
//  Lab1Rectangle
//
//  Created by Nathan Molby on 1/21/20.
//  Copyright © 2020 Nathan Molby All rights reserved.
//

#include <fstream>
#include "Rectangle.hpp"
#include "RectangleRenderer.hpp"

RectangleRenderer::RectangleRenderer(GLFWwindow *window, std::string filename) : Renderer(window) {
    std::ifstream infile(filename);
    
    
    int x1, y1, x2, y2, r, g, b;
    
    //reads line by line splitting on spaces into the 7 local variables
    while(infile >> x1 >> y1 >> x2 >> y2 >> r >> g >> b){
        
        //constructs a new rectangle with these variables and then draw it
        Rectangle x(x1, y1, x2, y2, r, g, b);
        x.Draw(this);
    }
}
