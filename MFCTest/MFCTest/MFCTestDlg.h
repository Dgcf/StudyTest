
// MFCTestDlg.h: 头文件
//
#include "Cabc.h"

#pragma once


// CMFCTestDlg 对话框
class CMFCTestDlg : public CDialogEx
{
// 构造
public:
	CMFCTestDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_list;
	CEdit editItem;
	int hitRow;
	int hitCol;

	int num;
	Cabc m_sub;
	bool m_bFullScreen;
	CRect m_FullScreenRect; //表示全屏显示时的窗口位置
		///////////////////////////////////////////////////
	//	全屏时保存原窗口信息,用来恢复窗口
	WINDOWPLACEMENT _temppl;		//window's placement
	CWnd* _tempparent;	//window's parent
	CRect m_rectSmall;
	CRect m_rectLarge;
	WINDOWPLACEMENT m_OldWndPlacement;
	void InitCtrl();

	int GetCurrentScreenMonitorRect(HWND hWnd, RECT& ScreenRect)
	{
		int nRet = 0;
		HMONITOR hMonitor = MonitorFromWindow(hWnd, MONITOR_DEFAULTTONEAREST);
		MONITORINFO mInfo;
		mInfo.cbSize = sizeof(MONITORINFO);
		if (GetMonitorInfo(hMonitor, &mInfo) == TRUE)
		{
			ScreenRect = mInfo.rcMonitor;
		}
		else
		{
			//取主窗口的信息
			HMONITOR hMonitor2 = MonitorFromWindow(hWnd, MONITOR_DEFAULTTOPRIMARY);
			MONITORINFO mInfo2;
			mInfo2.cbSize = sizeof(MONITORINFO);
			if (GetMonitorInfo(hMonitor2, &mInfo2) == TRUE)
			{
				ScreenRect = mInfo.rcMonitor;
			}
			else
			{
				ScreenRect.bottom = 0;
				ScreenRect.left = 0;
				ScreenRect.right = 0;
				ScreenRect.top = 0;
				nRet = -1;
			}
		}
		return nRet;
	}

	afx_msg void OnNMDblclkList2(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
};
