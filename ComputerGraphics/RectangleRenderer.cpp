//
//  RectangleRenderer.cpp
//  Lab1Rectangle
//
//  Created by David M Reed on 11/20/19.
//  Copyright © 2019 David M Reed. All rights reserved.
//

#include <fstream>
#include "Rectangle.hpp"
#include "RectangleRenderer.hpp"

RectangleRenderer::RectangleRenderer(GLFWwindow *window, std::string filename) : Renderer(window) {

    std::ifstream infile(filename.c_str());
    MyRectangle rect;

    // while not end of file read Rectangle objects from file stream
    while (infile >> rect) {
        // render it
        rect.render(this);
        // store it in case we want to use it in the future
        _rectangles.push_back(rect);
    }
    infile.close();
}
