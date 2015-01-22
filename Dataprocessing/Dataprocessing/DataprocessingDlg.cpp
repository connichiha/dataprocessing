
// DataprocessingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Dataprocessing.h"
#include "DataprocessingDlg.h"
#include "afxdialogex.h"

#include "math.h"
#include "conio.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDataprocessingDlg dialog




CDataprocessingDlg::CDataprocessingDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDataprocessingDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDataprocessingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EQOIn, m_QOIn);
	DDX_Control(pDX, IDC_SQOOut, m_QOOut);
}

BEGIN_MESSAGE_MAP(CDataprocessingDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BQ1, &CDataprocessingDlg::OnBnClickedBq1)
	ON_BN_CLICKED(IDC_BQ2, &CDataprocessingDlg::OnBnClickedBq2)
	ON_BN_CLICKED(IDC_BQ4, &CDataprocessingDlg::OnBnClickedBq4)
	ON_BN_CLICKED(IDC_BQ6, &CDataprocessingDlg::OnBnClickedBq6)
	ON_BN_CLICKED(IDC_BQ3, &CDataprocessingDlg::OnBnClickedBq3)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CDataprocessingDlg message handlers

BOOL CDataprocessingDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDataprocessingDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDataprocessingDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDataprocessingDlg::OnBnClickedBq1()
{
	/*acquire a string from Edit,and show in Static
	method: 
	Get Text from EDIT: 
		GetDlgItemText(ID_E,string);
	Set text to Static
		GetDlgItem(IDC_S)->SetWindowText("")
	*/
	CString j1_s;
	CString str;
	GetDlgItemText(IDC_EQOIn,j1_s);
	double j1;
	j1=atof(j1_s);
	if (j1 == 1)
	{
		str = _T("Yes");
	} 
	else
	{
		str =  _T("No");
	}
	GetDlgItem(IDC_SQOOut)->SetWindowText(str);
}


void CDataprocessingDlg::OnBnClickedBq2()
{
	// TODO: Add your control notification handler code here
	CString str;
	int num,i;
	int tmp = 1;
	num = GetDlgItemInt(IDC_EQTIn);
	for (i = 1;i <= num; i++)
	{
		tmp = tmp * i;
	}
	SetDlgItemInt(IDC_SQTOut,tmp);
}

void CDataprocessingDlg::OnBnClickedBq3()
{
	// TODO: Add your control notification handler code here
	SetTimer(1,100,NULL); // settimer is ok, but it's not while.
}

void CDataprocessingDlg::OnBnClickedBq4()
{
	// TODO: Add your control notification handler code here
	CString str;
	int num;
	num = GetDlgItemInt(IDC_EQFIn);
	switch (num)
	{
	case 1:
		str = "One";
		break;
	case 2:
		str = "Two";
		break;
	default:
		str = "It is neither one nor two.";
	}
	GetDlgItem(IDC_SQFOut)->SetWindowText(str);
}


void CDataprocessingDlg::OnBnClickedBq6()
{
	// TODO: Add your control notification handler code here
	CString str,tmpstr;
	double num1 = pow(double(2),8);
	//itoa(num1,str,10);
	double num2 = sin(67*3.14/180);
	double num3 = fabs(-23.456);
	int num4 = int(fmod(double(7),double(3)));//7%3;
	int num5[10] = {5};
	for(int   i=0;i <10;i++){
		num5[i] =rand()%2;
		tmpstr.Format("%d",num5[i]);
		str = str + tmpstr;
	} 
	//tmpstr.Format("%s%d","The first result is:",num1);  // num1 is 256 > 255, in INT it will be 0, so it's wrong.
	tmpstr.Format("%s%f%s%f%s%f%s%d%s","The first result is:",num1,". And the second result is:",num2,
		". And the third result is:",num3,". And the fourth result is:",num4,". And the fifth result is:");
	str = tmpstr + str;
	GetDlgItem(IDC_SQSixOut)->SetWindowText(str);
}





void CDataprocessingDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: Add your message handler code here and/or call default
	switch(nIDEvent)
	{
	case 1://Homework asks us to use while!
		int num = GetDlgItemInt(IDC_EQThrIn);
		while (num != 0)
		{
			int num = GetDlgItemInt(IDC_EQThrIn);
			SetDlgItemInt(IDC_SQThrOut,num);
			break;
		}
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
