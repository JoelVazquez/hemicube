#ifndef PLAYER_H
#define PLAYER_H
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <map>
#include "Camera.h"
#include "Model.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Player
{
public:
	Player(camera *pCamera, Model *pBody);
	void HandleKey(int &key, int &action);
	void UpdatePlayer(double deltaTime);
	~Player();
private:
	camera *m_pCamera;
	Model *m_pBody;
	std::map<int, bool> m_IsKeyPressed;
};

#endif