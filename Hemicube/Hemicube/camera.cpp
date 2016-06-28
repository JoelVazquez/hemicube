#include "Camera.h"


Camera::Camera()
{
	m_DeltaTime = 0;
	m_IsMousePressed = false;
	m_IsKeyPressed[GLFW_KEY_W] = false;
	m_IsKeyPressed[GLFW_KEY_S] = false;
	m_IsKeyPressed[GLFW_KEY_A] = false;
	m_IsKeyPressed[GLFW_KEY_D] = false;
}

glm::mat4 Camera::GetViewMatrix()
{
	return m_ViewMatrix;
}

void Camera::KeyPressed(int &key, int &action)
{

	if (action == GLFW_PRESS)
		m_IsKeyPressed[key] = true;
	if (action == GLFW_RELEASE)
		m_IsKeyPressed[key] = false;

	

}



void Camera::MouseMove(double x, double y)
{
	/*if (m_IsMousePressed == false)
		return;*/
	//always compute delta
	//mousePosition is the last mouse position
	glm::vec2 mouse_delta = glm::vec2(x, y);

	const float mouseX_Sensitivity = 0.0025f;
	const float mouseY_Sensitivity = 0.0025f;
	//note that yaw and pitch must be converted to radians.
	//this is done in UpdateView() by glm::rotate
	m_Yaw += mouseX_Sensitivity * mouse_delta.x;
	m_Pitch += mouseY_Sensitivity * mouse_delta.y;

	m_MousePosition = glm::vec2(x, y);
//	UpdateView();
}
void Camera::MousePressed(int button, int state, int x, int y)
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


void Camera::UpdateView(double &delta)
{


	double dx = 0; //how much we strafe on x
	double dz = 0; //how much we walk on z
	delta *= 2;
	if (m_IsKeyPressed[GLFW_KEY_W])
		dz = delta;
	if (m_IsKeyPressed[GLFW_KEY_S])
		dz = -delta;
	if (m_IsKeyPressed[GLFW_KEY_A])
		dx = -delta;
	if (m_IsKeyPressed[GLFW_KEY_D])
		dx = delta;


	//get current view matrix
	glm::mat4 mat = GetViewMatrix();
	//row major
	glm::vec3 forward(mat[0][2], mat[1][2], mat[2][2]);
	glm::vec3 strafe(mat[0][0], mat[1][0], mat[2][0]);

	const float speed = 0.12f;//how fast we move
	m_EyeVector += ((float)-dz * forward + (float)dx * strafe) * speed;


	glm::mat4 matRoll = glm::mat4(1.0f);//identity matrix; 
	glm::mat4 matPitch = glm::mat4(1.0f);//identity matrix
	glm::mat4 matYaw = glm::mat4(1.0f);//identity matrix

	//roll, pitch and yaw are used to store our angles in our class
	matRoll = glm::rotate(matRoll, m_Roll, glm::vec3(0.0f, 0.0f, 1.0f));
	matPitch = glm::rotate(matPitch, m_Pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	matYaw = glm::rotate(matYaw, m_Yaw, glm::vec3(0.0f, 1.0f, 0.0f));

	//order matters
	glm::mat4 rotate = matRoll * matPitch * matYaw;

	glm::mat4 translate = glm::mat4(1.0f);
	translate = glm::translate(translate, -m_EyeVector);

	m_ViewMatrix = rotate * translate;
}

Camera::~Camera()
{
}
