//
// Created by yesterday17 on 2020/2/17.
//

#include "common/color.h"

std::byte color::r() {
    return R;
}

std::byte color::g() {
    return G;
}

std::byte color::b() {
    return B;
}

std::byte color::a() {
    return A;
}

float color::rf() {
    return byte2float(R);
}

float color::gf() {
    return byte2float(G);
}

float color::bf() {
    return byte2float(B);
}

float color::af() {
    return byte2float(A);
}
