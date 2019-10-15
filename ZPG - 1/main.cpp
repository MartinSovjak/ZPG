#include "Application.hpp"


// OBJECT, SHADER, SCENE? - list objektu, CALLBACK, CAMERA, WINDOW


int main(void)
{
	
	//MainWindow * Window = new MainWindow();
	Application * app;

	app = app->getInstance();

	if (!app->init()) {
		exit(EXIT_FAILURE);
	}
	app->callBackFunctions();
	

	//M = glm::rotate(glm::mat4(1.0f), glm::radians(180.f), glm::vec3(0.0f, 1.0f, 0.0f));
	//M = glm::rotate(M, glm::radians(10.f), glm::vec3(1.0f, 0.0f, 0.0f));
	
	//M = glm::scale(glm::mat4(1.0f), glm::vec3(0.5f));
	
	app->draw();
	exit(EXIT_SUCCESS);



}