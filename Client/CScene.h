#pragma once

//전방선언
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring			 m_strName; 

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	//순수 가상함수를 보유하고 있는 클래스는 추상클래스이고
	//실제 객체화 할 수 있는 클레스가 아니라
	//오로지 상속을 통하고 구현해야할 함수의 목록을 알리는 목적
	// 자식이 이 함수를 구현하지 않으면 구체화 불가능
	//	->반드시 구현해야한다 알릴 수 있음
	//부모클레스는 실수로라도 이 함수 구현 못하게함
	virtual void Enter() = 0; //해당 씬에 집입 시 호출
	virtual void Exit() = 0; //해당 씬 탈출시 호출

	void update();
	void render(HDC _dc);

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

	

public:
	CScene();
	virtual ~CScene();//상속목적으로 사용할 경우 소멸자에 가상함수 무조건
};

