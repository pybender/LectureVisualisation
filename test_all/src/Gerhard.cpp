#include "Gerhard.h"

void Gerhard::draw(ofxAudioVisualApp* app, vector<float>* drawBins, float threshold) {
    ofPushMatrix();
    ofPushStyle();

    int binSize = abs(app->endBin - app->startBin);
    for(int i = app->startBin, j = 0; j < binSize; i++, j++){
        ofColor col;
        if(drawBins->at(i) > threshold){
            col = app->getColor(i);
        }else{
            col = (0,0,0);
        }
        
        ofSetColor(col);

        float height;
//        if(symmetrical){
//            height = ofMap(i, app->startBin, binSize, 0, ofGetHeight()) + ofGetHeight()/2;
//            
//            height = ofGetHeight()/2 - ofMap(i, app->startBin, binSize, 0, ofGetHeight());
//            
////            if (col != ofColor::black){
////                col.setBrightness(gradientSampler->getBrightness(height));
////            }
//            
////            ofSetColor(col);
//            ofDrawCircle(x, height, 2);
//        }else{
            height = ofMap(i, app->startBin, binSize, 0, ofGetHeight());

            ofDrawCircle(x, height, 2);
//        }
    }
    
    ofPopStyle();
    ofPopMatrix();
    
    x += 1 * app->drawSpeed;
    if(x > ofGetWidth()){
        x = 0;
    }else if(x < 0){
        x = ofGetWidth();
    }
}

void Gerhard::reset(){
    x = 0;
}
