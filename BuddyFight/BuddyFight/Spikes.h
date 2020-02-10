#pragma once
#include "Entity.h"
#include "Player.h"
class Spikes : public Entity
{
	private:


	protected:

	public:

		Spikes(float x, float y);
		~Spikes();

		void HandleCollision(Entity* other) override;

};

