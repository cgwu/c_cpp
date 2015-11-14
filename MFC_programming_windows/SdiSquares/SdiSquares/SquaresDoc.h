
// SquaresDoc.h : CSquaresDoc ��Ľӿ�
//


#pragma once


class CSquaresDoc : public CDocument
{
protected: // �������л�����
	CSquaresDoc();
	DECLARE_DYNCREATE(CSquaresDoc)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// ʵ��
public:
	virtual ~CSquaresDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// ����Ϊ����������������������ݵ� Helper ����
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
	COLORREF m_clrGrid[4][4];
	COLORREF m_clrCurrentColor;
public:
	void SetSquare(int i, int j, COLORREF color);
	COLORREF GetSquare(int i, int j);
	COLORREF GetCurrentColor(void);
};
