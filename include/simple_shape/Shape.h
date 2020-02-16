//
// Created by t on 3/5.
//

#ifndef LEARNOPENGL_SHAPE_H
#define LEARNOPENGL_SHAPE_H

namespace simple_shape {
    struct Node {
        float x;
        float y;

        Node(float x, float y) {
            this->x = x;
            this->y = y;
        }
    };

    class Shape {
    protected:
        static bool compiled;
        static int count;
    protected:
        static unsigned int shaderProgram;

    public:
        Shape();

        virtual double size() = 0;

        virtual void Draw() = 0;
    };
}

#endif //LEARNOPENGL_SHAPE_H
