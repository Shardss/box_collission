#include "GL_Cube.h"

void GL_Cube::reposition(float x, float y, float z)
{
    for(int i=0;i<8;i++)
	{
		cube[i][0] += x;
		cube[i][1] += y;
		cube[i][2] += z;

        if(cube[i][0] < minMaxX[0])
            {minMaxX[0] = cube[i][0];}
        if(cube[i][0] > minMaxX[1])
            {minMaxX[1] = cube[i][0];}

        if(cube[i][1] < minMaxY[0])
            {minMaxY[0] = cube[i][0];}
        if(cube[i][1] > minMaxY[1])
            {minMaxY[1] = cube[i][0];}

        if(cube[i][2] < minMaxZ[0])
            {minMaxZ[0] = cube[i][2];}
        if(cube[i][2] > minMaxZ[1])
            {minMaxZ[1] = cube[i][2];}
	}
}

void GL_Cube::drawCube()
{
    glBegin(GL_QUADS);

#ifdef SHADED_CUBE
    glColor3fv(color[0]);
    glVertex3fv(cube[0]);
    glColor3fv(color[1]);
    glVertex3fv(cube[1]);
    glColor3fv(color[2]);
    glVertex3fv(cube[2]);
    glColor3fv(color[3]);
    glVertex3fv(cube[3]);
   
    glColor3fv(color[3]);
    glVertex3fv(cube[3]);
    glColor3fv(color[4]);
    glVertex3fv(cube[4]);
    glColor3fv(color[7]);
    glVertex3fv(cube[7]);
    glColor3fv(color[2]);
    glVertex3fv(cube[2]);
   
    glColor3fv(color[0]);
    glVertex3fv(cube[0]);
    glColor3fv(color[5]);
    glVertex3fv(cube[5]);
    glColor3fv(color[6]);
    glVertex3fv(cube[6]);
    glColor3fv(color[1]);
    glVertex3fv(cube[1]);
   
    glColor3fv(color[5]);
    glVertex3fv(cube[5]);
    glColor3fv(color[4]);
    glVertex3fv(cube[4]);
    glColor3fv(color[7]);
    glVertex3fv(cube[7]);
    glColor3fv(color[6]);
    glVertex3fv(cube[6]);
   
    glColor3fv(color[5]);
    glVertex3fv(cube[5]);
    glColor3fv(color[0]);
    glVertex3fv(cube[0]);
    glColor3fv(color[3]);
    glVertex3fv(cube[3]);
    glColor3fv(color[4]);
    glVertex3fv(cube[4]);
   
    glColor3fv(color[6]);
    glVertex3fv(cube[6]);
    glColor3fv(color[1]);
    glVertex3fv(cube[1]);
    glColor3fv(color[2]);
    glVertex3fv(cube[2]);
    glColor3fv(color[7]);
    glVertex3fv(cube[7]);
#else /* flat cube */
	glColor3f(color[0][0], color[0][1], color[0][2]); //behind
	glVertex3fv(cube[0]);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[3]);
	glColor3f(color[1][0], color[1][1], color[1][2]); //bottom
	glVertex3fv(cube[0]);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[4]);
	glColor3f(color[2][0], color[2][1], color[2][2]); //left
	glVertex3fv(cube[0]);
	glVertex3fv(cube[4]);
	glVertex3fv(cube[7]);
	glVertex3fv(cube[3]);
	glColor3f(color[3][0], color[3][1], color[3][2]); //right
	glVertex3fv(cube[1]);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[5]);
	glColor3f(color[4][0], color[4][1], color[4][2]); //up
	glVertex3fv(cube[2]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[7]);
	glVertex3fv(cube[6]);
	glColor3f(color[5][0], color[5][1], color[5][2]); // front
	glVertex3fv(cube[4]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[7]);
#endif /* SHADED_CUBE */
glEnd();
}

int* GL_Cube::getMinMaxX()
{
    return minMaxX;
}

int* GL_Cube::getMinMaxY()
{
    return minMaxY;
}

int* GL_Cube::getMinMaxZ()
{
    return minMaxZ;
}