#pragma once


#pragma comment (lib, "glfw3.lib")

#include <GL/glew.h>

//Include GLFW  
#include <GLFW/glfw3.h>  

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr


//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

#include "Camera.hpp"
#include "Shaders.hpp"
#include "Object.hpp"
#include "Model.hpp"
#include "Scene.hpp"
class Application
{

	GLFWwindow * window;
	Shaders * shaders;
	Camera * cam;
	Object * obj;
	
	int prevX = 0, prevY = 0;
	int curX = 0, curY = 0;
	bool firstTouch = false, secondTouch = false;
	
	static Application* instance;
	Application();

	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void error_callback(int error, const char* description);
	void window_size_callback(GLFWwindow* window, int width, int height);
	void cursor_pos_callback(GLFWwindow* window, double mouseX, double mouseY);
	void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	void window_focus_callback(GLFWwindow* window, int focused);
	void window_iconify_callback(GLFWwindow* window, int iconified);

public:
	
	static Application* getInstance();
	bool init();
	void callBackFunctions();
	void draw();
	
	~Application();
};

