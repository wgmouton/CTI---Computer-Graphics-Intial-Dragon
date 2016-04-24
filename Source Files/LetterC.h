/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : LetterC.h
 */
void outerSurface_C(float r1) {
	curve(0, 270, r1, r1, 0.1, -0.1, 2);
}

void innerSurface_C(float r2) {
	curve(0, 270, r2, r2, 0.1, -0.1, 3);
}

void front_C(float r1, float r2) {
	curve(0, 270, r1, r2, 0.1, 0.1, 2);
}

void back_C(float r1, float r2) {
	curve(0, 270, r1, r2, -0.1, -0.1, 2);
}

void top_C() {

}

void endCap_C() {
	polygon(58, 59, 55, 49, 3);
	polygon(10, 21, 60, 61, 3);
}

void drawC(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz) {
	//Variables
	float r1 = 0.5;
	float r2 = 0.3;

	glPushMatrix();
	glScalef(sx, sy, sz);

		glPushMatrix();
			glTranslatef(tx, ty, tz);
			glRotatef(rx, 1, 0, 0);
			glRotatef(ry, 0, 1, 0);
			glRotatef(rz, 0, 0, 1);

			//G Part 1
			//Outer Surface
			outerSurface_C(r1);

			 //Inner Surface
			innerSurface_C(r2);

			//Front
			front_C(r1, r2);

			//Back
			back_C(r1, r2);

			//End Cap
			endCap_C();

		glPopMatrix();
	glPopMatrix();
}
