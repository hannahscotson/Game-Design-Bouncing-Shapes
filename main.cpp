#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

struct MyShape {
	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::Text text;
	float speedX;
	float speedY;
	bool isCircle;

	// Circle Constructor
	MyShape(std::string name, const sf::Font& font, int fSize, sf::Color fCol,
		float x, float y, float sx, float sy, int r, int g, int b, float radius)
		: speedX(sx), speedY(sy), isCircle(true)
	{
		circle.setRadius(radius);
		circle.setPosition(x, y);
		circle.setFillColor(sf::Color(r, g, b));
		setupText(name, font, fSize, fCol);
	}

	// Rectangle Constructor
	MyShape(std::string name, const sf::Font& font, int fSize, sf::Color fCol,
		float x, float y, float sx, float sy, int r, int g, int b, float w, float h)
		: speedX(sx), speedY(sy), isCircle(false)
	{
		rect.setSize({ w, h });
		rect.setPosition(x, y);
		rect.setFillColor(sf::Color(r, g, b));
		setupText(name, font, fSize, fCol);
	}

	void setupText(std::string name, const sf::Font& font, int size, sf::Color color) {
		text.setString(name);
		text.setFont(font);
		text.setCharacterSize(size);
		text.setFillColor(color);
		sf::FloatRect bounds = text.getLocalBounds();
		text.setOrigin(bounds.left + bounds.width / 2.0f, bounds.top + bounds.height / 2.0f);
	}

	void update(int windowWidth, int windowHeight)
	{
		// Move shape
		if (isCircle) circle.move(speedX, speedY);
		else rect.move(speedX, speedY);

		// Get the current boundaries of the shape
		sf::FloatRect shapeBounds = isCircle ? circle.getGlobalBounds() : rect.getGlobalBounds();

		// Check left/right collisions
		if (shapeBounds.left <= 0 || shapeBounds.left + shapeBounds.width >= windowWidth)
		{
			speedX *= -1;
		}

		// Check top/bottom collisions
		if (shapeBounds.top <= 0 || shapeBounds.top + shapeBounds.height >= windowHeight)
		{
			speedY *= -1;
		}

		// Move text with shape (centred)
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
	std::ifstream file("config.txt");
	if (!file.is_open())
	{
		std::cerr << "Could not open cinfig file!\n";
		return -1;
	}

	// Default values in case file lines are missing
	int wWidth = 1280, wHeight = 720;
	sf::Font myFont;
	int fontSize = 12;
	sf::Color fontColor = sf::Color::White;
	std::vector<MyShape> shapes;

	std::string type;
	while (file >> type)
	{
		if (type == "Window")
		{
			file >> wWidth >> wHeight;
		}
		else if (type == "Font")
		{
			std::string path;
			int r, g, b;
			file >> path >> fontSize >> r >> g >> b;
			if (!myFont.loadFromFile("RobotoRegular-3m4L.ttf"))
			{
				std::cerr << "Font file not found: " << path << "\n";
			}
			fontColor = sf::Color(r, g, b);
		}
		else if (type == "Circle")
		{
			std::string name;
			float x, y, sx, sy, radius;
			int r, g, b;
			file >> name >> x >> y >> sx >> sy >> r >> g >> b >> radius;
			shapes.emplace_back(name, myFont, fontSize, fontColor, x, y, sx, sy, r, g, b, radius);
		}
		else if (type == "Rectangle")
		{
			float x, y, sx, sy, w, h;
			int r, g, b;
			std::string name;
			file >> name >> x >> y >> sx >> sy >> r >> g >> b >> w >> h;
			shapes.emplace_back(name, myFont, fontSize, fontColor, x, y, sx, sy, r, g, b, w, h);
		}
	}

	// Create new window
	sf::RenderWindow window(sf::VideoMode(wWidth, wHeight), "Bouncing Shapes");
	window.setFramerateLimit(60); // 60 FPS

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
			shape.update(wWidth, wHeight);
			shape.draw(window);
		}

		window.display();
	}

	return 0;
}
