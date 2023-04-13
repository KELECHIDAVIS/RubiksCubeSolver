#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std; 
using namespace sf; 
#define WIDTH 850 
#define HEIGHT 600
#define SQUARESIZE 45
#define FACEOFFSET SQUARESIZE*3
#define	SPACE 20



char cube[6][3][3] = {
	{
		{'R','R','W'},
		{'O','W','O'},
		{'G','G','W'},
	},
	{
		{'R','O','G'},
		{'B','G','Y'},
		{'Y','B','Y'},
	},
	{
		{'R','W','B'},
		{'R','R','G'},
		{'R','G','O'},
	},
	{
		{'O','W','B'},
		{'R','B','Y'},
		{'G','Y','G'},
	},
	{
		{'W','B','Y'},
		{'B','O','R'},
		{'O','Y','O'},
	},

	{
		{'B','W','B'},
		{'O','Y','W'},
		{'W','G','Y'},
	}

	
};




Color getColor(char color)
{
	switch (color)
	{
	case 'W':	
		return Color::White; 
		break; 
	case 'G':
		return Color::Green;
		break;
	case 'R':
		return Color::Red;
		break;
	case 'B':
		return Color::Blue;
		break;
	case 'O':
		return Color(255,140,0);
		break;
	case 'Y':
		return Color::Yellow;
		break;
	}
}
int getHOffset(int face)
{
	switch (face)
	{
	case 4 : //orange
		return -FACEOFFSET- SPACE;
	case 2: //red
		return FACEOFFSET+SPACE;
	case 3: //blue
		return 2*(FACEOFFSET+ SPACE);
	default:
		return 0; 
	}
}
int getVOffset(int face)
{
	switch (face)
	{
	case 0: //white
		return -FACEOFFSET- SPACE;
	case 5: //yellow
		return FACEOFFSET+ SPACE;
	default:
		return 0;
	}
}
void drawFace(RenderWindow &window, char cube[6][3][3]	, int face )
{
	int hoffset = getHOffset(face); // gets the horizontal offset of face 
	int voffset = getVOffset(face); // gets the vertical    offset of face 
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			RectangleShape square; 
			square.setOrigin(SQUARESIZE / 2, SQUARESIZE / 2);
			square.setOutlineColor(Color::Black);
			square.setOutlineThickness(1.5); 
			square.setSize(Vector2f(SQUARESIZE, SQUARESIZE));
			square.setPosition(Vector2f(int(WIDTH / 2.5) - SQUARESIZE + hoffset + (j * SQUARESIZE), HEIGHT / 2 - SQUARESIZE + (i * SQUARESIZE) + voffset));
			square.setFillColor(getColor(cube[face][i][j]));
			window.draw(square); 
		}
	}
}
void makeUpper(char cube[6][3][3], int face)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cube[face][i][j] = toupper(cube[face][i][j]);
		}

	}
}
void printFace(char cube[6][3][3], int face) // enter the index for the face 
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << cube[face][i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void initWhiteFace(char cube[6][3][3])
{
	cout << "ENTER FACE WITH WHITE CENTER IN FOLLOWING ORDER (blue face on top, green on bottom):\n1 2 3\n4 5 6\n7 8 9" << endl << endl;
	// first row 
	cin >> cube[0][0][0] >> cube[0][0][1] >> cube[0][0][2];
	//second row 
	cin >> cube[0][1][0] >> cube[0][1][1] >> cube[0][1][2];
	//third row 
	cin >> cube[0][2][0] >> cube[0][2][1] >> cube[0][2][2];

	// make all of the characters uppercase 
	makeUpper(cube, 0);

}
void initGreenFace(char cube[6][3][3])
{
	cout << "ENTER FACE WITH GREEN CENTER IN FOLLOWING ORDER (white face on top, yellow on bottom):\n1 2 3\n4 5 6\n7 8 9" << endl;
	// first row 
	cin >> cube[1][0][0] >> cube[1][0][1] >> cube[1][0][2];
	//second row 				 
	cin >> cube[1][1][0] >> cube[1][1][1] >> cube[1][1][2];
	//third row 				 
	cin >> cube[1][2][0] >> cube[1][2][1] >> cube[1][2][2];

	// make all of the characters uppercase 
	makeUpper(cube, 1);

}
void initRedFace(char cube[6][3][3])
{
	cout << "ENTER FACE WITH RED CENTER IN FOLLOWING ORDER (white face on top, yellow on bottom):\n1 2 3\n4 5 6\n7 8 9" << endl;
	// first row 
	cin >> cube[2][0][0] >> cube[2][0][1] >> cube[2][0][2];
	//second row				 
	cin >> cube[2][1][0] >> cube[2][1][1] >> cube[2][1][2];
	//third row				 
	cin >> cube[2][2][0] >> cube[2][2][1] >> cube[2][2][2];

	// make all of the characters uppercase 
	makeUpper(cube, 2);

}
void initBlueFace(char cube[6][3][3])
{
	cout << "ENTER FACE WITH BLUE CENTER IN FOLLOWING ORDER (white face on top, yellow on bottom):\n1 2 3\n4 5 6\n7 8 9" << endl;
	// first row 
	cin >> cube[3][0][0] >> cube[3][0][1] >> cube[3][0][2];
	//second row				 
	cin >> cube[3][1][0] >> cube[3][1][1] >> cube[3][1][2];
	//third row				 
	cin >> cube[3][2][0] >> cube[3][2][1] >> cube[3][2][2];

	// make all of the characters uppercase 
	makeUpper(cube, 3);

}
void initOrangeFace(char cube[6][3][3])
{
	cout << "ENTER FACE WITH ORANGE CENTER IN FOLLOWING ORDER (white face on top, yellow on bottom):\n1 2 3\n4 5 6\n7 8 9" << endl;
	// first row 
	cin >> cube[4][0][0] >> cube[4][0][1] >> cube[4][0][2];
	//second row				 
	cin >> cube[4][1][0] >> cube[4][1][1] >> cube[4][1][2];
	//third row				 
	cin >> cube[4][2][0] >> cube[4][2][1] >> cube[4][2][2];

	// make all of the characters uppercase 
	makeUpper(cube, 4);

}
void initYellowFace(char cube[6][3][3])
{
	cout << "ENTER FACE WITH YELLOW CENTER IN FOLLOWING ORDER (green face on top, blue on bottom):\n1 2 3\n4 5 6\n7 8 9" << endl;
	// first row 
	cin >> cube[5][0][0] >> cube[5][0][1] >> cube[5][0][2];
	//second row				 
	cin >> cube[5][1][0] >> cube[5][1][1] >> cube[5][1][2];
	//third row				 
	cin >> cube[5][2][0] >> cube[5][2][1] >> cube[5][2][2];

	// make all of the characters uppercase 
	makeUpper(cube, 5);

}
void initCube(char cube[6][3][3])
{
	cout << "ENTER COLOR OF FACES USING CHARACTER W, G, R, B, O, OR Y TO REFER TO COLOR (upper or lowercase, space doesn't matter)" << endl << endl; ;
	initWhiteFace(cube);
	printFace(cube, 0);

	initGreenFace(cube);
	printFace(cube, 1);

	initRedFace(cube);
	printFace(cube, 2);

	initBlueFace(cube);
	printFace(cube, 3);

	initOrangeFace(cube);
	printFace(cube, 4);

	initYellowFace(cube);
	printFace(cube, 5);
}