/*! \file main_display.cpp
	\brief Main function for running the shape management menu

	Details.
*/

#include <iostream>
#include "DisplayFunctions.h"

/// @brief main function
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
			cout << endl << "Goodbye!" << endl << endl;
			break;
		default:
			cout << endl << "Functionality not implemented." << endl << endl;
			break;
		}
	}
	return 0;
}
