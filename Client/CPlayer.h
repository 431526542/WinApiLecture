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

    //만약 컴파일러라면 이렇게 컴파일 되고 굳이 따로 구현하지않아도 된다
    /*
    CPlayer(const CPlayer& _origin)
        : CObject(_origin)
        , m_pTex(_origin.m_pTex)
    {}
    */

    ~CPlayer();
};

