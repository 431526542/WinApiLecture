#pragma once

class CTimeMgr
{
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER m_llCurCount;
	LARGE_INTEGER m_llPrevCount;
	LARGE_INTEGER m_llFrequency;

	double		m_dDT; //프레임간 시간값
	double		m_dAcc;
	UINT		m_iCallCount; //함수 횟수 체크
	UINT		m_iFPS;	//초당 호출 횟수
	
public:
	void init();
	void update();
	void render();

public:
	double GetDT() { return m_dDT; }
	float GetfDT() { return (float)m_dDT; }
};

