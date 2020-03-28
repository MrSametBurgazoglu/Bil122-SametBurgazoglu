#include <array>
#include <string>
#include <map>
#include <stdexcept>
#include "Point.h"
#include "Quadrilateral.h"

using namespace std;

Quadrilateral::Quadrilateral(const Point & a = { 0, 0 }, const Point & c = { 1, 1 }, const Color & color = Color::GREEN){

	this.pts[0] = a;
	this.pts[1] = Point(a.y, c.x);
	this.pts[2] = c;
	this.pts[3] = Point(a.x, c.y);
	this.color = color;
	if(this.isValid() == false){
		throw invalid_argument("Girdiginiz deger hatali");
	}
}

Quadrilateral::Quadrilateral(const Point & a, double width, double height, const Color & color = Color::GREEN){

	this.pts[0] = a;
	this.pts[1] = Point(a.x+width, a.y);
	this.pts[2] = Point(a.x+width, a.y-height);
	this.pts[3] = Point(a.x, a.y-height);
	this.color = color;
}

Quadrilateral::Quadrilateral(const Point & a, const Point & b, const Point & c, const Point & d, const Color & color = Color::GREEN){
	this.pts[0] = a;
	this.pts[1] = b;
	this.pts[2] = c;
	this.pts[3] = d;
	this.color = color;
	if(this.isValid() == false){
		throw invalid_argument("Girdiginiz deger hatali");
	}
}

Quadrilateral::Quadrilateral(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color = Color::GREEN){
	this.pts[0] = pts[0];
	this.pts[1] = pts[1];
	this.pts[2] = pts[2];
	this.pts[3] = pts[3];
	this.color = color;
	if(this.isValid() == false){
		throw invalid_argument("Girdiginiz deger hatali");
		}
	}

bool Quadrilateral::isValid() const{

	int egim1 = (this.pts[0].x - this.pts[1].x) / (this.pts[0].y - this.pts[1].y);
	int egim2 = (this.pts[1].x - this.pts[2].x) / (this.pts[1].y - this.pts[2].y);
	int egim3 = (this.pts[2].x - this.pts[3].x) / (this.pts[2].y - this.pts[3].y);
	int egim4 = (this.pts[0].x - this.pts[3].x) / (this.pts[0].y - this.pts[3].y);
	if(egim1 != egim2 && egim1 != egim3 && egim2 != egim3){
		return true;
	}
	else{
		return false;
	}
}

Point Quadrilateral::getA(void) const noexcept{
	return pts[0];
}

Point Quadrilateral::getB(void) const noexcept{
	return pts[1];
}

Point Quadrilateral::getC(void) const noexcept{
	return pts[2];
}

Point Quadrilateral::getD(void) const noexcept{
	return pts[4];
}

void Quadrilateral::setA(Point & pt){
	pts[0] = pt;
}

void Quadrilateral::setB(Point & pt){
	pts[1] = pt;
}

void Quadrilateral::setC(Point & pt){
	pts[2] = pt;
}

void Quadrilateral::setD(Point & pt){
	pts[3] = pt;
}

Color Quadrilateral::getColor(void) const noexcept {
	return this.color;
}

string Quadrilateral::getColorAsString(void) const noexcept{
	return this.colorToStringMap.at(this.color);
}

double Quadrilateral::getPerimeter(void) const noexcept{
	
	auto result = this.a.distanceTo(this.b);
	result += this.b.distanceTo(this.c);
	result += this.c.distanceTo(this.d);
	result += this.d.distanceTo(this.a);
	return result;
}
	
void Quadrilateral::printInfo() const noexcept{

	cout << "Quadrilateral" << endl;
	cout << "Number of points";
	cout << this.NUMBER_OF_CORNERS << endl;
	cout << "Points: ";
	cout << "(" << this.a.x	<< "," this.a.y << ") ";
	cout << "(" << this.b.x << "," this.b.y << ") ";
	cout << "(" << this.c.x << "," this.c.y << ") ";
	cout << "(" << this.d.x << "," this.d.y << ")" << endl;
	cout << "Peripheral: " << this.getPerimeter() << endl;
	cout << "Color:" << this.colorToStringMap.at(this.color) << endl;
}



