#include <iostream>

#include "GL_Cube.h"

// =================================================================
// =================================================================
// =================================================================

#include<math.h>
#include<GL/glut.h>

// =================================================================
// =================================================================
// =================================================================

//Screen dimension constants
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 1000;

// =================================================================
// =================================================================
// =================================================================

typedef float Matrix4 [4][4];
Matrix4 theMatrix;
static GLfloat input[8][3]=
{
 {10,10,-50},{60,10,-50},{60,60,-50},{10,60,-50},   // back face
 {0,0,0},{50,0,0},{50,50,0},{0,50,0}                // front face
};
float output[8][3];
float deltaX, deltaY;
float sx,sy,sz;
float angle;
bool firstPositioning=true;
GL_Cube cubes[4];

void setIdentityM(Matrix4 m)
{
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			m[i][j]=(i==j);
}
// void translate(int tx,int ty,int tz)
// {
// 	for(int i=0;i<8;i++)
// 	{
// 		output[i][0]=input[i][0]+tx;
// 		output[i][1]=input[i][1]+ty;
// 		output[i][2]=input[i][2]+tz;
// 	}
// }
void scale(int sx,int sy,int sz)
{
	theMatrix[0][0]=sx;
	theMatrix[1][1]=sy;
	theMatrix[2][2]=sz;
}
void RotateX(float angle) //Parallel to x
{
	angle = angle*3.142/180;
	theMatrix[1][1] = cos(angle);
	theMatrix[1][2] = -sin(angle);
	theMatrix[2][1] = sin(angle);
	theMatrix[2][2] = cos(angle);
}
void RotateY(float angle) //parallel to y
{
	angle = angle*3.14/180;
	theMatrix[0][0] = cos(angle);
	theMatrix[0][2] = -sin(angle);
	theMatrix[2][0] = sin(angle);
	theMatrix[2][2] = cos(angle);
}
void RotateZ(float angle) //parallel to z
{
	angle = angle*3.14/180;
	theMatrix[0][0] = cos(angle);
	theMatrix[0][1] = sin(angle);
	theMatrix[1][0] = -sin(angle);
	theMatrix[1][1] = cos(angle);
}
void multiplyM()
{
	//We Don't require 4th row and column in scaling and rotation
	//[8][3]=[8][3]*[3][3] //4th not used
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<3;j++)
		{
			output[i][j]=0;
			for(int k=0;k<3;k++)
			{
				output[i][j]=output[i][j]+input[i][k]*theMatrix[k][j];
			}
		}
	}
}

void checkCollission()
{
	int *minMaxX;        // 1st val: min
	int *minMaxY;        // 2nd val: max
	int *minMaxZ;
	int *minMaxPlayerX;        // 1st val: min
	int *minMaxPlayerY;        // 2nd val: max
	int *minMaxPlayerZ;

	minMaxPlayerX = cubes[0].getMinMaxX();
	minMaxPlayerY = cubes[0].getMinMaxY();
	minMaxPlayerZ = cubes[0].getMinMaxZ();

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
	printf("Player min & max X, Y, Z:   \t%d %d | %d %d | %d %d \n", minMaxPlayerX[0], minMaxPlayerX[1], minMaxPlayerY[0], minMaxPlayerY[1], minMaxPlayerZ[0], minMaxPlayerZ[1]);

	for(int i=1; i < sizeof(cubes)/ sizeof(cubes[0]); i++)
	{
		minMaxX = cubes[i].getMinMaxX();
		minMaxY = cubes[i].getMinMaxY();
		minMaxZ = cubes[i].getMinMaxZ();
		
		printf("Cube[%d] min & max X, Y, Z: \t%d %d | %d %d | %d %d \n", i, minMaxX[0], minMaxX[1], minMaxY[0], minMaxY[1], minMaxZ[0], minMaxZ[1]);

		// we do this double check since in the future one object might be bigger than the other
		// X axis check
		if(((minMaxPlayerX[0] >= minMaxX[0]) && (minMaxPlayerX[0] <= minMaxX[1]) || (minMaxPlayerX[1] >= minMaxX[0]) && (minMaxPlayerX[1] <= minMaxX[1]))		// check if player's min or max X is inside cube
		|| ((minMaxX[0] >= minMaxPlayerX[0]) && (minMaxX[0] <= minMaxPlayerX[1]) || (minMaxX[1] >= minMaxPlayerX[0]) && (minMaxX[1] <= minMaxPlayerX[1])))		// check if cube's min or max X is inside player
		{
			printf("X collission on cube[%d]. \n", i);
		}

		// Y axis check
		if(((minMaxPlayerY[0] >= minMaxY[0]) && (minMaxPlayerY[0] <= minMaxY[1]) || (minMaxPlayerY[1] >= minMaxY[0]) && (minMaxPlayerY[1] <= minMaxY[1]))		// check if player's min or max X is inside cube
		|| ((minMaxY[0] >= minMaxPlayerY[0]) && (minMaxY[0] <= minMaxPlayerY[1]) || (minMaxY[1] >= minMaxPlayerY[0]) && (minMaxY[1] <= minMaxPlayerY[1])))		// check if cube's min or max X is inside player
		{
			printf("Y collission on cube[%d]. \n", i);
		}

		// Z axis check
		if(((minMaxPlayerZ[0] >= minMaxZ[0]) && (minMaxPlayerZ[0] < minMaxZ[1]) || (minMaxPlayerZ[1] >= minMaxZ[0]) && (minMaxPlayerZ[1] <= minMaxZ[1]))		// check if player's min or max X is inside cube
		|| ((minMaxZ[0] >= minMaxPlayerZ[0]) && (minMaxZ[0] < minMaxPlayerZ[1]) || (minMaxZ[1] >= minMaxPlayerZ[0]) && (minMaxZ[1] <= minMaxPlayerZ[1])))		// check if cube's min or max X is inside player
		{
			printf("Z collission on cube[%d]. \n", i);
		}
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ \n");
}

// void draw(float a[8][3])
// {
// 	glBegin(GL_QUADS);
// 	glColor3f(0.7,0.4,0.5); //behind
// 	glVertex3fv(a[0]);
// 	glVertex3fv(a[1]);
// 	glVertex3fv(a[2]);
// 	glVertex3fv(a[3]);
// 	glColor3f(0.8,0.2,0.4); //bottom
// 	glVertex3fv(a[0]);
// 	glVertex3fv(a[1]);
// 	glVertex3fv(a[5]);
// 	glVertex3fv(a[4]);
// 	glColor3f(0.3,0.6,0.7); //left
// 	glVertex3fv(a[0]);
// 	glVertex3fv(a[4]);
// 	glVertex3fv(a[7]);
// 	glVertex3fv(a[3]);
// 	glColor3f(0.2,0.8,0.2); //right
// 	glVertex3fv(a[1]);
// 	glVertex3fv(a[2]);
// 	glVertex3fv(a[6]);
// 	glVertex3fv(a[5]);
// 	glColor3f(0.7,0.7,0.2); //up
// 	glVertex3fv(a[2]);
// 	glVertex3fv(a[3]);
// 	glVertex3fv(a[7]);
// 	glVertex3fv(a[6]);
// 	glColor3f(1.0,0.1,0.1);
// 	glVertex3fv(a[4]);
// 	glVertex3fv(a[5]);
// 	glVertex3fv(a[6]);
// 	glVertex3fv(a[7]);
// 	glEnd();
// }
void init()
{
	glClearColor(0.0, 0.0, 0.0, 1.0); //set backgrond color to black
    //glClearColor(1.0,1.0,1.0,1.0); //set backgrond color to white
	glOrtho(-454.0,454.0,-250.0,250.0,-250.0,250.0);
	// Set the no. of Co-ordinates along X & Y axes and their gappings
	glEnable(GL_DEPTH_TEST);
	// To Render the surfaces Properly according to their depths
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	
    // printf("draw !!!\n");
    
    // middle cube
    cubes[0].reposition(deltaX, deltaY, 0);
	//setIdentityM(theMatrix);

    if(firstPositioning)
    {
		// for(int a = 0; a < 8; a++)
		// {
		// 	for(int b = 0; b < 3; b++)
		// 	{
		// 		printf("%.2f, ", cubes[1].cube[a][b]);
		// 	}

		// 	printf("\n");
		// }

		// printf("~~~~~~~~~~~~~~~\n");

		// for(int a = 0; a < 8; a++)
		// {
		// 	for(int b = 0; b < 3; b++)
		// 	{
		// 		printf("%.2f, ", cubes[2].cube[a][b]);
		// 	}

		// 	printf("\n");
		// }
		// printf("~~~~~~~~~~~~~~~\n");

		// for(int a = 0; a < 8; a++)
		// {
		// 	for(int b = 0; b < 3; b++)
		// 	{
		// 		printf("%.2f, ", cubes[3].cube[a][b]);
		// 	}

		// 	printf("\n");
		// }
		// printf("~~~~~~~~~~~~~~~\n");
		
        // right cube
		// printf("For cube 1: \n");
        cubes[1].reposition(100, 0, 0);
        // left cube
        cubes[2].reposition(-100, 0, 0);
        // top cube
        cubes[3].reposition(0, 100, 0);

        firstPositioning = false;

		// printf("\n");

		// for(int a = 0; a < 8; a++)
		// {
		// 	for(int b = 0; b < 3; b++)
		// 	{
		// 		printf("%.2f, ", cubes[1].cube[a][b]);
		// 	}

		// 	printf("\n");
		// }

		// printf("~~~~~~~~~~~~~~~\n");

		// for(int a = 0; a < 8; a++)
		// {
		// 	for(int b = 0; b < 3; b++)
		// 	{
		// 		printf("%.2f, ", cubes[2].cube[a][b]);
		// 	}

		// 	printf("\n");
		// }
		// printf("~~~~~~~~~~~~~~~\n");

		// for(int a = 0; a < 8; a++)
		// {
		// 	for(int b = 0; b < 3; b++)
		// 	{
		// 		printf("%.2f, ", cubes[3].cube[a][b]);
		// 	}

		// 	printf("\n");
		// }
		// printf("~~~~~~~~~~~~~~~\n");
    }

    // draw all cubes
    cubes[0].drawCube();
    cubes[1].drawCube();
    cubes[2].drawCube();
    cubes[3].drawCube();

    deltaX=0;
    deltaY=0;

    checkCollission();
	
	glFlush();
    // glutSwapBuffers();
}

// =================================================================
// =================================================================
// =================================================================

int keyUpPressed = 0;

void processSpecialKeys(unsigned char key, int x, int y)
{
    switch (key){
		case 'w':
			// printf("w !!!\n");
            deltaY=10;
			break;
		case 's': 
            // printf("s !!!\n");
            deltaY=-10;
		    break;
        case 'a': 
            // printf("a !!!\n");
            deltaX=-10;
		    break;
        case 'd': 
            // printf("d !!!\n");
            deltaX=10;
		    break;
		default:
            break;
	}
    glutPostRedisplay();
}

void releaseSpecialKeys(unsigned char key, int x, int y)
{
    switch (key){
		case 'w':
			// printf("w !!!\n");
            deltaY=0;
			break;
		case 's': 
            // printf("s !!!\n");
            deltaY=0;
		    break;
        case 'a': 
            // printf("a !!!\n");
            deltaX=0;
		    break;
        case 'd': 
            // printf("d !!!\n");
            deltaX=0;
		    break;
		default:
            break;
	}
    glutPostRedisplay();
}

int main( int argc, char* args[] )
{
    // std::cout << "Hello World!!!!" << std::endl;
    printf("Hello World!!!\n");



    glutInit(&argc,args);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(1280,720);
	glutInitWindowPosition(0,0);
	glutCreateWindow("3D TRANSFORMATIONS");
	init();
glutDisplayFunc(display);
    // handling for pressing and releasing a key
    glutKeyboardFunc(processSpecialKeys);
    glutKeyboardUpFunc(releaseSpecialKeys);
    // glutSpecialFunc(processSpecialKeys);
    // glutSpecialUpFunc(releaseSpecialKeys);
	
	
	glutMainLoop();

    return 0;
}