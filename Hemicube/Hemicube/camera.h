#pragma once
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class camera
{
public:
	camera();
	glm::mat4 GetViewMatrix();
	void KeyPressed(const unsigned char key);
	void MouseMove(int x, int y, int width, int height);
	void MousePressed(int button, int state, int x, int y);
	void UpdateView(); 
	~camera();
private:
	glm::vec3 eyeVector;
	glm::mat4 viewMatrix;
	float roll;
	float pitch;
	float yaw;
	bool isMousePressed;
	glm::vec2 mousePosition;
};

