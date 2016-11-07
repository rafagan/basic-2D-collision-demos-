/******************************************************************************
*
* COPYRIGHT Ráfagan S. de Abreu. ALL RIGHTS RESERVED.
*
* This software can be copied, stored and distributed without
* author's prior authorization. Just let him know and leave this header in this source code.
*
* This file was made available on https://github.com/rafagan/basic-2D-collision-demos/ and it is free
* to be restributed or used under Apache 2.0 license:
* http://www.apache.org/licenses/
*
******************************************************************************/

#include "collisions.h"

using namespace math;

int math::pointBoxCollisionCheck(const Point *point, const BoundingBox *box) {
	int left = point->x >= box->xy[0];
	int right = point->x <= (box->xy[0] + box->wh[0]);
	int top = point->y >= box->xy[1];
	int bottom = point->y <= (box->xy[1] + box->wh[1]);

	return (left && right && top && bottom);
}

int math::AABBCollisionCheck(const BoundingBox *box, const BoundingBox *other){
	float boxLeft, boxRight, boxTop, boxBottom;
	boxLeft = box->xy[0];
	boxRight = box->xy[0] + box->wh[0]; 
	boxTop = box->xy[1];
	boxBottom = box->xy[1] + box->wh[1];

	float otherLeft, otherRight, otherTop, otherBottom;
	otherLeft = other->xy[0];
	otherRight = other->xy[0] + other->wh[0]; 
	otherTop = other->xy[1];
	otherBottom = other->xy[1] + other->wh[1];

	if(boxLeft > otherRight)
		return 0;
	if(boxRight < otherLeft)
		return 0;
	if(boxTop > otherBottom)
		return 0;
	if(boxBottom < otherTop)
		return 0;

	return 1; 
}

int math::AABBInnerCollisionCheck(const BoundingBox *box, const BoundingBox *other){
	float boxLeft, boxRight, boxTop, boxBottom;
	boxLeft = box->xy[0];
	boxRight = box->xy[0] + box->wh[0];
	boxTop = box->xy[1];
	boxBottom = box->xy[1] + box->wh[1];

	float otherLeft, otherRight, otherTop, otherBottom;
	otherLeft = other->xy[0];
	otherRight = other->xy[0] + other->wh[0]; 
	otherTop = other->xy[1];
	otherBottom = other->xy[1] + other->wh[1];

	if(boxRight > otherLeft && boxLeft < otherRight)
		if(boxTop < otherBottom && boxBottom > otherTop)
			return 1;
	return 0; 
}

int math::circleCollisionCheck(const BoundingCircle *circle, const BoundingCircle *other) {
	Point distV;
	distV.x = circle->xy[0] - other->xy[0];
	distV.y = circle->xy[1] - other->xy[1];

	auto distSqr = distV.x * distV.x + distV.y * distV.y;
	auto sumRadius = (circle->radius * circle->radius + 2 * circle->radius * other->radius + other->radius * other->radius);
	return distSqr < sumRadius;
}

int math::circleBoxCollisionCheck(const BoundingBox *box, const BoundingCircle *circle) {
	Point point;
	float boxLeft, boxRight, boxTop, boxBottom;

	boxLeft = box->xy[0];
	boxRight = box->xy[0] + box->wh[0];
	boxTop = box->xy[1];
	boxBottom = box->xy[1] + box->wh[1];

	if(circle->xy[0] < boxLeft)
		point.x = boxLeft;
	else if(circle->xy[0] > boxRight)
		point.x = boxRight;
	else
		point.x = circle->xy[0];

	if(circle->xy[1] < boxTop)
		point.y = boxTop;
	else if(circle->xy[1] > boxBottom)
		point.y = boxBottom;
	else
		point.y = circle->xy[1];

	Point distV;
	distV.x = point.x - circle->xy[0];
	distV.y = point.y - circle->xy[1];
	auto distSqr = distV.x * distV.x + distV.y * distV.y; 

	return distSqr < circle->radius * circle->radius;
}

int math::AABBOffsetCollisionCheck(const BoundingBox *box, const BoundingBox *other) {
	Point offset;
	offset.x = other->xy[0] - box->xy[0];
	offset.y = other->xy[1] - box->xy[1];

	if(offset.x >= 0) {
		if(offset.x > box->wh[0])
			return 0;
	} else if(-offset.x > other->wh[0])
		return 0;

	if(offset.y >= 0) {
		if(offset.y > box->wh[1])
			return 0;
	} else if(-offset.y > other->wh[1])
		return 0;

	return 1;
}