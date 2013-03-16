
// StudentSystemDlg.h : ͷ�ļ�
//

#pragma once
#include "Student.h"

// CStudentSystemDlg �Ի���
class CStudentSystemDlg : public CDialogEx
{
private:
	CStudent student;
	CString m_cstrQuery;
	long m_Sno;
	CString m_Sname;
	long m_SearchBySno;
	CString m_SearchBySname;
// ����
public:
	CStudentSystemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_STUDENTSYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
