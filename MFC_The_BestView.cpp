
// MFC_The_BestView.cpp : реализация класса CMFC_The_BestView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "MFC_The_Best.h"
#endif

#include "MFC_The_BestDoc.h"
#include "MFC_The_BestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFC_The_BestView

IMPLEMENT_DYNCREATE(CMFC_The_BestView, CView)

BEGIN_MESSAGE_MAP(CMFC_The_BestView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_CHAR()
	ON_COMMAND(ID_32771, &CMFC_The_BestView::On32771)
	ON_COMMAND(ID_32772, &CMFC_The_BestView::On32772)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_32773, &CMFC_The_BestView::On32773)
	ON_COMMAND(ID_32771, &CMFC_The_BestView::On32771)
	ON_COMMAND(ID_32772, &CMFC_The_BestView::On32772)
	ON_COMMAND(ID_32773, &CMFC_The_BestView::On32773)
END_MESSAGE_MAP()

// создание/уничтожение CMFC_The_BestView

CMFC_The_BestView::CMFC_The_BestView()
{
	// TODO: добавьте код создания
	pen1.CreatePen(PS_DASH, 1, RGB(0, 0, 255)); 
	brush1.CreateHatchBrush(HS_VERTICAL, RGB(255, 0, 0));
}

CMFC_The_BestView::~CMFC_The_BestView()
{
}

BOOL CMFC_The_BestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CMFC_The_BestView

void CMFC_The_BestView::OnDraw(CDC* pDC)
{
	CMFC_The_BestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных
	CPen pen(PS_SOLID, 1, RGB(255, 0, 0)); 
	pDC->SelectObject(pen); 
	MyLine *p = pDoc->pF; 
	while (p) 
	{
		pDC->MoveTo(p->p1);
		pDC->LineTo(p->p2);
		p = p->pNext;
	}
	
	pDC->TextOut(50, 50, pDoc->text); 
	if (pDoc->flag1) 
	{
		pDC->SelectObject(&pen1); 
		pDC->SelectObject(&brush1); 
		pDC->Rectangle(100, 100, 200, 200); 
	}
	if (pDoc->flag2) 
	{
		pDC->SelectObject(&pen1); 
		pDC->SelectObject(&brush1); 
		pDC->Ellipse(300, 100, 400, 200); 
	}
	if (pDoc->flag3) 
	{
		pDC->SelectObject(&pen1);
		pDC->SelectObject(&brush1); 
		pDC->MoveTo(100, 100);
		pDC->LineTo(100, 300);
		pDC->MoveTo(100, 300);
		pDC->LineTo(250, 400); 
		pDC->MoveTo(250, 400);
		pDC->LineTo(100, 100);
	}

}


// печать CMFC_The_BestView

BOOL CMFC_The_BestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CMFC_The_BestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CMFC_The_BestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CMFC_The_BestView

#ifdef _DEBUG
void CMFC_The_BestView::AssertValid() const
{
	CView::AssertValid();
}

void CMFC_The_BestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFC_The_BestDoc* CMFC_The_BestView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFC_The_BestDoc)));
	return (CMFC_The_BestDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CMFC_The_BestView


void CMFC_The_BestView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	// TODO: Add your message handler code here and/or call default
	p1 = p2 = point;
	CView::OnLButtonDown(nFlags, point);
}


void CMFC_The_BestView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	
	CMFC_The_BestDoc* pDoc = GetDocument(); 
	pDoc->text += (TCHAR)nChar; 
	CClientDC dc(this);
	dc.TextOut(50, 50, pDoc->text);
	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CMFC_The_BestView::On32772()
{
	CClientDC dc(this); 
	dc.SelectObject(&pen1); 
	dc.SelectObject(&brush1); 
	dc.Rectangle(200, 200, 300, 300); 
	CMFC_The_BestDoc* pDoc = GetDocument(); 
	pDoc->flag1 = true; 
}


void CMFC_The_BestView::On32771()
{
	CClientDC dc(this); 
	dc.SelectObject(&pen1); 
	dc.SelectObject(&brush1); 
	dc.Ellipse(600, 200, 700, 300); 
	CMFC_The_BestDoc* pDoc = GetDocument(); 
	pDoc->flag2 = true; 
}


void CMFC_The_BestView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	// TODO: Add your message handler code here and/or call default
	if (nFlags == MK_LBUTTON) 
	{
		CPen pen1, pen2;
		pen1.CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		pen2.CreateStockObject(WHITE_PEN);
		CClientDC d(this);
		d.SelectObject(&pen2);
		d.MoveTo(p1); d.LineTo(p2); 
		p2 = point;
		d.SelectObject(&pen1);
		d.MoveTo(p1); d.LineTo(p2); 
	}
	CView::OnMouseMove(nFlags, point);
}


void CMFC_The_BestView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного
	// TODO: Add your message handler code here and/or call default
	MyLine *p = new MyLine(p1, p2); 
	CMFC_The_BestDoc* pDoc = GetDocument(); 
	p->add(pDoc->pF); 
	pDoc->SetModifiedFlag(1); 
	CView::OnLButtonUp(nFlags, point);
}


void CMFC_The_BestView::On32773()
{
	// TODO: добавьте свой код обработчика команд
	CClientDC dc(this); 
	dc.SelectObject(&pen1);
	dc.SelectObject(&brush1); 
	dc.MoveTo(100, 100);
	dc.LineTo(100, 300);
	dc.MoveTo(100, 300);
	dc.LineTo(250, 400); 
	dc.MoveTo(250, 400);
	dc.LineTo(100, 100);
	CMFC_The_BestDoc* pDoc = GetDocument();
	pDoc->flag3 = true;
}
