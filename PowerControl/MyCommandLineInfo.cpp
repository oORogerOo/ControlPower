#include "stdafx.h"
#include "MyCommandLineInfo.h"
#include "CPowerGPIBDev.h"



#include "..\\PowerControl\\ProcessLog\\ProcessLog.h"
#ifdef _WIN64
#pragma comment(lib,"..\\PowerControl\\ProcessLog\\x64\\ProcessLog.lib")
#else
#pragma comment(lib,"..\\PowerControl\\ProcessLog\\x86\\ProcessLog.lib")
#endif

MyCommandLineInfo::MyCommandLineInfo()
{
	nParam = 0;
}


MyCommandLineInfo::~MyCommandLineInfo()
{
}


void MyCommandLineInfo::ParseParam(const TCHAR* pszParam, BOOL bFlag, BOOL bLast)
{
	CString sArg(pszParam);
	if (bFlag)
	{
		if (nParam >= ParamNum)
		{

		}
		else
		{
			param[nParam] = sArg;
			nParam++;
		}
	}
	else if (m_strFileName.IsEmpty())
	{

	}
	CCommandLineInfo::ParseParam(pszParam, bFlag, bLast);
}

void MyCommandLineInfo::OpenPower()
{

	CPowerGPIBDev spPowerDisp1;
	
	if (::CoInitialize(NULL) == E_INVALIDARG)
	{
		ProcessLog(L"CoInitialize Fail", LOGDEBUG);
		return;
	}

	if (!spPowerDisp1.CreateDispatch(_T("Power.GPiBDev")))
	{
		ProcessLog(L"spPowerDisp1.CreateDispatch Fail", LOGDEBUG);
	}
	else
	{
		for (int i = 0; i < ParamNum; i++)
		{
			ProcessLog(param[i].GetBuffer(), LOGDEBUG);
			param[i].ReleaseBuffer();
		}
			

		if (param[OPENCLOSE] == _T("1"))
		{
			float fCurr;
			float fVol;
			spPowerDisp1.SetMAXVolt(15.0);//设置最大电压
			spPowerDisp1.SetDeviceName(param[PowerType]);
			spPowerDisp1.SetGPIBBoard(param[GPIBNum]);
			spPowerDisp1.SetGPIBAddress(param[GPIBAddr]);
			spPowerDisp1.Open();
			fCurr = _tstof(param[CURR]);
			spPowerDisp1.SetCurr(fCurr);
			fVol = _tstof(param[VOL]);
			spPowerDisp1.SetVolt(fVol);
			spPowerDisp1.PowerOn();
			spPowerDisp1.ReleaseDispatch();
			ProcessLog(_T("打开电源"), LOGDEBUG);
		}
		else
		{
			spPowerDisp1.SetDeviceName(param[PowerType]);
			spPowerDisp1.SetGPIBBoard(param[GPIBNum]);
			spPowerDisp1.SetGPIBAddress(param[GPIBAddr]);
			spPowerDisp1.Open();
			spPowerDisp1.SetVolt(0);
			spPowerDisp1.PowerOff();
			spPowerDisp1.Close();
			spPowerDisp1.ReleaseDispatch();
			ProcessLog(_T("关闭电源"), LOGDEBUG);
		}

	}
	::CoUninitialize();


}