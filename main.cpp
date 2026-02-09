#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	// Create a new window of size wxh pixels
	// Top-left of the window is (0,0) and bottom-right is (w,h)
	const int wWidth = 640;
	const int wHeight = 480;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "SFML works!");
	window.setFramerateLimit(60); // 60 FPS

	// Make a shape that we will draw to the screen
	sf::CircleShape circle(50);				// Create a circle shape with radius 50
	circle.setFillColor(sf::Color::Green);	// Set the circle color to green
	circle.setPosition(300.0f, 300.0f);		// Set the top-left position of the circle
	float circleMoveSpeed = 1.0f;			// Used later to move the circle

	//// Make a rectangle
	//float rx = 300;
	//float ry = 200;
	//sf::Vector2f rSize(rx, ry);
	//sf::RectangleShape rect(rSize);
	//rect.setPosition(100, 5);
	//rect.setFillColor(sf::Color(255, 255, 0));
	//rect.setOutlineColor(sf::Color::Red);
	//rect.setOutlineThickness(20);

	//// Create rectangle2
	//sf::RectangleShape rect2(rSize);
	//rect2.setPosition(400, 200);
	//rect2.setFillColor(sf::Color(255, 0, 0));

	// Load a font so we can display some text
	sf::Font myFont;

	// Attempt to load the font from a file
	if (!myFont.loadFromFile("RobotoRegular-3m4L.ttf"))
	{
		// If we can't load the font, print an error to the error console and exit
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	// Set up the text object that will be drawn to the screen
	sf::Text text("Sample Text", myFont, 24);

	// Position the top-left corner of the text so that the text aligns on the bottom
	// Text character size is in pixels, so move the text up from the bottom by its height
	text.setPosition(0, wHeight - (float)text.getCharacterSize());


	std::vector<sf::CircleShape> circles;
	circles.push_back(circle);
	//std::vector<sf::RectangleShape> rectangles;

	//// Make a grid of rectangles
	//for (int x = 0; x < 25; x++)
	//{
	//	for (int y = 0; y < 15; y++)
	//	{
	//		sf::RectangleShape rect(sf::Vector2f(15, 15));
	//		rect.setPosition(x*20, y*20);
	//		rect.setFillColor(sf::Color(x*10, y*10, 0)); // More red in x direction, more green in y direction
	//		rectangles.push_back(rect);
	//	}
	//}

	/*rectangles.push_back(rect);
	rectangles.push_back(rect2);*/

	// Main loop - continues for each frame while window is open
	while (window.isOpen())
	{
		// event handling
		sf::Event event;
		while (window.pollEvent(event)) // While an event has happened
		{
			// This event triggers when the window is closed
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

			// This event is triggered when a key is pressed
			if (event.type == sf::Event::KeyPressed)
			{
				// Print the key that was pressed to the console
				std::cout << "Key pressed with code = " << event.key.code << "\n";

				// Example, what happens when x is pressed
				if (event.key.code == sf::Keyboard::X)
				{
					// Reverse the direction of the circle on the screen
					circleMoveSpeed *= -1.0f;
				}
			}
		}

		// Basic animation - move the circle each frame if it's still in frame
		//float sx = 0.5; // Speed in x direction
		circle.setPosition(circle.getPosition().x + circleMoveSpeed, circle.getPosition().y + 0);

		//rect.rotate(0.1);

		// Basic rendering function calls
		window.clear();			// Clear the window of anything previously drawn
		window.draw(circle);
		/*for (auto& circle : circles)
		{
			window.draw(circle);
		}*/

		/*for (auto& rect : rectangles)
		{
			window.draw(rect);
		}*/

		window.draw(text);		// Draw the text
		window.display();		// Call the window display function

	}

	return 0;
}
