#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

class Point
{
    private:
        float x;
        float y;
        Point(float x, float y) : x{x}, y{y} {}
    public:
        friend class PointFacotry;
        friend std::ostream& operator<<(std::ostream& os, const Point& obj) {
            return os 
                    << "(" 
                    << obj.x 
                    << "," 
                    << obj.y 
                    << ")" 
                    << std::endl;
        }
};

class PointFacotry
{
    public:
        static Point NewCartesian(float x, float y) {
            return {x, y};
        }
        static Point NewPolar(float r, float theta) {
            return { r * std::cos(theta), r * std::sin(theta) };
        }
};

int main()
{
    auto myPointCart = PointFacotry::NewCartesian(5, 4);
    std::cout << myPointCart << std::endl;
    auto myPointPolar = PointFacotry::NewPolar(5, M_PI_4);
    std::cout << myPointPolar << std::endl;
}