#pragma once
#include "CScene.h"

class CScene_Start :
    public CScene
{

public:
    virtual void update();
    virtual void Enter(); //virtual�� ������� �����Լ� �� �ƴ϶�
    virtual void Exit();  //��������� �����Լ� ���� ����� �˱� ���� ǥ��



public:
    CScene_Start();
    ~CScene_Start();
};

