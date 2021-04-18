#include "prolog.h"

/// $name: Sizeof
/// $keywords: language
/// $level: beginner

/// $description
/// Checks user's undestanding of `sizeof`, its function and relationship to
/// memory layout.
/// $$

/// $question: What value s is going to be and what factors affect the value.

/// $code
int main()
{
    int v;

    size_t s = sizeof(v);

    return 0;
}
