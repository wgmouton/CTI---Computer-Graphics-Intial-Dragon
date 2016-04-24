/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : LetterG.h
 */
void outerSurface_G(float r1) {
	curve(45, 360, r1, r1, 0.1, -0.1, 4);
}

void innerSurface_G(float r2) {
	curve(45, 360, r2, r2, 0.1, -0.1, 4);
}

void front_G(float r1, float r2) {
	curve(45, 360, r1, r2, 0.1, 0.1, 4);
	polygon(46, 47, 48, 49, 4);
	polygon(49, 50, 51, 24, 4);
}

void back_G(float r1, float r2) {
	curve(45, 360, r1, r2, -0.1, -0.1, 4);
	polygon(52, 53, 54, 55, 4);
	polygon(55, 56, 57, 33, 4);
}

void sides_G() {
	polygon(46, 24, 33, 52, 4);
	polygon(50, 51, 57, 56, 4);
	polygon(47, 48, 54, 53, 4);
}

void top_G() {
	polygon(46, 47, 53, 52, 4);
}

void bottom_G() {
	polygon(24, 51, 57, 33, 4);
	polygon(49, 48, 54, 55, 4);
}

void drawG(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz) {
	//Variables
	float r1 = 0.5;
	float r2 = 0.4;

	glPushMatrix();

		glTranslatef(tx, ty, tz);
		glRotatef(rx, 1, 0, 0);
		glRotatef(ry, 0, 1, 0);
		glRotatef(rz, 0, 0, 1);
		glScalef(sx, sy, sz);


		//G Part 1
		//Outer Surface
		outerSurface_G(r1);

		 //Inner Surface
		innerSurface_G(r2);

		//G Part 2
		//Front
		front_G(r1,r2);

		//Back
		back_G(r1,r2);

		//Sides
		sides_G();

		//Top
		top_G();

		//Bottom
		bottom_G();

	//End Cap
//	polygon(24, 51, 57, 33, 1);

	glPopMatrix();
}
