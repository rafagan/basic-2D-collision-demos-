#include "Exemplo3.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo3::setup(){
	step = 0;

	c.position.set(300, 150);

	position.set(600, 200);
	b.size.set(100, 200);

	velocity = Vector2D(50, 0);
}

//--------------------------------------------------------------
void Exemplo3::configureNextStep()
{
	if (step == 0) {
		velocity = Vector2D(100, 0);

		c = BoundingCircle(150, 300, 50);

		position.set(500, 300);
		b.size.set(100, 200);

		step = 1;
	}
	else if (step == 1) {
		if (c.xy[0] > ofGetWidth())
			step = 2;
	}
	else if (step == 2) {
		velocity = Vector2D(0, 100);

		c = BoundingCircle(300, 200, 50);

		position.set(300, 400);
		b.size.set(200, 100);

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
	c.position += velocity * dt;
}

//--------------------------------------------------------------
void Exemplo3::draw(){
	ofSetBackgroundColor(0, 0, 0);

	b.position = position - b.size / 2; //Algorithm considerer top left corner
	cg::setColor(Vector3D(255, 255, 255));
	cg::drawBox(position, b.size);

	circleBoxCollisionCheck(&b, &c) ?
		cg::setColor(Vector3D(255, 255, 0)) :
		cg::setColor(Vector3D(0, 255, 255));

	cg::drawCircle(c.position, c.radius);
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
