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
#include "GameObject.h"

#include <iostream>

using namespace std;

GameObject::GameObject(string name, int x, int y, int width, int height) {
	this->name = name;
	this->xPos = x;
	this->yPos = y;
	this->width = width;
	this->height = height;
	boundingBox = new AABB(x, y, width, height);
}

GameObject::GameObject(string name, AABB* aabb) {
	this->name = name;
	this->xPos = aabb->getX();
	this->yPos = aabb->getY();
	this->width = aabb->getWidth();
	this->height = aabb->getHeight();
	boundingBox = aabb;
}

GameObject::~GameObject() {
	delete boundingBox;
}

void GameObject::setTag(string tag) {
	this->tag = tag;
}

void GameObject::setPosX(int x) {
	this->xPos = x;
}

void GameObject::setPosY(int y) {
	this->yPos = y;
}

// коллизия
bool GameObject::checkCollision(GameObject* other) {
	return this->boundingBox->intersects(other->boundingBox);
}

void GameObject::onCollisionEvent(GameObject* gameObject) {
	// use override
	cout << "[" << getTag() << "] " << getName() << " Collision()" << endl;
}

// Вызывайте методы из движка игры
/**
* use only for drawing
**/
void GameObject::Draw() {
	// use override
	cout << "[" << getTag() << "] " << getName() << " Draw()" << endl;
}

/**
* use for update position, physics and etc.
**/
void GameObject::Update(float delta) {
	// use override
	cout << "[" << getTag() << "] " << getName() << " Update()" << endl;
}