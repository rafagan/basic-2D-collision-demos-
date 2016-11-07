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

	b1.wh[0] = b2.wh[0] = 100;
	b1.wh[1] = b2.wh[1] = 100;
	c1.radius = c2.radius = 100;

	b2.xy[0] = c2.xy[0] = 600;
	b2.xy[1] = c2.xy[1] = 300;

	pressedButton = 1;
}

//--------------------------------------------------------------
void Exemplo4::update(){
	switch (pressedButton) {
		case 1:
			b1.xy[0] = mouse.x;
			b1.xy[1] = mouse.y;

			//TODO: Fazer o teste com os outros algoritmos de bounding box implementados
			colors[0] = AABBOffsetCollisionCheck(&b1, &b2) ? color3 : color2;
			break;
		case 2:
			c1.xy[0] = mouse.x;
			c1.xy[1] = mouse.y;

			colors[0] = circleCollisionCheck(&c1, &c2) ? color3 : color2;
			break;
		case 3:
			c1.xy[0] = mouse.x;
			c1.xy[1] = mouse.y;

			colors[0] = circleBoxCollisionCheck(&b2, &c1) ? color3 : color2;
			break;
		case 4:
			Point p;
			p.x = mouse.x;
			p.y = mouse.y;

			colors[1] = pointBoxCollisionCheck(&p, &b2) ? color3 : color2;
			break;
	}
}

//--------------------------------------------------------------
void Exemplo4::draw(){
	ofSetBackgroundColor(0, 0, 0);

	switch (pressedButton) {
	case 1:
		cg::setColor(colors[1]);
		cg::drawBox(Vector2D(b2.xy[0], b2.xy[1]), Vector2D(b2.wh[0], b2.wh[1]));
		cg::setColor(colors[0]);
		cg::drawBox(Vector2D(b1.xy[0], b1.xy[1]), Vector2D(b1.wh[0], b1.wh[1]));
		break;
	case 2:
		cg::setColor(colors[1]);
		cg::drawCircle(Vector2D(c2.xy[0], c2.xy[1]), c2.radius);
		cg::setColor(colors[0]);
		cg::drawCircle(Vector2D(c1.xy[0], c1.xy[1]), c1.radius);
		break;
	case 3:
		cg::setColor(colors[1]);
		cg::drawCircle(Vector2D(c1.xy[0], c1.xy[1]), c1.radius);
		cg::setColor(colors[0]);
		cg::drawBox(Vector2D(b2.xy[0] + b2.wh[0] / 2, b2.xy[1] + b2.wh[1] / 2), Vector2D(b2.wh[0], b2.wh[1]));
		break;
	case 4:
		cg::setColor(colors[1]);
		cg::drawBox(Vector2D(b2.xy[0] + b2.wh[0] / 2, b2.xy[1] + b2.wh[1] / 2), Vector2D(b2.wh[0], b2.wh[1]));
		cg::setColor(colors[0]);
		cg::drawCircle(Vector2D(mouse.x, mouse.y), 1);
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
	mouse = Vector2D(x, ofGetHeight() - y);
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
