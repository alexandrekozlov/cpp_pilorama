#include <iostream>

bool permissions_granted = false;

bool IsLogEnabled()
{
    return false;
}

bool CheckUserPermissions()
{
    std::cout << "Checking permissions..." << std::endl;

    // Very important code that checks permissions...

    permissions_granted = true;

    return true;
}

int main()
{

    if (IsLogEnabled() && CheckUserPermissions())
        std::cout << "ERROR: Permisson check failure." << std::endl;

    // Some other code....

    if (!permissions_granted)
        std::cout << "Error: Access denied" << std::endl;

    return 0;
}