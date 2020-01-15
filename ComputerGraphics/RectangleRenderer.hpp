//
//  RectangleRenderer.hpp
//  Lab1Rectangle
//
//  Created by David M Reed on 11/20/19.
//  Copyright © 2019 David M Reed. All rights reserved.
//

#ifndef RectangleRenderer_hpp
#define RectangleRenderer_hpp

#include "graphics.hpp"
#include "Rectangle.hpp"

class RectangleRenderer: public Renderer {
public:
    RectangleRenderer(GLFWwindow *window, std::string filename);

    virtual ~RectangleRenderer() noexcept {}
};


#endif /* RectangleRenderer_hpp */
