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
	if (key == GLFW_KEY_W && action == GLFW_PRESS)
	{
		std::cout << "handleKey: W press" << std::endl;
		m_pScene->GetCamera()->KeyPressed('w');
	}
	if (key == GLFW_KEY_S && action == GLFW_PRESS)
	{
		std::cout << "handleKey: S press" << std::endl;
		m_pScene->GetCamera()->KeyPressed('s');
	}
	if (key == GLFW_KEY_D && action == GLFW_PRESS)
	{
		std::cout << "handleKey: D press" << std::endl;
		m_pScene->GetCamera()->KeyPressed('d');
	}
	if (key == GLFW_KEY_A && action == GLFW_PRESS)
	{
		std::cout << "handleKey: A press" << std::endl;
		m_pScene->GetCamera()->KeyPressed('a');
	}
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
		std::cout << "handleKey: UP press" << std::endl;
	/*if (key == GLFW_KEY_1 && action == GLFW_PRESS)
		this->current_state = new PlayingState(this);*/

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
