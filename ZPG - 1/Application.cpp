#include "Application.hpp"


Application* Application::instance = NULL;

Application::Application()
{
	
}

Application* Application::getInstance()
{
	if (instance == NULL)
	{
		instance = new Application();
		return instance;
	}
	return instance;

}

bool Application::init()
{
	//glfwSetErrorCallback(error_callback);
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	int major, minor, revision;

	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();
	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	//Scene * scene = new Scene();
	
	cam = new Camera();
	shaders = new Shaders(cam);
	
	float points[9] = {
		0.0f, 0.5f, 1.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f
	};
	Model * mod = new Model(points);
	obj = new Object(mod);

	
	bool shaderError = shaders->checkShaderErrors();

	if (shaderError) {
		system("pause");
		return -1;
	}


	return true;
/*
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);

	float ratio = width / (float)height;

	glViewport(0, 0, width, height);
	*/
}

void Application::error_callback(int error, const char* description) {
	fputs(description, stderr);
}

void Application::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		cam->moveFront();
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS)
		cam->moveBack();
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
		cam->moveLeft();
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS)
		cam->moveRight();

	
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Application::window_size_callback(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Application::cursor_pos_callback(GLFWwindow* window, double mouseX, double mouseY) {
	printf("cursor_pos_callback %d, %d \n", (int)mouseX, (int)mouseY);

	if (!firstTouch) {
		curX = mouseX;
		curY = mouseY;
		firstTouch = true;
	}
	else {
		prevX = curX;
		prevY = curY;

		curX = mouseX;
		curY = mouseY;

		int diffX = curX - prevX;
		int diffY = curY - prevY;

		if (diffX > 0) {
			cam->lookLeft();
		}
		else {
			cam->lookRight();
		}
	}
}

void Application::mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	printf("mouse_button_callback %d, %d, %d \n", button, action, mods);
}

void Application::window_focus_callback(GLFWwindow* window, int focused) {
	printf("window_focus_callback %d \n", focused);
}

void Application::window_iconify_callback(GLFWwindow* window, int iconified) {
	printf("window_iconify_callback %d \n", iconified);
}

void Application::callBackFunctions() {

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) -> void {Application::getInstance()->key_callback(window, key, scancode, action, mods); });

	glfwSetErrorCallback([](int error, const char* description) -> void {Application::getInstance()->error_callback(error, description); });

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) -> void {Application::getInstance()->window_size_callback(window, width, height); });

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double mouseXPos, double mouseYPos) -> void {Application::getInstance()->cursor_pos_callback(window, mouseXPos, mouseYPos); });

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) -> void {Application::getInstance()->mouse_button_callback(window, button, action, mods); });

	glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused) -> void {Application::getInstance()->window_focus_callback(window, focused); });

	glfwSetWindowIconifyCallback(window, [](GLFWwindow* window, int iconified) -> void {Application::getInstance()->window_iconify_callback(window, iconified); });

}
void Application::draw()
{
	float angle = 0;

	while (!glfwWindowShouldClose(window))
	{

		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


		shaders->useShaderProgram();

		glm::mat4 M = glm::mat4(1.0f);

		angle += 2;
		if (angle > 360) {
			angle -= 360;
		}
		glm::vec3 vec = glm::vec3(0.0, 0.5, 0.0);
		M = glm::translate(M, vec);
		M = glm::rotate(M, glm::radians(angle), glm::vec3(0.0f, 0.0f, 1.0f));
		M = glm::translate(M, -vec);

		shaders->sendUniform("modelMatrix", M);
		cam->sendMatricesToShader(shaders);
		//shaders->update();

		//obj->getModel()->bindVertices();


		// draw triangles
		glDrawArrays(GL_TRIANGLES, 0, 3); //mode,first,count
										  // update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);

	}
	glfwDestroyWindow(window);
	glfwTerminate();
	
}
Application::~Application()
{
}
