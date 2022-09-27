// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
const double MINIMAL_NONZERO = 1e-3;
const unsigned int MAX_ELEMENTS_COUNT = 300;
class GeometryItem
{
public:
    virtual void Scale(double) = 0;
    virtual void Write(std::ostream& file) const = 0;
};
enum shape
{
    cros, box
};

class Point : public GeometryItem {
    double x, y;
    shape Pointshape; //cross, box size d
public:
    void Scale(double s) override { if (s > MINIMAL_NONZERO) { x *= s; y *= s; } };
    virtual void Display() const {};
    void Write(std::ostream& file ) const override;
    virtual void Read(const char* path) {};
    friend Point operator * (const Point& left, const double right) {};
    friend Point operator + (const Point& left, const Point& right) {};
};

void Point::Write(std::ostream& file) const {
    file << "POINT" << x << "" << y << "" << Pointshape << std::endl;
}


class Curve : public GeometryItem
 {
public:
    virtual void Display() const = 0;
    virtual void Read(const char* path) = 0;
    virtual double Tmin() const = 0;
    virtual double Tmax() const = 0;
    virtual Point Point(double t) const = 0;
};

class Line : public Curve 
{
    ::Point first, last;
public:
    void Write(std::ostream& file) const override;
    void Scale(double s) override { if (s > MINIMAL_NONZERO) { first.Scale(s); last.Scale(s); } };
    virtual double Tmin() const { return 0.0; };
    virtual double Tmax() const { return 1.0; };
    virtual ::Point Point(double t) const { return first * (1. - t) + last * t; };
};

void Line::Write(std::ostream& file) const {
    file << "LINE" << std::endl;
    first.Write(file);
    last.Write(file);
}


class GeometricScene 
{
    GeometryItem* shapes[MAX_ELEMENTS_COUNT];
    unsigned int shapeIndex;
public:
    void Scale(double);
    void Display() const;
    void Write(const char* path) const;
    void Read(const char* path);
    void AddItem(GeometryItem* item) { if (item && (shapeIndex < MAX_ELEMENTS_COUNT)) shapes[shapeIndex++] = item; }
};

void GeometricScene::Scale(double s) {
    if (s <= MINIMAL_NONZERO)
        return;
    for (unsigned int I = 0; I < shapeIndex; I++)
        shapes[I]->Scale(s);
}

void GeometricScene::Write(const char* path) const {
    std::ofstream file(path, std::ios::out);
    for (unsigned int I = 0; I < shapeIndex; I++)
        shapes[I]->Write(file);
}

int main()
{


}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.