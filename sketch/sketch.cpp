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
    stroke(0, 255, 0);
    //translate($width / 2, $height / 2);
    fill(255, 0, 0);
    rect(0, 0, 50, 50);
    line(800, 0, 400, 400);
    line(800, 600, 400, 400);
}

void draw()
{
    background(255);
    rect($mouseX, $mouseY, 200, 200);
}
