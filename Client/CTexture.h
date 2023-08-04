#pragma once
#include "CResource.h"


class CTexture :
    public CResource
{
private:
    HDC     m_dc;
    HBITMAP m_hBit;
    BITMAP  m_bitInfo;//� ��Ʈ���� ������ �����ϴ� ����ä

public:
    void Load(const wstring& _strFilePath);

    UINT Width() { return m_bitInfo.bmWidth; }
    UINT Height() { return m_bitInfo.bmHeight; }

    HDC GetDC() { return m_dc; }

private:
    CTexture();
    ~CTexture();

    friend class CResMgr;
};
