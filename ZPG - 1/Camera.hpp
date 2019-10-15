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

class Shaders;
class Camera
{
private:
	
	glm::mat4 projectionMatrix, viewMatrix;
	

public:
	glm::vec3 eye, target, up;
	float cameraSpeed;

	Camera();
	~Camera();
	glm::mat4 getCamera(void);
	void sendMatricesToShader(Shaders * shader);
	void notifyShader(Shaders * shader);
	void changeAngle();
	void lookLeft();
	void lookRight();
	void lookUp();
	void lookDown();
	void moveFront();
	void moveBack();
	void moveLeft();
	void moveRight();
	

};

