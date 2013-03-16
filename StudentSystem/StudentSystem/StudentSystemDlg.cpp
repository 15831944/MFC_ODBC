
// StudentSystemDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentSystem.h"
#include "StudentSystemDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CStudentSystemDlg �Ի���




CStudentSystemDlg::CStudentSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CStudentSystemDlg::IDD, pParent)
	, m_Sno(0)
	, m_Sname(_T(""))
	, m_SearchBySno(0)
	, m_SearchBySname(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CStudentSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_SNO, m_Sno);
	DDX_Text(pDX, IDC_EDIT_SNAME, m_Sname);
	DDX_Text(pDX, IDC_EDIT2, m_SearchBySno);
	DDX_Text(pDX, IDC_EDIT3, m_SearchBySname);
}

BEGIN_MESSAGE_MAP(CStudentSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CStudentSystemDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CStudentSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CStudentSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CStudentSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CStudentSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CStudentSystemDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CStudentSystemDlg ��Ϣ�������

BOOL CStudentSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CStudentSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CStudentSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CStudentSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CStudentSystemDlg::OnBnClickedOk()
{
	UpdateData();
	if (m_Sno!=0&&m_Sname!=_T(""))
	{
		student.Open();
		student.AddNew();
		student.m_Sno=m_Sno;
		student.m_Sname=m_Sname;
		student.Update();
		student.Close();
	}
	UpdateData(0);
}


void CStudentSystemDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if (m_SearchBySno!=0)
	{
		m_cstrQuery.Format(_T("SELECT * FROM %s WHERE Sno = %d;"),student.GetDefaultSQL(),m_SearchBySno);
		student.Open(CRecordset::dynaset,m_cstrQuery,CRecordset::none);
		if (student.m_Sname==_T(""))
		{
			MessageBox(_T("û�м�¼"));
			return;
		}
		CString str;
		str.Format(_T("���� : %s ѧ�� : %d"),student.m_Sname,student.m_Sno);
		MessageBox(str);
		student.Close();
	}
	UpdateData(0);
}


void CStudentSystemDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if (m_SearchBySname!=_T(""))
	{
		m_cstrQuery.Format(_T("SELECT * FROM %s WHERE Sname ='%s';"),student.GetDefaultSQL(),m_SearchBySname);
		student.Open(CRecordset::dynaset,m_cstrQuery,CRecordset::none);
		if (student.m_Sname==_T(""))
		{
			MessageBox(_T("û�м�¼"));
			return;
		}
		while (!student.IsEOF())
		{
			CString str;
			str.Format(_T("���� : %s ѧ�� : %d"),student.m_Sname,student.m_Sno);
			MessageBox(str);
			student.MoveNext();
		}
		student.Close();
	}
	UpdateData(0);
}


void CStudentSystemDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	if (m_SearchBySno!=0)
	{
		m_cstrQuery.Format(_T("SELECT * FROM %s WHERE Sno=%d;"),student.GetDefaultSQL(),m_SearchBySno);
		student.Open(CRecordset::dynaset,m_cstrQuery,CRecordset::none);
		student.Delete();
		student.Close();
	}
	UpdateData(0);
}


void CStudentSystemDlg::OnBnClickedButton4()
{
	UpdateData();
	if (m_SearchBySname!=_T(""))
	{
		m_cstrQuery.Format(_T("SELECT * FROM %s WHERE Sname='%s';"),student.GetDefaultSQL(),m_SearchBySname);
		student.Open(CRecordset::dynaset,m_cstrQuery,CRecordset::none);
		if (student.m_Sname==_T(""))
		{
			MessageBox(_T("û�м�¼"));
			return;
		}
		while (!student.IsEOF())
		{
			student.Delete();
			student.MoveNext();
		}
		student.Close();
	}
	UpdateData(0);
}


void CStudentSystemDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();
	m_cstrQuery.Format(_T("SELECT * FROM %s WHERE Sno = %d;"),student.GetDefaultSQL(),m_SearchBySno);
	student.Open(CRecordset::dynaset,m_cstrQuery,CRecordset::none);
	student.Edit();
	student.m_Sname=m_SearchBySname;
	student.Update();
	student.Close();
	UpdateData(0);
}
