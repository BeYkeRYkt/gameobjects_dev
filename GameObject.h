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
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "AABB.h"
#include <string>

using namespace std;

class GameObject {
private:
	string tag = "default";
	string name; // имя
	int xPos, yPos; // координаты
	int width, height; // ширина и высота
	AABB* boundingBox; // hitbox

public:
	GameObject(string name, int x, int y, int width, int height);
	GameObject(string name, AABB* aabb);

	~GameObject();

	string getName() {
		return name;
	}

	string getTag() {
		return tag;
	}

	void setTag(string tag);

	int getPosX() {
		return xPos;
	}

	void setPosX(int x);

	int getPosY() {
		return yPos;
	}

	void setPosY(int y);

	bool checkCollision(GameObject* other);

	virtual void onCollisionEvent(GameObject* gameObject);

	// Вызывайте методы с движка игры
	/**
	* use only for drawing
	**/
	virtual void Draw();

	/**
	* use for update position, physics and etc.
	**/
	virtual void Update(float delta);
};
#endif GAMEOBJECT_H