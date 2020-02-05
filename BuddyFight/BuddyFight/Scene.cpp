#include "Scene.h"





Scene::Scene(Texture* bg) :
	background(bg)
{}

void Scene::Render()
{
	if (background != NULL)
	{
		background->Render(Vector2(Graphics::SCREEN_WIDTH / 2, Graphics::SCREEN_HEIGHT / 2), V2ONE);
	}
}