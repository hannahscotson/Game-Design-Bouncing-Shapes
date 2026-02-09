#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

struct MyShape {
	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::Text text;
	float speedX;
	float speedY;
	bool isCircle;

	// Constructor
	MyShape(std::string name, sf::Font& font, sf::Color col, float x, float y, float sx, float sy, bool circleMode)
	{
		isCircle = circleMode;
		speedX = sx;
		speedY = sy;

		// Setup the text
		text = sf::Text(name, font, 18);
		// Centre text on shape
		sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin(bounds.left + bounds.width / 2.0f,
					   bounds.top + bounds.height / 2.0f);

		// Setup the shapes
		if (isCircle) {
			circle.setRadius(50.0f);
			circle.setFillColor(col);
			circle.setPosition(x, y);
		}
		else {
			rect.setSize(sf::Vector2f(100.0f, 100.0f));
			rect.setFillColor(col);
			rect.setPosition(x, y);
		}
	}

	void update()
	{
		// Move shape
		if (isCircle) circle.move(speedX, speedY);
		else rect.move(speedX, speedY);

		// Move text with shape (centred)
		sf::FloatRect shapeBounds = isCircle ? circle.getGlobalBounds() : rect.getGlobalBounds();
		text.setPosition(shapeBounds.left + shapeBounds.width / 2.0f,
						 shapeBounds.top + shapeBounds.height / 2.0f);
	}

	void draw(sf::RenderWindow& window)
	{
		if (isCircle) window.draw(circle);
		else window.draw(rect);
		window.draw(text);
	}

};

int main(int argc, char* argv[])
{
	// Create a new window of size 800 x 600
	const int wWidth = 800, wHeight = 600;
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Bouncing Shapes");
	window.setFramerateLimit(60); // 60 FPS

	// Load a font to display text
	sf::Font myFont;

	// Attempt to load the font from a file
	if (!myFont.loadFromFile("RobotoRegular-3m4L.ttf"))
	{
		// If can't load the font, print an error to the error console and exit
		std::cerr << "Could not load font!\n";
		exit(-1);
	}

	// Create a list to contain all shapes
	std::vector<MyShape> shapes;

	// Create Circles
	shapes.push_back(MyShape("CGreen", myFont, sf::Color::Green, 100.0f, 100.0f, -0.03f, 0.02f, true));
	shapes.push_back(MyShape("CBlue", myFont, sf::Color::Blue, 200.0f, 200.0f, 0.02f, 0.04f, true));
	shapes.push_back(MyShape("CPurple", myFont, sf::Color::Magenta, 300.0f, 300.0f, -0.02f, -0.01f, true));

	// Create Rectangles
	shapes.push_back(MyShape("RRed", myFont, sf::Color::Red, 200.0f, 200.0f, 0.1f, 0.15f, false));
	shapes.push_back(MyShape("RGrey", myFont, sf::Color(100, 100, 100), 300.0f, 250.0f, -0.02f, 0.02f, false));
	shapes.push_back(MyShape("RTeal", myFont, sf::Color(0, 255, 255), 25.0f, 100.0f, -0.02f, -0.02f, false));

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

		// Basic rendering function calls
		window.clear();	

		for (auto& shape : shapes)
		{
			shape.update();
			shape.draw(window);
		}

		window.display();
	}

	return 0;
}
