#ifndef I_GAME_STATE_H
#define I_GAME_STATE_H
class Game;
class IGameState
{
public:
	virtual ~IGameState() {};
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void handleKey(int &key, int &action) = 0;
};

#endif