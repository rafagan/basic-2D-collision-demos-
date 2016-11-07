#include "Exemplo2.h"
#include "DrawUtils.h"
#include "Math/collisions.h"
#include "Math/Vector2D.h"

using namespace math;

//--------------------------------------------------------------
void Exemplo2::setup(){
	c1.position.set(100, 200);
	c1.radius = 100;

	c2.position.set(600, 300);
	c2.radius = 50;

	velocity = Vector2D(100, 0);
}

//--------------------------------------------------------------
void Exemplo2::update(){
	auto dt = ofGetLastFrameTime();

	if (c1.xy[0] > ofGetWidth())
		std::exit(0);

	c1.position += velocity * dt;
}

//--------------------------------------------------------------
void Exemplo2::draw(){
	ofSetBackgroundColor(0, 0, 0);

	cg::setColor(Vector3D(255, 255, 255));
	cg::drawCircle(c2.position, c2.radius);

	circleCollisionCheck(&c1, &c2) ?
		cg::setColor(Vector3D(255, 255, 0)) :
		cg::setColor(Vector3D(0, 255, 255));

	cg::drawCircle(c1.position, c1.radius);
}

//--------------------------------------------------------------
void Exemplo2::keyPressed(int key){

}

//--------------------------------------------------------------
void Exemplo2::keyReleased(int key){

}

//--------------------------------------------------------------
void Exemplo2::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Exemplo2::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo2::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo2::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Exemplo2::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void Exemplo2::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void Exemplo2::windowResized(int w, int h){

}

//--------------------------------------------------------------
void Exemplo2::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void Exemplo2::dragEvent(ofDragInfo dragInfo){ 

}
