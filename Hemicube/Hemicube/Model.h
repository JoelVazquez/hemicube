#ifndef MODEL_H
#define MODEL_H
#include "Maya.h"
class Model
{
public:
	Model(Maya* pMaya);
	void Draw();
	~Model();
private:
	Maya* m_pMaya;
};



#endif