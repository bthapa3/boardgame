#include <iostream>
#include<vector>
#include<ctime>
#include<sstream>
#include <string>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <random>
#include <chrono>
#include<windows.h>
class player1 {
public:
	player1(int x,int y) {
		positionx = x;
		positiony = y;
	}
	int positionx;
	int positiony;
};
sf::RectangleShape rectangle;
sf::RectangleShape line1;
sf::RenderWindow abc(sf::VideoMode(800, 800), "ACROSS");
//sf::RenderWindow ab(sf::VideoMode(800, 800), "ACROSS THE ROAD");
sf::CircleShape Circle(20);
sf::CircleShape Circle2(20);
sf::Font Text1;
sf::Text text,text2,text3;
sf::Texture t1;
sf::Texture t2,trophy;
sf::SoundBuffer buffer1, buffer2, buffer3,buffer4;
player1 user1(80,200);
player1 user2(80,280);
int blocked(int x, int y) {

	if (x == 150 && y == 40) { return 1; }
	if (x < 10 || x>710 || y < 40 || y>440) { return 1; }
	else if (x == 710 && y == 40) { return 1; }
	else if (x == 430 && y == 80) { return 1; }
	else if (x == 290 && y == 120) { return 1; }
	else if (x == 570 && y == 160) { return 1; }
	else if (x == 640 && y == 200) { return 1; }
	else if (x == 290 && y == 280) { return 1; }
	else if (x == 570 && y == 320) { return 1; }
	else if (x == 150 && y == 400) { return 1; }
	else if (x == 430 && y == 440) { return 1; }
	else {
		return -1;
	}
   }
void drawb(){
	rectangle.setFillColor(sf::Color::Red);
	rectangle.setPosition(140,40);
	abc.draw(rectangle);
	rectangle.setPosition(700,40);
	abc.draw(rectangle);
	rectangle.setPosition(420,80);
	abc.draw(rectangle);
	rectangle.setPosition(280,120);
	abc.draw(rectangle);
	rectangle.setPosition(560,160);
	abc.draw(rectangle);
	rectangle.setPosition(630,200);
	abc.draw(rectangle);
	rectangle.setPosition(280,280);
	abc.draw(rectangle);
	rectangle.setPosition(560,320);
	abc.draw(rectangle);
	rectangle.setPosition(140,400);
	abc.draw(rectangle);
	rectangle.setPosition(420,440);
	abc.draw(rectangle);
	rectangle.setFillColor(sf::Color::White);



}
void moveup(int score,player1 &x) {
	
	for (int i=0;i<score;i++){
		
		if (blocked(x.positionx,x.positiony-40)==-1) {
			x.positiony = x.positiony - 40;
			
		}
	}
}
void movedown(int score, player1& x) {
	
	for (int i = 0;i < score;i++) {
		
		if (blocked(x.positionx,x.positiony+40)==-1) {
			x.positiony = x.positiony + 40;
		}
	}
}

void wheretodraw() {
	
	rectangle.setSize(sf::Vector2f(70, 40));
	rectangle.setOutlineColor(sf::Color::Blue);
	rectangle.setOutlineThickness(2);
	abc.setFramerateLimit(30);
	if (!Text1.loadFromFile("stocky.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
	}
	text.setFont(Text1);
    text.setPosition(150, 650);
	text2.setFont(Text1);
	text2.setPosition(150, 650);
	for (int i = 1;i <= 10;i++) {
		for (int j = 1;j <= 5;j++) {
			rectangle.setOutlineColor(sf::Color::Red);
			rectangle.setPosition(i * 70, j * 40);
			abc.draw(rectangle);
		}
	}
	for (int i = 1;i <= 10;i++) {
		for (int j = 6;j <= 6;j++) {
			rectangle.setOutlineColor(sf::Color::Blue);
			rectangle.setPosition(i * 70, j * 40 );
			abc.draw(rectangle);
		}
	}
	for (int i = 1;i <= 10;i++) {
		for (int j = 7;j <= 11;j++) {
			rectangle.setOutlineColor(sf::Color::Red);
			rectangle.setPosition(i * 70, j * 40 );
			abc.draw(rectangle);

		}
	}
	drawb();
	Circle.setFillColor(sf::Color::Blue);
	Circle.setPosition(user2.positionx, user2.positiony);
	//abc.draw(Circle);
	Circle2.setFillColor(sf::Color::Red);
	Circle2.setPosition(user1.positionx, user1.positiony);
	//abc.draw(Circle2);
	abc.draw(text);
	if (!t1.loadFromFile("tushar.png")) {
		std::cout << "load failed" << std::endl;
	}
	if (!t2.loadFromFile("sibika.png")) {
		std::cout << "load failed" << std::endl;
	}
	if (!trophy.loadFromFile("trophy.png")) {
		std::cout << "load failed" << std::endl;
	}
	sf::Sprite sp;
	sf::Sprite sp1;
	sf::Sprite troph;
	troph.setTexture(trophy);
	sp.setTexture(t1);
	sp1.setTexture(t2);
	sp.setPosition(user1.positionx, user1.positiony);
	sp1.setPosition(user2.positionx, user2.positiony);
    sp.setScale(0.23,0.22);
	sp1.setScale(0.23, 0.23);
	troph.setPosition(710, 240);
	troph.setScale(0.05, 0.07);
	abc.draw(troph);
	abc.draw(sp);
	abc.draw(sp1);
	
	
  }
int getscore() {
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine generator(seed);

	std::uniform_real_distribution<float> distribution(-4, 4);
	int a = distribution(generator);
	//int a = (rand() % (7) -3);
	std::cout << " Your Dice score is: " << a << std::endl;
	return a;


}

int main()
{
	int i = 0, turn = 0;
	if (!Text1.loadFromFile("stocky.ttf"))
	{
		std::cout << "ERROR::GAME::INITFONTS::Failed to load font!" << "\n";
	}
	text2.setFont(Text1);
	text2.setPosition(150, 650);
	if (!buffer1.loadFromFile("collide.wav")) {
		std::cout << "Error" << std::endl;
	}
	sf::Sound clip1;
	clip1.setBuffer(buffer1);
	if (!buffer2.loadFromFile("okie.wav")) {
		std::cout << "Error" << std::endl;
	}
	sf::Sound clip2;
	clip2.setBuffer(buffer2);
	if (!buffer3.loadFromFile("game.wav")) {
		std::cout << "Error" << std::endl;
	}
	sf::Sound clip3;
	clip3.setBuffer(buffer3);
	if (!buffer4.loadFromFile("start.wav")) {
		std::cout << "Error" << std::endl;
	}
	sf::Sound clip4;
	clip4.setBuffer(buffer4);
	std::string f,input1,input2,start;
	//input1 = "Player 1: Input your name";
	//input2="player 2: Input your name";
	start = "Olivia:A Tushar:B Olivia Starts!!";
	text2.setString(start);
	text3.setFont(Text1);
	clip4.play();
	while (abc.isOpen()) {


		sf::Event event;

		if (i != 5) {
			abc.draw(text2);
			

		}


		wheretodraw();
		drawb();
		line1.setSize(sf::Vector2f(700, 0));
		line1.setPosition(70, 279);
		line1.setOutlineColor(sf::Color::Blue);
		line1.setOutlineThickness(1);
		abc.draw(line1);
		abc.display();
		abc.clear();
		while (abc.pollEvent(event)) {
			switch (event.type) {
			case::sf::Event::KeyReleased:

				if (event.key.code == (sf::Keyboard::A)) {
					if (turn == 0) {
						i = 5;
						int value = getscore();
						f = " Your score is : " + std::to_string(value) + "   Player B turn";
						text.setString(f);
						if (value == 0 && blocked(user2.positionx + 70, user2.positiony) == -1) { user2.positionx = user2.positionx + 70;clip2.play(); }
						else if (value == 0 && blocked(user2.positionx + 70, user2.positiony) == 1) {
							if (user1.positionx <= 640) {
								clip1.play();
							}
						}
						else if (value > 0) { moveup(value, user2); }
						else if (value < 0) { movedown(abs(value), user2); }
						std::cout << user2.positionx << " " << user2.positiony << std::endl;
						turn++;
					}
				}
				else if (event.key.code == (sf::Keyboard::B)) {
					if (turn == 1) {
						int value = getscore();
						f = " Your score is: " + std::to_string(value) + "  Player A turn";
						text.setString(f);
						if (value == 0 && blocked(user1.positionx + 70, user1.positiony) == -1) { user1.positionx = user1.positionx + 70;clip2.play(); }
						else if (value == 0 && blocked(user1.positionx + 70, user1.positiony) == 1) {
							if (user1.positionx <= 640) {
								clip1.play();
							}
						}
						else if (value > 0) { moveup(value, user1); }
						else if (value < 0) { movedown(abs(value), user1); }
						std::cout << user1.positionx << " " << user1.positiony << std::endl;
						turn--;
					}
				}
			}
		}

		switch (event.type) {
		case sf::Event::Closed:
			abc.close();
			break;

		}
		
		abc.clear();

		if (user1.positionx == 710 && user1.positiony == 240) {
			wheretodraw();
			drawb();abc.display();Sleep(1515); abc.close(); }
		if (user2.positionx == 710 && user2.positiony == 240) {
			wheretodraw();
			drawb();abc.display();Sleep(1524);abc.close(); }
	}
    sf::RenderWindow ab(sf::VideoMode(800, 800), "ACROSS ROAD");
	if (user1.positionx == 710 && user1.positiony == 240) {
		
			sf::Event event;
			//abc.close();
		   clip3.play();

			while (ab.isOpen()) {
				while (ab.pollEvent(event)) {
					text3.setString("Tushar won the game");
					text3.setPosition(250, 350);
					sf::Texture t3;
					if (!t3.loadFromFile("tushar.png")) {
						std::cout << "load failed" << std::endl;
					}
					sf::Sprite s3;
					s3.setTexture(t3);
					s3.setPosition(100, 100);
					s3.setScale(1, 1);
					ab.draw(text3);
					ab.draw(s3);

					ab.display();

				switch (event.type) {
					case sf::Event::Closed:
						ab.close();
						abc.close();
						break;

					}
				}
			}
		
	}
	if (user2.positionx == 710 && user2.positiony == 240) {
		
		
		clip3.play();
				//sf::RenderWindow ab(sf::VideoMode(800, 800), "ACROSS THE ROAD");
	               sf::Event event1;
				   while (ab.isOpen()) {
					   while (ab.pollEvent(event1)) {
						   text3.setString("Olivia won the game");
						   text3.setPosition(250, 350);
						   sf::Texture t4;
						   if (!t4.loadFromFile("Sibika.png")) {
							   std::cout << "load failed" << std::endl;
						   }
						   sf::Sprite s4;
						   s4.setTexture(t4);
						   s4.setPosition(100, 100);
						   s4.setScale(1, 1);ab.draw(text3);
						   ab.draw(s4);
						   ab.display();
						  switch (event1.type) {
						   case sf::Event::Closed:
							   ab.close();
							  // abc.close();
							   break;

						   }
					   }
				   }
		    }
	   
			
			
}
	



		
	
