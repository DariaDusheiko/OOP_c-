#include <iostream>
#include <string>
#include <cstring>   
#include <unordered_set>
#include <cassert>

using namespace std;


class Car_line {
    public:
        Car_line();
        Car_line(double spd, double accel, double turn, double startX, double startY, double time);
        Car_line(const Car_line& other);

        double speed;      
        double acceleration; 
        double turnAngle;  
        double positionX;
        double positionY;
        double startTime;
};

Car_line::Car_line()
{
    speed = 0.0;
    acceleration = 0.0;
    turnAngle = 0.0;
    positionX = 0.0;
    positionY = 0.0;
    startTime = 0.0;
};

Car_line::Car_line(double spd, double accel, double turn, double startX, double startY, double time)
{
    speed = spd;
    acceleration = accel;
    turnAngle = turn;
    positionX = startX;
    positionY = startY;
    startTime = time;
};

Car_line::Car_line(const Car_line& other)
{
    speed = other.speed;
    acceleration = other.acceleration;
    turnAngle = other.turnAngle;
    positionX = other.positionX;
    positionY = other.positionY;
    startTime = other.startTime;
};


int main() {
    {
        Car_line car_line;
        assert(car_line.speed == 0.0);
        assert(car_line.acceleration == 0.0);
        assert(car_line.turnAngle == 0.0);
        assert(car_line.positionX == 0.0);
        assert(car_line.positionY == 0.0);
        assert(car_line.startTime == 0.0);
    }

    Car_line car_line(45.0, -4.0, 55.0, 8.8, 0.0, 78.1);

    assert(car_line.speed == 45.0);
    assert(car_line.acceleration == -4.0);
    assert(car_line.turnAngle == 55.0);
    assert(car_line.positionX == 8.8);
    assert(car_line.positionY == 0.0);
    assert(car_line.startTime == 78.1);

    car_line.speed = 70.0;
    car_line.acceleration = 9.0;
    car_line.positionX = 7.6;
    Car_line car_line_new = car_line;

    assert(car_line_new.speed == 70.0);
    assert(car_line_new.acceleration == 9.0);
    assert(car_line_new.turnAngle == 55.0);
    assert(car_line_new.positionX == 7.6);
    assert(car_line_new.positionY == 0.0);
    assert(car_line_new.startTime == 78.1);

    cout << "All tests done!" << endl;
    return 0;
}
