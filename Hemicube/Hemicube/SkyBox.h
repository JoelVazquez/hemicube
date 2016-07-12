#ifndef SKY_BOX_H
#define SKY_BOX_H
#include "Maya.h"
#include <iostream>

class SkyBox
{
public:
	SkyBox();
	bool load_cube_map_side(
		GLuint texture, GLenum side_target, const char* file_name
		);
	void create_cube_map(
		const char* front,
		const char* back,
		const char* top,
		const char* bottom,
		const char* left,
		const char* right,
		GLuint* tex_cube
		);
	void Draw(glm::mat4 v, glm::mat4 p);
	~SkyBox();
private:
	GLuint m_VBO;
	GLuint m_VAO;
	GLuint m_ProgramID;
	GLuint m_TexCube;
};


#endif