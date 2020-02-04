#pragma once
#include "Texture.h"




class Scene
{
protected:

	Texture* background;

public:

	Scene(Texture* bg);

	virtual void InitializeScene() {};

	virtual void UpdateScene() {};

	void Render();
};

