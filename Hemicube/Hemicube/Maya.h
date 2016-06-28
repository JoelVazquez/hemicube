#ifndef MAYA_H
#define MAYA_H
#include "shader.h"
#include <vector>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include <GL/glew.h>

class Maya
{
public:
	Maya(std::vector<glm::vec3> & vertices,
		std::vector<glm::vec2> & uvs,
		std::vector<glm::vec3> & normals);
	void Draw();
	~Maya();
private:	
	unsigned int m_VertexsSize;
	GLuint m_ProgramID;
	glm::mat4 m_MVP;
	glm::mat4 m_MW;
	GLuint m_MatrixID;
	GLuint m_MatrixMWID;
	GLuint m_VertexArrayID;
	GLuint m_VertexBuffer;
	GLuint m_NormalBuffer;
	GLuint m_UvBuffer;
};

#endif
