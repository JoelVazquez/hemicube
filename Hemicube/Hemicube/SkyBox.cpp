#include "SkyBox.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

float g_Points[] = {
	-10.0f, 10.0f, -10.0f,
	-10.0f, -10.0f, -10.0f,
	10.0f, -10.0f, -10.0f,
	10.0f, -10.0f, -10.0f,
	10.0f, 10.0f, -10.0f,
	-10.0f, 10.0f, -10.0f,

	-10.0f, -10.0f, 10.0f,
	-10.0f, -10.0f, -10.0f,
	-10.0f, 10.0f, -10.0f,
	-10.0f, 10.0f, -10.0f,
	-10.0f, 10.0f, 10.0f,
	-10.0f, -10.0f, 10.0f,

	10.0f, -10.0f, -10.0f,
	10.0f, -10.0f, 10.0f,
	10.0f, 10.0f, 10.0f,
	10.0f, 10.0f, 10.0f,
	10.0f, 10.0f, -10.0f,
	10.0f, -10.0f, -10.0f,

	-10.0f, -10.0f, 10.0f,
	-10.0f, 10.0f, 10.0f,
	10.0f, 10.0f, 10.0f,
	10.0f, 10.0f, 10.0f,
	10.0f, -10.0f, 10.0f,
	-10.0f, -10.0f, 10.0f,

	-10.0f, 10.0f, -10.0f,
	10.0f, 10.0f, -10.0f,
	10.0f, 10.0f, 10.0f,
	10.0f, 10.0f, 10.0f,
	-10.0f, 10.0f, 10.0f,
	-10.0f, 10.0f, -10.0f,

	-10.0f, -10.0f, -10.0f,
	-10.0f, -10.0f, 10.0f,
	10.0f, -10.0f, -10.0f,
	10.0f, -10.0f, -10.0f,
	-10.0f, -10.0f, 10.0f,
	10.0f, -10.0f, 10.0f
};

SkyBox::SkyBox()
{
	create_cube_map(
		"../negz.bmp",
		"../posz.bmp",
		"../posy.bmp",
		"../negy.bmp",
		"../negx.bmp",
		"../posx.bmp"
		);

	m_ProgramID = LoadShaders("../sky.vertexshader", "../sky.fragmentshader");
	glGenVertexArrays(1, &m_VAO);
	glBindVertexArray(m_VAO);
	glGenBuffers(1, &m_VBO);
	glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glBufferData(GL_ARRAY_BUFFER, 3 * 36 * sizeof(float), &g_Points, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	//glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
}

bool SkyBox::load_cube_map_side(
	 GLenum side_target, const char* file_name
	) {
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_TexCube);

	int x, y, n;
	int force_channels = 4;
	unsigned char*  image_data = stbi_load(
		file_name, &x, &y, &n, force_channels);
	if (!image_data) {
		fprintf(stderr, "ERROR: could not load %s\n", file_name);
		return false;
	}
	// non-power-of-2 dimensions check
	if ((x & (x - 1)) != 0 || (y & (y - 1)) != 0) {
		fprintf(
			stderr, "WARNING: image %s is not power-of-2 dimensions\n", file_name
			);
	}

	// copy image data into 'target' side of cube map
	glTexImage2D(
		side_target,
		0,
		GL_RGBA,
		x,
		y,
		0,
		GL_RGBA,
		GL_UNSIGNED_BYTE,
		image_data
		);
	free(image_data);
	return true;
}

void SkyBox::create_cube_map(
	const char* front,
	const char* back,
	const char* top,
	const char* bottom,
	const char* left,
	const char* right
	) {
	// generate a cube-map texture to hold all the sides
	glActiveTexture(GL_TEXTURE0);
	glGenTextures(1, &m_TexCube);

	// load each image and copy into a side of the cube-map texture
	load_cube_map_side(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, front);
	load_cube_map_side(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, back);
	load_cube_map_side(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, top);
	load_cube_map_side(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, bottom);
	load_cube_map_side(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, left);
	load_cube_map_side(GL_TEXTURE_CUBE_MAP_POSITIVE_X, right);
	// format cube map texture
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

void SkyBox::Draw(glm::mat4 v, glm::mat4 p)
{
	glDepthMask(GL_FALSE);
	glUseProgram(m_ProgramID);
	//glm::mat4 vt = glm::transpose(v);
	//glm::vec3 camPos(vt[0][3], vt[1][3], vt[2][3]);

	//glm::mat4 m = glm::translate(glm::mat4(1.0f), -camPos);
	glUniformMatrix4fv(glGetUniformLocation(m_ProgramID, "P"), 1, GL_FALSE, &p[0][0]);
	glUniformMatrix4fv(glGetUniformLocation(m_ProgramID, "V"), 1, GL_FALSE, &v[0][0]);
	//glUniformMatrix4fv(glGetUniformLocation(m_ProgramID, "M"), 1, GL_FALSE, &m[0][0]);
	glUniform1i(glGetUniformLocation(m_ProgramID, "cube_texture"), 0);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, m_TexCube);
	glBindVertexArray(m_VAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDepthMask(GL_TRUE);
}


SkyBox::~SkyBox()
{
}
