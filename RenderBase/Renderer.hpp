//
//  Renderer.hpp
//  ComputerGraphics
//
//  Created by David M Reed on 11/10/19.
//  Copyright © 2019 David M Reed. All rights reserved.
//

#ifndef Renderer_hpp
#define Renderer_hpp

#include <memory>
#include <vector>
#include "GLFWBase.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Color.hpp"
#include "Drawable.hpp"

class Renderer : public GLFWBase {

public:
    Renderer(GLFWwindow* window);
    virtual ~Renderer() noexcept;

    /// add points to be rendered
    /// @param pts vector of Point3D to render
    /// @param color color to render each point in
    /// @param pointSize size of each point (defaults to 1.0)
    /// @param objectTransformation transformation to apply to each point (defaults to identity matrix)
    /// @return position identifier for the drawable added (can be sent to removeDrawable method)
    size_t addPoints(const std::vector<Point3D> &pts, const Color &color, float pointSize = 1.0, const mat4 &objectTransformation = mat4());

    /// add colored points to be rendered
    /// @param pts vector of ColoredPoint3D to render
    /// @param pointSize size of each point (defaults to 1.0)
    /// @param objectTransformation transformation to apply to each point (defaults to identity matrix)
    /// @return position identifier for the drawable added (can be sent to removeDrawable method)
    size_t addColoredPoints(const std::vector<ColoredPoint3D> &pts, const float pointSize = 1.0, const mat4 &objectTransformation = mat4());

    /// add lines to be rendered
    /// @param lines vector of Line3D to render
    /// @param color color for the lines
    /// @param objectTransformation transformation to apply to each point (defaults to identity matrix)
    /// @return position identifier for the drawable added (can be sent to removeDrawable method)
    size_t addLines(const std::vector<Line3D> &lines, const Color &color, const mat4 &objectTransformation = mat4());

    /// add a line strip to be rendered
    /// @param pts vector of Point3D that define the line strip
    /// @param color color for the line strip
    /// @param objectTransformation transformation to apply to each point (defaults to identity matrix)
    /// @return position identifier for the drawable added (can be sent to removeDrawable method)
    size_t addLineStrip(const std::vector<Point3D> &pts, const Color &color, const mat4 &objectTransformation = mat4());

    /// add a polyline to be rendered
    /// @param pts vector of Point3D that define the polyline
    /// @param color color for the polyline
    /// @param objectTransformation transformation to apply to each point (defaults to identity matrix)
    /// @return position identifier for the drawable added (can be sent to removeDrawable method)
    size_t addPolyLine(const std::vector<Point3D> &pts, const Color &color, const mat4 &objectTransformation = mat4());

    /// return Drawable at specified position
    std::shared_ptr<Drawable> operator[](size_t pos) const {
        return _objects[pos];
    }

    /// remove drawable with specified position so it is not rendered in subsequent window re-draws
    /// @param position position identifier for drawable that is to be removed
    void removeDrawable(size_t position);

    // override the render method
    virtual void render();

protected:
    std::vector<std::shared_ptr<Drawable>> _objects;
};

#endif /* Renderer_hpp */
