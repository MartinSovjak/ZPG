#include "Camera.hpp"
#include "Shaders.hpp"


Camera::Camera()
{
	//projectionMatrix = glm::mat4(1.0f);
	eye = glm::vec3(0.0f,0.0f,0.0f);
	up = glm::vec3(0.0f, 1.0f, 0.0f);

	cameraSpeed = 0.1f;
	
	double fi = 2;
	double psi = 0.0;
	
	target.x = cos(fi);
	target.z = sin(fi);
	target.y = sin(psi);

	//target = glm::vec3(0.0f, 0.5f, 0.0f);
	projectionMatrix = glm::mat4(1.0f);//glm::perspective(glm::radians(45.0f), 4.0f / 3.0f, 0.1f, 100.0f);
	viewMatrix = getCamera();

	target = glm::vec3(0.0f, 0.0f, -1.0f);
	
}


Camera::~Camera()
{
}



glm::mat4 Camera::getCamera(void)
{

	return glm::lookAt(eye, eye + target, up);
}

void Camera::sendMatricesToShader(Shaders * shader) {
	
	viewMatrix = getCamera();
	
	shader->sendUniform("viewMatrix", viewMatrix);
	shader->sendUniform("projectionMatrix", projectionMatrix);
}

void Camera::notifyShader(Shaders * shader)
{
	shader->update();
}

void Camera::lookLeft()
{
	//target.x += 0.005;
	//target.z += 0.005;
	//target.y += 0.005;
	
	//eye += (glm::normalize(glm::cross(target, up)));
}

void Camera::lookRight() {

	//target.x -= 0.005;
	//target.z -= 0.005;
	//target.y -= 0.005;
	
	//eye -= (glm::normalize(glm::cross(target, up)));
}

void Camera::moveFront()
{
	eye += cameraSpeed * target;
}

void Camera::moveBack()
{
	eye -= cameraSpeed * target;
}

void Camera::moveLeft()
{
	eye -= glm::normalize(glm::cross(target, up)) * cameraSpeed;
}

void Camera::moveRight()
{
	eye += glm::normalize(glm::cross(target, up)) * cameraSpeed;
}



