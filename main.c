#include <GL/glut.h>
#include<stdio.h>
#include "pieces.h"
#include<string.h>
#include<math.h>
#include<unistd.h>
float angle= 0;
float i;
int k=0;
int m,n;
int first;
GLuint displayList_blackArea; //The OpenGL id of the display list
GLuint displayList_whiteArea; //The OpenGL id of the display list
int whitepawn[][2]={{1,0},{1,1},{1,2},{1,3},{1,4},{1,5},{1,6},{1,7}};
int whitepowers[][3]={{0,0,1},{0,1,2},{0,2,3},{0,3,4},{0,4,5},{0,5,3},{0,6,2},{0,7,1}};
int blackpawn[][2]={{6,0},{6,1},{6,2},{6,3},{6,4},{6,5},{6,6},{6,7}};
int blackpowers[][3]={{7,0,1},{7,1,2},{7,2,3},{7,3,4},{7,4,5},{7,5,3},{7,6,2},{7,7,1}};
void drawText( float x, float y, int r, int g, int b, const char *string );
int options();
void PawnDisplay();
void Keypress(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 27:
			exit(0);
	}
}
void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0,(double)w/(double)h,1.0,200);
	gluLookAt(0.0f,5.5f, 15.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
}
void draw_BlackArea()
{
glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glTranslatef(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(1.50f,0.0f,0.0f);
		glVertex3f(1.5f,0.3f,0.0f);
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,-1.5f);
		glVertex3f(0.0f,0.3f,-1.5f);
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(1.5f,0.0f,0.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(0.0f,0.0f,-1.5f);
		glVertex3f(1.50f,0.0f,-1.5f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(1.50f,0.0f,0.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glVertex3f(0.0f,0.0f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.3f,0.0f);
		glVertex3f(1.50f,0.3f,0.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
}
void draw_WhiteArea()
{
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glTranslatef(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(1.50f,0.0f,0.0f);
		glVertex3f(1.5f,0.3f,0.0f);
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(0.0f,0.0f,-1.5f);
		glVertex3f(0.0f,0.3f,-1.5f);
		glVertex3f(0.0f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(1.5f,0.0f,0.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glVertex3f(1.5f,0.3f,0.0f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(0.0f,0.0f,-1.5f);
		glVertex3f(1.50f,0.0f,-1.5f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.05f,0.05f,0.05f);
		glVertex3f(0.0f,0.0f,0.0f);
		glVertex3f(1.50f,0.0f,0.0f);
		glVertex3f(1.5f,0.0f,-1.5f);
		glVertex3f(0.0f,0.0f,-1.5f);
	glEnd();
	glBegin(GL_QUADS);
		glColor3f(0.52f,0.37f,0.26f);
		glVertex3f(0.0f,0.3f,0.0f);
		glVertex3f(1.50f,0.3f,0.0f);
		glVertex3f(1.5f,0.3f,-1.5f);
		glVertex3f(0.0f,0.3f,-1.5f);
	glEnd();
}
void myinit()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glClearColor(0.0f,0.0f,0.2f,1.0f);
//Set up a display list for drawing a cube
	displayList_blackArea = glGenLists(1); //Make room for the display list
	glNewList(displayList_blackArea, GL_COMPILE); //Begin the display list
	draw_BlackArea(); //Add commands for drawing a black area to the display list
	glEndList(); //End the display list
//Set up a display list for drawing a cube
	displayList_whiteArea = glGenLists(2); //Make room for the display list
	glNewList(displayList_whiteArea, GL_COMPILE); //Begin the display list
	draw_WhiteArea(); //Add commands for drawing a black to the display list
	glEndList(); //End the display list
}
void drawScene()
{
	float j;
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-angle, 0.0f, 1.0f, 0.0f);
	glTranslatef(-4*1.5, 0.0, 4*1.5);
	for(j=0.0;j>(-8*1.5);j-=1.5)
	{
		k++;
		for(i=0.0;i<(4*3.0);i+=3.0)
		{
			if(k%2==0)
			{
				glPushMatrix();
				glTranslatef(i,0.0,j);
				glCallList(displayList_blackArea);
				glPopMatrix();
			}
			else
			{
				glPushMatrix();
				glTranslatef(i+1.5,0.0,j);
				glCallList(displayList_blackArea);
				glPopMatrix();
			}
		}
	}
	for(j=0.0;j>(-8*1.5);j-=1.5)
	{
		k++;
		for(i=0.0;i<(4*3.0);i+=3.0)
		{
			if(k%2!=0)
			{
				glPushMatrix();
				glTranslatef(i,0.0,j);
				glCallList(displayList_whiteArea);
				glPopMatrix();
			}
			else
			{
				glPushMatrix();
				glTranslatef(i+1.5,0.0,j);
				glCallList(displayList_whiteArea);
				glPopMatrix();
			}
		}
	}
	PawnDisplay();
	glutSwapBuffers();
}


void update(int value)
{
	angle += 0.5f;
	if (angle > 360)
	{
		angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(25, update, 0);
}

void motion(int x, int y)
{
	if(moving)
	{
		angle1=angle1+(x-startx);
		angle2=angle2+(y-starty);
		startx=x;
		starty=y;
		glutPostRedisplay();
	}
}


void drawText( float x, float y, int r, int g, int b, const char *string )
{
	int j = strlen( string );

	glColor3f(r,g,b );
	glRasterPos2f( x, y );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
	}
}
void display1(void)
{

//glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	drawText(550,600,1,1,1,"PROJECT TITLE:");
	drawText(525,560,1,1,0,"\"PARACHUTE JUMP\"");
	drawText(570,520,1,1,1,"Developed By:");
	drawText(340,480,0,1,0,"SAGAR.S.P");
	drawText(335,440,1,1,1,"(1BY14CS061)");
	drawText(800,480,0,1,0," SARATH ");
	drawText(825,440,1,1,1,"(1BY14CS065)");
	drawText(490.0,400.0,1,1,1,"UNDER THE GUIDANCE OF");
	drawText(450.0,360.0,0,1,1,"Dr.ANIL GN                		 MR.ANAND R");
	drawText(425.0,320.0,0,1,1,"Associate professor            Assistant professor");
	drawText(580.0,280.0,1,1,0,"Dept. of CSE");
	drawText(585.0,240,1,1,0,"BMSIT&M");
	drawText(1030,120,0,1,0,"Press C to continue  ");
	glFlush();
}

void keyboard(unsigned char key,int x,int y)
{
if(key=='c'||key=='C')
{
	glutDestroyWindow(first);

	options();
}

}


int options(int argc,char** argv)
{
	//glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(800,800);
	glutCreateWindow("basic shape");
	myinit();
	PiecesInit();
	glutFullScreen();
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(Keypress);
	glutReshapeFunc(myReshape);
     glutMotionFunc(motion);
	glutTimerFunc(25,update,0);
	glutMainLoop();
	return 0;
}


int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1250,500);
	glutInitWindowPosition(0,0);
	first=glutCreateWindow("MY INTRO");
	glutFullScreen();
	glutDisplayFunc(display1);
	glutReshapeFunc(myReshape);
  	glutKeyboardFunc(keyboard);
  	glutMainLoop();
	return 0;
}
