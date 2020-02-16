//
// Created by yesterday17 on 2020/2/17.
//

#ifndef LEARNOPENGL_COLOR_H
#define LEARNOPENGL_COLOR_H

#include <cstddef>

class color {
private:
    std::byte R;
    std::byte G;
    std::byte B;
    std::byte A;

public:
    static float byte2float(std::byte b) {
        return (float) b / 256.f;
    }

    color(std::byte r, std::byte g, std::byte b, std::byte a = std::byte(0xff)) {
        R = r;
        G = g;
        B = b;
        A = a;
    }

    color(int r, int g, int b, int a = 0xff) : color(std::byte(r % 0x100),
                                                     std::byte(g % 0x100),
                                                     std::byte(b % 0x100),
                                                     std::byte(a % 0x100)) {
    }

    std::byte r();

    std::byte g();

    std::byte b();

    std::byte a();

    float rf();

    float gf();

    float bf();

    float af();
};


#endif //LEARNOPENGL_COLOR_H
