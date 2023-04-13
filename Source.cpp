/*#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>*/
#include "util.h"




using namespace std; 
using namespace sf; 
int main()
{
	// face order is going to be W G R B O Y 
	
	//initCube(cube); 

	sf::RenderWindow window( sf::VideoMode(WIDTH, HEIGHT),"Cube Solver" ); // the visual representation of the cube
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(Color(190,165,115));
        for (int i = 0; i < 6; i++)
        {
            drawFace(window, cube, i); 
        }
        window.display();
    }

	
	return 0; 
}