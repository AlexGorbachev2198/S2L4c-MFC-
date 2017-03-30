
// MFC_The_BestDoc.h : ��������� ������ CMFC_The_BestDoc
//

#include "MyLine.h"

#pragma once


class CMFC_The_BestDoc : public CDocument
{
protected: // ������� ������ �� ������������
	CMFC_The_BestDoc();
	DECLARE_DYNCREATE(CMFC_The_BestDoc)

// ��������
public:
	MyLine *pF;
	bool flag1, flag2,flag3; 
	CString text;

// ��������
public:

// ���������������
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ����������
public:
	virtual ~CMFC_The_BestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ��������� ������� ����� ���������
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ��������������� �������, �������� ���������� ������ ��� ����������� ������
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
