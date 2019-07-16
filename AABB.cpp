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
#include "AABB.h"

using namespace std;

// Axis-Aligned Bounding Box
// https://tutorialedge.net/gamedev/aabb-collision-detection-tutorial/
AABB::AABB(int x, int y, int width, int height) {
	this->xCoord = x;
	this->yCoord = y;
	this->width = width;
	this->height = height;
}

AABB::~AABB() {
}

void AABB::setX(int x) {
	this->xCoord = x;
}

void AABB::setY(int y) {
	this->yCoord = y;
}

void AABB::updatePos(int x, int y) {
	setX(x);
	setY(y);
}

bool AABB::intersects(AABB* a, AABB* b) {
	if (a->getX() <= b->getX() + b->getWidth() &&
		a->getX() + a->getWidth() >= b->getX() &&
		a->getY() <= b->getY() + b->getHeight() &&
		a->getY() + a->getHeight() >= b->getY())
	{
		return true;
	}
	return false;
}

bool AABB::intersects(AABB* other) {
	return intersects(this, other);
}
