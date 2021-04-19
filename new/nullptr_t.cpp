#include <array>
#include "prolog.h"

/// $name: nullptr_t

/// $description
/// Checks understanding for `nullptr_t` existance.
/// The source contains two issues: Missing overload for `process_array` 
/// with `nullptr_t` argument. Compounding to that, `NULL` is used instead
/// of `nullptr`, which will still results in ambiguity, even in presence
/// of overload.
/// $$

/// $keywords: language
/// $level: intermediate

/// $question:
/// Why compilation fails? How would you fix it?
/// $$

/// $output: compile
/// $code

// Requirement: values argument can be null

void process_array(double *values, size_t count)
{
    // Some array prcessing code.
}

void process_array(int *values, size_t count)
{
    // Some array processing code.
}

// ...other process_ functions

int main()
{
    double a[] = {1, 2, 3, 4};
    int b[] = {1, 2, 3, 4};

    process_array(NULL, 0);
    process_array(a, 4);
    process_array(b, 4);

    return 0;
}