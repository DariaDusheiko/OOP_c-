#ifndef CARLINE_H
#define CARLINE_H

class CarLine {
    public:
        CarLine();
        CarLine(double spd, double accel, double turn, double startX, double startY, double time);
        CarLine(const CarLine& other);

        void changeSpeed(double spd);
        void changeAcceleration(double accel);
        void changeTurnAngle(double turn);
        void changeX(double startX);
        void changeY(double startY);
        void changeTime(double time);

        double getPositionX() const;
        double getPositionY() const;
        double getSpeed() const;
        double getAcceleration() const;
        double getAngle() const;
        double getTime() const;


    private:
        double speed;      
        double acceleration; 
        double turnAngle;  
        double positionX;
        double positionY;
        double startTime;
};
#endif