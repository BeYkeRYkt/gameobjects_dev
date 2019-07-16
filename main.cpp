/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Vladimir Mikhailov <beykerykt@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include <iostream>

// gameobjects includes
#include "AABB.h"
#include "GameObject.h"
#include "PlayerObject.h"
#include "TriggerObject.h"

using namespace std;

int main(int argc, char** argv) {

	// collision test
	AABB* aabb1 = new AABB(0, 0, 2, 5);
	AABB* aabb2 = new AABB(0, 5, 2, 5);

	cout << "AABB Collision test" << endl;
	cout << "AABB1: " << "x(" << aabb1->getX() << ") " << "y(" << aabb1->getY() << ") " << "width(" << aabb1->getWidth() << ") " << "height(" << aabb1->getHeight() << ") " << endl;
	cout << "AABB2: " << "x(" << aabb2->getX() << ") " << "y(" << aabb2->getY() << ") " << "width(" << aabb2->getWidth() << ") " << "height(" << aabb2->getHeight() << ") " << endl;
	if (aabb1->intersects(aabb2)) {
		cout << "oh shit" << endl;
	}
	cout << "=====================" << endl;

	// GameObject tests
	cout << "GameObjects Draw/Update test" << endl;
	GameObject* truba = new GameObject("Truba", 0, 0, 50, 150);
	PlayerObject* player = new PlayerObject("SASHA_BIRD", 0, 0, 2, 2);
	TriggerObject* trigger = new TriggerObject("dead_trigger", 0 , 0, 25, 75);

	truba->Draw();
	truba->Update(60);
	cout << "=====================" << endl;
	player->Draw();
	player->Update(60);
	cout << "=====================" << endl;
	trigger->Draw();
	trigger->Update(60);
	cout << "=====================" << endl;

	cout << "GameObjects Collision test" << endl;
	if (player->checkCollision(truba)) {
		player->onCollisionEvent(truba);
		truba->onCollisionEvent(player);
	}

	if (player->checkCollision(trigger)) {
		player->onCollisionEvent(trigger);
		trigger->onCollisionEvent(trigger);
	}
	cout << "=====================" << endl;

	cout << trigger->isTriggered();

	return 0;
}