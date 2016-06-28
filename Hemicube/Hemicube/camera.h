#ifndef camera_HPP
#define camera_HPP
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <map>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class camera
{
public:
	camera();
	glm::mat4 GetViewMatrix();
	void KeyPressed(int &key, int &action);
	void MouseMove(double deltaX, double deltaY);
	void MousePressed(int button, int state, int x, int y);
	void UpdateView(double deltaTime);
	~camera();
private:
	glm::vec3 eyeVector;
	glm::mat4 viewMatrix;
	float roll;
	float pitch;
	float yaw;
	bool isMousePressed;
	glm::vec2 mousePosition;
	std::map<int, bool> m_IsKeyPressed;
};

#endif