#include "Game.h"

void State1::enter(Game* game)
{
	this->game = game;
};

void State1::update()
{
	std::cout << "update from state 1" << std::endl;
	game->current_state = new State2();
	game->current_state->enter(this->game);
};

void State1::leave()
{

};

void State2::enter(Game* game)
{
	this->game = game;
};

void State2::update()
{
	std::cout << "update from state 2" << std::endl;
	game->current_state = new State1();
	game->current_state->enter(this->game);
};

void State2::leave()
{

};

Game::Game()
{
	current_state = new State1();
	current_state->enter(this);
}

void Game::update(double &lag)
{
	while (lag >= MS_PER_UPDATE)
	{
		current_state->update();
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

void Game::handleCursorPos(double &xpos, double &ypos)
{
	std::cout << "mouse pos: (" << xpos << ", " << ypos << ")" << std::endl;
}

void Game::render()
{
	//std::cout << "render" << std::endl;
}

Game::~Game()
{
}
