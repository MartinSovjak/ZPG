#include "Scene.hpp"



Scene::Scene()
{

}


Scene::~Scene()
{
}

void Scene::drawObject(Object obj)
{
	glDrawArrays(GL_TRIANGLES, 0, 3);
}

void Scene::drawAllObjects()
{
	for (Object & item : objects) {
		drawObject(item);
	}
}

void Scene::addObject(Object obj)
{
	objects.push_back(obj);
}
