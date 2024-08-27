#include "Robot_Function.h"

// ENUM MAP
const ROBOT_FACE_ENUM local_Left_TBL[] = {WEST, NORTH, SOUTH, EAST};
const ROBOT_FACE_ENUM local_Right_TBL[] = {EAST, SOUTH, NORTH, WEST};

RobotFunctions::RobotFunctions()
{
}
RobotFunctions::~RobotFunctions()
{
}
void RobotFunctions::Place_Robot(long int x, long int y, ROBOT_FACE_ENUM rb_dir, bool &isPlaced)
{
    if ((x > _TBL_MX_X || x < 0) || (y > _TBL_MX_Y || y < 0))
    {
        std::cout << "Robot cannot be place." << std::endl;
        isPlaced = false;
        return;
    }
    m_X = x;
    m_Y = y;
    mRobotFace = rb_dir;
}
void RobotFunctions::Move_Robot(bool &isMoved)
{
    long int curr_x = m_X;
    long int curr_y = m_Y;
    switch (mRobotFace)
    {
    case NORTH:
        m_Y += 1;
        Move_Y(curr_y, isMoved);
        break;
    case SOUTH:
        m_Y -= 1;
        Move_Y(curr_y, isMoved);
        break;
    case WEST:
        m_X -= 1;
        Move_X(curr_x, isMoved);
        break;
    case EAST:
        m_X += 1;
        Move_X(curr_x, isMoved);
        break;
    };
}
void RobotFunctions::Rotate_Left_Robot()
{
    // local_Left_TBL
    mRobotFace = local_Left_TBL[mRobotFace];
}
void RobotFunctions::Rotate_Right_Robot()
{
    // local_Right_TBL
    mRobotFace = local_Right_TBL[mRobotFace];
}

void RobotFunctions::Move_X(long int currentX, bool &isMoved)
{
    if (m_X < 0 || m_X > m_table_max_current_x)
    {
        std::cout << "Robot cannot be move." << std::endl;
        m_X = currentX;
        isMoved = false;
    }
}

void RobotFunctions::Move_Y(long int currentY, bool &isMoved)
{
    if (m_Y < 0 || m_Y > m_table_max_current_y)
    {
        std::cout << "Robot cannot be move." << std::endl;
        m_Y = currentY;
        isMoved = false;
    }
}
