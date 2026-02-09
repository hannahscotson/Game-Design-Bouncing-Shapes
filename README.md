# Game-Design-Bouncing-Shapes
Basic Program: Moving circles and rectangles with different colours and speeds around a window, bouncing off boundaries.

## Program Specification

### Main Objective
- Write a c++/SFML program that reads descriptions of shapes from a configuration file, then draws those shapes to the screen
### Requirements
- Program must read specifications from file
- Shapes must have correct colour, size, initial position and speed
- Shape names must be centred within each shape
- Shapes must bounce off of window boundaries via collisions

### Configuration File Specification
Each line of the configuration file specifies one of the config settings of the assignment program, with the first string in each line being the type of setting that the rest of the line specified. Lines in the config file can be one of the following types, and lines can appear in any order in the file.

Window W H
- This line declares that the SFML Window must be constructed
with width W and height H, each of which will be integers

Font F S R G B
- This lines defines the font which is to be used to draw text
	for this program. The format of the line is as follows: <br />
	Font File		F			std :: string (it will have no spaces) <br />
	Font Size		S			int <br />
	RGB Color		(R,G,B)		int, int, int <br />

Circle N X Y SX SY R G B R
- Defines a CircleShape with: <br />
	Shape Name				N			std :: string <br />
	Initial Position		(X,Y)		float, float <br />
	Initial Speed			(SX,SY)		float, float <br />
	RGB Color				(R,G,B)		int, int, int <br />
	Radius					R			float <br />

Rectangle N X Y SX SY R G B W H
- Defines a RectangleShape with: <br />
	Shape Name			Name		std :: string <br />
  Initial Position	(X,Y)		float, float <br />
	Initial Speed		(SX,SY)		float, float <br />
	RGB Color			(R,G,B)		int, int, int <br />
	Size				(W,H)		float, float <br />
