//
//  Processing.hpp
//  Processing
//
//  Created by 中国美术学院 陈天翼(Apollo Chen) on 1/28/19.
//  Copyright © 2019 Apollo Chen. All rights reserved.
//


#ifndef Processing_hpp
#define Processing_hpp


#include <string>
#include <vector>
#include <array>
#include "OpenGLAgent.h"

//not in Processing
/*
 * Name: resizeWindow
 * Params: width - new Window's width
 *        height - new Window's height
 * Description: Resize Window(depend on platform)
 */
void resizeWindow(int width, int height);

//From Processing

//conflict with windows POINTS(tagPOINTS)

//VK_
#if defined(_WIN32) or defined(_WIN64)
#define weak_import weak
#define ALT
#define CONTROL VK_CONTROL
#define SHIFT VK_SHIFT
#define BACKSPACE VK_BACK
#define TAB VK_TAB
#define ENTER VK_RETURN
#define RETURN
#define ESC VK_ESCAPE
//#define DELETE VK_DELETE
#define UP VK_UP
#define DOWN VK_DOWN
#elif defined(__APPLE__)
#define ALT
#define CONTROL
#define SHIFT
#define BACKSPACE
#define TAB 0x907
#define ENTER 0x90a
#define RETURN 0x90d
#define ESC 0x933
#define DELETE 0x934
#define UP NSUpArrowFunctionKey
#define DOWN NSDownArrowFunctionKey
#endif

//Enum from Processing
enum _penum {
    //renderer
    P2D = 301,
    P3D,
    FX2D,
    PDF,
    SVG,
    //mode for arc
    PIE,
    OPEN,
    CHORD,
    //mode for rect, ellipse
    CENTER = 311,
    RADIUS,
    CORNER,
    CORNERS,
    //cap
    SQUARE,
    PROJECT,
    ROUND,
    //join
    MITER,
    BEVEL,
    /*ROUND*/
    //kind
#ifndef _WINDEF_H
    POINTS = 321,
#endif
    LINES = 322,
    TRIANGLES,
    TRIANGLE_FAN,
    TRIANGLE_STRIP,
    QUADS,
    QUAD_STRIP,
    //mode for endShape
    CLOSE = 331,
    //mode for shapes
    /*CORNER,*/
    /*CORNERS,*/
    /*CENTER,*/
    //mouseButton
    LEFT,
    RIGHT,
    /*CENTER,*/
    //mode for color
    RGB,
    HSB,
    //format for image
    /*RGB,*/
    ARGB ,
    ALPHA,
    //kind for PImage filter
    THRESHOLD = 341,
    GRAY,
#ifndef _WINGDI_H
    OPAQUE = 343,
#endif
    INVERT = 344,
    POSTERIZE,
    BLUR,
    ERODE,
    DILATE,
    //mode for PImage blend
    BLEND = 351,
    ADD,
    SUBTRACT,
    LIGHTEST,
    DARKEST,
#ifndef _WINUSER_H
    DIFFERENCE = 356,
#endif
    EXCLUSION = 357,
    MULTIPLY,
    SCREEN,
    OVERLAY,
    HARD_LIGHT,
    SOFT_LIGHT,
    DODGE,
    BURN,
    //made for image
    /*CORNER,*/
    /*CORNERS,*/
    /*CENTER,*/
    //mode for texture
    IMAGE,
    NORMAL,
    //wrap for texture
    CLAMP,
    REPEAT,
    //mode for pixel blend
    /*BLEND,*/
    /*ADD,*/
    /*SUBTRACT,*/
    /*LIGHTEST,*/
    /*DARKEST,*/
    /*DIFFERENCE,*/
    /*EXCLUSION,*/
    /*MULTIPLY,*/
    /*SCREEN,*/
    /*OVERLAY,*/
    /*HARD_LIGHT,*/
    /*SOFT_LIGHT,*/
    /*DODGE,*/
    /*BURN,*/
    //kind for shader
    /*POINTS,*/
    /*LINES,*/
    /*TRIANGLES,*/
    //text align
    /*LEFT,*/
    /*CENTER,*/
    /*RIGHT,*/
    TOP,
    BOTTOM,
    /*CENTER,*/
    BASELINE,
    //mode for text
    MODEL,
    SHAPE,
    //key
    CODED,
};

//Processing Type
#define colorType unsigned int

//inner members for Processing
//for loop
extern bool $loop;

//for Color Mode
extern _penum $colorMode;
extern float $colorMax1;
extern float $colorMax2;
extern float $colorMax3;
extern float $colorMaxA;

//for Color
extern colorType $fill;
extern colorType $stroke;
extern float $strokeWight;

/*
 Name
 PVector
 Examples
 PVector v1, v2;

 void setup() {
 noLoop();
 v1 = new PVector(40, 20);
 v2 = new PVector(25, 50);
 }

 void draw() {
 ellipse(v1.x, v1.y, 12, 12);
 ellipse(v2.x, v2.y, 12, 12);
 v2.add(v1);
 ellipse(v2.x, v2.y, 24, 24);
 }
 Description    A class to describe a two or three dimensional vector, specifically a Euclidean (also known as geometric) vector. A vector is an entity that has both magnitude and direction. The datatype, however, stores the components of the vector (x,y for 2D, and x,y,z for 3D). The magnitude and direction can be accessed via the methods mag() and heading().

 In many of the Processing examples, you will see PVector used to describe a position, velocity, or acceleration. For example, if you consider a rectangle moving across the screen, at any given instant it has a position (a vector that points from the origin to its location), a velocity (the rate at which the object's position changes per time unit, expressed as a vector), and acceleration (the rate at which the object's velocity changes per time unit, expressed as a vector). Since vectors represent groupings of values, we cannot simply use traditional addition/multiplication/etc. Instead, we'll need to do some "vector" math, which is made easy by the methods inside the PVector class.
 Fields
 x    The x component of the vector
 y    The y component of the vector
 z    The z component of the vector
 Methods
 set()    Set the components of the vector
 random2D()    Make a new 2D unit vector with a random direction.
 random3D()    Make a new 3D unit vector with a random direction.
 fromAngle()    Make a new 2D unit vector from an angle
 copy()    Get a copy of the vector
 mag()    Calculate the magnitude of the vector
 magSq()    Calculate the magnitude of the vector, squared
 add()    Adds x, y, and z components to a vector, one vector to another, or two independent vectors
 sub()    Subtract x, y, and z components from a vector, one vector from another, or two independent vectors
 mult()    Multiply a vector by a scalar
 div()    Divide a vector by a scalar
 dist()    Calculate the distance between two points
 dot()    Calculate the dot product of two vectors
 cross()    Calculate and return the cross product
 normalize()    Normalize the vector to a length of 1
 limit()    Limit the magnitude of the vector
 setMag()    Set the magnitude of the vector
 heading()    Calculate the angle of rotation for this vector
 rotate()    Rotate the vector by an angle (2D only)
 lerp()    Linear interpolate the vector to another vector
 angleBetween()    Calculate and return the angle between two vectors
 array()    Return a representation of the vector as a float array
 Constructor
 PVector()
 PVector(x, y, z)
 PVector(x, y)
 Parameters
 x    float: the x coordinate.
 y    float: the y coordinate.
 z    float: the z coordinate.
 */
class PVector {
public:
    //Fields
    /*
     Class
     PVector

     Name
     x
     Examples
     PVector v;

     void setup() {
     size(100, 100);
     v = new PVector(20.0, 30.0, 40.0);
     println(v.x);  // Prints "20.0"
     println(v.y);  // Prints "30.0"
     println(v.z);  // Prints "40.0"
     v.x = 50.0;
     println(v.x);  // Prints "50.0"
     }
     Description    The x component of the vector. This field (variable) can be used to both get and set the value (see above example.)
     Syntax
     .x
     Parameters
     PVector:
     */
    float x;    //The x component of the vector

    /*
     Class
     PVector

     Name
     y
     Examples
     PVector v;

     void setup() {
     size(100, 100);
     v = new PVector(20.0, 30.0, 40.0);
     println(v.x);  // Prints "20.0"
     println(v.y);  // Prints "30.0"
     println(v.z);  // Prints "40.0"
     v.y = 50.0;
     println(v.y);  // Prints "50.0"
     }
     Description    The y component of the vector. This field (variable) can be used to both get and set the value (see above example.)
     Syntax
     .y
     Parameters
     PVector:
     */
    float y;    //The y component of the vector

    /*
     Class
     PVector

     Name
     z
     Examples
     PVector v;

     void setup() {
     size(100, 100);
     v = new PVector(20.0, 30.0, 40.0);
     println(v.x);  // Prints "20.0"
     println(v.y);  // Prints "30.0"
     println(v.z);  // Prints "40.0"
     v.z = 50.0;
     println(v.z);  // Prints "50.0"
     }
     Description    The z component of the vector. This field (variable) can be used to both get and set the value (see above example.)
     Syntax
     .z
     Parameters
     PVector:
     */
    float z;    //The z component of the vector

    //Methods
    /*
     Class
     PVector

     Name
     set()
     Examples
     PVector v;

     void setup() {
     size(100, 100);
     v = new PVector(0.0, 0.0, 0.0);
     v.set(20.0, 30.0, 40.0);
     println(v.x);  // Prints "20.0"
     println(v.y);  // Prints "30.0"
     println(v.z);  // Prints "40.0"
     }
     PVector v1, v2;

     void setup() {
     size(100, 100);
     v1 = new PVector(20.0, 30.0, 40.0);
     v2 = new PVector(0.0, 0.0, 0.0);
     v2.set(v1);
     println(v2.x);  // Prints "20.0"
     println(v2.y);  // Prints "30.0"
     println(v2.z);  // Prints "40.0"
     }
     PVector v;
     float[] vvv = { 20.0, 30.0, 40.0 };

     void setup() {
     size(100, 100);
     v = new PVector(0.0, 0.0, 0.0);
     v.set(vvv);
     println(v.x);  // Prints "20.0"
     println(v.y);  // Prints "30.0"
     println(v.z);  // Prints "40.0"
     }
     Description    Sets the x, y, and z component of the vector using three separate variables, the data from a PVector, or the values from a float array.
     Syntax
     .set(x, y, z)
     .set(x, y)
     .set(v)
     .set(source)
     Parameters
     x    float: the x component of the vector
     y    float: the y component of the vector
     z    float: the z component of the vector
     x    float: the x component of the vector
     y    float: the y component of the vector
     v    PVector: any variable of type PVector
     source    float[]: array to copy from
     Returns    PVector
     */
    PVector set(float x, float y, float z);    //Set the components of the vector
    PVector set(float x, float y);    //Set the components of the vector
    PVector set(PVector v);    //Set the components of the vector
    PVector set(float source[]);    //Set the components of the vector

    /*
     Class
     PVector

     Name
     random2D()
     Examples
     PVector v;

     void setup() {
     v = PVector.random2D();
     println(v);
     // May print something like:
     // [ -0.75006354, -0.6613658, 0.0 ] or
     // [ 0.13742635, 0.990512, 0.0 ] or
     // [ -0.9456181, -0.32527903, 0.0 ]
     }
     Description    Returns a new 2D unit vector with a random direction. If you pass in this as an argument, it will use the PApplet's random number generator.
     Syntax
     .random2D()
     .random2D(parent)
     .random2D(target)
     .random2D(target, parent)
     Parameters
     parent    PApplet: current PApplet instance
     target    PVector: the target vector (if null, a new vector will be created)
     Returns    PVector
     Related    random3D()
     */
    static PVector random2D();    //Make a new 2D unit vector with a random direction.
    //static PVector random2D(PApplet parent);    //Make a new 2D unit vector with a random direction.
    static PVector random2D(PVector target);    //Make a new 2D unit vector with a random direction.
    //static PVector random2D(PVector target, PApplet parent);    //Make a new 2D unit vector with a random direction.

    /*
     Class
     PVector

     Name
     random3D()
     Examples
     PVector v;

     void setup() {
     v = PVector.random3D();
     println(v);
     // May print something like:
     // [ 0.61554617, -0.51195765, 0.599168 ] or
     // [ -0.4695841, -0.14366731, -0.8711202 ] or
     // [ 0.6091097, -0.22805278, -0.7595902 ]
     }
     Description    Returns a new 3D unit vector with a random direction. If you pass in this as an argument, it will use the PApplet's random number generator.
     Syntax
     .random3D()
     .random3D(parent)
     .random3D(target)
     .random3D(target, parent)
     Parameters
     parent    PApplet: current PApplet instance
     target    PVector: the target vector (if null, a new vector will be created)
     Returns    PVector
     Related    random2D()
     */
    static PVector random3D();    //Make a new 3D unit vector with a random direction.
    //static PVector random3D(PApplet parent);    //Make a new 3D unit vector with a random direction.
    static PVector random3D(PVector target);    //Make a new 3D unit vector with a random direction.
    //static PVector random3D(PVector target, PApplet parent);    //Make a new 3D unit vector with a random direction.

    /*
     Class
     PVector

     Name
     fromAngle()
     Examples
     PVector v;

     void setup() {
     v = PVector.fromAngle(0.01);
     println(v);  // Prints "[ 0.99995, 0.009999833, 0.0 ]"
     }
     Description    Calculates and returns a new 2D unit vector from the specified angle value (in radians).
     Syntax
     .fromAngle(angle)
     .fromAngle(angle, target)
     Parameters
     angle    float: the angle in radians
     target    PVector: the target vector (if null, a new vector will be created)
     Returns    PVector
     */
    PVector fromAngle(float angle);    //Make a new 2D unit vector from an angle
    PVector fromAngle(float angle, PVector target);    //Make a new 2D unit vector from an angle

    /*
     Class
     PVector

     Name
     copy()
     Examples
     PVector v1, v2;

     void setup() {
     size(100, 100);
     v1 = new PVector(20.0, 30.0, 40.0);
     v2 = new PVector();
     v2 = v1.copy();
     println(v2.x);  // Prints "20.0"
     println(v2.y);  // Prints "30.0"
     println(v2.z);  // Prints "40.0"
     }
     Description    Copies the components of the vector and returns the result as a PVector.
     Syntax
     .copy()
     Returns    PVector
     */
    PVector copy();    //Get a copy of the vector

    /*
     Class
     PVector

     Name
     mag()
     Examples
     PVector v;

     void setup() {
     size(100, 100);
     v = new PVector(20.0, 30.0, 40.0);
     float m = v.mag();
     println(m);  // Prints "53.851646"
     }
     Description    Calculates the magnitude (length) of the vector and returns the result as a float (this is simply the equation sqrt(x*x + y*y + z*z).)
     Syntax
     .mag()
     Returns    float
     Related    magSq()
     */
    float mag();    //Calculate the magnitude of the vector

    /*
     Class
     PVector

     Name
     magSq()
     Examples
     PVector v;

     void setup() {
     v = new PVector(20.0, 30.0, 40.0);
     float m = v.magSq();
     println(m);  // Prints "2900.0"
     }
     Description    Calculates the magnitude (length) of the vector, squared. This method is often used to improve performance since, unlike mag(), it does not require a sqrt() operation.
     Syntax
     .magSq()
     Returns    float
     Related    mag()
     */
    float magSq();    //Calculate the magnitude of the vector, squared

    /*
     Class
     PVector

     Name
     add()
     Examples
     PVector v1, v2;

     void setup() {
     noLoop();
     v1 = new PVector(40, 20, 0);
     v2 = new PVector(25, 50, 0);
     }

     void draw() {
     ellipse(v1.x, v1.y, 12, 12);
     ellipse(v2.x, v2.y, 12, 12);
     v2.add(v1);
     ellipse(v2.x, v2.y, 24, 24);
     }
     PVector v;

     void setup() {
     noLoop();
     v = new PVector(40, 20, 0);
     }

     void draw() {
     ellipse(v.x, v.y, 12, 12);
     ellipse(25, 50, 12, 12);
     v.add(25, 50, 0);
     ellipse(v.x, v.y, 24, 24);
     }
     PVector v1, v2;

     void setup() {
     noLoop();
     v1 = new PVector(40, 20, 0);
     v2 = new PVector(25, 50, 0);
     }

     void draw() {
     ellipse(v1.x, v1.y, 12, 12);
     ellipse(v2.x, v2.y, 12, 12);
     PVector v3 = PVector.add(v1, v2);
     ellipse(v3.x, v3.y, 24, 24);
     }
     Description    Adds x, y, and z components to a vector, adds one vector to another, or adds two independent vectors together. The version of the method that adds two vectors together is a static method and returns a new PVector, the others act directly on the vector itself. See the examples for more context.
     Syntax
     .add(v)
     .add(x, y)
     .add(x, y, z)
     .add(v1, v2)
     .add(v1, v2, target)
     Parameters
     v    PVector: the vector to be added
     x    float: x component of the vector
     y    float: y component of the vector
     z    float: z component of the vector
     v1    PVector: a vector
     v2    PVector: another vector
     target    PVector: the target vector (if null, a new vector will be created)
     Returns    PVector
     */
    PVector add(PVector v);    //Adds x, y, and z components to a vector, one vector to another, or two independent vectors
    PVector add(float x, float y);    //Adds x, y, and z components to a vector, one vector to another, or two independent vectors
    PVector add(float x, float y, float z);    //Adds x, y, and z components to a vector, one vector to another, or two independent vectors
    PVector add(PVector v1, PVector v2);    //Adds x, y, and z components to a vector, one vector to another, or two independent vectors
    PVector add(PVector v1, PVector v2, PVector target);    //Adds x, y, and z components to a vector, one vector to another, or two independent vectors

    /*
     Class
     PVector

     Name
     sub()
     Examples
     PVector v1, v2;

     void setup() {
     noLoop();
     v1 = new PVector(40, 20, 0);
     v2 = new PVector(65, 70, 0);
     }

     void draw() {
     ellipse(v1.x, v1.y, 12, 12);
     ellipse(v2.x, v2.y, 12, 12);
     v2.sub(v1);
     ellipse(v2.x, v2.y, 24, 24);
     }
     PVector v;

     void setup() {
     noLoop();
     v = new PVector(65, 70, 0);
     }

     void draw() {
     ellipse(v.x, v.y, 12, 12);
     ellipse(40, 20, 12, 12);
     v.sub(40, 20, 0);
     ellipse(v.x, v.y, 24, 24);
     }
     PVector v1, v2;

     void setup() {
     noLoop();
     v1 = new PVector(65, 70, 0);
     v2 = new PVector(40, 20, 0);
     }

     void draw() {
     ellipse(v1.x, v1.y, 12, 12);
     ellipse(v2.x, v2.y, 12, 12);
     PVector v3 = PVector.sub(v1, v2);
     ellipse(v3.x, v3.y, 24, 24);
     }
     Description    Subtracts x, y, and z components from a vector, subtracts one vector from another, or subtracts two independent vectors. The version of the method that substracts two vectors is a static method and returns a PVector, the others act directly on the vector. See the examples for more context. In all cases, the second vector (v2) is subtracted from the first (v1), resulting in v1-v2.
     Syntax
     .sub(v)
     .sub(x, y)
     .sub(x, y, z)
     .sub(v1, v2)
     .sub(v1, v2, target)
     Parameters
     v    PVector: any variable of type PVector
     x    float: the x component of the vector
     y    float: the y component of the vector
     z    float: the z component of the vector
     v1    PVector: the x, y, and z components of a PVector object
     v2    PVector: the x, y, and z components of a PVector object
     target    PVector: PVector in which to store the result
     Returns    PVector
     */
    PVector sub(PVector v);    //Subtract x, y, and z components from a vector, one vector from another, or two independent vectors
    PVector sub(float x, float y);    //Subtract x, y, and z components from a vector, one vector from another, or two independent vectors
    PVector sub(float x, float y, float z);    //Subtract x, y, and z components from a vector, one vector from another, or two independent vectors
    PVector sub(PVector v1, PVector v2);    //Subtract x, y, and z components from a vector, one vector from another, or two independent vectors
    PVector sub(PVector v1, PVector v2, PVector target);    //Subtract x, y, and z components from a vector, one vector from another, or two independent vectors

    /*
     Class
     PVector

     Name
     mult()
     Examples
     PVector v;

     void setup() {
     noLoop();
     v = new PVector(5, 10, 0);
     }

     void draw() {
     ellipse(v.x, v.y, 12, 12);
     v.mult(6);
     ellipse(v.x, v.y, 24, 24);
     }
     PVector v1;

     void setup() {
     noLoop();
     v1 = new PVector(5, 10, 0);
     }

     void draw() {
     ellipse(v1.x, v1.y, 12, 12);
     PVector v2 = PVector.mult(v1, 6);
     ellipse(v2.x, v2.y, 24, 24);
     }
     Description    Multiplies a vector by a scalar. The version of the method that uses a float acts directly on the vector upon which it is called (as in the first example above). The versions that receive both a PVector and a float as arguments are static methods, and each returns a new PVector that is the result of the multiplication operation. Both examples above produce the same visual output.
     Syntax
     .mult(n)
     .mult(v, n)
     .mult(v, n, target)
     Parameters
     n    float: the number to multiply with the vector
     v    PVector: the vector to multiply by the scalar
     target    PVector: PVector in which to store the result
     Returns    PVector
     */
    PVector mult(float n);    //Multiply a vector by a scalar
    PVector mult(PVector v, float n);    //Multiply a vector by a scalar
    PVector mult(PVector v, float n, PVector target);    //Multiply a vector by a scalar

    /*
     Class
     PVector

     Name
     div()
     Examples
     PVector v;

     void setup() {
     noLoop();
     v = new PVector(30, 60, 0);
     }

     void draw() {
     ellipse(v.x, v.y, 12, 12);
     v.div(6);
     ellipse(v.x, v.y, 24, 24);
     }
     PVector v1;

     void setup() {
     noLoop();
     v1 = new PVector(30, 60, 0);
     }

     void draw() {
     ellipse(v1.x, v1.y, 12, 12);
     PVector v2 = PVector.div(v1, 6);
     ellipse(v2.x, v2.y, 24, 24);
     }
     Description    Divides a vector by a scalar. The version of the method that uses a float acts directly on the vector upon which it is called (as in the first example above). The version that receives both a PVector and a float as arguments is a static methods, and returns a new PVector that is the result of the division operation. Both examples above produce the same visual output.
     Syntax
     .div(n)
     .div(v, n)
     .div(v, n, target)
     Parameters
     n    float: the number by which to divide the vector
     v    PVector: the vector to divide by the scalar
     target    PVector: PVector in which to store the result
     Returns    PVector
     */
    PVector div(float n);    //Divide a vector by a scalar
    PVector div(PVector v, float n);    //Divide a vector by a scalar
    PVector div(PVector v, float n, PVector target);    //Divide a vector by a scalar

    /*
     Class
     PVector

     Name
     dist()
     Examples
     PVector  v1 = new PVector(10, 20, 0);
     PVector  v2 = new PVector(60, 80, 0);
     float d = v1.dist(v2);
     println(d);  // Prints "78.10249"
     PVector  v1 = new PVector(10, 20, 0);
     PVector  v2 = new PVector(60, 80, 0);
     float d = PVector.dist(v1, v2);
     println(d);  // Prints "78.10249"
     Description    Calculates the Euclidean distance between two points (considering a point as a vector object).
     Syntax
     .dist(v)
     .dist(v1, v2)
     Parameters
     v    PVector: the x, y, and z coordinates of a PVector
     v1    PVector: any variable of type PVector
     v2    PVector: any variable of type PVector
     Returns    float
     */
    float dist(PVector v);    //Calculate the distance between two points
    float dist(PVector v1, PVector v2);    //Calculate the distance between two points

    /*
     Class
     PVector

     Name
     dot()
     Examples
     PVector  v = new PVector(10, 20, 0);
     float d = v.dot(60, 80, 0);
     println(d);  // Prints "2200.0"
     PVector  v1 = new PVector(10, 20, 0);
     PVector  v2 = new PVector(60, 80, 0);
     float d = v1.dot(v2);
     println(d);  // Prints "2200.0"
     Description    Calculates the dot product of two vectors.
     Syntax
     .dot(v)
     .dot(x, y, z)
     .dot(v1, v2)
     Parameters
     v    PVector: any variable of type PVector
     x    float: x component of the vector
     y    float: y component of the vector
     z    float: z component of the vector
     v1    PVector: any variable of type PVector
     v2    PVector: any variable of type PVector
     Returns    float
     */
    float dot(PVector v);    //Calculate the dot product of two vectors
    float dot(float x, float y, float z);    //Calculate the dot product of two vectors
    float dot(PVector v1, PVector v2);    //Calculate the dot product of two vectors

    /*
     Class
     PVector

     Name
     cross()
     Examples
     PVector v1 = new PVector(10, 20, 2);
     PVector v2 = new PVector(60, 80, 6);
     PVector v3 = v1.cross(v2);
     println(v3);  // Prints "[ -40.0, 60.0, -400.0 ]"
     Description    Calculates and returns a vector composed of the cross product between two vectors.
     Syntax
     .cross(v)
     .cross(v, target)
     .cross(v1, v2, target)
     Parameters
     v    PVector: the vector to calculate the cross product
     v    PVector: any variable of type PVector
     target    PVector: PVector to store the result
     v1    PVector: any variable of type PVector
     v2    PVector: any variable of type PVector
     target    PVector: PVector to store the result
     Returns    PVector
     */
    PVector cross(PVector v);    //Calculate and return the cross product
    PVector cross(PVector v, PVector target);    //Calculate and return the cross product
    PVector cross(PVector v1, PVector v2, PVector target);    //Calculate and return the cross product

    /*
     Class
     PVector

     Name
     normalize()
     Examples
     PVector v = new PVector(10, 20, 2);
     v.normalize();
     println(v);  // Prints "[ 0.4454354, 0.8908708, 0.089087084 ]"
     Description    Normalize the vector to length 1 (make it a unit vector).
     Syntax
     .normalize()
     .normalize(target)
     Parameters
     target    PVector: Set to null to create a new vector
     Returns    PVector
     */
    PVector normalize();    //Normalize the vector to a length of 1
    PVector normalize(PVector target);    //Normalize the vector to a length of 1

    /*
     Class
     PVector

     Name
     limit()
     Examples
     PVector v = new PVector(10, 20, 2);
     v.limit(5);
     println(v);  // Prints "[ 2.2271771, 4.4543543, 0.4454354 ]"
     Description    Limit the magnitude of this vector to the value used for the max parameter.
     Syntax
     .limit(max)
     Parameters
     max    float: the maximum magnitude for the vector
     Returns    PVector
     */
    PVector limit(float max);    //Limit the magnitude of the vector

    /*
     Class
     PVector

     Name
     setMag()
     Examples
     PVector v = new PVector(3, 4, 0);
     v.setMag(10);
     println(v);  // Prints "[ 6.0, 8.0, 0.0 ]"
     Description    Set the magnitude of this vector to the value used for the len parameter.
     Syntax
     .setMag(len)
     .setMag(target, len)
     Parameters
     len    float: the new length for this vector
     target    PVector: Set to null to create a new vector
     len    float: the new length for the new vector
     Returns    PVector
     */
    PVector setMag(float len);    //Set the magnitude of the vector
    PVector setMag(PVector target, float len);    //Set the magnitude of the vector

    /*
     Class
     PVector

     Name
     heading()
     Examples
     PVector v;

     void setup() {
     v = new PVector(10.0, 20.0);
     println(v.heading());  // Prints "1.1071488"
     }
     Description    Calculates the angle of rotation for a vector (2D vectors only).
     Syntax
     .heading()
     Returns    float
     */
    float heading();    //Calculate the angle of rotation for this vector

    /*
     Class
     PVector

     Name
     rotate()
     Examples
     PVector v;

     void setup() {
     v = new PVector(10.0, 20.0);
     println(v);  // Prints "[ 10.0, 20.0, 0.0 ]"
     v.rotate(HALF_PI);
     println(v);  // Prints "[ -20.0, 9.999999, 0.0 ]"
     }
     Description    Rotates a vector by the specified angle (2D vectors only), while maintaining the same magnitude.
     Syntax
     .rotate(theta)
     Parameters
     theta    float: the angle of rotation
     Returns    PVector
     */
    PVector rotate(float theta);    //Rotate the vector by an angle (2D only)

    /*
     Class
     PVector

     Name
     lerp()
     Examples
     // Non-static (lerp on a specific vector)

     PVector current;
     PVector target;

     void setup() {
     current = new PVector(0.0, 0.0);
     target = new PVector(100.0, 100.0);
     current.lerp(target, 0.5);
     println(current);  // Prints "[ 50.0, 50.0, 0.0 ]"
     }
     // Static (return a new vector)

     PVector start;
     PVector end;
     PVector middle;

     void setup() {
     start = new PVector(0.0, 0.0);
     end = new PVector(100.0, 100.0);
     middle = PVector.lerp(start, end, 0.5);
     println(middle);  // Prints "[ 50.0, 50.0, 0.0 ]"
     }
     // Non-static (lerp on a specific vector)

     PVector v;

     void setup() {
     v = new PVector(0.0, 0.0);
     }

     void draw() {
     v.lerp(mouseX, mouseY, 0.0, 0.1);
     ellipse(v.x, v.y, 20, 20);
     }
     Description    Calculates linear interpolation from one vector to another vector. (Just like regular lerp(), but for vectors.)

     Note that there is one static version of this method, and two non-static versions. The static version, lerp(v1, v2, amt) is given the two vectors to interpolate and returns a new PVector object. The static version is used by referencing the PVector class directly. (See the middle example above.) The non-static versions, lerp(v, amt) and lerp(x, y, z, amt), do not create a new PVector, but transform the values of the PVector on which they are called. These non-static versions perform the same operation, but the former takes another vector as input, while the latter takes three float values. (See the top and bottom examples above, respectively.)
     Syntax
     .lerp(v, amt)
     .lerp(v1, v2, amt)
     .lerp(x, y, z, amt)
     Parameters
     v    PVector: the vector to lerp to
     amt    float: The amount of interpolation; some value between 0.0 (old vector) and 1.0 (new vector). 0.1 is very near the old vector; 0.5 is halfway in between.
     v1    PVector: the vector to start from
     v2    PVector: the vector to lerp to
     x    float: the x component to lerp to
     y    float: the y component to lerp to
     z    float: the z component to lerp to
     Returns    PVector
     Related    lerp()
     */
    PVector lerp(PVector v, float amt);    //Linear interpolate the vector to another vector
    PVector lerp(PVector v1, PVector v2, float amt);    //Linear interpolate the vector to another vector
    PVector lerp(float x, float y, float z, float amt);    //Linear interpolate the vector to another vector

    /*
     Class
     PVector

     Name
     angleBetween()
     Examples
     PVector v1 = new PVector(10, 20);
     PVector v2 = new PVector(60, 80);
     float a = PVector.angleBetween(v1, v2);
     println(degrees(a));  // Prints "10.304827"
     Description    Calculates and returns the angle (in radians) between two vectors.
     Syntax
     .angleBetween(v1, v2)
     Parameters
     v1    PVector: the x, y, and z components of a PVector
     v2    PVector: the x, y, and z components of a PVector
     Returns    float
     */
    float angleBetween(PVector v1, PVector v2);    //Calculate and return the angle between two vectors

    /*
     Class
     PVector

     Name
     array()
     Examples
     PVector v = new PVector(10.0, 20.0, 30.0);
     float[] f = v.array();
     println(f[0]);  // Prints "10.0"
     println(f[1]);  // Prints "20.0"
     println(f[2]);  // Prints "30.0"
     Description    Return a representation of this vector as a float array. This is only for temporary use. If used in any other fashion, the contents should be copied by using the copy() method to copy into your own array.
     Syntax
     .array()
     Returns    float[]
     */
    std::vector<float> array();    //Return a representation of the vector as a float array

    //Constructor
    PVector();
    PVector(float x, float y, float z);
    PVector(float x, float y);

};

/*
Name
PImage
Examples
example pic
PImage photo;

void setup() {
    size(100, 100);
    photo = loadImage("laDefense.jpg");
}

void draw() {
    image(photo, 0, 0);
}
Description    Datatype for storing images. Processing can display .gif, .jpg, .tga, and .png images. Images may be displayed in 2D and 3D space. Before an image is used, it must be loaded with the loadImage() function. The PImage class contains fields for the width and height of the image, as well as an array called pixels[] that contains the values for every pixel in the image. The methods described below allow easy access to the image's pixels and alpha channel and simplify the process of compositing.

Before using the pixels[] array, be sure to use the loadPixels() method on the image to make sure that the pixel data is properly loaded.

To create a new image, use the createImage() function. Do not use the syntax new PImage().
Fields
pixels[]    Array containing the color of every pixel in the image
width    Image width
height    Image height
Methods
loadPixels()    Loads the pixel data for the image into its pixels[] array
updatePixels()    Updates the image with the data in its pixels[] array
resize()    Changes the size of an image to a new width and height
get()    Reads the color of any pixel or grabs a rectangle of pixels
set()    writes a color to any pixel or writes an image into another
mask()    Masks part of an image with another image as an alpha channel
filter()    Converts the image to grayscale or black and white
copy()    Copies the entire image
blend()    Copies a pixel or rectangle of pixels using different blending modes
save()    Saves the image to a TIFF, TARGA, PNG, or JPEG file
Constructor
PImage(width, height, format, factor)
Related    loadImage()
imageMode()
createImage()
*/
class PImage {
public:
    //Fields
    /*
    Class
    PImage

    Name
    pixels[]
    Examples
    example pic
    PImage tower;

    void setup() {
        size(100, 100);
        tower = loadImage("tower.jpg");
        int dimension = tower.width * tower.height;
        tower.loadPixels();
        for (int i = 0; i < dimension; i += 2) {
            tower.pixels[i] = color(0, 0, 0);
        }
        tower.updatePixels();
    }

    void draw() {
        image(tower, 0, 0);
    }
    Description    Array containing the values for all the pixels in the image. These values are of the color datatype. This array is the size of the image, meaning if the image is 100 x 100 pixels, there will be 10000 values and if the window is 200 x 300 pixels, there will be 60000 values.

        Before accessing this array, the data must loaded with the loadPixels() method. Failure to do so may result in a NullPointerException. After the array data has been modified, the updatePixels() method must be run to update the content of the display window.
    Syntax
            pimg.pixels[]
    Parameters
            pimg    PImage: any object of type PImage
    */
    std::vector<int> pixels;    //Array containing the color of every pixel in the image

    /*
    Class
    PImage

    Name
    width
    Examples
    example pic
    PImage tiles = loadImage("tiles.jpg");
    image(tiles, 20, 10);
    rect(55, 10, tiles.width, tiles.height);
    Description    The width of the image in units of pixels.
    Syntax
    pimg.width
    Parameters
    pimg    PImage: any object of type PImage
    */
    int width;    //Image width

    /*
    Class
    PImage

    Name
    height
    Examples
    example pic
    PImage tiles = loadImage("tiles.jpg");
    image(tiles, 20, 10);
    rect(55, 10, tiles.width, tiles.height);
    Description    The height of the image in units of pixels.
    Syntax
    pimg.height
    Parameters
    pimg    PImage: any object of type PImage
    */
    int height;    //Image height

    //Methods
    /*
    Class
    PImage

    Name
    loadPixels()
    Examples
    example pic
    PImage myImage;
    int halfImage;

    void setup() {
        size(100, 100);
        halfImage = width * height/2;
        myImage = loadImage("apples.jpg");
        myImage.loadPixels();
        for (int i = 0; i < halfImage; i++) {
            myImage.pixels[i+halfImage] = myImage.pixels[i];
        }
        myImage.updatePixels();
    }

    void draw() {
        image(myImage, 0, 0);
    }
    Description    Loads the pixel data for the image into its pixels[] array. This function must always be called before reading from or writing to pixels[].

        Certain renderers may or may not seem to require loadPixels() or updatePixels(). However, the rule is that any time you want to manipulate the pixels[] array, you must have previously called loadPixels(), and after changes have been made, call updatePixels(). Even if the renderer may not seem to use this function in the current Processing release, this will always be subject to change.
    Syntax
            pimg.loadPixels()
    Parameters
            pimg    PImage: any object of type PImage
    Returns    void
    */
    void loadPixels();    //Loads the pixel data for the image into its pixels[] array

    /*
    Class
    PImage

    Name
    updatePixels()
    Examples
    example pic
    PImage myImage;
    int halfImage;

    void setup() {
        size(100, 100);
        halfImage = width * height/2;
        myImage = loadImage("apples.jpg");
        myImage.loadPixels();
        for (int i = 0; i < halfImage; i++) {
            myImage.pixels[i+halfImage] = myImage.pixels[i];
        }
        myImage.updatePixels();
    }

    void draw() {
        image(myImage, 0, 0);
    }
    Description    Updates the image with the data in its pixels[] array. Use in conjunction with loadPixels(). If you're only reading pixels from the array, there's no need to call updatePixels().

    Certain renderers may or may not seem to require loadPixels() or updatePixels(). However, the rule is that any time you want to manipulate the pixels[] array, you must first call loadPixels(), and after changes have been made, call updatePixels(). Even if the renderer may not seem to use this function in the current Processing release, this will always be subject to change.

        Currently, none of the renderers use the additional parameters to updatePixels(), however this may be implemented in the future.
    Syntax
        pimg.updatePixels()
        pimg.updatePixels(x, y, w, h)
    Parameters
        pimg    PImage: any object of type PImage
        x    int: x-coordinate of the upper-left corner
        y    int: y-coordinate of the upper-left corner
        w    int: width
        h    int: height
    Returns    void
    */
    void updatePixels();    //Updates the image with the data in its pixels[] array

    /*
    Class
    PImage

    Name
    resize()
    Examples
    example pic
    PImage jelly = loadImage("jelly.jpg");
    image(jelly, 0, 0);
    jelly.resize(100, 50);
    image(jelly, 0, 0);
    example pic
    PImage jelly = loadImage("jelly.jpg");
    image(jelly, 0, 0);
    jelly.resize(0, 50);
    image(jelly, 0, 0);
    Description    Resize the image to a new width and height. To make the image scale proportionally, use 0 as the value for the wide or high parameter. For instance, to make the width of an image 150 pixels, and change the height using the same proportion, use resize(150, 0).

        Even though a PGraphics is technically a PImage, it is not possible to rescale the image data found in a PGraphics. (It's simply not possible to do this consistently across renderers: technically infeasible with P3D, or what would it even do with PDF?) If you want to resize PGraphics content, first get a copy of its image data using the get() method, and call resize() on the PImage that is returned.
    Syntax
    pimg.resize(w, h)
    Parameters
    pimg    PImage: any object of type PImage
    w    int: the resized image width
    h    int: the resized image height
    Returns    void
    Related    get()
    */
    void resize(int w, int h);    //Changes the size of an image to a new width and height

    /*
    Class
    PImage

    Name
    get()
    Examples
    example pic
    PImage mountains = loadImage("rockies.jpg");
    background(mountains);
    noStroke();
    color c = mountains.get(60, 90);
    fill(c);
    rect(25, 25, 50, 50);
    example pic
    PImage mountains = loadImage("rockies.jpg");
    background(mountains);
    PImage newMountains = mountains.get(50, 0, 50, 100);
    image(newMountains, 0, 0);
    Description    Reads the color of any pixel or grabs a section of an image. If no parameters are specified, the entire image is returned. Use the x and y parameters to get the value of one pixel. Get a section of the display window by specifying an additional width and height parameter. When getting an image, the x and y parameters define the coordinates for the upper-left corner of the image, regardless of the current imageMode().

        If the pixel requested is outside of the image window, black is returned. The numbers returned are scaled according to the current color ranges, but only RGB values are returned by this function. For example, even though you may have drawn a shape with colorMode(HSB), the numbers returned will be in RGB format.

        Getting the color of a single pixel with get(x, y) is easy, but not as fast as grabbing the data directly from pixels[]. The equivalent statement to get(x, y) using pixels[] is pixels[y*width+x]. See the reference for pixels[] for more information.
    Syntax
            pimg.get(x, y)
            pimg.get(x, y, w, h)
            pimg.get()
    Parameters
            pimg    PImage: any object of type PImage
            x    int: x-coordinate of the pixel
            y    int: y-coordinate of the pixel
            w    int: width of pixel rectangle to get
            h    int: height of pixel rectangle to get
    Returns    int or PImage
    Related    set()
            pixels[]
            copy()
    */
    int get(int x, int y);    //Reads the color of any pixel or grabs a rectangle of pixels
    PImage get(int x, int y, int w, int h);    //Reads the color of any pixel or grabs a rectangle of pixels
    PImage get();    //Reads the color of any pixel or grabs a rectangle of pixels

    /*
    Class
    PImage

    Name
    set()
    Examples
    example pic
    PImage tower;

    void setup() {
        size(100, 100);
        tower = loadImage("tower.jpg");
        color black = color(0);
        tower.set(30, 20, black);
        tower.set(85, 20, black);
        tower.set(85, 75, black);
        tower.set(30, 75, black);
    }

    void draw() {
        image(tower, 0, 0);
    }
    Description    Changes the color of any pixel or writes an image directly into the display window.

    The x and y parameters specify the pixel to change and the color parameter specifies the color value. The color parameter is affected by the current color mode (the default is RGB values from 0 to 255). When setting an image, the x and y parameters define the coordinates for the upper-left corner of the image, regardless of the current imageMode().

        Setting the color of a single pixel with set(x, y) is easy, but not as fast as putting the data directly into pixels[]. The equivalent statement to set(x, y, #000000) using pixels[] is pixels[y*width+x] = #000000. See the reference for pixels[] for more information.
    Syntax
            pimg.set(x, y, c)
            pimg.set(x, y, img)
    Parameters
            pimg    PImage: any object of type PImage
            x    int: x-coordinate of the pixel
            y    int: y-coordinate of the pixel
            c    int: any value of the color datatype
            img    PImage: image to copy into the original image
    Returns    void
    Related    get()
            pixels[]
            copy()
    */
    void set(int x, int y, int c);    //writes a color to any pixel or writes an image into another
    void set(int x, int y, PImage img);    //writes a color to any pixel or writes an image into another

    /*
    Class
    PImage

    Name
    mask()
    Examples
    example pic
    PImage photo, maskImage;

    void setup() {
        size(100, 100);
        photo = loadImage("test.jpg");
        maskImage = loadImage("mask.jpg");
        photo.mask(maskImage);
    }

    void draw() {
        image(photo, 0, 0);
        image(photo, width/4, 0);
    }
    Description    Masks part of an image from displaying by loading another image and using it as an alpha channel. This mask image should only contain grayscale data, but only the blue color channel is used. The mask image needs to be the same size as the image to which it is applied.

    In addition to using a mask image, an integer array containing the alpha channel data can be specified directly. This method is useful for creating dynamically generated alpha masks. This array must be of the same length as the target image's pixels array and should contain only grayscale data of values between 0-255.
    Syntax
        pimg.mask(maskArray)
        pimg.mask(img)
    Parameters
        pimg    PImage: any object of type PImage
        maskArray    int[]: array of integers used as the alpha channel, needs to be the same length as the image's pixel array.
        img    PImage: image to use as the mask
    Returns    void
    */
    void mask(std::vector<int> maskArray);    //Masks part of an image with another image as an alpha channel
    void mask(PImage img);    //Masks part of an image with another image as an alpha channel

    /*
    Class
    PImage

    Name
    filter()
    Examples
    example pic
    PImage img1, img2;

    void setup() {
        size(100, 100);
        img1 = loadImage("apples.jpg");
        img2 = loadImage("apples.jpg");
        img1.filter(THRESHOLD, 0.3);
        img2.filter(THRESHOLD, 0.7);
    }

    void draw() {
        image(img1, 0, 0);
        image(img2, width/2, 0);
    }
    example pic
    PImage img1, img2;

    void setup() {
        img1 = loadImage("apples.jpg");
        img2 = loadImage("apples.jpg");
        img2.filter(GRAY);
    }

    void draw() {
        image(img1, 0, 0);
        image(img2, width/2, 0);
    }
    example pic
    PImage img1, img2;

    void setup() {
        img1 = loadImage("apples.jpg");
        img2 = loadImage("apples.jpg");
        img2.filter(INVERT);
    }

    void draw() {
        image(img1, 0, 0);
        image(img2, width/2, 0);
    }
    example pic
    PImage img1, img2;

    void setup() {
        img1 = loadImage("apples.jpg");
        img2 = loadImage("apples.jpg");
        img2.filter(POSTERIZE, 4);
    }

    void draw() {
        image(img1, 0, 0);
        image(img2, width/2, 0);
    }
    example pic
    PImage img1, img2;

    void setup() {
        img1 = loadImage("apples.jpg");
        img2 = loadImage("apples.jpg");
        img2.filter(BLUR, 6);
    }

    void draw() {
        image(img1, 0, 0);
        image(img2, width/2, 0);
    }
    example pic
    PImage img1, img2;

    void setup() {
        img1 = loadImage("apples.jpg");
        img2 = loadImage("apples.jpg");
        img2.filter(ERODE);
    }

    void draw() {
        image(img1, 0, 0);
        image(img2, width/2, 0);
    }
    example pic
    PImage img1, img2;

    void setup() {
        img1 = loadImage("apples.jpg");
        img2 = loadImage("apples.jpg");
        img2.filter(DILATE);
    }

    void draw() {
        image(img1, 0, 0);
        image(img2, width/2, 0);
    }
    Description    Filters the image as defined by one of the following modes:

    THRESHOLD
    Converts the image to black and white pixels depending if they are above or below the threshold defined by the level parameter. The parameter must be between 0.0 (black) and 1.0 (white). If no level is specified, 0.5 is used.

        GRAY
        Converts any colors in the image to grayscale equivalents. No parameter is used.

        OPAQUE
        Sets the alpha channel to entirely opaque. No parameter is used.

        INVERT
        Sets each pixel to its inverse value. No parameter is used.

        POSTERIZE
        Limits each channel of the image to the number of colors specified as the parameter. The parameter can be set to values between 2 and 255, but results are most noticeable in the lower ranges.

        BLUR
        Executes a Guassian blur with the level parameter specifying the extent of the blurring. If no parameter is used, the blur is equivalent to Guassian blur of radius 1. Larger values increase the blur.

        ERODE
        Reduces the light areas. No parameter is used.

        DILATE
        Increases the light areas. No parameter is used.
    Syntax
        pimg.filter(kind)
        pimg.filter(kind, param)
    Parameters
        pimg    PImage: any object of type PImage
        kind    int: Either THRESHOLD, GRAY, OPAQUE, INVERT, POSTERIZE, BLUR, ERODE, or DILATE
        param    float: unique for each, see above
    Returns    void
    */
    void filter(_penum kind);    //Converts the image to grayscale or black and white
    void filter(_penum kind, float param);    //Converts the image to grayscale or black and white

    /*
    Class
    PImage

    Name
    copy()
    Examples
    example pic
    PImage apples;

    void setup() {
        size(100, 100);
        apples = loadImage("apples.jpg");
        int x = width/2;
        apples.copy(x, 0, x, height, 0, 0, x, height);
    }

    void draw() {
        image(apples, 0, 0);
    }
    Description    Copies a region of pixels from one image into another. If the source and destination regions aren't the same size, it will automatically resize source pixels to fit the specified target region. No alpha information is used in the process, however if the source image has an alpha channel set, it will be copied as well.

    As of release 0149, this function ignores imageMode().
    Syntax
    pimg.copy()
    pimg.copy(sx, sy, sw, sh, dx, dy, dw, dh)
    pimg.copy(src, sx, sy, sw, sh, dx, dy, dw, dh)
    Parameters
    pimg    PImage: any object of type PImage
    sx    int: X coordinate of the source's upper left corner
    sy    int: Y coordinate of the source's upper left corner
    sw    int: source image width
    sh    int: source image height
    dx    int: X coordinate of the destination's upper left corner
    dy    int: Y coordinate of the destination's upper left corner
    dw    int: destination image width
    dh    int: destination image height
    src    PImage: an image variable referring to the source image.
    Returns    void or PImage
    Related    blend()
    */
    PImage copy();    //Copies the entire image
    void copy(int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh);    //Copies the entire image
    void copy(PImage src, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh);    //Copies the entire image

    /*
    Class
    PImage

    Name
    blend()
    Examples
    example pic
    PImage mountains = loadImage("rockies.jpg");
    PImage bricks = loadImage("bricks.jpg");
    mountains.blend(bricks, 0, 0, 33, 100, 67, 0, 33, 100, ADD);
    image(mountains, 0, 0);
    image(bricks, 0, 0);
    example pic
    PImage mountains = loadImage("rockies.jpg");
    PImage bricks = loadImage("bricks.jpg");
    mountains.blend(bricks, 0, 0, 33, 100, 67, 0, 33, 100, SUBTRACT);
    image(mountains, 0, 0);
    image(bricks, 0, 0);
    example pic
    PImage mountains = loadImage("rockies.jpg");
    PImage bricks = loadImage("bricks.jpg");
    mountains.blend(bricks, 0, 0, 33, 100, 67, 0, 33, 100, DARKEST);
    image(mountains, 0, 0);
    image(bricks, 0, 0);
    example pic
    PImage mountains = loadImage("rockies.jpg");
    PImage bricks = loadImage("bricks.jpg");
    mountains.blend(bricks, 0, 0, 33, 100, 67, 0, 33, 100, LIGHTEST);
    image(mountains, 0, 0);
    image(bricks, 0, 0);
    Description    Blends a region of pixels into the image specified by the img parameter. These copies utilize full alpha channel support and a choice of the following modes to blend the colors of source pixels (A) with the ones of pixels in the destination image (B):

    BLEND - linear interpolation of colours: C = A*factor + B

    ADD - additive blending with white clip: C = min(A*factor + B, 255)

    SUBTRACT - subtractive blending with black clip: C = max(B - A*factor, 0)

    DARKEST - only the darkest colour succeeds: C = min(A*factor, B)

    LIGHTEST - only the lightest colour succeeds: C = max(A*factor, B)

    DIFFERENCE - subtract colors from underlying image.

    EXCLUSION - similar to DIFFERENCE, but less extreme.

    MULTIPLY - Multiply the colors, result will always be darker.

    SCREEN - Opposite multiply, uses inverse values of the colors.

    OVERLAY - A mix of MULTIPLY and SCREEN. Multiplies dark values, and screens light values.

    HARD_LIGHT - SCREEN when greater than 50% gray, MULTIPLY when lower.

    SOFT_LIGHT - Mix of DARKEST and LIGHTEST. Works like OVERLAY, but not as harsh.

    DODGE - Lightens light tones and increases contrast, ignores darks. Called "Color Dodge" in Illustrator and Photoshop.

    BURN - Darker areas are applied, increasing contrast, ignores lights. Called "Color Burn" in Illustrator and Photoshop.

    All modes use the alpha information (highest byte) of source image pixels as the blending factor. If the source and destination regions are different sizes, the image will be automatically resized to match the destination size. If the src parameter is not used, the display window is used as the source image.

    As of release 0149, this function ignores imageMode().
    Syntax
    pimg.blend(sx, sy, sw, sh, dx, dy, dw, dh, mode)
    pimg.blend(src, sx, sy, sw, sh, dx, dy, dw, dh, mode)
    Parameters
    pimg    PImage: any object of type PImage
    src    PImage: an image variable referring to the source image
    sx    int: X coordinate of the source's upper left corner
    sy    int: Y coordinate of the source's upper left corner
    sw    int: source image width
    sh    int: source image height
    dx    int: X coordinate of the destinations's upper left corner
    dy    int: Y coordinate of the destinations's upper left corner
    dw    int: destination image width
    dh    int: destination image height
    mode    int: Either BLEND, ADD, SUBTRACT, LIGHTEST, DARKEST, DIFFERENCE, EXCLUSION, MULTIPLY, SCREEN, OVERLAY, HARD_LIGHT, SOFT_LIGHT, DODGE, BURN
    Returns    void
    Related    alpha()
    copy()
    */
    void blend(int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, _penum mode);    //Copies a pixel or rectangle of pixels using different blending modes
    void blend(PImage src, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, _penum mode);    //Copies a pixel or rectangle of pixels using different blending modes

    /*
    Class
    PImage

    Name
    save()
    Examples
    PImage tower = loadImage("tower.jpg");
    tower.save("outputImage.jpg");

    size(100, 100);
    PImage tower = loadImage("tower.jpg");
    PImage newImage = createImage(100, 100, RGB);
    newImage = tower.get();
    newImage.save("outputImage.jpg");
    Description    Saves the image into a file. Append a file extension to the name of the file, to indicate the file format to be used: either TIFF (.tif), TARGA (.tga), JPEG (.jpg), or PNG (.png). If no extension is included in the filename, the image will save in TIFF format and .tif will be added to the name. These files are saved to the sketch's folder, which may be opened by selecting "Show sketch folder" from the "Sketch" menu.

    To save an image created within the code, rather than through loading, it's necessary to make the image with the createImage() function so it is aware of the location of the program and can therefore save the file to the right place. See the createImage() reference for more information.
    Syntax
    pimg.save(filename)
    Parameters
    pimg    PImage: any object of type PImage
    filename    String: a sequence of letters and numbers
    Returns    boolean
    */
    bool save(std::string filename);    //Saves the image to a TIFF, TARGA, PNG, or JPEG file

    //Constructor
    //PImage(width, height, format, factor)
};

#define PMatrix3D std::array<float, 9>
#define PMatrix2D std::array<float, 4>
/*
 Name
 PShader
 Examples
 PShader blur;

 void setup() {
 size(640, 360, P2D);
 // Shaders files must be in the "data" folder to load correctly
 blur = loadShader("blur.glsl");
 stroke(0, 102, 153);
 rectMode(CENTER);
 }

 void draw() {
 filter(blur);
 rect(mouseX-75, mouseY, 150, 150);
 ellipse(mouseX+75, mouseY, 150, 150);
 }
 Description    This class encapsulates a GLSL shader program, including a vertex and a fragment shader. It's compatible with the P2D and P3D renderers, but not with the default renderer. Use the loadShader() function to load your shader code. [Note: It's strongly encouraged to use loadShader() to create a PShader object, rather than calling the PShader constructor manually.]
 Methods
 set()    Sets a variable within the shader
 Constructor
 PShader()
 PShader(parent)
 PShader(parent, vertFilename, fragFilename)
 PShader(parent, vertURL, fragURL)
 PShader(parent, vertSource, fragSource)
 Parameters
 parent    PApplet: the parent program
 vertFilename    String: name of the vertex shader
 fragFilename    String: name of the fragment shader
 vertURL    URL: network location of the vertex shader
 fragURL    URL: network location of the fragment shader
 */
class PShader {
public:
    //Methods
    /*
     Class
     PShader

     Name
     set()
     Examples
     PImage tex;
     PShader deform;

     void setup() {
     size(640, 360, P2D);
     tex = loadImage("tex1.jpg");
     deform = loadShader("deform.glsl");
     deform.set("resolution", float(width), float(height));
     }

     void draw() {
     deform.set("time", millis() / 1000.0);
     deform.set("mouse", float(mouseX), float(mouseY));
     shader(deform);
     image(tex, 0, 0, width, height);
     }
     Description    Sets the uniform variables inside the shader to modify the effect while the program is running.
     Syntax
     .set(name, x)
     .set(name, x, y)
     .set(name, x, y, z)
     .set(name, x, y, z, w)
     .set(name, vec)
     .set(name, vec, ncoords)
     .set(name, boolvec, ncoords)
     .set(name, mat)
     .set(name, mat, use3x3)
     .set(name, tex)
     Parameters
     name    String: the name of the uniform variable to modify
     x    boolean, float, or int: first component of the variable to modify
     y    boolean, float, or int: second component of the variable to modify. The variable has to be declared with an array/vector type in the shader (i.e.: int[2], vec2)
     z    boolean, float, or int: third component of the variable to modify. The variable has to be declared with an array/vector type in the shader (i.e.: int[3], vec3)
     w    boolean, float, or int: fourth component of the variable to modify. The variable has to be declared with an array/vector type in the shader (i.e.: int[4], vec4)
     vec    boolean[], float[], int[], or PVector: modifies all the components of an array/vector uniform variable. PVector can only be used if the type of the variable is vec3.
     ncoords    int: number of coordinates per element, max 4
     mat    PMatrix3D, or PMatrix2D: matrix of values
     use3x3    boolean: enforces the matrix is 3 x 3
     tex    PImage: sets the sampler uniform variable to read from this image texture
     Returns    void
     */
    void set(std::string name, bool x);  //Sets a variable within the shader
    void set(std::string name, float x);  //Sets a variable within the shader
    void set(std::string name, int x);  //Sets a variable within the shader
    void set(std::string name, bool x, bool y);  //Sets a variable within the shader
    void set(std::string name, float x, float y);  //Sets a variable within the shader
    void set(std::string name, int x, int y);  //Sets a variable within the shader
    void set(std::string name, bool x, bool y, bool z);  //Sets a variable within the shader
    void set(std::string name, float x, float y, float z);  //Sets a variable within the shader
    void set(std::string name, int x, int y, int z);  //Sets a variable within the shader
    void set(std::string name, bool x, bool y, bool z, bool w);  //Sets a variable within the shader
    void set(std::string name, float x, float y, float z, float w);  //Sets a variable within the shader
    void set(std::string name, int x, int y, int z, int w);  //Sets a variable within the shader
    void set(std::string name, bool vec[]);  //Sets a variable within the shader
    void set(std::string name, float vec[]);  //Sets a variable within the shader
    void set(std::string name, int vec[]);  //Sets a variable within the shader
    void set(std::string name, PVector vec);  //Sets a variable within the shader
    void set(std::string name, bool vec[], int ncoords);  //Sets a variable within the shader
    void set(std::string name, float vec[], int ncoords);  //Sets a variable within the shader
    void set(std::string name, int vec[], int ncoords);  //Sets a variable within the shader
    void set(std::string name, PVector vec, int ncoords);  //Sets a variable within the shader
    //set(name, boolvec, ncoords);  //Sets a variable within the shader
    void set(std::string name, PMatrix3D mat);  //Sets a variable within the shader
    void set(std::string name, PMatrix2D mat);  //Sets a variable within the shader
    void set(std::string name, PMatrix3D mat, bool use3x3);  //Sets a variable within the shader
    void set(std::string name, PMatrix2D mat, bool use3x3);  //Sets a variable within the shader
    void set(std::string name, PImage tex);  //Sets a variable within the shader
    //Constructor
    /*PShader()
     PShader(parent)
     PShader(parent, vertFilename, fragFilename)
     PShader(parent, vertURL, fragURL)
     PShader(parent, vertSource, fragSource)*/
};


//Structure
/*
Name
exit()
Examples
void draw() {
    line(mouseX, mouseY, 50, 50);
}

void mousePressed() {
    exit();
}
Description    Quits/stops/exits the program. Programs without a draw() function stop automatically after the last line has run, but programs with draw() run continuously until the program is manually stopped or exit() is run.

Rather than terminating immediately, exit() will cause the sketch to exit after draw() has completed (or after setup() completes if called during the setup() function).

For Java programmers, this is not the same as System.exit(). Further, System.exit() should not be used because closing out an application while draw() is running may cause a crash (particularly with P3D).
Syntax
exit()
Returns    void
*/
void exit();

/*
Name
loop()
Examples
void setup() {
    size(200, 200);
    noLoop();  // draw() will not loop
}

float x = 0;

void draw() {
    background(204);
    x = x + .1;
    if (x > width) {
        x = 0;
    }
    line(x, 0, x, height);
}

void mousePressed() {
    loop();  // Holding down the mouse activates looping
}

void mouseReleased() {
    noLoop();  // Releasing the mouse stops looping draw()
}
Description    By default, Processing loops through draw() continuously, executing the code within it. However, the draw() loop may be stopped by calling noLoop(). In that case, the draw() loop can be resumed with loop().
Syntax
loop()
Returns    void
Related    noLoop()
redraw()
draw()
*/
void loop();

/*
Name
noLoop()
Examples
void setup() {
    size(200, 200);
    noLoop();
}

void draw() {
    line(10, 10, 190, 190);
}
void setup() {
    size(200, 200);
}

float x = 0.0;

void draw() {
    background(204);
    x = x + 0.1;
    if (x > width) {
        x = 0;
    }
    line(x, 0, x, height);
}

void mousePressed() {
    noLoop();
}

void mouseReleased() {
    loop();
}
boolean someMode = false;

void setup() {
    noLoop();
}

void draw() {
    if (someMode) {
        // do something
    }
}

void mousePressed() {
    someMode = true;
    redraw();  // or loop()
}
Description    Stops Processing from continuously executing the code within draw(). If loop() is called, the code in draw() begins to run continuously again. If using noLoop() in setup(), it should be the last line inside the block.

When noLoop() is used, it's not possible to manipulate or access the screen inside event handling functions such as mousePressed() or keyPressed(). Instead, use those functions to call redraw() or loop(), which will run draw(), which can update the screen properly. This means that when noLoop() has been called, no drawing can happen, and functions like saveFrame() or loadPixels() may not be used.

Note that if the sketch is resized, redraw() will be called to update the sketch, even after noLoop() has been specified. Otherwise, the sketch would enter an odd state until loop() was called.
Syntax
noLoop()
Returns    void
Related    loop()
redraw()
draw()
*/
void noLoop();

/*
Name
pop()
Examples
example pic
fill(255);
rect(0, 0, 50, 50);  // White rectangle

push();
translate(30, 20);
fill(0);
rect(0, 0, 50, 50);  // Black rectangle
pop();  // Restore original settings

fill(100);
rect(15, 10, 50, 50);  // Gray rectangle
example pic
ellipse(0, 50, 33, 33);  // Left circle

push();
strokeWeight(10);
fill(204, 153, 0);
ellipse(50, 50, 33, 33);  // Middle circle
pop();  // Restore original settings

ellipse(100, 50, 33, 33);  // Right circle
Description    The pop() function restores the previous drawing style settings and transformations after push() has changed them. Note that these functions are always used together. They allow you to change the style and transformation settings and later return to what you had. When a new state is started with push(), it builds on the current style and transform information.

push() stores information related to the current transformation state and style settings controlled by the following functions: rotate(), translate(), scale(), fill(), stroke(), tint(), strokeWeight(), strokeCap(), strokeJoin(), imageMode(), rectMode(), ellipseMode(), colorMode(), textAlign(), textFont(), textMode(), textSize(), textLeading().

The push() and pop() functions were added with Processing 3.5. They can be used in place of pushMatrix(), popMatrix(), pushStyles(), and popStyles(). The difference is that push() and pop() control both the transformations (rotate, scale, translate) and the drawing styles at the same time.
Syntax
pop()
Returns    void
Related    push()
*/
void pop();

/*
Name
popStyle()
Examples
example pic
ellipse(0, 50, 33, 33);  // Left circle

pushStyle();  // Start a new style
strokeWeight(10);
fill(204, 153, 0);
ellipse(50, 50, 33, 33);  // Middle circle
popStyle();  // Restore original style

ellipse(100, 50, 33, 33);  // Right circle
example pic
ellipse(0, 50, 33, 33);  // Left circle

pushStyle();  // Start a new style
strokeWeight(10);
fill(204, 153, 0);
ellipse(33, 50, 33, 33);  // Left-middle circle

pushStyle();  // Start another new style
stroke(0, 102, 153);
ellipse(66, 50, 33, 33);  // Right-middle circle
popStyle();  // Restore the previous style

popStyle();  // Restore original style

ellipse(100, 50, 33, 33);  // Right circle
Description    The pushStyle() function saves the current style settings and popStyle() restores the prior settings; these functions are always used together. They allow you to change the style settings and later return to what you had. When a new style is started with pushStyle(), it builds on the current style information. The pushStyle() and popStyle() functions can be embedded to provide more control (see the second example above for a demonstration.)
Syntax
popStyle()
Returns    void
Related    pushStyle()
*/
void popStyle();

/*
Name
push()
Examples
example pic
fill(255);
rect(0, 0, 50, 50);  // White rectangle

push();
translate(30, 20);
fill(0);
rect(0, 0, 50, 50);  // Black rectangle
pop();  // Restore original settings

fill(100);
rect(15, 10, 50, 50);  // Gray rectangle
example pic
ellipse(0, 50, 33, 33);  // Left circle

push();
strokeWeight(10);
fill(204, 153, 0);
ellipse(50, 50, 33, 33);  // Middle circle
pop();  // Restore original settings

ellipse(100, 50, 33, 33);  // Right circle
Description    The push() function saves the current drawing style settings and transformations, while pop() restores these settings. Note that these functions are always used together. They allow you to change the style and transformation settings and later return to what you had. When a new state is started with push(), it builds on the current style and transform information.

push() stores information related to the current transformation state and style settings controlled by the following functions: rotate(), translate(), scale(), fill(), stroke(), tint(), strokeWeight(), strokeCap(), strokeJoin(), imageMode(), rectMode(), ellipseMode(), colorMode(), textAlign(), textFont(), textMode(), textSize(), textLeading().

The push() and pop() functions were added with Processing 3.5. They can be used in place of pushMatrix(), popMatrix(), pushStyles(), and popStyles(). The difference is that push() and pop() control both the transformations (rotate, scale, translate) and the drawing styles at the same time.
Syntax
push()
Returns    void
Related    pop()
*/
void push();

/*
Name
pushStyle()
Examples
example pic
ellipse(0, 50, 33, 33);  // Left circle

pushStyle();  // Start a new style
strokeWeight(10);
fill(204, 153, 0);
ellipse(50, 50, 33, 33);  // Middle circle
popStyle();  // Restore original style

ellipse(100, 50, 33, 33);  // Right circle
example pic
ellipse(0, 50, 33, 33);  // Left circle

pushStyle();  // Start a new style
strokeWeight(10);
fill(204, 153, 0);
ellipse(33, 50, 33, 33);  // Left-middle circle

pushStyle();  // Start another new style
stroke(0, 102, 153);
ellipse(66, 50, 33, 33);  // Right-middle circle
popStyle();  // Restore previous style

popStyle();  // Restore original style

ellipse(100, 50, 33, 33);  // Right circle
Description    The pushStyle() function saves the current style settings and popStyle() restores the prior settings. Note that these functions are always used together. They allow you to change the style settings and later return to what you had. When a new style is started with pushStyle(), it builds on the current style information. The pushStyle() and popStyle() functions can be embedded to provide more control. (See the second example above for a demonstration.)

The style information controlled by the following functions are included in the style: fill(), stroke(), tint(), strokeWeight(), strokeCap(), strokeJoin(), imageMode(), rectMode(), ellipseMode(), shapeMode(), colorMode(), textAlign(), textFont(), textMode(), textSize(), textLeading(), emissive(), specular(), shininess(), ambient()
Syntax
pushStyle()
Returns    void
Related    popStyle()
*/
void pushStyle();

/*
Name
redraw()
Examples
float x = 0;

void setup() {
    size(200, 200);
    noLoop();
}

void draw() {
    background(204);
    line(x, 0, x, height);
}

void mousePressed() {
    x += 1;
    redraw();
}
Description    Executes the code within draw() one time. This functions allows the program to update the display window only when necessary, for example when an event registered by mousePressed() or keyPressed() occurs.

In structuring a program, it only makes sense to call redraw() within events such as mousePressed(). This is because redraw() does not run draw() immediately (it only sets a flag that indicates an update is needed).

The redraw() function does not work properly when called inside draw(). To enable/disable animations, use loop() and noLoop().
Syntax
redraw()
Returns    void
Related    draw()
loop()
noLoop()
frameRate()
*/
void redraw();

/*
Name
thread()
Examples
String time = "";

void setup() {
    size(100, 100);
}

void draw() {
    background(0);
    // Every 30 frames request new data
    if (frameCount % 30 == 0) {
        thread("requestData");
    }
    text(time, 10, 50);
}

// This happens as a separate thread and can take as long as it wants
void requestData() {
    JSONObject json = loadJSONObject("http://time.jsontest.com/");
    time = json.getString("time");
}
Description    Processing sketches follow a specific sequence of steps: setup() first, followed by draw() over and over and over again in a loop. A thread is also a series of steps with a beginning, a middle, and an end. A Processing sketch is a single thread, often referred to as the "Animation" thread. Other threads' sequences, however, can run independently of the main animation loop. In fact, you can launch any number of threads at one time, and they will all run concurrently.

You cannot draw to the screen from a function called by thread(). Because it runs independently, the code will not be synchronized to the animation thread, causing strange or at least inconsistent results. Use thread() to load files or do other tasks that take time. When the task is finished, set a variable that indicates the task is complete, and check that from inside your draw() method.

Processing uses threads quite often, such as with library functions like captureEvent() and movieEvent(). These functions are triggered by a different thread running behind the scenes, and they alert Processing whenever they have something to report. This is useful when you need to perform a task that takes too long and would slow down the main animation's frame rate, such as grabbing data from the network. If a separate thread gets stuck or has an error, the entire program won't grind to a halt, since the error only stops that individual thread.

Writing your own thread can be a complex endeavor that involves extending the Java Thread class. However, the thread() method is a quick and dirty way to implement a simple thread in Processing. By passing in a String that matches the name of a function declared elsewhere in the sketch, Processing will execute that function in a separate thread.
Syntax
thread(name)
Parameters
name    String: name of the function to be executed in a separate thread
Returns    void
Related    setup()
draw()
loop()
noLoop()
*/
void thread();

//Environment

/*
Name
cursor()
Examples
// Move the mouse left and right across the image
// to see the cursor change from a cross to a hand

void setup() {
    size(100, 100);
}

void draw() {
    if (mouseX < 50) {
        cursor(CROSS);
    } else {
        cursor(HAND);
    }
}
Description    Sets the cursor to a predefined symbol or an image, or makes it visible if already hidden. If you are trying to set an image as the cursor, the recommended size is 16x16 or 32x32 pixels. The values for parameters x and y must be less than the dimensions of the image.

Setting or hiding the cursor does not generally work with "Present" mode (when running full-screen).

With the P2D and P3D renderers, a generic set of cursors are used because the OpenGL renderer doesn't have access to the default cursor images for each platform (Issue 3791).
Syntax
cursor(kind)
cursor(img)
cursor(img, x, y)
cursor()
Parameters
kind    int: either ARROW, CROSS, HAND, MOVE, TEXT, or WAIT
img    PImage: any variable of type PImage
x    int: the horizontal active spot of the cursor
y    int: the vertical active spot of the cursor
Returns    void
Related    noCursor()
*/
void cursor(int kind);
void cursor(PImage img);
void cursor(PImage img, int x, int y);
void cursor();

/*
Name
delay()
Examples
import processing.serial.*;

Serial myPort;  // The serial port

void setup() {
    printArray(Serial.list());
    myPort = new Serial(this, Serial.list()[0], 9600);
}

void draw() {
    while (myPort.available() > 0) {
        int inByte = myPort.read();
        println(inByte);
    }
    delay(100);
}
Description    The delay() function halts for a specified time. Delay times are specified in thousandths of a second. For example, running delay(3000) will stop the program for three seconds and delay(500) will stop the program for a half-second.

The screen only updates when the end of draw() is reached, so delay() cannot be used to slow down drawing. For instance, you cannot use delay() to control the timing of an animation.

The delay() function should only be used for pausing scripts (i.e. a script that needs to pause a few seconds before attempting a download, or a sketch that needs to wait a few milliseconds before reading from the serial port.)
Syntax
delay(napTime)
Parameters
napTime    int: milliseconds to pause before running draw() again
Returns    void
Related    frameRate
draw()
*/
void delay(int napTime);

/*
Name
displayDensity()
Examples
void setup() {
    size(100, 100);
    pixelDensity(displayDensity());
    noStroke();
}

void draw() {
    background(0);
    ellipse(30, 48, 36, 36);
    ellipse(70, 48, 36, 36);
}
Description    This function returns the number "2" if the screen is a high-density screen (called a Retina display on OS X or high-dpi on Windows and Linux) and a "1" if not. This information is useful for a program to adapt to run at double the pixel density on a screen that supports it.
Syntax
displayDensity()
displayDensity(display)
Parameters
display    int: the display number to check
Returns    int
Related    pixelDensity()
size()
 */
int displayDensity();
int displayDensity(int display);

/*
Name
focused
Examples
if (focused) {  // or "if (focused == true)"
    ellipse(25, 25, 50, 50);
} else {
    line(0, 0, 100, 100);
    line(100, 0, 0, 100);
}
Description    Confirms if a Processing program is "focused," meaning that it is active and will accept mouse or keyboard input. This variable is "true" if it is focused and "false" if not.
*/
extern bool $focused;

/*
Name
frameCount
Examples
void setup() {
    frameRate(30);
}

void draw() {
    line(0, 0, width, height);
    println(frameCount);
}
Description    The system variable frameCount contains the number of frames that have been displayed since the program started. Inside setup() the value is 0, after the first iteration of draw it is 1, etc.
Related    frameRate()
frameRate
*/
extern long long $frameCount;

/*
Name
frameRate()
Examples
void setup() {
    frameRate(4);
}
int pos = 0;
void draw() {
    background(204);
    pos++;
    line(pos, 20, pos, 80);
    if (pos > width) {
        pos = 0;
    }
}
Description    Specifies the number of frames to be displayed every second. For example, the function call frameRate(30) will attempt to refresh 30 times a second. If the processor is not fast enough to maintain the specified rate, the frame rate will not be achieved. Setting the frame rate within setup() is recommended. The default rate is 60 frames per second.
Syntax
frameRate(fps)
Parameters
fps    float: number of desired frames per second
Returns    void
Related    frameRate
frameCount
setup()
draw()
loop()
noLoop()
redraw()
*/
void frameRate(float fps);

/*
Name
frameRate
Examples
void setup() {
    frameRate(30);
}

void draw() {
    line(0, 0, width, height);
    println(frameRate);
}
Description    The system variable frameRate contains the approximate frame rate of a running sketch. The initial value is 10 fps and is updated with each frame. The value is averaged over several frames, and so will only be accurate after the draw function has run 5-10 times.
Related    frameRate()
frameCount
*/
extern float $frameRate;

/*
Name
fullScreen()
Examples
// Run the code at the full dimensions of the screen currently
// selected inside the Preferences window

int x = 0;

void setup() {
    fullScreen();
    background(0);
    noStroke();
    fill(102);
}

void draw() {
    rect(x, height*0.2, 1, height*0.6);
    x = x + 2;
}
// If more than one screen is attached to the computer, run the
// code at the full dimensions on the screen defined by the
// parameter to fullScreen()

int x = 0;

void setup() {
    fullScreen(2);
    background(0);
    noStroke();
    fill(102);
}

void draw() {
    rect(x, height*0.2, 1, height*0.6);
    x = x + 2;
}
// Run full screen using the P2D renderer on screen 2

int x = 0;

void setup() {
    fullScreen(P2D, 2);
    background(0);
    noStroke();
    fill(102);
}

void draw() {
    rect(x, height*0.2, 1, height*0.6);
    x = x + 2;
}
// If more than one screen is attached to the computer, run the
// code at the full dimensions across all of the attached screens

int x = 0;

void setup() {
    fullScreen(P2D, SPAN);
    background(0);
    noStroke();
    fill(102);
}

void draw() {
    rect(x, height*0.2, 1, height*0.6);
    x = x + 2;
}
Description    This function is new for Processing 3.0. It opens a sketch using the full size of the computer's display. This function must be the first line in setup(). The size() and fullScreen() functions cannot both be used in the same program, just choose one.

When fullScreen() is used without a parameter, it draws the sketch to the screen currently selected inside the Preferences window. When it is used with a single parameter, this number defines the screen to display to program on (e.g. 1, 2, 3...). When used with two parameters, the first defines the renderer to use (e.g. P2D) and the second defines the screen. The SPAN parameter can be used in place of a screen number to draw the sketch as a full-screen window across all of the attached displays if there are more than one.

Prior to Processing 3.0, a full-screen program was defined with size(displayWidth, displayHeight).
Syntax
fullScreen()
fullScreen(display)
fullScreen(renderer)
fullScreen(renderer, display)
Parameters
renderer    String: the renderer to use, e.g. P2D, P3D, JAVA2D (default)
display    int: the screen to run the sketch on (1, 2, 3, etc. or on multiple screens using SPAN)
Returns    void
Related    settings()
setup()
size()
smooth()
*/
void fullScreen();
void fullScreen(int display);
void fullScreen(char * renderer);
void fullScreen(char * renderer, int display);

/*
Name
height
Examples
example pic
noStroke();
background(0);
rect(40, 0, 20, height);
rect(60, 0, 20, height/2);
Description    System variable that stores the height of the display window. This value is set by the second parameter of the size() function. For example, the function call size(320, 240) sets the height variable to the value 240. The value of height defaults to 100 if size() is not used in a program.
Related    width
size()
*/
extern int $height;

/*
Name
noCursor()
Examples
// Press the mouse to hide the cursor
void draw()
{
    if (mousePressed == true) {
        noCursor();
    } else {
        cursor(HAND);
    }
}
Description    Hides the cursor from view. Will not work when running the program in a web browser or in full screen (Present) mode.
Syntax
noCursor()
Returns    void
Related    cursor()
*/
void noCursor();

/*
Name
noSmooth()
Examples
size(100, 100);
noSmooth();
noStroke();
background(0);
ellipse(30, 48, 36, 36);
ellipse(70, 48, 36, 36);
void setup() {
    size(100, 100, P2D);
    noSmooth();
    noStroke();
}

void draw() {
    background(0);
    ellipse(30, 48, 36, 36);
    ellipse(70, 48, 36, 36);
}
Description    Draws all geometry and fonts with jagged (aliased) edges and images when hard edges between the pixels when enlarged rather than interpoloating pixels. Note that smooth() is active by default, so it is necessary to call noSmooth() to disable smoothing of geometry, fonts, and images. Since the release of Processing 3.0, the noSmooth() function can only be run once for each sketch, either at the top of a sketch without a setup(), or after the size() function when used in a sketch with setup(). See the examples above for both scenarios.
Syntax
noSmooth()
Returns    void
*/
void noSmooth();

/*
Name
pixelDensity()
Examples
size(100, 100);
pixelDensity(2);
noStroke();
background(0);
ellipse(30, 48, 36, 36);
ellipse(70, 48, 36, 36);
void setup() {
    size(100, 100);
    pixelDensity(2);
    noStroke();
}

void draw() {
    background(0);
    ellipse(30, 48, 36, 36);
    ellipse(70, 48, 36, 36);
}
void setup() {
    size(100, 100);
    // Pulling the display's density dynamically
    pixelDensity(displayDensity());
    noStroke();
}

void draw() {
    background(0);
    ellipse(30, 48, 36, 36);
    ellipse(70, 48, 36, 36);
}
Description    This function is new with Processing 3.0. It makes it possible for Processing to render using all of the pixels on high resolutions screens like Apple Retina displays and Windows High-DPI displays. This function can only be run once within a program and it must be used right after size() in a program without a setup() and used within setup() when a program has one. The pixelDensity() should only be used with hardcoded numbers (in almost all cases this number will be 2) or in combination with displayDensity() as in the third example above. To use variables as the arguments to pixelDensity() function, place the pixelDensity() function within the settings() function. There is more information about this on the settings() reference page.
Syntax
pixelDensity(density)
Parameters
density    int: 1 or 2
Returns    void
*/
void pixelDensity(int density);

/*
Name
pixelHeight
Examples
size(600, 400);
pixelDensity(2);
println(width, height);
println(pixelWidth, pixelHeight);
Description    When pixelDensity(2) is used to make use of a high resolution display (called a Retina display on OS X or high-dpi on Windows and Linux), the width and height of the sketch do not change, but the number of pixels is doubled. As a result, all operations that use pixels (like loadPixels(), get(), set(), etc.) happen in this doubled space. As a convenience, the variables pixelWidth and pixelHeight hold the actual width and height of the sketch in pixels. This is useful for any sketch that uses the pixels[] array, for instance, because the number of elements in the array will be pixelWidth*pixelHeight, not width*height.
Related    pixelWidth
pixelDensity()
displayDensity()
*/
extern int $pixelHeight;

/*
Name
pixelWidth
Examples
size(600, 400);
pixelDensity(2);
println(width, height);
println(pixelWidth, pixelHeight);
Description    When pixelDensity(2) is used to make use of a high resolution display (called a Retina display on OS X or high-dpi on Windows and Linux), the width and height of the sketch do not change, but the number of pixels is doubled. As a result, all operations that use pixels (like loadPixels(), get(), set(), etc.) happen in this doubled space. As a convenience, the variables pixelWidth and pixelHeight hold the actual width and height of the sketch in pixels. This is useful for any sketch that uses the pixels[] array, for instance, because the number of elements in the array will be pixelWidth*pixelHeight, not width*height.
Related    pixelHeight
pixelDensity()
displayDensity()
*/
extern int $pixelWidth;

/*
Name
size()
Examples
size(200, 100);
background(153);
line(0, 0, width, height);
void setup() {
    size(320, 240);
}

void draw() {
    background(153);
    line(0, 0, width, height);
}
size(150, 200, P3D);  // Specify P3D renderer
background(153);

// With P3D, we can use z (depth) values...
line(0, 0, 0, width, height, -100);
line(width, 0, 0, width, height, -100);
line(0, height, 0, width, height, -100);

//...and 3D-specific functions, like box()
translate(width/2, height/2);
rotateX(PI/6);
rotateY(PI/6);
box(35);
Description    Defines the dimension of the display window width and height in units of pixels. In a program that has the setup() function, the size() function must be the first line of code inside setup(), and the setup() function must appear in the code tab with the same name as your sketch folder.

The built-in variables width and height are set by the parameters passed to this function. For example, running size(640, 480) will assign 640 to the width variable and 480 to the height variable. If size() is not used, the window will be given a default size of 100 x 100 pixels.

The size() function can only be used once inside a sketch, and it cannot be used for resizing.

As of Processing 3, to run a sketch at the full dimensions of a screen, use the fullScreen() function, rather than the older way of using size(displayWidth, displayHeight).

The maximum width and height is limited by your operating system, and is usually the width and height of your actual screen. On some machines it may simply be the number of pixels on your current screen, meaning that a screen of 800 x 600 could support size(1600, 300), since that is the same number of pixels. This varies widely, so you'll have to try different rendering modes and sizes until you get what you're looking for. If you need something larger, use createGraphics to create a non-visible drawing surface.

The minimum width and height is around 100 pixels in each direction. This is the smallest that is supported across Windows, macOS, and Linux. We enforce the minimum size so that sketches will run identically on different machines.
The renderer parameter selects which rendering engine to use. For example, if you will be drawing 3D shapes, use P3D. In addition to the default renderer, other renderers are:

P2D (Processing 2D): 2D graphics renderer that makes use of OpenGL-compatible graphics hardware.

P3D (Processing 3D): 3D graphics renderer that makes use of OpenGL-compatible graphics hardware.

FX2D (JavaFX 2D): A 2D renderer that uses JavaFX, which may be faster for some applications, but has some compatibility quirks.
PDF: The PDF renderer draws 2D graphics directly to an Acrobat PDF file. This produces excellent results when you need vector shapes for high-resolution output or printing. You must first use Import Library → PDF to make use of the library. More information can be found in the PDF library reference.

SVG: The SVG renderer draws 2D graphics directly to an SVG file. This is great for importing into other vector programs or using for digital fabrication. You must first use Import Library → SVG Export to make use of the library.

As of Processing 3.0, to use variables as the parameters to size() function, place the size() function within the settings() function (instead of setup()). There is more information about this on the settings() reference page.

Syntax
size(width, height)
size(width, height, renderer)
Parameters
width    int: width of the display window in units of pixels
height    int: height of the display window in units of pixels
Returns    void
Related    width
height
*/
void size(int width, int height);
void size(int width, int height, _penum renderer);

/*
Name
smooth()
Examples
void setup() {
    size(100, 100);
    smooth(2);
    noStroke();
}

void draw() {
    background(0);
    ellipse(30, 48, 36, 36);
    ellipse(70, 48, 36, 36);
}
void setup() {
    fullScreen(P2D, SPAN);
    smooth(4);
}

void draw() {
    background(0);
    ellipse(x, height/2, height/4, height/4);
    x += 1;
}
Description    Draws all geometry with smooth (anti-aliased) edges. This behavior is the default, so smooth() only needs to be used when a program needs to set the smoothing in a different way. The level parameter increases the level of smoothness. This is the level of over sampling applied to the graphics buffer.

With the P2D and P3D renderers, smooth(2) is the default, this is called "2x anti-aliasing." The code smooth(4) is used for 4x anti-aliasing and smooth(8) is specified for 8x anti-aliasing. The maximum anti-aliasing level is determined by the hardware of the machine that is running the software, so smooth(4) and smooth(8) will not work with every computer.

The default renderer uses smooth(3) by default. This is bicubic smoothing. The other option for the default renderer is smooth(2), which is bilinear smoothing.

With Processing 3.0, smooth() is different than before. It was common to use smooth() and noSmooth() to turn on and off antialiasing within a sketch. Now, because of how the software has changed, smooth() can only be set once within a sketch. It can be used either at the top of a sketch without a setup(), or after the size() function when used in a sketch with setup(). The noSmooth() function also follows the same rules.
Syntax
smooth(level)
Parameters
level    int: either 2, 3, 4, or 8 depending on the renderer
Returns    void
*/
void smooth(int level);

/*
Name
width
Examples
example pic
noStroke();
background(0);
rect(0, 40, width, 20);
rect(0, 60, width/2, 20);
Description    System variable that stores the width of the display window. This value is set by the first parameter of the size() function. For example, the function call size(320, 240) sets the width variable to the value 320. The value of width defaults to 100 if size() is not used in a program.
Related    height
size()
*/
extern int $width;

//Data
//Primitive
//boolean
//byte
//char

/*
Name
color
Examples
example pic
color c1 = color(204, 153, 0);
color c2 = #FFCC00;
noStroke();
fill(c1);
rect(0, 0, 25, 100);
fill(c2);
rect(25, 0, 25, 100);
color c3 = get(10, 50);
fill(c3);
rect(50, 0, 50, 100);
Description    Datatype for storing color values. Colors may be assigned with get() and color() or they may be specified directly using hexadecimal notation such as #FFCC00 or 0xFFFFCCOO.

Using print() or println() on a color will produce strange results (usually negative numbers) because of the way colors are stored in memory. A better technique is to use the hex() function to format the color data, or use the red(), green(), and blue() functions to get individual values and print those. The hue(), saturation(), and brightness() functions work in a similar fashion. To extract red, green, and blue values more quickly (for instance when analyzing an image or a frame of video), use bit shifting.

Values can also be created using web color notation. For example: color c = #006699

Web color notation only works for opaque colors. To define a color with an alpha value, you can either use color() or hexadecimal notation. For hex notation, prefix the values with 0x, for instance color c = 0xCC006699. In that example, CC (the hex value of 204) is the alpha value, and the remainder is identical to a web color. Note that in hexadecimal notation, the alpha value appears in the first position. (The alpha value appears last when used within color(), fill(), and stroke().) The following is an equivalent way of writing the preceding example, but using color() and specifying the alpha value as its second parameter: color c = color(#006699, 191)

From a technical standpoint, colors are 32 bits of information ordered as AAAAAAAARRRRRRRRGGGGGGGGBBBBBBBB where the A's contain the alpha value, the R's are the red value, G's are green, and B's are blue. Each component is 8 bits (a number between 0 and 255). These values can be manipulated with bit shifting.
*/
//#define colorType int

//double
//float
//int
//long

//Composite
/*
Array
ArrayList
DoubleDict
DoubleList
FloatDict
FloatList
HashMap
IntDict
IntList
JSONArray
JSONObject
LongDict
LongList
Object
String
StringDict
StringList
Table
TableRow
XML
*/

//Conversion

/*
Name
binary()
Examples
color c = color(255, 204, 0);
println(c);             // Prints "-13312"
println(binary(c));     // Prints "11111111111111111100110000000000"
println(binary(c, 16)); // Prints "1100110000000000"

Description    Converts an int, byte, char, or color to a String containing the equivalent binary notation. For example, the color value produced by color(0, 102, 153, 255) will convert to the String value "11111111000000000110011010011001". This function can help make your geeky debugging sessions much happier.

Note that the maximum number of digits is 32, because an int value can only represent up to 32 bits. Specifying more than 32 digits will have no effect.
Syntax
binary(value)
binary(value, digits)
Parameters
value    char, byte, or int: value to convert
digits    int: number of digits to return
Returns    String
Related    unbinary()
hex()
unhex()
*/
std::string binary(char * value);
std::string binary(int value);
std::string binary(char * value, int digits);
std::string binary(int value, int digits);

/*
Name
boolean()
Examples
String s = "true";
boolean b = boolean(s);
if (b) {
    println("The boolean is true");
} else {
    println("The boolean is false");
}
Description    Converts an int or String to its boolean representation. For an int, any non-zero value (positive or negative) evaluates to true, while zero evaluates to false. For a String, the value "true" evaluates to true, while any other value (including "false" or "hippopotamus") evaluates to false.

When an array of int or String values is passed in, then a boolean array of the same length is returned.
*/
#ifndef _RPCNDR_H
bool boolean(char * value);
bool boolean(int value);
std::vector<bool> boolean(std::vector<std::string> value);
std::vector<bool> boolean(std::vector<int> value);
#endif
/*
Name
byte()
Examples
char c = 'E';
byte b = byte(c);
println(c + " : " + b);  // Prints "E : 69"

int i = 130;
b = byte(i);
println(i + " : " + b);  // Prints "130 : -126"
Description    Converts any value of a primitive data type (boolean, byte, char, color, double, float, int, or long) to its byte representation. A byte can only be a whole number between -128 and 127, so when a value outside of this range is converted, it wraps around to the corresponding byte representation. (For example, byte(128) evaluates to -128.)

When an array of values is passed in, then a byte array of the same length is returned.
*/
//byte()

/*
Name
char()
Examples
int i = 65;
char c = char(i);
println(i + " : " + c);  // Prints "65 : A"

byte b = 65;
c = char(b);
println(b + " : " + c);  // Prints "65 : A"
Description    Converts any value of a primitive data type (boolean, byte, char, color, double, float, int, or long) to its numeric character representation.

When an array of values is passed in, then a char array of the same length is returned.
*/
//char()

/*
Name
float()
Examples
int i = 65;
float f = float(i);
println(i + " : " + f);  // Prints "65 : 65.0"
Description    Converts an int or String to its floating point representation. An int is easily converted to a float, but the contents of a String must resemble a number, or NaN (not a number) will be returned. For example, float("1234.56") evaluates to 1234.56, but float("giraffe") will return NaN.

When an array of int or String values is passed in, then a floating point array of the same length is returned.
*/
//float()

/*
Name
hex()
Examples
color c = #ffcc00;
println(c);          // Prints "-13312"
println(hex(c));     // Prints "FFFFCC00"
println(hex(c, 6));  // Prints "FFCC00"
color c = color(255, 204, 0);
println(c);          // Prints "-13312"
println(hex(c));     // Prints "FFFFCC00"
println(hex(c, 6));  // Prints "FFCC00"
Description    Converts an int, byte, char, or color to a String containing the equivalent hexadecimal notation. For example, the color value produced by color(0, 102, 153) will convert to the String value "FF006699". This function can help make your geeky debugging sessions much happier.

Note that the maximum number of digits is 8, because an int value can only represent up to 32 bits. Specifying more than 8 digits will not increase the length of the String further.
Syntax
hex(value)
hex(value, digits)
Parameters
value    int, char, or byte: the value to convert
digits    int: the number of digits (maximum 8)
Returns    String
Related    unhex()
binary()
unbinary()
*/
std::string hex(int value);
std::string hex(char value);
std::string hex(int value, int digits);
std::string hex(char value, int digits);

/*
Name
int()
Examples
float f = 65.0;
int i = int(f);
println(f + " : " + i);  // Prints "65.0 : 65"

char c = 'E';
i = int(c);
println(c + " : " + i);  // Prints "E : 69"
Description    Converts any value of a primitive data type (boolean, byte, char, color, float, int, or long) to its integer representation.

When an array of values is passed in, then an int array of the same length is returned.
*/
//int()

/*
Name
str()
Examples
boolean b = false;
byte y = -28;
char c = 'R';
float f = -32.6;
int i = 1024;

String sb = str(b);
String sy = str(y);
String sc = str(c);
String sf = str(f);
String si = str(i);

sb = sb + sy + sc + sf + si;

println(sb);  // Prints 'false-28R-32.61024'
Description    Converts a value of a primitive data type (boolean, byte, char, int, or float) to its String representation. For example, converting an integer with str(3) will return the String value of "3", converting a float with str(-12.6) will return "-12.6", and converting a boolean with str(true) will return "true".

When an array of values is passed in, then a String array of the same length is returned.
*/
//str()

/*
Name
unbinary()
Examples
String s1 = "00010000";
String s2 = "00001000";
String s3 = "00000100";
println(unbinary(s1));  // Prints "16"
println(unbinary(s2));  // Prints "8"
println(unbinary(s3));  // Prints "4"

int i1 = 10000;
int i2 = 1000;
int i3 = 100
println(unbinary(i1));  // Prints "16"
println(unbinary(i2));  // Prints "8"
println(unbinary(i3));  // Prints "4"
Description    Converts a String representation of a binary number to its equivalent integer value. For example, unbinary("00001000") will return 8. Alternately, converts an int representation of a binary number to its equivalent integer value. For example, unbinary(1000) will return 8.
Syntax
unbinary(value)
Parameters
value    String: String to convert to an integer
Returns    int
Related    binary()
hex()
unhex()
*/
int unbinary(std::string value);

/*
Name
unhex()
Examples
String hs = "FF006699";
int hi = unhex(hs);
fill(hi);
rect(30, 20, 55, 55);
Description    Converts a String representation of a hexadecimal number to its equivalent integer value.
Syntax
unhex(value)
Parameters
value    String: String to convert to an integer
Returns    int
Related    hex()
binary()
unbinary()
*/
int unhex(std::string value);

//String Functions
/*join()
match()
matchAll()
nf()
nfc()
nfp()
nfs()
split()
splitTokens()
trim()
Array Functions
append()
arrayCopy()
concat()
expand()
reverse()
shorten()
sort()
splice()
subset()*/

//Control
//Relational Operators
/*!= (inequality)
< (less than)
<= (less than or equal to)
== (equality)
> (greater than)
>= (greater than or equal to)*/

//Iteration
/*for
while*/

//Conditionals
/*?: (conditional)
break
case
continue
default
else
if
switch*/

//Logical Operators
/*! (logical NOT)
&& (logical AND)
|| (logical OR)*/

//Math

//Shape
/*
Name
PShape
Examples
PShape s;

void setup() {
    size(100, 100);
    // The file "bot.svg" must be in the data folder
    // of the current sketch to load successfully
    s = loadShape("bot.svg");
}

void draw() {
    shape(s, 10, 10, 80, 80);
}
PShape square;  // The PShape object

void setup() {
    size(100, 100);
    // Creating the PShape as a square. The corner
    // is 0,0 so that the center is at 40,40
    square = createShape(RECT, 0, 0, 80, 80);
}

void draw() {
    shape(square, 10, 10);
}
Description    Datatype for storing shapes. Before a shape is used, it must be loaded with the loadShape() or created with the createShape(). The shape() function is used to draw the shape to the display window. Processing can currently load and display SVG (Scalable Vector Graphics) and OBJ shapes. OBJ files can only be opened using the P3D renderer. The loadShape() function supports SVG files created with Inkscape and Adobe Illustrator. It is not a full SVG implementation, but offers some straightforward support for handling vector data.

The PShape object contains a group of methods that can operate on the shape data. Some of the methods are listed below, but the full list used for creating and modifying shapes is available here in the Processing Javadoc.

To create a new shape, use the createShape() function. Do not use the syntax new PShape().
Fields
width    Shape document width
height    Shape document height
Methods
isVisible()    Returns a boolean value "true" if the image is set to be visible, "false" if not
setVisible()    Sets the shape to be visible or invisible
disableStyle()    Disables the shape's style data and uses Processing styles
enableStyle()    Enables the shape's style data and ignores the Processing styles
beginContour()    Starts a new contour
endContour()    Ends a contour
beginShape()    Starts the creation of a new PShape
endShape()    Finishes the creation of a new PShape
getChildCount()    Returns the number of children
getChild()    Returns a child element of a shape as a PShape object
addChild()    Adds a new child
getVertexCount()    Returns the total number of vertices as an int
getVertex()    Returns the vertex at the index position
setVertex()    Sets the vertex at the index position
setFill()    Set the fill value
setStroke()    Set the stroke value
translate()    Displaces the shape
rotateX()    Rotates the shape around the x-axis
rotateY()    Rotates the shape around the y-axis
rotateZ()    Rotates the shape around the z-axis
rotate()    Rotates the shape
scale()    Increases and decreases the size of a shape
resetMatrix()    Replaces the current matrix of a shape with the identity matrix
Constructor
PShape(g, kind, params)
Related    loadShape()
createShape()
shapeMode()
*/
class PShape {
private:
    bool visible;
    std::vector<PShape> children;
    std::vector<PVector> vertexes;
    colorType fill;
    colorType stroke;
    int strokeWeight;
public:
    //Fields
    /*
    Class
    PShape

    Name
    width
    Examples
    PShape s;

    void setup() {
        // The file "bot.svg" must be in the data folder
        // of the current sketch to load successfully
        s = loadShape("bot.svg");
        println(s.width);  // Prints "281.0", the width of the shape
    }
    Description    The width of the PShape document.
    Syntax
    sh.width
    Parameters
    sh    PShape: any variable of type PShape
    Related    height
    */
    int width;    //Shape document width

    /*
    Class
    PShape

    Name
    height
    Examples
    PShape s;

    void setup() {
        // The file "bot.svg" must be in the data folder
        // of the current sketch to load successfully
        s = loadShape("bot.svg");
        println(s.height);  // Prints "281.0", the height of the shape
    }
    Description    The height of the PShape document.
    Syntax
    sh.height
    Parameters
    sh    PShape: any variable of type PShape
    Related    width
    */
    int height;    //Shape document height

    //Methods
    /*
    Class
    PShape

    Name
    isVisible()
    Examples
    example pic
    PShape s;

    void setup() {
        size(100, 100);
        // The file "bot.svg" must be in the data folder
        // of the current sketch to load successfully
        s = loadShape("bot.svg");
    }
    void draw() {
        background(204);
        shape(s, 10, 10, 80, 80);  // Draw shape
        s.setVisible(mousePressed);
        if (s.isVisible() == false) {  // Or use: "if (!s.isVisible)"
            noFill();
            rect(10, 10, 80, 80);
        }
    }
    Description    Returns a boolean value "true" if the image is set to be visible, "false" if not. This value can be modified with the setVisible() method.

        The default visibility of a shape is usually controlled by whatever program created the SVG file. For instance, this parameter is controlled by showing or hiding the shape in the layers palette in Adobe Illustrator.
        Syntax
        sh.isVisible()
        Parameters
        sh    PShape: any variable of type PShape
        Returns    boolean
        Related    setVisible()
    */
    bool isVisible();    //Returns a boolean value "true" if the image is set to be visible, "false" if not

    /*
    Class
    PShape

    Name
    setVisible()
    Examples
    PShape s;

    void setup() {
        size(100, 100);
        // The file "bot.svg" must be in the data folder
        // of the current sketch to load successfully
        s = loadShape("bot.svg");
    }
    void draw() {
        background(204);
        shape(s, 10, 10, 80, 80);  // Draw shape
        s.setVisible(mousePressed);
        if (s.isVisible() == false) {  // Or use: "if (!s.isVisible)"
            noFill();
            rect(10, 10, 80, 80);
        }
    }
    Description    Sets the shape to be visible or invisible. This is determined by the value of the visible parameter.

    The default visibility of a shape is usually controlled by whatever program created the SVG file. For instance, this parameter is controlled by showing or hiding the shape in the layers palette in Adobe Illustrator.
    Syntax
    sh.setVisible(visible)
    Parameters
    sh    PShape: any variable of type PShape
    visible    boolean: "false" makes the shape invisible and "true" makes it visible
    Returns    void
    Related    isVisible()
    */
    void setVisible(bool visible);    //Sets the shape to be visible or invisible

    /*
    Class
    PShape

    Name
    disableStyle()
    Examples
    example pic
    PShape s;

    void setup() {
        // The file "bot.svg" must be in the data folder
        // of the current sketch to load successfully
        s = loadShape("bot.svg");
    }

    void draw() {
        s.disableStyle();
        shape(s, -30, 10, 80, 80);
        s.enableStyle();
        shape(s, 50, 10, 80, 80);
    }
    Description    Disables the shape's style data and uses Processing's current styles. Styles include attributes such as colors, stroke weight, and stroke joints.
    Syntax
    sh.disableStyle()
    Parameters
    sh    PShape: any variable of type PShape
    Returns    void
    Related    enableStyle()
    */
    void disableStyle();    //Disables the shape's style data and uses Processing styles

    /*
    Class
    PShape

    Name
    enableStyle()
    Examples
    example pic
    PShape s;

    void setup() {
        // The file "bot.svg" must be in the data folder
        // of the current sketch to load successfully
        s = loadShape("bot.svg");
    }

    void draw() {
        s.disableStyle();
        shape(s, -30, 10, 80, 80);
        s.enableStyle();
        shape(s, 50, 10, 80, 80);
    }
    Description    Enables the shape's style data and ignores Processing's current styles. Styles include attributes such as colors, stroke weight, and stroke joints.
    Syntax
    sh.enableStyle()
    Parameters
    sh    PShape: any variable of type PShape
    Returns    void
    Related    disableStyle()
    */
    void enableStyle();    //Enables the shape's style data and ignores the Processing styles

    /*
    Class
    PShape

    Name
    beginContour()
    Examples
    PShape s;

    void setup() {
        size(100, 100);

        // Make a shape
        s = createShape();
        s.beginShape();
        s.noStroke();

        // Exterior part of shape
        s.vertex(-50,-50);
        s.vertex(50,-50);
        s.vertex(50,50);
        s.vertex(-50,50);

        // Interior part of shape
        s.beginContour();
        s.vertex(-20,-20);
        s.vertex(-20,20);
        s.vertex(20,20);
        s.vertex(20,-20);
        s.endContour();

        // Finish off shape
        s.endShape();
    }

    void draw() {
        background(52);
        translate(width/2, height/2);
        s.rotate(0.01);
        shape(s);
    }
    Description    The beginContour() and endContour() methods make it possible to define shapes with other shapes cut out of them. For example, the inside of a letter 'O'. These two functions are always used together, you'll never use one without the other. Between them, define the geometry you want to create. As you'll see when you run the example above, the second smaller shape is cut out of the first larger shape.

    The exterior shape and the interior contour must wind in opposite directions. This means that if the points of the geometry for the exterior shape are described in a clockwise order, the points on the interior shape are defined in a counterclockwise order.
        Syntax
        sh.beginContour()
        Parameters
        sh    PShape: any variable of type PShape
        Returns    void
        Related    endContour()
    */
    void beginContour();    //Starts a new contour

    /*
    Class
    PShape

    Name
    endContour()
    Examples
    PShape s;

    void setup() {
        size(100, 100);

        // Make a shape
        s = createShape();
        s.beginShape();
        s.noStroke();

        // Exterior part of shape
        s.vertex(-50,-50);
        s.vertex(50,-50);
        s.vertex(50,50);
        s.vertex(-50,50);

        // Interior part of shape
        s.beginContour();
        s.vertex(-20,-20);
        s.vertex(-20,20);
        s.vertex(20,20);
        s.vertex(20,-20);
        s.endContour();

        // Finish off shape
        s.endShape();
    }

    void draw() {
        background(52);
        translate(width/2, height/2);
        s.rotate(0.01);
        shape(s);
    }
    Description    The beginContour() and endContour() methods make it possible to define shapes with other shapes cut out of them. For example, the inside of a letter 'O'. These two functions are always used together, you'll never use one without the other. Between them, define the geometry you want to create. As you'll see when you run the example above, the second smaller shape is cut out of the first larger shape.

    The exterior shape and the interior contour must wind in opposite directions. This means that if the points of the geometry for the exterior shape are described in a clockwise order, the points on the interior shape are defined in a counterclockwise order.
        Syntax
        sh.endContour()
        Parameters
        sh    PShape: any variable of type PShape
        Returns    void
        Related    beginContour()
    */
    void endContour();    //Ends a contour

    /*
    Class
    PShape

    Name
    beginShape()
    Examples
    PShape s;  // The PShape object

    void setup() {
        size(100, 100);
        s = createShape();
        s.beginShape();
        s.fill(0, 0, 255);
        s.noStroke();
        s.vertex(0, 0);
        s.vertex(0, 50);
        s.vertex(50, 0);
        s.endShape();
    }

    void draw() {
        shape(s, 25, 25);
    }
    Description    This method is used to start a custom shape created with the createShape() function. It's always and only used with createShape().
    Syntax
    sh.beginShape()
    sh.beginShape(kind)
    Parameters
    sh    PShape: any variable of type PShape
    Returns    void
    Related    endShape()
    */
    void beginShape();    //Starts the creation of a new PShape

    /*
    Class
    PShape

    Name
    endShape()
    Examples
    PShape s;  // The PShape object

    void setup() {
        size(100, 100);
        s = createShape();
        s.beginShape();
        s.fill(0, 0, 255);
        s.noStroke();
        s.vertex(0, 0);
        s.vertex(0, 50);
        s.vertex(50, 0);
        s.endShape();
    }

    void draw() {
        shape(s, 25, 25);
    }
    Description    This method is used to complete a custom shape created with the createShape() function. It's always and only used with createShape().
    Syntax
    sh.endShape()
    sh.endShape(mode)
    Parameters
    sh    PShape: any variable of type PShape
    Returns    void
    Related    beginShape()
    */
    void endShape();    //Finishes the creation of a new PShape

    /*
    Class
    PShape

    Name
    getChildCount()
    Examples
    PShape states;

    void setup() {
        size(100, 100);
        states = loadShape("tristate.svg");
        int count = states.getChildCount();
        println(count);
    }
    Description    Returns the number of children within the PShape.
    Syntax
    sh.getChildCount()
    Parameters
    sh    PShape: any variable of type PShape
    Returns    int
    */
    int getChildCount();    //Returns the number of children

    /*
    Class
    PShape

    Name
    getChild()
    Examples
    example pic
    PShape states;
    PShape ohio;

    void setup() {
        size(100, 100);
        states = loadShape("tristate.svg");
        ohio = states.getChild("OH");
        ohio.disableStyle();
    }

    void draw() {
        background(0);
        shape(states, -48, 5);
        fill(102, 0, 0);
        shape(ohio, -48, 5);
    }
    Description    Extracts a child shape from a parent shape. Specify the name of the shape with the target parameter. The shape is returned as a PShape object, or null is returned if there is an error.
        Syntax
        sh.getChild(index)
        sh.getChild(target)
        Parameters
        sh    PShape: any variable of type PShape
        index    int: the layer position of the shape to get
        target    String: the name of the shape to get
        Returns    PShape
        Related    addChild()
    */
    PShape getChild(int index);    //Returns a child element of a shape as a PShape object
    //PShape getChild(std::string target);    //Returns a child element of a shape as a PShape object

    /*
    Class
    PShape

    Name
    addChild()
    Examples

    PShape group;

    void setup() {

        // Make a group PShape
        group = createShape(GROUP);

        // Make three shapes
        PShape path = createShape();
        path.beginShape();
        path.vertex(-20, -20);
        path.vertex(0, -40);
        path.vertex(20, -20);
        path.endShape();
        PShape rectangle = createShape(RECT, -20, -20, 40, 40);
        PShape circle = createShape(ELLIPSE, 0, 0, 20, 20);

        // Add all three as children
        group.addChild(path);
        group.addChild(rectangle);
        group.addChild(circle);
    }

    void draw() {
        background(52);
        translate(mouseX, mouseY);
        shape(group);
    }
    Description    This is a new reference entry for Processing 2.0. It will be updated shortly. For now, please check the Examples to see how to use this new syntax.
        Syntax
        sh.addChild(who)
        sh.addChild(who, idx)
        Parameters
        sh    PShape: any variable of type PShape
        who    PShape: any variable of type PShape
        idx    int: the layer position in which to insert the new child
        Returns    void
        Related    getChild()
    */
    void addChild(PShape who);    //Adds a new child
    void addChild(PShape who, int idx);    //Adds a new child

    /*
    Class
    PShape

    Name
    getVertexCount()
    Examples
    PShape s;

    void setup() {
        size(100, 100);
        s = createShape();
        s.beginShape();
        s.vertex(0, 0);
        s.vertex(60, 0);
        s.vertex(60, 60);
        s.vertex(0, 60);
        s.endShape(CLOSE);
    }

    void draw() {
        translate(20, 20);
        for (int i = 0; i < s.getVertexCount(); i++) {
            PVector v = s.getVertex(i);
            v.x += random(-1, 1);
            v.y += random(-1, 1);
            s.setVertex(i, v);
        }
        shape(s);
    }
    Description    The getVertexCount() method returns the number of vertices that make up a PShape. In the above example, the value 4 is returned by the getVertexCount() method because 4 vertices are defined in setup().
    Syntax
    sh.getVertexCount()
    Parameters
    sh    PShape: any variable of type PShape
    Returns    int
    Related    getVertex()
    setVertex()
    */
    int getVertexCount();    //Returns the total number of vertices as an int

    /*
    Class
    PShape

    Name
    getVertex()
    Examples
    PShape s;

    void setup() {
        size(100, 100);
        s = createShape();
        s.beginShape();
        s.vertex(0, 0);
        s.vertex(60, 0);
        s.vertex(60, 60);
        s.vertex(0, 60);
        s.endShape(CLOSE);
    }

    void draw() {
        translate(20, 20);
        for (int i = 0; i < s.getVertexCount(); i++) {
            PVector v = s.getVertex(i);
            v.x += random(-1, 1);
            v.y += random(-1, 1);
            s.setVertex(i, v);
        }
        shape(s);
    }
    Description    The getVertex() method returns a PVector with the coordinates of the vertex point located at the position defined by the index parameter. This method works when shapes are created as shown in the example above, but won't work properly when a shape is defined explicitly (e.g. createShape(RECT, 20, 20, 80, 80).
    Syntax
    sh.getVertex(index)
    sh.getVertex(index, vec)
    Parameters
    sh    PShape: any variable of type PShape
    index    int: the location of the vertex
    vec    PVector: PVector to assign the data to
    Returns    PVector
    Related    setVertex()
    getVertexCount()
    */
    PVector getVertex(int index);    //Returns the vertex at the index position
    PVector getVertex(int index, PVector &vec);    //Returns the vertex at the index position

    /*
    Class
    PShape

    Name
    setVertex()
    Examples
    PShape s;

    void setup() {
        size(100, 100);
        s = createShape();
        s.beginShape();
        s.vertex(0, 0);
        s.vertex(60, 0);
        s.vertex(60, 60);
        s.vertex(0, 60);
        s.endShape(CLOSE);
    }

    void draw() {
        translate(20, 20);
        for (int i = 0; i < s.getVertexCount(); i++) {
            PVector v = s.getVertex(i);
            v.x += random(-1, 1);
            v.y += random(-1, 1);
            s.setVertex(i, v);
        }
        shape(s);
    }
    Description    The setVertex() method defines the coordinates of the vertex point located at the position defined by the index parameter. This method works when shapes are created as shown in the example above, but won't work properly when a shape is defined explicitly (e.g. createShape(RECT, 20, 20, 80, 80).
    Syntax
    sh.setVertex(index, x, y)
    sh.setVertex(index, x, y, z)
    sh.setVertex(index, vec)
    Parameters
    sh    PShape: any variable of type PShape
    index    int: the location of the vertex
    x    float: the x value for the vertex
    y    float: the y value for the vertex
    z    float: the z value for the vertex
    vec    PVector: the PVector to define the x, y, z coordinates
    Returns    void
    Related    getVertex()
    getVertexCount()
    */
    void setVertex(int index, float x, float y);    //Sets the vertex at the index position
    void setVertex(int index, float x, float y, float z);    //Sets the vertex at the index position
    void setVertex(int index, PVector vec);    //Sets the vertex at the index position

    /*
    Class
    PShape

    Name
    setFill()
    Examples
    PShape circle;

    void setup() {
        size(640, 360, P2D);
        circle = createShape(ELLIPSE, 0, 0, 200, 200);
        circle.setStroke(color(255));
    }

    void draw() {
        background(51);
        circle.setFill(color(random(255)));
        translate(mouseX, mouseY);
        shape(circle);
    }

    Description    The setFill() method defines the fill color of a PShape. This method is used after shapes are created or when a shape is defined explicitly (e.g. createShape(RECT, 20, 20, 80, 80)) as shown in the above example. When a shape is created with beginShape() and endShape(), its attributes may be changed with fill() and stroke() within beginShape() and endShape(). However, after the shape is created, only the setFill() method can define a new fill value for the PShape.
    Syntax
        sh.setFill(fill)
    Parameters
        sh    PShape: any variable of type PShape
    Returns    void
    */
    void setFill(colorType fill);    //Set the fill value

    /*
    Class
    PShape

    Name
    setStroke()
    Examples
    PShape circle;

    void setup() {
        size(640, 360, P2D);
        circle = createShape(ELLIPSE, 0, 0, 200, 200);
        circle.setStroke(color(255));
    }

    void draw() {
        background(51);
        circle.setFill(color(random(255)));
        translate(mouseX, mouseY);
        shape(circle);
    }

    Description    The setStroke() method defines the outline color of a PShape. This method is used after shapes are created or when a shape is defined explicitly (e.g. createShape(RECT, 20, 20, 80, 80)) as shown in the above example. When a shape is created with beginShape() and endShape(), its attributes may be changed with fill() and stroke() within beginShape() and endShape(). However, after the shape is created, only the setStroke() method can define a new stroke value for the PShape.
    Syntax
        sh.setStroke(stroke)
    Parameters
        sh    PShape: any variable of type PShape
    Returns    void
    */
    void setStroke(colorType stroke);    //Set the stroke value

    /*
    Class
    PShape

    Name
    translate()
    Examples
    PShape s;

    void setup() {
        s = loadShape("bot.svg");
    }

    void draw() {
        background(204);
        shape(s);
    }

    void mousePressed() {
        // Move the shape 10 pixels right each time the mouse is pressed
        s.translate(10, 0);
    }
    Description    Specifies an amount to displace the shape. The x parameter specifies left/right translation, the y parameter specifies up/down translation, and the z parameter specifies translations toward/away from the screen. Subsequent calls to the method accumulates the effect. For example, calling translate(50, 0) and then translate(20, 0) is the same as translate(70, 0). This transformation is applied directly to the shape, it's not refreshed each time draw() is run.

    Using this method with the z parameter requires using the P3D parameter in combination with size.
    Syntax
    sh.translate(x, y)
    sh.translate(x, y, z)
    Parameters
    sh    PShape: any variable of type PShape
    x    float: left/right translation
    y    float: up/down translation
    z    float: forward/back translation
    Returns    void
    Related    rotate()
    scale()
    resetMatrix()
    */
    void translate(float x, float y);    //Displaces the shape
    void translate(float x, float y, float z);    //Displaces the shape

    /*
    Class
    PShape

    Name
    rotateX()
    Examples
    PShape s;

    void setup() {
        size(100, 100, P3D);
        s = loadShape("ohio.svg");
    }

    void draw() {
        background(204);
        shape(s);
    }

    void mousePressed() {
        // Rotate the shape around the x-axis each time the mouse is pressed
        s.rotateX(0.1);
    }
    Description    Rotates the shape around the x-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to TWO_PI) or converted from degrees to radians with the radians() method.

    Shapes are always rotated around the upper-left corner of their bounding box. Positive numbers rotate objects in a clockwise direction. Subsequent calls to the method accumulates the effect. For example, calling rotateX(HALF_PI) and then rotateX(HALF_PI) is the same as rotateX(PI). This transformation is applied directly to the shape, it's not refreshed each time draw() is run.

    This method requires a 3D renderer. You need to use P3D as a third parameter for the size() function as shown in the example above.
    Syntax
        sh.rotateX(angle)
    Parameters
        sh    PShape: any variable of type PShape
        angle    float: angle of rotation specified in radians
    Returns    void
    Related    rotate()
        rotateY()
        rotateZ()
        scale()
        translate()
        resetMatrix()
    */
    void rotateX(float angle);    //Rotates the shape around the x-axis

    /*
    Class
    PShape

    Name
    rotateY()
    Examples
    PShape s;

    void setup() {
        size(100, 100, P3D);
        s = loadShape("ohio.svg");
    }

    void draw() {
        background(204);
        shape(s);
    }

    void mousePressed() {
        // Rotate the shape around the y-axis each time the mouse is pressed
        s.rotateY(0.1);
    }
    Description    Rotates the shape around the y-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to TWO_PI) or converted from degrees to radians with the radians() method.

    Shapes are always rotated around the upper-left corner of their bounding box. Positive numbers rotate objects in a clockwise direction. Subsequent calls to the method accumulates the effect. For example, calling rotateY(HALF_PI) and then rotateY(HALF_PI) is the same as rotateY(PI). This transformation is applied directly to the shape, it's not refreshed each time draw() is run.

    This method requires a 3D renderer. You need to use P3D as a third parameter for the size() function as shown in the example above.
    Syntax
        sh.rotateY(angle)
    Parameters
        sh    PShape: any variable of type PShape
        angle    float: angle of rotation specified in radians
    Returns    void
    Related    rotate()
        rotateX()
        rotateZ()
        scale()
        translate()
        resetMatrix()
    */
    void rotateY(float angle);    //Rotates the shape around the y-axis

    /*
    Class
    PShape

    Name
    rotateZ()
    Examples
    PShape s;

    void setup() {
        size(100, 100, P3D);
        s = loadShape("ohio.svg");
    }

    void draw() {
        background(204);
        shape(s);
    }

    void mousePressed() {
        // Rotate the shape around the z-axis each time the mouse is pressed
        s.rotateZ(0.1);
    }
    Description    Rotates the shape around the z-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to TWO_PI) or converted from degrees to radians with the radians() method.

    Shapes are always rotated around the upper-left corner of their bounding box. Positive numbers rotate objects in a clockwise direction. Subsequent calls to the method accumulates the effect. For example, calling rotateZ(HALF_PI) and then rotateZ(HALF_PI) is the same as rotateZ(PI). This transformation is applied directly to the shape, it's not refreshed each time draw() is run.

    This method requires a 3D renderer. You need to use P3D as a third parameter for the size() function as shown in the example above.
    Syntax
        sh.rotateZ(angle)
    Parameters
        sh    PShape: any variable of type PShape
        angle    float: angle of rotation specified in radians
    Returns    void
    Related    rotate()
        rotateX()
        rotateY()
        scale()
        translate()
        resetMatrix()
    */
    void rotateZ(float angle);    //Rotates the shape around the z-axis

    /*
    Class
    PShape

    Name
    rotate()
    Examples
    PShape s;

    void setup() {
        size(100, 100);
        s = loadShape("ohio.svg");
    }

    void draw() {
        background(204);
        shape(s);
    }

    void mousePressed() {
        // Rotate the shape each time the mouse is pressed
        s.rotate(0.1);
    }
    Description    Rotates the shape the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to TWO_PI) or converted from degrees to radians with the radians() method.

    Shapes are always rotated around the upper-left corner of their bounding box. Positive numbers rotate objects in a clockwise direction. Transformations apply to everything that happens after and subsequent calls to the method accumulates the effect. For example, calling rotate(HALF_PI) and then rotate(HALF_PI) is the same as rotate(PI). This transformation is applied directly to the shape, it's not refreshed each time draw() is run.
    Syntax
    sh.rotate(angle)
    Parameters
    sh    PShape: any variable of type PShape
    angle    float: angle of rotation specified in radians
    Returns    void
    Related    rotateX()
    rotateY()
    rotateZ()
    scale()
    translate()
    resetMatrix()
    */
    void rotate(float angle);    //Rotates the shape

    /*
    Class
    PShape

    Name
    scale()
    Examples
    PShape s;

    void setup() {
        s = loadShape("bot.svg");
    }

    void draw() {
        background(204);
        shape(s);
    }

    void mousePressed() {
        // Shrink the shape 90% each time the mouse is pressed
        s.scale(0.9);
    }
    Description    Increases or decreases the size of a shape by expanding and contracting vertices. Shapes always scale from the relative origin of their bounding box. Scale values are specified as decimal percentages. For example, the method call scale(2.0) increases the dimension of a shape by 200%. Subsequent calls to the method multiply the effect. For example, calling scale(2.0) and then scale(1.5) is the same as scale(3.0). This transformation is applied directly to the shape; it's not refreshed each time draw() is run.

    Using this method with the z parameter requires using the P3D parameter in combination with size.
    Syntax
    sh.scale(s)
    sh.scale(x, y)
    sh.scale(x, y, z)
    Parameters
    sh    PShape: any variable of type PShape
    s    float: percentate to scale the object
    x    float: percentage to scale the object in the x-axis
    y    float: percentage to scale the object in the y-axis
    z    float: percentage to scale the object in the z-axis
    Returns    void
    Related    rotate()
    translate()
    resetMatrix()
    */
    void scale(float s);    //Increases and decreases the size of a shape
    void scale(float x, float y);    //Increases and decreases the size of a shape
    void scale(float x, float y, float z);    //Increases and decreases the size of a shape

    /*
    Class
    PShape

    Name
    resetMatrix()
    Examples
    PShape s;

    void setup() {
        size(100, 100);
        s = loadShape("ohio.svg");
        s.rotate(PI/6);
    }

    void draw() {
        background(204);
        shape(s);
    }

    void mousePressed() {
        // Removes all transformations applied to shape
        // Loads the identity matrix
        s.resetMatrix();
    }
    Description    Replaces the current matrix of a shape with the identity matrix. The equivalent function in OpenGL is glLoadIdentity().
    Syntax
    sh.resetMatrix()
    Parameters
    sh    PShape: any variable of type PShape
    Returns    void
    Related    rotate()
    scale()
    translate()
    */
    void resetMatrix();    //Replaces the current matrix of a shape with the identity matrix

    //Constructor
    //PShape(g, kind, params)
};

/*
Name
createShape()
Examples
PShape square;  // The PShape object

void setup() {
    size(100, 100);
    // Creating the PShape as a square. The
    // numeric arguments are similar to rect().
    square = createShape(RECT, 0, 0, 50, 50);
    square.setFill(color(0, 0, 255));
    square.setStroke(false);
}

void draw() {
    shape(square, 25, 25);
}
PShape s;  // The PShape object

void setup() {
    size(100, 100);
    // Creating a custom PShape as a square, by
    // specifying a series of vertices.
    s = createShape();
    s.beginShape();
    s.fill(0, 0, 255);
    s.noStroke();
    s.vertex(0, 0);
    s.vertex(0, 50);
    s.vertex(50, 50);
    s.vertex(50, 0);
    s.endShape(CLOSE);
}

void draw() {
    shape(s, 25, 25);
}
PShape s;

void setup() {
    size(100, 100, P2D);
    s = createShape();
    s.beginShape(TRIANGLE_STRIP);
    s.vertex(30, 75);
    s.vertex(40, 20);
    s.vertex(50, 75);
    s.vertex(60, 20);
    s.vertex(70, 75);
    s.vertex(80, 20);
    s.vertex(90, 75);
    s.endShape();
}

void draw() {
    shape(s, 0, 0);
}
PShape alien, head, body;

void setup() {
    size(100, 100);

    // Create the shape group
    alien = createShape(GROUP);

    // Make two shapes
    ellipseMode(CORNER);
    head = createShape(ELLIPSE, -25, 0, 50, 50);
    head.setFill(color(255));
    body = createShape(RECT, -25, 45, 50, 40);
    body.setFill(color(0));

    // Add the two "child" shapes to the parent group
    alien.addChild(body);
    alien.addChild(head);
}

void draw() {
    background(204);
    translate(50, 15);
    shape(alien); // Draw the group
}
Description    The createShape() function is used to define a new shape. Once created, this shape can be drawn with the shape() function. The basic way to use the function defines new primitive shapes. One of the following parameters are used as the first parameter: ELLIPSE, RECT, ARC, TRIANGLE, SPHERE, BOX, QUAD, or LINE. The parameters for each of these different shapes are the same as their corresponding functions: ellipse(), rect(), arc(), triangle(), sphere(), box(), quad(), and line(). The first example above clarifies how this works.

Custom, unique shapes can be made by using createShape() without a parameter. After the shape is started, the drawing attributes and geometry can be set directly to the shape within the beginShape() and endShape() methods. See the second example above for specifics, and the reference for beginShape() for all of its options.

The createShape() function can also be used to make a complex shape made of other shapes. This is called a "group" and it's created by using the parameter GROUP as the first parameter. See the fourth example above to see how it works.

After using createShape(), stroke and fill color can be set by calling methods like setFill() and setStroke(), as seen in the examples above. The complete list of methods and fields for the PShape class are in the Processing Javadoc.
Syntax
createShape()
createShape(type)
createShape(kind, p)
Parameters
kind    int: either POINT, LINE, TRIANGLE, QUAD, RECT, ELLIPSE, ARC, BOX, SPHERE
p    float[]: parameters that match the kind of shape
Returns    PShape
Related    PShape
endShape()
loadShape()
*/
PShape createShape();
PShape createShape(int kind);
PShape createShape(int kind, float p[]);

/*
Name
loadShape()
Examples
PShape s;

void setup() {
    size(100, 100);
    // The file "bot.svg" must be in the data folder
    // of the current sketch to load successfully
    s = loadShape("bot.svg");
}

void draw() {
    shape(s, 10, 10, 80, 80);
}
PShape s;

void setup() {
    size(100, 100, P3D);
    // The file "bot.obj" must be in the data folder
    // of the current sketch to load successfully
    s = loadShape("bot.obj");
}

void draw() {
    background(204);
    translate(width/2, height/2);
    shape(s, 0, 0);
}
Description    Loads geometry into a variable of type PShape. SVG and OBJ files may be loaded. To load correctly, the file must be located in the data directory of the current sketch. In most cases, loadShape() should be used inside setup() because loading shapes inside draw() will reduce the speed of a sketch.

Alternatively, the file maybe be loaded from anywhere on the local computer using an absolute path (something that starts with / on Unix and Linux, or a drive letter on Windows), or the filename parameter can be a URL for a file found on a network.

If the file is not available or an error occurs, null will be returned and an error message will be printed to the console. The error message does not halt the program, however the null value may cause a NullPointerException if your code does not check whether the value returned is null.
Syntax
loadShape(filename)
Parameters
filename    String: name of file to load, can be .svg or .obj
Returns    PShape
Related    PShape
createShape()
*/
PShape loadShape(std::string filename);

//2D Primitives
/*
Name
arc()
Examples
example pic
arc(50, 55, 50, 50, 0, HALF_PI);
noFill();
arc(50, 55, 60, 60, HALF_PI, PI);
arc(50, 55, 70, 70, PI, PI+QUARTER_PI);
arc(50, 55, 80, 80, PI+QUARTER_PI, TWO_PI);
example pic
arc(50, 50, 80, 80, 0, PI+QUARTER_PI, OPEN);
example pic
arc(50, 50, 80, 80, 0, PI+QUARTER_PI, CHORD);
example pic
arc(50, 50, 80, 80, 0, PI+QUARTER_PI, PIE);
Description    Draws an arc to the screen. Arcs are drawn along the outer edge of an ellipse defined by the a, b, c, and d parameters. The origin of the arc's ellipse may be changed with the ellipseMode() function. Use the start and stop parameters to specify the angles (in radians) at which to draw the arc.

There are three ways to draw an arc; the rendering technique used is defined by the optional seventh parameter. The three options, depicted in the above examples, are PIE, OPEN, and CHORD. The default mode is the OPEN stroke with a PIE fill.

In some cases, the arc() function isn't accurate enough for smooth drawing. For example, the shape may jitter on screen when rotating slowly. If you're having an issue with how arcs are rendered, you'll need to draw the arc yourself with beginShape()/endShape() or a PShape.
Syntax
arc(a, b, c, d, start, stop)
arc(a, b, c, d, start, stop, mode)
Parameters
a    float: x-coordinate of the arc's ellipse
b    float: y-coordinate of the arc's ellipse
c    float: width of the arc's ellipse by default
d    float: height of the arc's ellipse by default
start    float: angle to start the arc, specified in radians
stop    float: angle to stop the arc, specified in radians
Returns    void
Related    ellipse()
ellipseMode()
radians()
degrees()
*/
void arc(float a, float b, float c, float d, float start, float stop);
void arc(float a, float b, float c, float d, float start, float stop, int mode);

/*
Name
circle()
Examples
example pic
circle(56, 46, 55);
Description    Draws a circle to the screen. By default, the first two parameters set the location of the center, and the third sets the shape's width and height. The origin may be changed with the ellipseMode() function.
Syntax
circle(x, y, extent)
Parameters
x    float: x-coordinate of the ellipse
y    float: y-coordinate of the ellipse
extent    float: width and height of the ellipse by default
Returns    void
Related    ellipse()
ellipseMode()
*/
void circle(float x, float y, float extent);

/*
Name
ellipse()
Examples
example pic
ellipse(56, 46, 55, 55);
Description    Draws an ellipse (oval) to the screen. An ellipse with equal width and height is a circle. By default, the first two parameters set the location, and the third and fourth parameters set the shape's width and height. The origin may be changed with the ellipseMode() function.
Syntax
ellipse(a, b, c, d)
Parameters
a    float: x-coordinate of the ellipse
b    float: y-coordinate of the ellipse
c    float: width of the ellipse by default
d    float: height of the ellipse by default
Returns    void
Related    ellipseMode()
arc()
*/
void ellipse(float a, float b, float c, float d);

/*
Name
line()
Examples
example pic
line(30, 20, 85, 75);
example pic
line(30, 20, 85, 20);
stroke(126);
line(85, 20, 85, 75);
stroke(255);
line(85, 75, 30, 75);
example pic
// Drawing lines in 3D requires P3D
// as a parameter to size()
size(100, 100, P3D);
line(30, 20, 0, 85, 20, 15);
stroke(126);
line(85, 20, 15, 85, 75, 0);
stroke(255);
line(85, 75, 0, 30, 75, -50);
Description    Draws a line (a direct path between two points) to the screen. The version of line() with four parameters draws the line in 2D. To color a line, use the stroke() function. A line cannot be filled, therefore the fill() function will not affect the color of a line. 2D lines are drawn with a width of one pixel by default, but this can be changed with the strokeWeight() function. The version with six parameters allows the line to be placed anywhere within XYZ space. Drawing this shape in 3D with the z parameter requires the P3D parameter in combination with size() as shown in the above example.
Syntax
line(x1, y1, x2, y2)
line(x1, y1, z1, x2, y2, z2)
Parameters
x1    float: x-coordinate of the first point
y1    float: y-coordinate of the first point
x2    float: x-coordinate of the second point
y2    float: y-coordinate of the second point
z1    float: z-coordinate of the first point
z2    float: z-coordinate of the second point
Returns    void
Related    strokeWeight()
strokeJoin()
strokeCap()
beginShape()
*/
void line(float x1, float y1, float x2, float y2);
void line(float x1, float y1, float z1, float x2, float y2, float z2);

/*
Name
point()
Examples
example pic
noSmooth();
point(30, 20);
point(85, 20);
point(85, 75);
point(30, 75);
example pic
size(100, 100, P3D);
noSmooth();
point(30, 20, -50);
point(85, 20, -50);
point(85, 75, -50);
point(30, 75, -50);
Description    Draws a point, a coordinate in space at the dimension of one pixel. The first parameter is the horizontal value for the point, the second value is the vertical value for the point, and the optional third value is the depth value. Drawing this shape in 3D with the z parameter requires the P3D parameter in combination with size() as shown in the above example.

Use stroke() to set the color of a point().
Syntax
point(x, y)
point(x, y, z)
Parameters
x    float: x-coordinate of the point
y    float: y-coordinate of the point
z    float: z-coordinate of the point
Returns    void
Related    stroke()
*/
void point(float x, float y);
void point(float x, float y, float z);

/*
Name
quad()
Examples
example pic
quad(38, 31, 86, 20, 69, 63, 30, 76);
Description    A quad is a quadrilateral, a four sided polygon. It is similar to a rectangle, but the angles between its edges are not constrained to ninety degrees. The first pair of parameters (x1,y1) sets the first vertex and the subsequent pairs should proceed clockwise or counter-clockwise around the defined shape.
Syntax
quad(x1, y1, x2, y2, x3, y3, x4, y4)
Parameters
x1    float: x-coordinate of the first corner
y1    float: y-coordinate of the first corner
x2    float: x-coordinate of the second corner
y2    float: y-coordinate of the second corner
x3    float: x-coordinate of the third corner
y3    float: y-coordinate of the third corner
x4    float: x-coordinate of the fourth corner
y4    float: y-coordinate of the fourth corner
Returns    void
*/
void quad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);

/*
Name
rect()
Examples
example pic
rect(30, 20, 55, 55);
example pic
rect(30, 20, 55, 55, 7);
example pic
rect(30, 20, 55, 55, 3, 6, 12, 18);
Description    Draws a rectangle to the screen. A rectangle is a four-sided shape with every angle at ninety degrees. By default, the first two parameters set the location of the upper-left corner, the third sets the width, and the fourth sets the height. The way these parameters are interpreted, however, may be changed with the rectMode() function.

To draw a rounded rectangle, add a fifth parameter, which is used as the radius value for all four corners.

To use a different radius value for each corner, include eight parameters. When using eight parameters, the latter four set the radius of the arc at each corner separately, starting with the top-left corner and moving clockwise around the rectangle.
Syntax
rect(a, b, c, d)
rect(a, b, c, d, r)
rect(a, b, c, d, tl, tr, br, bl)
Parameters
a    float: x-coordinate of the rectangle by default
b    float: y-coordinate of the rectangle by default
c    float: width of the rectangle by default
d    float: height of the rectangle by default
r    float: radii for all four corners
tl    float: radius for top-left corner
tr    float: radius for top-right corner
br    float: radius for bottom-right corner
bl    float: radius for bottom-left corner
Returns    void
Related    rectMode()
quad()
*/
void rect(float a, float b, float c, float d);
void rect(float a, float b, float c, float d, float r);
void rect(float a, float b, float c, float d, float tl, float tr, float br, float bl);

/*
Name
square()
Examples
example pic
square(30, 20, 55);
Description    Draws a square to the screen. A square is a four-sided shape with every angle at ninety degrees and each side is the same length. By default, the first two parameters set the location of the upper-left corner, the third sets the width and height. The way these parameters are interpreted, however, may be changed with the rectMode() function.
Syntax
square(x, y, extent)
Parameters
x    float: x-coordinate of the rectangle by default
y    float: y-coordinate of the rectangle by default
extent    float: width and height of the rectangle by default
Returns    void
Related    rect()
rectMode()
*/
void square(float x, float y, float extent);

/*
Name
triangle()
Examples
example pic
triangle(30, 75, 58, 20, 86, 75);
Description    A triangle is a plane created by connecting three points. The first two arguments specify the first point, the middle two arguments specify the second point, and the last two arguments specify the third point.
Syntax
triangle(x1, y1, x2, y2, x3, y3)
Parameters
x1    float: x-coordinate of the first point
y1    float: y-coordinate of the first point
x2    float: x-coordinate of the second point
y2    float: y-coordinate of the second point
x3    float: x-coordinate of the third point
y3    float: y-coordinate of the third point
Returns    void
Related    beginShape()
*/
void triangle(float x1, float y1, float x2, float y2, float x3, float y3);

//Curves
/*
Name
bezier()
Examples
example pic
noFill();
stroke(255, 102, 0);
line(85, 20, 10, 10);
line(90, 90, 15, 80);
stroke(0, 0, 0);
bezier(85, 20, 10, 10, 90, 90, 15, 80);
example pic
noFill();
stroke(255, 102, 0);
line(30, 20, 80, 5);
line(80, 75, 30, 75);
stroke(0, 0, 0);
bezier(30, 20,  80, 5,  80, 75,  30, 75);
Description    Draws a Bezier curve on the screen. These curves are defined by a series of anchor and control points. The first two parameters specify the first anchor point and the last two parameters specify the other anchor point. The middle parameters specify the control points which define the shape of the curve. Bezier curves were developed by French engineer Pierre Bezier. Using the 3D version requires rendering with P3D (see the Environment reference for more information).
Syntax
bezier(x1, y1, x2, y2, x3, y3, x4, y4)
bezier(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4)
Parameters
x1    float: coordinates for the first anchor point
y1    float: coordinates for the first anchor point
z1    float: coordinates for the first anchor point
x2    float: coordinates for the first control point
y2    float: coordinates for the first control point
z2    float: coordinates for the first control point
x3    float: coordinates for the second control point
y3    float: coordinates for the second control point
z3    float: coordinates for the second control point
x4    float: coordinates for the second anchor point
y4    float: coordinates for the second anchor point
z4    float: coordinates for the second anchor point
Returns    void
Related    bezierVertex()
curve()
*/
void bezier(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
void bezier(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);

/*
Name
bezierDetail()
Examples
// Move the mouse left and right to see the detail change

void setup() {
    size(100, 100, P3D);
    noFill();
}

void draw() {
    background(204);
    int d = int(map(mouseX, 0, 100, 1, 20));
    bezierDetail(d);
    bezier(85, 20, 10, 10, 90, 90, 15, 80);
}
Description    Sets the resolution at which Beziers display. The default value is 20. This function is only useful when using the P3D renderer; the default P2D renderer does not use this information.
Syntax
bezierDetail(detail)
Parameters
detail    int: resolution of the curves
Returns    void
Related    curve()
curveVertex()
curveTightness()
*/
void bezierDetail(int detail);

/*
Name
bezierPoint()
Examples
example pic
noFill();
bezier(85, 20, 10, 10, 90, 90, 15, 80);
fill(255);
int steps = 10;
for (int i = 0; i <= steps; i++) {
    float t = i / float(steps);
    float x = bezierPoint(85, 10, 90, 15, t);
    float y = bezierPoint(20, 10, 90, 80, t);
    ellipse(x, y, 5, 5);
}
Description    Evaluates the Bezier at point t for points a, b, c, d. The parameter t varies between 0 and 1, a and d are points on the curve, and b and c are the control points. This can be done once with the x coordinates and a second time with the y coordinates to get the location of a bezier curve at t.
Syntax
bezierPoint(a, b, c, d, t)
Parameters
a    float: coordinate of first point on the curve
b    float: coordinate of first control point
c    float: coordinate of second control point
d    float: coordinate of second point on the curve
t    float: value between 0 and 1
Returns    float
Related    bezier()
bezierVertex()
curvePoint()
*/
float bezierPoint(float a, float b, float c, float d, float t);

/*
Name
bezierTangent()
Examples
example pic
noFill();
bezier(85, 20, 10, 10, 90, 90, 15, 80);
int steps = 6;
fill(255);
for (int i = 0; i <= steps; i++) {
    float t = i / float(steps);
    // Get the location of the point
    float x = bezierPoint(85, 10, 90, 15, t);
    float y = bezierPoint(20, 10, 90, 80, t);
    // Get the tangent points
    float tx = bezierTangent(85, 10, 90, 15, t);
    float ty = bezierTangent(20, 10, 90, 80, t);
    // Calculate an angle from the tangent points
    float a = atan2(ty, tx);
    a += PI;
    stroke(255, 102, 0);
    line(x, y, cos(a)*30 + x, sin(a)*30 + y);
    // The following line of code makes a line
    // inverse of the above line
    //line(x, y, cos(a)*-30 + x, sin(a)*-30 + y);
    stroke(0);
    ellipse(x, y, 5, 5);
}
example pic
noFill();
bezier(85, 20, 10, 10, 90, 90, 15, 80);
stroke(255, 102, 0);
int steps = 16;
for (int i = 0; i <= steps; i++) {
    float t = i / float(steps);
    float x = bezierPoint(85, 10, 90, 15, t);
    float y = bezierPoint(20, 10, 90, 80, t);
    float tx = bezierTangent(85, 10, 90, 15, t);
    float ty = bezierTangent(20, 10, 90, 80, t);
    float a = atan2(ty, tx);
    a -= HALF_PI;
    line(x, y, cos(a)*8 + x, sin(a)*8 + y);
}
Description    Calculates the tangent of a point on a Bezier curve. There is a good definition of tangent on Wikipedia.
Syntax
bezierTangent(a, b, c, d, t)
Parameters
a    float: coordinate of first point on the curve
b    float: coordinate of first control point
c    float: coordinate of second control point
d    float: coordinate of second point on the curve
t    float: value between 0 and 1
Returns    float
Related    bezier()
bezierVertex()
curvePoint()
*/
float bezierTangent(float a, float b, float c, float d, float t);

/*
Name
curve()
Examples
example pic
noFill();
stroke(255, 102, 0);
curve(5, 26, 5, 26, 73, 24, 73, 61);
stroke(0);
curve(5, 26, 73, 24, 73, 61, 15, 65);
stroke(255, 102, 0);
curve(73, 24, 73, 61, 15, 65, 15, 65);
Description    Draws a curved line on the screen. The first and second parameters specify the beginning control point and the last two parameters specify the ending control point. The middle parameters specify the start and stop of the curve. Longer curves can be created by putting a series of curve() functions together or using curveVertex(). An additional function called curveTightness() provides control for the visual quality of the curve. The curve() function is an implementation of Catmull-Rom splines. Using the 3D version requires rendering with P3D (see the Environment reference for more information).
Syntax
curve(x1, y1, x2, y2, x3, y3, x4, y4)
curve(x1, y1, z1, x2, y2, z2, x3, y3, z3, x4, y4, z4)
Parameters
x1    float: coordinates for the beginning control point
y1    float: coordinates for the beginning control point
x2    float: coordinates for the first point
y2    float: coordinates for the first point
x3    float: coordinates for the second point
y3    float: coordinates for the second point
x4    float: coordinates for the ending control point
y4    float: coordinates for the ending control point
z1    float: coordinates for the beginning control point
z2    float: coordinates for the first point
z3    float: coordinates for the second point
z4    float: coordinates for the ending control point
Returns    void
Related    curveVertex()
curveTightness()
bezier()
*/
void curve(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4);
void curve(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);

/*
Name
curveDetail()
Examples
example pic
void setup() {
    size(100, 100, P3D);
    noFill();
    noLoop();
}

void draw() {
    curveDetail(1);
    drawCurves(-15);
    stroke(126);
    curveDetail(2);
    drawCurves(0);
    stroke(255);
    curveDetail(4);
    drawCurves(15);
}

void drawCurves(float y) {
    curve( 5, 28+y,  5, 28+y, 73, 26+y, 73, 63+y);
    curve( 5, 28+y, 73, 26+y, 73, 63+y, 15, 67+y);
    curve(73, 26+y, 73, 63+y, 15, 67+y, 15, 67+y);
}

Description    Sets the resolution at which curves display. The default value is 20. This function is only useful when using the P3D renderer as the default P2D renderer does not use this information.
Syntax
curveDetail(detail)
Parameters
detail    int: resolution of the curves
Returns    void
Related    curve()
curveVertex()
curveTightness()
*/
void curveDetail(int detail);

/*
Name
curvePoint()
Examples
example pic
noFill();
curve(5, 26, 5, 26, 73, 24, 73, 61);
curve(5, 26, 73, 24, 73, 61, 15, 65);
fill(255);
ellipseMode(CENTER);
int steps = 6;
for (int i = 0; i <= steps; i++) {
    float t = i / float(steps);
    float x = curvePoint(5, 5, 73, 73, t);
    float y = curvePoint(26, 26, 24, 61, t);
    ellipse(x, y, 5, 5);
    x = curvePoint(5, 73, 73, 15, t);
    y = curvePoint(26, 24, 61, 65, t);
    ellipse(x, y, 5, 5);
}
Description    Evaluates the curve at point t for points a, b, c, d. The parameter t may range from 0 (the start of the curve) and 1 (the end of the curve). a and d are points on the curve, and b and c are the control points. This can be used once with the x coordinates and a second time with the y coordinates to get the location of a curve at t.
Syntax
curvePoint(a, b, c, d, t)
Parameters
a    float: coordinate of first point on the curve
b    float: coordinate of second point on the curve
c    float: coordinate of third point on the curve
d    float: coordinate of fourth point on the curve
t    float: value between 0 and 1
Returns    float
Related    curve()
curveVertex()
bezierPoint()
*/
float curvePoint(float a, float b, float c, float d, float t);

/*
Name
curveTangent()
Examples
example pic
noFill();
curve(5, 26, 73, 24, 73, 61, 15, 65);
int steps = 6;
for (int i = 0; i <= steps; i++) {
    float t = i / float(steps);
    float x = curvePoint(5, 73, 73, 15, t);
    float y = curvePoint(26, 24, 61, 65, t);
    //ellipse(x, y, 5, 5);
    float tx = curveTangent(5, 73, 73, 15, t);
    float ty = curveTangent(26, 24, 61, 65, t);
    float a = atan2(ty, tx);
    a -= PI/2.0;
    line(x, y, cos(a)*8 + x, sin(a)*8 + y);
}
Description    Calculates the tangent of a point on a curve. There's a good definition of tangent on Wikipedia.
Syntax
curveTangent(a, b, c, d, t)
Parameters
a    float: coordinate of first point on the curve
b    float: coordinate of first control point
c    float: coordinate of second control point
d    float: coordinate of second point on the curve
t    float: value between 0 and 1
Returns    float
Related    curve()
curveVertex()
curvePoint()
bezierTangent()
*/
float curveTangent(float a, float b, float c, float d, float z);

/*
Name
curveTightness()
Examples
// Move the mouse left and right to see the curve change

void setup() {
    size(100, 100);
    noFill();
}

void draw() {
    background(204);
    float t = map(mouseX, 0, width, -5, 5);
    curveTightness(t);
    beginShape();
    curveVertex(10, 26);
    curveVertex(10, 26);
    curveVertex(83, 24);
    curveVertex(83, 61);
    curveVertex(25, 65);
    curveVertex(25, 65);
    endShape();
}
Description    Modifies the quality of forms created with curve() and curveVertex(). The parameter tightness determines how the curve fits to the vertex points. The value 0.0 is the default value for tightness (this value defines the curves to be Catmull-Rom splines) and the value 1.0 connects all the points with straight lines. Values within the range -5.0 and 5.0 will deform the curves but will leave them recognizable and as values increase in magnitude, they will continue to deform.
Syntax
curveTightness(tightness)
Parameters
tightness    float: amount of deformation from the original vertices
Returns    void
Related    curve()
curveVertex()
*/
void curveTightness(float tightness);

//3D Primitives
/*
Name
box()
Examples
example pic
size(100, 100, P3D);
translate(58, 48, 0);
rotateY(0.5);
noFill();
box(40);
example pic
size(100, 100, P3D);
translate(58, 48, 0);
rotateY(0.5);
noFill();
box(40, 20, 50);
Description    A box is an extruded rectangle. A box with equal dimensions on all sides is a cube.
Syntax
box(size)
box(w, h, d)
Parameters
size    float: dimension of the box in all dimensions (creates a cube)
w    float: dimension of the box in the x-dimension
h    float: dimension of the box in the y-dimension
d    float: dimension of the box in the z-dimension
Returns    void
Related    sphere()
*/
void box(float size);
void box(float w, float h, float d);

/*
Name
sphere()
Examples
example pic
noStroke();
lights();
translate(58, 48, 0);
sphere(28);
Description    A sphere is a hollow ball made from tessellated triangles.
Syntax
sphere(r)
Parameters
r    float: the radius of the sphere
Returns    void
Related    sphereDetail()
*/
void sphere(float r);

/*
Name
sphereDetail()
Examples
void setup() {
    size(100, 100, P3D);
}

void draw() {
    background(200);
    stroke(255, 50);
    translate(50, 50, 0);
    rotateX(mouseY * 0.05);
    rotateY(mouseX * 0.05);
    fill(mouseX * 2, 0, 160);
    sphereDetail(mouseX / 4);
    sphere(40);
}
Description    Controls the detail used to render a sphere by adjusting the number of vertices of the sphere mesh. The default resolution is 30, which creates a fairly detailed sphere definition with vertices every 360/30 = 12 degrees. If you're going to render a great number of spheres per frame, it is advised to reduce the level of detail using this function. The setting stays active until sphereDetail() is called again with a new parameter and so should not be called prior to every sphere() statement, unless you wish to render spheres with different settings, e.g. using less detail for smaller spheres or ones further away from the camera. To control the detail of the horizontal and vertical resolution independently, use the version of the functions with two parameters.
Syntax
sphereDetail(res)
sphereDetail(ures, vres)
Parameters
res    int: number of segments (minimum 3) used per full circle revolution
ures    int: number of segments used longitudinally per full circle revolutoin
vres    int: number of segments used latitudinally from top to bottom
Returns    void
Related    sphere()
*/
void sphereDetail(int res);
void sphereDetail(int ures, int vres);

//Attributes
/*
Name
ellipseMode()
Examples
example pic
ellipseMode(RADIUS);  // Set ellipseMode to RADIUS
fill(255);  // Set fill to white
ellipse(50, 50, 30, 30);  // Draw white ellipse using RADIUS mode

ellipseMode(CENTER);  // Set ellipseMode to CENTER
fill(100);  // Set fill to gray
ellipse(50, 50, 30, 30);  // Draw gray ellipse using CENTER mode
example pic
ellipseMode(CORNER);  // Set ellipseMode is CORNER
fill(255);  // Set fill to white
ellipse(25, 25, 50, 50);  // Draw white ellipse using CORNER mode

ellipseMode(CORNERS);  // Set ellipseMode to CORNERS
fill(100);  // Set fill to gray
ellipse(25, 25, 50, 50);  // Draw gray ellipse using CORNERS mode
Description    Modifies the location from which ellipses are drawn by changing the way in which parameters given to ellipse() are intepreted.

The default mode is ellipseMode(CENTER), which interprets the first two parameters of ellipse() as the shape's center point, while the third and fourth parameters are its width and height.

ellipseMode(RADIUS) also uses the first two parameters of ellipse() as the shape's center point, but uses the third and fourth parameters to specify half of the shapes's width and height.

ellipseMode(CORNER) interprets the first two parameters of ellipse() as the upper-left corner of the shape, while the third and fourth parameters are its width and height.

ellipseMode(CORNERS) interprets the first two parameters of ellipse() as the location of one corner of the ellipse's bounding box, and the third and fourth parameters as the location of the opposite corner.

The parameter must be written in ALL CAPS because Processing is a case-sensitive language.
Syntax
ellipseMode(mode)
Parameters
mode    int: either CENTER, RADIUS, CORNER, or CORNERS
Returns    void
Related    ellipse()
arc()
*/

void ellipseMode(_penum mode);

/*
Name
rectMode()
Examples
example pic
rectMode(CORNER);  // Default rectMode is CORNER
fill(255);  // Set fill to white
rect(25, 25, 50, 50);  // Draw white rect using CORNER mode

rectMode(CORNERS);  // Set rectMode to CORNERS
fill(100);  // Set fill to gray
rect(25, 25, 50, 50);  // Draw gray rect using CORNERS mode
example pic
rectMode(RADIUS);  // Set rectMode to RADIUS
fill(255);  // Set fill to white
rect(50, 50, 30, 30);  // Draw white rect using RADIUS mode

rectMode(CENTER);  // Set rectMode to CENTER
fill(100);  // Set fill to gray
rect(50, 50, 30, 30);  // Draw gray rect using CENTER mode
Description    Modifies the location from which rectangles are drawn by changing the way in which parameters given to rect() are intepreted.

The default mode is rectMode(CORNER), which interprets the first two parameters of rect() as the upper-left corner of the shape, while the third and fourth parameters are its width and height.

rectMode(CORNERS) interprets the first two parameters of rect() as the location of one corner, and the third and fourth parameters as the location of the opposite corner.

rectMode(CENTER) interprets the first two parameters of rect() as the shape's center point, while the third and fourth parameters are its width and height.

rectMode(RADIUS) also uses the first two parameters of rect() as the shape's center point, but uses the third and fourth parameters to specify half of the shapes's width and height.

The parameter must be written in ALL CAPS because Processing is a case-sensitive language.
Syntax
rectMode(mode)
Parameters
mode    int: either CORNER, CORNERS, CENTER, or RADIUS
Returns    void
Related    rect()
*/
void rectMode(_penum mode);

/*
Name
strokeCap()
Examples
example pic
strokeWeight(12.0);
strokeCap(ROUND);
line(20, 30, 80, 30);
strokeCap(SQUARE);
line(20, 50, 80, 50);
strokeCap(PROJECT);
line(20, 70, 80, 70);
Description    Sets the style for rendering line endings. These ends are either squared, extended, or rounded, each of which specified with the corresponding parameters: SQUARE, PROJECT, and ROUND. The default cap is ROUND.
Syntax
strokeCap(cap)
Parameters
cap    int: either SQUARE, PROJECT, or ROUND
Returns    void
Related    stroke()
strokeWeight()
strokeJoin()
size()
*/
void strokeCap(_penum cap);

/*
Name
strokeJoin()
Examples
example pic
noFill();
strokeWeight(10.0);
strokeJoin(MITER);
beginShape();
vertex(35, 20);
vertex(65, 50);
vertex(35, 80);
endShape();
example pic
noFill();
strokeWeight(10.0);
strokeJoin(BEVEL);
beginShape();
vertex(35, 20);
vertex(65, 50);
vertex(35, 80);
endShape();
example pic
noFill();
strokeWeight(10.0);
strokeJoin(ROUND);
beginShape();
vertex(35, 20);
vertex(65, 50);
vertex(35, 80);
endShape();
Description    Sets the style of the joints which connect line segments. These joints are either mitered, beveled, or rounded and specified with the corresponding parameters MITER, BEVEL, and ROUND. The default joint is MITER.
Syntax
strokeJoin(join)
Parameters
join    int: either MITER, BEVEL, ROUND
Returns    void
Related    stroke()
strokeWeight()
strokeCap()
*/
void strokeJoin(_penum join);

/*
Name
strokeWeight()
Examples
example pic
strokeWeight(1);  // Default
line(20, 20, 80, 20);
strokeWeight(4);  // Thicker
line(20, 40, 80, 40);
strokeWeight(10);  // Beastly
line(20, 70, 80, 70);
Description    Sets the width of the stroke used for lines, points, and the border around shapes. All widths are set in units of pixels.
Syntax
strokeWeight(weight)
Parameters
weight    float: the weight (in pixels) of the stroke
Returns    void
Related    stroke()
strokeJoin()
strokeCap()
*/
void strokeWeight(float weight);

//Vertex
/*
Name
beginContour()
Examples
example pic
size(100, 100);
translate(50, 50);
stroke(255, 0, 0);
beginShape();
// Exterior part of shape, clockwise winding
vertex(-40, -40);
vertex(40, -40);
vertex(40, 40);
vertex(-40, 40);
// Interior part of shape, counter-clockwise winding
beginContour();
vertex(-20, -20);
vertex(-20, 20);
vertex(20, 20);
vertex(20, -20);
endContour();
endShape(CLOSE);
Description    Use the beginContour() and endContour() function to create negative shapes within shapes such as the center of the letter 'O'. beginContour() begins recording vertices for the shape and endContour() stops recording. The vertices that define a negative shape must "wind" in the opposite direction from the exterior shape. First draw vertices for the exterior shape in clockwise order, then for internal shapes, draw vertices counterclockwise.

These functions can only be used within a beginShape()/endShape() pair and transformations such as translate(), rotate(), and scale() do not work within a beginContour()/endContour() pair. It is also not possible to use other shapes, such as ellipse() or rect() within.
Syntax
beginContour()
Returns    void
*/
void beginContour();

/*
Name
beginShape()
Examples
example pic
beginShape();
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape(CLOSE);
example pic
beginShape(POINTS);
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape();
example pic
beginShape(LINES);
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape();
example pic
noFill();
beginShape();
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape();
example pic
noFill();
beginShape();
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape(CLOSE);
example pic
beginShape(TRIANGLES);
vertex(30, 75);
vertex(40, 20);
vertex(50, 75);
vertex(60, 20);
vertex(70, 75);
vertex(80, 20);
endShape();
example pic
beginShape(TRIANGLE_STRIP);
vertex(30, 75);
vertex(40, 20);
vertex(50, 75);
vertex(60, 20);
vertex(70, 75);
vertex(80, 20);
vertex(90, 75);
endShape();
example pic
beginShape(TRIANGLE_FAN);
vertex(57.5, 50);
vertex(57.5, 15);
vertex(92, 50);
vertex(57.5, 85);
vertex(22, 50);
vertex(57.5, 15);
endShape();
example pic
beginShape(QUADS);
vertex(30, 20);
vertex(30, 75);
vertex(50, 75);
vertex(50, 20);
vertex(65, 20);
vertex(65, 75);
vertex(85, 75);
vertex(85, 20);
endShape();
example pic
beginShape(QUAD_STRIP);
vertex(30, 20);
vertex(30, 75);
vertex(50, 20);
vertex(50, 75);
vertex(65, 20);
vertex(65, 75);
vertex(85, 20);
vertex(85, 75);
endShape();
example pic
beginShape();
vertex(20, 20);
vertex(40, 20);
vertex(40, 40);
vertex(60, 40);
vertex(60, 60);
vertex(20, 60);
endShape(CLOSE);
Description    Using the beginShape() and endShape() functions allow creating more complex forms. beginShape() begins recording vertices for a shape and endShape() stops recording. The value of the kind parameter tells it which types of shapes to create from the provided vertices. With no mode specified, the shape can be any irregular polygon. The parameters available for beginShape() are POINTS, LINES, TRIANGLES, TRIANGLE_FAN, TRIANGLE_STRIP, QUADS, and QUAD_STRIP. After calling the beginShape() function, a series of vertex() commands must follow. To stop drawing the shape, call endShape(). The vertex() function with two parameters specifies a position in 2D and the vertex() function with three parameters specifies a position in 3D. Each shape will be outlined with the current stroke color and filled with the fill color.

Transformations such as translate(), rotate(), and scale() do not work within beginShape(). It is also not possible to use other shapes, such as ellipse() or rect() within beginShape().

The P2D and P3D renderers allow stroke() and fill() to be altered on a per-vertex basis, but the default renderer does not. Settings such as strokeWeight(), strokeCap(), and strokeJoin() cannot be changed while inside a beginShape()/endShape() block with any renderer.
Syntax
beginShape()
beginShape(kind)
Parameters
kind    int: Either POINTS, LINES, TRIANGLES, TRIANGLE_FAN, TRIANGLE_STRIP, QUADS, or QUAD_STRIP
Returns    void
Related    PShape
endShape()
vertex()
curveVertex()
bezierVertex()
*/
void beginShape();
void beginShape(_penum kind);

/*
Name
bezierVertex()
Examples
example pic
noFill();
beginShape();
vertex(30, 20);
bezierVertex(80, 0, 80, 75, 30, 75);
endShape();
example pic
beginShape();
vertex(30, 20);
bezierVertex(80, 0, 80, 75, 30, 75);
bezierVertex(50, 80, 60, 25, 30, 20);
endShape();
Description    Specifies vertex coordinates for Bezier curves. Each call to bezierVertex() defines the position of two control points and one anchor point of a Bezier curve, adding a new segment to a line or shape. The first time bezierVertex() is used within a beginShape() call, it must be prefaced with a call to vertex() to set the first anchor point. This function must be used between beginShape() and endShape() and only when there is no MODE parameter specified to beginShape(). Using the 3D version requires rendering with P3D (see the Environment reference for more information).
Syntax
bezierVertex(x2, y2, x3, y3, x4, y4)
bezierVertex(x2, y2, z2, x3, y3, z3, x4, y4, z4)
Parameters
x2    float: the x-coordinate of the 1st control point
y2    float: the y-coordinate of the 1st control point
z2    float: the z-coordinate of the 1st control point
x3    float: the x-coordinate of the 2nd control point
y3    float: the y-coordinate of the 2nd control point
z3    float: the z-coordinate of the 2nd control point
x4    float: the x-coordinate of the anchor point
y4    float: the y-coordinate of the anchor point
z4    float: the z-coordinate of the anchor point
Returns    void
Related    curveVertex()
vertex()
quadraticVertex()
bezier()
*/
void bezierVertex(float x2, float y2, float x3, float y3, float x4, float y4);
void bezierVertex(float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4);

/*
Name
curveVertex()
Examples
example pic
noFill();
beginShape();
curveVertex(84,  91);
curveVertex(84,  91);
curveVertex(68,  19);
curveVertex(21,  17);
curveVertex(32, 100);
curveVertex(32, 100);
endShape();
Description    Specifies vertex coordinates for curves. This function may only be used between beginShape() and endShape() and only when there is no MODE parameter specified to beginShape(). The first and last points in a series of curveVertex() lines will be used to guide the beginning and end of a the curve. A minimum of four points is required to draw a tiny curve between the second and third points. Adding a fifth point with curveVertex() will draw the curve between the second, third, and fourth points. The curveVertex() function is an implementation of Catmull-Rom splines. Using the 3D version requires rendering with P3D (see the Environment reference for more information).
Syntax
curveVertex(x, y)
curveVertex(x, y, z)
Parameters
x    float: the x-coordinate of the vertex
y    float: the y-coordinate of the vertex
z    float: the z-coordinate of the vertex
Returns    void
Related    curve()
beginShape()
endShape()
vertex()
bezier()
quadraticVertex()
*/
void curveVertex(float x, float y);
void curveVertex(float x, float y, float z);

/*
Name
endContour()
Examples
example pic
size(100, 100);
translate(50, 50);
stroke(255, 0, 0);
beginShape();
// Exterior part of shape, clockwise winding
vertex(-40, -40);
vertex(40, -40);
vertex(40, 40);
vertex(-40, 40);
// Interior part of shape, counter-clockwise winding
beginContour();
vertex(-20, -20);
vertex(-20, 20);
vertex(20, 20);
vertex(20, -20);
endContour();
endShape(CLOSE);
Description    Use the beginContour() and endContour() function to create negative shapes within shapes such as the center of the letter 'O'. beginContour() begins recording vertices for the shape and endContour() stops recording. The vertices that define a negative shape must "wind" in the opposite direction from the exterior shape. First draw vertices for the exterior shape in clockwise order, then for internal shapes, draw vertices counterclockwise.

These functions can only be used within a beginShape()/endShape() pair and transformations such as translate(), rotate(), and scale() do not work within a beginContour()/endContour() pair. It is also not possible to use other shapes, such as ellipse() or rect() within.
Syntax
endContour()
Returns    void
*/
void endContour();

/*
Name
endShape()
Examples
example pic
noFill();

beginShape();
vertex(20, 20);
vertex(45, 20);
vertex(45, 80);
endShape(CLOSE);

beginShape();
vertex(50, 20);
vertex(75, 20);
vertex(75, 80);
endShape();
Description    The endShape() function is the companion to beginShape() and may only be called after beginShape(). When endshape() is called, all of image data defined since the previous call to beginShape() is written into the image buffer. The constant CLOSE as the value for the MODE parameter to close the shape (to connect the beginning and the end).
Syntax
endShape()
endShape(mode)
Parameters
mode    int: use CLOSE to close the shape
Returns    void
Related    PShape
beginShape()
*/
void endShape();
void endShape(_penum mode);

/*
Name
quadraticVertex()
Examples
example pic
noFill();
strokeWeight(4);
beginShape();
vertex(20, 20);
quadraticVertex(80, 20, 50, 50);
endShape();
example pic
noFill();
strokeWeight(4);
beginShape();
vertex(20, 20);
quadraticVertex(80, 20, 50, 50);
quadraticVertex(20, 80, 80, 80);
vertex(80, 60);
endShape();
Description    Specifies vertex coordinates for quadratic Bezier curves. Each call to quadraticVertex() defines the position of one control point and one anchor point of a Bezier curve, adding a new segment to a line or shape. The first time quadraticVertex() is used within a beginShape() call, it must be prefaced with a call to vertex() to set the first anchor point. This function must be used between beginShape() and endShape() and only when there is no MODE parameter specified to beginShape(). Using the 3D version requires rendering with P3D (see the Environment reference for more information).
Syntax
quadraticVertex(cx, cy, x3, y3)
quadraticVertex(cx, cy, cz, x3, y3, z3)
Parameters
cx    float: the x-coordinate of the control point
cy    float: the y-coordinate of the control point
x3    float: the x-coordinate of the anchor point
y3    float: the y-coordinate of the anchor point
cz    float: the z-coordinate of the control point
z3    float: the z-coordinate of the anchor point
Returns    void
Related    curveVertex()
vertex()
bezierVertex()
bezier()
*/
void quadraticVertex(float cx, float cy, float x3, float y3);
void quadraticVertex(float cx, float cy, float cz, float x3, float y3, float z3);

/*
Name
vertex()
Examples
example pic
beginShape(POINTS);
vertex(30, 20);
vertex(85, 20);
vertex(85, 75);
vertex(30, 75);
endShape();
example pic
// Drawing vertices in 3D requires P3D
// as a parameter to size()
size(100, 100, P3D);
beginShape(POINTS);
vertex(30, 20, -50);
vertex(85, 20, -50);
vertex(85, 75, -50);
vertex(30, 75, -50);
endShape();
example pic
size(100, 100, P3D);
PImage img = loadImage("laDefense.jpg");
noStroke();
beginShape();
texture(img);
// "laDefense.jpg" is 100x100 pixels in size so
// the values 0 and 100 are used for the
// parameters "u" and "v" to map it directly
// to the vertex points
vertex(10, 20, 0, 0);
vertex(80, 5, 100, 0);
vertex(95, 90, 100, 100);
vertex(40, 95, 0, 100);
endShape();
Description    All shapes are constructed by connecting a series of vertices. vertex() is used to specify the vertex coordinates for points, lines, triangles, quads, and polygons. It is used exclusively within the beginShape() and endShape() functions.

Drawing a vertex in 3D using the z parameter requires the P3D parameter in combination with size, as shown in the above example.

This function is also used to map a texture onto geometry. The texture() function declares the texture to apply to the geometry and the u and v coordinates set define the mapping of this texture to the form. By default, the coordinates used for u and v are specified in relation to the image's size in pixels, but this relation can be changed with textureMode().
Syntax
vertex(x, y)
vertex(x, y, z)
vertex(v)
vertex(x, y, u, v)
vertex(x, y, z, u, v)
Parameters
v    float[]: vertex parameters, as a float array of length VERTEX_FIELD_COUNT
x    float: x-coordinate of the vertex
y    float: y-coordinate of the vertex
z    float: z-coordinate of the vertex
u    float: horizontal coordinate for the texture mapping
v    float: vertical coordinate for the texture mapping
Returns    void
Related    beginShape()
endShape()
bezierVertex()
quadraticVertex()
curveVertex()
texture()
*/
void verte(float x, float y);
void vertex(float x, float y, float z);
void vertex(float v[]);
void vertex(float x, float y, float u, float v);
void vertex(float x, float y, float z, float u, float v);

//Loading & Displaying
/*
Name
shape()
Examples
example pic
PShape s;

void setup() {
    s = loadShape("bot.svg");
}

void draw() {
    shape(s, 10, 10, 80, 80);
}
Description    Draws shapes to the display window. Shapes must be in the sketch's "data" directory to load correctly. Select "Add file..." from the "Sketch" menu to add the shape. Processing currently works with SVG, OBJ, and custom-created shapes. The shape parameter specifies the shape to display and the coordinate parameters define the location of the shape from its upper-left corner. The shape is displayed at its original size unless the c and d parameters specify a different size. The shapeMode() function can be used to change the way these parameters are interpreted.
Syntax
shape(shape)
shape(shape, x, y)
shape(shape, a, b, c, d)
Parameters
shape    PShape: the shape to display
x    float: x-coordinate of the shape
y    float: y-coordinate of the shape
a    float: x-coordinate of the shape
b    float: y-coordinate of the shape
c    float: width to display the shape
d    float: height to display the shape
Returns    void
Related    PShape
loadShape()
shapeMode()
*/
void shape(PShape shape);
void shape(PShape shape, float x, float y);
void shape(PShape shape, float a, float b, float c, float d);

/*
Name
shapeMode()
Examples
example pic
PShape bot

void setup() {
    size(100, 100);
    bot = loadShape("bot.svg");
}

void draw() {
    shapeMode(CENTER);
    shape(bot, 35, 35, 50, 50);
    shapeMode(CORNER);
    shape(bot, 35, 35, 50, 50);
}
Description    Modifies the location from which shapes draw. The default mode is shapeMode(CORNER), which specifies the location to be the upper left corner of the shape and uses the third and fourth parameters of shape() to specify the width and height. The syntax shapeMode(CORNERS) uses the first and second parameters of shape() to set the location of one corner and uses the third and fourth parameters to set the opposite corner. The syntax shapeMode(CENTER) draws the shape from its center point and uses the third and forth parameters of shape() to specify the width and height. The parameter must be written in "ALL CAPS" because Processing is a case sensitive language.
Syntax
shapeMode(mode)
Parameters
mode    int: either CORNER, CORNERS, CENTER
Returns    void
Related    PShape
shape()
rectMode()
*/
void shapeMode(_penum mode);

//Input
//Mouse
/*
Name
mouseButton
Examples
// Click within the image and press
// the left and right mouse buttons to
// change the value of the rectangle
void draw() {
    if (mousePressed && (mouseButton == LEFT)) {
        fill(0);
    } else if (mousePressed && (mouseButton == RIGHT)) {
        fill(255);
    } else {
        fill(126);
    }
    rect(25, 25, 50, 50);
}
// Click within the image and press
// the left and right mouse buttons to
// change the value of the rectangle
void draw() {
    rect(25, 25, 50, 50);
}

void mousePressed() {
    if (mouseButton == LEFT) {
        fill(0);
    } else if (mouseButton == RIGHT) {
        fill(255);
    } else {
        fill(126);
    }
}
Description    When a mouse button is pressed, the value of the system variable mouseButton is set to either LEFT, RIGHT, or CENTER, depending on which button is pressed. (If no button is pressed, mouseButton may be reset to 0. For that reason, it's best to use mousePressed first to test if any button is being pressed, and only then test the value of mouseButton, as shown in the examples above.)
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseWheel()
*/
extern int $mouseButton;

/*mouseClicked()
mouseDragged()
mouseMoved()
mousePressed()*/

/*
Name
mousePressed
Examples
// Click within the image to change
// the value of the rectangle
void draw() {
    if (mousePressed == true) {
        fill(0);
    } else {
        fill(255);
    }
    rect(25, 25, 50, 50);
}
Description    The mousePressed variable stores whether or not a mouse button is currently being pressed. The value is true when any mouse button is pressed, and false if no button is pressed. The mouseButton variable (see the related reference entry) can be used to determine which button has been pressed.
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
extern bool $mousePressed;

/*mouseReleased()
mouseWheel()*/

/*
Name
mouseX
Examples
void draw() {
    background(204);
    line(mouseX, 20, mouseX, 80);
}
Description    The system variable mouseX always contains the current horizontal coordinate of the mouse.

Note that Processing can only track the mouse position when the pointer is over the current window. The default value of mouseX is 0, so 0 will be returned until the mouse moves in front of the sketch window. (This typically happens when a sketch is first run.) Once the mouse moves away from the window, mouseX will continue to report its most recent position.
Related    mouseY
pmouseX
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
extern int $mouseX;

/*
Name
mouseY
Examples
void draw() {
    background(204);
    line(20, mouseY, 80, mouseY);
}
Description    The system variable mouseY always contains the current vertical coordinate of the mouse.

Note that Processing can only track the mouse position when the pointer is over the current window. The default value of mouseY is 0, so 0 will be returned until the mouse moves in front of the sketch window. (This typically happens when a sketch is first run.) Once the mouse moves away from the window, mouseY will continue to report its most recent position.
Related    mouseX
pmouseX
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
extern int $mouseY;

/*
Name
pmouseX
Examples
// Move the mouse quickly to see the difference
// between the current and previous position
void draw() {
    background(204);
    line(mouseX, 20, pmouseX, 80);
    println(mouseX + " : " + pmouseX);
}
Description    The system variable pmouseX always contains the horizontal position of the mouse in the frame previous to the current frame.

You may find that pmouseX and pmouseY have different values when referenced inside of draw() and inside of mouse events like mousePressed() and mouseMoved(). Inside draw(), pmouseX and pmouseY update only once per frame (once per trip through the draw() loop). But inside mouse events, they update each time the event is called. If these values weren't updated immediately during mouse events, then the mouse position would be read only once per frame, resulting in slight delays and choppy interaction. If the mouse variables were always updated multiple times per frame, then something like line(pmouseX, pmouseY, mouseX, mouseY) inside draw() would have lots of gaps, because pmouseX may have changed several times in between the calls to line().

If you want values relative to the previous frame, use pmouseX and pmouseY inside draw(). If you want continuous response, use pmouseX and pmouseY inside the mouse event functions.
Related    mouseX
mouseY
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
extern int $pmouseX;

/*
Name
pmouseY
Examples
// Move the mouse quickly to see the difference
// between the current and previous position
void draw() {
    background(204);
    line(20, mouseY, 80, pmouseY);
    println(mouseY + " : " + pmouseY);
}
Description    The system variable pmouseY always contains the vertical position of the mouse in the frame previous to the current frame.

For more detail on how pmouseY is updated inside of mouse events and draw(), see the reference for pmouseX.
Related    mouseX
mouseY
pmouseX
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
extern int $pmouseY;

//Keyboard
/*
Name
key
Examples
// Click on the window to give it focus,
// and press the 'B' key.

void draw() {
    if (keyPressed) {
        if (key == 'b' || key == 'B') {
            fill(0);
        }
    } else {
        fill(255);
    }
    rect(25, 25, 50, 50);
}
Description    The system variable key always contains the value of the most recent key on the keyboard that was used (either pressed or released).

For non-ASCII keys, use the keyCode variable. The keys included in the ASCII specification (BACKSPACE, TAB, ENTER, RETURN, ESC, and DELETE) do not require checking to see if the key is coded, and you should simply use the key variable instead of keyCode If you're making cross-platform projects, note that the ENTER key is commonly used on PCs and Unix and the RETURN key is used instead on Macintosh. Check for both ENTER and RETURN to make sure your program will work for all platforms.

There are issues with how keyCode behaves across different renderers and operating systems. Watch out for unexpected behavior as you switch renderers and operating systems.
Related    keyCode
keyPressed
keyPressed()
keyReleased()
*/
extern int $key;

/*
Name
keyCode
Examples
color fillVal = color(126);

void draw() {
    fill(fillVal);
    rect(25, 25, 50, 50);
}

void keyPressed() {
    if (key == CODED) {
        if (keyCode == UP) {
            fillVal = 255;
        } else if (keyCode == DOWN) {
            fillVal = 0;
        }
    } else {
        fillVal = 126;
    }
}
Description    The variable keyCode is used to detect special keys such as the arrow keys (UP, DOWN, LEFT, and RIGHT) as well as ALT, CONTROL, and SHIFT.

When checking for these keys, it can be useful to first check if the key is coded. This is done with the conditional if (key == CODED), as shown in the example above.

The keys included in the ASCII specification (BACKSPACE, TAB, ENTER, RETURN, ESC, and DELETE) do not require checking to see if the key is coded; for those keys, you should simply use the key variable directly (and not keyCode). If you're making cross-platform projects, note that the ENTER key is commonly used on PCs and Unix, while the RETURN key is used on Macs. Make sure your program will work on all platforms by checking for both ENTER and RETURN.

For those familiar with Java, the values for UP and DOWN are simply shorter versions of Java's KeyEvent.VK_UP and KeyEvent.VK_DOWN. Other keyCode values can be found in the Java KeyEvent reference.

There are issues with how keyCode behaves across different renderers and operating systems. Watch out for unexpected behavior as you switch renderers and operating systems and you are using keys are aren't mentioned in this reference entry.
Related    key
keyPressed
keyPressed()
keyReleased()
*/
extern int $keyCode;

/*keyPressed()*/

/*
Name
keyPressed
Examples
// Click on the image to give it focus,
// and then press any key.

// Note: The rectangle in this example may
// flicker as the operating system may
// register a long key press as a repetition
// of key presses.

void draw() {
    if (keyPressed == true) {
        fill(0);
    } else {
        fill(255);
    }
    rect(25, 25, 50, 50);
}
Description    The boolean system variable keyPressed is true if any key is pressed and false if no keys are pressed.

Note that there is a similarly named function called keyPressed(). See its reference page for more information.
Related    key
keyCode
keyPressed()
keyReleased()
*/
extern int $keyPressed;

/*keyReleased()
keyTyped()*/

//Files
/*BufferedReader
createInput()
createReader()
launch()
loadBytes()
loadJSONArray()
loadJSONObject()
loadStrings()
loadTable()
loadXML()
parseJSONArray()
parseJSONObject()
parseXML()
selectFolder()
selectInput()*/

//Time & Date
/*day()
hour()
millis()
minute()
month()
second()
year()*/

//Output
//Text Area
/*print()
printArray()
println()*/

//Image
/*save()
saveFrame()*/

//Files
/*beginRaw()
beginRecord()
createOutput()
createWriter()
endRaw()
endRecord()
PrintWriter
saveBytes()
saveJSONArray()
saveJSONObject()
saveStream()
saveStrings()
saveTable()
saveXML()
selectOutput()*/

//Transform
/*
Name
applyMatrix()
Examples
example pic
size(100, 100, P3D);
noFill();
translate(50, 50, 0);
rotateY(PI/6);
stroke(153);
box(35);
// Set rotation angles
float ct = cos(PI/9.0);
float st = sin(PI/9.0);
// Matrix for rotation around the Y axis
applyMatrix(  ct, 0.0,  st,  0.0,
            0.0, 1.0, 0.0,  0.0,
            -st, 0.0,  ct,  0.0,
            0.0, 0.0, 0.0,  1.0);
stroke(255);
box(50);
Description    Multiplies the current matrix by the one specified through the parameters. This is very slow because it will try to calculate the inverse of the transform, so avoid it whenever possible. The equivalent function in OpenGL is glMultMatrix().
Syntax
applyMatrix(source)
applyMatrix(n00, n01, n02, n10, n11, n12)
applyMatrix(n00, n01, n02, n03, n10, n11, n12, n13, n20, n21, n22, n23, n30, n31, n32, n33)
Parameters
n00    float: numbers which define the 4x4 matrix to be multiplied
n01    float: numbers which define the 4x4 matrix to be multiplied
n02    float: numbers which define the 4x4 matrix to be multiplied
n10    float: numbers which define the 4x4 matrix to be multiplied
n11    float: numbers which define the 4x4 matrix to be multiplied
n12    float: numbers which define the 4x4 matrix to be multiplied
n03    float: numbers which define the 4x4 matrix to be multiplied
n13    float: numbers which define the 4x4 matrix to be multiplied
n20    float: numbers which define the 4x4 matrix to be multiplied
n21    float: numbers which define the 4x4 matrix to be multiplied
n22    float: numbers which define the 4x4 matrix to be multiplied
n23    float: numbers which define the 4x4 matrix to be multiplied
n30    float: numbers which define the 4x4 matrix to be multiplied
n31    float: numbers which define the 4x4 matrix to be multiplied
n32    float: numbers which define the 4x4 matrix to be multiplied
n33    float: numbers which define the 4x4 matrix to be multiplied
Returns    void
Related    pushMatrix()
popMatrix()
resetMatrix()
printMatrix()
*/
void applyMatrix(float source[]);
void applyMatrix(float n00, float n01, float n02, float n10, float n11, float n12);
void applyMatrix(float n00, float n01, float n02, float n03, float n10, float n11, float n12, float n13, float n20, float n21, float n22, float n23, float n30, float n31, float n32, float n33);

/*
Name
popMatrix()
Examples
example pic
fill(255);
rect(0, 0, 50, 50);  // White rectangle

pushMatrix();
translate(30, 20);
fill(0);
rect(0, 0, 50, 50);  // Black rectangle
popMatrix();

fill(100);
rect(15, 10, 50, 50);  // Gray rectangle
Description    Pops the current transformation matrix off the matrix stack. Understanding pushing and popping requires understanding the concept of a matrix stack. The pushMatrix() function saves the current coordinate system to the stack and popMatrix() restores the prior coordinate system. pushMatrix() and popMatrix() are used in conjuction with the other transformation functions and may be embedded to control the scope of the transformations.
Syntax
popMatrix()
Returns    void
Related    pushMatrix()
*/
void popMatrix();

/*
Name
printMatrix()
Examples
size(100, 100, P3D);
printMatrix();
// Prints:
// 01.0000  00.0000  00.0000 -50.0000
// 00.0000  01.0000  00.0000 -50.0000
// 00.0000  00.0000  01.0000 -86.6025
// 00.0000  00.0000  00.0000  01.0000

resetMatrix();
printMatrix();
// Prints:
// 1.0000  0.0000  0.0000  0.0000
// 0.0000  1.0000  0.0000  0.0000
// 0.0000  0.0000  1.0000  0.0000
// 0.0000  0.0000  0.0000  1.0000
Description    Prints the current matrix to the Console (the text window at the bottom of Processing).
Syntax
printMatrix()
Returns    void
Related    pushMatrix()
popMatrix()
resetMatrix()
applyMatrix()
*/
void printMatrix();

/*
Name
pushMatrix()
Examples
example pic
fill(255);
rect(0, 0, 50, 50);  // White rectangle

pushMatrix();
translate(30, 20);
fill(0);
rect(0, 0, 50, 50);  // Black rectangle
popMatrix();

fill(100);
rect(15, 10, 50, 50);  // Gray rectangle
Description    Pushes the current transformation matrix onto the matrix stack. Understanding pushMatrix() and popMatrix() requires understanding the concept of a matrix stack. The pushMatrix() function saves the current coordinate system to the stack and popMatrix() restores the prior coordinate system. pushMatrix() and popMatrix() are used in conjuction with the other transformation functions and may be embedded to control the scope of the transformations.
Syntax
pushMatrix()
Returns    void
Related    popMatrix()
translate()
scale()
rotate()
rotateX()
rotateY()
rotateZ()
*/
void pushMatrix();

/*
Name
resetMatrix()
Examples
size(100, 100, P3D);
noFill();
box(80);
printMatrix();
// Prints:
// 01.0000  00.0000  00.0000 -50.0000
// 00.0000  01.0000  00.0000 -50.0000
// 00.0000  00.0000  01.0000 -86.6025
// 00.0000  00.0000  00.0000  01.0000

resetMatrix();
box(80);
printMatrix();
// Prints:
// 1.0000  0.0000  0.0000  0.0000
// 0.0000  1.0000  0.0000  0.0000
// 0.0000  0.0000  1.0000  0.0000
// 0.0000  0.0000  0.0000  1.0000
Description    Replaces the current matrix with the identity matrix. The equivalent function in OpenGL is glLoadIdentity().
Syntax
resetMatrix()
Returns    void
Related    pushMatrix()
popMatrix()
applyMatrix()
printMatrix()
*/
void resetMatrix();

/*
Name
rotate()
Examples
example pic
translate(width/2, height/2);
rotate(PI/3.0);
rect(-26, -26, 52, 52);
Description    Rotates the amount specified by the angle parameter. Angles must be specified in radians (values from 0 to TWO_PI), or they can be converted from degrees to radians with the radians() function.

The coordinates are always rotated around their relative position to the origin. Positive numbers rotate objects in a clockwise direction and negative numbers rotate in the couterclockwise direction. Transformations apply to everything that happens afterward, and subsequent calls to the function compound the effect. For example, calling rotate(PI/2.0) once and then calling rotate(PI/2.0) a second time is the same as a single rotate(PI). All tranformations are reset when draw() begins again.

Technically, rotate() multiplies the current transformation matrix by a rotation matrix. This function can be further controlled by pushMatrix() and popMatrix().
Syntax
rotate(angle)
Parameters
angle    float: angle of rotation specified in radians
Returns    void
Related    popMatrix()
pushMatrix()
rotateX()
rotateY()
rotateZ()
scale()
radians()
*/
void rotate(float angle);

/*
Name
rotateX()
Examples
example pic
size(100, 100, P3D);
translate(width/2, height/2);
rotateX(PI/3.0);
rect(-26, -26, 52, 52);
example pic
size(100, 100, P3D);
translate(width/2, height/2);
rotateX(radians(60));
rect(-26, -26, 52, 52);
Description    Rotates around the x-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to TWO_PI) or converted from degrees to radians with the radians() function. Coordinates are always rotated around their relative position to the origin. Positive numbers rotate in a clockwise direction and negative numbers rotate in a counterclockwise direction. Transformations apply to everything that happens after and subsequent calls to the function accumulates the effect. For example, calling rotateX(PI/2) and then rotateX(PI/2) is the same as rotateX(PI). If rotateX() is run within the draw(), the transformation is reset when the loop begins again. This function requires using P3D as a third parameter to size() as shown in the example above.
Syntax
rotateX(angle)
Parameters
angle    float: angle of rotation specified in radians
Returns    void
Related    popMatrix()
pushMatrix()
rotate()
rotateY()
rotateZ()
scale()
translate()
*/
void rotateX(float angle);

/*
Name
rotateY()
Examples
example pic
size(100, 100, P3D);
translate(width/2, height/2);
rotateY(PI/3.0);
rect(-26, -26, 52, 52);
example pic
size(100, 100, P3D);
translate(width/2, height/2);
rotateY(radians(60));
rect(-26, -26, 52, 52);
Description    Rotates around the y-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to TWO_PI) or converted from degrees to radians with the radians() function. Coordinates are always rotated around their relative position to the origin. Positive numbers rotate in a clockwise direction and negative numbers rotate in a counterclockwise direction. Transformations apply to everything that happens after and subsequent calls to the function accumulates the effect. For example, calling rotateY(PI/2) and then rotateY(PI/2) is the same as rotateY(PI). If rotateY() is run within the draw(), the transformation is reset when the loop begins again. This function requires using P3D as a third parameter to size() as shown in the example above.
Syntax
rotateY(angle)
Parameters
angle    float: angle of rotation specified in radians
Returns    void
Related    popMatrix()
pushMatrix()
rotate()
rotateX()
rotateZ()
scale()
translate()
*/
void rotateY(float angle);

/*
Name
rotateZ()
Examples
example pic
size(100, 100, P3D);
translate(width/2, height/2);
rotateZ(PI/3.0);
rect(-26, -26, 52, 52);
example pic
size(100, 100, P3D);
translate(width/2, height/2);
rotateZ(radians(60));
rect(-26, -26, 52, 52);
Description    Rotates around the z-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to TWO_PI) or converted from degrees to radians with the radians() function. Coordinates are always rotated around their relative position to the origin. Positive numbers rotate in a clockwise direction and negative numbers rotate in a counterclockwise direction. Transformations apply to everything that happens after and subsequent calls to the function accumulates the effect. For example, calling rotateZ(PI/2) and then rotateZ(PI/2) is the same as rotateZ(PI). If rotateZ() is run within the draw(), the transformation is reset when the loop begins again. This function requires using P3D as a third parameter to size() as shown in the example above.
Syntax
rotateZ(angle)
Parameters
angle    float: angle of rotation specified in radians
Returns    void
Related    popMatrix()
pushMatrix()
rotate()
rotateX()
rotateY()
scale()
translate()
*/
void rotateZ(float angle);

/*
Name
scale()
Examples
example pic
rect(30, 20, 50, 50);
scale(0.5);
rect(30, 20, 50, 50);
example pic
rect(30, 20, 50, 50);
scale(0.5, 1.3);
rect(30, 20, 50, 50);
example pic
// Scaling in 3D requires P3D
// as a parameter to size()
size(100, 100, P3D);
noFill();
translate(width/2+12, height/2);
box(20, 20, 20);
scale(2.5, 2.5, 2.5);
box(20, 20, 20);
Description    Increases or decreases the size of a shape by expanding and contracting vertices. Objects always scale from their relative origin to the coordinate system. Scale values are specified as decimal percentages. For example, the function call scale(2.0) increases the dimension of a shape by 200%.

Transformations apply to everything that happens after and subsequent calls to the function multiply the effect. For example, calling scale(2.0) and then scale(1.5) is the same as scale(3.0). If scale() is called within draw(), the transformation is reset when the loop begins again. Using this function with the z parameter requires using P3D as a parameter for size(), as shown in the third example above. This function can be further controlled with pushMatrix() and popMatrix().
Syntax
scale(s)
scale(x, y)
scale(x, y, z)
Parameters
s    float: percentage to scale the object
x    float: percentage to scale the object in the x-axis
y    float: percentage to scale the object in the y-axis
z    float: percentage to scale the object in the z-axis
Returns    void
Related    pushMatrix()
popMatrix()
translate()
rotate()
rotateX()
rotateY()
rotateZ()
*/
void scale(float s);
void scale(float x, float y);
void scale(float x, float y, float z);

/*
Name
shearX()
Examples
example pic
size(100, 100);
translate(width/4, height/4);
shearX(PI/4.0);
rect(0, 0, 30, 30);
Description    Shears a shape around the x-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to PI*2) or converted to radians with the radians() function. Objects are always sheared around their relative position to the origin and positive numbers shear objects in a clockwise direction. Transformations apply to everything that happens after and subsequent calls to the function accumulates the effect. For example, calling shearX(PI/2) and then shearX(PI/2) is the same as shearX(PI). If shearX() is called within the draw(), the transformation is reset when the loop begins again.

Technically, shearX() multiplies the current transformation matrix by a rotation matrix. This function can be further controlled by the pushMatrix() and popMatrix() functions.
Syntax
shearX(angle)
Parameters
angle    float: angle of shear specified in radians
Returns    void
Related    popMatrix()
pushMatrix()
shearY()
scale()
translate()
radians()
*/
void shearX(float angle);

/*
Name
shearY()
Examples
example pic
size(100, 100);
translate(width/4, height/4);
shearY(PI/4.0);
rect(0, 0, 30, 30);
Description    Shears a shape around the y-axis the amount specified by the angle parameter. Angles should be specified in radians (values from 0 to PI*2) or converted to radians with the radians() function. Objects are always sheared around their relative position to the origin and positive numbers shear objects in a clockwise direction. Transformations apply to everything that happens after and subsequent calls to the function accumulates the effect. For example, calling shearY(PI/2) and then shearY(PI/2) is the same as shearY(PI). If shearY() is called within the draw(), the transformation is reset when the loop begins again.

Technically, shearY() multiplies the current transformation matrix by a rotation matrix. This function can be further controlled by the pushMatrix() and popMatrix() functions.
Syntax
shearY(angle)
Parameters
angle    float: angle of shear specified in radians
Returns    void
Related    popMatrix()
pushMatrix()
shearX()
scale()
translate()
radians()
*/
void shearY(float angle);

/*
Name
translate()
Examples
example pic
translate(30, 20);
rect(0, 0, 55, 55);
example pic
// Translating in 3D requires P3D
// as the parameter to size()
size(100, 100, P3D);
// Translate 30 across, 20 down, and
// 50 back, or "away" from the screen.
translate(30, 20, -50);
rect(0, 0, 55, 55);
example pic
rect(0, 0, 55, 55);  // Draw rect at original 0,0
translate(30, 20);
rect(0, 0, 55, 55);  // Draw rect at new 0,0
translate(14, 14);
rect(0, 0, 55, 55);  // Draw rect at new 0,0
Description    Specifies an amount to displace objects within the display window. The x parameter specifies left/right translation, the y parameter specifies up/down translation, and the z parameter specifies translations toward/away from the screen. Using this function with the z parameter requires using P3D as a parameter in combination with size as shown in the above example.

Transformations are cumulative and apply to everything that happens after and subsequent calls to the function accumulates the effect. For example, calling translate(50, 0) and then translate(20, 0) is the same as translate(70, 0). If translate() is called within draw(), the transformation is reset when the loop begins again. This function can be further controlled by using pushMatrix() and popMatrix().
Syntax
translate(x, y)
translate(x, y, z)
Parameters
x    float: left/right translation
y    float: up/down translation
z    float: forward/backward translation
Returns    void
Related    popMatrix()
pushMatrix()
rotate()
rotateX()
rotateY()
rotateZ()
scale()
*/
void translate(float x, float y);
void translate(float x, float y, float z);

//Lights, Camera
//Lights
/*
Name
ambientLight()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
// The spheres are white by default so
// the ambient light changes their color
ambientLight(51, 102, 126);
translate(20, 50, 0);
sphere(30);
translate(60, 0, 0);
sphere(30);
example pic
size(100, 100, P3D);
background(0);
noStroke();
directionalLight(126, 126, 126, 0, 0, -1);
ambientLight(102, 102, 102);
translate(32, 50, 0);
rotateY(PI/5);
box(40);
translate(60, 0, 0);
sphere(30);
Description    Adds an ambient light. Ambient light doesn't come from a specific direction, the rays of light have bounced around so much that objects are evenly lit from all sides. Ambient lights are almost always used in combination with other types of lights. Lights need to be included in the draw() to remain persistent in a looping program. Placing them in the setup() of a looping program will cause them to only have an effect the first time through the loop. The v1, v2, and v3 parameters are interpreted as either RGB or HSB values, depending on the current color mode.
Syntax
ambientLight(v1, v2, v3)
ambientLight(v1, v2, v3, x, y, z)
Parameters
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
x    float: x-coordinate of the light
y    float: y-coordinate of the light
z    float: z-coordinate of the light
Returns    void
Related    lights()
directionalLight()
pointLight()
spotLight()
*/
void ambientLight(float v1, float v2, float v3);
void ambientLight(float v1, float v2, float v3, float x, float y, float z);

/*
Name
directionalLight()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
directionalLight(51, 102, 126, -1, 0, 0);
translate(20, 50, 0);
sphere(30);
example pic
size(100, 100, P3D);
background(0);
noStroke();
directionalLight(51, 102, 126, 0, -1, 0);
translate(80, 50, 0);
sphere(30);
Description    Adds a directional light. Directional light comes from one direction: it is stronger when hitting a surface squarely, and weaker if it hits at a gentle angle. After hitting a surface, directional light scatters in all directions. Lights need to be included in the draw() to remain persistent in a looping program. Placing them in the setup() of a looping program will cause them to only have an effect the first time through the loop. The v1, v2, and v3 parameters are interpreted as either RGB or HSB values, depending on the current color mode. The nx, ny, and nz parameters specify the direction the light is facing. For example, setting ny to -1 will cause the geometry to be lit from below (since the light would be facing directly upward).
Syntax
directionalLight(v1, v2, v3, nx, ny, nz)
Parameters
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
nx    float: direction along the x-axis
ny    float: direction along the y-axis
nz    float: direction along the z-axis
Returns    void
Related    lights()
ambientLight()
pointLight()
spotLight()
*/
void directionalLight(float v1, float v2, float v3, float nx, float ny, float nz);

/*
Name
lightFalloff()
Examples
example pic
size(100, 100, P3D);
noStroke();
background(0);
lightFalloff(1.0, 0.001, 0.0);
pointLight(150, 250, 150, 50, 50, 50);
beginShape();
vertex(0, 0, 0);
vertex(100, 0, -100);
vertex(100, 100, -100);
vertex(0, 100, 0);
endShape(CLOSE);
Description    Sets the falloff rates for point lights, spot lights, and ambient lights. Like fill(), it affects only the elements which are created after it in the code. The default value is lightFalloff(1.0, 0.0, 0.0), and the parameters are used to calculate the falloff with the following equation:

d = distance from light position to vertex position
falloff = 1 / (CONSTANT + d * LINEAR + (d*d) * QUADRATIC)

Thinking about an ambient light with a falloff can be tricky. If you want a region of your scene to be lit ambiently with one color and another region to be lit ambiently with another color, you could use an ambient light with location and falloff. You can think of it as a point light that doesn't care which direction a surface is facing.
Syntax
lightFalloff(constant, linear, quadratic)
Parameters
constant    float: constant value or determining falloff
linear    float: linear value for determining falloff
quadratic    float: quadratic value for determining falloff
Returns    void
Related    lights()
ambientLight()
pointLight()
spotLight()
lightSpecular()
*/
void lightFalloff(float constant, float linear, float quadratic);

/*
Name
lights()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
// Sets the default ambient
// and directional light
lights();
translate(20, 50, 0);
sphere(30);
translate(60, 0, 0);
sphere(30);
example pic
void setup() {
    size(100, 100, P3D);
    background(0);
    noStroke();
}

void draw() {
    // Include lights() at the beginning
    // of draw() to keep them persistent
    lights();
    translate(20, 50, 0);
    sphere(30);
    translate(60, 0, 0);
    sphere(30);
}
Description    Sets the default ambient light, directional light, falloff, and specular values. The defaults are ambientLight(128, 128, 128) and directionalLight(128, 128, 128, 0, 0, -1), lightFalloff(1, 0, 0), and lightSpecular(0, 0, 0). Lights need to be included in the draw() to remain persistent in a looping program. Placing them in the setup() of a looping program will cause them to only have an effect the first time through the loop.
Syntax
lights()
Returns    void
Related    ambientLight()
directionalLight()
pointLight()
spotLight()
noLights()
*/
void lights();

/*
Name
lightSpecular()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
directionalLight(102, 102, 102, 0, 0, -1);
lightSpecular(204, 204, 204);
directionalLight(102, 102, 102, 0, 1, -1);
lightSpecular(102, 102, 102);
translate(20, 50, 0);
specular(51, 51, 51);
sphere(30);
translate(60, 0, 0);
specular(102, 102, 102);
sphere(30);
Description    Sets the specular color for lights. Like fill(), it affects only the elements which are created after it in the code. Specular refers to light which bounces off a surface in a preferred direction (rather than bouncing in all directions like a diffuse light) and is used for creating highlights. The specular quality of a light interacts with the specular material qualities set through the specular() and shininess() functions.
Syntax
lightSpecular(v1, v2, v3)
Parameters
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
Returns    void
Related    specular()
lights()
ambientLight()
pointLight()
spotLight()
*/
void lightSpecular(float v1, float v2, float v3);

/*
Name
noLights()
Description    Disable all lighting. Lighting is turned off by default and enabled with the lights() function. This function can be used to disable lighting so that 2D geometry (which does not require lighting) can be drawn after a set of lighted 3D geometry.
Syntax
noLights()
Returns    void
Related    lights()
*/
void noLights();

/*
Name
normal()
Examples
example pic
size(100, 100, P3D);
noStroke();
background(0);
pointLight(150, 250, 150, 10, 30, 50);
beginShape();
normal(0, 0, 1);
vertex(20, 20, -10);
vertex(80, 20, 10);
vertex(80, 80, -10);
vertex(20, 80, 10);
endShape(CLOSE);
Description    Sets the current normal vector. Used for drawing three dimensional shapes and surfaces, normal() specifies a vector perpendicular to a shape's surface which, in turn, determines how lighting affects it. Processing attempts to automatically assign normals to shapes, but since that's imperfect, this is a better option when you want more control. This function is identical to glNormal3f() in OpenGL.
Syntax
normal(nx, ny, nz)
Parameters
nx    float: x direction
ny    float: y direction
nz    float: z direction
Returns    void
Related    beginShape()
endShape()
lights()
*/
//conflicted in mac
void normal(float nx, float ny, float nz);

/*
Name
pointLight()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
pointLight(51, 102, 126, 35, 40, 36);
translate(80, 50, 0);
sphere(30);
Description    Adds a point light. Lights need to be included in the draw() to remain persistent in a looping program. Placing them in the setup() of a looping program will cause them to only have an effect the first time through the loop. The v1, v2, and v3 parameters are interpreted as either RGB or HSB values, depending on the current color mode. The x, y, and z parameters set the position of the light.
Syntax
pointLight(v1, v2, v3, x, y, z)
Parameters
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
x    float: x-coordinate of the light
y    float: y-coordinate of the light
z    float: z-coordinate of the light
Returns    void
Related    lights()
directionalLight()
ambientLight()
spotLight()
*/
void pointLight(float v1, float v2, float v3, float x, float y, float z);

/*
Name
spotLight()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
spotLight(51, 102, 126, 80, 20, 40, -1, 0, 0, PI/2, 2);
translate(20, 50, 0);
sphere(30);
example pic
size(100, 100, P3D);
int concentration = 600;  // Try 1 -> 10000
background(0);
noStroke();
spotLight(51, 102, 126, 50, 50, 400,
          0, 0, -1, PI/16, concentration);
translate(80, 50, 0);
sphere(30);
Description    Adds a spot light. Lights need to be included in the draw() to remain persistent in a looping program. Placing them in the setup() of a looping program will cause them to only have an effect the first time through the loop. The v1, v2, and v3 parameters are interpreted as either RGB or HSB values, depending on the current color mode. The x, y, and z parameters specify the position of the light and nx, ny, nz specify the direction of light. The angle parameter affects angle of the spotlight cone, while concentration sets the bias of light focusing toward the center of that cone.
Syntax
spotLight(v1, v2, v3, x, y, z, nx, ny, nz, angle, concentration)
Parameters
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
x    float: x-coordinate of the light
y    float: y-coordinate of the light
z    float: z-coordinate of the light
nx    float: direction along the x axis
ny    float: direction along the y axis
nz    float: direction along the z axis
angle    float: angle of the spotlight cone
concentration    float: exponent determining the center bias of the cone
Returns    void
Related    lights()
directionalLight()
pointLight()
ambientLight()
*/
void spotLight(float v1, float v2, float v3, float x, float y, float z, float nx, float ny, float nz, float angle, float concentration);

//Camera
/*
Name
beginCamera()
Examples
example pic
size(100, 100, P3D);
noFill();

beginCamera();
camera();
rotateX(-PI/6);
endCamera();

translate(50, 50, 0);
rotateY(PI/3);
box(45);
Description    The beginCamera() and endCamera() functions enable advanced customization of the camera space. The functions are useful if you want to more control over camera movement, however for most users, the camera() function will be sufficient.

The camera functions will replace any transformations (such as rotate() or translate()) that occur before them in draw(), but they will not automatically replace the camera transform itself. For this reason, camera functions should be placed at the beginning of draw() (so that transformations happen afterwards), and the camera() function can be used after beginCamera() if you want to reset the camera before applying transformations.

This function sets the matrix mode to the camera matrix so calls such as translate(), rotate(), applyMatrix() and resetMatrix() affect the camera. beginCamera() should always be used with a following endCamera() and pairs of beginCamera() and endCamera() cannot be nested.
Syntax
beginCamera()
Returns    void
Related    camera()
endCamera()
applyMatrix()
resetMatrix()
translate()
scale()
*/
void beginCamera();

/*
Name
camera()
Examples
example pic
size(100, 100, P3D);
noFill();
background(204);
camera(70.0, 35.0, 120.0, 50.0, 50.0, 0.0,
       0.0, 1.0, 0.0);
translate(50, 50, 0);
rotateX(-PI/6);
rotateY(PI/3);
box(45);
Description    Sets the position of the camera through setting the eye position, the center of the scene, and which axis is facing upward. Moving the eye position and the direction it is pointing (the center of the scene) allows the images to be seen from different angles. The version without any parameters sets the camera to the default position, pointing to the center of the display window with the Y axis as up. The default values are camera(width/2.0, height/2.0, (height/2.0) / tan(PI*30.0 / 180.0), width/2.0, height/2.0, 0, 0, 1, 0). This function is similar to gluLookAt() in OpenGL, but it first clears the current camera settings.
Syntax
camera()
camera(eyeX, eyeY, eyeZ, centerX, centerY, centerZ, upX, upY, upZ)
Parameters
eyeX    float: x-coordinate for the eye
eyeY    float: y-coordinate for the eye
eyeZ    float: z-coordinate for the eye
centerX    float: x-coordinate for the center of the scene
centerY    float: y-coordinate for the center of the scene
centerZ    float: z-coordinate for the center of the scene
upX    float: usually 0.0, 1.0, or -1.0
upY    float: usually 0.0, 1.0, or -1.0
upZ    float: usually 0.0, 1.0, or -1.0
Returns    void
Related    beginCamera()
endCamera()
frustum()
*/
void camera();
void camera(float eyeX, float eyeY, float eyeZ, float centerX, float centerY, float centerZ, float upX, float upY, float upZ);

/*
Name
endCamera()
Examples
example pic
size(100, 100, P3D);
noFill();

beginCamera();
camera();
rotateX(-PI/6);
endCamera();

translate(50, 50, 0);
rotateY(PI/3);
box(45);
Description    The beginCamera() and endCamera() functions enable advanced customization of the camera space. Please see the reference for beginCamera() for a description of how the functions are used.
Syntax
endCamera()
Returns    void
Related    beginCamera()
camera()
*/
void endCamera();

/*
Name
frustum()
Examples
example pic
size(100, 100, P3D);
noFill();
background(204);
frustum(-10, 0, 0, 10, 10, 200);
rotateY(PI/6);
box(45);
Description    Sets a perspective matrix as defined by the parameters.

A frustum is a geometric form: a pyramid with its top cut off. With the viewer's eye at the imaginary top of the pyramid, the six planes of the frustum act as clipping planes when rendering a 3D view. Thus, any form inside the clipping planes is rendered and visible; anything outside those planes is not visible.

Setting the frustum has the effect of changing the perspective with which the scene is rendered. This can be achieved more simply in many cases by using perspective().

Note that the near value must be greater than zero (as the point of the frustum "pyramid" cannot converge "behind" the viewer). Similarly, the far value must be greater than the near value (as the "far" plane of the frustum must be "farther away" from the viewer than the near plane).

Works like glFrustum, except it wipes out the current perspective matrix rather than multiplying itself with it.
Syntax
frustum(left, right, bottom, top, near, far)
Parameters
left    float: left coordinate of the clipping plane
right    float: right coordinate of the clipping plane
bottom    float: bottom coordinate of the clipping plane
top    float: top coordinate of the clipping plane
near    float: near component of the clipping plane; must be greater than zero
far    float: far component of the clipping plane; must be greater than the near value
Returns    void
Related    camera()
beginCamera()
endCamera()
perspective()
*/
void frustum(float left, float right, float bottom, float top, float near, float far);

/*
Name
ortho()
Examples
example pic
size(100, 100, P3D);
noFill();
ortho(-width/2, width/2, -height/2, height/2); // Same as ortho()
translate(width/2, height/2, 0);
rotateX(-PI/6);
rotateY(PI/3);
box(45);
Description    Sets an orthographic projection and defines a parallel clipping volume. All objects with the same dimension appear the same size, regardless of whether they are near or far from the camera. The parameters to this function specify the clipping volume where left and right are the minimum and maximum x values, top and bottom are the minimum and maximum y values, and near and far are the minimum and maximum z values. If no parameters are given, the default is used: ortho(-width/2, width/2, -height/2, height/2).
Syntax
ortho()
ortho(left, right, bottom, top)
ortho(left, right, bottom, top, near, far)
Parameters
left    float: left plane of the clipping volume
right    float: right plane of the clipping volume
bottom    float: bottom plane of the clipping volume
top    float: top plane of the clipping volume
near    float: maximum distance from the origin to the viewer
far    float: maximum distance from the origin away from the viewer
Returns    void
*/
void ortho();
void ortho(float left, float right, float bottom, float top);
void ortho(float left, float right, float bottom, float top, float near, float far);

/*
Name
perspective()
Examples
example pic
// Re-creates the default perspective
size(100, 100, P3D);
noFill();
float fov = PI/3.0;
float cameraZ = (height/2.0) / tan(fov/2.0);
perspective(fov, float(width)/float(height),
            cameraZ/10.0, cameraZ*10.0);
translate(50, 50, 0);
rotateX(-PI/6);
rotateY(PI/3);
box(45);
Description    Sets a perspective projection applying foreshortening, making distant objects appear smaller than closer ones. The parameters define a viewing volume with the shape of truncated pyramid. Objects near to the front of the volume appear their actual size, while farther objects appear smaller. This projection simulates the perspective of the world more accurately than orthographic projection. The version of perspective without parameters sets the default perspective and the version with four parameters allows the programmer to set the area precisely. The default values are: perspective(PI/3.0, width/height, cameraZ/10.0, cameraZ*10.0) where cameraZ is ((height/2.0) / tan(PI*60.0/360.0));
Syntax
perspective()
perspective(fovy, aspect, zNear, zFar)
Parameters
fovy    float: field-of-view angle (in radians) for vertical direction
aspect    float: ratio of width to height
zNear    float: z-position of nearest clipping plane
zFar    float: z-position of farthest clipping plane
Returns    void
*/
void perspective();
void perspective(float fovy, float aspect, float zNear, float zFar);

/*
Name
printCamera()
Examples
size(100, 100, P3D);
printCamera();

// The program above prints this data:
// 01.0000  00.0000  00.0000 -50.0000
// 00.0000  01.0000  00.0000 -50.0000
// 00.0000  00.0000  01.0000 -86.6025
// 00.0000  00.0000  00.0000  01.0000
Description    Prints the current camera matrix to the Console (the text window at the bottom of Processing).
Syntax
printCamera()
Returns    void
Related    camera()
*/
void printCamera();

/*
Name
printProjection()
Examples
size(100, 100, P3D);
printProjection();

// The program above prints this data:
// 01.7321  00.0000  00.0000  00.0000
// 00.0000 -01.7321  00.0000  00.0000
// 00.0000  00.0000 -01.0202 -17.4955
// 00.0000  00.0000 -01.0000  00.0000
Description    Prints the current projection matrix to the Console (the text window at the bottom of Processing).
Syntax
printProjection()
Returns    void
Related    camera()
*/
void printProjection();

//Coordinates
/*
Name
modelX()
Examples
void setup() {
    size(500, 500, P3D);
    noFill();
}

void draw() {
    background(0);

    pushMatrix();
    // start at the middle of the screen
    translate(width/2, height/2, -200);
    // some random rotation to make things interesting
    rotateY(1.0); //yrot);
    rotateZ(2.0); //zrot);
    // rotate in X a little more each frame
    rotateX(frameCount / 100.0);
    // offset from center
    translate(0, 150, 0);

    // draw a white box outline at (0, 0, 0)
    stroke(255);
    box(50);

    // the box was drawn at (0, 0, 0), store that location
    float x = modelX(0, 0, 0);
    float y = modelY(0, 0, 0);
    float z = modelZ(0, 0, 0);
    // clear out all the transformations
    popMatrix();

    // draw another box at the same (x, y, z) coordinate as the other
    pushMatrix();
    translate(x, y, z);
    stroke(255, 0, 0);
    box(50);
    popMatrix();
}
Description    Returns the three-dimensional X, Y, Z position in model space. This returns the X value for a given coordinate based on the current set of transformations (scale, rotate, translate, etc.) The X value can be used to place an object in space relative to the location of the original point once the transformations are no longer in use.

In the example, the modelX(), modelY(), and modelZ() functions record the location of a box in space after being placed using a series of translate and rotate commands. After popMatrix() is called, those transformations no longer apply, but the (x, y, z) coordinate returned by the model functions is used to place another box in the same location.
Syntax
modelX(x, y, z)
Parameters
x    float: 3D x-coordinate to be mapped
y    float: 3D y-coordinate to be mapped
z    float: 3D z-coordinate to be mapped
Returns    float
Related    modelY()
modelZ()
*/
float modelX(float x, float y, float z);

/*
Name
modelY()
Examples
void setup() {
    size(500, 500, P3D);
    noFill();
}

void draw() {
    background(0);

    pushMatrix();
    // start at the middle of the screen
    translate(width/2, height/2, -200);
    // some random rotation to make things interesting
    rotateY(1.0); //yrot);
    rotateZ(2.0); //zrot);
    // rotate in X a little more each frame
    rotateX(frameCount / 100.0);
    // offset from center
    translate(0, 150, 0);

    // draw a white box outline at (0, 0, 0)
    stroke(255);
    box(50);

    // the box was drawn at (0, 0, 0), store that location
    float x = modelX(0, 0, 0);
    float y = modelY(0, 0, 0);
    float z = modelZ(0, 0, 0);
    // clear out all the transformations
    popMatrix();

    // draw another box at the same (x, y, z) coordinate as the other
    pushMatrix();
    translate(x, y, z);
    stroke(255, 0, 0);
    box(50);
    popMatrix();
}
Description    Returns the three-dimensional X, Y, Z position in model space. This returns the Y value for a given coordinate based on the current set of transformations (scale, rotate, translate, etc.) The Y value can be used to place an object in space relative to the location of the original point once the transformations are no longer in use.

In the example, the modelX(), modelY(), and modelZ() functions record the location of a box in space after being placed using a series of translate and rotate commands. After popMatrix() is called, those transformations no longer apply, but the (x, y, z) coordinate returned by the model functions is used to place another box in the same location.
Syntax
modelY(x, y, z)
Parameters
x    float: 3D x-coordinate to be mapped
y    float: 3D y-coordinate to be mapped
z    float: 3D z-coordinate to be mapped
Returns    float
Related    modelX()
modelZ()
*/
float modelY(float x, float y, float z);

/*
Name
modelZ()
Examples
void setup() {
    size(500, 500, P3D);
    noFill();
}

void draw() {
    background(0);

    pushMatrix();
    // start at the middle of the screen
    translate(width/2, height/2, -200);
    // some random rotation to make things interesting
    rotateY(1.0); //yrot);
    rotateZ(2.0); //zrot);
    // rotate in X a little more each frame
    rotateX(frameCount / 100.0);
    // offset from center
    translate(0, 150, 0);

    // draw a white box outline at (0, 0, 0)
    stroke(255);
    box(50);

    // the box was drawn at (0, 0, 0), store that location
    float x = modelX(0, 0, 0);
    float y = modelY(0, 0, 0);
    float z = modelZ(0, 0, 0);
    // clear out all the transformations
    popMatrix();

    // draw another box at the same (x, y, z) coordinate as the other
    pushMatrix();
    translate(x, y, z);
    stroke(255, 0, 0);
    box(50);
    popMatrix();
}
Description    Returns the three-dimensional X, Y, Z position in model space. This returns the Z value for a given coordinate based on the current set of transformations (scale, rotate, translate, etc.) The Z value can be used to place an object in space relative to the location of the original point once the transformations are no longer in use.

In the example, the modelX(), modelY(), and modelZ() functions record the location of a box in space after being placed using a series of translate and rotate commands. After popMatrix() is called, those transformations no longer apply, but the (x, y, z) coordinate returned by the model functions is used to place another box in the same location.
Syntax
modelZ(x, y, z)
Parameters
x    float: 3D x-coordinate to be mapped
y    float: 3D y-coordinate to be mapped
z    float: 3D z-coordinate to be mapped
Returns    float
Related    modelX()
modelY()
*/
float modelZ(float x, float y, float z);

/*
Name
screenX()
Examples
void setup() {
    size(100, 100, P3D);
}

void draw() {
    background(204);

    float x = mouseX;
    float y = mouseY;
    float z = -100;

    // Draw "X" at z = -100
    stroke(255);
    line(x-10, y-10, z, x+10, y+10, z);
    line(x+10, y-10, z, x-10, y+10, z);

    // Draw gray line at z = 0 and same
    // x value. Notice the parallax
    stroke(102);
    line(x, 0, 0, x, height, 0);

    // Draw black line at z = 0 to match
    // the x value element drawn at z = -100
    stroke(0);
    float theX = screenX(x, y, z);
    line(theX, 0, 0, theX, height, 0);
}
Description    Takes a three-dimensional X, Y, Z position and returns the X value for where it will appear on a (two-dimensional) screen.
Syntax
screenX(x, y)
screenX(x, y, z)
Parameters
x    float: 3D x-coordinate to be mapped
y    float: 3D y-coordinate to be mapped
z    float: 3D z-coordinate to be mapped
Returns    float
Related    screenY()
screenZ()
*/
float screenX(float x, float y);
float screenX(float x, float y, float z);

/*
Name
screenY()
Examples
void setup() {
    size(100, 100, P3D);
}

void draw() {
    background(204);

    float x = mouseX;
    float y = mouseY;
    float z = -100;

    // Draw "X" at z = -100
    stroke(255);
    line(x-10, y-10, z, x+10, y+10, z);
    line(x+10, y-10, z, x-10, y+10, z);

    // Draw gray line at z = 0 and same
    // y value. Notice the parallax
    stroke(102);
    line(0, y, 0, width, y, 0);

    // Draw black line at z = 0 to match
    // the y value element drawn at z = -100
    stroke(0);
    float theY = screenY(x, y, z);
    line(0, theY, 0, width, theY, 0);
}
Description    Takes a three-dimensional X, Y, Z position and returns the Y value for where it will appear on a (two-dimensional) screen.
Syntax
screenY(x, y)
screenY(x, y, z)
Parameters
x    float: 3D x-coordinate to be mapped
y    float: 3D y-coordinate to be mapped
z    float: 3D z-coordinate to be mapped
Returns    float
Related    screenX()
screenZ()
*/
float screenY(float x, float y);
float screenY(float x, float y, float z);

/*
Name
screenZ()
Examples
Coming soon...

Description    Takes a three-dimensional X, Y, Z position and returns the Z value for where it will appear on a (two-dimensional) screen.
Syntax
screenZ(x, y, z)
Parameters
x    float: 3D x-coordinate to be mapped
y    float: 3D y-coordinate to be mapped
z    float: 3D z-coordinate to be mapped
Returns    float
Related    screenX()
screenY()
*/
float screenZ(float x, float y, float z);

//Material Properties
/*
Name
ambient()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
directionalLight(153, 153, 153, .5, 0, -1);
ambientLight(153, 102, 0);
ambient(51, 26, 0);
translate(70, 50, 0);
sphere(30);
Description    Sets the ambient reflectance for shapes drawn to the screen. This is combined with the ambient light component of environment. The color components set through the parameters define the reflectance. For example in the default color mode, setting v1=255, v2=127, v3=0, would cause all the red light to reflect and half of the green light to reflect. Used in combination with emissive(), specular(), and shininess() in setting the material properties of shapes.
Syntax
ambient(rgb)
ambient(gray)
ambient(v1, v2, v3)
Parameters
rgb    int: any value of the color datatype
gray    float: number specifying value between white and black
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
Returns    void
Related    emissive()
specular()
shininess()
*/
void ambient(colorType rgb);
void ambient(float gray);
void ambient(float v1, float v2, float v3);

/*
Name
emissive()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
background(0);
directionalLight(204, 204, 204, .5, 0, -1);
emissive(0, 26, 51);
translate(70, 50, 0);
sphere(30);
Description    Sets the emissive color of the material used for drawing shapes drawn to the screen. Used in combination with ambient(), specular(), and shininess() in setting the material properties of shapes.
Syntax
emissive(rgb)
emissive(gray)
emissive(v1, v2, v3)
Parameters
rgb    int: color to set
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
Returns    void
Related    ambient()
specular()
shininess()
*/
void emissive(colorType rgb);
void emissive(float gray);
void emissive(float v1, float v2, float v3);

/*
Name
shininess()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
background(0);
fill(0, 51, 102);
ambientLight(102, 102, 102);
lightSpecular(204, 204, 204);
directionalLight(102, 102, 102, 0, 0, -1);
specular(255, 255, 255);
translate(30, 50, 0);
shininess(1.0);
sphere(20);  // Left sphere
translate(40, 0, 0);
shininess(5.0);
sphere(20);  // Right sphere
Description    Sets the amount of gloss in the surface of shapes. Used in combination with ambient(), specular(), and emissive() in setting the material properties of shapes.
Syntax
shininess(shine)
Parameters
shine    float: degree of shininess
Returns    void
Related    emissive()
ambient()
specular()
*/
void shininess(float shine);

/*
Name
specular()
Examples
example pic
size(100, 100, P3D);
background(0);
noStroke();
background(0);
fill(0, 51, 102);
lightSpecular(255, 255, 255);
directionalLight(204, 204, 204, 0, 0, -1);
translate(20, 50, 0);
specular(255, 255, 255);
sphere(30);
translate(60, 0, 0);
specular(204, 102, 0);
sphere(30);
Description    Sets the specular color of the materials used for shapes drawn to the screen, which sets the color of highlights. Specular refers to light which bounces off a surface in a preferred direction (rather than bouncing in all directions like a diffuse light). Used in combination with emissive(), ambient(), and shininess() in setting the material properties of shapes.
Syntax
specular(rgb)
specular(gray)
specular(v1, v2, v3)
Parameters
rgb    int: color to set
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
Returns    void
Related    lightSpecular()
ambient()
emissive()
shininess()
*/
void specular(colorType rgb);
void specular(float gray);
void specular(float v1, float v2, float v3);

//Color
//Setting
/*
Name
background()
Examples
example pic
background(51);
example pic
background(255, 204, 0);
example pic
PImage img;
img = loadImage("laDefense.jpg");
background(img);
Description    The background() function sets the color used for the background of the Processing window. The default background is light gray. This function is typically used within draw() to clear the display window at the beginning of each frame, but it can be used inside setup() to set the background on the first frame of animation or if the backgound need only be set once.

An image can also be used as the background for a sketch, although the image's width and height must match that of the sketch window. Images used with background() will ignore the current tint() setting. To resize an image to the size of the sketch window, use image.resize(width, height).

It is not possible to use the transparency alpha parameter with background colors on the main drawing surface. It can only be used along with a PGraphics object and createGraphics().
Syntax
background(rgb)
background(rgb, alpha)
background(gray)
background(gray, alpha)
background(v1, v2, v3)
background(v1, v2, v3, alpha)
background(image)
Parameters
rgb    int: any value of the color datatype
alpha    float: opacity of the background
gray    float: specifies a value between white and black
v1    float: red or hue value (depending on the current color mode)
v2    float: green or saturation value (depending on the current color mode)
v3    float: blue or brightness value (depending on the current color mode)
image    PImage: PImage to set as background (must be same size as the sketch window)
Returns    void
Related    stroke()
fill()
tint()
colorMode()
*/
/*inline void background(colorType rgb);
inline void background(colorType rgb, float alpha);
inline void background(float gray);
inline void background(float gray, float alpha);
inline void background(float v1, float v2, float v3);
inline void background(float v1, float v2, float v3, float alpha);*/
inline void background(float gray)
{
    if (gray < 256) {
    glClearColor(gray * (HSB - $colorMode) / $colorMax1, gray * (HSB - $colorMode) / $colorMax2, gray * (HSB - $colorMode) / $colorMax3, 1.0f);
    }
    else {
        colorType rgb = (colorType)gray;
        glClearColor(((rgb * 0xFF0000) >> 16) * (HSB - $colorMode) / $colorMax1, ((rgb * 0xFF00) >> 8)  * (HSB - $colorMode) / $colorMax2, (rgb * 0xFF)  * (HSB - $colorMode) / $colorMax3, ((rgb * 0xFF000000) >> 24)  * (HSB - $colorMode) / $colorMaxA);
    }
    glClear(GL_COLOR_BUFFER_BIT);
}

inline void background(float gray, float alpha)
{
    glClearColor(gray * (HSB - $colorMode) / $colorMax1, gray * (HSB - $colorMode) / $colorMax2, gray * (HSB - $colorMode) / $colorMax3, alpha / $colorMaxA);
    glClear(GL_COLOR_BUFFER_BIT);
}

/*inline void background(colorType rgb)
{
    glClearColor(((rgb * 0xFF0000) >> 16) * (HSB - $colorMode) / $colorMax1, ((rgb * 0xFF00) >> 8)  * (HSB - $colorMode) / $colorMax2, (rgb * 0xFF)  * (HSB - $colorMode) / $colorMax3, ((rgb * 0xFF000000) >> 24)  * (HSB - $colorMode) / $colorMaxA);
    glClear(GL_COLOR_BUFFER_BIT);
}*/

inline void background(colorType rgb, float alpha)
{
    glClearColor(((rgb * 0xFF0000) >> 16) * (HSB - $colorMode) / $colorMax1, ((rgb * 0xFF00) >> 8)  * (HSB - $colorMode) / $colorMax2, (rgb * 0xFF)  * (HSB - $colorMode) / $colorMax3, alpha / $colorMaxA);
    glClear(GL_COLOR_BUFFER_BIT);
}

inline void background(float v1, float v2, float v3)
{
    glClearColor(v1 * (HSB - $colorMode) / $colorMax1, v2 * (HSB - $colorMode) / $colorMax2, v3 * (HSB - $colorMode) / $colorMax3, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
}

inline void background(float v1, float v2, float v3, float alpha)
{
    glClearColor(v1 * (HSB - $colorMode) / $colorMax1, v2 * (HSB - $colorMode) / $colorMax2, v3 * (HSB - $colorMode) / $colorMax3, alpha / $colorMaxA);
    glClear(GL_COLOR_BUFFER_BIT);
}

inline void background(PImage image);

/*
Name
clear()
Examples
PGraphics pg;

void setup() {
    size(200, 200);
    pg = createGraphics(100, 100);
}

void draw() {
    background(204);
    pg.beginDraw();
    pg.stroke(0, 102, 153);
    pg.line(0, 0, mouseX, mouseY);
    pg.endDraw();
    image(pg, 50, 50);
}

// Click to clear the PGraphics object
void mousePressed() {
    pg.beginDraw();
    pg.clear();
    pg.endDraw();
}
Description    Clears the pixels within a buffer. This function only works on PGraphics objects created with the createGraphics() function. Unlike the main graphics context (the display window), pixels in additional graphics areas created with createGraphics() can be entirely or partially transparent. This function clears everything in a PGraphics object to make all of the pixels 100% transparent.
Syntax
clear()
Returns    void
*/
//clear()

/*
Name
colorMode()
Examples
example pic
noStroke();
colorMode(RGB, 100);
for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
        stroke(i, j, 0);
        point(i, j);
    }
}
example pic
noStroke();
colorMode(HSB, 100);
for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
        stroke(i, j, 100);
        point(i, j);
    }
}
example pic
// If the color is defined here, it won't be
// affected by the colorMode() in setup().
// Instead, just declare the variable here and
// assign the value after the colorMode() in setup()
//color bg = color(180, 50, 50);  // No
color bg;  // Yes, but assign it in setup()

void setup() {
    size(100, 100);
    colorMode(HSB, 360, 100, 100);
    bg = color(180, 50, 50);
}

void draw() {
    background(bg);
}
Description    Changes the way Processing interprets color data. By default, the parameters for fill(), stroke(), background(), and color() are defined by values between 0 and 255 using the RGB color model. The colorMode() function is used to change the numerical range used for specifying colors and to switch color systems. For example, calling colorMode(RGB, 1.0) will specify that values are specified between 0 and 1. The limits for defining colors are altered by setting the parameters max, max1, max2, max3, and maxA.

After changing the range of values for colors with code like colorMode(HSB, 360, 100, 100), those ranges remain in use until they are explicitly changed again. For example, after running colorMode(HSB, 360, 100, 100) and then changing back to colorMode(RGB), the range for R will be 0 to 360 and the range for G and B will be 0 to 100. To avoid this, be explicit about the ranges when changing the color mode. For instance, instead of colorMode(RGB), write colorMode(RGB, 255, 255, 255).
Syntax
colorMode(mode)
colorMode(mode, max)
colorMode(mode, max1, max2, max3)
colorMode(mode, max1, max2, max3, maxA)
Parameters
mode    int: Either RGB or HSB, corresponding to Red/Green/Blue and Hue/Saturation/Brightness
max    float: range for all color elements
max1    float: range for the red or hue depending on the current color mode
max2    float: range for the green or saturation depending on the current color mode
max3    float: range for the blue or brightness depending on the current color mode
maxA    float: range for the alpha
Returns    void
Related    background()
fill()
stroke()
*/
void colorMode(_penum mode);
void colorMode(_penum mode, float max);
void colorMode(_penum mode, float max1, float max2, float max3);
void colorMode(_penum mode, float max1, float max2, float max3, float maxA);

/*
Name
fill()
Examples
example pic
fill(153);
rect(30, 20, 55, 55);
example pic
fill(204, 102, 0);
rect(30, 20, 55, 55);
Description    Sets the color used to fill shapes. For example, if you run fill(204, 102, 0), all subsequent shapes will be filled with orange. This color is either specified in terms of the RGB or HSB color depending on the current colorMode(). The default color space is RGB, with each value in the range from 0 to 255.

When using hexadecimal notation to specify a color, use "#" or "0x" before the values (e.g., #CCFFAA or 0xFFCCFFAA). The # syntax uses six digits to specify a color (just as colors are typically specified in HTML and CSS). When using the hexadecimal notation starting with "0x", the hexadecimal value must be specified with eight characters; the first two characters define the alpha component, and the remainder define the red, green, and blue components.

The value for the "gray" parameter must be less than or equal to the current maximum value as specified by colorMode(). The default maximum value is 255.

To change the color of an image or a texture, use tint().
Syntax
fill(rgb)
fill(rgb, alpha)
fill(gray)
fill(gray, alpha)
fill(v1, v2, v3)
fill(v1, v2, v3, alpha)
Parameters
rgb    int: color variable or hex value
alpha    float: opacity of the fill
gray    float: number specifying value between white and black
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
Returns    void
Related    noFill()
stroke()
noStroke()
tint()
background()
colorMode()
*/
void fill(colorType rgb);
void fill(colorType rgb, float alpha);
void fill(float gray);
void fill(float gray, float alpha);
void fill(float v1, float v2, float v3);
void fill(float v1, float v2, float v3, float alpha);

/*
Name
noFill()
Examples
example pic
rect(15, 10, 55, 55);
noFill();
rect(30, 20, 55, 55);
Description    Disables filling geometry. If both noStroke() and noFill() are called, nothing will be drawn to the screen.
Syntax
noFill()
Returns    void
Related    fill()
stroke()
noStroke()
*/
void noFill();

/*
Name
noStroke()
Examples
example pic
noStroke();
rect(30, 20, 55, 55);
Description    Disables drawing the stroke (outline). If both noStroke() and noFill() are called, nothing will be drawn to the screen.
Syntax
noStroke()
Returns    void
Related    stroke()
fill()
noFill()
*/
void noStroke();

/*
Name
stroke()
Examples
example pic
stroke(153);
rect(30, 20, 55, 55);
example pic
stroke(204, 102, 0);
rect(30, 20, 55, 55);
Description    Sets the color used to draw lines and borders around shapes. This color is either specified in terms of the RGB or HSB color depending on the current colorMode(). The default color space is RGB, with each value in the range from 0 to 255.

When using hexadecimal notation to specify a color, use "#" or "0x" before the values (e.g., #CCFFAA or 0xFFCCFFAA). The # syntax uses six digits to specify a color (just as colors are typically specified in HTML and CSS). When using the hexadecimal notation starting with "0x", the hexadecimal value must be specified with eight characters; the first two characters define the alpha component, and the remainder define the red, green, and blue components.

The value for the gray parameter must be less than or equal to the current maximum value as specified by colorMode(). The default maximum value is 255.

When drawing in 2D with the default renderer, you may need hint(ENABLE_STROKE_PURE) to improve drawing quality (at the expense of performance). See the hint() documentation for more details.
Syntax
stroke(rgb)
stroke(rgb, alpha)
stroke(gray)
stroke(gray, alpha)
stroke(v1, v2, v3)
stroke(v1, v2, v3, alpha)
Parameters
rgb    int: color value in hexadecimal notation
alpha    float: opacity of the stroke
gray    float: specifies a value between white and black
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
Returns    void
Related    noStroke()
strokeWeight()
strokeJoin()
strokeCap()
fill()
noFill()
tint()
background()
colorMode()
*/
void stroke(colorType rgb);
void stroke(colorType rgb, float alpha);
void stroke(float gray);
void stroke(float gray, float alpha);
void stroke(float v1, float v2, float v3);
void stroke(float v1, float v2, float v3, float alpha);

//Creating & Reading
/*
Name
alpha()
Examples
example pic
noStroke();
color c = color(0, 126, 255, 102);
fill(c);
rect(15, 15, 35, 70);
float value = alpha(c);  // Sets 'value' to 102
fill(value);
rect(50, 15, 35, 70);
Description    Extracts the alpha value from a color.
Syntax
alpha(rgb)
Parameters
rgb    int: any value of the color datatype
Returns    float
Related    red()
green()
blue()
hue()
saturation()
brightness()
*/
float alpha(colorType rgb);

/*
Name
blue()
Examples
example pic
color c = color(175, 100, 220);  // Define color 'c'
fill(c);  // Use color variable 'c' as fill color
rect(15, 20, 35, 60);  // Draw left rectangle

float blueValue = blue(c);  // Get blue in 'c'
println(blueValue);  // Prints "220.0"
fill(0, 0, blueValue);  // Use 'blueValue' in new fill
rect(50, 20, 35, 60);  // Draw right rectangle
Description    Extracts the blue value from a color, scaled to match current colorMode(). The value is always returned as a float, so be careful not to assign it to an int value.

The blue() function is easy to use and understand, but it is slower than a technique called bit masking. When working in colorMode(RGB, 255), you can acheive the same results as blue() but with greater speed by using a bit mask to remove the other color components. For example, the following two lines of code are equivalent means of getting the blue value of the color value c:

float b1 = blue(c);   // Simpler, but slower to calculate
float b2 = c & 0xFF;  // Very fast to calculate
Syntax
blue(rgb)
Parameters
rgb    int: any value of the color datatype
Returns    float
Related    red()
green()
alpha()
hue()
saturation()
brightness()
>> (right shift)
*/
float blue(colorType rgb);

/*
Name
brightness()
Examples
example pic
noStroke();
colorMode(HSB, 255);
color c = color(0, 126, 255);
fill(c);
rect(15, 20, 35, 60);
float value = brightness(c);  // Sets 'value' to 255
fill(value);
rect(50, 20, 35, 60);
Description    Extracts the brightness value from a color.
Syntax
brightness(rgb)
Parameters
rgb    int: any value of the color datatype
Returns    float
Related    red()
green()
blue()
alpha()
hue()
saturation()
*/
void brightness(colorType rgb);

/*
Name
color()
Examples
example pic
color c = color(255, 204, 0);  // Define color 'c'
fill(c);  // Use color variable 'c' as fill color
noStroke();  // Don't draw a stroke around shapes
rect(30, 20, 55, 55);  // Draw rectangle
example pic
color c = color(255, 204, 0);  // Define color 'c'
fill(c);  // Use color variable 'c' as fill color
noStroke();  // Don't draw a stroke around shapes
ellipse(25, 25, 80, 80);  // Draw left circle

// Using only one value with color()
// generates a grayscale value.
c = color(65);  // Update 'c' with grayscale value
fill(c);  // Use updated 'c' as fill color
ellipse(75, 75, 80, 80);  // Draw right circle
example pic
color c;  // Declare color 'c'
noStroke();  // Don't draw a stroke around shapes

// If no colorMode is specified, then the
// default of RGB with scale of 0-255 is used.
c = color(50, 55, 100);  // Create a color for 'c'
fill(c);  // Use color variable 'c' as fill color
rect(0, 10, 45, 80);  // Draw left rect

colorMode(HSB, 100);  // Use HSB with scale of 0-100
c = color(50, 55, 100);  // Update 'c' with new color
fill(c);  // Use updated 'c' as fill color
rect(55, 10, 45, 80);  // Draw right rect
Description    Creates colors for storing in variables of the color datatype. The parameters are interpreted as RGB or HSB values depending on the current colorMode(). The default mode is RGB values from 0 to 255 and, therefore, color(255, 204, 0) will return a bright yellow color (see the first example above).

Note that if only one value is provided to color(), it will be interpreted as a grayscale value. Add a second value, and it will be used for alpha transparency. When three values are specified, they are interpreted as either RGB or HSB values. Adding a fourth value applies alpha transparency.

Note that when using hexadecimal notation, it is not necessary to use color(), as in: color c = #006699

More about how colors are stored can be found in the reference for the color datatype.
Syntax
color(gray)
color(gray, alpha)
color(v1, v2, v3)
color(v1, v2, v3, alpha)
Parameters
gray    int: number specifying value between white and black
alpha    float, or int: relative to current color range
v1    float, or int: red or hue values relative to the current color range
v2    float, or int: green or saturation values relative to the current color range
v3    float, or int: blue or brightness values relative to the current color range
Returns    int
Related    colorMode()
*/
colorType color(int gray);
colorType color(int gray, float alpha);
colorType color(float v1, float v2, float v3);
colorType color(float v1, float v2, float v3, float alpha);

/*
Name
green()
Examples
example pic
color c = color(20, 75, 200);  // Define color 'c'
fill(c);  // Use color variable 'c' as fill color
rect(15, 20, 35, 60);  // Draw left rectangle

float greenValue = green(c);  // Get green in 'c'
println(greenValue);  // Print "75.0"
fill(0, greenValue, 0);  // Use 'greenValue' in new fill
rect(50, 20, 35, 60);  // Draw right rectangle
Description    Extracts the green value from a color, scaled to match current colorMode(). The value is always returned as a float, so be careful not to assign it to an int value.

The green() function is easy to use and understand, but it is slower than a technique called bit shifting. When working in colorMode(RGB, 255), you can acheive the same results as green() but with greater speed by using the right shift operator (>>) with a bit mask. For example, the following two lines of code are equivalent means of getting the green value of the color value c:

float r1 = green(c);  // Simpler, but slower to calculate
float r2 = c >> 8 & 0xFF;  // Very fast to calculate
Syntax
green(rgb)
Parameters
rgb    int: any value of the color datatype
Returns    float
Related    red()
blue()
alpha()
hue()
saturation()
brightness()
>> (right shift)
*/
float green(colorType rgb);

/*
Name
hue()
Examples
example pic
noStroke();
colorMode(HSB, 255);
color c = color(0, 126, 255);
fill(c);
rect(15, 20, 35, 60);
float value = hue(c);  // Sets 'value' to "0"
fill(value);
rect(50, 20, 35, 60);
Description    Extracts the hue value from a color.
Syntax
hue(rgb)
Parameters
rgb    int: any value of the color datatype
Returns    float
Related    red()
green()
blue()
alpha()
saturation()
brightness()
*/
float hue(colorType rgb);

/*
Name
lerpColor()
Examples
example pic
stroke(255);
background(51);
color from = color(204, 102, 0);
color to = color(0, 102, 153);
color interA = lerpColor(from, to, .33);
color interB = lerpColor(from, to, .66);
fill(from);
rect(10, 20, 20, 60);
fill(interA);
rect(30, 20, 20, 60);
fill(interB);
rect(50, 20, 20, 60);
fill(to);
rect(70, 20, 20, 60);
Description    Calculates a color between two colors at a specific increment. The amt parameter is the amount to interpolate between the two values where 0.0 is equal to the first point, 0.1 is very near the first point, 0.5 is halfway in between, etc.
An amount below 0 will be treated as 0. Likewise, amounts above 1 will be capped at 1. This is different from the behavior of lerp(), but necessary because otherwise numbers outside the range will produce strange and unexpected colors.
Syntax
lerpColor(c1, c2, amt)
Parameters
c1    int: interpolate from this color
c2    int: interpolate to this color
amt    float: between 0.0 and 1.0
Returns    int
Related    color()
lerp()
*/
int lerpColor(int c1, int c2, float awt);

/*
Name
red()
Examples
example pic
color c = color(255, 204, 0);  // Define color 'c'
fill(c);  // Use color variable 'c' as fill color
rect(15, 20, 35, 60);  // Draw left rectangle

float redValue = red(c);  // Get red in 'c'
println(redValue);  // Print "255.0"
fill(redValue, 0, 0);  // Use 'redValue' in new fill
rect(50, 20, 35, 60);  // Draw right rectangle
Description    Extracts the red value from a color, scaled to match current colorMode(). The value is always returned as a float, so be careful not to assign it to an int value.

The red() function is easy to use and understand, but it is slower than a technique called bit shifting. When working in colorMode(RGB, 255), you can acheive the same results as red() but with greater speed by using the right shift operator (>>) with a bit mask. For example, the following two lines of code are equivalent means of getting the red value of the color value c:

float r1 = red(c);  // Simpler, but slower to calculate
float r2 = c >> 16 & 0xFF;  // Very fast to calculate
Syntax
red(rgb)
Parameters
rgb    int: any value of the color datatype
Returns    float
Related    green()
blue()
alpha()
hue()
saturation()
brightness()
>> (right shift)
*/
float red(colorType rgb);

/*
Name
saturation()
Examples
example pic
noStroke();
colorMode(HSB, 255);
color c = color(0, 126, 255);
fill(c);
rect(15, 20, 35, 60);
float value = saturation(c);  // Sets 'value' to 126
fill(value);
rect(50, 20, 35, 60);
Description    Extracts the saturation value from a color.
Syntax
saturation(rgb)
Parameters
rgb    int: any value of the color datatype
Returns    float
Related    red()
green()
blue()
alpha()
hue()
brightness()
*/
float saturation(colorType rgb);

//Image
/*
Name
createImage()
Examples
example pic
PImage img = createImage(66, 66, RGB);
img.loadPixels();
for (int i = 0; i < img.pixels.length; i++) {
    img.pixels[i] = color(0, 90, 102);
}
img.updatePixels();
image(img, 17, 17);
example pic
PImage img = createImage(66, 66, ARGB);
img.loadPixels();
for (int i = 0; i < img.pixels.length; i++) {
    img.pixels[i] = color(0, 90, 102, i % img.width * 2);
}
img.updatePixels();
image(img, 17, 17);
image(img, 34, 34);
Description    Creates a new PImage (the datatype for storing images). This provides a fresh buffer of pixels to play with. Set the size of the buffer with the width and height parameters. The format parameter defines how the pixels are stored. See the PImage reference for more information.

Be sure to include all three parameters, specifying only the width and height (but no format) will produce a strange error.

Advanced users please note that createImage() should be used instead of the syntax new PImage().
Syntax
createImage(w, h, format)
Parameters
w    int: width in pixels
h    int: height in pixels
format    int: Either RGB, ARGB, ALPHA (grayscale alpha channel)
Returns    PImage
Related    PImage
PGraphics
*/
PImage createImage(int w, int h, int format);

//Loading & Displaying
/*
Name
image()
Examples
example pic
PImage img;

void setup() {
    // Images must be in the "data" directory to load correctly
    img = loadImage("laDefense.jpg");
}

void draw() {
    image(img, 0, 0);
}
example pic
PImage img;

void setup() {
    // Images must be in the "data" directory to load correctly
    img = loadImage("laDefense.jpg");
}

void draw() {
    image(img, 0, 0);
    image(img, 0, 0, width/2, height/2);
}
Description    The image() function draws an image to the display window. Images must be in the sketch's "data" directory to load correctly. Select "Add file..." from the "Sketch" menu to add the image to the data directory, or just drag the image file onto the sketch window. Processing currently works with GIF, JPEG, and PNG images.

The img parameter specifies the image to display and by default the a and b parameters define the location of its upper-left corner. The image is displayed at its original size unless the c and d parameters specify a different size. The imageMode() function can be used to change the way these parameters draw the image.

The color of an image may be modified with the tint() function. This function will maintain transparency for GIF and PNG images.
Syntax
image(img, a, b)
image(img, a, b, c, d)
Parameters
img    PImage: the image to display
a    float: x-coordinate of the image by default
b    float: y-coordinate of the image by default
c    float: width to display the image by default
d    float: height to display the image by default
Returns    void
Related    loadImage()
PImage
imageMode()
tint()
background()
alpha()
*/
void image(PImage, float a, float b);
void image(PImage, float a, float b, float c, float d);

/*
Name
imageMode()
Examples
example pic
PImage img;

void setup() {
    img = loadImage("laDefense.jpg");
}

void draw() {
    imageMode(CORNER);
    image(img, 10, 10, 50, 50);  // Draw image using CORNER mode
}
example pic
PImage img;

void setup() {
    img = loadImage("laDefense.jpg");
}

void draw() {
    imageMode(CORNERS);
    image(img, 10, 10, 90, 40);  // Draw image using CORNERS mode
}
example pic
PImage img;

void setup() {
    img = loadImage("laDefense.jpg");
}

void draw() {
    imageMode(CENTER);
    image(img, 50, 50, 80, 80);  // Draw image using CENTER mode
}
Description    Modifies the location from which images are drawn by changing the way in which parameters given to image() are intepreted.

The default mode is imageMode(CORNER), which interprets the second and third parameters of image() as the upper-left corner of the image. If two additional parameters are specified, they are used to set the image's width and height.

imageMode(CORNERS) interprets the second and third parameters of image() as the location of one corner, and the fourth and fifth parameters as the opposite corner.

imageMode(CENTER) interprets the second and third parameters of image() as the image's center point. If two additional parameters are specified, they are used to set the image's width and height.

The parameter must be written in ALL CAPS because Processing is a case-sensitive language.
Syntax
imageMode(mode)
Parameters
mode    int: either CORNER, CORNERS, or CENTER
Returns    void
Related    loadImage()
PImage
image()
background()
*/
void imageMode(_penum mode);

/*
Name
loadImage()
Examples
example pic
PImage img;
img = loadImage("laDefense.jpg");
image(img, 0, 0);
example pic
PImage img;

void setup() {
    img = loadImage("laDefense.jpg");
}

void draw() {
    image(img, 0, 0);
}
example pic
PImage webImg;

void setup() {
    String url = "https://processing.org/img/processing-web.png";
    // Load image from a web server
    webImg = loadImage(url, "png");
}

void draw() {
    background(0);
    image(webImg, 0, 0);
}
Description    Loads an image into a variable of type PImage. Four types of images ( .gif, .jpg, .tga, .png) images may be loaded. To load correctly, images must be located in the data directory of the current sketch.

In most cases, load all images in setup() to preload them at the start of the program. Loading images inside draw() will reduce the speed of a program. Images cannot be loaded outside setup() unless they're inside a function that's called after setup() has already run.

Alternatively, the file maybe be loaded from anywhere on the local computer using an absolute path (something that starts with / on Unix and Linux, or a drive letter on Windows), or the filename parameter can be a URL for a file found on a network.

If the file is not available or an error occurs, null will be returned and an error message will be printed to the console. The error message does not halt the program, however the null value may cause a NullPointerException if your code does not check whether the value returned is null.

The extension parameter is used to determine the image type in cases where the image filename does not end with a proper extension. Specify the extension as the second parameter to loadImage(), as shown in the third example on this page. Note that CMYK images are not supported.

Depending on the type of error, a PImage object may still be returned, but the width and height of the image will be set to -1. This happens if bad image data is returned or cannot be decoded properly. Sometimes this happens with image URLs that produce a 403 error or that redirect to a password prompt, because loadImage() will attempt to interpret the HTML as image data.
Syntax
loadImage(filename)
loadImage(filename, extension)
Parameters
filename    String: name of file to load, can be .gif, .jpg, .tga, or a handful of other image types depending on your platform
extension    String: type of image to load, for example "png", "gif", "jpg"
Returns    PImage
Related    PImage
image()
imageMode()
background()
*/
PImage loadImage(std::string filename);
PImage loadImage(std::string filename, std::string extension);

/*
Name
noTint()
Examples
example pic
PImage img;
img = loadImage("laDefense.jpg");
tint(0, 153, 204);  // Tint blue
image(img, 0, 0);
noTint();  // Disable tint
image(img, 50, 0);
Description    Removes the current fill value for displaying images and reverts to displaying images with their original hues.
Syntax
noTint()
Returns    void
Related    tint()
image()
*/
void noTint();

/*
Name
requestImage()
Examples
PImage bigImage;

void setup() {
    bigImage = requestImage("something.jpg");
}

void draw() {
    if (bigImage.width == 0) {
        // Image is not yet loaded
    } else if (bigImage.width == -1) {
        // This means an error occurred during image loading
    } else {
        // Image is ready to go, draw it
        image(bigImage, 0, 0);
    }
}
Description    This function loads images on a separate thread so that your sketch doesn't freeze while images load during setup(). While the image is loading, its width and height will be 0. If an error occurs while loading the image, its width and height will be set to -1. You'll know when the image has loaded properly because its width and height will be greater than 0. Asynchronous image loading (particularly when downloading from a server) can dramatically improve performance.

The extension parameter is used to determine the image type in cases where the image filename does not end with a proper extension. Specify the extension as the second parameter to requestImage().
Syntax
requestImage(filename)
requestImage(filename, extension)
Parameters
filename    String: name of the file to load, can be .gif, .jpg, .tga, or a handful of other image types depending on your platform
extension    String: the type of image to load, for example "png", "gif", "jpg"
Returns    PImage
Related    PImage
loadImage()
*/
PImage requestImage(std::string filename);
PImage requestImage(std::string filename, std::string extension);

/*
Name
tint()
Examples
example pic
PImage img;
img = loadImage("laDefense.jpg");
image(img, 0, 0);
tint(0, 153, 204);  // Tint blue
image(img, 50, 0);
example pic
PImage img;
img = loadImage("laDefense.jpg");
image(img, 0, 0);
tint(0, 153, 204, 126);  // Tint blue and set transparency
image(img, 50, 0);
example pic
PImage img;
img = loadImage("laDefense.jpg");
image(img, 0, 0);
tint(255, 126);  // Apply transparency without changing color
image(img, 50, 0);
Description    Sets the fill value for displaying images. Images can be tinted to specified colors or made transparent by including an alpha value.

To apply transparency to an image without affecting its color, use white as the tint color and specify an alpha value. For instance, tint(255, 128) will make an image 50% transparent (assuming the default alpha range of 0-255, which can be changed with colorMode()).

When using hexadecimal notation to specify a color, use "#" or "0x" before the values (e.g., #CCFFAA or 0xFFCCFFAA). The # syntax uses six digits to specify a color (just as colors are typically specified in HTML and CSS). When using the hexadecimal notation starting with "0x", the hexadecimal value must be specified with eight characters; the first two characters define the alpha component, and the remainder define the red, green, and blue components.

The value for the gray parameter must be less than or equal to the current maximum value as specified by colorMode(). The default maximum value is 255.

The tint() function is also used to control the coloring of textures in 3D.
Syntax
Parameters
rgb    int: color value in hexadecimal notation
alpha    float: opacity of the image
gray    float: specifies a value between white and black
v1    float: red or hue value (depending on current color mode)
v2    float: green or saturation value (depending on current color mode)
v3    float: blue or brightness value (depending on current color mode)
Returns    void
Related    noTint()
image()
*/
void tint(colorType rgb);
void tint(colorType rgb, float alpha);
void tint(float gray);
void tint(float gray, float alpha);
void tint(float v1, float v2, float v3);
void tint(float v1, float v2, float v3, float alpha);


//Textures
/*
Name
texture()
Examples
example pic
size(100, 100, P3D);
noStroke();
PImage img = loadImage("laDefense.jpg");
beginShape();
texture(img);
vertex(10, 20, 0, 0);
vertex(80, 5, 100, 0);
vertex(95, 90, 100, 100);
vertex(40, 95, 0, 100);
endShape();
Description    Sets a texture to be applied to vertex points. The texture() function must be called between beginShape() and endShape() and before any calls to vertex(). This function only works with the P2D and P3D renderers.

When textures are in use, the fill color is ignored. Instead, use tint() to specify the color of the texture as it is applied to the shape.
Syntax
texture(image)
Parameters
image    PImage: reference to a PImage object
Returns    void
Related    textureMode()
textureWrap()
beginShape()
endShape()
vertex()
*/
void texture(PImage image);

/*
Name
textureMode()
Examples
example pic
size(100, 100, P3D);
noStroke();
PImage img = loadImage("laDefense.jpg");
textureMode(IMAGE);
beginShape();
texture(img);
vertex(10, 20, 0, 0);
vertex(80, 5, 100, 0);
vertex(95, 90, 100, 100);
vertex(40, 95, 0, 100);
endShape();
example pic
size(100, 100, P3D);
noStroke();
PImage img = loadImage("laDefense.jpg");
textureMode(NORMAL);
beginShape();
texture(img);
vertex(10, 20, 0, 0);
vertex(80, 5, 1, 0);
vertex(95, 90, 1, 1);
vertex(40, 95, 0, 1);
endShape();
Description    Sets the coordinate space for texture mapping. The default mode is IMAGE, which refers to the actual coordinates of the image. NORMAL refers to a normalized space of values ranging from 0 to 1. This function only works with the P2D and P3D renderers.

With IMAGE, if an image is 100 x 200 pixels, mapping the image onto the entire size of a quad would require the points (0,0) (100, 0) (100,200) (0,200). The same mapping in NORMAL is (0,0) (1,0) (1,1) (0,1).
Syntax
textureMode(mode)
Parameters
mode    int: either IMAGE or NORMAL
Returns    void
Related    texture()
textureWrap()
*/
void textureMode(_penum mode);

/*
Name
textureWrap()
Examples
PImage img;

void setup() {
    size(300, 300, P2D);
    img = loadImage("berlin-1.jpg");
    textureMode(NORMAL);
}

void draw() {
    background(0);
    translate(width/2, height/2);
    rotate(map(mouseX, 0, width, -PI, PI));
    if (mousePressed) {
        textureWrap(REPEAT);
    } else {
        textureWrap(CLAMP);
    }
    beginShape();
    texture(img);
    vertex(-100, -100, 0, 0);
    vertex(100, -100, 2, 0);
    vertex(100, 100, 2, 2);
    vertex(-100, 100, 0, 2);
    endShape();
}
Description    Defines if textures repeat or draw once within a texture map. The two parameters are CLAMP (the default behavior) and REPEAT. This function only works with the P2D and P3D renderers.
Syntax
textureWrap(wrap)
Parameters
wrap    int: Either CLAMP (default) or REPEAT
Returns    void
Related    texture()
textureMode()
*/
void textureWrap(_penum wrap);

//Pixels
/*
Name
blend()
Examples
example pic
background(loadImage("rockies.jpg"));
PImage img = loadImage("bricks.jpg");
image(img, 0, 0);
blend(img, 0, 0, 33, 100, 67, 0, 33, 100, ADD);
example pic
background(loadImage("rockies.jpg"));
PImage img = loadImage("bricks.jpg");
image(img, 0, 0);
blend(img, 0, 0, 33, 100, 67, 0, 33, 100, SUBTRACT);
example pic
background(loadImage("rockies.jpg"));
PImage img = loadImage("bricks.jpg");
image(img, 0, 0);
blend(img, 0, 0, 33, 100, 67, 0, 33, 100, DARKEST);
example pic
background(loadImage("rockies.jpg"));
PImage img = loadImage("bricks.jpg");
image(img, 0, 0);
blend(img, 0, 0, 33, 100, 67, 0, 33, 100, LIGHTEST);
Description    Blends a region of pixels from one image into another (or in itself again) with full alpha channel support. There is a choice of the following modes to blend the source pixels (A) with the ones of pixels in the destination image (B):

BLEND - linear interpolation of colours: C = A*factor + B

ADD - additive blending with white clip: C = min(A*factor + B, 255)

SUBTRACT - subtractive blending with black clip: C = max(B - A*factor, 0)

DARKEST - only the darkest colour succeeds: C = min(A*factor, B)

LIGHTEST - only the lightest colour succeeds: C = max(A*factor, B)

DIFFERENCE - subtract colors from underlying image.

EXCLUSION - similar to DIFFERENCE, but less extreme.

MULTIPLY - Multiply the colors, result will always be darker.

SCREEN - Opposite multiply, uses inverse values of the colors.

OVERLAY - A mix of MULTIPLY and SCREEN. Multiplies dark values, and screens light values.

HARD_LIGHT - SCREEN when greater than 50% gray, MULTIPLY when lower.

SOFT_LIGHT - Mix of DARKEST and LIGHTEST. Works like OVERLAY, but not as harsh.

DODGE - Lightens light tones and increases contrast, ignores darks. Called "Color Dodge" in Illustrator and Photoshop.

BURN - Darker areas are applied, increasing contrast, ignores lights. Called "Color Burn" in Illustrator and Photoshop.

All modes use the alpha information (highest byte) of source image pixels as the blending factor. If the source and destination regions are different sizes, the image will be automatically resized to match the destination size. If the src parameter is not used, the display window is used as the source image.

As of release 0149, this function ignores imageMode().
Syntax
blend(sx, sy, sw, sh, dx, dy, dw, dh, mode)
blend(src, sx, sy, sw, sh, dx, dy, dw, dh, mode)
Parameters
src    PImage: an image variable referring to the source image
sx    int: X coordinate of the source's upper left corner
sy    int: Y coordinate of the source's upper left corner
sw    int: source image width
sh    int: source image height
dx    int: X coordinate of the destinations's upper left corner
dy    int: Y coordinate of the destinations's upper left corner
dw    int: destination image width
dh    int: destination image height
mode    int: Either BLEND, ADD, SUBTRACT, LIGHTEST, DARKEST, DIFFERENCE, EXCLUSION, MULTIPLY, SCREEN, OVERLAY, HARD_LIGHT, SOFT_LIGHT, DODGE, BURN
Returns    void
Related    alpha()
copy()
*/
void blend(int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, _penum mode);
void blend(PImage src, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh, _penum mode);

/*
Name
copy()
Examples
example pic
PImage img = loadImage("eames.jpg");
image(img, 0, 0, width, height);
copy(7, 22, 10, 10, 35, 25, 50, 50);
stroke(255);
noFill();
// Rectangle shows area being copied
rect(7, 22, 10, 10);
Description    Copies a region of pixels from the display window to another area of the display window and copies a region of pixels from an image used as the srcImg parameter into the display window. If the source and destination regions aren't the same size, it will automatically resize the source pixels to fit the specified target region. No alpha information is used in the process, however if the source image has an alpha channel set, it will be copied as well.

As of release 0149, this function ignores imageMode().
Syntax
copy()
copy(sx, sy, sw, sh, dx, dy, dw, dh)
copy(src, sx, sy, sw, sh, dx, dy, dw, dh)
Parameters
sx    int: X coordinate of the source's upper left corner
sy    int: Y coordinate of the source's upper left corner
sw    int: source image width
sh    int: source image height
dx    int: X coordinate of the destination's upper left corner
dy    int: Y coordinate of the destination's upper left corner
dw    int: destination image width
dh    int: destination image height
src    PImage: an image variable referring to the source image.
Returns    void or PImage
Related    alpha()
blend()
*/
PImage copy();
void copy(int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh);
void copy(PImage src, int sx, int sy, int sw, int sh, int dx, int dy, int dw, int dh);

/*
Name
filter()
Examples
example pic
PImage img;
img = loadImage("apples.jpg");
image(img, 0, 0);
filter(THRESHOLD);
example pic
PImage img;
img = loadImage("apples.jpg");
image(img, 0, 0);
filter(GRAY);
example pic
PImage img;
img = loadImage("apples.jpg");
image(img, 0, 0);
filter(INVERT);
example pic
PImage img;
img = loadImage("apples.jpg");
image(img, 0, 0);
filter(POSTERIZE, 4);
example pic
PImage img;
img = loadImage("apples.jpg");
image(img, 0, 0);
filter(BLUR, 6);
example pic
PImage img;
img = loadImage("apples.jpg");
image(img, 0, 0);
filter(ERODE);
example pic
PImage img;
img = loadImage("apples.jpg");
image(img, 0, 0);
filter(DILATE);
example pic
PShader blur;
PImage img;

void setup() {
    size(100, 100, P2D);
    blur = loadShader("blur.glsl");
    img = loadImage("apples.jpg");
    image(img, 0, 0);
}

void draw() {
    filter(blur); // Blurs more each time through draw()
}
Description    Filters the display window using a preset filter or with a custom shader. Using a shader with filter() is much faster than without. Shaders require the P2D or P3D renderer in size().

The presets options are:

THRESHOLD
Converts the image to black and white pixels depending if they are above or below the threshold defined by the level parameter. The parameter must be between 0.0 (black) and 1.0 (white). If no level is specified, 0.5 is used.

GRAY
Converts any colors in the image to grayscale equivalents. No parameter is used.

OPAQUE
Sets the alpha channel to entirely opaque. No parameter is used.

INVERT
Sets each pixel to its inverse value. No parameter is used.

POSTERIZE
Limits each channel of the image to the number of colors specified as the parameter. The parameter can be set to values between 2 and 255, but results are most noticeable in the lower ranges.

BLUR
Executes a Guassian blur with the level parameter specifying the extent of the blurring. If no parameter is used, the blur is equivalent to Guassian blur of radius 1. Larger values increase the blur.

ERODE
Reduces the light areas. No parameter is used.

DILATE
Increases the light areas. No parameter is used.
Syntax
filter(shader)
filter(kind)
filter(kind, param)
Parameters
shader    PShader: the fragment shader to apply
kind    int: Either THRESHOLD, GRAY, OPAQUE, INVERT, POSTERIZE, BLUR, ERODE, or DILATE
param    float: unique for each, see above
Returns    void
*/
void filter(PShader shader);
void filter(_penum kind);
void filter(_penum kind, float param);

/*
Name
get()
Examples
example pic
PImage myImage = loadImage("apples.jpg");
image(myImage, 0, 0);
PImage c = get();
image(c, width/2, 0);
example pic
PImage myImage = loadImage("apples.jpg");
image(myImage, 0, 0);
color c = get(25, 25);
fill(c);
noStroke();
rect(25, 25, 50, 50);
Description    Reads the color of any pixel or grabs a section of an image. If no parameters are specified, the entire image is returned. Use the x and y parameters to get the value of one pixel. Get a section of the display window by specifying additional w and h parameters. When getting an image, the x and y parameters define the coordinates for the upper-left corner of the image, regardless of the current imageMode().

If the pixel requested is outside of the image window, black is returned. The numbers returned are scaled according to the current color ranges, but only RGB values are returned by this function. For example, even though you may have drawn a shape with colorMode(HSB), the numbers returned will be in RGB format.

If a width and a height are specified, get(x, y, w, h) returns a PImage corresponding to the part of the original PImage where the top left pixel is at the (x, y) position with a width of w a height of h.

Getting the color of a single pixel with get(x, y) is easy, but not as fast as grabbing the data directly from pixels[]. The equivalent statement to get(x, y) using pixels[] is pixels[y*width+x]. See the reference for pixels[] for more information.
Syntax
get(x, y)
get(x, y, w, h)
get()
Parameters
x    int: x-coordinate of the pixel
y    int: y-coordinate of the pixel
w    int: width of pixel rectangle to get
h    int: height of pixel rectangle to get
Returns    int or PImage
Related    set()
pixels[]
copy()
*/
int get(int x, int y);
PImage get(int x, int y, int w, int h);
PImage get();

/*
Name
loadPixels()
Examples
example pic
int halfImage = width*height/2;
PImage myImage = loadImage("apples.jpg");
image(myImage, 0, 0);

loadPixels();
for (int i = 0; i < halfImage; i++) {
    pixels[i+halfImage] = pixels[i];
}
updatePixels();
Description    Loads a snapshot of the current display window into the pixels[] array. This function must always be called before reading from or writing to pixels[]. Subsequent changes to the display window will not be reflected in pixels until loadPixels() is called again.

Certain renderers may or may not seem to require loadPixels() or updatePixels(). However, the rule is that any time you want to manipulate the pixels[] array, you must have previously called loadPixels(), and after changes have been made, call updatePixels(). Even if the renderer may not seem to use this function in the current Processing release, this will always be subject to change.
Syntax
loadPixels()
Returns    void
Related    pixels[]
updatePixels()
*/
void loadPixels();

/*
Name
pixels[]
Examples
example pic
color pink = color(255, 102, 204);
loadPixels();
for (int i = 0; i < (width*height/2)-width/2; i++) {
    pixels[i] = pink;
}
updatePixels();
Description    Array containing the values for all the pixels in the display window. These values are of the color datatype. This array is the size of the display window. For example, if the image is 100x100 pixels, there will be 10000 values and if the window is 200x300 pixels, there will be 60000 values.

Before accessing this array, the data must loaded with the loadPixels() function. Failure to do so may result in a NullPointerException. Subsequent changes to the display window will not be reflected in pixels until loadPixels() is called again. After pixels has been modified, the updatePixels() function must be run to update the content of the display window.
Related    loadPixels()
updatePixels()
get()
set()
PImage
*/
extern std::vector<int> $pixels;

/*
Name
set()
Examples
example pic
color black = color(0);
set(30, 20, black);
set(85, 20, black);
set(85, 75, black);
set(30, 75, black);
example pic
for (int i = 30; i < width-15; i++) {
    for (int j = 20; j < height-25; j++) {
        color c = color(204-j, 153-i, 0);
        set(i, j, c);
    }
}
example pic
size(100, 100);
PImage myImage = loadImage("apples.jpg");
set(0, 0, myImage);
line(0, 0, width, height);
line(0, height, width, 0);
Description    Changes the color of any pixel, or writes an image directly to the display window.

The x and y parameters specify the pixel to change and the c parameter specifies the color value. The c parameter is interpreted according to the current color mode. (The default color mode is RGB values from 0 to 255.) When setting an image, the x and y parameters define the coordinates for the upper-left corner of the image, regardless of the current imageMode().

Setting the color of a single pixel with set(x, y) is easy, but not as fast as putting the data directly into pixels[]. The equivalent statement to set(x, y, #000000) using pixels[] is pixels[y*width+x] = #000000. See the reference for pixels[] for more information.
Syntax
set(x, y, c)
set(x, y, img)
Parameters
x    int: x-coordinate of the pixel
y    int: y-coordinate of the pixel
c    int: any value of the color datatype
img    PImage: image to copy into the original image
Returns    void
Related    get()
pixels[]
copy()
*/
void set(int x, int y, int c);
void set(int x, int y, PImage img);

/*
Name
updatePixels()
Examples
example pic
PImage img = loadImage("rockies.jpg");
image(img, 0, 0);
int halfImage = img.width * img.height/2;
loadPixels();
for (int i = 0; i < halfImage; i++) {
    pixels[i+halfImage] = pixels[i];
}
updatePixels();
Description    Updates the display window with the data in the pixels[] array. Use in conjunction with loadPixels(). If you're only reading pixels from the array, there's no need to call updatePixels() — updating is only necessary to apply changes.

Certain renderers may or may not seem to require loadPixels() or updatePixels(). However, the rule is that any time you want to manipulate the pixels[] array, you must first call loadPixels(), and after changes have been made, call updatePixels(). Even if the renderer may not seem to use this function in the current Processing release, this will always be subject to change.

Currently, while none of the renderers use the additional parameters to updatePixels(), this may be implemented in the future.
Syntax
updatePixels()
Returns    void
Related    loadPixels()
pixels[]
*/
void updatePixels();

//Rendering
/*
Name
blendMode()
Examples
size(100, 100);
background(0);
blendMode(ADD);
stroke(102);
strokeWeight(30);
line(25, 25, 75, 75);
line(75, 25, 25, 75);
size(100, 100, P2D);
blendMode(MULTIPLY);
stroke(51);
strokeWeight(30);
line(25, 25, 75, 75);
line(75, 25, 25, 75);
Description    Blends the pixels in the display window according to a defined mode. There is a choice of the following modes to blend the source pixels (A) with the ones of pixels already in the display window (B). A pixel's final color is the result of applying one of the above blend modes with each channel of (A) and (B) independently. For example, red is compared with red, green with green, and blue with blue.

BLEND - linear interpolation of colours: C = A*factor + B. This is the default blending mode.

ADD - additive blending with white clip: C = min(A*factor + B, 255)

SUBTRACT - subtractive blending with black clip: C = max(B - A*factor, 0)

DARKEST - only the darkest colour succeeds: C = min(A*factor, B)

LIGHTEST - only the lightest colour succeeds: C = max(A*factor, B)

DIFFERENCE - subtract colors from underlying image.

EXCLUSION - similar to DIFFERENCE, but less extreme.

MULTIPLY - multiply the colors, result will always be darker.

SCREEN - opposite multiply, uses inverse values of the colors.

REPLACE - the pixels entirely replace the others and don't utilize alpha (transparency) values

We recommend using blendMode() and not the previous blend() function. However, unlike blend(), the blendMode() function does not support the following: HARD_LIGHT, SOFT_LIGHT, OVERLAY, DODGE, BURN. On older hardware, the LIGHTEST, DARKEST, and DIFFERENCE modes might not be available as well.
Syntax
blendMode(mode)
Parameters
mode    int: the blending mode to use
Returns    void
*/
void blendMode(_penum mode);

/*
Name
clip()
Examples
void setup() {
    size(200, 200);
    imageMode(CENTER);
}

void draw() {
    background(204);
    if (mousePressed) {
        clip(mouseX, mouseY, 100, 100);
    } else {
        noClip();
    }
    line(0, 0, width, height);
    line(0, height, width, 0);
}
Description    Limits the rendering to the boundaries of a rectangle defined by the parameters. The boundaries are drawn based on the state of the imageMode() fuction, either CORNER, CORNERS, or CENTER.
Syntax
clip(a, b, c, d)
Parameters
a    float: x-coordinate of the rectangle, by default
b    float: y-coordinate of the rectangle, by default
c    float: width of the rectangle, by default
d    float: height of the rectangle, by default
Returns    void
*/
void clip(float a, float b, float c, float d);

/*
Name
PGraphics
Examples
PGraphics pg;

void setup() {
    size(100, 100);
    pg = createGraphics(40, 40);
}

void draw() {
    pg.beginDraw();
    pg.background(100);
    pg.stroke(255);
    pg.line(20, 20, mouseX, mouseY);
    pg.endDraw();
    image(pg, 9, 30);
    image(pg, 51, 30);
}
Description    Main graphics and rendering context, as well as the base API implementation for processing "core". Use this class if you need to draw into an off-screen graphics buffer. A PGraphics object can be constructed with the createGraphics() function. The beginDraw() and endDraw() methods (see above example) are necessary to set up the buffer and to finalize it. The fields and methods for this class are extensive. For a complete list, visit the developer's reference.

To create a new graphics context, use the createGraphics() function. Do not use the syntax new PGraphics().
Methods
beginDraw()    Sets the default properties for a PGraphics object
endDraw()    Finalizes the rendering of a PGraphics object
Constructor
PGraphics()
Related    createGraphics()
*/
class PGraphics {
public:
    //Methods
    /*
    Class
    PGraphics

    Name
    beginDraw()
    Examples
    PGraphics pg;

    void setup() {
        size(100, 100);
        pg = createGraphics(80, 80, P2D);
        pg.beginDraw();
        pg.background(102);
        pg.stroke(255);
        pg.line(20, 20, 80, 80);
        pg.endDraw();
        noLoop();
    }

    void draw() {
        image(pg, 10, 10);
    }

    Description    Sets the default properties for a PGraphics object. It should be called before anything is drawn into the object.
    Syntax
        graphics.beginDraw()
    Parameters
        graphics    PGraphics: any object of the type PGraphics
    Returns    void
    */
    void beginDraw();    //Sets the default properties for a PGraphics object

    /*
    Class
    PGraphics

    Name
    endDraw()
    Examples
    PGraphics pg;

    void setup() {
        size(100, 100);
        pg = createGraphics(80, 80, P2D);
        pg.beginDraw();
        pg.background(102);
        pg.stroke(255);
        pg.line(20, 20, 80, 80);
        pg.endDraw();
        noLoop();
    }

    void draw() {
        image(pg, 10, 10);
    }

    Description    Finalizes the rendering of a PGraphics object so that it can be shown on screen.
    Syntax
    graphics.endDraw()
    Parameters
    graphics    PGraphics: any object of the type PGraphics
    Returns    void
    */
    void endDraw();    //Finalizes the rendering of a PGraphics object
};

/*
Name
createGraphics()
Examples
PGraphics pg;

void setup() {
    size(200, 200);
    pg = createGraphics(100, 100);
}

void draw() {
    pg.beginDraw();
    pg.background(102);
    pg.stroke(255);
    pg.line(pg.width*0.5, pg.height*0.5, mouseX, mouseY);
    pg.endDraw();
    image(pg, 50, 50);
}
Description    Creates and returns a new PGraphics object. Use this class if you need to draw into an off-screen graphics buffer. The first two parameters define the width and height in pixels. The third, optional parameter specifies the renderer. It can be defined as P2D, P3D, PDF, or SVG. If the third parameter isn't used, the default renderer is set. The PDF and SVG renderers require the filename parameter.

It's important to consider the renderer used with createGraphics() in relation to the main renderer specified in size(). For example, it's only possible to use P2D or P3D with createGraphics() when one of them is defined in size(). Unlike Processing 1.0, P2D and P3D use OpenGL for drawing, and when using an OpenGL renderer it's necessary for the main drawing surface to be OpenGL-based. If P2D or P3D are used as the renderer in size(), then any of the options can be used with createGraphics(). If the default renderer is used in size(), then only the default, PDF, or SVG can be used with createGraphics().

It's important to call any drawing functions between beginDraw() and endDraw() statements. This is also true for any functions that affect drawing, such as smooth() or colorMode().

The createGraphics() function should almost never be used inside draw() because of the memory and time needed to set up the graphics. One-time or occasional use during draw() are acceptable, but code that calls createGraphics() at 60 frames per second will run out of memory or freeze your sketch.

Unlike the main drawing surface which is completely opaque, surfaces created with createGraphics() can have transparency. This makes it possible to draw into a graphics and maintain the alpha channel. By using save() to write a PNG or TGA file, the transparency of the graphics object will be honored.
Syntax
createGraphics(w, h)
createGraphics(w, h, renderer)
createGraphics(w, h, renderer, path)
Parameters
w    int: width in pixels
h    int: height in pixels
renderer    String: Either P2D, P3D, or PDF
path    String: the name of the file (can be an absolute or relative path)
Returns    PGraphics
*/
PGraphics createGraphics(int w, int h);
PGraphics createGraphics(int w, int h, _penum renderer);
PGraphics createGraphics(int w, int h, _penum renderer, std::string path);

/*
Name
noClip()
Examples
void setup() {
    size(200, 200);
    imageMode(CENTER);
}

void draw() {
    background(204);
    if (mousePressed) {
        clip(mouseX, mouseY, 100, 100);
    } else {
        noClip();
    }
    line(0, 0, width, height);
    line(0, height, width, 0);
}
Description    Disables the clipping previously started by the clip() function.
Syntax
noClip()
Returns    void
*/
void noClip();


//Shaders
/*
Name
loadShader()
Examples
PShader blur;

void setup() {
    size(640, 360, P2D);
    // Shaders files must be in the "data" folder to load correctly
    blur = loadShader("blur.glsl");
    stroke(0, 102, 153);
    rectMode(CENTER);
}

void draw() {
    filter(blur);
    rect(mouseX-75, mouseY, 150, 150);
    ellipse(mouseX+75, mouseY, 150, 150);
}
Description    Loads a shader into the PShader object. The shader file must be loaded in the sketch's "data" folder/directory to load correctly. Shaders are compatible with the P2D and P3D renderers, but not with the default renderer.

Alternatively, the file maybe be loaded from anywhere on the local computer using an absolute path (something that starts with / on Unix and Linux, or a drive letter on Windows), or the filename parameter can be a URL for a file found on a network.

If the file is not available or an error occurs, null will be returned and an error message will be printed to the console. The error message does not halt the program, however the null value may cause a NullPointerException if your code does not check whether the value returned is null.
Syntax
loadShader(fragFilename)
loadShader(fragFilename, vertFilename)
Parameters
fragFilename    String: name of fragment shader file
vertFilename    String: name of vertex shader file
Returns    PShader
*/
PShader loadShader(std::string fragFilename);
PShader loadShader(std::string fragFilename, std::string vertFilename);

/*
Name
resetShader()
Examples
PShader edges;
PImage img;

void setup() {
    size(640, 360, P2D);
    img = loadImage("leaves.jpg");
    edges = loadShader("edges.glsl");
}

void draw() {
    shader(edges);
    image(img, 0, 0);
    resetShader();
    image(img, width/2, 0);
}
Description    Restores the default shaders. Code that runs after resetShader() will not be affected by previously defined shaders.
Syntax
resetShader()
resetShader(kind)
Parameters
kind    int: type of shader, either POINTS, LINES, or TRIANGLES
Returns    void
*/
void resetShader();
void resetShader(_penum kind);

/*
Name
shader()
Examples
PShader edges;
PImage img;

void setup() {
    size(640, 360, P2D);
    img = loadImage("leaves.jpg");
    edges = loadShader("edges.glsl");
}

void draw() {
    shader(edges);
    image(img, 0, 0);
}
Description    Applies the shader specified by the parameters. It's compatible with the P2D and P3D renderers, but not with the default renderer.
Syntax
shader(shader)
shader(shader, kind)
Parameters
shader    PShader: name of shader file
kind    int: type of shader, either POINTS, LINES, or TRIANGLES
Returns    void
*/
void shader(PShader shader);
void shader(PShader shader, _penum kind);

//Typography
/*
Name
PFont
Examples
example pic
PFont font;
// The font must be located in the sketch's
// "data" directory to load successfully
font = createFont("LetterGothicStd.ttf", 32);
textFont(font);
text("word", 10, 50);
Description    PFont is the font class for Processing. To create a font to use with Processing, select "Create Font..." from the Tools menu. This will create a font in the format Processing requires and also adds it to the current sketch's data directory. Processing displays fonts using the .vlw font format, which uses images for each letter, rather than defining them through vector data. The loadFont() function constructs a new font and textFont() makes a font active. The list() method creates a list of the fonts installed on the computer, which is useful information to use with the createFont() function for dynamically converting fonts into a format to use with Processing.

To create a new font dynamically, use the createFont() function. Do not use the syntax new PFont().
Methods
list()    Gets a list of the fonts installed on the system
Related    loadFont()
createFont()
*/
class PFont {
public:
    /*
    Class
    PFont

    Name
    list()
    Examples
    size(200, 200);
    String[] fontList = PFont.list();
    printArray(fontList);
    Description    Gets a list of the fonts installed on the system. The data is returned as a String array. This list provides the names of each font for input into createFont(), which allows Processing to dynamically format fonts.
    Syntax
        .list()
    Returns    String[]
    */
    std::vector<std::string> list();    //Gets a list of the fonts installed on the system
};

//Loading & Displaying
/*
Name
createFont()
Examples
PFont myFont;

void setup() {
    size(200, 200);
    // Uncomment the following two lines to see the available fonts
    //String[] fontList = PFont.list();
    //printArray(fontList);
    myFont = createFont("Georgia", 32);
    textFont(myFont);
    textAlign(CENTER, CENTER);
    text("!@#$%", width/2, height/2);
}

Description    Dynamically converts a font to the format used by Processing from a .ttf or .otf file inside the sketch's "data" folder or a font that's installed elsewhere on the computer. If you want to use a font installed on your computer, use the PFont.list() method to first determine the names for the fonts recognized by the computer and are compatible with this function. Not all fonts can be used and some might work with one operating system and not others. When sharing a sketch with other people or posting it on the web, you may need to include a .ttf or .otf version of your font in the data directory of the sketch because other people might not have the font installed on their computer. Only fonts that can legally be distributed should be included with a sketch.

The size parameter states the font size you want to generate. The smooth parameter specifies if the font should be antialiased or not. The charset parameter is an array of chars that specifies the characters to generate.

This function allows Processing to work with the font natively in the default renderer, so the letters are defined by vector geometry and are rendered quickly. In the P2D and P3D renderers, the function sets the project to render the font as a series of small textures. For instance, when using the default renderer, the actual native version of the font will be employed by the sketch, improving drawing quality and performance. With the P2D and P3D renderers, the bitmapped version will be used to improve speed and appearance, but the results are poor when exporting if the sketch does not include the .otf or .ttf file, and the requested font is not available on the machine running the sketch.
Syntax
createFont(name, size)
createFont(name, size, smooth)
createFont(name, size, smooth, charset)
Parameters
name    String: name of the font to load
size    float: point size of the font
smooth    boolean: true for an antialiased font, false for aliased
charset    char[]: array containing characters to be generated
Returns    PFont
Related    PFont
textFont()
text()
loadFont()
*/
void createFont(std::string name, float size);
void createFont(std::string name, float size, bool smooth);
void createFont(std::string name, float size, bool smooth, std::vector<char> & charse);

/*
Name
loadFont()
Examples
example pic
PFont font;
// The font must be located in the sketch's
// "data" directory to load successfully
font = loadFont("LetterGothicStd-32.vlw");
textFont(font, 32);
text("word", 10, 50);
Description    Loads a .vlw formatted font into a PFont object. Create a .vlw font by selecting "Create Font..." from the Tools menu. This tool creates a texture for each alphanumeric character and then adds them as a .vlw file to the current sketch's data folder. Because the letters are defined as textures (and not vector data) the size at which the fonts are created must be considered in relation to the size at which they are drawn. For example, load a 32pt font if the sketch displays the font at 32 pixels or smaller. Conversely, if a 12pt font is loaded and displayed at 48pts, the letters will be distorted because the program will be stretching a small graphic to a large size.

Like loadImage() and other functions that load data, the loadFont() function should not be used inside draw(), because it will slow down the sketch considerably, as the font will be re-loaded from the disk (or network) on each frame. It's recommended to load files inside setup()

To load correctly, fonts must be located in the "data" folder of the current sketch. Alternatively, the file maybe be loaded from anywhere on the local computer using an absolute path (something that starts with / on Unix and Linux, or a drive letter on Windows), or the filename parameter can be a URL for a file found on a network.

If the file is not available or an error occurs, null will be returned and an error message will be printed to the console. The error message does not halt the program, however the null value may cause a NullPointerException if your code does not check whether the value returned is null.

Use createFont() (instead of loadFont()) to enable vector data to be used with the default renderer setting. This can be helpful when many font sizes are needed, or when using any renderer based on the default renderer, such as the PDF library.
Syntax
loadFont(filename)
Parameters
filename    String: name of the font to load
Returns    PFont
Related    PFont
textFont()
createFont()
*/
PFont loadFont(std::string filename);

/*
Name
text()
Examples
example pic
textSize(32);
text("word", 10, 30);
fill(0, 102, 153);
text("word", 10, 60);
fill(0, 102, 153, 51);
text("word", 10, 90);
example pic
size(100, 100, P3D);
textSize(32);
fill(0, 102, 153, 204);
text("word", 12, 45, -30);  // Specify a z-axis value
text("word", 12, 60);  // Default depth, no z-value specified
example pic
String s = "The quick brown fox jumped over the lazy dog.";
fill(50);
text(s, 10, 10, 70, 80);  // Text wraps within text box
Description    Draws text to the screen. Displays the information specified in the first parameter on the screen in the position specified by the additional parameters. A default font will be used unless a font is set with the textFont() function and a default size will be used unless a font is set with textSize(). Change the color of the text with the fill() function. The text displays in relation to the textAlign() function, which gives the option to draw to the left, right, and center of the coordinates.

The x2 and y2 parameters define a rectangular area to display within and may only be used with string data. When these parameters are specified, they are interpreted based on the current rectMode() setting. Text that does not fit completely within the rectangle specified will not be drawn to the screen.

Note that Processing now lets you call text() without first specifying a PFont with textFont(). In that case, a generic sans-serif font will be used instead. (See the third example above.)
Syntax
text(c, x, y)
text(c, x, y, z)
text(str, x, y)
text(chars, start, stop, x, y)
text(str, x, y, z)
text(chars, start, stop, x, y, z)
text(str, x1, y1, x2, y2)
text(num, x, y)
text(num, x, y, z)
Parameters
c    char: the alphanumeric character to be displayed
x    float: x-coordinate of text
y    float: y-coordinate of text
z    float: z-coordinate of text
chars    char[]: the alphanumberic symbols to be displayed
start    int: array index at which to start writing characters
stop    int: array index at which to stop writing characters
x1    float: by default, the x-coordinate of text, see rectMode() for more info
y1    float: by default, the y-coordinate of text, see rectMode() for more info
x2    float: by default, the width of the text box, see rectMode() for more info
y2    float: by default, the height of the text box, see rectMode() for more info
num    int, or float: the numeric value to be displayed
Returns    void
Related    textAlign()
textFont()
textMode()
textSize()
textLeading()
textWidth()
textAscent()
textDescent()
rectMode()
fill()
String
*/
void text(char c, float x, float y);
void text(char c, float x, float y, float z);
void text(std::string str, float x, float y);
void text(std::string chars, int start, int stop, float x, float y);
void text(std::string str, float x, float y, float z);
void text(std::string chars, int start, int stop, float x, float y, float z);
void text(std::string str, float x1, float y1, float x2, float y2);
void text(int num, float x, float y);
void text(int num, float x, float y, float z);
void text(float num, float x, float y);
void text(float num, float x, float y, float z);

/*
Name
textFont()
Examples
example pic
PFont mono;
// The font "andalemo.ttf" must be located in the
// current sketch's "data" directory to load successfully
mono = loadFont("andalemo.ttf", 32);
background(0);
textFont(mono);
text("word", 12, 60);
Description    Sets the current font that will be drawn with the text() function. Fonts must be created for Processing with createFont() or loaded with loadFont() before they can be used. The font set through textFont() will be used in all subsequent calls to the text() function. If no size parameter is specified, the font size defaults to the original size (the size in which it was created with the "Create Font..." tool) overriding any previous calls to textFont() or textSize().

When fonts are rendered as an image texture (as is the case with the P2D and P3D renderers as well as with loadFont() and vlw files), you should create fonts at the sizes that will be used most commonly. Using textFont() without the size parameter will result in the cleanest type.

Syntax
textFont(which)
textFont(which, size)
Parameters
which    PFont: any variable of the type PFont
size    float: the size of the letters in units of pixels
Returns    void
Related    createFont()
loadFont()
PFont
text()
textSize()
*/
void textFont(PFont which);
void textFont(PFont which, float size);

//Attributes
/*
Name
textAlign()
Examples
example pic
background(0);
textSize(16);
textAlign(RIGHT);
text("ABCD", 50, 30);
textAlign(CENTER);
text("EFGH", 50, 50);
textAlign(LEFT);
text("IJKL", 50, 70);
example pic
background(0);
stroke(153);
textSize(11);
textAlign(CENTER, BOTTOM);
line(0, 30, width, 30);
text("CENTER,BOTTOM", 50, 30);
textAlign(CENTER, CENTER);
line(0, 50, width, 50);
text("CENTER,CENTER", 50, 50);
textAlign(CENTER, TOP);
line(0, 70, width, 70);
text("CENTER,TOP", 50, 70);
Description    Sets the current alignment for drawing text. The parameters LEFT, CENTER, and RIGHT set the display characteristics of the letters in relation to the values for the x and y parameters of the text() function.

An optional second parameter can be used to vertically align the text. BASELINE is the default, and the vertical alignment will be reset to BASELINE if the second parameter is not used. The TOP and CENTER parameters are straightforward. The BOTTOM parameter offsets the line based on the current textDescent(). For multiple lines, the final line will be aligned to the bottom, with the previous lines appearing above it.

When using text() with width and height parameters, BASELINE is ignored, and treated as TOP. (Otherwise, text would by default draw outside the box, since BASELINE is the default setting. BASELINE is not a useful drawing mode for text drawn in a rectangle.)

The vertical alignment is based on the value of textAscent(), which many fonts do not specify correctly. It may be necessary to use a hack and offset by a few pixels by hand so that the offset looks correct. To do this as less of a hack, use some percentage of textAscent() or textDescent() so that the hack works even if you change the size of the font.
Syntax
textAlign(alignX)
textAlign(alignX, alignY)
Parameters
alignX    int: horizontal alignment, either LEFT, CENTER, or RIGHT
alignY    int: vertical alignment, either TOP, BOTTOM, CENTER, or BASELINE
Returns    void
Related    loadFont()
PFont
text()
textSize()
textAscent()
textDescent()
*/
void textAlign(_penum alignX);
void textAlign(_penum alignX, _penum alignY);

/*
Name
textLeading()
Examples
example pic
// Text to display. The "\n" is a "new line" character
String lines = "L1\nL2\nL3";
textSize(12);
fill(0);  // Set fill to black

textLeading(10);  // Set leading to 10
text(lines, 10, 25);

textLeading(20);  // Set leading to 20
text(lines, 40, 25);

textLeading(30);  // Set leading to 30
text(lines, 70, 25);
Description    Sets the spacing between lines of text in units of pixels. This setting will be used in all subsequent calls to the text() function. Note, however, that the leading is reset by textSize(). For example, if the leading is set to 20 with textLeading(20), then if textSize(48) is run at a later point, the leading will be reset to the default for the text size of 48.
Syntax
textLeading(leading)
Parameters
leading    float: the size in pixels for spacing between lines
Returns    void
Related    loadFont()
text()
textFont()
textSize()
*/
void textLeading(float leading);

/*
Name
textMode()
Examples
import processing.pdf.*;

void setup() {
    size(500, 500, PDF, "TypeDemo.pdf");
    textMode(SHAPE);
    textSize(180);
}

void draw() {
    text("ABC", 75, 350);
    exit();  // Quit the program
}
Description    Sets the way text draws to the screen, either as texture maps or as vector geometry. The default textMode(MODEL), uses textures to render the fonts. The textMode(SHAPE) mode draws text using the glyph outlines of individual characters rather than as textures. This mode is only supported with the PDF and P3D renderer settings. With the PDF renderer, you must call textMode(SHAPE) before any other drawing occurs. If the outlines are not available, then textMode(SHAPE) will be ignored and textMode(MODEL) will be used instead.

The textMode(SHAPE) option in P3D can be combined with beginRaw() to write vector-accurate text to 2D and 3D output files, for instance DXF or PDF. The SHAPE mode is not currently optimized for P3D, so if recording shape data, use textMode(MODEL) until you're ready to capture the geometry with beginRaw().
Syntax
textMode(mode)
Parameters
mode    int: either MODEL or SHAPE
Returns    void
Related    loadFont()
text()
textFont()
beginRaw()
createFont()
*/
void textMode(_penum mode);

/*
Name
textSize()
Examples
example pic
background(0);
fill(255);
textSize(26);
text("WORD", 10, 50);
textSize(14);
text("WORD", 10, 70);
Description    Sets the current font size. This size will be used in all subsequent calls to the text() function. Font size is measured in units of pixels.
Syntax
textSize(size)
Parameters
size    float: the size of the letters in units of pixels
Returns    void
Related    loadFont()
text()
textFont()
*/
void textSize(float size);

/*
Name
textWidth()
Examples
example pic
textSize(28);

char c = 'T';
float cw = textWidth(c);
text(c, 0, 40);
line(cw, 0, cw, 50);

String s = "Tokyo";
float sw = textWidth(s);
text(s, 0, 85);
line(sw, 50, sw, 100);
Description    Calculates and returns the width of any character or text string.
Syntax
textWidth(c)
textWidth(str)
Parameters
c    char: the character to measure
str    String: the String of characters to measure
Returns    float
Related    loadFont()
text()
textFont()
textSize()
*/
float textWidth(char c);
float textWidth(std::string str);

//Metrics
/*
Name
textAscent()
Examples
example pic
float base = height * 0.75;
float scalar = 0.8; // Different for each font

textSize(32);  // Set initial text size
float a = textAscent() * scalar;  // Calc ascent
line(0, base-a, width, base-a);
text("dp", 0, base);  // Draw text on baseline

textSize(64);  // Increase text size
a = textAscent() * scalar;  // Recalc ascent
line(40, base-a, width, base-a);
text("dp", 40, base);  // Draw text on baseline
Description    Returns ascent of the current font at its current size. This information is useful for determining the height of the font above the baseline. For example, adding the textAscent() and textDescent() values will give you the total height of the line.
Syntax
textAscent()
Returns    float
Related    textDescent()
*/
float textAscent();

/*
Name
textDescent()
Examples
example pic
float base = height * 0.75;
float scalar = 0.8; // Different for each font

textSize(32);  // Set initial text size
float a = textDescent() * scalar;  // Calc ascent
line(0, base+a, width, base+a);
text("dp", 0, base);  // Draw text on baseline

textSize(64);  // Increase text size
a = textDescent() * scalar;  // Recalc ascent
line(40, base+a, width, base+a);
text("dp", 40, base);  // Draw text on baseline
Description    Returns descent of the current font at its current size. This information is useful for determining the height of the font below the baseline. For example, adding the textAscent() and textDescent() values will give you the total height of the line.
Syntax
textDescent()
Returns    float
Related    textAscent()
*/
float textDescent();


//Math

//Operators
/*% (modulo)
* (multiply)
*= (multiply assign)
+ (addition)
++ (increment)
+= (add assign)
- (minus)
-- (decrement)
-= (subtract assign)
/ (divide)
/= (divide assign)
Bitwise Operators
& (bitwise AND)
<< (left shift)
>> (right shift)
| (bitwise OR)*/

//Calculation
/*abs()
ceil()
constrain()
dist()
exp()
floor()
lerp()
log()
mag()
map()
max()
min()
norm()
pow()
round()
sq()
sqrt()*/

//Trigonometry
/*acos()
asin()
atan()
atan2()
cos()
degrees()
radians()
sin()
tan()*/

//Random
/*
Name
noise()
Examples
float xoff = 0.0;

void draw() {
    background(204);
    xoff = xoff + .01;
    float n = noise(xoff) * width;
    line(n, 0, n, height);
}
float noiseScale = 0.02;

void draw() {
    background(0);
    for (int x=0; x < width; x++) {
        float noiseVal = noise((mouseX+x)*noiseScale, mouseY*noiseScale);
        stroke(noiseVal*255);
        line(x, mouseY+noiseVal*80, x, height);
    }
}
Description    Returns the Perlin noise value at specified coordinates. Perlin noise is a random sequence generator producing a more natural, harmonic succession of numbers than that of the standard random() function. It was developed by Ken Perlin in the 1980s and has been used in graphical applications to generate procedural textures, shapes, terrains, and other seemingly organic forms.

In contrast to the random() function, Perlin noise is defined in an infinite n-dimensional space, in which each pair of coordinates corresponds to a fixed semi-random value (fixed only for the lifespan of the program). The resulting value will always be between 0.0 and 1.0. Processing can compute 1D, 2D and 3D noise, depending on the number of coordinates given. The noise value can be animated by moving through the noise space, as demonstrated in the first example above. The 2nd and 3rd dimensions can also be interpreted as time.

The actual noise structure is similar to that of an audio signal, in respect to the function's use of frequencies. Similar to the concept of harmonics in physics, Perlin noise is computed over several octaves which are added together for the final result.

Another way to adjust the character of the resulting sequence is the scale of the input coordinates. As the function works within an infinite space, the value of the coordinates doesn't matter as such; only the distance between successive coordinates is important (such as when using noise() within a loop). As a general rule, the smaller the difference between coordinates, the smoother the resulting noise sequence. Steps of 0.005-0.03 work best for most applications, but this will differ depending on use.

There have been debates over the accuracy of the implementation of noise in Processing. For clarification, it's an implementation of "classic Perlin noise" from 1983, and not the newer "simplex noise" method from 2001.
Syntax
noise(x)
noise(x, y)
noise(x, y, z)
Parameters
x    float: x-coordinate in noise space
y    float: y-coordinate in noise space
z    float: z-coordinate in noise space
Returns    float
Related    noiseSeed()
noiseDetail()
random()
*/
float noise(float x);
float noise(float x, float y);
float noise(float x, float y, float z);

/*
Name
noiseDetail()
Examples
float noiseVal;
float noiseScale=0.02;

void draw() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width/2; x++) {
            noiseDetail(3,0.5);
            noiseVal = noise((mouseX+x) * noiseScale, (mouseY+y) * noiseScale);
            stroke(noiseVal*255);
            point(x,y);
            noiseDetail(8,0.65);
            noiseVal = noise((mouseX + x + width/2) * noiseScale,
                             (mouseY + y) * noiseScale);
            stroke(noiseVal * 255);
            point(x + width/2, y);
        }
    }
}
Description    Adjusts the character and level of detail produced by the Perlin noise function. Similar to harmonics in physics, noise is computed over several octaves. Lower octaves contribute more to the output signal and as such define the overall intensity of the noise, whereas higher octaves create finer-grained details in the noise sequence.

By default, noise is computed over 4 octaves with each octave contributing exactly half than its predecessor, starting at 50% strength for the first octave. This falloff amount can be changed by adding an additional function parameter. For example, a falloff factor of 0.75 means each octave will now have 75% impact (25% less) of the previous lower octave. While any number between 0.0 and 1.0 is valid, note that values greater than 0.5 may result in noise() returning values greater than 1.0.

By changing these parameters, the signal created by the noise() function can be adapted to fit very specific needs and characteristics.
Syntax
noiseDetail(lod)
noiseDetail(lod, falloff)
Parameters
lod    int: number of octaves to be used by the noise
falloff    float: falloff factor for each octave
Returns    void
Related    noise()
noiseDetail()
*/
void noiseDetail(int lod);
void noiseDetail(int lod, float falloff);

/*
Name
noiseSeed()
Examples
float xoff = 0.0;

void setup() {
    noiseSeed(0);
    stroke(0, 10);
}

void draw() {
    xoff = xoff + .01;
    float n = noise(xoff) * width;
    line(n, 0, n, height);
}
Description    Sets the seed value for noise(). By default, noise() produces different results each time the program is run. Set the seed parameter to a constant to return the same pseudo-random numbers each time the software is run.
Syntax
noiseSeed(seed)
Parameters
seed    int: seed value
Returns    void
Related    noise()
noiseDetail()
random()
randomSeed()
*/
void noiseSeed(int seed);

/*
Name
random()
Examples
for (int i = 0; i < 100; i++) {
    float r = random(50);
    stroke(r*5);
    line(50, i, 50+r, i);
}
for (int i = 0; i < 100; i++) {
    float r = random(-50, 50);
    println(r);
}
// Get a random element from an array
String[] words = { "apple", "bear", "cat", "dog" };
int index = int(random(words.length));  // Same as int(random(4))
println(words[index]);  // Prints one of the four words
Description    Generates random numbers. Each time the random() function is called, it returns an unexpected value within the specified range. If only one parameter is passed to the function, it will return a float between zero and the value of the high parameter. For example, random(5) returns values between 0 and 5 (starting at zero, and up to, but not including, 5).

If two parameters are specified, the function will return a float with a value between the two values. For example, random(-5, 10.2) returns values starting at -5 and up to (but not including) 10.2. To convert a floating-point random number to an integer, use the int() function.
Syntax
random(high)
random(low, high)
Parameters
low    float: lower limit
high    float: upper limit
Returns    float
Related    randomSeed()
noise()
*/
float random(float high);
float random(float low, float high);

/*
Name
randomGaussian()
Examples
example pic
for (int y = 0; y < 100; y++) {
    float x = randomGaussian() * 15;
    line(50, y, 50 + x, y);
}
example pic
float[] distribution = new float[360];

void setup() {
    size(100, 100);
    for (int i = 0; i < distribution.length; i++) {
        distribution[i] = int(randomGaussian() * 15);
    }
}

void draw() {
    background(204);

    translate(width/2, width/2);

    for (int i = 0; i < distribution.length; i++) {
        rotate(TWO_PI/distribution.length);
        stroke(0);
        float dist = abs(distribution[i]);
        line(0, 0, dist, 0);
    }
}
Description    Returns a float from a random series of numbers having a mean of 0 and standard deviation of 1. Each time the randomGaussian() function is called, it returns a number fitting a Gaussian, or normal, distribution. There is theoretically no minimum or maximum value that randomGaussian() might return. Rather, there is just a very low probability that values far from the mean will be returned; and a higher probability that numbers near the mean will be returned.
Syntax
randomGaussian()
Returns    float
Related    random()
noise()
*/
float randomGaussian();

/*
Name
randomSeed()
Examples
randomSeed(0);
for (int i=0; i < 100; i++) {
    float r = random(0, 255);
    stroke(r);
    line(i, 0, i, 100);
}

Description    Sets the seed value for random(). By default, random() produces different results each time the program is run. Set the seed parameter to a constant to return the same pseudo-random numbers each time the software is run.
Syntax
randomSeed(seed)
Parameters
seed    int: seed value
Returns    void
Related    random()
noise()
noiseSeed()
*/
void randomSeed(int seed);


//Constants

#define HALF_PI 1.5707964
#define PI 3.1415927
#define QUARTER_PI 0.7853982
#define TAU 6.2831855
#define TWO_PI 6.2831855


//sketch

/*
Name
draw()
Examples
float yPos = 0.0;

void setup() {  // setup() runs once
size(200, 200);
frameRate(30);
}

void draw() {  // draw() loops forever, until stopped
background(204);
yPos = yPos - 1.0;
if (yPos < 0) {
yPos = height;
}
line(0, yPos, width, yPos);
}
void setup() {
size(200, 200);
}

// Although empty here, draw() is needed so
// the sketch can process user input events
// (mouse presses in this case).
void draw() { }

void mousePressed() {
line(mouseX, 10, mouseX, 90);
}
Description    Called directly after setup(), the draw() function continuously executes the lines of code contained inside its block until the program is stopped or noLoop() is called. draw() is called automatically and should never be called explicitly. All Processing programs update the screen at the end of draw(), never earlier.

To stop the code inside of draw() from running continuously, use noLoop(), redraw() and loop(). If noLoop() is used to stop the code in draw() from running, then redraw() will cause the code inside draw() to run a single time, and loop() will cause the code inside draw() to resume running continuously.

The number of times draw() executes in each second may be controlled with the frameRate() function.

It is common to call background() near the beginning of the draw() loop to clear the contents of the window, as shown in the first example above. Since pixels drawn to the window are cumulative, omitting background() may result in unintended results.

There can only be one draw() function for each sketch, and draw() must exist if you want the code to run continuously, or to process events such as mousePressed(). Sometimes, you might have an empty call to draw() in your program, as shown in the second example above.
Syntax
draw()
Returns    void
Related    setup()
loop()
noLoop()
redraw()
frameRate()
background()
*/
void draw() __attribute__((weak_import));

/*
Name
setup()
Examples
int x = 0;

void setup() {
size(200, 200);
background(0);
noStroke();
fill(102);
}

void draw() {
rect(x, 10, 2, 80);
x = x + 1;
}
int x = 0;

void setup() {
fullScreen();
background(0);
noStroke();
fill(102);
}

void draw() {
rect(x, height*0.2, 1, height*0.6);
x = x + 2;
}
Description    The setup() function is run once, when the program starts. It's used to define initial enviroment properties such as screen size and to load media such as images and fonts as the program starts. There can only be one setup() function for each program and it shouldn't be called again after its initial execution.

If the sketch is a different dimension than the default, the size() function or fullScreen() function must be the first line in setup().

Note: Variables declared within setup() are not accessible within other functions, including draw().
Syntax
setup()
Returns    void
Related    size()
loop()
noLoop()
draw()
*/
void setup() __attribute__((weak_import));

/*
Name
settings()
Examples
// Run code at full screen using the default renderer

int x = 0;

void settings() {
fullScreen();
}

void setup() {
background(0);
noStroke();
fill(102);
}

void draw() {
rect(x, height*0.2, 1, height*0.6);
x = x + 2;
}
// Run code at full screen using the P2D renderer
// on screen 2 of a multiple monitor hardware setup

int x = 0;

void settings() {
fullScreen(P2D, 2);
}

void setup() {
background(0);
noStroke();
fill(102);
}

void draw() {
rect(x, height*0.2, 1, height*0.6);
x = x + 2;
}
// Run code at full screen using the P2D renderer
// across all screens on a multiple monitor setup

int x = 0;

void settings() {
fullScreen(P2D, SPAN);
}

void setup() {
background(0);
noStroke();
fill(102);
}

void draw() {
rect(x, height*0.2, 1, height*0.6);
x = x + 2;
}
int w = 200;
int h = 200;
int x = 0;

void settings() {
size(w, h);
}

void setup() {
background(0);
noStroke();
fill(102);
}

void draw() {
rect(x, 10, 1, 180);
x = x + 2;
}
Description    The settings() function is new with Processing 3.0. It's not needed in most sketches. It's only useful when it's absolutely necessary to define the parameters to size() with a variable. Alternately, the settings() function is necessary when using Processing code outside of the Processing Development Environment (PDE). For example, when using the Eclipse code editor, it's necessary to use settings() to define the size() and smooth() values for a sketch..

The settings() method runs before the sketch has been set up, so other Processing functions cannot be used at that point. For instance, do not use loadImage() inside settings(). The settings() method runs "passively" to set a few variables, compared to the setup() command that call commands in the Processing API.
Syntax
settings()
Returns    void
Related    fullScreen()
setup()
size()
smooth()
*/
void settings()  __attribute__((weak_import));

/*
Name
mouseClicked()
Examples
// Click within the image to change
// the value of the rectangle after
// after the mouse has been clicked

int value = 0;

void draw() {
fill(value);
rect(25, 25, 50, 50);
}

void mouseClicked() {
if (value == 0) {
value = 255;
} else {
value = 0;
}
}
Description    The mouseClicked() function is called after a mouse button has been pressed and then released.

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
mouseClicked()
mouseClicked(event)
Returns    void
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
void mouseClicked()  __attribute__((weak_import));
//void mouseClicked(event)  __attribute__((weak_import));

/*
Name
mouseDragged()
Examples
// Drag (click and hold) your mouse across the
// image to change the value of the rectangle

int value = 0;

void draw() {
fill(value);
rect(25, 25, 50, 50);
}

void mouseDragged()
{
value = value + 5;
if (value > 255) {
value = 0;
}
}
Description    The mouseDragged() function is called once every time the mouse moves while a mouse button is pressed. (If a button is not being pressed, mouseMoved() is called instead.)

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
mouseDragged()
mouseDragged(event)
Returns    void
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseButton
mouseWheel()
*/
void mouseDragged()  __attribute__((weak_import));
//void mouseDragged(event)  __attribute__((weak_import));

/*
Name
mouseMoved()
Examples
// Move the mouse across the image
// to change its value

int value = 0;

void draw() {
fill(value);
rect(25, 25, 50, 50);
}

void mouseMoved() {
value = value + 5;
if (value > 255) {
value = 0;
}
}
Description    The mouseMoved() function is called every time the mouse moves and a mouse button is not pressed. (If a button is being pressed, mouseDragged() is called instead.)

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
mouseMoved()
mouseMoved(event)
Returns    void
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseDragged()
mouseButton
mouseWheel()
*/
void mouseMoved() __attribute__((weak_import));
//void mouseMoved(event) __attribute__((weak_import));

/*
Name
mousePressed()
Examples
// Click within the image to change
// the value of the rectangle

int value = 0;

void draw() {
fill(value);
rect(25, 25, 50, 50);
}

void mousePressed() {
if (value == 0) {
value = 255;
} else {
value = 0;
}
}
Description    The mousePressed() function is called once after every time a mouse button is pressed. The mouseButton variable (see the related reference entry) can be used to determine which button has been pressed.

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
mousePressed()
mousePressed(event)
Returns    void
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
void mousePressed() __attribute__((weak_import));
//void mousePressed(event) __attribute__((weak_import));

/*
Name
mouseReleased()
Examples
// Click within the image to change
// the value of the rectangle

int value = 0;

void draw() {
fill(value);
rect(25, 25, 50, 50);
}

void mouseReleased() {
if (value == 0) {
value = 255;
} else {
value = 0;
}
}
Description    The mouseReleased() function is called every time a mouse button is released.

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
mouseReleased()
mouseReleased(event)
Returns    void
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed
mousePressed()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
mouseWheel()
*/
void mouseReleased() __attribute__((weak_import));
//void mouseReleased(event) __attribute__((weak_import));

/*
Name
mouseWheel()
Examples
void setup() {
size(100, 100);
}

void draw() {}

void mouseWheel(MouseEvent event) {
float e = event.getCount();
println(e);
}

Description    The mouseWheel() function returns positive values when the mouse wheel is rotated down (toward the user), and negative values for the other direction (up or away from the user). On OS X with "natural" scrolling enabled, the values are opposite.

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
mouseWheel(event)
Parameters
event    MouseEvent: the MouseEvent
Returns    void
Related    mouseX
mouseY
pmouseX
pmouseY
mousePressed
mousePressed()
mouseReleased()
mouseClicked()
mouseMoved()
mouseDragged()
mouseButton
*/
//void mouseWheel(MouseEvent event) __attribute__((weak_import));

/*
Name
keyPressed()
Examples
// Click on the image to give it focus,
// and then press any key.

int value = 0;

void draw() {
fill(value);
rect(25, 25, 50, 50);
}

void keyPressed() {
if (value == 0) {
value = 255;
} else {
value = 0;
}
}
Description    The keyPressed() function is called once every time a key is pressed. The key that was pressed is stored in the key variable.

For non-ASCII keys, use the keyCode variable. The keys included in the ASCII specification (BACKSPACE, TAB, ENTER, RETURN, ESC, and DELETE) do not require checking to see if the key is coded; for those keys, you should simply use the key variable directly (and not keyCode). If you're making cross-platform projects, note that the ENTER key is commonly used on PCs and Unix, while the RETURN key is used on Macs. Make sure your program will work on all platforms by checking for both ENTER and RETURN.

Because of how operating systems handle key repeats, holding down a key may cause multiple calls to keyPressed(). The rate of repeat is set by the operating system, and may be configured differently on each computer.

Note that there is a similarly named boolean variable called keyPressed. See its reference page for more information.

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.

With the release of macOS Sierra, Apple changed how key repeat works, so keyPressed may not function as expected. See here for details of the problem and how to fix it.
Syntax
keyPressed()
keyPressed(event)
Returns    void
Related    key
keyCode
keyPressed
keyReleased()
*/
void keyPressed() __attribute__((weak_import));
//void keyPressed(event) __attribute__((weak_import));

/*
Name
keyReleased()
Examples
// Click on the image to give it focus,
// and then press any key.

int value = 0;

void draw() {
fill(value);
rect(25, 25, 50, 50);
}

void keyReleased() {
if (value == 0) {
value = 255;
} else {
value = 0;
}
}
Description    The keyReleased() function is called once every time a key is released. The key that was released will be stored in the key variable. See key and keyCode for more information.

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
keyReleased()
keyReleased(event)
Returns    void
Related    key
keyCode
keyPressed
keyPressed()
*/
void keyReleased() __attribute__((weak_import));
//void keyReleased(event) __attribute__((weak_import));

/*
Name
keyTyped()
Examples
// Run this program to learn how each of these functions
// relate to the others.

void draw() { } // Empty draw() needed to keep the program running

void keyPressed() {
println("pressed " + int(key) + " " + keyCode);
}

void keyTyped() {
println("typed " + int(key) + " " + keyCode);
}

void keyReleased() {
println("released " + int(key) + " " + keyCode);
}

Description    The keyTyped() function is called once every time a key is pressed, but action keys such as Ctrl, Shift, and Alt are ignored.

Because of how operating systems handle key repeats, holding down a key may cause multiple calls to keyTyped(). The rate of repeat is set by the operating system, and may be configured differently on each computer.

Mouse and keyboard events only work when a program has draw(). Without draw(), the code is only run once and then stops listening for events.
Syntax
keyTyped()
keyTyped(event)
Returns    void
Related    keyPressed
key
keyCode
keyReleased()
*/
void keyTyped() __attribute__((weak_import));
//void keyTyped(event) __attribute__((weak_import));


//OpenGL
void showGLVersion();

#endif /* Processing_hpp */
