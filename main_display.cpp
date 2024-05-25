#include <iostream>
#include "CQuadrilateral.h"
#include "CRectangle.h"
#include "CRhombus.h"

void menu(void);
void ShowAll();
void AddShape();
void RemoveShape();
void RemoveAll();
Color ShapeColor(int n);

Quadrilateral* ShapeList[50];

int main() {

	for (int i = 0; i < 50; i++)
	{
		ShapeList[i] = NULL;
	}

	int choice = 0;

	while (choice != 5)
	{
		menu();
		cin >> choice;

		switch (choice)
		{
		case 1:
			ShowAll();
			break;
		case 2:
			AddShape();
			break;
		case 3:
			RemoveShape();
			break;
		case 4:
			RemoveAll();
			break;
		case 5:
			cout << "Goodbye" << endl;
			break;
		default:
			cout << "Functionality not implemented" << endl;
			break;
		}
	}
	return 0;
}

void menu(void)
{
	cout << "\n\t Shape management menu\n" << endl;
	cout << "What operation would you like to perform?" << endl;
	cout << "1 - To view all shapes" << endl;
	cout << "2 - To add new shapes" << endl;
	cout << "3 - To remove a shape" << endl;
	cout << "4 - To remove all shapes" << endl;
	cout << "5 - To exit" << endl;
}

void ShowAll()
{
	int i = 0;
	int counter = 0;

	for (int i = 0; i < 50; i++)
	{
		if (ShapeList[i] != NULL)
		{
			cout << endl << "Shape number: " << i << endl;
			ShapeList[i]->Drawing();
			counter++;
		}
	}

	if (counter == 0)
		cout << "The list is empty" << endl;
}

void AddShape()
{
	int i = 0;
	int figureType;

	while (ShapeList[i] != NULL && i < 49)
	{
		i++;

		if (i > 49)
		{
			cout << "The list is full" << endl;
			return;
		}
	}

	cout << "Press 1 to insert a rectangle, 2 to insert a rhombus" << endl;
	cin >> figureType;

	while (figureType < 1 || figureType > 2)
	{
		cout << "Figure does not exist." << endl;
		cout << "Press 1 to insert a rectangle, 2 to insert a rhombus" << endl;
		cin >> figureType;
	}

	if (figureType == 1)
	{
		float h;
		float w;
		int outline;
		int fill;
		Format f;

		cout << "Enter the height of the rectangle:" << endl;
		cin >> h;
		cout << "Enter the width of the rectangle:" << endl;
		cin >> w;
		cout << "Enter the fill color of the rectangle, blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
		cin >> fill;
		while (fill < 0 || fill > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the fill color of the rectangle, blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
			cin >> fill;
		}

		cout << "Enter the outline color of the rectangle: blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
		cin >> outline;
		while (outline < 0 || outline > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the fill color of the rectangle, blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
			cin >> outline;
		}

		f.outline = ShapeColor(outline);
		f.fill = ShapeColor(fill);

		Rectangle* RectP;
		RectP = new Rectangle(w, h, f);
		ShapeList[i] = RectP;

		cout << "Figure successfully inserted at position number " << i << endl;
	}
	else if (figureType == 2)
	{
		float dL;
		float dS;
		int outline;
		int fill;
		Format f;

		cout << "Enter the major diagonal of the rhombus:" << endl;
		cin >> dL;
		cout << "Enter the minor diagonal of the rhombus:" << endl;
		cin >> dS;
		cout << "Enter the fill color of the rhombus, blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
		cin >> fill;
		while (fill < 0 || fill > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the fill color of the rhombus, blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
			cin >> fill;
		}
		
		cout << "Enter the outline color of the rhombus: blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
		cin >> outline;
		while (outline < 0 || outline > 4)
		{
			cout << "You entered a wrong number!" << endl;
			cout << "Enter the fill color of the rhombus, blacK = 0, White = 1, Red = 2, Green = 3, Blue = 4" << endl;
			cin >> outline;
		}

		f.outline = ShapeColor(outline);
		f.fill = ShapeColor(fill);

		Rhombus* RhombP;
		RhombP = new Rhombus(dL, dS, f);
		ShapeList[i] = RhombP;

		cout << "Figure successfully inserted at position number " << i << endl;
	}
}

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
}

void RemoveShape()
{
	int i;
	cout << "Select the number of the shape to delete:" << endl;
	cin >> i;
	if (ShapeList[i] == NULL || i >= 50)
	{
		cout << "The number you entered doesn't exist" << endl;
	}
	else
	{
		delete ShapeList[i];
		ShapeList[i] = NULL;

		cout << "Shape " << i << " successfully deleted" << endl;
	}
}

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
	cout << "All shapes have been deleted" << endl;
}
