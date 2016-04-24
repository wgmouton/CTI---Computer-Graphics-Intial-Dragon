/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : LetterM.h
 */
void front_M() {
	polygon(6, 7, 9, 25, 7);
	polygon(0, 1, 3, 24, 7);
	polygon(1, 40, 5, 41, 7);
	polygon(7, 42, 5, 41, 7);
}

void back_M() {
	polygon(17, 18, 20, 34, 7);
	polygon(11, 12, 14, 33, 7);
	polygon(12, 43, 16, 44, 7);
	polygon(18, 45, 16, 44, 7);
}

void sideOuter_M() {
	polygon(0, 11, 33, 24, 7);
	polygon(6, 17, 34, 25, 7);
	polygon(7, 18, 20, 9, 7);
	polygon(1, 12, 14, 3, 7);
}

void sideInner_M() {
	polygon(1, 12, 44, 41, 7);
	polygon(7, 18, 44, 41, 7);
	polygon(40, 43, 16, 5, 7);
	polygon(42, 45, 16, 5, 7);
}

void top_M() {
	polygon(6, 17, 18, 7, 7);
	polygon(0, 11, 12, 1, 7);
}

void bottom_M() {
	polygon(25, 9, 20, 34, 7);
	polygon(24, 3, 14, 33, 7);
}

void drawM(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz) {
	glPushMatrix();

		glTranslatef(tx, ty, tz);
		glRotatef(rx, 1, 0, 0);
		glRotatef(ry, 0, 1, 0);
		glRotatef(rz, 0, 0, 1);
		glScalef(sx, sy, sz);

		//Front
		front_M();

		//Back
		back_M();

		//Sides - Outer
		sideOuter_M();

		//Sides - Inner
		sideInner_M();

		//Top
		top_M();

		//Bottom
		bottom_M();

	glPopMatrix();
}
