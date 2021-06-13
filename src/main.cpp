#include "man/entitymanager.hpp"
#include "sys/render.hpp"
#include "sys/physics.hpp"
#include "sys/collision.hpp"
#include "sys/input.hpp"
#include "util/typealiases.hpp"

extern "C" {
	#include "lib/tinyPTC/tinyptc.h"
}

#include <cstdint>
#include <iostream>

constexpr uint32_t kSCRWIDTH 	{ 640 };
constexpr uint32_t kSCRHEIGHT { 360 };

int main() {

	try {
		const ECS::RenderSystem_t render{kSCRWIDTH, kSCRHEIGHT};
		ECS::PhysicsSystem_t Pyhisics;
		ECS::CollisionSystem_t Collision;
		ECS::InputSystem_t Input;
		ECS::EntityManager_t EntityMan;

		EntityMan.createEntity(0, 0);
		EntityMan.createEntity(20, 50);
		auto& entity = EntityMan.createEntity(0, 300);
		EntityMan.addInputComponent(entity);

		while( render.update(EntityMan) ) {
			Input.update(EntityMan);
			Pyhisics.update(EntityMan);
			Collision.update(EntityMan);
		}

	} catch(const char* s) {
		std::cout << "Capturada excepción " << s << "\n";
	}

	return 0;
}
