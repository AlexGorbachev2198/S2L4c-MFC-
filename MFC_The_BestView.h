
// MFC_The_BestView.h : интерфейс класса CMFC_The_BestView
//

#pragma once


class CMFC_The_BestView : public CView
{
protected: // создать только из сериализации
	CMFC_The_BestView();
	DECLARE_DYNCREATE(CMFC_The_BestView)

// Атрибуты
public:
	CMFC_The_BestDoc* GetDocument() const;
	CPoint p1, p2; 
	CPen pen1; 
	CBrush brush1;
// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CMFC_The_BestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void On32771();
	afx_msg void On32772();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void On32773();
};

#ifndef _DEBUG  // отладочная версия в MFC_The_BestView.cpp
inline CMFC_The_BestDoc* CMFC_The_BestView::GetDocument() const
   { return reinterpret_cast<CMFC_The_BestDoc*>(m_pDocument); }
#endif

