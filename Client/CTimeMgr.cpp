#include "pch.h"
#include "CTimeMgr.h"

#include "CCore.h"
 

CTimeMgr::CTimeMgr()
	: m_llCurCount{}
	, m_llPrevCount{}
	, m_llFrequency{}
	, m_dDT(0)
	, m_dAcc(0.f)
	, m_iCallCount(0)
	, m_iFPS(0)
{

}

CTimeMgr::~CTimeMgr()
{

}

void CTimeMgr::init()
{
	QueryPerformanceCounter(&m_llPrevCount);

	QueryPerformanceFrequency(&m_llFrequency);
}

void CTimeMgr::update()
{
	QueryPerformanceCounter(&m_llCurCount);

	//이전 프레임의 카운팅과 현재 프레임 카운팅 값을 차이를 구한다.
	m_dDT = (double)(m_llCurCount.QuadPart - m_llPrevCount.QuadPart) / (double)(m_llFrequency.QuadPart);

	//이전 카운트 값을 현재 카운트 값으로 갱신
	m_llPrevCount = m_llCurCount;

#ifdef  _DEBUG
	if (m_dDT > 1. / 60.)
	{
		m_dDT = (1. / 60.);
	}
#endif //  _DEBUG
}

void CTimeMgr::render()
{
	++m_iCallCount;
	m_dAcc += m_dDT; //DT누적 <-흘러간 시간

	if (m_dAcc >= 1.f) //1초가 흘러간시간 체크
	{
		m_iFPS = m_iCallCount;
		m_iCallCount = 0.f;

		m_dAcc = 0.f;


		wchar_t szBuffer[255] = {};
		swprintf_s(szBuffer, L"FPS : %d, DT : %f", m_iFPS, m_dDT);
		SetWindowText(CCore::GetInst()->GetMainHwnd(), szBuffer);

	}
}
