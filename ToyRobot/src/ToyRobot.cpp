#include "ToyRobot.h"

ToyRobot::ToyRobot()
{
    m_isKeepALive = true;
    m_CurrCmd = CMD_EMPTY;
    std::cout << "---------------------------------------" << std::endl;
}

ToyRobot::~ToyRobot()
{
    std::cout << "---------------------------------------" << std::endl;
}

void ToyRobot::ProcessCommandLineInput(std::vector<std::string> aInput)
{
    bool isParsingOK = false;
    TablePosition tbp = InputParser::ParseInput(aInput, isParsingOK);
    if (false == isParsingOK)
    {
        std::cout << "Invalid command has been received. Ignoring." << std::endl;
        return;
    }

    Process_Command(tbp);
}

void ToyRobot::ProcessCommandLineInput(std::string aInput)
{
    if (aInput.length() > 0)
    {
        std::stringstream ss(aInput);
        std::vector<std::string> tokens;
        std::string token;
        while (ss >> token)
        {
            tokens.push_back(token);
        }
        ProcessCommandLineInput(tokens);
    }
}

void ToyRobot::Process_Command(TablePosition aTbl)
{
    switch (aTbl._cmd)
    {
    case CMD_PLACE:
        Place_Robot(aTbl._pos[0], aTbl._pos[1], ROBOT_FACE_ENUM(aTbl._pos[2]));
        break;
    case CMD_MOVE:
        Move_Robot();
        break;
    case CMD_LEFT:
        Rotate_Left_Robot();
        break;
    case CMD_RIGHT:
        Rotate_Right_Robot();
        break;
    case CMD_REPORT:
        Report_Robot();
        break;
    default:
        break;
    };
}

void ToyRobot::Place_Robot(long int x, long int y, ROBOT_FACE_ENUM aFace)
{
    bool isPlaced = true;
    m_RobFunction.Place_Robot(x, y, aFace, isPlaced);
    if (isPlaced)
        m_CurrCmd = CMD_PLACE;
}

void ToyRobot::Move_Robot()
{
    if (isRobotPlaced())
    {
        bool isMoved = true;
        m_RobFunction.Move_Robot(isMoved);
        if (isMoved)
            m_CurrCmd = CMD_MOVE;
    }
    else
    {
        std::cout << "Invalid command has been received. Ignoring." << std::endl;
    }
}

void ToyRobot::Rotate_Left_Robot()
{
    if (isRobotPlaced())
    {
        m_RobFunction.Rotate_Left_Robot();
        m_CurrCmd = CMD_LEFT;
    }
    else
    {
        std::cout << "Invalid command has been received. Ignoring." << std::endl;
    }
}

void ToyRobot::Rotate_Right_Robot()
{
    if (isRobotPlaced())
    {
        m_RobFunction.Rotate_Right_Robot();
        m_CurrCmd = CMD_RIGHT;
    }
    else
    {
        std::cout << "Invalid command has been received. Ignoring." << std::endl;
    }
}

void ToyRobot::Report_Robot()
{
    if (isRobotPlaced())
    {
        const char *RobotDirection_Txt[] = {"NORTH", "EAST", "WEST", "SOUTH"};
        long int x = m_RobFunction.getX();
        long int y = m_RobFunction.getY();
        const char *robot_face = RobotDirection_Txt[m_RobFunction.getFace()];

        std::cout << "Output: " << x << "," << y << "," << robot_face << std::endl;
        m_isKeepALive = false;
    }
    else
    {
        std::cout << "Invalid command has been received. Ignoring." << std::endl;
    }
}
