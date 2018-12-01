//---------------------------------------------------------------------------

#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)




AnsiString GetCurDir()
{
    /*
    TCHAR thBuffer[MAX_PATH];
    GetCurrentDirectory(sizeof(thBuffer),thBuffer);
    return AnsiString(thBuffer) + "\\";
    */

    TCHAR thBuffer[MAX_PATH];
    GetModuleFileName(NULL, thBuffer, MAX_PATH);
    AnsiString str = AnsiString(thBuffer);

    StringsContainer strCont;
    strCont.BreakString(str, "\\");
    str = "";
    for(int i=0; i<strCont.Vector.size()-1; i++)
        str += strCont.Vector[i] + "\\";

return str;
}
//------------------------------------------------------------------------------



//StringsContainer
//------------------------------------------------------------------------------
unsigned int StringsContainer::BreakString(AnsiString str, AnsiString sDivider)
{
    Vector.clear();

    AnsiString sTemp;
    int nDivLen = sDivider.Length();
    int nPos = str.AnsiPos(sDivider);
    while(nPos)
    {
        sTemp = str.SubString(0, nPos-1);
        Vector.push_back(sTemp);
        str.Delete(1, nPos+nDivLen-1);

        nPos = str.AnsiPos(sDivider);
    }
    if(str != "")
        Vector.push_back(str);//«апихиваем в вектор последнюю часть(то что осталось, если что-то осталось)

return Vector.size();
}
//------------------------------------------------------------------------------
int StringsContainer::IndexOf(AnsiString sValue)
{
    int nResult = -1;
    for(unsigned int i = 0; i<Vector.size(); i++)
    {
        if(Vector[i] == sValue)
        {
            nResult = i;
            return nResult;
        }
    }
return nResult;
}