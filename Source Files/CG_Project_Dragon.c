/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : CG_Project_Dragon.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <gl\glut.h>
#include <math.h>
#include <stdbool.h>

//Header-------------
#include "vertices.h"
#include "LetterC.h"
#include "LetterG.h"
#include "LetterW.h"
#include "LetterM.h"
#include "LetterX.h"
#include "LetterZ.h"

#define WIDTH 800
#define HEIGHT 800

static float win_theta[3] = {0.0, 0.0, 0.0};
static float win_zome = 0.6;
float pitch0, yaw0;
int mouseX0, mouseY0;

//Rotation Commands for parts
//kbtX, kbtY, kbtZ, kbrX, kbrY, kbrZ, kbsX, kbsY, kbsZ
float kbtX;
float kbtY;
float kbtZ;

float kbrX;
float kbrY;
float kbrZ;

float kbsX = 1;
float kbsY = 1;
float kbsZ = 1;

float increment = 0.1;

bool MousePressed;
bool flymode = false;

float spawnhight = 2.0;

//Pivot Points
float joint_jaw = 0;
float joint_head[2] = { 0.0, 0.0 };
float joint_neck[2] = { 0.0, 0.0 };
float joint_leftLeg = 0;
float joint_rightLeg = 0;
float joint_wings = 10;
float joint_tail[2] = {90.0, 0.0};
float joint_frontBody = 0;
float joint_backBody = 0;

//Other Functions--------------------------------------------------
void printPoints (){
	system("CLS");// Clear the console screen

	printf("Current Increment: ");
	printf("%3.2f\n", increment);

	printf("\nTranslate X: ");
	printf("%3.2f\n", kbtX);
	printf("Translate Y: ");
	printf("%3.2f\n", kbtY);
	printf("Translate Z: ");
	printf("%3.2f\n", kbtZ);

	printf("\nRotate X: ");
	printf("%3.2f\n", kbrX);
	printf("Rotate Y: ");
	printf("%3.2f\n", kbrY);
	printf("Rotate Z: ");
	printf("%3.2f\n", kbrZ);

	printf("\nScale X: ");
	printf("%3.2f\n", kbsX);
	printf("Scale Y: ");
	printf("%3.2f\n", kbsY);
	printf("Scale Z: ");
	printf("%3.2f\n", kbsZ);

	printf("\n\n (");
	printf("%3.1f, ", kbtX);
	printf("%3.1f, ", kbtY);
	printf("%3.1f, ", kbtZ);
	printf("%3.1f, ", kbrX);
	printf("%3.1f, ", kbrY);
	printf("%3.1f, ", kbrZ);
	printf("%3.1f, ", kbsX);
	printf("%3.1f, ", kbsY);
	printf("%3.1f", kbsZ);
	printf(")");
}
void printMenu (){
	printf("List of keys:");
//	printf("\n 1  - Make the dragon fly.");
	printf("\nQ/q - Open/Close mouth.");
	printf("\nA/a - Rotate head horizontally.");
	printf("\nZ/z - Rotate head vertically.");
	printf("\nW/w - Turns the neck horizontally.");
	printf("\nS/s - Rotates the neck vertically.");
	printf("\nE/e - Drops and lowers the back body part.");
	printf("\nD/d - Drops and lowers the front body part.");
	printf("\nR/r - Rotates wings vertically.");
	printf("\nT/t - Rotates the left leg, forwards and backwards.");
	printf("\nG/g - Rotates the left right, forwards and backwards.");
	printf("\nF/f - Spins the tail.");
	printf("\nV/v - Rotates the tail clockwise or anti-clockwise");
	printf("\n+/- - Zoom in and out.");
	printf("\nUse mouse to rotate the dragon.");

}
void transform(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz){
	glTranslatef(tx, ty, tz);
	glRotatef(rx, 1, 0, 0);
	glRotatef(ry, 0, 1, 0);
	glRotatef(rz, 0, 0, 1);
	glScalef(sx, sy, sz);

}

//Smaller Parts-------------------------------------------------
void drawBodyPart(){
	glPushMatrix();
		drawW(0.1, 0.4, 0.0, 0.0, 0.0, 170.0, 0.3, 0.3, 0.3);
		drawW(-0.1, 0.4, 0.0, 0.0, 0.0, -180.0, 0.3, 0.4, 0.3);
		drawW(-0.3, 0.4, 0.0, 0.0, 0.0, -160.0, 0.3, 0.3, 0.3);
		drawC(0.0, 0.0, 0.0, 30.0, 0.0, 45.0, 1.0, 1.0, 1.0);
		drawC(0.0, 0.0, 0.0, -30, 0.0, 45.0, 1.0, 1.0, 1.0);
	glPopMatrix();
}
void drawEyes () {
	glPushMatrix(); //Eye
		transform(-0.2, 0.8, 0.2, -21.0, 0.0, 9.0, 0.4, 0.4, 0.5);
		drawG(-0.1, 0, 0, 0, 180, 49, 0.2, 0.5, 1);
		drawZ(-0.4, 0, 0, 0, 0, 0, 1, 1, 1);
		drawZ(0.4, 0, 0, 0, 0, 0, 1, 1, 1);
	glPopMatrix();
}

//Body Parts----------------------------------------------------
void drawFoot () {
	drawZ(-0.4, 0.0, -0.3, 90.0, 0.0, 0.0, 0.6, 0.4, 0.5);
	drawM(-0.6, 0.0, 0.1, 90.0, 0.0, 90.0, 0.5, 0.7, 0.5);
	drawW(0.5, 0.0, 0.0, 90.0, 0.0, 90.0, 1.0, 1.0, 0.5);
	drawC(0.0, 0.0, 0.0, 90.0, 0.0, 45.0, 1.5, 0.5, 1.0);
}
void drawLeg(){
	drawC(0.0, 0.0, 0.0, 0.0, 0.0, -45.0, 0.7, 1.5, 1.8);
	drawC(0.0, 0.0, 0.0, 0.0, 0.0, -45.0, 0.8, 1.6, 1.0);
}
void drawRightFoot () {
	drawFoot();

	glPushMatrix();
		transform(0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.9, 1.0, 0.9);
		drawFoot();

		glPushMatrix();
			transform(0.0, 0.1, 0.0, 0.0, 0.0, 0.0, 0.8, 1.0, 0.8);
			drawFoot();

			glPushMatrix();
				transform(0.4, 0.3, 0.0, -7.0, 7.0, -30.0, 1.0, 1.1, 1.0);
				drawLeg();

				glPushMatrix();
					transform(-0.6, 0.6, -0.2, 2.0, -23.0, 80.0, 1.0, 1.6, 1.0);
					drawLeg();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
void drawLeftFoot () {
	transform(0.0, 0.0, 0.0, 180.0, 0.0, 0.0, 1.0, 1.0, 1.0);
	drawFoot();

	glPushMatrix();
		transform(0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.9, 1.0, 0.9);
		drawFoot();

		glPushMatrix();
			transform(0.0, -0.1, 0.0, 0.0, 0.0, 0.0, 0.8, 1.0, 0.8);
			drawFoot();

			glPushMatrix();
				transform(0.4, -0.3, 0.0, 7.0, -7.0, 210.0, 1.0, 1.1, 1.0);
				drawLeg();

				glPushMatrix();
					transform(0.6, 0.6, -0.2, -2.0, 23.0, -80.0, 1.0, 1.6, 1.0);
//				transform(kbtX, kbtY, kbtZ, kbrX, kbrY, kbrZ, kbsX, kbsY, kbsZ);
//				transform(-0.6, 0.6, -0.2, 2.0, -23.0, 80.0, 1.0, 1.6, 1.0);
					drawLeg();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}
void drawRightWing (){
	glPushMatrix();
		transform(0.0, 0.0, 0.0, -90.0, 0.0, 0.0, 0.6, 1.0, 0.8);
		drawLeg();

		glPushMatrix();
			glPushMatrix();
			transform(-2.2, -0.2, 0.0, 0.0, 0.0, -96.0, 0.6, 3.3, 1.0);
			drawLeg();

				glPushMatrix();
					transform(2.1, -0.0, 0.0, 0.0, 0.0, 103.0, 0.4, 3.0, 0.9);
					drawLeg();

				glPopMatrix();
			glPopMatrix();

			drawW(-2.2, -0.7, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.8, -1.2, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.5, -0.7, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.4, -1.6, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.1, -1.1, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-0.7, -0.6, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
		glPopMatrix();
	glPopMatrix();

}
void drawLeftWing (){
	glPushMatrix();
	transform(0.0, 0.0, 0.0, 90.0, 0.0, 0.0, 0.6, 1.0, 0.8);
		drawLeg();

		glPushMatrix();

			glPushMatrix();
			transform(-2.2, -0.2, 0.0, 0.0, 0.0, -96.0, 0.6, 3.3, 1.0);
			drawLeg();

				glPushMatrix();
					transform(2.1, -0.0, 0.0, 0.0, 0.0, 103.0, 0.4, 3.0, 0.9);
					drawLeg();

				glPopMatrix();
			glPopMatrix();

			drawW(-2.2, -0.7, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.8, -1.2, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.5, -0.7, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.4, -1.6, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-1.1, -1.1, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
			drawW(-0.7, -0.6, 0.0, 0.0, 0.0, 240.0, 0.8, 0.5, 0.9);
		glPopMatrix();
	glPopMatrix();

}
void drawTail(){
	glPushMatrix();
		transform(0.0, 0.0, -0.9, 0.0, -90.0, 0.0, 1.0, 0.7, 1.0);
		drawBodyPart();
	glPopMatrix();

	glPushMatrix();
		glPushMatrix();
			glPushMatrix();
				transform(0.0, 0.0, -0.3, 0.0, -90.0, 0.0, 1.0, 0.6, 1.0);
				drawBodyPart();
			glPopMatrix();

			glPushMatrix();
				drawX(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.3, 0.3, 0.5);
				drawX(0.0, 0.0, 0.1, 0.0, 0.0, 0.0, 0.4, 0.4, 0.5);
				drawX(0.0, 0.0, 0.2, 0.0, 0.0, 0.0, 0.5, 0.5, 0.5);
				drawX(0.0, 0.0, 0.3, 0.0, 0.0, 0.0, 0.6, 0.6, 0.5);
				drawX(0.0, 0.0, 0.4, 0.0, 0.0, 0.0, 0.7, 0.7, 0.5);
				drawX(0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.8, 0.8, 0.5);
				drawX(0.0, 0.0, 0.6, 0.0, 0.0, 0.0, 0.7, 0.7, 0.5);
				drawX(0.0, 0.0, 0.7, 0.0, 0.0, 0.0, 0.6, 0.6, 0.5);
				drawX(0.0, 0.0, 0.8, 0.0, 0.0, 0.0, 0.5, 0.5, 0.5);
				drawX(0.0, 0.0, 0.9, 0.0, 0.0, 0.0, 0.4, 0.4, 0.5);
				drawX(0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.3, 0.3, 0.5);
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();


}
void drawNeck () {
	glPushMatrix();
		transform(0.9, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.9, 1.6);
		drawBodyPart();
	glPopMatrix();
	glPushMatrix();
		transform(0.3, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.8, 1.4);
		drawBodyPart();
	glPopMatrix();
}
void drawHead() {
	//Nose
	glPushMatrix();
		drawG(-0.8, 0.7, 0.0, 0.0, 0.0, -52.0, 0.5, 0.5, 0.4);
		drawEyes();
	glPopMatrix();
	//Head - Left
	glPushMatrix();
		transform(0.0, 0.4, -0.9, 49.0, 0.0, 0.0, 1.0, 1.0, 1.0);
		drawC(0.0, 0.9, 0.2, -18.0, 0.0, 45.0, 2.2, 0.8, 1.0);
		drawEyes();
	glPopMatrix();

	//Head - Right
	glPushMatrix();
		drawC(0.0, 0.9, 0.2, -18.0, 0.0, 45.0, 2.2, 0.8, 1.0);
		drawEyes();
	glPopMatrix();

	//Top Jaw
	glPushMatrix();
		transform(0.0, 0.5, 0.0, 180.0, 0.0, 0.0, 0.8, 1.0, 0.7);
		//Teeth - Front
		drawW(-0.9, 0.2, 0.0, 0.0, 90.0, 180.0, 0.4, 0.3, 0.5);
		//Teeth - Right
		drawW(-0.7, 0.2, 0.3, 180.0, 24.0, 0.0, 0.5, 0.5, 0.5);
		drawW(-0.3, 0.2, 0.4, 180.0, 9.0, 0.0, 0.6, 0.3, 0.5);
		drawW(0.2, 0.2, 0.4, 0.0, 6.0, 180.0, 0.6, 0.3, 0.5);
		//Teeth - Left
		drawW(-0.7, 0.2, -0.3, 0.0, 24.0, 180.0, 0.5, 0.5, 0.5);
		drawW(-0.3, 0.2, -0.4, 0.0, 9.0, 180.0, 0.6, 0.3, 0.5);
		drawW(0.2, 0.2, -0.4, 0.0, -6.0, 180.0, 0.6, 0.3, 0.5);
		//Jaw
		drawC(0.0, 0.0, 0.0, 90.0, 0.0, 45.0, 2.2, 1.0, 1.0);
	glPopMatrix();
	//Bottom Jaw Connection
	glPushMatrix();
		drawC(1.1, 0.2, 0.0, 90.0, 27.0, 45.0, 0.6, 1.2, 0.7);
	glPopMatrix();
	//Bottom Jaw
	glPushMatrix();
		transform(0.6, 0.0, 0.0, 0.0, 0.0, joint_jaw, 1.0, 1.0, 1.0); //Joint Needed
		transform(-0.6, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
		//Teeth - Front
		drawW(-0.9, 0.2, 0.0, 0.0, 90.0, 180.0, 0.4, 0.3, 0.5);
		//Teeth - Right
		drawW(-0.7, 0.2, 0.3, 180.0, 24.0, 0.0, 0.5, 0.5, 0.5);
		drawW(-0.3, 0.2, 0.4, 180.0, 9.0, 0.0, 0.6, 0.3, 0.5);
		drawW(0.2, 0.2, 0.4, 0.0, 6.0, 180.0, 0.6, 0.3, 0.5);
		//Teeth - Left
		drawW(-0.7, 0.2, -0.3, 0.0, 24.0, 180.0, 0.5, 0.5, 0.5);
		drawW(-0.3, 0.2, -0.4, 0.0, 9.0, 180.0, 0.6, 0.3, 0.5);
		drawW(0.2, 0.2, -0.4, 0.0, -6.0, 180.0, 0.6, 0.3, 0.5);
		//Jaw
		drawC(0.0, 0.0, 0.0, 90.0, 0.0, 45.0, 2.2, 1.0, 1.0);
	glPopMatrix();
}


//Draw Main Body------------------------------------------------
void drawBody() {
	glPushMatrix();
		transform(2.0, spawnhight, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
		glPushMatrix();
			//Draw Back Legs----------------------------------------------------
			glPushMatrix();
				transform(1.0, -2.0, 0.8, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
				drawRightFoot();
			glPopMatrix();

			glPushMatrix();
				transform(1.0, -2.0, -0.8, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
				drawLeftFoot();
			glPopMatrix();

			glPushMatrix();
				transform(0.9, 0.0, 0.0, 0.0, 0.0, joint_backBody, 1.0, 1.0, 1.0);

				glPushMatrix();
					//Draw Back Body---------------------------------------------
					glPushMatrix();
						transform(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 1.2, 1.2);
						drawBodyPart();
					glPopMatrix();

					glPushMatrix();
						transform(2.2, 0.0, 0.0, joint_tail[1], joint_tail[0], 0.0, 1.0, 1.0, 1.0);

						//Draw Tail---------------------------------------------
						drawTail();
					glPopMatrix();

					glPushMatrix();
						transform(-2.6, 0.0, 0.0, 0.0, 0.0, joint_frontBody, 1.0, 1.0, 1.0);

						glPushMatrix();
							//Draw Front Body-----------------------------------
							glPushMatrix();
								transform(0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.0, 1.2, 1.2);
								drawBodyPart();
							glPopMatrix();

							//Draw Wings----------------------------------------
							glPushMatrix();
								transform(0.0, 0.0, 0.0, -joint_wings, 0.0, 0.0, 1.0, 1.0, 1.0);
								transform(0.9, 0.4, 0.9, 0.0, 34.0, 0.0, 1.0, 1.0, 1.0);
								drawRightWing();
							glPopMatrix();
							glPushMatrix();
								transform(0.0, 0.0, 0.0, joint_wings, 0.0, 0.0, 1.0, 1.0, 1.0);
								transform(0.9, 0.4, -0.9, 0.0, -34.0, 0.0, 1.0, 1.0, 1.0);
								drawLeftWing();
							glPopMatrix();

							//Draw Front Legs-----------------------------------
							glPushMatrix();
								transform(0.0, 0.0, 0.0, 0.0, 0.0, joint_leftLeg, 1.0, 1.0, 1.0);
								transform(-0.5, -2.0, 0.8, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
								drawRightFoot();
							glPopMatrix();
							glPushMatrix();
								transform(0.0, 0.0, 0.0, 0.0, 0.0, joint_rightLeg, 1.0, 1.0, 1.0);
								transform(-0.5, -2.0, -0.8, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
								drawLeftFoot();
							glPopMatrix();

							glPushMatrix();
								transform(-2.9, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);
								transform(0.0, 0.0, 0.0, 0.0, joint_neck[0], joint_neck[1], 1.0, 1.0, 1.0);

								//Draw Neck-------------------------------------
								drawNeck();

								glPushMatrix();
									transform(0.0, 0.0, 0.0, 0.0, joint_head[0], joint_head[1], 1.0, 1.0, 1.0);
									transform(-0.6, -0.7, 0.0, 0.0, 0.0, 0.0, 1.0, 1.0, 1.0);

									//Draw Head---------------------------------
									drawHead();
								glPopMatrix();
							glPopMatrix();
						glPopMatrix();
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
}

//void fly() {
//	if (flymode) {
//		int i = 0;
//		for (i = 0; i <= 20; i++) {
//
//			if (joint_wings > -20)
//				joint_wings -= 2;
//			if (joint_wings < 36)
//				joint_wings += 2;
//		}
//	} else {
//		flymode = false;
//	}
//}
//Draw Other----------------------------------------------------
void drawFloor () {
	glPushMatrix();
		glTranslatef(0, -0.05, 0); //draw slightly below y=0 so we can see grid
		glBegin(GL_POLYGON);
			glColor3f(.75,.75,.75);
			glVertex3f(-10,0,10);
			glVertex3f(-10,0,-10);
			glVertex3f(10,0,-10);
			glVertex3f(10,0,10);
		glEnd();
	glPopMatrix();
}

void drawAxes() {
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES); //x axis
	glVertex3f(-15.0, 0.0, 0.0);
	glVertex3f(15.0, 0.0, 0.0);
	glEnd();

	glBegin(GL_LINES); //y axis
	glVertex3f(0.0, -2.0, 0.0);
	glVertex3f(0.0, 15.0, 0.0);
	glEnd();

	glBegin(GL_LINES); //z axis
	glVertex3f(0.0, 0.0, -15.0);
	glVertex3f(0.0, 0.0, 15.0);
	glEnd();
}

//Input Functions---------------------------------------------------------
void mouseMotion(int x, int y)
{
	// Called when the Mouse is moved with left button down
	win_theta[0] = pitch0 + (y - mouseY0);
	win_theta[1] = yaw0 + (x - mouseX0);

	glutPostRedisplay();
}

void mouseClick(int button, int state, int x, int y) {
//	 Called on button press or release
	switch (state) {
	case GLUT_DOWN:
		MousePressed = true;
		pitch0 = win_theta[0];
		yaw0 = win_theta[1];
		mouseX0 = x;
		mouseY0 = y;
		break;
	default:
	case GLUT_UP:
		MousePressed = false;
		break;
	}
}
/*
void keyboardDev(unsigned char key, int x, int y) {
	switch (key) {
	case 'z':
		kbrX++;
		break;
	case 'Z':
		kbrX--;
		break;
	case 'x':
		kbrY++;
		break;
	case 'X':
		kbrY--;
		break;
	case 'c':
		kbrZ++;
		break;
	case 'C':
		kbrZ--;
		break;
	case 'v':
		kbrX += 10;
		break;
	case 'V':
		kbrX -= 10;
		break;
	case 'b':
		kbrY += 10;
		break;
	case 'B':
		kbrY -= 10;
		break;
	case 'n':
		kbrZ += 10;
		break;
	case 'N':
		kbrZ -= 10;
		break;
	case 'a':
		kbtX = kbtX + increment;
		break;
	case 'A':
		kbtX = kbtX - increment;
		break;
	case 's':
		kbtY = kbtY + increment;
		break;
	case 'S':
		kbtY = kbtY - increment;
		break;
	case 'd':
		kbtZ = kbtZ + increment;
		break;
	case 'D':
		kbtZ = kbtZ - increment;
		break;
	case 'q':
		kbsX = kbsX + increment;
		break;
	case 'Q':
		kbsX = kbsX - increment;
		break;
	case 'w':
		kbsY = kbsY + increment;
		break;
	case 'W':
		kbsY = kbsY - increment;
		break;
	case 'e':
		kbsZ = kbsZ + increment;
		break;
	case 'E':
		kbsZ = kbsZ - increment;
		break;
	case ',':
		increment = increment + 0.1;
		break;
	case '.':
		increment = increment - 0.1;
		break;
	case '+':
		win_zome+= 0.2;
		break;
	case '-':
		win_zome-= 0.2;
		break;
	case 'm':
		kbtX = 0;
		kbtY = 0;
		kbtZ = 0;
		kbrX = 0;
		kbrY = 0;
		kbrZ = 0;
		kbsX = 1;
		kbsY = 1;
		kbsZ = 1;
		increment = 0.1;
		break;
	case ' ':
		printPoints();
		break;
		//Official actions
	case 'p': //Rotate Jaw
		if (joint_jaw < 35)
			joint_jaw += 5;
		break;
	case 'P': //Rotate Jaw
		if (joint_jaw > 0)
			joint_jaw -= 5;
		break;
	case 'o': //Rotate Head Y
		if (joint_head[0] < 15)
			joint_head[0] += 5;
		break;
	case 'O': //Rotate Head Y
		if (joint_head[0] > -15)
			joint_head[0] -= 5;
		break;
	case 'i': //Rotate Head Z
		if (joint_head[1] < 30)
			joint_head[1] += 5;
		break;
	case 'I': //Rotate Head Z
		if (joint_head[1] > -35)
			joint_head[1] -= 5;
		break;
	case 'u': //Rotate Neck Y
			if (joint_neck[0] < 25)
				joint_neck[0] += 5;
			break;
		case 'U': //Rotate Neck Y
			if (joint_neck[0] > -25)
				joint_neck[0] -= 5;
			break;
		case 'y': //Rotate Neck Z
			if (joint_neck[1] < 100)
				joint_neck[1] += 5;
			break;
		case 'Y': //Rotate Neck Z
			if (joint_neck[1] > -30)
				joint_neck[1] -= 5;
			break;
	}
	glutPostRedisplay();
	printPoints();
}
*/
void keyboard(unsigned char key, int x, int y){
	switch (key) {
	case '+':
		win_zome += 0.2;
		break;
	case '-':
		win_zome -= 0.2;
		break;
	case '1':
		flymode = true;
		break;
	//Official actions
	case 'q': //Rotate Jaw
		if (joint_jaw < 35)
			joint_jaw += 5;
		break;
	case 'Q': //Rotate Jaw
		if (joint_jaw > 0)
			joint_jaw -= 5;
		break;
	case 'a': //Rotate Head Y
		if (joint_head[0] < 15)
			joint_head[0] += 5;
		break;
	case 'A': //Rotate Head Y
		if (joint_head[0] > -15)
			joint_head[0] -= 5;
		break;
	case 'z': //Rotate Head Z
		if (joint_head[1] < 30)
			joint_head[1] += 5;
		break;
	case 'Z': //Rotate Head Z
		if (joint_head[1] > -35)
			joint_head[1] -= 5;
		break;
	case 'w': //Rotate Neck Y
		if (joint_neck[0] < 20)
			joint_neck[0] += 5;
		break;
	case 'W': //Rotate Neck Y
		if (joint_neck[0] > -20)
			joint_neck[0] -= 5;
		break;
	case 's': //Rotate Neck Z
		if (joint_neck[1] < 15)
			joint_neck[1] += 5;
		break;
	case 'S': //Rotate Neck Z
		if (joint_neck[1] > -15)
			joint_neck[1] -= 5;
		break;
	case 'e': //Rotate Back Body Z
		if (joint_backBody > -70)
			joint_backBody -= 5;
		break;
	case 'E': //Rotate Back Body Z
		if (joint_backBody < 0)
			joint_backBody += 5;
		break;
	case 'd': //Rotate Front Body Z
		if (joint_frontBody > -10)
			joint_frontBody -= 5;
		break;
	case 'D': //Rotate Front Body Z
		if (joint_frontBody < 0)
			joint_frontBody += 5;
		break;
	case 'r': //Rotate Wings
		if (joint_wings > -20)
			joint_wings -= 2;
		break;
	case 'R': //Rotate Wings
		if (joint_wings < 36)
			joint_wings += 2;
		break;
	case 't': //Rotate Left Leg
		if (joint_leftLeg > -20)
			joint_leftLeg -= 2;
		break;
	case 'T': //Rotate Left Leg
		if (joint_leftLeg < 40)
			joint_leftLeg += 2;
		break;
	case 'g': //Rotate Left Leg
		if (joint_rightLeg > -20)
			joint_rightLeg -= 2;
		break;
	case 'G': //Rotate Left Leg
		if (joint_rightLeg < 40)
			joint_rightLeg += 2;
		break;
	/*case 'f': //Rotate Tail Y
		if (joint_tail[0] < 110)
			joint_tail[0] += 5;
		break;
	case 'F': //Rotate Tail Y
		if (joint_tail[0] > -70)
			joint_tail[0] -= 5;
		break;*/
	case 'v': //Rotate Tail Z
		if (joint_tail[1] < 100)
			joint_tail[1] += 5;
		break;
	case 'V': //Rotate Tail Z
		if (joint_tail[1] > 0)
			joint_tail[1] -= 5;
		break;
	}
	glutPostRedisplay();
}

void reshapeCallBack(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		if (w <= h)
			glOrtho(-4.0, 4.0, -4.0 * (float) h / (float) w,
				4.0 * (float) h / (float) w, -10.0, 10.0);
		else
			glOrtho(-2.0 * (float) w / (float) h,
				2.0 * (float) w / (float) h, -2.0, 2.0, -10.0, 10.0);
//		gluLookAt(0, 0, 1, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
}

void viewControll() {
	//Rotate everything
	glRotatef(win_theta[0], 1.0, 0.0, 0.0);
	glRotatef(win_theta[1], 0.0, 1.0, 0.0);
	glRotatef(win_theta[2], 0.0, 0.0, 1.0);

	//zoom (NB glOrtho projection)
	glScalef(win_zome,win_zome,win_zome);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	viewControll();

	drawBody();

	drawFloor();
	drawAxes();

//	fly();
	glFlush();
	glutSwapBuffers();

}

int main(int argc, char ** args) {
	printMenu();
	glutInit(&argc, args);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("CG Project Dragon - Willem Mouton, Charlie van Zyl"); //create window
	glEnable(GL_DEPTH_TEST);

	glutReshapeFunc(reshapeCallBack);
	glutDisplayFunc(display); //display function

	//Input Functions.
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouseClick);
	glutMotionFunc(mouseMotion);

	glutMainLoop(); //call registered functions
	return 0;
}
