CommonFunctions: CommonFunctions.cpp
	g++ -I C://SFML-2.5.1/include CommonFunctions.cpp -o CommonFunctions.exe -L C://SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
Bullet: Bullet.cpp
	g++ -I C://SFML-2.5.1/include Bullet.cpp -o Bullet -L C://SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
Asteroid: Asteroid.cpp
	g++ -I C://SFML-2.5.1/include Asteroid.cpp -o Asteroid -L C://SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
Ship: Ship.cpp
	g++ -I C://SFML-2.5.1/include Ship.cpp -o Ship -L C://SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
GameWindow: GameWindow.cpp
	g++ -I C://SFML-2.5.1/include GameWindow.cpp -o GameWindow -L C://SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
main: main.cpp
	g++ -I C://SFML-2.5.1/include main.cpp -o main -L C://SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
all: main.cpp GameWindow.cpp Ship.cpp Asteroid.cpp Bullet.cpp CommonFunctions.cpp
	g++ -I C://SFML-2.5.1/include *.cpp -o game.exe -L C://SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
runGame:
	./game.exe