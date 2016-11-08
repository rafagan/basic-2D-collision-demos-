#include "Exemplo4.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo4::setup(){
	ofHideCursor();

	color1 = Vector3D(255, 0, 0);
	color2 = Vector3D(0, 255, 0);
	color3 = Vector3D(255, 255, 0);
	
	colors[0] = color1;
	colors[1] = color2;

	b1.size = b2.size = Vector2D(100, 100);
	c1.radius = c2.radius = 100;
	b2.position = c2.position = Vector2D(600, 300);

	pressedButton = 1;
}

//--------------------------------------------------------------
void Exemplo4::update(){
	switch (pressedButton) {
		case 1:
			b1.position = mouse;
			colors[0] = //Testing all algorithms
				AABBOffsetCollisionCheck(&b1, &b2) && AABBInnerCollisionCheck(&b1, &b2) && AABBCollisionCheck(&b1, &b2)
				? color3 : color2;
			break;
		case 2:
			c1.position = mouse;
			colors[0] = circleCollisionCheck(&c1, &c2) ? color3 : color2;
			break;
		case 3:
			c1.position = mouse;
			colors[0] = circleBoxCollisionCheck(&b2, &c1) ? color3 : color2;
			break;
		case 4:
			colors[1] = pointBoxCollisionCheck(&mouse, &b2) ? color3 : color2;
			break;
	}
}

//--------------------------------------------------------------
void Exemplo4::draw(){
	ofSetBackgroundColor(0, 0, 0);

	switch (pressedButton) {
	case 1:
		cg::setColor(colors[1]);
		cg::drawBox(b2.position, b2.size);
		cg::setColor(colors[0]);
		cg::drawBox(b1.position, b1.size);
		break;
	case 2:
		cg::setColor(colors[1]);
		cg::drawCircle(c2.position, c2.radius);
		cg::setColor(colors[0]);
		cg::drawCircle(c1.position, c1.radius);
		break;
	case 3:
		cg::setColor(colors[1]);
		cg::drawCircle(c1.position, c1.radius);
		cg::setColor(colors[0]);
		cg::drawBox(b2.position + b2.size / 2, b2.size);
		break;
	case 4:
		cg::setColor(colors[1]);
		cg::drawBox(b2.position + b2.size / 2, b2.size);
		cg::setColor(colors[0]);
		cg::drawCircle(mouse, 1);
		break;
	}
}

//--------------------------------------------------------------
void Exemplo4::keyPressed(int key){
	if (isdigit(key))
		pressedButton = key - '0';
}

//--------------------------------------------------------------
void Exemplo4::keyReleased(int key){

}

//--------------------------------------------------------------
void Exemplo4::mouseMoved(int x, int y ){
	mouse.set(x, ofGetHeight() - y);
}

//--------------------------------------------------------------
void Exemplo4::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo4::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo4::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo4::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Exemplo4::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Exemplo4::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Exemplo4::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Exemplo4::dragEvent(ofDragInfo dragInfo){ 

}
