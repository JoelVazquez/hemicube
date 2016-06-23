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
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		std::cout << "handleKey: W press" << std::endl;
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		std::cout << "handleKey: UP press" << std::endl;
	if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		this->current_state = new PlayingState(this);
	//if (key == GLFW_KEY_2 && action == GLFW_PRESS)
		//this->current_state = new State2();
}

void Game::handleCursorPos(double &xpos, double &ypos)
{
	std::cout << "mouse pos: (" << xpos << ", " << ypos << ")" << std::endl;
}

void Game::render()
{
	current_state->Render();
	//std::cout << "render" << std::endl;
}

Game::~Game()
{
}
