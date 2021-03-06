#pragma once

#include "ofMain.h"
#include "ofxAudioVisualApp.h"
#include "util_GradientSampler.h"

class Gerhard {
public:
    void setup();
    void draw(ofxAudioVisualApp* app, vector<float>* drawBins, float threshold);
    void reset();
    
    float x = 0;

    ofColor baseColor;
};
