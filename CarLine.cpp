#pragma once
#include <iostream>
#include <chrono>
#include "Change_data.h"
#include "CarLine.h"


CarLine::CarLine()
{
    speed = 0.0;
    acceleration = 0.0;
    turnAngle = 0.0;
    positionX = 0.0;
    positionY = 0.0;
    startTime = 0.0;
};

CarLine::CarLine(double spd, double accel, double turn, double startX, double startY, double time)
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

CarLine::CarLine(const CarLine& other)
{
    speed = other.speed;
    acceleration = other.acceleration;
    turnAngle = other.turnAngle;
    positionX = other.positionX;
    positionY = other.positionY;
    startTime = other.startTime;
};


void CarLine::changeSpeed(double spd)
{
    if (spd < 0) {
        spd = 0.0;
    }
    speed = spd;
}

void CarLine::changeAcceleration(double accel)
{
    acceleration = accel;
}

void CarLine::changeX(double startX)
{
    positionX = startX;
}

void CarLine::changeY(double startY)
{
    positionY = startY;
}

void CarLine::changeTurnAngle(double turn)
{
    if (turn < -360 || turn > 360) {
        turn = 0.0;
    }
    turnAngle = turn;
}

void CarLine::changeTime(double time)
{
    if (time < 0) {
        time = 0.0;
    }
    startTime = time;
}

double CarLine::getPositionX() const {
    return positionX;
}

double CarLine::getPositionY() const {
    return positionY;
}

double CarLine::getSpeed() const {
    return speed;
}

double CarLine::getAcceleration() const {
    return acceleration;
}

double CarLine::getAngle() const {
    return turnAngle;
}

double CarLine::getTime() const {
    return startTime;
}