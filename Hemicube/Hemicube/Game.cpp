#include "Game.h"

void State1::update(Game* game)
{
	std::cout << "update from state 1" << std::endl;
	std::cout << l <<" from state 1" << std::endl;
	game->current = new State2();
};

void State2::update(Game* game)
{
	std::cout << "update from state 2" << std::endl;
	game->current = new State1(27);
};

Game::Game()
{
	current = new State2();
}

void Game::update(double &lag)
{
	while (lag >= MS_PER_UPDATE)
	{
		current->update(this);
		//std::cout << "game updated" << std::endl;
		lag -= MS_PER_UPDATE;
	}
}

void Game::handleKey(int &key, int &action)
{
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
		std::cout << "handleKey: W press" << std::endl;
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		std::cout << "handleKey: UP press" << std::endl;
}

void Game::render()
{
	//std::cout << "render" << std::endl;
}

Game::~Game()
{
}
