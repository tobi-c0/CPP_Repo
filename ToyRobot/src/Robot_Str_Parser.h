#ifndef _PARSER_H_
#define _PARSER_H_

#include <iostream>
#include <sstream>
#include <vector>

#include "RobotDefinitions.h"

class InputParser
{
public:
    static TablePosition ParseInput(std::vector<std::string> strInputs, bool &isOK);

private:
    static long int *ParseInputCommas(std::string strInputs, bool &isOK);
    static bool ParseNextParameterInputs(std::vector<std::string> aStr, TablePosition &aTb);
    static ROBOT_FACE_ENUM ParseParamFace(std::string aStr);
    static bool IsStringDigits(const std::string &s)
    {
        std::string::const_iterator it = s.begin();
        while (it != s.end() && std::isdigit(*it))
            ++it;
        return !s.empty() && it == s.end();
    }
};

#endif