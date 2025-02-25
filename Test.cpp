#define GLEW_DLL
#define GLFW_DLL

#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3.\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 1);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    GLFWwindow* window = glfwCreateWindow(640, 480, "Trapezia", NULL, NULL);
    if (!window) {
        fprintf(stderr, "ERROR: could not create window.\n");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (GLEW_OK != ret) {
        fprintf(stderr, "ERROR: %s\n", glewGetErrorString(ret));
        return 1;
    }

    while (!glfwWindowShouldClose(window)) {
        // Установить цвет фона
        glClearColor(1.0, 0.4, 0.1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

        // Нарисовать трапецию
        glBegin(GL_QUADS);

        // Цвет трапеции
        glColor3f(0.7, 0.1, 0.6);

        // Координаты вершин трапеции
        glVertex2f(-0.5, 0.5); // Верхняя левая
        glVertex2f(0.5, 0.5);  // Верхняя правая
        glVertex2f(0.8, -0.5); // Нижняя правая
        glVertex2f(-0.8, -0.5); // Нижняя левая

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
