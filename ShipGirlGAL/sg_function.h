#ifndef SG_FUNCTION_H
#define SG_FUNCTION_H
#include "library.h"

class SG_Function
{
public:
    SG_Function(library *fu);
    void SG_Return();
private:
    library* fn;
};

#endif // SG_FUNCTION_H
