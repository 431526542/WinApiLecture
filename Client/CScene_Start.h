#pragma once
#include "CScene.h"

class CScene_Start :
    public CScene
{

public:
    virtual void update();
    virtual void Enter(); //virtual을 꼭적어야 가상함수 가 아니라
    virtual void Exit();  //명시적으로 가상함수 인지 사람이 알기 쉽게 표시



public:
    CScene_Start();
    ~CScene_Start();
};

