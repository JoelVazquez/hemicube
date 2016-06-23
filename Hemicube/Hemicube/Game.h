#ifndef GAME_HPP
#define GAME_HPP

#include "shader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "PlayingState.h"



class Game
{
public:
	Game();
	void update(double &lag);
	void handleKey(int &key, int &action);
	void handleCursorPos(double &xpos, double &ypos);
	void render();
	~Game();
private:
	class IGameState *current_state;
	const double MS_PER_UPDATE = 0.20;
};



#endif