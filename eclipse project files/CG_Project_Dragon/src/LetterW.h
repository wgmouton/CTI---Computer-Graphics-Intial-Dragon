/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : LetterW.h
 */
void front_W () {
	polygon(0, 1, 2, 3, 0);
	polygon(3, 2, 4, 5, 0);
	polygon(5, 10, 8, 9, 0);
	polygon(9, 8, 7, 6, 0);
}

void back_W () {
	polygon(11, 12, 13, 14, 0);
	polygon(14, 13, 15, 16, 0);
	polygon(16, 21, 19, 20, 0);
	polygon(20, 19, 18, 17, 0);
}

void sideOuter_W () {
	polygon(6, 17, 20, 9, 0);
	polygon(1, 12, 13, 2, 0);
	polygon(0, 11, 14, 3, 0);
	polygon(7, 18, 19, 8, 0);
}

void sideInner_W () {
	polygon(9, 20, 16, 5, 0);
	polygon(3, 14, 16, 5, 0);
	polygon(8, 19, 21, 10, 0);
	polygon(2, 13, 21, 10, 0);
}

void top_W () {
	polygon(6, 17, 18, 7, 0);
	polygon(0, 11, 12, 1, 0);
}

void bottom_W () {
	polygon(9, 20, 19, 8, 0);
	polygon(3, 14, 13, 2, 0);
}

void drawW(float tx, float ty, float tz, float rx, float ry, float rz, float sx, float sy, float sz) {
	glPushMatrix();

		glTranslatef(tx, ty, tz);
		glRotatef(rx, 1, 0, 0);
		glRotatef(ry, 0, 1, 0);
		glRotatef(rz, 0, 0, 1);
		glScalef(sx, sy, sz);

		//Front
		front_W ();

		//Back
		back_W ();

		//Sides - Outer
		sideOuter_W ();

		//Sides - Inner
		sideInner_W ();

		//Top
		top_W ();

		//Bottom
		bottom_W ();

	glPopMatrix();
}
