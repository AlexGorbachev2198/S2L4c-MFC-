
// MFC_The_Best.h : главный файл заголовка для приложения MFC_The_Best
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CMFC_The_BestApp:
// О реализации данного класса см. MFC_The_Best.cpp
//

class CMFC_The_BestApp : public CWinApp
{
public:
	CMFC_The_BestApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_The_BestApp theApp;
