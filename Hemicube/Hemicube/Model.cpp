#include "Model.h"


Model::Model(Maya* pMaya)
{
	m_pMaya = pMaya;
}

void Model::Draw(glm::mat4 vP)
{
	m_pMaya->Draw(vP);
}

Model::~Model()
{
}
