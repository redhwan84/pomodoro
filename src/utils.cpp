// Define utils functions

#include "utils.h"
#include <string>
#include <iostream>

bool convertBool(std::string answer)
{
    if (answer == "y" || answer == "yes" || answer == "true" || answer == "Yes")
    {
        return true;
    }
    else if (answer == "n" || answer == "no" || answer == "false" || answer == "No")
    {
        return false;
    }
    

    std::cout << "Invalid Input! Assuming no.\n";
    return false;

}