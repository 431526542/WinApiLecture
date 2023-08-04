#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CPartMgr.h"

#include "CObject.h"

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_mdmDC(0)
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd,m_hDC);

	DeleteDC(m_mdmDC);
	DeleteObject(m_hBit);
}

int CCore::init(HWND _hWnd, POINT _ptResolution)
{
	m_hWnd = _hWnd;
	m_ptResolution = _ptResolution;


	//해상도 윈도우 크기에 조정
	RECT rt = { 0,0,m_ptResolution.x,m_ptResolution.y };
	AdjustWindowRect(&rt,WS_OVERLAPPEDWINDOW,true);
	SetWindowPos(m_hWnd, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	//
	m_hDC = GetDC(m_hWnd);

	//렌더링
	//이중 버퍼링 용더의 비트맵과 DC를 만든다
	m_hBit = CreateCompatibleBitmap(m_hDC, m_ptResolution.x, m_ptResolution.y);
	m_mdmDC = CreateCompatibleDC(m_hDC);

	HBITMAP hOldBit = (HBITMAP)SelectObject(m_mdmDC, m_hBit);
	DeleteObject(hOldBit);

	//Manager 초기화
	CPartMgr::GetInst()->init();
	CTimeMgr::GetInst()->init();
	CKeyMgr::GetInst()->init();
	CSceneMgr::GetInst()->init();


	return S_OK;
}


void CCore::progress()
{
	//Manager Update
	CTimeMgr::GetInst()->update();
	CKeyMgr::GetInst()->update();
	CSceneMgr::GetInst()->update();


	//==========
	//Rendering
	//==========
	//화면 Clear
	Rectangle(m_mdmDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInst()->render(m_mdmDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		, m_mdmDC, 0, 0, SRCCOPY);

	//CTimeMgr::GetInst()->render();
}

