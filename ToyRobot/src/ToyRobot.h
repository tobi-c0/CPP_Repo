#ifndef _TOY_ROBOT_H
#define _TOY_ROBOT_H

#include <iostream>
#include <sstream>
#include <vector>

#include "Robot_Str_Parser.h"
#include "Robot_Function.h"

class ToyRobot
{
public:
    ToyRobot();
    virtual ~ToyRobot();

    void ProcessCommandLineInput(std::string aInput);
    bool isKeepAlive()
    {
        return m_isKeepALive;
    }

private:
    // Member Variables
    bool m_isKeepALive;
    RobotFunctions m_RobFunction;
    CMD_ENUM m_CurrCmd;

    // Private methods
    void ProcessCommandLineInput(std::vector<std::string> aInput);
    void Process_Command(TablePosition aTbl);
    void Place_Robot(long int x, long int y, ROBOT_FACE_ENUM aFace);
    void Move_Robot();
    void Rotate_Left_Robot();
    void Rotate_Right_Robot();
    void Report_Robot();
    bool isRobotPlaced() { return ((m_CurrCmd != CMD_EMPTY) ? true : false); }
};

#endif