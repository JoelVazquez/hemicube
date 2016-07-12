#include "Player.h"


Player::Player(camera *pCamera, Model *pBody)
{
	m_pCamera = pCamera;
	m_pBody = pBody;
	m_IsKeyPressed[GLFW_KEY_W] = false;
	m_IsKeyPressed[GLFW_KEY_S] = false;
	m_IsKeyPressed[GLFW_KEY_A] = false;
	m_IsKeyPressed[GLFW_KEY_D] = false;
}

void Player::UpdatePlayer(double deltaTime)
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

}

void Player::HandleKey(int &key, int &action)
{
	

}

Player::~Player()
{
}
