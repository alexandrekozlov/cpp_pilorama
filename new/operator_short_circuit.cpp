#include "prolog.h"

/// $name: Logical operator short-circuit
/// $category: language operators
/// $level: intermediate

/// $question: Why it fails?

/// $output: run

/// $code
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

    EXPECT_TRUE(permissions_granted);

    return 0;
}