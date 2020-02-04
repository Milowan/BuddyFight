#include "Scene.h"





Scene::Scene(Texture* bg) :
	background(bg)
{}

void Scene::Render()
{
	if (background != NULL)
	{
		background->Render(V2ZERO, V2ONE);
	}
}