#include "GL_Cube.h"

void GL_Cube::reposition(float x, float y, float z)
{
    // reset since they're obsolete at this point
    minMaxX[0] =  32767;
    minMaxX[1] = -32767;
    minMaxY[0] =  32767;
    minMaxY[1] = -32767;
    minMaxZ[0] =  32767;
    minMaxZ[1] = -32767;

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
            {minMaxY[0] = cube[i][1];}
        if(cube[i][1] > minMaxY[1])
            {minMaxY[1] = cube[i][1];}

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
    glColor3fv(colorBuff[0]);
    glVertex3fv(cube[0]);
    glColor3fv(colorBuff[1]);
    glVertex3fv(cube[1]);
    glColor3fv(colorBuff[2]);
    glVertex3fv(cube[2]);
    glColor3fv(colorBuff[3]);
    glVertex3fv(cube[3]);
   
    glColor3fv(colorBuff[3]);
    glVertex3fv(cube[0]);
    glColor3fv(colorBuff[4]);
    glVertex3fv(cube[1]);
    glColor3fv(colorBuff[5]);
    glVertex3fv(cube[5]);
    glColor3fv(colorBuff[2]);
    glVertex3fv(cube[4]);
   
    glColor3fv(colorBuff[0]);
    glVertex3fv(cube[0]);
    glColor3fv(colorBuff[5]);
    glVertex3fv(cube[4]);
    glColor3fv(colorBuff[4]);
    glVertex3fv(cube[7]);
    glColor3fv(colorBuff[1]);
    glVertex3fv(cube[3]);
   
    glColor3fv(colorBuff[5]);
    glVertex3fv(cube[1]);
    glColor3fv(colorBuff[4]);
    glVertex3fv(cube[2]);
    glColor3fv(colorBuff[5]);
    glVertex3fv(cube[6]);
    glColor3fv(colorBuff[4]);
    glVertex3fv(cube[5]);
   
    glColor3fv(colorBuff[5]);
    glVertex3fv(cube[2]);
    glColor3fv(colorBuff[0]);
    glVertex3fv(cube[3]);
    glColor3fv(colorBuff[3]);
    glVertex3fv(cube[7]);
    glColor3fv(colorBuff[4]);
    glVertex3fv(cube[6]);
   
    glColor3fv(colorBuff[4]);
    glVertex3fv(cube[4]);
    glColor3fv(colorBuff[1]);
    glVertex3fv(cube[5]);
    glColor3fv(colorBuff[2]);
    glVertex3fv(cube[6]);
    glColor3fv(colorBuff[5]);
    glVertex3fv(cube[7]);
#else /* flat cube */
	glColor3f(colorBuff[0][0], colorBuff[0][1], colorBuff[0][2]); //behind
	glVertex3fv(cube[0]);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[3]);
	glColor3f(colorBuff[1][0], colorBuff[1][1], colorBuff[1][2]); //bottom
	glVertex3fv(cube[0]);
	glVertex3fv(cube[1]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[4]);
	glColor3f(colorBuff[2][0], colorBuff[2][1], colorBuff[2][2]); //left
	glVertex3fv(cube[0]);
	glVertex3fv(cube[4]);
	glVertex3fv(cube[7]);
	glVertex3fv(cube[3]);
	glColor3f(colorBuff[3][0], colorBuff[3][1], colorBuff[3][2]); //right
	glVertex3fv(cube[1]);
	glVertex3fv(cube[2]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[5]);
	glColor3f(colorBuff[4][0], colorBuff[4][1], colorBuff[4][2]); //up
	glVertex3fv(cube[2]);
	glVertex3fv(cube[3]);
	glVertex3fv(cube[7]);
	glVertex3fv(cube[6]);
	glColor3f(colorBuff[5][0], colorBuff[5][1], colorBuff[5][2]); // front
	glVertex3fv(cube[4]);
	glVertex3fv(cube[5]);
	glVertex3fv(cube[6]);
	glVertex3fv(cube[7]);
#endif /* SHADED_CUBE */
    glEnd();
}

void GL_Cube::hasDied(bool isDead)
{
    for ( int i = 0; i < 6; i ++ )
    {
        for ( int j = 0; j < 3; j ++ )
        {
            if(!isDead)
                {colorBuff[i][j] = color[i][j];}
            else
                {colorBuff[i][j] = colorDead[i][j];}
        }   
    }
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