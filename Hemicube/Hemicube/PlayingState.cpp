#include "PlayingState.h"


PlayingState::PlayingState(Game* pGame)
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	m_pScene = new Scene();
	m_pScene->LoadMaya("man.obj");
	m_pScene->AddModel("man.obj");
	m_pScene->LoadMaya("cube.obj");
	m_pScene->AddModel("cube.obj");
}

void PlayingState::handleKey(int &key, int &action)
{
	m_pScene->GetCamera()->KeyPressed(key,action);
	/*if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		this->current_state = new PlayingState(this);*/

}

void PlayingState::Update()
{
}
void PlayingState::HandleMouse(double deltaX, double deltaY)
{
	m_pScene->GetCamera()->MouseMove(deltaX, deltaY);
}
void PlayingState::Render(double deltaTime)
{
	m_pScene->GetCamera()->UpdateView(deltaTime);
	m_pScene->Render();
}


PlayingState::~PlayingState()
{
}
