#include "Scene.h"






Scene::Scene()
{
	m_pSkyBox = new SkyBox();
	m_pGround = new Ground();
	m_pCamera = new camera();
}
void Scene::RenderSkyBox()
{
	glm::mat4 V = m_pCamera->GetViewMatrix();
	glm::mat4 P = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	m_pSkyBox->Draw(V,P);
}

void Scene::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	RenderSkyBox();
	glm::mat4 view = m_pCamera->GetViewMatrix();
	glm::mat4 vP = glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f) * view;
	m_pGround->Draw(view, glm::perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f));
	for (auto model : m_Models)
		model->Draw(vP);
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

camera * Scene::GetCamera()
{
	return m_pCamera;
}

/*Model* Scene::GetPlayer()
{
}

std::vector<Model*> Scene::GetModels()
{
}*/




Scene::~Scene()
{
}
