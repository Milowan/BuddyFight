#include "Scene.h"





Scene::Scene(Texture* bg) :
	background(bg)
{
	background->SetHeight(Graphics::SCREEN_HEIGHT);
	background->SetWidth(Graphics::SCREEN_WIDTH);
}

void Scene::Render()
{
	if (background != NULL)
	{
		background->Render(Vector2(Graphics::SCREEN_WIDTH / 2, Graphics::SCREEN_HEIGHT / 2), V2ONE);
	}
}