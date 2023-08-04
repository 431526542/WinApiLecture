#pragma once
#include "CObject.h"
class CMonster :
    public CObject
{
private:
    Vec2    m_vCenterPos;
    float   m_fSpeed;
    float   m_fMaxDistance;
    int     m_iDir;

    

public:
    float GetSpeed() { return m_fSpeed; }
    float SetSpeed(float _f) { m_fSpeed = _f; }

    void SetCenterPos(Vec2 _vPos) { m_vCenterPos = _vPos; }
    void SetMoveDistance(float _f) { m_fMaxDistance = _f; }

public:
    virtual void update();
    virtual void render();

public:
    CMonster();
    ~CMonster();
};

