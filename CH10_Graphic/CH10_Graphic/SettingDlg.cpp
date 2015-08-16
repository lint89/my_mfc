// SettingDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CH10_Graphic.h"
#include "SettingDlg.h"
#include "afxdialogex.h"


// CSettingDlg �Ի���

IMPLEMENT_DYNAMIC(CSettingDlg, CDialogEx)

CSettingDlg::CSettingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSettingDlg::IDD, pParent)
	, m_nLineWidth(0)
	, m_nLineStyle(0)
{
	m_brush.CreateSolidBrush(RGB(0, 0, 255));
	m_font.CreatePointFont(200, _T("�����п�"));
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


// CSettingDlg ��Ϣ�������


void CSettingDlg::OnChangeLineWidth()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

//#1015

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

}


void CSettingDlg::OnClickedRadio1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CSettingDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting
		// TODO: �ڴ˴������Ϣ����������
		// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()
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
//	// TODO:  �ڴ˸��� DC ���κ�����
//
//#3019
//	return hbr;
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������

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

	//if (pWnd->GetDlgCtrlID() == IDOK)	// ��ť��Ч����Ҫʵ�ְ�ť����дDrawItem����
	//{
	//	return m_brush;
	//}


	return hbr;
}
