#include "Robot_Str_Parser.h"

TablePosition InputParser::ParseInput(std::vector<std::string> strInputs, bool &isOK)
{
    TablePosition tblPos;
    isOK = true;

    if (strInputs.size() == 0)
    {
        isOK = false;
        return tblPos;
    }
    std::string input = strInputs[0];
    if (input == "PLACE")
    {
        tblPos._cmd = CMD_PLACE;
        if (strInputs.size() > 1)
        {
            isOK = ParseNextParameterInputs(strInputs, tblPos);
        }
        else
        {
            isOK = false;
        }
    }
    else if (input == "MOVE")
    {
        if (strInputs.size() > 1)
        {
            isOK = false;
            return tblPos;
        }
        tblPos._cmd = CMD_MOVE;
    }
    else if (input == "LEFT")
    {
        if (strInputs.size() > 1)
        {
            isOK = false;
            return tblPos;
        }
        tblPos._cmd = CMD_LEFT;
    }
    else if (input == "RIGHT")
    {
        if (strInputs.size() > 1)
        {
            isOK = false;
            return tblPos;
        }
        tblPos._cmd = CMD_RIGHT;
    }
    else if (input == "REPORT")
    {
        if (strInputs.size() > 1)
        {
            isOK = false;
            return tblPos;
        }
        tblPos._cmd = CMD_REPORT;
    }
    else
    {
        isOK = false;
    }
    return tblPos;
}

long int *InputParser::ParseInputCommas(std::string strInputs, bool &isOK)
{
    std::istringstream iSs(strInputs);
    std::string pStr;
    long int *retVal = new long int[3];
    int cnt = 0;
    isOK = true;
    while (std::getline(iSs, pStr, ','))
    {
        if (cnt == 2)
        {
            // Check if position is NORTH, SOUTH, WEST, EAST
            retVal[cnt] = ParseParamFace(pStr);
        }
        else
        {
            if (IsStringDigits(pStr))
            {
                retVal[cnt] = stol(pStr);
            }
            else
            {
                isOK = false;
                break;
            }
        }
        cnt++;
    }
    return retVal;
}

bool InputParser::ParseNextParameterInputs(std::vector<std::string> aStr, TablePosition &aTb)
{
    bool isOK = false;
    int nextParam = 1;

    // Vector size is 2 ( Input was entered without spaces )
    if (aStr.size() == 2)
    {
        if (aStr[nextParam].find(',') != std::string::npos)
        {
            long int *val = ParseInputCommas(aStr[nextParam], isOK); // Next string is passed to function
            aTb._pos = val;
        }
    }
    else if (aStr.size() == 4)
    {
        // Vector size is greater than 2 ( Input was entered with spaces )
        long int *val = new long int[3];
        int index = 0;
        while (nextParam < aStr.size())
        {
            if (aStr[nextParam].find(',') != std::string::npos)
            {
                long int *temp = ParseInputCommas(aStr[nextParam], isOK); // Next string is passed to function
                val[index] = *temp;
                index++;
            }
            else
            {
                val[index] = (ParseParamFace(aStr[nextParam]));
            }
            nextParam++;
        }
        aTb._pos = val;
    }
    return isOK;
}

ROBOT_FACE_ENUM InputParser::ParseParamFace(std::string aStr)
{
    ROBOT_FACE_ENUM retFace = INVALID_FACE;
    if (aStr == "NORTH")
    {
        retFace = NORTH;
    }
    else if (aStr == "SOUTH")
    {
        retFace = SOUTH;
    }
    else if (aStr == "WEST")
    {
        retFace = WEST;
    }
    else if (aStr == "EAST")
    {
        retFace = EAST;
    }
    return retFace;
}
