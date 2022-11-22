#include <iostream>
#include <fstream>
const double MINIMAL_NONZERO = 1e-3;
const unsigned int MAX_ELEMENTS_COUNT = 300;

class __declspec(dllexport)  MPGeometryItem
{
public:
	virtual void Scale(double) = 0;
	virtual void Write(std::ostream& file) const = 0;
};	

enum shape
{
	cros, box
};


class __declspec(dllexport) MPPoint : public MPGeometryItem {
	double x, y;
	shape Pointshape; //cross, box size d
public:
	void Scale(double s) override { if (s > MINIMAL_NONZERO) { x *= s; y *= s; } };
	virtual void Display() const {};
	void Write(std::ostream& file) const override;
	virtual void Read(const char* path) {};
	friend MPPoint operator * (const MPPoint& left, const double right) {};
	friend MPPoint operator + (const MPPoint& left, const MPPoint& right) {};
	MPPoint();
	MPPoint( double const ix, double const iy, shape const shape = cros );
};

class MPCurve : public MPGeometryItem
{
public:
	virtual void Display() const = 0;
	virtual void Read(const char* path) = 0;
	virtual double Tmin() const = 0;
	virtual double Tmax() const = 0;
	virtual MPPoint Point(double t) const = 0;
};
class MPLine : public MPCurve
{
	MPPoint first, last;
public:
	void Write(std::ostream& file) const override;
	void Scale(double s) override { if (s > MINIMAL_NONZERO) { first.Scale(s); last.Scale(s); } };
	virtual double Tmin() const { return 0.0; };
	virtual double Tmax() const { return 1.0; };
	virtual MPPoint Point(double t) const { return first * (1. - t) + last * t; };
};
class GeometricScene
{
	MPGeometryItem* shapes[MAX_ELEMENTS_COUNT];
	unsigned int shapeIndex;
public:
	void Scale(double);
	void Display() const;
	void Write(const char* path) const;
	void Read(const char* path);
	void AddItem(MPGeometryItem* item) { if (item && (shapeIndex < MAX_ELEMENTS_COUNT)) shapes[shapeIndex++] = item; }
};
