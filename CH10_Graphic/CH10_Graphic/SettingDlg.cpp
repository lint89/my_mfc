// SettingDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CH10_Graphic.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// CSettingDlg 对话框

IMPLEMENT_DYNAMIC(CSettingDlg, CDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDlg::IDD, pParent)
	, m_nLineWidth(0)
	, m_nLineStyle(0)
{
	m_brush.CreateSolidBrush(RGB(0, 0, 255));
	m_font.CreatePointFont(200, _T("华文行楷"));
}

CSettingDlg::~CSettingDlg()
{
}

void CSettingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_LINE_WIDTH, m_nLineWidth);
	DDX_Radio(pDX, IDC_RADIO1, m_nLineStyle);
}


BEGIN_MESSAGE_MAP(CSettingDlg, CDialogEx)
	ON_EN_CHANGE(IDC_LINE_WIDTH, &CSettingDlg::OnChangeLineWidth)
	ON_BN_CLICKED(IDC_RADIO1, &CSettingDlg::OnClickedRadio1)
	ON_WM_PAINT()
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CSettingDlg 消息处理程序


void CSettingDlg::OnChangeLineWidth()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

//#1015

	// TODO:  在此添加控件通知处理程序代码

}


void CSettingDlg::OnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CSettingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: 在此处添加消息处理程序代码
		// 不为绘图消息调用 CDialogEx::OnPaint()
	UpdateData();
	CPen pen(m_nLineStyle, m_nLineWidth, RGB(255, 0, 0));
	dc.SelectObject(&pen);

	CRect rect;
	GetDlgItem(IDC_SAMPLE)->GetWindowRect(&rect);
	ScreenToClient(&rect);

	dc.MoveTo(rect.left + 20, rect.top + rect.Height()/2);
	dc.LineTo(rect.right - 20, rect.top + rect.Height()/2);
}


HBRUSH CSettingDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

//#3018
//
//#3019
//	return hbr;
//
//#3018
//
//#3019
//	return hbr;
//	// TODO:  在此更改 DC 的任何特性
//
//#3019
//	return hbr;
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔

	//return hbr;
	//return m_brush;
	if (pWnd->GetDlgCtrlID() == IDC_LINE_STYLE)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		pDC->SetBkMode(TRANSPARENT);
		return m_brush;
	}
	
	if (pWnd->GetDlgCtrlID() == IDC_LINE_WIDTH)
	{
		pDC->SetTextColor(RGB(255, 0, 0));
		//pDC->SetBkMode(TRANSPARENT);
		return m_brush;
	}

	if (pWnd->GetDlgCtrlID() == IDC_TEXT)
	{
		pDC->SelectObject(&m_font);
	}

	//if (pWnd->GetDlgCtrlID() == IDOK)	// 按钮无效，需要实现按钮类重写DrawItem函数
	//{
	//	return m_brush;
	//}


	return hbr;
}
