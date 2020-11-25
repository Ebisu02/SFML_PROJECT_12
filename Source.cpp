#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <cmath>

/*8.  f1(x)= sqr(x-3)          f2(x)= 16           коричневый*/

using namespace sf;

int sqr(int x) {
	return x * x;
}



int main() {
	std::cout << "Your lab #11, lets see, what we have\n";
	
	FreeConsole();

	ContextSettings settings;
	settings.antialiasingLevel = 16;

	int scrX = GetSystemMetrics(SM_CXSCREEN);
	int scrY = GetSystemMetrics(SM_CYSCREEN);

	RenderWindow window(VideoMode(scrX, scrY), "Programming lab. work #12", Style::Default, settings);

	while (window.isOpen()) { 
		Event event;

		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(Color(255, 255, 255, 0));

		//Ось Y
		RectangleShape line1(Vector2f(2.f, scrX));
		line1.rotate(0.f);
		line1.setFillColor(Color(0, 0, 0));
		line1.move(scrX/2, 0);
		window.draw(line1);

		//Ось X
		RectangleShape line5(Vector2f(2.f, scrX));
		line5.rotate(90.f);
		line5.setFillColor(Color(0, 0, 0));
		line5.move(scrX, scrY/2);  
		window.draw(line5);


		// y = 16
		RectangleShape line3(Vector2f(2.f, scrX)); 
		line3.rotate(90.f);
		line3.setFillColor(Color(255, 0, 0));
		line3.move(scrX, (scrY/2) - 16);
		window.draw(line3);


		//y = sqr(x - 3) как же я бомбил рот документации SFML(Она вся английская!!!! Я патриот(хз, помойму нет)!!!!), пришлось форумы шерстить об VertexArray
		VertexArray curvamatkaparabola(LinesStrip, 100);
		for (int x = -50, i = 0; x < 50; ++x, ++i){
			int y = (x + 3);
			curvamatkaparabola[i].position = Vector2f((scrX/2) - x, (scrY/2) - sqr(y));
			curvamatkaparabola[i].color = Color(55, 55, 55);
		}
		window.draw(curvamatkaparabola);


		//Закрашиваем(О боже, зачем? =D)
		for (int y = 0; y <= 16; ++y) {
			int bufY = (scrY / 2) - y;
			VertexArray hate(Points, 10);
			if (y == 5 || y > 5){
				for (int i = 0; i < sqrt(y) + 3; ++i) {
					if (i > (sqrt(y) + 3)){
						break;
					}
					int bufX = (scrX / 2) - i + 3;
					hate[i].position = Vector2f(bufX + 3, bufY);
					hate[i].color = Color(88, 60, 50, 225);
				}
				window.draw(hate);
			}
			if (y < 5) {
				for (int i = 0; i < sqrt(y) + 3; ++i) {
					if (i > (sqrt(y) + 3)) {
						break;
					}
					int bufX = (scrX / 2) - i + 3;
					hate[i].position = Vector2f(bufX + 2, bufY);
					hate[i].color = Color(88, 60, 50, 225);
				}
				window.draw(hate);
			}
		}



		//Выводим всю эту байду в окно
		window.display();
	}

	return 0;
}
