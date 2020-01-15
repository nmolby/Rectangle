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
    std::ifstream infile(filename);
    
    int x1, y1, x2, y2, r, g, b;
    while(infile >> x1 >> y1 >> x2 >> y2 >> r >> g >> b){
        std::vector<Point3D> pts;
        int minX, maxX, minY, maxY;
        minX = x1 > x2 ? x2 : x1;
        maxX = x1 > x2 ? x1 : x2;
        minY = y1 > y2 ? y2 : y1;
        maxY = y1 > y2 ? y1 : y2;

        for(int currentX = minX; currentX <= maxX; currentX++){
            for(int currentY = minY; currentY <= maxY; currentY++){
                pts.push_back(Point3D(currentX, currentY));
            }
        }
        
        addPoints(pts, Color(r, g, b));

    }
}
