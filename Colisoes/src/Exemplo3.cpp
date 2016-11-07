#include "Exemplo3.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo3::setup(){
	step = 0;

	c.xy[0] = 300;
	c.xy[1] = 150;
	c.radius = 50;

	position.set(600, 200);
	b.wh[0] = 100;
	b.wh[1] = 200;

	velocity = Vector2D(50, 0);
}

//--------------------------------------------------------------
void Exemplo3::configureNextStep()
{
	if (step == 0) {
		velocity = Vector2D(100, 0);
		c.xy[0] = 150;
		c.xy[1] = 300;
		c.radius = 50;

		position.set(500, 300);
		b.wh[0] = 100;
		b.wh[1] = 200;

		step = 1;
	}
	else if (step == 1) {
		if (c.xy[0] > ofGetWidth())
			step = 2;
	}
	else if (step == 2) {
		c.xy[0] = 300;
		c.xy[1] = 200;
		c.radius = 50;

		position.set(300, 400);
		b.wh[0] = 200;
		b.wh[1] = 100;

		velocity = Vector2D(0, 100);

		step = 3;
	}
	else if (step == 3) {
		if (c.xy[1] > ofGetHeight())
			step = 4;
	}
	else if (step == 4) {
		std::exit(0);
	}
}

void Exemplo3::update(){
	configureNextStep();

	auto dt = ofGetLastFrameTime();

	c.xy[0] += velocity.x * dt;
	c.xy[1] += velocity.y * dt;
}

//--------------------------------------------------------------
void Exemplo3::draw(){
	ofSetBackgroundColor(0, 0, 0);

	b.xy[0] = position.x - b.wh[0] / 2;
	b.xy[1] = position.y - b.wh[1] / 2;
	cg::setColor(Vector3D(255, 255, 255));
	cg::drawBox(Vector2D(position.x, position.y), Vector2D(b.wh[0], b.wh[1]));

	circleBoxCollisionCheck(&b, &c) ?
		cg::setColor(Vector3D(255, 255, 0)) :
		cg::setColor(Vector3D(0, 255, 255));

	cg::drawCircle(Vector2D(c.xy[0], c.xy[1]), c.radius);
}

//--------------------------------------------------------------
void Exemplo3::keyPressed(int key){

}

//--------------------------------------------------------------
void Exemplo3::keyReleased(int key){

}

//--------------------------------------------------------------
void Exemplo3::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Exemplo3::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo3::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo3::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo3::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Exemplo3::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Exemplo3::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Exemplo3::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Exemplo3::dragEvent(ofDragInfo dragInfo){ 

}
