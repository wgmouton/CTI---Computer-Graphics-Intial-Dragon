/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : LetterX.h
 */
void front_X() {
	polygon(6, 7, 24, 3, 6);
	polygon(0, 1, 25, 9, 6);
}

void back_X() {
	polygon(17, 18, 33, 14, 6);
	polygon(11, 12, 34, 20, 6);
}

void sideLeft_X() {
	polygon(18, 7, 24, 33, 6);
	polygon(17, 6, 3, 14, 6);
}

void sideRight_X() {
	polygon(12, 1, 25, 34, 6);
	polygon(11, 0, 9, 20, 6);
}

void top_X() {
	polygon(6, 7, 18, 17, 6);
	polygon(0, 1, 12, 11, 6);
}

void bottom_X() {
	polygon(25, 9, 20, 34, 6);
	polygon(24, 3, 14, 33, 6);
}

void drawX(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz) {
	glPushMatrix();

		glTranslatef(tx, ty, tz);
		glRotatef(rx, 1, 0, 0);
		glRotatef(ry, 0, 1, 0);
		glRotatef(rz, 0, 0, 1);
		glScalef(sx, sy, sz);

		//Front
		front_X();

		//Back
		back_X();

		//Sides - Left
		sideLeft_X();

		//Sides - Right
		sideRight_X();

		//Top
		top_X();

		//Bottom
		bottom_X();

	glPopMatrix();
}
