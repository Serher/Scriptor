//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------



#include <System.Classes.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.ValEdit.hpp>
//---------------------------------------------------------------------------
#include "Unit2.h"
#include <Vcl.Menus.hpp>
#include <fstream>




class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TComboBox *CB1;
	TRichEdit *RE1;
	TButton *Button1;
	TRichEdit *RE3;
	TBitBtn *BitBtn1;
	TButton *Button2;
	TButton *Button3;
	TButton *Button4;
	TButton *Button5;
	TButton *Button6;
	TButton *Button7;
	TButton *Button8;
	TButton *Button9;
	TPanel *P2;
	TEdit *Ed1;
	TBitBtn *BitBtn2;
	TBitBtn *BitBtn3;
	TButton *Bt2;
	TLabel *L1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TTreeView *TV1;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TPopupMenu *PM1;
	TMenuItem *N9;
	TMenuItem *N10;
	TMenuItem *N11;
	TPanel *P1;
	TLabel *Label1;
	TBitBtn *BitBtn4;
	TBitBtn *BitBtn5;
	TLabel *Label2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall CB1Change(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
	void __fastcall BitBtn3Click(TObject *Sender);
	void __fastcall Bt2Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall RE1Change(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall BitBtn5Click(TObject *Sender);
	void __fastcall BitBtn4Click(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);

	// Переменные
	AnsiString sScriptsDir;
	TTreeNode *tnCurrent;
	TTreeNode *EdNd;

	// Вспомогательные функции
    bool GetIsFileExist(AnsiString sPath);
	void OpenEditPanel(AnsiString sMessage);
	TButton *GetBt(int nNumber);
	void HideAllButtons();
	void TreeToForm();
	void SetPUMenus(TPopupMenu *PM);

	// Пользовательский интерфейс
	void LoadScript(int nNumber);
	void PressVariant(TButton *Bt);
	void ShowVariant(int nNumber, AnsiString sText);

	// Создание/редактирование
	void StartNewScript();
	void SaveScript();
	void SaveNewScript(AnsiString sName);
	void AddAbonReply(AnsiString sText);
	void ToggleEditMode(bool bOn=true);


	// Дебаг
	void DBM(AnsiString str1, AnsiString str2 = "");
    void DBM(AnsiString str1, int n);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
