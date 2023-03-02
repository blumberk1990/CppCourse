#include <iostream>
#include <string>
#include <cmath>

class Point
{
    private:
        float x;
        float y;
        Point(float x, float y) :x{x}, y{y} {}

        class PointFacotry 
        {
            private:
                PointFacotry();
            public:
                static Point NewCartesian(float x, float y) {
                    return { x, y };
                }
                static Point NewPolar(float r, float theta) {
                    return { r* std::cos(theta), r* std::sin(theta) };
                }
        };
    public:
        static PointFacotry Factory;
        friend std::ostream& operator<<(std::ostream& os, Point& obj) {
            return os 
                    << "("
                    << obj.x
                    << ","
                    << obj.y
                    << ")"
                    << std::endl;
        }
};

int main()
{
    auto myPointCart = Point::Factory.NewCartesian(5, 4);
    std::cout << myPointCart << std::endl;
    auto myPointPolar = Point::Factory.NewPolar(5, M_PI_4);
    std::cout << myPointPolar << std::endl;
}