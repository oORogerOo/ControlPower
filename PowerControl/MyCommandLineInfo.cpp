#include "stdafx.h"
#include "MyCommandLineInfo.h"
#include "CPowerGPIBDev.h"


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
		return;
	}

	if (!spPowerDisp1.CreateDispatch(_T("Power.GPiBDev")))
	{

	}
	else
	{
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
		}

	}
	::CoUninitialize();


}