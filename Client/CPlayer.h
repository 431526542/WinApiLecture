#pragma once
#include "CObject.h"

class CTexture;

class CPlayer :
    public CObject
{
private:
    //CTexture* m_pTex;

public:
    virtual void update();
    virtual void render(HDC _dc);

public:
    void CreateMissile();

    CLONE(CPlayer);

public:
    CPlayer();

    //���� �����Ϸ���� �̷��� ������ �ǰ� ���� ���� ���������ʾƵ� �ȴ�
    /*
    CPlayer(const CPlayer& _origin)
        : CObject(_origin)
        , m_pTex(_origin.m_pTex)
    {}
    */

    ~CPlayer();
};

