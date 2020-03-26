#pragma once
#include <array>
#include <vector>
#include <map>
#include <stdexcept>
#include "Point.h"
#include "Triangle.h"

Triangle::Triangle(const Point & a = { 1, 0 }, const Point & b = { 0, 1 }, const Point & c = { 2, 1 }, const Color & color = Color::RED){
	this.pts[0] = a;
	this.pts[1] = b;
	this.pts[2] = c;
	this.color = color;
	//TODO: Is_valid ekle
}
Triangle::Triangle(const vector<Point> & pts, const Color & color = Color::RED){
	this.pts[0] = pts[0];
	this.pts[1] = pts[1];
	this.pts[2] = pts[2];
	this.color = color;
}
Triangle::Triangle(const array<Point, NUMBER_OF_CORNERS> & pts, const Color & color = Color::RED){
	this.pts[0] = pts[0];
	this.pts[1] = pts[1];
	this.pts[2] = pts[2];
	this.color = color;
}

Point Triangle::getA(void) const noexcept{
	return pts[0];
}

Point Triangle::getB(void) const noexcept{
	return pts[1];
}

Point Triangle::getC(void) const noexcept{
	return pts[2];
}

void Triangle::setA(const Point & pt){
	pts[0] = pt;
}

void Triangle::setB(const Point & pt){
	pts[1] = pt;
}

void Triangle::setC(const Point & pt){
	pts[2] = pt;
}

ColorTriangle::getColor(void) const noexcept {
	return this.color;
}

string Triangle::getColorAsString(void) const noexcept{
	return this.colorToStringMap.at(this.color);
}

double Triangle::getPerimeter(void) const noexcept{
	
	auto result = this.a.distanceTo(this.b);
	result += this.b.distanceTo(this.c);
	result += this.c.distanceTo(this.a);
	return result;
}

double Quadrilateral::printInfo() const noexcept{

	cout << "Quadrilateral" << endl;
	cout << "Number of points";
	cout << this.NUMBER_OF_CORNERS << endl;
	cout << "Points: ";
	cout << "(" << this.a.x	<< "," this.a.y << ") ";
	cout << "(" << this.b.x << "," this.b.y << ") ";
	cout << "(" << this.c.x << "," this.c.y << ")" << endl;
	cout << "Peripheral: " << this.getPerimeter() << endl;
	cout << "Color:" << this.colorToStringMap.at(this.color) << endl;
}
