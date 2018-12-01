//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <vector>


AnsiString GetCurDir();


class StringsContainer
{
    public:
    std::vector<AnsiString> Vector;

    StringsContainer(){Vector.clear();}
    unsigned int BreakString(AnsiString str, AnsiString sDivider);
    int IndexOf(AnsiString sValue);
};

#endif
