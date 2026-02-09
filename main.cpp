#include <SFML/Graphics.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
	// Create a new window of size 800 x 600
	const int wWidth = 800, wHeight = 600;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Bouncing Shapes");
	window.setFramerateLimit(60); // 60 FPS

	// Create Circles
	sf::CircleShape CGreen(50);
	CGreen.setFillColor(sf::Color::Green);
	CGreen.setPosition(100.0f, 100.0f);
	float circleMoveSpeed = 1.0f;

	sf::CircleShape CBlue(100);
	CBlue.setFillColor(sf::Color::Blue);
	CBlue.setPosition(200, 200);

	sf::CircleShape CPurple(75);
	CPurple.setFillColor(sf::Color::Magenta);
	CPurple.setPosition(300, 300);

	// Create Rectangles
	sf::RectangleShape RRed(sf::Vector2f(200, 25));
	RRed.setFillColor(sf::Color(255, 0, 0));
	RRed.setPosition(200, 200);
	float rectangleMoveSpeed_x = 1.0f;

	sf::RectangleShape RGrey(sf::Vector2f(50, 100));
	RGrey.setFillColor(sf::Color(100, 100, 100));
	RGrey.setPosition(300, 250);

	sf::RectangleShape RTeal(sf::Vector2f(100, 100));
	RTeal.setFillColor(sf::Color(0, 255, 255));
	RTeal.setPosition(25, 100);

	// Load a font to display text
	sf::Font myFont;

	// Attempt to load the font from a file
	if (!myFont.loadFromFile("RobotoRegular-3m4L.ttf"))
	{
		// If can't load the font, print an error to the error console and exit
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	std::vector<sf::CircleShape> circles;
	for (auto& circle : circles)
	{
		circles.push_back(circle);
	}

	std::vector<sf::RectangleShape> rectangles;
	for (auto& rectangle : rectangles)
	{
		rectangles.push_back(rectangle);
	}

	// Main loop - continues for each frame while window is open
	while (window.isOpen())
	{
		// Event handling
		sf::Event event;
		while (window.pollEvent(event)) // While an event has happened
		{
			// This event triggers when the window is closed
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		// Basic animation - move the shape each frame if it's still in frame
		float sx = -0.03, sy = 0.02;
		CGreen.setPosition(CGreen.getPosition().x + sx, CGreen.getPosition().y + sy);
		sx = 0.02, sy = 0.04;
		CBlue.setPosition(CBlue.getPosition().x + sx, CBlue.getPosition().y + sy);
		sx = -0.02, sy = -0.01;
		CPurple.setPosition(CPurple.getPosition().x + sx, CPurple.getPosition().y + sy);

		sx = 0.1, sy = 0.15;
		RRed.setPosition(RRed.getPosition().x + sx, RRed.getPosition().y + sy);
		sx = -0.02, sy = 0.02;
		RGrey.setPosition(RGrey.getPosition().x + sx, RGrey.getPosition().y + sy);
		sx = -0.02, sy = -0.02;
		RTeal.setPosition(RTeal.getPosition().x + sx, RTeal.getPosition().y + sy);

		// Basic rendering function calls
		window.clear();	

		window.draw(CGreen);
		window.draw(CBlue);
		window.draw(CPurple);

		window.draw(RRed);
		window.draw(RGrey);
		window.draw(RTeal);

		window.display();
	}

	return 0;
}
