//
//  sketch.cpp
//  Processing
//
//  Created by
//  Copyright © 2019  All rights reserved.
//

#include "lib/Processing.h"

void setup()
{
    size(800.0f, 600.0f);
    background(255);
    stroke(255, 0, 0);
    //translate($width / 2, $height / 2);
    fill(255, 0, 0);
    //noFill();
    //quad(0, 0, 100, 100, 100, 0, 0, 100);
    //rect(0, 0, 50, 50);
    bezier(100, 100, 200, 200, 400, 0, 400, 100);
    //scale(0.5);
    //line(800, 0, 400, 400);
    //curve(100, 0, 200, 200, 400, 200, 400, 800);
    noLoop();
}

void draw()
{
    background(255);
    rect($mouseX, $mouseY, 200, 200);
}

