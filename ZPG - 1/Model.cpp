#include "Model.hpp"



Model::Model(float * arr)
{
	//points = new float[9];
	
	for (int i = 0; i < 9; i++) {
		points[i] = arr[i];
	}
	GLuint VBO = 0;
	glGenBuffers(1, &VBO); // generate the VBO
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points,
	GL_STATIC_DRAW);
	//vertex attribute object(VAO)

	VAO = 0;
	glGenVertexArrays(1, &VAO); //generate the VAO
	glBindVertexArray(VAO); //bind the VAO
	glEnableVertexAttribArray(0); //enable vertex attributes
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}


Model::~Model()
{
}

void Model::bindVertices()
{
	glBindVertexArray(VAO);
}


