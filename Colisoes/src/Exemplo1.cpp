#include "Exemplo1.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo1::setup(){
	step = 0;
}

//--------------------------------------------------------------
void Exemplo1::configureNextStep()
{
	if (step == 0) {
		velocity = Vector2D(0, 200);
		
		rect1.position.set(300, 0);
		rect1.size.set(70, 100);

		rect2.position.set(300, 400);
		rect2.size.set(100, 100);

		step = 1;
	}
	else if (step == 1) {
		if (rect1.xy[1] > ofGetHeight())
			step = 2;
	}
	else if (step == 2) {
		velocity = Vector2D(200, 0);

		rect1.position.set(100, 200);
		rect1.size.set(100, 70);

		rect2.position.set(500, 200);
		rect2.size.set(100, 100);

		step = 3;
	}
	else if (step == 3) {
		if (rect1.xy[0] > ofGetWidth())
			step = 4;
	}
	else if (step == 4) {
		std::exit(0);
	}
}

void Exemplo1::update(){
	configureNextStep();
	
	auto dt = ofGetLastFrameTime();
	rect1.position += velocity * dt;
}

//--------------------------------------------------------------
void Exemplo1::draw(){
	ofSetBackgroundColor(0, 0, 0);

	cg::setColor(Vector3D(255, 255, 255));
	cg::drawBox(rect2.position, rect2.size);

	AABBCollisionCheck(&rect1, &rect2) ?
		cg::setColor(Vector3D(255, 255, 0)) :
		cg::setColor(Vector3D(0, 255, 255));

	cg::drawBox(rect1.position, rect1.size);
}

//--------------------------------------------------------------
void Exemplo1::keyPressed(int key){
	
}

//--------------------------------------------------------------
void Exemplo1::keyReleased(int key){

}

//--------------------------------------------------------------
void Exemplo1::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Exemplo1::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo1::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo1::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo1::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Exemplo1::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Exemplo1::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Exemplo1::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Exemplo1::dragEvent(ofDragInfo dragInfo){ 

}
