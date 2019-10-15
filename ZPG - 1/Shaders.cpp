
#include "Shaders.hpp"
#include "Camera.hpp"



Shaders::Shaders(Camera * cam)
{
	
	this->cam = cam;
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);
	
}

void Shaders::useShaderProgram()
{
	glUseProgram(shaderProgram);
}

bool Shaders::checkShaderErrors()
{
	
	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;

		return true;
	}
	
	printf("Shaders are correctly setup.");
	return false;
	
}

void Shaders::sendUniform(const GLchar * name, glm::mat4 data)
{
	GLint uniformID = glGetUniformLocation(this->shaderProgram, name);
	if (uniformID >= 0) {
		glUseProgram(this->shaderProgram);
		glUniformMatrix4fv(uniformID, 1, GL_FALSE, glm::value_ptr(data));
	}
	else {
		printf("Variable doesn't exist.");

		// in shader doesn't exist uniform variable 
	}
}


void Shaders::update() {

	sendUniform("viewMatrix", cam->getCamera());
	sendUniform("projectionMatrix", cam->getCamera());
}


Shaders::~Shaders()
{
}
