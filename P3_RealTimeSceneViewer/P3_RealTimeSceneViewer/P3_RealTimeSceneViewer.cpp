
//OpenGL Includes
#include<glad/glad.h>
#include <GLFW/glfw3.h>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#define TINYOBJLOADER_IMPLEMENTATION
#include"tiny_obj_loader.h"

#define STB_IMAGE_IMPLEMENTATION
#include"stb_image.h"

//DearIMGUI Includes
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

//Base Includes
#include <iostream>

//Created Classes Includes

using namespace std;

//User Input (idk if needed)
//void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
//void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);

//Vars
float delta;

int main()
{
    float width = 800;
    float height = 800;
    GLFWwindow* window;


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(width, height, "Real Time Scene Viewer - Macuha & Akim", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    gladLoadGL();

    glViewport(0, 0, width, height);

    /*
    * Needed for User Inputs
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    glfwSetCursorPosCallback(window, mouse_callback);
    */

    glEnable(GL_DEPTH_TEST);

    //Time
    float lastTime = glfwGetTime();

    //DearIMGUIInit
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);          // Second param install_callback=true will install GLFW callbacks and chain to existing ones.
    ImGui_ImplOpenGL3_Init();

    while (!glfwWindowShouldClose(window))
    {
        /* Pre Start of Loop */
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        ImGui::ShowDemoWindow(); // Show demo window! :)

        /*Calculate Delta Time*/
        GLfloat currTime = glfwGetTime();
        delta = currTime - lastTime;

       /*Start of Loop*/

        /*End of Loop*/
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();



        lastTime = currTime; // delta time
    }

    /*On ShutDown*/
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}

