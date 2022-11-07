#include <iostream>
#include <string>
#include <cmath>
#include <sstream>

class Point
{
    private:
        float x;
        float y;
    protected:
        Point(const float x, const float y) : x{x}, y{y} {}
    public:
        //Factory Method's
        static Point NewCartesian(float x, float y) {
            return {x, y};
        }
        static Point NewPolar(float r, float theta) {
            return { r * std::cos(theta), r * std::sin(theta) };
        }
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

int main() 
{
    auto pointCart = Point::NewCartesian(5, 4);
    std::cout << pointCart;
    auto pointPolar = Point::NewPolar(5, M_PI_4);
    std::cout << pointPolar;

    return 0;
}
