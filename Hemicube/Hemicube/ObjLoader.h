#ifndef OBJ_LOADER_H
#define OBJ_LOADER_H
#include <iostream>
#include <vector>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class ObjLoader
{
public:
	ObjLoader();
	bool LoadObj(
		const char *path,
		std::vector<glm::vec3> & vertices,
		std::vector<glm::vec2> & uvs,
		std::vector<glm::vec3> & normals
		);
	~ObjLoader();
};

#endif