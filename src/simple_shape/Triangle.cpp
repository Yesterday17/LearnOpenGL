//
// Created by yesterday17 on 3/5.
//

#include <glad/glad.h>
#include "simple_shape/Triangle.h"

namespace simple_shape {
    Triangle::Triangle(float x1, float y1, float x2, float y2, float x3, float y3) : Shape() {
        this->top = new Node(x1, y1);
        this->left = new Node(x2, y2);
        this->right = new Node(x3, y3);

        float vertices[] = {
                this->top->x, this->top->y, 0.0f,
                this->left->x, this->left->y, 0.0f,
                this->right->x, this->right->y, 0.0f
        };

        unsigned int VBO;// 生成 VBO 对象
        glGenBuffers(1, &VBO); // 缓冲 ID, VBO 地址
        glGenVertexArrays(1, &VAO); // 生成 VAO 对象
        glBindVertexArray(VAO); // 绑定VAO

        // 绑定顶点缓冲对象(VBO)到 GL_ARRAY_BUFFER 上
        // 绑定后所有的操作都会对该 VBO 执行
        glBindBuffer(GL_ARRAY_BUFFER, VBO);

        // 将顶点数据复制到缓冲的内存中
        // 其中 GL_STATIC_DRAW 表示数据几乎不会改变
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // 设置顶点属性指针
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    double Triangle::size() {
        return (this->top->x * this->left->y +
                this->left->x * this->right->y +
                this->right->x * this->top->y -
                this->top->x * this->right->y -
                this->left->x * this->top->y +
                this->right->x * this->left->y) / 2;
    }

    void Triangle::Draw() {
        // 使用已经编译完成的 shaderProgram
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
    }
}