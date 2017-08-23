// 从类型库向导中用“添加类”创建的计算机生成的 IDispatch 包装器类
#ifdef _WIN64
#import "C:\\Program Files (x86)\\Common Files\\Huaqin\\Power.dll" no_namespace
#else
#import "C:\\Program Files\\Common Files\\Huaqin\\Power.dll" no_namespace
#endif

// CPowerGPIBDev 包装器类

class CPowerGPIBDev : public COleDispatchDriver
{
public:
	CPowerGPIBDev(){} // 调用 COleDispatchDriver 默认构造函数
	CPowerGPIBDev(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPowerGPIBDev(const CPowerGPIBDev& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// 特性
public:

	// 操作
public:


	// IPowerGPIBDev 方法
public:
	BOOL PowerOn()
	{
		BOOL result;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL PowerOff()
	{
		BOOL result;
		InvokeHelper(0x2, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	long Open()
	{
		long result;
		InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	BOOL Close()
	{
		BOOL result;
		InvokeHelper(0x4, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	BOOL SetCurr(double fCurrent)
	{
		BOOL result;
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0x5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, fCurrent);
		return result;
	}
	double GetCurr()
	{
		double result;
		InvokeHelper(0x6, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	BOOL SetVolt(double fVolt)
	{
		BOOL result;
		static BYTE parms[] = VTS_R8;
		InvokeHelper(0x7, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, fVolt);
		return result;
	}
	double GetVolt()
	{
		double result;
		InvokeHelper(0x8, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
		return result;
	}
	CString GetSupportType()
	{
		CString result;
		InvokeHelper(0x9, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long GetGPIBLastError()
	{
		long result;
		InvokeHelper(0xe, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void SysSleep()
	{
		InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void ReSet()
	{
		InvokeHelper(0x10, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void GPIBWrite(LPCTSTR GPIBCMD)
	{
		static BYTE parms[] = VTS_BSTR;
		InvokeHelper(0x16, DISPATCH_METHOD, VT_EMPTY, NULL, parms, GPIBCMD);
	}
	CString GPIBRead(long strLen)
	{
		CString result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x17, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, strLen);
		return result;
	}
	long SetArrTest(double iInterval, long iPoints)
	{
		long result;
		static BYTE parms[] = VTS_R8 VTS_I4;
		InvokeHelper(0x18, DISPATCH_METHOD, VT_I4, (void*)&result, parms, iInterval, iPoints);
		return result;
	}
	CString GetArrVolt()
	{
		CString result;
		InvokeHelper(0x19, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString GetArrCurr()
	{
		CString result;
		InvokeHelper(0x1a, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	long SetCurrRange(long RangeFlag)
	{
		long result;
		static BYTE parms[] = VTS_I4;
		InvokeHelper(0x1b, DISPATCH_METHOD, VT_I4, (void*)&result, parms, RangeFlag);
		return result;
	}

	// IPowerGPIBDev 属性
public:
	CString GetDeviceName()
	{
		CString result;
		GetProperty(0xa, VT_BSTR, (void*)&result);
		return result;
	}
	void SetDeviceName(CString propVal)
	{
		SetProperty(0xa, VT_BSTR, propVal);
	}
	CString GetDevicePort()
	{
		CString result;
		GetProperty(0xb, VT_BSTR, (void*)&result);
		return result;
	}
	void SetDevicePort(CString propVal)
	{
		SetProperty(0xb, VT_BSTR, propVal);
	}
	CString GetGPIBBoard()
	{
		CString result;
		GetProperty(0xc, VT_BSTR, (void*)&result);
		return result;
	}
	void SetGPIBBoard(CString propVal)
	{
		SetProperty(0xc, VT_BSTR, propVal);
	}
	CString GetGPIBAddress()
	{
		CString result;
		GetProperty(0xd, VT_BSTR, (void*)&result);
		return result;
	}
	void SetGPIBAddress(CString propVal)
	{
		SetProperty(0xd, VT_BSTR, propVal);
	}
	CString GetViRsrcName()
	{
		CString result;
		GetProperty(0x11, VT_BSTR, (void*)&result);
		return result;
	}
	void SetViRsrcName(CString propVal)
	{
		SetProperty(0x11, VT_BSTR, propVal);
	}
	long GetMAXVolt()
	{
		long result;
		GetProperty(0x12, VT_I4, (void*)&result);
		return result;
	}
	void SetMAXVolt(long propVal)
	{
		SetProperty(0x12, VT_I4, propVal);
	}
	CString GetVersion()
	{
		CString result;
		GetProperty(0x13, VT_BSTR, (void*)&result);
		return result;
	}
	void SetVersion(CString propVal)
	{
		SetProperty(0x13, VT_BSTR, propVal);
	}
	long GetErrorCode()
	{
		long result;
		GetProperty(0x14, VT_I4, (void*)&result);
		return result;
	}
	void SetErrorCode(long propVal)
	{
		SetProperty(0x14, VT_I4, propVal);
	}
	CString GetDeviceIDN()
	{
		CString result;
		GetProperty(0x15, VT_BSTR, (void*)&result);
		return result;
	}
	void SetDeviceIDN(CString propVal)
	{
		SetProperty(0x15, VT_BSTR, propVal);
	}

};
