#pragma once
#include <GLFW/glfw3.h>
#include <iostream>


class Game
{
public:
	Game();
	void update(double &lag);
	void handleKey(int &key, int &action);
	void handleCursorPos(double &xpos, double &ypos);
	void render();
	class State *current_state;
	~Game();
private:
	
	const double MS_PER_UPDATE = 0.20;
};

class State
{
public:
	virtual void enter(Game* game) = 0;
	virtual void update() = 0;
	virtual void leave() = 0;

};

class State1 :public State
{
public:
	void enter(Game* game);
	void update();
	void leave();
private:
	Game* game;
};

class State2: public State
{
public:
	void enter(Game* game);
	void update();
	void leave();
private:
	Game* game;

};

