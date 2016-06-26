#ifndef SCENE_H
#define SCENE_H
#include <string>
#include <vector>
#include <map>
#include "Model.h"
#include "Maya.h"
#include "camera.h"
#include "ObjLoader.h"
class Scene
{
public:
	Scene();
	void Render();
	void AddPlayer(std::string name);
	void AddModel(std::string name);
	void LoadMaya(const char *pPath);
	void AddCamera(camera *pCamera);
	//camera * GetCamera();
	//Model* GetPlayer();
	//std::vector<Model*> GetModels();
	~Scene();
private:
	std::vector<Model*> m_Models;
	Model *m_Player;
	std::map<std::string, Maya*> m_Mayas;
	camera *m_pCamera;
	ObjLoader m_Loader;
};

#endif