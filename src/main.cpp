#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include "simple_shape/Triangle.h"
#include "common/color.h"

void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);

// 设置
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main() {
    // glfw: 初始化 & 配置
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __OS_X__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // fix compilation on OS X
#endif

    // glfw: 创建 GLFW 窗口
    // --------------------
    auto window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: 加载所有 OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // 三角形
    auto triangle = new simple_shape::Triangle(-0.5f, -0.5f, 0.5f, -0.5f, 0, 0.5f);
    auto triangle2 = new simple_shape::Triangle(0.5f, -0.5f, -0.5f, 0.5f, 0.5f, 0);

    // 渲染 loop
    // -----------
    while (!glfwWindowShouldClose(window)) {
        // 处理输入
        // -------
        processInput(window);

        // 渲染
        // ----
        // 设置清空屏幕所用的颜色
        color c(0x99, 0x99, 0xff);
        glClearColor(c.rf(), c.gf(), c.bf(), c.af());
        // 清空屏幕 并用 glClearColor 的颜色填充
        glClear(GL_COLOR_BUFFER_BIT); // GL_COLOR_BUFFER_BIT 指定深度缓存

        triangle->Draw();
        triangle2->Draw();

        // glfw: 检查并调用事件，交换缓冲
        // ---------------------------
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    // glfw: 结束程序 清理资源
    // ---------------------
    glfwTerminate();
    return 0;
}

// 处理所有输入: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}