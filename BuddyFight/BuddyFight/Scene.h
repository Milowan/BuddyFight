#pragma once
#include "Texture.h"




class Scene
{
protected:

	Texture* background;
	string id;

public:

	Scene(Texture* bg);

	string GetID();

	virtual void InitializeScene() {};

	virtual void UpdateScene() {};

	void Render();
};

