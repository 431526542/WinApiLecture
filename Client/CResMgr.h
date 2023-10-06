#pragma once

class CResource;
class CTexture;

class CResMgr
{
	SINGLE(CResMgr);

private:
	map<wstring, CResource*> m_mapTex;
public:
	CTexture* LoadTexture(const wstring& _strKey
		, const wstring& _strRelativePath);

	CTexture* FindTexture(const wstring& _strKey);
};

