
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

int flag_Q5 = 0;


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
	ON_BN_CLICKED(IDC_BQ5, &CDataprocessingDlg::OnBnClickedBq5)
	ON_BN_CLICKED(IDC_BQ7, &CDataprocessingDlg::OnBnClickedBq7)
	ON_BN_CLICKED(IDC_BQ8, &CDataprocessingDlg::OnBnClickedBq8)
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

void CDataprocessingDlg::OnBnClickedBq5()
{
	// TODO: Add your control notification handler code here
	flag_Q5 = 1;
	//GetDlgItem(IDC_SQFivOut)->SetWindowText(_T("Waiting for keyin."));
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

void CDataprocessingDlg::OnBnClickedBq7()
{
	// TODO: Add your control notification handler code here
	//creat data and save in file VII.txt
/*	FILE *fpx;
	fpx = fopen("VII.txt","w");
	CString tmpstr;
	int t = 0;
	float x[100],y[100],z[100];
	float data[100][4];
	for (t = 0; t < 100; t++)
	{
		data[t][0] = t;
		data[t][1] = (rand()%100)/100.0;
		data[t][2] = (rand()%100)/100.0;
		data[t][3] = (rand()%100)/100.0;
		fprintf(fpx,"%d,%.7f,%.7f,%.7f\n",data[t][0],data[t][1],data[t][2],data[t][3]);
		tmpstr.Format("%s%d%s%.7f%s%.7f%s%.7f","t is:",t,". x is:",data[t][1],
			". y is:",data[t][2],". z is: ",data[t][3]);
		GetDlgItem(IDC_SQSevOut)->SetWindowText(tmpstr);
		Sleep(10);
	}
	fclose(fpx);
	AfxMessageBox("File saved in Dataprocessing\VII.txt");
*/
	CStdioFile myFile;
	//CFileException fileException;
	if(myFile.Open("VII.txt",CFile::typeText|CFile::modeCreate|CFile::modeReadWrite))
	{
		int t = 0;
		float data[100][4];
		CString tmpstr;
		for (t = 0; t < 100; t++)
		{
			data[t][0] = t;
			//float i = rand()%32768;
			data[t][1] = (rand()%32768)/32767.0;   // n=rand()%(y-x+1)+x  x~y
			data[t][2] = (rand()%32768)/32767.0;
			data[t][3] = (rand()%32768)/32767.0;
			tmpstr.Format("%s%d%s%.7f%s%.7f%s%.7f","t is:",t,". x is:",data[t][1],
				". y is:",data[t][2],". z is: ",data[t][3]);
			GetDlgItem(IDC_SQSevOut)->SetWindowText(tmpstr);
			tmpstr.Format("%d%s%.7f%s%.7f%s%.7f\n",t,",",data[t][1],
				",",data[t][2],",",data[t][3]);
			myFile.WriteString(tmpstr);
			Sleep(50);
		}
	}
	myFile.Close();
}

void CDataprocessingDlg::OnBnClickedBq8()
{
	// TODO: Add your control notification handler code here
	CStdioFile myFile;
	if(myFile.Open("VII.txt",CFile::typeText|CFile::modeReadWrite))
	{
		myFile.SeekToBegin();
		CString str1;
		myFile.ReadString(str1);
		CString str2;
		myFile.ReadString(str2);
		AfxMessageBox(str1+str2);
	}
	myFile.Close();
}


/////////////////////////////////////////////////////////////////////////////////////////////////////

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


BOOL CDataprocessingDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	//如果处理可视化字符可以使用WM_CHAR, 使用WM_KEYDOWN时需判断大写键, Shift键, Ctrl键, Alt键是否按下
	if (pMsg->message == WM_CHAR)
	{
		//if(pMsg->wParam >= 'a' && pMsg->wParam <= 'z') 
		//{ AfxMessageBox("小写"); } 
		//else if(pMsg->wParam >= 'A' && pMsg->wParam <= 'Z') 
		//{ AfxMessageBox("大写"); } 
		CString str;
		str.Format("%c",pMsg->wParam);
		GetDlgItem(IDC_SQFivOut)->SetWindowText(str);
		flag_Q5 = 2;
	}
	while ((pMsg->message != WM_KEYDOWN)&&(flag_Q5 == 1))
	{
		GetDlgItem(IDC_SQFivOut)->SetWindowText(_T("Waiting for keyin."));
		break;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}



