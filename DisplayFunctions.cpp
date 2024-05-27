
/// \file DisplayFunctions.cpp
///	\brief Implementation of the functions used in main_display.cpp
///
///	Details.
///

#include <iostream>
#include "DisplayFunctions.h"

Quadrilateral* ShapeList[50];

/// @brief display the menu with the features available
void menu(void)
{
	cout << endl << "\t _________________________" << endl;
	cout << "\t | Shape management menu |" << endl;
	cout << "\t -------------------------" << endl << endl;
	cout << "What operation would you like to perform?" << endl << endl;
	cout << "\t1 - To view all shapes" << endl;
	cout << "\t2 - To add new shapes" << endl;
	cout << "\t3 - To remove a shape" << endl;
	cout << "\t4 - To remove all shapes" << endl;
	cout << "\t5 - To exit" << endl << endl;
	cout << "Enter a number:\t";
}

/// @brief display the entire list of shapes created
void ShowAll()
{
	int i = 0;
	int counter = 0;

	cout << endl << "\t\tALL SHAPES" << endl << endl;

	for (int i = 0; i < 50; i++)
	{
		if (ShapeList[i] != NULL)
		{
			cout << "------------------------------------------" << endl;
			cout << "Shape number: " << i << endl;
			ShapeList[i]->Drawing();
			counter++;
		}
	}

	if (counter == 0)
		cout << "The list is empty." << endl << endl;
}


/// @brief add a new shape to the list
void AddShape()
{
	int i = 0;
	int figureType;

	while (ShapeList[i] != NULL && i <= 49)
	{
		i++;

		if (i > 49)
		{
			cout << endl << "The list is full. Remove a shape to add a new one." << endl << endl;
			return;
		}
	}

	cout << endl << "\t\tADD SHAPE" << endl;
	cout << endl << "Press 1 to insert a rectangle, 2 to insert a rhombus:  ";
	cin >> figureType;

	while (figureType < 1 || figureType > 2)
	{
		cout << "Figure does not exist." << endl;
		cout << "Press 1 to insert a rectangle, 2 to insert a rhombus:  ";
		cin >> figureType;
	}

	if (figureType == 1)
	{
		float h;
		float w;
		int outline;
		int fill;
		Format f = { k, k };

		cout << endl << "\t\tRectangle" << endl << endl;
		cout << "Enter the height of the rectangle:  ";
		cin >> h;
		cout << "Enter the width of the rectangle:  ";
		cin >> w;
		cout << "Enter the fill color of the rectangle (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
		cin >> fill;
		while (fill < 0 || fill > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the fill color of the rectangle (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
			cin >> fill;
		}

		cout << "Enter the outline color of the rectangle (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
		cin >> outline;
		while (outline < 0 || outline > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the outline color of the rectangle (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
			cin >> outline;
		}

		f.outline = ShapeColor(outline);
		f.fill = ShapeColor(fill);

		Rectangle* RectP;
		RectP = new Rectangle(w, h, f);
		ShapeList[i] = RectP;

		cout << endl << "Figure successfully inserted at position number:  " << i << endl;
	}
	else if (figureType == 2)
	{
		float dL;
		float dS;
		int outline;
		int fill;
		Format f = { k, k };

		cout << endl << "\t\tRhombus" << endl << endl;
		cout << "Enter the major diagonal of the rhombus:  ";
		cin >> dL;
		cout << "Enter the minor diagonal of the rhombus:  ";
		cin >> dS;
		cout << "Enter the fill color of the rhombus (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
		cin >> fill;
		while (fill < 0 || fill > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the fill color of the rhombus (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
			cin >> fill;
		}

		cout << "Enter the outline color of the rhombus (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
		cin >> outline;
		while (outline < 0 || outline > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the outline color of the rhombus (Black = 0, White = 1, Red = 2, Green = 3, Blue = 4):  ";
			cin >> outline;
		}

		f.outline = ShapeColor(outline);
		f.fill = ShapeColor(fill);

		Rhombus* RhombP;
		RhombP = new Rhombus(dL, dS, f);
		ShapeList[i] = RhombP;

		cout << endl << "Figure successfully inserted at position number:  " << i << endl;
	}
}

/// @brief convert from number (user choise) to color
/// @param n number entered by the user
/// @return letter of the corresponding color 
Color ShapeColor(int n)
{
	if (n == 0)
		return k;
	else if (n == 1)
		return w;
	else if (n == 2)
		return r;
	else if (n == 3)
		return g;
	else if (n == 4)
		return b;
	else
		return k; //k (blacK) used as default value
}

/// @brief remove a shape from the list chosen by number by the user
void RemoveShape()
{
	int i;

	cout << endl << "\t\tREMOVE SHAPE" << endl << endl;
	cout << "Select the number of the shape to delete:  ";
	cin >> i;
	if (ShapeList[i] == NULL || i >= 50)
	{
		cout << endl << "The shape with the number you entered doesn't exist." << endl << endl;
	}
	else
	{
		delete ShapeList[i];
		ShapeList[i] = NULL;

		cout << endl << "Shape " << i << " successfully deleted." << endl << endl;
	}
}

/// @brief clear the entire list
void RemoveAll()
{
	for (int i = 0; i < 50; i++)
	{
		if (ShapeList[i] != NULL)
		{
			delete ShapeList[i];
			ShapeList[i] = NULL;
		}
	}
	cout << endl << "All shapes have been deleted." << endl << endl;
}
