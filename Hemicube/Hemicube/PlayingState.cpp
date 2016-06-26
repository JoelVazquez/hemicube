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


void PlayingState::Update()
{
}

void PlayingState::Render()
{
	m_pScene->Render();
}


PlayingState::~PlayingState()
{
}
