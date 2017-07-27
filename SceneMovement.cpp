#include "SceneMovement.h"



SceneMovement::SceneMovement()
{
}


SceneMovement::~SceneMovement()
{
}

void SceneMovement::initialize()
{
}

float SceneMovement::update()
{
	return m_alpha;
}

void SceneMovement::In()
{
	m_in_out = true;
}

void SceneMovement::Out()
{
	m_in_out = false;
}
