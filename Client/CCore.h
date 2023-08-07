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

	//자주 사용하는 GDI object
	HBRUSH	m_arrBrush[(UINT)BRUSH_TYPE::END];
	HPEN	m_arrPen[(UINT)PEN_TYPE::END];

public:

public:
	int init(HWND _hWnd, POINT _ptResolution);
	void progress();

private:
	void CreateBrushPen();

public:
	HWND	GetMainHwnd() { return m_hWnd; }
	POINT	GetResolution() { return m_ptResolution; }
	HDC		GetMainDC() { return m_hDC; }

	HBRUSH	GetBrush(BRUSH_TYPE _eType) { return m_arrBrush[(UINT)_eType]; }
	HPEN	GetPen(PEN_TYPE _eType) { return m_arrPen[(UINT)_eType]; }
	

private:

};
