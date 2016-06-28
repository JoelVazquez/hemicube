#include "Game.h"



Game::Game()
{
	current_state = new PlayingState(this);
}

void Game::update(double &lag)
{
	while (lag >= MS_PER_UPDATE)
	{
		current_state->Update();
		lag -= MS_PER_UPDATE;
	}
}

void Game::handleKey(int &key, int &action)
{
	current_state->handleKey(key, action);
	//if (key == GLFW_KEY_2 && action == GLFW_PRESS)
		//this->current_state = new State2();
}

void Game::handleCursorPos(double &xpos, double &ypos)
{
	xpos -= 1280 / 2;
	ypos -= 720 / 2;

	current_state->handleMouse(xpos, ypos);
	std::cout << "mouse pos: (" << xpos << ", " << ypos << ")" << std::endl;
}

void Game::render(double &delta)
{
	current_state->Render(delta);
	//std::cout << "render" << std::endl;
}

Game::~Game()
{
}
