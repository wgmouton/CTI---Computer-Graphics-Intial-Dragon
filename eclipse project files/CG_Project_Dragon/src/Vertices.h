/*
 Project    : Computer Graphics OpenGL Semester 1 Project
 Author     : Willem Mouton (H00180920), Charlie van Zyl (H00180839)
 Document   : Vertices.h
 */
float colours[8][3] = {
	{1, 0, 0},
	{0.6, 0, 0},
	{0, 1, 0},
	{0, 0.6, 0},
	{0, 0, 1},
	{0, 0, 0.6},
	{0, 0.6, 0.6},
	{0.6, 0, 0.6},
};

float vertices[100][3] = { { 0.5, 0.5, 0.1 }, { 0.3, 0.5, 0.1 },
		{ 0.1, -0.5, 0.1 }, { 0.3, -0.5, 0.1 }, { 0.0, -0.3, 0.1 },
		{ 0.0, 0.0,	0.1 }, { -0.5, 0.5, 0.1 }, { -0.3, 0.5, 0.1 },
		{ -0.1, -0.5, 0.1 }, { -0.3, -0.5, 0.1 }, { 0.0, -0.3, 0.1 },

		{ 0.5, 0.5, -0.1 }, { 0.3, 0.5, -0.1 }, { 0.1, -0.5, -0.1 },
		{ 0.3, -0.5, -0.1 }, { 0.0, -0.3, -0.1 }, { 0.0, 0.0, -0.1 },
		{ -0.5, 0.5, -0.1 }, { -0.3, 0.5, -0.1 }, { -0.1, -0.5, -0.1 },
		{ -0.3, -0.5, -0.1 }, { 0.0, -0.3, -0.1 },

		{ 0.5,0.3,0.1 }, { -0.5,0.3,0.1 }, { 0.5,-0.5,0.1 },
		{ -0.5,-0.5,0.1 }, { -0.5,-0.3,0.1 }, { 0.5,-0.3,0.1 },
	    { 0.2,0.3,0.1 }, { -0.5,-0.3,0.1 }, { -0.2,-0.3,0.1 },

		{ 0.5,0.3,-0.1 }, { -0.5,0.3,-0.1 }, { 0.5,-0.5,-0.1 },
		{ -0.5,-0.5,-0.1 }, { -0.5,-0.3,-0.1 }, { 0.5,-0.3,-0.1 },
		{ 0.2,0.3,-0.1 }, { -0.5,-0.3,-0.1 }, { -0.2,-0.3,-0.1 },

		{ 0.3, 0.3, 0.1 }, { 0.0, 0.2, 0.1 }, { -0.3, 0.3, 0.1 },

		{ 0.3,0.3,-0.1 }, { 0.0,0.2,-0.1 }, { -0.3,0.3,-0.1 },

		{ 0.5,0.1,0.1 }, { 0.2,0.1,0.1 }, { 0.2,0.0,0.1 },
		{ 0.5,0.0,0.1 }, { 0.4,0.0,0.1 }, { 0.4,-0.5,0.1 },

		{ 0.5,0.1,-0.1 }, { 0.2,0.1,-0.1 }, { 0.2,0.0,-0.1 },
		{ 0.5,0.0,-0.1 }, { 0.4,0.0,-0.1 },	{ 0.4,-0.5,-0.1 },

		{ 0.3,0.0,0.1 }, { 0.3,0.0,-0.1 },
		{ 0.0,-0.5,-0.1 }, { 0.0,-0.5,0.1 },
};

void polygon(int a, int b, int c, int d, int col) {
	glBegin(GL_POLYGON);
	glColor3fv(colours[col]);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}

void curve(float startPoint, float endPoint, float r1, float r2, float a,
		float b, int col) {

	//Variables
	float theta;
	float PI = 3.142;

	glBegin(GL_QUAD_STRIP);
		glColor3fv(colours[col]);
		for (theta = startPoint; theta <= endPoint; theta++) {
			float thetaRad = theta * PI / 180.0;
			glVertex3f(r1 * cos(thetaRad), r1 * sin(thetaRad), a);
			glVertex3f(r2 * cos(thetaRad), r2 * sin(thetaRad), b);
		}
	glEnd();
}
