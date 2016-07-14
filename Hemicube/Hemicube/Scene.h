#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <vector>
#include <map>
#include "Model.h"
#include "Maya.h"
#include "SkyBox.h"
#include "Camera.h"
#include "ObjLoader.h"
#include "Ground.h"


class Scene
{
public:
	Scene();
	void Render();
	void AddPlayer(std::string name);
	void AddModel(std::string name);
	void LoadMaya(const char *pPath);
	void AddCamera(camera *pCamera);
	camera * GetCamera();
	//Model* GetPlayer();
	//std::vector<Model*> GetModels();
	void RenderSkyBox();
	~Scene();
private:
	std::vector<Model*> m_Models;
	Model *m_pPlayer;
	SkyBox *m_pSkyBox;
	Ground *m_pGround;
	std::map<std::string, Maya*> m_Mayas;
	camera *m_pCamera;
	ObjLoader m_Loader;
};



#endif