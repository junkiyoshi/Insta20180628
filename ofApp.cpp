#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(39);
	ofSetColor(239, 128);
	ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

}	

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);
	
	int start_radius = 100;
	int max_radius = 320;

	for (int deg = 0; deg < 360; deg += 2) {

		int half_radius = (max_radius - start_radius) * 0.5 + start_radius;
		ofPoint half_point = ofPoint(half_radius * cos(deg * DEG_TO_RAD), half_radius * sin(deg * DEG_TO_RAD));

		ofBeginShape();
		for (int radius = start_radius; radius <= max_radius; radius += 1) {

			ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
		
			float noise_deg = ofMap(ofNoise(point.x * 0.008, point.y * 0.008 + ofGetFrameNum() * 0.008), 0, 1, -25, 25);
			float deg_param = ofMap(half_point.distance(point), 0, (max_radius - start_radius) * 0.5, 1, 0);
			noise_deg *= deg_param; 

			point = ofPoint(ofPoint(radius * cos((deg + noise_deg) * DEG_TO_RAD), radius * sin((deg + noise_deg) * DEG_TO_RAD)));
			ofVertex(point);
		}
		ofEndShape();
	}
}

//========================================================================
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}