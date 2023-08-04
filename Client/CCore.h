#pragma once

/*
class CCore
{
private:
	static CCore* g_pInst;

public:


	static CCore* GetInstance()
	{
		if (nullptr == g_pInst)
		{
			g_pInst = new CCore;
		}

		return g_pInst;
	}

	static void Release()
	{
		if (nullptr != g_pInst)
		{
			delete g_pInst;
			g_pInst = nullptr;
		}
	}


private:
	CCore();
	~CCore();
};*/
class CCore
{
	SINGLE(CCore);
private:
	HWND	m_hWnd;
	POINT	m_ptResolution;
	HDC		m_hDC;

	HBITMAP m_hBit;
	HDC		m_mdmDC;

public:

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

public:
	HWND GetMainHwnd() { return m_hWnd; }
	POINT GetResolution() { return m_ptResolution; }
	HDC GetMainDC() { return m_hDC; }
	

private:

};
