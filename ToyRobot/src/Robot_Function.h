#ifndef _ROBOT_FUNC_H_
#define _ROBOT_FUNC_H_

#include "RobotDefinitions.h"

class RobotFunctions
{
public:
    RobotFunctions();
    virtual ~RobotFunctions();
    void Place_Robot(long int x, long int y, ROBOT_FACE_ENUM rb_dir, bool &isPlaced);
    void Move_Robot(bool &isMoved);
    void Rotate_Left_Robot();
    void Rotate_Right_Robot();

    long int getX() { return m_X; }
    long int getY() { return m_Y; }
    ROBOT_FACE_ENUM getFace() { return mRobotFace; }

private:
    long int m_table_max_current_x = _TBL_MX_X;
    long int m_table_max_current_y = _TBL_MX_Y;
    long int m_X;
    long int m_Y;
    ROBOT_FACE_ENUM mRobotFace;

    void Move_X(long int currentX, bool &isMoved);
    void Move_Y(long int currentY, bool &isMoved);
};

#endif