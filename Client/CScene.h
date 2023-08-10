#pragma once

//���漱��
class CObject;

class CScene
{
private:
	vector<CObject*> m_arrObj[(UINT)GROUP_TYPE::END];
	wstring			 m_strName; 

public:
	void SetName(const wstring& _strName) { m_strName = _strName; }
	const wstring& GetName() { return m_strName; }

	//���� �����Լ��� �����ϰ� �ִ� Ŭ������ �߻�Ŭ�����̰�
	//���� ��üȭ �� �� �ִ� Ŭ������ �ƴ϶�
	//������ ����� ���ϰ� �����ؾ��� �Լ��� ����� �˸��� ����
	// �ڽ��� �� �Լ��� �������� ������ ��üȭ �Ұ���
	//	->�ݵ�� �����ؾ��Ѵ� �˸� �� ����
	//�θ�Ŭ������ �Ǽ��ζ� �� �Լ� ���� ���ϰ���
	virtual void Enter() = 0; //�ش� ���� ���� �� ȣ��
	virtual void Exit() = 0; //�ش� �� Ż��� ȣ��

	virtual void update();
	virtual void finalupdate();
	virtual void render(HDC _dc);

public:
	void AddObject(CObject* _pObj, GROUP_TYPE _eType)
	{
		m_arrObj[(UINT)_eType].push_back(_pObj);
	}

	const vector<CObject*>& GetGroupObject(GROUP_TYPE _eType) 
	{
		return m_arrObj[(UINT)_eType];
	}

	void DeleteGroup(GROUP_TYPE _eTarget);
	void DeleteAll();

public:
	CScene();
	virtual ~CScene();//��Ӹ������� ����� ��� �Ҹ��ڿ� �����Լ� ������
};

