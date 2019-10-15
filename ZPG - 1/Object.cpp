#include "Object.hpp"


Object::Object(Model * model)
{
	this->model = model;
}

Object::~Object()
{
}

Model * Object::getModel()
{
	return model;
}
