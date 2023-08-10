#include "pch.h"
#include "CCore.h"

#include "CTimeMgr.h"
#include "CKeyMgr.h"
#include "CSceneMgr.h"
#include "CPartMgr.h"
#include "CCollisionMgr.h"
#include "CEventMgr.h"

#include "CObject.h"

CCore::CCore()
	: m_hWnd(0)
	, m_ptResolution{}
	, m_hDC(0)
	, m_hBit(0)
	, m_mdmDC(0)
	, m_arrBrush{}
	, m_arrPen{}
{
}

CCore::~CCore()
{
	ReleaseDC(m_hWnd,m_hDC);

	DeleteDC(m_mdmDC);
	DeleteObject(m_hBit);

	for (int i = 0; i < (UINT)PEN_TYPE::END; ++i)
	{
		DeleteObject(m_arrPen[i]);
	}


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

	//자주 사용 할 펜 및 브러쉬 생성
	CreateBrushPen();

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

	//=============
	//Scene Update
	//=============
	CSceneMgr::GetInst()->update();

	//충돌체크
	CCollisionMgr::GetInst()->update();



	//==========
	//Rendering
	//==========
	//화면 Clear
	Rectangle(m_mdmDC, -1, -1, m_ptResolution.x + 1, m_ptResolution.y + 1);

	CSceneMgr::GetInst()->render(m_mdmDC);

	BitBlt(m_hDC, 0, 0, m_ptResolution.x, m_ptResolution.y
		, m_mdmDC, 0, 0, SRCCOPY);

	CTimeMgr::GetInst()->render();

	//이벤트 지연처리
	CEventMgr::GetInst()->update();
}

void CCore::CreateBrushPen()
{
	//브러쉬는 기본 제공
	m_arrBrush[(UINT)BRUSH_TYPE::HOLLOW] = (HBRUSH)GetStockObject(HOLLOW_BRUSH);

	// 펜은 내가 만듬
	m_arrPen[(UINT)PEN_TYPE::RED] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
	m_arrPen[(UINT)PEN_TYPE::BLUE] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
	m_arrPen[(UINT)PEN_TYPE::GREEN] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
}

