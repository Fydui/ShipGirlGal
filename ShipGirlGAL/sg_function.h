#ifndef SG_FUNCTION_H
#define SG_FUNCTION_H
#include "library.h"
#include <fstream>
#include <vector>
#include <string>
using namespace std;
class SG_Function
{
public:
    SG_Function(library *fu);
    void SG_Return();
    void FU_ClearTextui();
    void SG_ReadText(string name,string fenge, int sum);
private:
    library* fn;
};

#endif // SG_FUNCTION_H
