
// PowerControl.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPowerControlApp: 
// �йش����ʵ�֣������ PowerControl.cpp
//

class CPowerControlApp : public CWinApp
{
public:
	CPowerControlApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPowerControlApp theApp;