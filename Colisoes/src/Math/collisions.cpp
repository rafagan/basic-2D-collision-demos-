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

bool math::pointBoxCollisionCheck(const Point *point, const BoundingBox *box) {
	auto left = point->x >= box->xy[0];
	auto right = point->x <= (box->xy[0] + box->wh[0]);
	auto top = point->y >= box->xy[1];
	auto bottom = point->y <= (box->xy[1] + box->wh[1]);

	return (left && right && top && bottom);
}

bool math::AABBCollisionCheck(const BoundingBox *box, const BoundingBox *other){
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
		return false;
	if(boxRight < otherLeft)
		return false;
	if(boxTop > otherBottom)
		return false;
	if(boxBottom < otherTop)
		return false;

	return true; 
}

bool math::AABBInnerCollisionCheck(const BoundingBox *box, const BoundingBox *other){
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
			return true;
	return false;
}

bool math::circleCollisionCheck(const BoundingCircle *circle, const BoundingCircle *other) {
	Point distV;
	distV.x = circle->xy[0] - other->xy[0];
	distV.y = circle->xy[1] - other->xy[1];

	auto distSqr = distV.x * distV.x + distV.y * distV.y;
	auto sumRadius = (circle->radius * circle->radius + 2 * circle->radius * other->radius + other->radius * other->radius);
	return distSqr < sumRadius;
}

bool math::circleBoxCollisionCheck(const BoundingBox *box, const BoundingCircle *circle) {
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

bool math::AABBOffsetCollisionCheck(const BoundingBox *box, const BoundingBox *other) {
	Point offset;
	offset.x = other->xy[0] - box->xy[0];
	offset.y = other->xy[1] - box->xy[1];

	if(offset.x >= 0) {
		if(offset.x > box->wh[0])
			return false;
	} else if(-offset.x > other->wh[0])
		return false;

	if(offset.y >= 0) {
		if(offset.y > box->wh[1])
			return false;
	} else if(-offset.y > other->wh[1])
		return false;

	return true;
}