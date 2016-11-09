#pragma once

#include <array>
#include "ofMain.h"
#include "../Math/Vector2D.h"
#include "../Math/Vector3D.h"

class ExColisao1_2 : public ofBaseApp {
	public:
		void setup() override;
		void update() override;
		void draw() override;

		void keyPressed(int key) override;
		void keyReleased(int key) override;
		void mouseMoved(int x, int y ) override;
		void mouseDragged(int x, int y, int button) override;
		void mousePressed(int x, int y, int button) override;
		void mouseReleased(int x, int y, int button) override;
		void mouseEntered(int x, int y) override;
		void mouseExited(int x, int y) override;
		void windowResized(int w, int h) override;
		void dragEvent(ofDragInfo dragInfo) override;
		void gotMessage(ofMessage msg) override;
		
	private:
		ofImage ufo;
		float ufoIndex;
		math::Vector2D ufoPos, ufoDirection, ufoVelocity, path;
};
