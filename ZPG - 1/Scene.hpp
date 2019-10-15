#pragma once

#include <GL/glew.h>

#include <stdio.h>
#include <stdlib.h>
#include <vector>

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

#include "Shaders.hpp"
#include "Object.hpp"


class Scene
{
	Shaders * shader;
	std::vector<Object> objects;
	Camera * cam;

	
	
public:
	Scene();
	~Scene();

	void drawObject(Object obj);
	void drawAllObjects();
	void addObject(Object obj);
	



};

