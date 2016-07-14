#ifndef GROUND_H
#define GROUND_H
#include "Maya.h"
#include <iostream>

class Ground
{
public:
	Ground();
	bool LoadTexture( const char* file_name);
	void Draw(glm::mat4 v, glm::mat4 p);
	~Ground();
private:
	GLuint m_VBO;
	GLuint m_VAO;
	GLuint m_ProgramID;
	GLuint m_TexHeight;
};


#endif