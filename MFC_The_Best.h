
// MFC_The_Best.h : ������� ���� ��������� ��� ���������� MFC_The_Best
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������


// CMFC_The_BestApp:
// � ���������� ������� ������ ��. MFC_The_Best.cpp
//

class CMFC_The_BestApp : public CWinApp
{
public:
	CMFC_The_BestApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFC_The_BestApp theApp;
