#include "ExColisao1_2.h"

#include "../Math/MathUtil.h"
#include "../Math/Vector2D.h"
#include "../DrawUtils.h"

using namespace math;
using namespace std;
using namespace cg;

inline Vector2D reflect2(const Vector2D& ray, const Vector2D& normal, float e = 1)
{
	return ray - (1 + e) * ray.dot(normal) * normal;
}

//--------------------------------------------------------------
void ExColisao1_2::setup() {
	ufo.load("ufo_1x6.png");
	ufoIndex = 0;
	ufoPos = Vector2D(ofGetWidth() / 2.0f, ofGetHeight() / 2.0f);

	auto destination = Vector2D::newBySizeAngle(1, toRadians(rand() % 360));
	ufoDirection = (destination - ufoPos).normalize();

	auto speed = 200.0f;
	ufoVelocity = ufoDirection * speed;
}

//--------------------------------------------------------------
void ExColisao1_2::update() {
	//Troca 1 frame a cada 0.125 segundos
	ufoIndex += ofGetLastFrameTime() * 8;

	ufoPos += (ufoVelocity * ofGetLastFrameTime());
	if (ufoPos.x > ofGetWidth() - 55 || ufoPos.x < 55) {
		if (ufoPos.x > ofGetWidth() - 55)
			ufoPos.x = ofGetWidth() - 60;
		else if (ufoPos.x < 55)
			ufoPos.x = 60;

		//ufoVelocity = reflect(ufoVelocity, Vector2D(1, 0));
		ufoVelocity = reflect2(ufoVelocity, Vector2D(1, 0), 0.5);
		ufoDirection = normalize(ufoVelocity);
	}

	if (ufoPos.y > ofGetHeight() - 66 || ufoPos.y < 66) {
		if (ufoPos.y > ofGetHeight() - 66)
			ufoPos.y = ofGetHeight() - 70;
		else if (ufoPos.y < 66)
			ufoPos.y = 70;

		//ufoVelocity = reflect(ufoVelocity, Vector2D(0, 1));
		ufoVelocity = reflect2(ufoVelocity, Vector2D(0, 1), 1.1);
		ufoDirection = normalize(ufoVelocity);
	}
}

//--------------------------------------------------------------
void ExColisao1_2::draw() {
	ofSetBackgroundColor(0, 0, 0);
	setColor(Vector3D(255, 255, 255));
	
	drawImage(ufoPos, Vector2D(100, 100), ufo, ufoIndex);

	setColor(Vector3D(255.0f, 0, 0));
	drawLine(ufoPos, ufoPos + ufoDirection * 50);

	setColor(Vector3D(255, 255, 255));
}

//--------------------------------------------------------------
void ExColisao1_2::keyPressed(int key) {

}

//--------------------------------------------------------------
void ExColisao1_2::keyReleased(int key) {

}

//--------------------------------------------------------------
void ExColisao1_2::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ExColisao1_2::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ExColisao1_2::mousePressed(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ExColisao1_2::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ExColisao1_2::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ExColisao1_2::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ExColisao1_2::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ExColisao1_2::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ExColisao1_2::dragEvent(ofDragInfo dragInfo) {

}