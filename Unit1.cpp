//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	sScriptsDir = GetCurDir() + "Scripts\\";     //"D:\\C++\\Scriptor\\Scripts\\";
	AnsiString sFName = sScriptsDir + "main.txt";
	if(GetIsFileExist(sFName))
		CB1->Items->LoadFromFile(sFName);

	tnCurrent = TV1->Items->Add(0, "Опер1");
	EdNd = 0;
}
//---------------------------------------------------------------------------



// Not the class members
//---------------------------------------------------------------------------
AnsiString TextToString(TRichEdit *RE)
{
	int i=0;
	AnsiString str = RE->Lines->Strings[i];
	while(++i<RE->Lines->Count)
		str += "/n"+RE->Lines->Strings[i];
return str;
}
//---------------------------------------------------------------------------
void StringToText(TRichEdit *RE, AnsiString sText)
{
	int nPos = sText.AnsiPos("/n");                                             //Form1->DBM("nPos", nPos);
	while(nPos)
	{
		sText.Delete(nPos, 2);
		sText.Insert("\n", nPos);
        nPos = sText.AnsiPos("/n");
	}
	RE->Text = sText;
}






// Help Funcs
//---------------------------------------------------------------------------
bool TForm1::GetIsFileExist(AnsiString sPath)
{
	std::fstream F;
	F.open(sPath.c_str());
	if(F)
	{
		F.close();
		return true;
	}
return false;
}
//---------------------------------------------------------------------------
void TForm1::OpenEditPanel(AnsiString sMessage)
{
	if(sMessage == "Новый вариант:")
		P2->Left = 687;
	else if(sMessage == "Новый скрипт:")
		P2->Left = 431;

	P2->Top = 44;
	L1->Caption = sMessage;
	Ed1->Clear();
	P2->Visible = true;
	Ed1->SetFocus();
}
//---------------------------------------------------------------------------
TButton *TForm1::GetBt(int nNumber)
{
	TComponent *comp = Form1->FindComponent("Button" + IntToStr(nNumber));
return dynamic_cast<TButton*>(comp);
}
//---------------------------------------------------------------------------
void TForm1::TreeToForm()
{
    HideAllButtons();
	StringToText(RE1, tnCurrent->Text);

	for(int i=0; i<tnCurrent->Count; i++)
		ShowVariant(i+1, tnCurrent->Item[i]->Text);
}
//---------------------------------------------------------------------------
void TForm1::SetPUMenus(TPopupMenu *PM)
{
  	int i=1;
	TButton *Bt = GetBt(i);
	while(Bt)
	{
		Bt->PopupMenu = PM;
		Bt = GetBt(++i);
	}
}
//---------------------------------------------------------------------------







// User Interface // Show
//---------------------------------------------------------------------------
void TForm1::LoadScript(int nNumber)
{
	TV1->LoadFromFile(sScriptsDir + IntToStr(nNumber) + ".scri");
	tnCurrent = TV1->Items->Item[0];
    TreeToForm();
}
//---------------------------------------------------------------------------
void TForm1::PressVariant(TButton *Bt)
{
	AnsiString sName = Bt->Name;
	int nBtNumber = StrToInt(sName.SubString(sName.Length(), 1));
	tnCurrent = tnCurrent->Item[nBtNumber-1]->Item[0];
	TreeToForm();
}
//---------------------------------------------------------------------------
void TForm1::HideAllButtons()
{
	int i=1;
	TButton *Bt = GetBt(i);
	while(Bt)
	{
		Bt->Visible = false;
		Bt = GetBt(++i);
	}
}
//---------------------------------------------------------------------------
void TForm1::ShowVariant(int nNumber, AnsiString sText)
{
	if(nNumber <= 9)
	{
		TButton *Bt = GetBt(nNumber);
		if(Bt)
		{
			Bt->Height = 62;
			Bt->Width = 631;
			Bt->Left = 440;
			Bt->Top = 44 + (nNumber-1)*60;
			Bt->Caption = sText;
			Bt->Visible = true;
		}
	}
}
//---------------------------------------------------------------------------



// User Interface // Create / Edit
//---------------------------------------------------------------------------
void TForm1::StartNewScript()
{
	RE1->Clear();
	TV1->Items->Clear();
	tnCurrent = TV1->Items->Add(0, "Опер1");

	CB1->ItemIndex = -1;
	HideAllButtons();
	ToggleEditMode();
	EdNd = 0;
}
//---------------------------------------------------------------------------
void TForm1::SaveScript()
{
	TV1->SaveToFile(sScriptsDir + IntToStr(CB1->ItemIndex+1) + ".scri");
}
//---------------------------------------------------------------------------
void TForm1::SaveNewScript(AnsiString sName)
{
  	CB1->Items->Add(sName);
	CB1->Items->SaveToFile(sScriptsDir + "main.txt");
	TV1->SaveToFile(sScriptsDir + IntToStr(CB1->Items->Count) + ".scri");
	CB1->ItemIndex = CB1->Items->Count-1;
}
//---------------------------------------------------------------------------
void TForm1::AddAbonReply(AnsiString sText)
{
	TTreeNode * tn = TV1->Items->AddChild(tnCurrent, sText);  // Добавсляем кнопку
	TV1->Items->AddChild(tn, "Реплика оператора"); // Добавляем сразу реплику оператора
}
//---------------------------------------------------------------------------
void TForm1::ToggleEditMode(bool bOn)
{
	if(bOn)
	{
		RE1->ReadOnly = false;
		Bt2->Visible = true;
		N4->Checked = true;
		SetPUMenus(PM1);
	}
	else
	{
		RE1->ReadOnly = true;
		Bt2->Visible = false;
		P2->Visible = false;
		N4->Checked = false;
		SetPUMenus(0);
	}
}










// FORM Funcs
//---------------------------------------------------------------------------
void __fastcall TForm1::CB1Change(TObject *Sender)
{
	LoadScript(CB1->ItemIndex+1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender) // Вперед
{
	AnsiString sID, sName;
	TButton *Bt = dynamic_cast<TButton *>(Sender);
	if(Bt)
		PressVariant(Bt);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender) // Назад
{
	TTreeNode *Par;
	try
	{
		Par = tnCurrent->Parent->Parent;
    }
	catch(...)
	{
    	Par = 0;
	}

	if(Par)
    {
		tnCurrent = Par;
		TreeToForm();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RE1Change(TObject *Sender)
{
	if(tnCurrent)
		tnCurrent->Text = TextToString(RE1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Bt2Click(TObject *Sender)
{
	N8Click(Form1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender) // Отмена
{
    EdNd = 0;
	P2->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender) // OK Button на P2
{
	if(Ed1->Text == "")
		return;

	if(L1->Caption == "Новый скрипт:")
	{
		SaveNewScript(Ed1->Text);
		P2->Visible = false;
	}
	else if(L1->Caption == "Новый вариант:")
	{
		if(EdNd)
			EdNd->Text = Ed1->Text;
		else
			AddAbonReply(Ed1->Text);

		TreeToForm();
		P2->Visible = false;
		EdNd = 0;
	}
}
//---------------------------------------------------------------------------



// Main menu
void __fastcall TForm1::N6Click(TObject *Sender) // Новый скрипт
{
	StartNewScript();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N2Click(TObject *Sender) // Сохранить
{
	if(CB1->ItemIndex>-1) // Save
		TV1->SaveToFile(sScriptsDir + IntToStr(CB1->ItemIndex+1) + ".scri");
	else
		N7Click(Form1); // Save As
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N7Click(TObject *Sender) // Сохранить как
{
	OpenEditPanel("Новый скрипт:");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N5Click(TObject *Sender)   // Удалить скрипт
{
	P1->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)  // Режим редактирования
{
	if(N4->Checked)
		ToggleEditMode(false);
	else
		ToggleEditMode();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N8Click(TObject *Sender) 	// Добавить реплику абонента
{
	if(N4->Checked)
		OpenEditPanel("Новый вариант:");
}
//---------------------------------------------------------------------------




// PopupMenu
void __fastcall TForm1::N11Click(TObject *Sender) // Двинуть вверх
{
	int nBtID = 0;
	TPopupMenu *PM = dynamic_cast<TPopupMenu *>(N10->GetParentMenu());
	TButton *Bt = dynamic_cast<TButton *>(PM->PopupComponent);
	if(Bt)
	{
		nBtID = StrToInt(Bt->Name.SubString(Bt->Name.Length(), 1));
		tnCurrent->Item[nBtID-1]->MoveTo(tnCurrent->Item[nBtID-2], 4);
		TreeToForm();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N10Click(TObject *Sender) // Изменить кнопку
{
	OpenEditPanel("Новый вариант:");

	int nBtID = 0;
	TPopupMenu *PM = dynamic_cast<TPopupMenu *>(N10->GetParentMenu());
	TButton *Bt = dynamic_cast<TButton *>(PM->PopupComponent);
	if(Bt)
	{
		nBtID = StrToInt(Bt->Name.SubString(Bt->Name.Length(), 1));
		EdNd = tnCurrent->Item[nBtID-1]; // Запоминаем какую кнопку поменять
		Ed1->Text = EdNd->Text;
	}

}
//---------------------------------------------------------------------------
void __fastcall TForm1::N9Click(TObject *Sender) // Удалить кнопку
{
	int nBtID = 0;
	TPopupMenu *PM = dynamic_cast<TPopupMenu *>(N10->GetParentMenu());
	TButton *Bt = dynamic_cast<TButton *>(PM->PopupComponent);
	if(Bt)
	{
		nBtID = StrToInt(Bt->Name.SubString(Bt->Name.Length(), 1));
		tnCurrent->Item[nBtID-1]->Delete();
		TreeToForm();
	}
}
//---------------------------------------------------------------------------












//---------------------------------------------------------------------------
void TForm1::DBM(AnsiString str1, AnsiString str2)
{
	RE3->Lines->Add(str1 + ": " + str2);
}
//---------------------------------------------------------------------------
void TForm1::DBM(AnsiString str1, int n)
{
    RE3->Lines->Add(str1 + ": " + IntToStr(n));
}
//---------------------------------------------------------------------------

/*
int FindStringWithPart(TStrings *Lines, AnsiString sPart)
{
	int i=0;
	AnsiString str;
	while(i<Lines->Count)
	{
		str = Lines->Strings[i];
		if(str.AnsiPos(sPart)>0)
			return i;
		i++;
	}
return -1;
}
//---------------------------------------------------------------------------
void ReplaceLine(TStrings *Lines, int nLine, AnsiString str)
{
	Lines->Delete(nLine);
	Lines->Insert(nLine, str);
}
//---------------------------------------------------------------------------
*/



// Панель подтверждения
void __fastcall TForm1::BitBtn5Click(TObject *Sender) // Отмена
{
	P1->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BitBtn4Click(TObject *Sender) // ОК
{
	int nID = CB1->ItemIndex;
	if(nID<0)
		return;

	CB1->ItemIndex = -1;
	AnsiString sNewName, sName = sScriptsDir + IntToStr(nID+1)+ ".scri";
	remove(sName.c_str());
	for(int i=nID+1; i<CB1->Items->Count; i++)
	{
		sName = sScriptsDir + IntToStr(nID+i)+ ".scri";
		sNewName = sScriptsDir + IntToStr(nID+i-1)+ ".scri";
		rename(sName.c_str(), sNewName.c_str());
	}
	CB1->Items->Delete(nID);
	CB1->Items->SaveToFile(sScriptsDir + "main.txt");

	StartNewScript();
	P1->Visible = false;
}
//---------------------------------------------------------------------------

