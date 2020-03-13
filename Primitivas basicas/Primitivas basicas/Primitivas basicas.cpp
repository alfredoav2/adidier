// Primitivas basicas.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <SDL.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
#include <math.h>
#include <array>
#include <vector>
#include "Vector2.h"
//Screen dimension constants
int SCREEN_WIDTH = 720;
int SCREEN_HEIGHT = 480;
int tam = 30;
//Starts up SDL and creates window
bool init();
//Frees media and shuts down SDL
void close();
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
//The window renderer
SDL_Renderer* gRenderer = NULL;
bool init() {
	//Initialization flag
	bool success = true;
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else {
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
			printf("Warning: Linear texture filtering not enabled!");
		}
		//Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL) {
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else {
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL) {
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else {
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);


			}
		}
	}
	return success;
}

void close() {
	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;
	SDL_Quit();
}

void SetScreen() {
	if (SCREEN_WIDTH == 0 || SCREEN_HEIGHT == 0) {
		SCREEN_WIDTH = 720;
		SCREEN_HEIGHT = 480;
	}
	if (tam == 0) {
		tam = 32;
	}
}

//void Drawline2(float xa, float ya, float xb, float yb)
//{
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//
//	float m, c, x, y;
//
//	m = (yb - ya) / (xb - xa);
//
//	if (m < 0)
//	{
//		m = m * -1;
//	}
//
//	c = ya - (m * xa);
//
//	x = xa;
//
//	for (y = ya; y<=yb; y++)
//	{
//		SDL_RenderDrawPoint(gRenderer, x, y);
//		x = (y - c) / m;
//		//SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, x);
//	}
//	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//}

//void DrawPlain() {
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	//Dibujamos en y desde la mitad
//	SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
//	SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT, SCREEN_WIDTH / 2, 0);
//	SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH, SCREEN_HEIGHT / 2, 0, SCREEN_HEIGHT / 2);
//	//SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH , SCREEN_HEIGHT / 2);
//	//SDL_RenderDrawLine(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, SCREEN_WIDTH / 2, SCREEN_HEIGHT);
//	for (int i = SCREEN_HEIGHT / 2; i < SCREEN_HEIGHT;) {
//		SDL_SetRenderDrawColor(gRenderer, 6, 4, 20, 50);
//		i += tam;
//		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, SCREEN_HEIGHT - i);
//		SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, i);
//	}
//	//Dibujamos en x desde la mitad
//	//for (int i = SCREEN_WIDTH / 2; i < SCREEN_WIDTH;)
//	//{
//	//i += tam;
//	//SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT / 2);
//	//SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT / 2);
//	//}
//	SDL_SetRenderDrawColor(gRenderer, 0x44, 0x44, 0x44, 0xFF);
//	//for (int i = (SCREEN_WIDTH / 2) + tam; i < SCREEN_WIDTH; i += tam)
//	//{
//	//for (int j = (SCREEN_HEIGHT / 2) + tam; j < SCREEN_HEIGHT; j += tam)
//	//{
//	//SDL_RenderDrawPoint(gRenderer, i, j);
//	//SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, j);
//	//SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH - i, SCREEN_HEIGHT - j);
//	//SDL_RenderDrawPoint(gRenderer, i, SCREEN_HEIGHT - j);
//	//}
//	//}
//}

//void DrawPoint(float x, float y){
//	x = (SCREEN_WIDTH / 2) + (tam * x);
//	y = (SCREEN_HEIGHT / 2) - (tam * y);
//	SDL_SetRenderDrawColor(gRenderer, 0x00, 0xFF, 0xFF, 0xFF);
//	SDL_RenderDrawPoint(gRenderer, x, y);
//}

//void Drawline(float xa, float ya, float xb, float yb){
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	float m, c, x, y;
//	m = (yb - ya) / (xb - xa);
//	c = ya - (m * xa);
//	if (std::abs(m) < 1){
//		y = ya;
//		for (float x = xa; x <= xb; x++){
//			SDL_RenderDrawPoint(gRenderer, x, y);
//			y = m * x + c;
//		}
//		SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//	}
//	else{
//		x = xa;
//		for (y = ya; y <= yb; y++){
//			SDL_RenderDrawPoint(gRenderer, x, y);
//			x = (y - c) / m;
//			//SDL_RenderDrawPoint(gRenderer, SCREEN_WIDTH / 2, x);
//		}
//		SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//	}
//}

//void DDA(float xa, float ya, float xb, float yb){
//	float deno, dx, dy, yin, xin, x, y;
//	int j = 0;
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	dx = xb - xa;
//	dy = yb - ya;
//	if (std::abs(dy) < std::abs(dx)){
//		deno = std::abs(dx);
//	}
//	else if (std::abs(dy) >= std::abs(dx)){
//		deno = std::abs(dy);
//	}
//	xin = dx / deno;
//	yin = dy / deno;
//	x = xa;
//	y = ya;
//	for (int i = 0; i <= deno; i++){
//		SDL_RenderDrawPoint(gRenderer, x, y);
//		x = x + xin;
//		y = y + yin;
//	}
//	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//}

//void Pendiente(float Xa, float Ya, float Xb, float Yb){
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	float x, y;
//	float dx, dy;
//	float p, i;
//	dx = Xb - Xa;
//	dy = Yb - Ya;
//	p = 2 * dy - dx;
//	x = Xa;
//	for (y = Ya; y <= Yb; y++){
//		SDL_RenderDrawPoint(gRenderer, x, y);
//		if (p < 0){
//			x = x + 1;
//			y = y + 1;
//			p = 2 * dy + p;
//		}
//		else if (p >= 0){
//			x = x + 1;
//			y = y + 1;
//			p = 2 * dy - 2 * dx + p;
//		}
//	}
//	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//}

//void Pendiente2(float Xa, float Ya, float Xb, float Yb){
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
//	float x, y;
//	float dx, dy;
//	float p, i;
//	dx = Xb - Xa;
//	dy = Yb - Ya;
//	p = 2 * dx - dy;
//	x = Xa;
//	y = Ya;
//	for (int i = 0; i <= dy; i++){
//		SDL_RenderDrawPoint(gRenderer, x, y);
//		if (p < 0){
//			x = x;
//			y = y + 1;
//			p = 2 * dx + p;
//		}
//		else if (p >= 0){
//			x = x + 1;
//			y = y + 1;
//			p = p + 2 * dx - 2 * dy;
//		}
//	}
//	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//}

void Bresenham(float Xa, float Ya, float Xb, float Yb) {
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	float x = Xa, y = Ya;
	float dx, dy;
	float p, i;
	int signx;
	int signy;
	dx = Xb - Xa;
	dy = Yb - Ya;
	if (dx >= 0) {
		signx = 1;
	}
	else {
		signx = -1;
	}
	if (dy >= 0) {
		signy = 1;
	}
	else {
		signy = -1;
	}
	if (std::abs(dy) <= std::abs(dx)) {
		p = 2 * dy * signy - dx * signx;
		for (int j = 0; j <= dx * signx; j++) {
			if (p < 0) {
				x = x + signx;
				y = y;
				p = p + 2 * dy * signy;
			}
			else if (p >= 0) {
				x = x + signx;
				y = y + signy;
				p = p + (2 * dy * signy) - (2 * dx * signx);
			}
			SDL_RenderDrawPoint(gRenderer, x, y);
		}
	}
	else if (std::abs(dy) > std::abs(dx)) {
		p = 2 * dx * signx - dy * signy;
		for (int j = 0; j <= dy * signy; j++) {
			if (p < 0) {
				x = x;
				y = y + signy;
				p = p + 2 * dx * signx;
			}
			else if (p >= 0) {
				x = x + signx;
				y = y + signy;
				p = p + (2 * dx * signx) - (2 * dy * signy);
			}
			SDL_RenderDrawPoint(gRenderer, x, y);
		}
	}
	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
}
//
//void circunferencia(float R, float Xc, float Yc) {
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
//	float p, x = 0, y = R;
//	p = 1 - R;
//	for (int i = 0; x <= y; i++) {
//		if (p <= 0) {
//			x = x + 1;
//			y = y;
//			p = p + 2 * x + 3;
//		}
//		else {
//			x = x + 1;
//			y = y - 1;
//			p = p + 2 * x - 2 * y + 5;
//		}
//		SDL_RenderDrawPoint(gRenderer, x + Xc, y + Yc);
//		SDL_RenderDrawPoint(gRenderer, -x + Xc, y + Yc);
//		SDL_RenderDrawPoint(gRenderer, -x + Xc, -y + Yc);
//		SDL_RenderDrawPoint(gRenderer, x + Xc, -y + Yc);
//		SDL_RenderDrawPoint(gRenderer, y + Xc, x + Yc);
//		SDL_RenderDrawPoint(gRenderer, -y + Xc, x + Yc);
//		SDL_RenderDrawPoint(gRenderer, -y + Xc, -x + Yc);
//		SDL_RenderDrawPoint(gRenderer, y + Xc, -x + Yc);
//	}
//	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//}
//
//	void Rotate(Vector2* vertex, float angle) {
//		float NuevoX, NuevoY;
//		NuevoX = cos(angle * M_PI / 180) * vertex->getx() - sin(angle * M_PI / 180) * vertex->gety();
//		NuevoY = sin(angle * M_PI / 180) * vertex->getx() + cos(angle * M_PI / 180) * vertex->gety();
//		vertex->setx(NuevoX);
//		vertex->sety(NuevoY);
//	}
//	void Escalar(Vector2* vertex, float escalar) {
//		float NuevoX, NuevoY;
//		NuevoX = vertex->getx() * escalar;
//		NuevoY = vertex->gety() * escalar;
//		vertex->setx(NuevoX);
//		vertex->sety(NuevoY);
//	}
//	void Trasladar(Vector2* vertex, float traslacionX, float traslacionY) {
//		float NuevoX;
//		float NuevoY;
//		NuevoX = vertex->getx() + traslacionX;
//		NuevoY = vertex->gety() + traslacionY;
//		vertex->setx(NuevoX);
//		vertex->sety(NuevoY);
//	}
//	void RotatePoly(std::vector<Vector2*>& vertex, float angle) {
//		for (auto poin : vertex) {
//			Rotate(poin, angle);
//		}
//	}
//	void EscalarPoly(std::vector<Vector2*>& vertex, float escalar) {
//		for (auto poin : vertex) {
//			Escalar(poin, escalar);
//		}
//	}
//	void TrasladarPoly(std::vector<Vector2*>& vertex, float traslacionX, float traslacionY) {
//		for (auto poin : vertex) {
//			Trasladar(poin, traslacionX, traslacionY);
//		}
//	}
//	void DrawPoly(std::vector<Vector2*>& vertex) {
//		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
//		for (int i = 0; i < vertex.size(); i++) {
//			if (i < vertex.size() - 1) {
//				Bresenham(vertex[i]->getx(), vertex[i]->gety(), vertex[i + 1]->getx(), vertex[i + 1]->gety());
//			}
//			else if (i == vertex.size() - 1) {
//				Bresenham(vertex[i]->getx(), vertex[i]->gety(), vertex[0]->getx(), vertex[0]->gety());
//			}
//		}
//		SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//	}
//	
//	void Cuadrado(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4) {
//		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
//		Bresenham(X1, Y1, X2, Y2);
//		Bresenham(X2, Y2, X3, Y3);
//		Bresenham(X3, Y3, X4, Y4);
//		Bresenham(X4, Y4, X1, Y1);
//		SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//	}
//	
//	void Caja(float X1, float Y1, float X2, float Y2, float X3, float Y3, float X4, float Y4) {
//		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
//		std::array<float, 8> VectoresC = { X1,Y1, X2,Y2, X3,Y3, X4,Y4 };
//		Bresenham(X1, Y1, X2, Y2);
//		Bresenham(X2, Y2, X3, Y3);
//		Bresenham(X3, Y3, X4, Y4);
//		SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//	}
int Perriodico(int n, int k) {
	int nuevon = 1;
	int nuevok = 1;
	int nuevaresta = 1;
	int resta = n - k;
	int periodicaFinal;
	if (n == 1) {
		nuevon = 1;
	}
	else{
		for (int i = 1; i <= n; i++) {
			nuevon *= i;
		}
	}
	if (k <= 1) {
		nuevok = 1;
	}
	else {
		for (int i = 1; i <= k; i++) {
		nuevok *= i;
		}
	}
	if (resta <= 1) {
		nuevaresta = 1;
	}
	else {
		for (int i = 1; i <= resta; i++) {
			nuevaresta *= i;
		}
	}
	periodicaFinal = nuevon / (nuevok * nuevaresta);
	/*std::cout << nuevon << std::endl;
	std::cout << nuevok << std::endl;
	std::cout << nuevaresta << std::endl;
	std::cout << periodicaFinal << std::endl;*/
	return periodicaFinal;
}
void BezierConLineas(std::vector<Vector2*>& vertex) {
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	float x, y;
	float xf, yf;
	std::vector<Vector2*>vectorBezier;
	int n = vertex.size() - 1;
	for (float t = 0; t <= 1; t += 0.2) {
		int l = n;
		float sumaDeBezierX = 0;
		float sumaDeBezierY = 0;
		for (float i = 0; i < vertex.size(); i++) {
			float xActual = vertex[i]->getx();
			float yActual = vertex[i]->gety();
			float tConPotencia = std::pow(t, n - l);
			float potenciaDeTMenosUno = std::pow(1 - t, n - i);
			float perriodicoSeparado = Perriodico(n, n - l);
			sumaDeBezierX += (perriodicoSeparado * tConPotencia) * potenciaDeTMenosUno * xActual;
			sumaDeBezierY += (perriodicoSeparado * tConPotencia) * potenciaDeTMenosUno * yActual;
			l -= 1;
		}
		vectorBezier.push_back(new Vector2(sumaDeBezierX, sumaDeBezierY));
		SDL_RenderDrawPoint(gRenderer, sumaDeBezierX, sumaDeBezierY);
	}
	for (int i = 0; i < vectorBezier.size() - 1; i++) {
		Bresenham(vectorBezier[i]->getx(), vectorBezier[i]->gety(), vectorBezier[i + 1]->getx(), vectorBezier[i + 1]->gety());
	}
	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
}
//void BezierConLineas(std::vector<Vector2*>& vertex) {
//	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
//	float x, y;
//	float xf, yf;
//	std::vector<Vector2*>vectorBezier;
//	int n = vertex.size() - 1;
//	for (float t = 0; t <= 1; t += 0.2) {
//		int l = n;
//		float sumaDeBezierX = 0;
//		float sumaDeBezierY = 0;
//		for (float i = 0; i < vertex.size(); i++) {
//			float xActual = vertex[i]->getx();
//			float yActual = vertex[i]->gety();
//			float tConPotencia = std::pow(t, n - l);
//			float potenciaDeTMenosUno = std::pow(1 - t, n - i);
//			float perriodicoSeparado = Perriodico(n, n - l);
//			sumaDeBezierX += (perriodicoSeparado * tConPotencia) * potenciaDeTMenosUno * xActual;
//			sumaDeBezierY += (perriodicoSeparado * tConPotencia) * potenciaDeTMenosUno * yActual;
//			l -= 1;
//		}
//		vectorBezier.push_back(new Vector2(sumaDeBezierX, sumaDeBezierY));
//		SDL_RenderDrawPoint(gRenderer, sumaDeBezierX, sumaDeBezierY);
//	}
//	for (int i = 0; i < vectorBezier.size() - 1; i++) {
//		Bresenham(vectorBezier[i]->getx(), vectorBezier[i]->gety(), vectorBezier[i + 1]->getx(), vectorBezier[i + 1]->gety());
//	}
//	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
//}
void Bezier(float Xa, float Ya, float Xb, float Yb, float Xc, float Yc, float Xd, float Yd) {
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	float px0 = Xa, py0 = Ya;
	float px1 = Xb, py1 = Yb;
	float px2 = Xc, py2 = Yc;
	float px3 = Xd, py3 = Yd;
	float x, y;
	float xf, yf;
	std::vector<Vector2*>vectorBezier;
	int h = Perriodico(4, 0);
	int n=4;
	for (float t = 0; t <= 1; t += 0.2) {
		float m = t + 0.2;
		float tresta = 1 - t;
		x = ((std::pow(tresta, 3)) * px0) + ((3 * t) * ((1 - t) * (1 - t)) * px1) + ((3 * (t * t)) * (1 - t) * px2) + ((t * t * t) * px3);
		y = (((1 - t) * (1 - t) * (1 - t)) * py0) + ((3 * t) * ((1 - t) * (1 - t)) * py1) + ((3 * (t * t)) * (1 - t) * py2) + ((t * t * t) * py3);

		if (t < 1) {
			xf = (((1 - m) * (1 - m) * (1 - m)) * px0) + ((3 * m) * ((1 - m) * (1 - m)) * px1) + ((3 * (m * m)) * (1 - m) * px2) + ((m * m * m) * px3);
			yf = (((1 - m) * (1 - m) * (1 - m)) * py0) + ((3 * m) * ((1 - m) * (1 - m)) * py1) + ((3 * (m * m)) * (1 - m) * py2) + ((m * m * m) * py3);
		}
		//Bresenham(x,y,xf,yf);
		SDL_RenderDrawPoint(gRenderer, x, y);
		std::cout << x << std::endl;
	}
	SDL_SetRenderDrawColor(gRenderer, 0xaa, 0xaa, 0xaa, 0xaa);
}

int main(int argc, char* args[]) {
	SetScreen();
	//Matriz m(2, 3, 2);
	//Matriz m2(2, 3, 1);
	//Matriz mr(2, 3, 1);
	//m.Print();
	//m2.Print();
	//mr.Print();
	//mr = m + m2;
	//m.Print();
	//m2.Print();
	//mr.Print();
	//Start up SDL and create window
	if (!init()) {
		printf("Failed to initialize!\n");
	}
	else {
		//Main loop flag
		bool quit = false;
		//Event handler
		SDL_Event e;

		//While application is running
		while (!quit) {
			//Handle events on queue
			while (SDL_PollEvent(&e) != 0) {
				//User requests quit
				if (e.type == SDL_QUIT) {
					quit = true;
				}
			}
			SDL_RenderClear(gRenderer);
			SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, 0xFF);
			//DrawPlain();
			//Drawline(0, 0, 100, 300);
			//DDA(0, 0, 200, 200);
			//Drawline2(0, 0, 100, 300);
			//Pendiente(0, 0, 100, 200);
			//Pendiente2(20, 10, 100, 200);
			/*Bresenham(100, 200, 500, 0);
			circunferencia(100, 360, 240);*/

		/*	std::vector<Vector2*>vertex;
			vertex.push_back(new Vector2(50, 30));
			vertex.push_back(new Vector2(100, 30));
			vertex.push_back(new Vector2(100, 60));
			vertex.push_back(new Vector2(50, 60));
			RotatePoly(vertex, 10);
			EscalarPoly(vertex, 2);
			TrasladarPoly(vertex, 50, 30);
			DrawPoly(vertex);
			Cuadrado(10, 30, 10, 60, 40, 60, 40, 30);
			Caja(50, 30, 100, 30, 100, 60, 50, 60);*/
			std::vector<Vector2*>vertex;
			vertex.push_back(new Vector2(200, 20));
			vertex.push_back(new Vector2(200, 200));
			vertex.push_back(new Vector2(20, 200));
			vertex.push_back(new Vector2(20, 20));
			BezierConLineas(vertex);
			//Bezier(20, 20, 20, 200, 200, 200, 200, 20);
			SDL_RenderPresent(gRenderer);
		}
	}
	//Free resources and close SDL
	close();
	return 0;
}
// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
