#pragma once


#include <GL/glew.h>

#include <stdio.h>
#include <stdlib.h>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

class Camera;
class Shaders
{

private: 
	GLuint shaderProgram;
	Camera * cam;

	const char* vertex_shader = "#version 330\n"
		
		"uniform mat4 modelMatrix;"
		"uniform mat4 viewMatrix;"
		"uniform mat4 projectionMatrix;"

		"layout(location= 0)in vec3 in_Position;"


		"void main () {"
		"gl_Position = (projectionMatrix * viewMatrix * modelMatrix) * vec4(in_Position, 1.0);"
		"}";
	const char* fragment_shader =
		"#version 330\n"
		"out vec4 frag_colour;"
		"void main () {"
		"     frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
		"}";
	


public:
	
	
	Shaders(Camera * cam);
	void useShaderProgram();
	bool checkShaderErrors();
	void sendUniform(const GLchar *name, glm::mat4 data);
	void update();


	~Shaders();
};

