
// MFC_The_BestDoc.h : интерфейс класса CMFC_The_BestDoc
//

#include "MyLine.h"

#pragma once


class CMFC_The_BestDoc : public CDocument
{
protected: // создать только из сериализации
	CMFC_The_BestDoc();
	DECLARE_DYNCREATE(CMFC_The_BestDoc)

// Атрибуты
public:
	MyLine *pF;
	bool flag1, flag2,flag3; 
	CString text;

// Операции
public:

// Переопределение
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Реализация
public:
	virtual ~CMFC_The_BestDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Вспомогательная функция, задающая содержимое поиска для обработчика поиска
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
