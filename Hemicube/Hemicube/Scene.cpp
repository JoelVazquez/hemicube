#include "Scene.h"


Scene::Scene()
{
}

void Scene::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	for (auto model : m_Models)
		model->Draw();
}


void Scene::AddPlayer(std::string name)
{
}

void Scene::AddModel(std::string name)
{
	m_Models.push_back(new Model(m_Mayas[name]));
}

void Scene::LoadMaya(const char *pPath)
{
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals;
	m_Loader.LoadObj(pPath, vertices, uvs, normals);
	m_Mayas[std::string(pPath)] = new Maya(vertices, uvs, normals);
}

void Scene::AddCamera(camera *pCamera)
{
}

/*camera * Scene::GetCamera()
{
}

Model* Scene::GetPlayer()
{
}

std::vector<Model*> Scene::GetModels()
{
}*/




Scene::~Scene()
{
}
