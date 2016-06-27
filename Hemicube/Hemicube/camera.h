#ifndef CAMERA_H
#define CAMERA_H
#include <map>
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Camera
{
public:
	Camera();
	glm::mat4 GetViewMatrix();
	void KeyPressed(const unsigned char key);
	void MouseMove(int x, int y, int width, int height);
	void MousePressed(int button, int state, int x, int y);
	void UpdateView(); 
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

	
};

#endif