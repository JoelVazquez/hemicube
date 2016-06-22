#pragma once
#include <GLFW/glfw3.h>
#include <iostream>


class Game
{
public:
	Game();
	void update(double &lag);
	void handleKey(int &key, int &action);
	void render();
	class State *current;
	~Game();
private:
	
	const double MS_PER_UPDATE = 0.20;
};

class State
{
public:

	virtual void update(Game* game) = 0;

};

class State1 :public State
{
public:
	State1(int loco) { l=loco; };
	void update(Game* game) ;
private:
	int l;
};

class State2: public State
{
public:

	void update(Game* game);

};

