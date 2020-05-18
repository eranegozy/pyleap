// ------------------------------
// 
// Copyright (c) 2020, Eran Egozy. All rights reserved.
// Released under GNU GPL version 3
//
// -------------------------------

#include "Leap.h"

#if defined(_MSC_VER)
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

using namespace Leap;

struct cFinger {
	int id;
	float pos[3];
};

struct cHand {
	int id;
	float palm_pos[3];
	cFinger fingers[5];
};

struct cFrame {
	bool valid;
	cHand hands[2];
};

struct cInfo {
	bool isServiceConnected;
	bool isConnected;
	bool hasFocus;
};

void copyFromVector(float* pos, const Vector& v) {
	pos[0] = v.x;
	pos[1] = v.y;
	pos[2] = v.z;
}



// some globals
Controller* gController = NULL;


extern "C" {

    // must call init() before calling any other functions
    EXPORT void init() {
        if (!gController)
            gController = new Controller();
    }

    // return basic connectivity info
	EXPORT void getInfo(cInfo* outInfo) {
        if (!gController) {
            printf("Error: Leap init() must be called first");
            return;
        }

    	outInfo->isServiceConnected = gController->isServiceConnected();
    	outInfo->isConnected = gController->isConnected();
    	outInfo->hasFocus = gController->hasFocus();
    }

    // return frame data.
	EXPORT void getFrame(cFrame* outFrame) {
        if (!gController) {
            printf("Error: Leap init() must be called first");
            return;
        }

    	Frame frame = gController->frame();
    	HandList hands = frame.hands();

    	outFrame->valid = true;
    	for(int h=0; h < 2; ++h) {
	    	Hand hand = hands[h];
    		cHand& outHand = outFrame->hands[h];

    		outHand.id = hand.id();
    		copyFromVector(outHand.palm_pos, hand.palmPosition());

    		FingerList fingers = hand.fingers();
    		for(int f=0; f < 5; ++f) {
    			cFinger& outFinger = outHand.fingers[f];
    			Finger finger = fingers[f];
    			outFinger.id = finger.id();
    			copyFromVector(outFinger.pos, finger.tipPosition());
    		}
    	}
    }

} // extern "C"

