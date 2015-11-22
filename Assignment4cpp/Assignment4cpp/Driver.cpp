#include "Shape.h"
#include "Canvas.h"
#include "BorderedCanvas.h"
#include "FramedCanvas.h"
#include "Isosceles.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "RightIsosceles.h"
#include<iostream>

using namespace std;

	void drawHouse()
	{
		// draw a house front view
		FramedCanvas canvas(45, 46, "A Geometric House: Front View");      // a canvas to draw on
		Rectangle chimney(2, 14, "Chimeny on the roof"); // A vertical 14 x 2 chimney
		chimney.draw(4, 7, canvas, 'H');                 // Draw chimney on canvas

		Isosceles roof(21, "House roof");     // A triangular roof of height 21
		roof.draw(1, 1, canvas, '/');              // Draw roof

		Rectangle skylightFrame(9, 5, "Frame around skylight");         // A 9c x 5r skylight frame
		skylightFrame.draw(17, 11, canvas, 'H');                // Draw skylight frame

		Rectangle skylight(7, 3, "skylight");         // A 7c x 3r skylight
		skylight.draw(18, 12, canvas, ' ');                // Draw skylight


		Rectangle front(41, 22, "Front wall");  // A 41c x 22r rectangular front wall
		front.draw(1, 22, canvas, ':');               // draw front wall

		Rectangle leftDoors(7, 15, "Front Left Door");         // A 7c x 15r rectangle door
		leftDoors.draw(22, 28, canvas, 'd');                // Draw left door

		Rectangle rightDoors(7, 15, "Front Right Door");         // A 7c x 15r rectangle door
		rightDoors.draw(30, 28, canvas, 'd');                // Draw right door

		// visually split the two doors
		Rectangle doorsMiddle(1, 15, "Vertical center panel between front doors");
		doorsMiddle.draw(29, 28, canvas, '=');       // draw the middle vertical rectangle

		// windows above front door
		Rectangle doorTop = Rectangle(15, 2, "Top door window");  //  A 4c by 2r rectangle 
		doorTop.draw(22, 24, canvas, 'W');              // Draw top door window


		Rectangle doggyDoor = Rectangle(4, 2, "A rectangle  doggy door");  //  A 4c by 2r rectangle 
		doggyDoor.draw(4, 41, canvas, 'D');              // Draw doggy door

		Rhombus window(7, "Diamond shape window on front wall"); // A rhombus window on front wall
		window.draw(4, 25, canvas, 'O');            // Draw rhombus window

		cout << canvas << endl;            // polymorphic call
		cout << chimney << endl;
		cout << roof << endl;
		cout << skylightFrame << endl;
		cout << skylight << endl;
		cout << front << endl;
		cout << leftDoors << endl;
		cout << rightDoors << endl;
		cout << doorsMiddle << endl;
		cout << doorTop << endl;
		cout << doggyDoor << endl;
		cout << window << endl;

	}
	int main()
	{
		drawHouse();
		system("pause");
		return 0;
	}