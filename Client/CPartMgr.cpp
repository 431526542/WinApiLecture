#include "pch.h"
#include "CPartMgr.h"

#include "CCore.h"

CPartMgr::CPartMgr()
	: m_szContentPath{}
{

}

CPartMgr::~CPartMgr()
{

}

void CPartMgr::init()
{
	//����� ���α׷��� ��ġ�� �޾ƿ���
	GetCurrentDirectory(255, m_szContentPath);


	//���������� ������
	int iLen = wcslen(m_szContentPath);
	for (int i = iLen - 1; 0 <= i; --i)
	{
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	// ��ο� bin\content�� ���δ�
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");
	
	//SetWindowText(CCore::GetInst()->GetMainHwnd(), m_szContentPath);
}
