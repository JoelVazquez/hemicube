#ifndef CAMERA_H
#define CAMERA_H
#include <map>
#include <iostream>
#include <GLFW/glfw3.h>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera
{
public:
	Camera();
	glm::mat4 GetViewMatrix();
	void KeyPressed(int &key, int &action);
	void MouseMove(double x, double y);
	void MousePressed(int button, int state, int x, int y);
	void UpdateView(double &delta);
	~Camera();
private:
	glm::vec3 m_EyeVector;
	glm::mat4 m_ViewMatrix;
	glm::vec2 m_MousePosition;
	std::map<int, bool> m_IsKeyPressed;
	bool m_IsMousePressed;
	float m_Roll;
	float m_Pitch;
	float m_Yaw;
	double m_DeltaTime;

	
};

#endif