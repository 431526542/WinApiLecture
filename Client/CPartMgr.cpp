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
	//실행된 프로그램의 위치를 받아오기
	GetCurrentDirectory(255, m_szContentPath);


	//상위폴더로 나가기
	int iLen = wcslen(m_szContentPath);
	for (int i = iLen - 1; 0 <= i; --i)
	{
		if ('\\' == m_szContentPath[i])
		{
			m_szContentPath[i] = '\0';
			break;
		}
	}

	// 경로에 bin\content를 붙인다
	wcscat_s(m_szContentPath, 255, L"\\bin\\content\\");
	
	//SetWindowText(CCore::GetInst()->GetMainHwnd(), m_szContentPath);
}

wstring CPartMgr::GetRelativePath(const wchar_t* _filepath)
{
	 
	wstring strFilePath = _filepath;

	size_t iAbsLen = wcslen(m_szContentPath);
	size_t iFullLen = strFilePath.length();
	wstring strRelativePath = strFilePath.substr(iAbsLen, iFullLen - iAbsLen);

	return strRelativePath;
}
