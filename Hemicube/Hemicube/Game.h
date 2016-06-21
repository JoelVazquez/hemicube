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

	~Game();
private:
	const double MS_PER_UPDATE = 0.20;
};

