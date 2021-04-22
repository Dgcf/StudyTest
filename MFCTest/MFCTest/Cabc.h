#pragma once


// Cabc 对话框
#include <string>
using namespace std;

class Cabc : public CDialogEx
{
	DECLARE_DYNAMIC(Cabc)

public:
	Cabc(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Cabc();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString a;
	CString b;
	CString c;
	CString d;
	CString e;
	afx_msg void OnBnClickedOk();
};
