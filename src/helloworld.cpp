#include <iostream>

#include "GL_Cube.h"

// =================================================================
// =================================================================
// =================================================================


//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

GL_Cube cubes[4];
float deltaX, deltaY;
float angleX = 0.0f, angleY = 0.0f;
bool firstPositioning=true;

void checkCollission()
{
	int *minMaxX, *minMaxY, *minMaxZ;        				// 1st val: min; 2nd val: max
	int *minMaxPlayerX, *minMaxPlayerY, *minMaxPlayerZ;     // 1st val: min; 2nd val: max

	minMaxPlayerX = cubes[0].getMinMaxX();
	minMaxPlayerY = cubes[0].getMinMaxY();
	minMaxPlayerZ = cubes[0].getMinMaxZ();

	for(int i=1; i < sizeof(cubes)/ sizeof(cubes[0]); i++)
	{
		int collCounter=0;

		minMaxX = cubes[i].getMinMaxX();
		minMaxY = cubes[i].getMinMaxY();
		minMaxZ = cubes[i].getMinMaxZ();
		
		// X axis check
		if((minMaxPlayerX[0] <= minMaxX[1]) && (minMaxPlayerX[1] >= minMaxX[0]))
		{
			// printf("X collission on cube[%d]. \n", i);
			collCounter++;
		}

		// Y axis check
		if((minMaxPlayerY[0] <= minMaxY[1]) && (minMaxPlayerY[1] >= minMaxY[0]))
		{
			// printf("Y collission on cube[%d]. \n", i);
			collCounter++;
		}

		// Z axis check
		if((minMaxPlayerZ[0] <= minMaxZ[1]) && (minMaxPlayerZ[1] >= minMaxZ[0]))
		{
			// printf("Z collission on cube[%d]. \n", i);
			collCounter++;
		}

		if(collCounter == 3)
		{
			cubes[i].hasDied(true);
			break;
		}
	}
}

void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //set backgrond color to black
    //glClearColor(1.0,1.0,1.0,1.0);    //set backgrond color to white
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glOrtho(-454.0,454.0, -250.0,250.0, -250.0,250.0);	// Set the no. of Co-ordinates along X & Y axes and their gappings

	glMatrixMode(GL_MODELVIEW);
	// To Render the surfaces Properly according to their depths
	glEnable(GL_DEPTH_TEST);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
    
    // middle cube (the player)
    cubes[0].reposition(deltaX, deltaY, 0);

    if(firstPositioning)
    {
		// right cube
        cubes[1].reposition(100, 0, 0);
        // left cube
        cubes[2].reposition(-100, 0, 0);
        // top cube
        cubes[3].reposition(0, 100, 0);

        firstPositioning = false;
    }

	if(angleX != 0.0f)
		{glRotatef(angleX, 1.0f, 0.0f, 0.0f);}
	if(angleY != 0.0f)
		{glRotatef(angleY, 0.0f, 1.0f, 0.0f);}

	// draw all cubes
    cubes[0].drawCube();
    cubes[1].drawCube();
    cubes[2].drawCube();
    cubes[3].drawCube();

    deltaX=0;
    deltaY=0;
	angleX = 0.0f;
	angleY = 0.0f;

    checkCollission();
	
	glFlush();
    // glutSwapBuffers();
}

// =================================================================
// =================================================================
// =================================================================

int keyUpPressed = 0;

void processSpecialKeys(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			angleX+=5.0f;
			break;
		case GLUT_KEY_DOWN:
			angleX-=5.0f;
			break;
		case GLUT_KEY_LEFT:
			angleY+=5.0f;
			break;
		case GLUT_KEY_RIGHT:
			angleY-=5.0f;
			break;
	}

	glutPostRedisplay();
}

void processKeys(unsigned char key, int x, int y)
{
    switch (key){
		case 'w':
            deltaY=10;
			break;
		case 's': 
            deltaY=-10;
		    break;
        case 'a': 
            deltaX=-10;
		    break;
        case 'd': 
            deltaX=10;
		    break;
		default:
            break;
	}
    glutPostRedisplay();
}

void releaseKeys(unsigned char key, int x, int y)
{
    switch (key){
		case 'w':
            deltaY=0;
			break;
		case 's': 
            deltaY=0;
		    break;
        case 'a': 
            deltaX=0;
		    break;
        case 'd': 
            deltaX=0;
		    break;
		default:
            break;
	}
    glutPostRedisplay();
}

int main( int argc, char* args[] )
{
    printf("Hello World!!!\n");

    glutInit(&argc,args);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Box collision");
	init();
	glutDisplayFunc(display);

    // handling for pressing and releasing a key
    glutKeyboardFunc(processKeys);
    glutKeyboardUpFunc(releaseKeys);
	// special processing for arrow keys
    glutSpecialFunc(processSpecialKeys);
	
	
	glutMainLoop();

    return 0;
}