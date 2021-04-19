#include "prolog.h"

/// $name: Array new/delete
/// $description
/// Checks understanding between class and array new/delete.
/// 
/// Followup question for more advanced:
///
/// Why is it necessary to have `delete` and `delete[]` opeators?
///
/// Answer:
///
/// Because there is no distinction between array and pointer. Thus
/// compiler does not know whether it is looking at array or a signle object.
/// ```
/// $$

/// $categories: memory
/// $level: beginner

/// $question: Why application crashes?

/// $output: run
/// $code

class BodyPart
{
    std::string name;

public:
    BodyPart(const char *name) : name(name) {}
};

int main()
{
    auto *parts = new BodyPart[6] { 
        {"head"}, {"torso"}, 
        {"left hand"}, {"right hand"},
        {"left leg"}, {"right leg"} };

    // Use parts...

    delete parts;

    std::cout << "Exiting!" << std::endl;

    return 0;
}
