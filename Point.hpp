#ifndef POINT_HPP
#define POINT_HPP

class Point {
public:
	virtual ~Point(){}
};

class DPoint : public Point {
public:
	int x, y;
public:
	DPoint(int X = 0, int Y = 0);
};

#endif