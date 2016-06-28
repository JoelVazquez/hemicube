#ifndef PLAYING_STATE_H
#define PLAYING_STATE_H
#include "IGameState.h"
#include "shader.h"
#include "Scene.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
class PlayingState :
	public IGameState
{
	public:
		PlayingState(Game* pGame);
		void Update();
		void Render(double &delta);
		void handleKey(int &key, int &action) override;
		void handleMouse(double &xpos, double &ypos) override;
		~PlayingState();
	private:
		Game* m_pGame;
		Scene* m_pScene;

};


#endif
