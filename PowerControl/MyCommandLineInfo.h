#pragma once
#include "afxwin.h"

enum ParamType
{
	PowerType=0,
	GPIBNum,
	GPIBAddr,
	VOL,
	CURR,
	OPENCLOSE,
	ParamNum,
};

class MyCommandLineInfo :
	public CCommandLineInfo
{
public:
	MyCommandLineInfo();
	~MyCommandLineInfo();
public:
	CString param[ParamNum];
	int nParam;
	
public:
	void ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast);
	void OpenPower();
};

