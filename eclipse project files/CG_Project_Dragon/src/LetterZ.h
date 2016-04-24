/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : LetterZ.h
 */
void front_Z() {
	polygon(6, 0, 22, 23, 1);
	polygon(24, 25, 29, 27, 1);
	polygon(22, 28, 29, 30, 1);
}

void back_Z() {
	polygon(17, 11, 31, 32, 1);
	polygon(33, 34, 38, 36, 1);
	polygon(31, 37, 38, 39, 1);
}

void sides_Z() {
	polygon(6, 17, 32, 23, 1);
	polygon(25, 34, 38, 29, 1);
	polygon(0, 11, 31, 22, 1);
	polygon(24, 33, 36, 27, 1);
	polygon(28, 37, 38, 29, 1);
	polygon(22, 31, 39, 30, 1);
}

void top_Z() {
	polygon(6, 0, 11, 17, 1);
	polygon(23, 22, 31, 32, 1);

}

void bottom_Z() {
	polygon(25, 24, 33, 34, 1);
	polygon(29, 27, 36, 38, 1);
}

void drawZ(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz) {
	glPushMatrix();

		glTranslatef(tx, ty, tz);
		glRotatef(rx, 1, 0, 0);
		glRotatef(ry, 0, 1, 0);
		glRotatef(rz, 0, 0, 1);
		glScalef(sx, sy, sz);

		//Front
		front_Z();

		//Back
		back_Z();

		//Sides
		sides_Z();

		//Top
		top_Z();

		//Bottom
		bottom_Z();

	glPopMatrix();
}
