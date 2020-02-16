//
// Created by yesterday17 on 3/5.
//
#ifndef LEARNOPENGL_TRIANGLE_H
#define LEARNOPENGL_TRIANGLE_H

#include "Shape.h"

namespace simple_shape {
    class Triangle : public Shape {
    private:
        Node *top, *left, *right;
        unsigned int VAO;
    public:
        Triangle(float x1, float y1, float x2, float y2, float x3, float y3);

        double size() override;

        void Draw() override;
    };
}

#endif //LEARNOPENGL_TRIANGLE_H
