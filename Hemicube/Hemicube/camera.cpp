#include "Camera.h"


camera::camera()
{
	isMousePressed = false;
	m_IsKeyPressed[GLFW_KEY_W] = false;
	m_IsKeyPressed[GLFW_KEY_S] = false;
	m_IsKeyPressed[GLFW_KEY_A] = false;
	m_IsKeyPressed[GLFW_KEY_D] = false;
}

glm::mat4 camera::GetViewMatrix()
{
	return viewMatrix;
}

void camera::KeyPressed(int &key, int &action)
{
	m_IsKeyPressed[key] = (action == GLFW_PRESS || action == GLFW_REPEAT) ? true : false;
}



void camera::MouseMove(double deltaX, double deltaY)
{
	/*if (isMousePressed == false)
		return;*/
	//always compute delta
	//mousePosition is the last mouse position
	//glm::vec2 mouse_delta = glm::vec2(x, y) - mousePosition;

	const float mouseX_Sensitivity = 0.005f;
	const float mouseY_Sensitivity = 0.005f;
	//note that yaw and pitch must be converted to radians.
	//this is done in UpdateView() by glm::rotate
	yaw += (float) mouseX_Sensitivity * deltaX;
	pitch += (float) mouseY_Sensitivity * deltaY;

	//mousePosition = glm::vec2(x, y);
	//UpdateView();
}
void camera::MousePressed(int button, int state, int x, int y)
{

	/*if (state == GLUT_UP)
	{
		isMousePressed = false;
	}
	if (state == GLUT_DOWN)
	{
		isMousePressed = true;
		mousePosition.x = x;
		mousePosition.y = y;
	}*/
}


void camera::UpdateView(double deltaTime)
{
	float dx = 0; //how much we strafe on x
	float dz = 0; //how much we walk on z
	deltaTime *= 10;
	if (m_IsKeyPressed[GLFW_KEY_W])
		dz = deltaTime;
	if (m_IsKeyPressed[GLFW_KEY_S])
		dz = -deltaTime;
	if (m_IsKeyPressed[GLFW_KEY_D])
		dx = deltaTime;
	if (m_IsKeyPressed[GLFW_KEY_A])
		dx = -deltaTime;
	//get current view matrix
	glm::mat4 mat = GetViewMatrix();
	//row major
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	const float speed = 0.12f;//how fast we move
	eyeVector += (-dz * forward + dx * strafe) * speed;
	glm::mat4 matRoll = glm::mat4(1.0f);//identity matrix; 
	glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
	glm::mat4 matYaw = glm::mat4(1.0f);//identity matrix

	//roll, pitch and yaw are used to store our angles in our class
	matRoll = glm::rotate(matRoll, roll, glm::vec3(0.0f, 0.0f, 1.0f));
	matPitch = glm::rotate(matPitch, pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, yaw, glm::vec3(0.0f, 1.0f, 0.0f));

	//order matters
	glm::mat4 rotate = matRoll * matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -eyeVector);

	viewMatrix = rotate * translate;
}

camera::~camera()
{
}
