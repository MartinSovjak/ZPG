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

#include "Model.hpp"

class Object
{
	Model* model;

public:
	Object(Model* model);
	~Object();

	Model * getModel();

	
};

