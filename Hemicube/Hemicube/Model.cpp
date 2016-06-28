#include "Model.h"


Model::Model(Maya* pMaya)
{
	m_pMaya = pMaya;
}

void Model::Draw()
{
	m_pMaya->Draw();
}

Model::~Model()
{
}
