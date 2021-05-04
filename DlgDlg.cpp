/****************************************************
*Assigned By: Shai Carmi and Ohad Ashkenazi
*TZ: 311396451 and 205641574
****************************************************/


#include "stdafx.h"
#include "Dlg.h"
#include "DlgDlg.h"
#include <afxwin.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

	// Dialog Data
		//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CDlgDlg::CDlgDlg(CWnd* pParent) : CDialog(CDlgDlg::IDD, pParent), isThin(FALSE)
{
	futureFigKIND = RECTANGLE;
	f = NULL;
	isPressed = false;
	curColor = RGB(255, 255, 255);
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CDlgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, isThin);
	DDX_Control(pDX, IDOK, mbExit);
	DDX_Control(pDX, IDC_BUTTON1, mbSave);
	DDX_Control(pDX, IDC_BUTTON2, mbLoad);
	DDX_Control(pDX, IDC_RADIO1, mbRect);
	DDX_Control(pDX, IDC_RADIO2, mbElip);
	DDX_Control(pDX, IDC_RADIO5, mbSqua);
	DDX_Control(pDX, IDC_RADIO6, mbCirc);
	DDX_Control(pDX, IDC_RADIO4, mbLine);
	DDX_Control(pDX, IDC_RADIO7, mbPen);
	DDX_Control(pDX, IDC_RADIO3, mbTri);
	DDX_Control(pDX, IDC_RADIO8, mbDel);
	DDX_Control(pDX, IDC_RADIO9, mbPick);
	DDX_Control(pDX, IDC_RADIO10, mbPaint);
	DDX_Control(pDX, IDC_RADIO11, mbArrow);
	DDX_Control(pDX, IDC_BUTTON3, mbCls);
	DDX_Control(pDX, IDC_BUTTON5, mbUndo);
	DDX_Control(pDX, IDC_BUTTON6, mbPaintFigs);
}

BEGIN_MESSAGE_MAP(CDlgDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlgDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_RADIO1, &CDlgDlg::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &CDlgDlg::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO3, &CDlgDlg::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO4, &CDlgDlg::OnBnClickedRadio4)
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_CHECK1, &CDlgDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_RADIO5, &CDlgDlg::OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_RADIO7, &CDlgDlg::OnBnClickedRadio7)
	ON_BN_CLICKED(IDC_RADIO6, &CDlgDlg::OnBnClickedRadio6)
	ON_BN_CLICKED(IDC_RADIO8, &CDlgDlg::OnBnClickedRadio8)
	ON_BN_CLICKED(IDC_RADIO9, &CDlgDlg::OnBnClickedRadio9)
	ON_BN_CLICKED(IDC_RADIO10, &CDlgDlg::OnBnClickedRadio10)
	ON_BN_CLICKED(IDC_RADIO11, &CDlgDlg::OnBnClickedRadio11)

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDlg message handlers
BOOL CDlgDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Add "About..." menu item to system menu.
	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);
	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	CheckRadioButton(IDC_RADIO1, IDC_RADIO9, IDC_RADIO1);
	mode = SHAPE;
	// TODO: Add extra initialization here
	mbExit.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP3)));
	mbSave.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP5)));
	mbLoad.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP1)));
	mbRect.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP6)));
	mbElip.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP8)));
	mbSqua.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP4)));
	mbCirc.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP7)));
	mbLine.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP9)));
	mbPen.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP10)));
	mbTri.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP11)));
	mbDel.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP12)));
	mbPaint.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP13)));
	mbPick.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP14)));
	mbArrow.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP15)));
	mbCls.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP16)));
	mbUndo.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP17)));
	mbPaintFigs.SetBitmap(LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP19)));
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR8)));
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CDlgDlg::OnPaint()
{
	CRect rect;
	GetClientRect(&rect);
	CPaintDC dc(this);
	UpdateWindow();
	dc.SetBkMode(TRANSPARENT);
	for (int i = 0; i < figs.GetSize(); i++)
	{
		figs[i]->Draw(&dc);
	}
	if (isPressed)
	{
		UpdateWindow();
		dc.MoveTo(startP.x, startP.y);
		dc.LineTo(startP.x, endP.y);
		dc.LineTo(endP.x, endP.y);
		dc.LineTo(endP.x, startP.y);
		dc.LineTo(startP.x, startP.y);
	}
}


HCURSOR CDlgDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}
int inshape = 0;
int l;
void CDlgDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	POINT pos;
	GetCursorPos(&pos);
	int i = 0;
	inshape = 0;
	if (mode != SHAPE && figs.GetSize() >= 0)
		for (i = figs.GetSize() - 1; i >= 0; i--)
			if (!((point.x > figs[i]->x1 && point.x > figs[i]->x2) || (point.x < figs[i]->x1 && point.x < figs[i]->x2) || (point.y > figs[i]->y1 && point.y > figs[i]->y2) || (point.y < figs[i]->y1 && point.y < figs[i]->y2)))
				if (figs[i]->GetColor() == dc.GetPixel(point))
				{
					inshape = 1;
					break;
				}
	switch (mode)
	{
	case SHAPE:
	{
		inshape = 0;
		endP = startP = point;
		CDialog::OnLButtonDown(nFlags, point);
	}
	break;
	case DEL:
	{
		if (inshape == 1)
		{
			Temp = figs[i];
			UR.Undo.Push(Temp);
			for (i; i < figs.GetSize() - 1; i++)
				figs[i] = figs[i + 1];
			figs.SetSize(figs.GetSize() - 1);
		}
	}
	break;
	case PAINT:
	{	if (inshape == 1)
		figs[i]->SetColor(curColor);
	}
	break;
	case PICK:
	{		if (inshape == 1)
	{
		l = i;
		endP = startP = point;
	}
	}
	break;
	default:
	{
		mode = SHAPE;
		endP = startP = point;
		CDialog::OnLButtonDown(nFlags, point);
	}
	break;
	}
	if (mode != DEL)
		UR.DeleteAll();
	isPressed = true;
}

void CDlgDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		endP = point;
		isPressed = false;
		switch (mode)
		{
		case PICK:
		{
			if (inshape == 1)
			{
				int deltax, deltay, i;
				deltax = endP.x - startP.x;
				deltay = endP.y - startP.y;
				figs[l]->x1 += deltax;
				figs[l]->x2 += deltax;
				figs[l]->y1 += deltay;
				figs[l]->y2 += deltay;
				Figure* temp = figs[l];
				for (i = l; i < figs.GetSize() - 1; i++)
					figs[i] = figs[i + 1];
				figs[i] = temp;
			}
		}
		break;
		case SHAPE:
		{
			switch (futureFigKIND)
			{
			case RECTANGLE:
				figs.Add(new RectangleM(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case ELLIPSE:
				figs.Add(new EllipseM(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case TRIANGLE:
				figs.Add(new TriangleM(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case LINE:
				figs.Add(new LineM(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case PEN:
				break;
			case SQUARE:
				figs.Add(new SquareM(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case CIRCLE:
				figs.Add(new CircleM(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			case ARROW:
				figs.Add(new ArrowM(startP.x, startP.y, endP.x, endP.y, curColor));
				break;
			}
		}
		break;
		}
	}
	UpdateWindow();
	Invalidate();
	CDialog::OnLButtonUp(nFlags, point);
	UpdateWindow();
}

void CDlgDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		CClientDC dc(this);
		CPen *oldPen;
		CBrush myBrush2, *oldBrush;
		myBrush2.CreateSolidBrush(curColor);
		oldBrush = dc.SelectObject(&myBrush2);
		CPen myPen1(PS_SOLID, isThin ? 1 : 2, RGB(0, 0, 0));
		oldPen = dc.SelectObject(&myPen1);
		switch (mode)
		{
		case PICK:
		{
			if (inshape == 1)
			{

				CBrush myBrush3;
				myBrush3.CreateSolidBrush(figs[l]->GetColor());
				oldBrush = dc.SelectObject(&myBrush3);
				UpdateWindow();
				figs[l]->MouseMove(startP, endP, &dc);
				endP = point;
			}
			break;
		}
		case SHAPE:
		{
			dc.SetROP2(R2_NOTXORPEN);
			switch (futureFigKIND)
			{

			case RECTANGLE:
			{
				dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
				endP = point;
				dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
				UpdateWindow();
			}
			break;
			case SQUARE:
			{

				dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
				endP = point;
				if (startP.x < endP.x)
					endP.x = startP.x + abs(startP.y - endP.y);
				else
					endP.x = startP.x - abs(startP.y - endP.y);
				dc.Rectangle(startP.x, startP.y, endP.x, endP.y);
			}
			break;
			case ELLIPSE:
			{
				dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
				endP = point;
				dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			}
			break;
			case CIRCLE:
			{
				dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
				endP = point;
				if (startP.x < endP.x)
					endP.x = startP.x + abs(startP.y - endP.y);
				else
					endP.x = startP.x - abs(startP.y - endP.y);
				dc.Ellipse(startP.x, startP.y, endP.x, endP.y);
			}
			break;
			case TRIANGLE:
			{
				CPoint p[3];
				p[0].x = startP.x;
				p[0].y = endP.y;
				p[1].x = endP.x;
				p[1].y = endP.y;
				p[2].x = (startP.x + endP.x) / 2;
				p[2].y = startP.y;
				dc.Polygon(p, 3);
				endP = point;
				p[0].x = startP.x;
				p[0].y = endP.y;
				p[1].x = endP.x;
				p[1].y = endP.y;
				p[2].x = (startP.x + endP.x) / 2;
				p[2].y = startP.y;
				UpdateWindow();
				dc.Polygon(p, 3);
			}
			break;
			case LINE:
			{
				dc.MoveTo(startP);
				dc.LineTo(endP.x, endP.y);
				endP = point;
				dc.MoveTo(startP);
				dc.LineTo(endP.x, endP.y);
			}
			break;
			case PEN:
			{
				dc.MoveTo(startP);
				dc.LineTo(endP.x, endP.y);
				endP = point;
				dc.MoveTo(startP);
				dc.LineTo(endP.x, endP.y);
				figs.Add(new PenM(startP.x, startP.y, endP.x, endP.y, curColor));
				startP = endP;
			}
			break;
			case ARROW:
			{
				CPoint p[7];
				p[0].x = startP.x;
				p[0].y = ((startP.y + endP.y) / 2 + startP.y) / 2;
				p[1].x = startP.x;
				p[1].y = ((startP.y + endP.y) / 2 + endP.y) / 2;
				p[2].x = (startP.x + endP.x) / 2;
				p[2].y = ((startP.y + endP.y) / 2 + endP.y) / 2;
				p[3].x = (startP.x + endP.x) / 2;
				p[3].y = endP.y;
				p[4].x = endP.x;
				p[4].y = (startP.y + endP.y) / 2;
				p[5].x = (startP.x + endP.x) / 2;
				p[5].y = startP.y;
				p[6].x = (startP.x + endP.x) / 2;
				p[6].y = ((startP.y + endP.y) / 2 + startP.y) / 2;
				dc.Polygon(p, 7);
				endP = point;
				p[0].x = startP.x;
				p[0].y = ((startP.y + endP.y) / 2 + startP.y) / 2;
				p[1].x = startP.x;
				p[1].y = ((startP.y + endP.y) / 2 + endP.y) / 2;
				p[2].x = (startP.x + endP.x) / 2;
				p[2].y = ((startP.y + endP.y) / 2 + endP.y) / 2;
				p[3].x = (startP.x + endP.x) / 2;
				p[3].y = endP.y;
				p[4].x = endP.x;
				p[4].y = (startP.y + endP.y) / 2;
				p[5].x = (startP.x + endP.x) / 2;
				p[5].y = startP.y;
				p[6].x = (startP.x + endP.x) / 2;
				p[6].y = ((startP.y + endP.y) / 2 + startP.y) / 2;
				dc.Polygon(p, 7);
			}
			break;
			}
		}
		break;
		}
		dc.SelectObject(oldPen);
		dc.SetROP2(R2_COPYPEN);
		dc.SelectObject(oldBrush);
	}
	CDialog::OnMouseMove(nFlags, point);
}

//save Serialize file
void CDlgDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.dat"), CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
}

//load Serialize file
void CDlgDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CFile file(_T("File.dat"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	UR.DeleteAll();
	Invalidate();
}

//clear screen by removing all figures
void CDlgDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CFile file(_T("Clear.dat"), CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	figs.Serialize(ar);
	ar.Close();
	file.Close();
	for (int i = 0; i < figs.GetSize(); i++)
		delete figs[i];
	UR.DeleteAll();
	Invalidate();
}

//undo button
void CDlgDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (figs.GetSize() != 0)
	{
		figs.RemoveAt(figs.GetSize() - 1);
		Invalidate();
	}
}

//paint all the figures in the same color
void CDlgDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	for (int i = 0; i < figs.GetSize(); i++)
		figs[i]->SetColor(curColor);
	Invalidate();
}


void CDlgDlg::OnBnClickedRadio1()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = RECTANGLE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR8)));
}

void CDlgDlg::OnBnClickedRadio2()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = ELLIPSE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR2)));
}

void CDlgDlg::OnBnClickedRadio3()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = TRIANGLE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR10)));
}

void CDlgDlg::OnBnClickedRadio4()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = LINE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR4)));
}
void CDlgDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CClientDC dc(this);
	curColor = dc.GetPixel(point);
	Invalidate(0);
	CDialog::OnRButtonDown(nFlags, point);
}
void CDlgDlg::OnBnClickedCheck1()
{
	UpdateData(true);
	// TODO: Add your control notification handler code here
}
void CDlgDlg::OnBnClickedRadio5()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = SQUARE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR9)));
}
void CDlgDlg::OnBnClickedRadio6()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = CIRCLE;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR1)));
}
void CDlgDlg::OnBnClickedRadio7()
{
	// TODO: Add your control notification handler code here
	futureFigKIND = PEN;
	mode = SHAPE;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR7)));
}
void CDlgDlg::OnBnClickedRadio8()
{
	mode = DEL;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR3)));
}
void CDlgDlg::OnBnClickedRadio9()
{
	mode = PICK;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR5)));
}
void CDlgDlg::OnBnClickedRadio10()
{
	mode = PAINT;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR6)));
}

void CDlgDlg::OnBnClickedRadio11()
{
	futureFigKIND = ARROW;
	SetClassLong(m_hWnd, GCL_HCURSOR, (LONG)LoadCursor(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDC_CURSOR11)));
	mode = SHAPE;
}