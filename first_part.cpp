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

        void changeSpeed(double spd);
        void changeAcceleration(double accel);
        void changeTurnAngle(double turn);
        void changeX(double startX);
        void changeY(double startY);
        void changeTime(double time);

        double getPositionX() const { return positionX; }
        double getPositionY() const { return positionY; }
        double getSpeed() const { return speed; }
        double getAcceleration() const { return acceleration; }
        double getAngle() const { return turnAngle; }
        double getTime() const { return startTime; }


    private:
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
    if (spd < 0) {
        spd = 0.0;
    }
        
    if (turn < -360 || turn > 360) {
        turn = 0.0;
    }
        
    if (time < 0) {
        time = 0.0;
    }

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


void Car_line::changeSpeed(double spd)
{
    if (spd < 0) {
        spd = 0.0;
    }
    speed = spd;
}

void Car_line::changeAcceleration(double accel)
{
    acceleration = accel;
}

void Car_line::changeX(double startX)
{
    positionX = startX;
}

void Car_line::changeY(double startY)
{
    positionY = startY;
}

void Car_line::changeTurnAngle(double turn)
{
    if (turn < -360 || turn > 360) {
        turn = 0.0;
    }
    turnAngle = turn;
}
void Car_line::changeTime(double time)
{
    if (time < 0) {
        time = 0.0;
    }
    startTime = time;
}


int main() {
    {
        Car_line car_line;
        assert(car_line.getSpeed() == 0.0);
        assert(car_line.getAcceleration() == 0.0);
        assert(car_line.getAngle() == 0.0);
        assert(car_line.getPositionX()  == 0.0);
        assert(car_line.getPositionY() == 0.0);
        assert(car_line.getTime() == 0.0);
    }

    Car_line car_line(-45, -4.0, 55.0, 8.8, 0.0, 78.1);

    assert(car_line.getSpeed() == 0.0);
    assert(car_line.getAcceleration() == -4.0);
    assert(car_line.getAngle() == 55.0);
    assert(car_line.getPositionX()  == 8.8);
    assert(car_line.getPositionY() == 0.0);
    assert(car_line.getTime() == 78.1);

    car_line.changeSpeed(70.0);
    car_line.changeAcceleration(9.0);
    car_line.changeX(7.6);
    car_line.changeTime(-78.1);
    Car_line car_line_new = car_line;

    assert(car_line_new.getSpeed() == 70.0);
    assert(car_line_new.getAcceleration() == 9.0);
    assert(car_line_new.getAngle() == 55.0);
    assert(car_line_new.getPositionX()  == 7.6);
    assert(car_line_new.getPositionY() == 0.0);
    assert(car_line_new.getTime() == 0.0);

    cout << "All tests done!" << endl;
    return 0;
}
