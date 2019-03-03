//
//  ProcessingOpenGLView.m
//  Processing
//
//  Created by Apollo Chen on 1/28/19.
//  Copyright © 2019 Apollo Chen. All rights reserved.
//

#import "MacTypes.h"//modifed for "normal" conflict
#import "ProcessingOpenGLView.h"
#include <OpenGL/gl3.h>
#include "lib/Processing.h"

extern void draw() __attribute__((weak_import));

/*
 * Name: resizeWindow
 * Params: width - new Window's width
 *        height - new Window's height
 * Description: Resize Window(depend on platform)
 */
void resizeWindow(int width, int height)
{
    NSRect frame = [[NSApplication sharedApplication].mainWindow frame];
    frame.size.width = $width + 1;
    frame.size.height = $height + 23;
    [[NSApplication sharedApplication].mainWindow setFrame:frame display:TRUE];
    [[NSApplication sharedApplication].mainWindow center];
}

@interface ProcessingOpenGLView ()


@end

@implementation ProcessingOpenGLView
- (void) awakeFromNib
{
    // 1. Create a context with opengl pixel format
    NSOpenGLPixelFormatAttribute pixelFormatAttributes[] =
    {
        NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core,
        NSOpenGLPFAColorSize    , 24                           ,
        NSOpenGLPFAAlphaSize    , 8                            ,
        NSOpenGLPFADoubleBuffer ,
        NSOpenGLPFAAccelerated  ,
        NSOpenGLPFANoRecovery   ,
        0
    };
    NSOpenGLPixelFormat *pixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:pixelFormatAttributes];
    
    NSOpenGLContext* openGLContext = [[NSOpenGLContext alloc] initWithFormat:pixelFormat shareContext:nil];
    [self setOpenGLContext:openGLContext];
    
    // 2. Make the context current
    [[self openGLContext] makeCurrentContext];

}

- (void)drawRect:(NSRect)dirtyRect {
    [super drawRect:dirtyRect];

    if (setup != NULL)
        setup();
    [[self openGLContext] flushBuffer];

    [self loop];
}

- (void)loop {
    $mouseX = self.window.mouseLocationOutsideOfEventStream.x - 1;
    $mouseY = $height - (self.window.mouseLocationOutsideOfEventStream.y - 1);
    $mouseX = $mouseX < 0 ? 0 : ($mouseX > $width ? $width : $mouseX);
    $mouseY = $mouseY < 0 ? 0 : ($mouseY > $height ? $height : $mouseY);
    if ($loop) {
        if (draw) {
            resetMatrix();
            draw();
            $frameCount ++;
            [[self openGLContext] flushBuffer];
        }
    }
    $pmouseX = $mouseX;
    $pmouseY = $mouseY;
    
    double delayInSeconds = 1.0 / $frameRate;
    dispatch_time_t delayInNanoSeconds = dispatch_time(DISPATCH_TIME_NOW, delayInSeconds * NSEC_PER_SEC);
    //dispatch_queue_t concurrentQueue = dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0);
    dispatch_after(delayInNanoSeconds, dispatch_get_main_queue(), ^(void)
                   {
                       [self loop];
                   });
}


- (void)prepareOpenGL {
    openglAgent.PrepareOpenGL();
}

- (BOOL)acceptsFirstResponder
{
    return TRUE;
}

- (void)keyDown:(NSEvent *)event
{
    $keyPressed = TRUE;
    switch(event.keyCode) {
        case NSUpArrowFunctionKey:
            $key = CODED;
            $keyCode = UP;
            break;
        case NSDownArrowFunctionKey:
            $key = CODED;
            $keyCode = DOWN;
            break;
        case NSLeftArrowFunctionKey:
            $key = CODED;
            $keyCode = LEFT;
            break;
        case NSRightArrowFunctionKey:
            $key = CODED;
            $keyCode = RIGHT;
            break;
        case NSF1FunctionKey:
            break;
        case NSF2FunctionKey:
            break;
        case NSF3FunctionKey:
            break;
        case NSF4FunctionKey:
            break;
        case NSF5FunctionKey:
            break;
        case NSF6FunctionKey:
            break;
        case NSF7FunctionKey:
            break;
        case NSF8FunctionKey:
            break;
        case NSF9FunctionKey:
            break;
        case NSF10FunctionKey:
            break;
        case NSF11FunctionKey:
            break;
        case NSF12FunctionKey:
            break;
        case NSDeleteFunctionKey:
            $key = CODED;
            $keyCode = DELETE;
            break;
        case NSExecuteFunctionKey:
            break;
        case '\r':
        case '\n':
            $key = CODED;
            $keyCode = RETURN;
            break;
        case 0x33:
            $key = CODED;
            $keyCode = ESC;
            break;
        /*// other constants here
            NSUndoFunctionKey               = 0xF743,
            NSRedoFunctionKey               = 0xF744,
            NSFindFunctionKey               = 0xF745,
            NSHelpFunctionKey               = 0xF746,
            NSModeSwitchFunctionKey         = 0xF747*/
        default:
            $key = event.keyCode;
            $keyCode = 0;
            break;

    }
    if (keyPressed)
        keyPressed();
}

- (void)keyUp:(NSEvent *)event
{
    $keyPressed = FALSE;
    if (keyReleased)
        keyReleased();
}


//鼠标左键按下
- (void)mouseDown:(NSEvent *)event{
    NSPoint clickLocation = [self convertPoint:[event locationInWindow] fromView:nil];
    $mouseX = clickLocation.x;
    $mouseY = clickLocation.y;
    $mouseButton = LEFT;
    $mousePressed = TRUE;
    if (mousePressed)
        mousePressed();
}

//鼠标左键起来
- (void)mouseUp:(NSEvent *)event{
    NSPoint clickLocation = [self convertPoint:[event locationInWindow] fromView:nil];
    $mouseX = clickLocation.x;
    $mouseY = clickLocation.y;
    $mousePressed = FALSE;
    if (mouseReleased)
        mouseReleased();
}

//鼠标右键按下
- (void)rightMouseDown:(NSEvent *)event{
    NSPoint clickLocation = [self convertPoint:[event locationInWindow] fromView:nil];
    $mouseX = clickLocation.x;
    $mouseY = clickLocation.y;
    $mouseButton = RIGHT;
    $mousePressed = TRUE;
    if (mousePressed)
        mousePressed();
}

//鼠标右键起来
- (void)rightMouseUp:(NSEvent *)event{
    NSPoint clickLocation = [self convertPoint:[event locationInWindow] fromView:nil];
    $mouseX = clickLocation.x;
    $mouseY = clickLocation.y;
    $mousePressed = FALSE;
    if (mouseReleased)
        mouseReleased();
}

//鼠标移动
- (void)mouseMoved:(NSEvent *)event{
    NSPoint clickLocation = [self convertPoint:[event locationInWindow] fromView:nil];
    $mouseX = clickLocation.x;
    $mouseY = clickLocation.y;
    if (mouseMoved)
        mouseMoved();
}

//鼠标按住左键进行拖拽
- (void)mouseDragged:(NSEvent *)event{
    NSPoint clickLocation = [self convertPoint:[event locationInWindow] fromView:nil];
    $mouseX = clickLocation.x;
    $mouseY = clickLocation.y;
    if (mouseDragged)
        mouseDragged();
}

//鼠标按住右键进行拖拽
- (void)rightMouseDragged:(NSEvent *)event{
    NSPoint clickLocation = [self convertPoint:[event locationInWindow] fromView:nil];
    $mouseX = clickLocation.x;
    $mouseY = clickLocation.y;
}

@end
