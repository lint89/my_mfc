#pragma once


// CSettingDlg �Ի���

class CSettingDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSettingDlg)

public:
	CSettingDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSettingDlg();

// �Ի�������
	enum { IDD = IDD_DLG_SETTING };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	UINT m_nLineWidth;
	int m_nLineStyle;
	afx_msg void OnChangeLineWidth();
	afx_msg void OnClickedRadio1();
	afx_msg void OnPaint();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
private:
	CBrush m_brush;
	CFont m_font;
};
