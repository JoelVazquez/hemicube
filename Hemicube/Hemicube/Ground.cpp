#include "Ground.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
float g_Ground[] = {
	-10.0f,-5.0f,  -10.0f,		0.0f,0.0f, 
	-10.0f, -5.0f, 10.0f,		0.0f, 1.0f,
	10.0f, -5.0f, -10.0f,		1.0f, 0.0f,
	10.0f, -5.0f, -10.0f,		1.0f, 0.0f,
	-10.0f, -5.0f, 10.0f,		0.0f, 1.0f,
	10.0f, -5.0f, 10.0f,		1.0f, 1.0f,
};


Ground::Ground()
{
	m_ProgramID = LoadShaders("../ground.vertexshader", "../ground.fragmentshader");
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 5 * 6 * sizeof(float), &g_Ground, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5*sizeof(float), (void *) 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void *)(3 * sizeof(float)));

	LoadTexture("../ground.bmp");
}

bool Ground::LoadTexture( const char* file_name)
{
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &m_TexHeight);
	glBindTexture(GL_TEXTURE_2D, m_TexHeight);
	int x, y, n;
	int force_channels = 4;
	unsigned char*  image_data = stbi_load(
		file_name, &x, &y, &n, force_channels);
	if (!image_data) {
		fprintf(stderr, "ERROR: could not load %s\n", file_name);
		return false;
	}
	// non-power-of-2 dimensions check
	/*if ((x & (x - 1)) != 0 || (y & (y - 1)) != 0) {
		fprintf(
			stderr, "WARNING: image %s is not power-of-2 dimensions\n", file_name
			);
	}*/
	printf("%d",x);
	// copy image data into 'target' side of cube map
	glTexSubImage2D(
		GL_TEXTURE_2D,
		0,
		0,
		0,
		x,
		y,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		&image_data
		);
	free(image_data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	/*glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);*/

	return true;
}

void Ground::Draw(glm::mat4 v, glm::mat4 p)
{
	glUseProgram(m_ProgramID);
	glUniformMatrix4fv(glGetUniformLocation(m_ProgramID, "P"), 1, GL_FALSE, &p[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(m_ProgramID, "V"), 1, GL_FALSE, &v[0][0]);
	glUniform1i(glGetUniformLocation(m_ProgramID, "cube_texture"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_TexHeight);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
}
Ground::~Ground()
{
}
