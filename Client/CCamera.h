#pragma once

class CObject;

class CCamera
{
	SINGLE(CCamera);

private:
	Vec2		m_vLookAt; //내가진짜 보고있는곳
	Vec2		m_vCurLookAt;//이전위치와 현재위치 보정위치
	Vec2		m_vPrevLookAt;//이번프레임

	CObject*	m_pTargetObj;
	Vec2		m_vDiff;

	float		m_fTime; // 타겟을 따라가는데 걸리는 시간
	float		m_fSpeed;//타겟을 따라가는 속도
	float		m_fAccTime;

public:
	void SetLookAt(Vec2 _vLook) 
	{
		m_vLookAt = _vLook;
		float fMoveDist = (m_vLookAt - m_vPrevLookAt).Length();
		m_fSpeed = fMoveDist / m_fTime;
		m_fAccTime = 0.f;
	}
	void SetTarget(CObject* _pTarget) { m_pTargetObj = _pTarget; }
	Vec2 GetLookAt() { return m_vCurLookAt; }
	Vec2 GetRenderPos(Vec2 _vObjPos) { return _vObjPos - m_vDiff; }
	Vec2 GetRealPos(Vec2 _vRenderPos) { return _vRenderPos + m_vDiff; }

public:
	void update();

private:
	void CalDiff();


};

