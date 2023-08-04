#include "pch.h"
#include "CPlayer.h"

#include "CScene.h"

#include "CSceneMgr.h"
#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CMissile.h"

#include "CResMgr.h"
#include "CTexture.h"

CPlayer::CPlayer()
	: m_pTex(nullptr)
{
	//texture load
	m_pTex = CResMgr::GetInst()->LoadTexture(L"PlayerTex", L"texture\\Player.bmp");
	
}

CPlayer::~CPlayer()
{
	
}

void CPlayer::update()
{
	Vec2 vPos = GetPos();

	if (KEY_HOLE(KEY::W))
	{
		vPos.y -= 200.f * fDT;
	}
	if (KEY_HOLE(KEY::S))
	{
		vPos.y += 200.f * fDT;
	}
	if (KEY_HOLE(KEY::A))
	{
		vPos.x -= 200.f * fDT;
	}
	if (KEY_HOLE(KEY::D))
	{
		vPos.x += 200.f * fDT;
	}
	if (KEY_TAP(KEY::SPACE))
	{
		CreateMissile();
	}

	SetPos(vPos);
}

void CPlayer::render(HDC _dc)
{
	int iWidth = (int)m_pTex->Width();
	int iHeight = (int)m_pTex->Height();

	Vec2 vPos = GetPos();

	/*BitBlt(_dc
		, (int)(vPos.x - (float)(iWidth / 2))
		, (int)(vPos.y - (float)(iHeight / 2))
		, iWidth, iHeight
		, m_pTex->GetDC()
		, 0, 0, SRCCOPY);
	*/
	
	//내가 원하는 색상을 제외하고 받는법
	TransparentBlt(_dc
			, (int)(vPos.x - (float)(iWidth / 2))
			, (int)(vPos.y - (float)(iHeight / 2))
			, iWidth, iHeight
			, m_pTex->GetDC()
			, 0, 0, iWidth, iHeight
			,RGB(255,0,255));
}

void CPlayer::CreateMissile()
{
	Vec2 vMissilePos = GetPos();
	vMissilePos.y -= GetScale().y / 2;

	CMissile* pMissile = new CMissile;
	pMissile->SetPos(vMissilePos);
	pMissile->SetScale(Vec2(20.f, 20.f));
	pMissile->SetDir(Vec2(0.0f, -1.0f));
	CScene* pCurScene = CSceneMgr::GetInst()->GetCurScene();
	pCurScene->AddObject(pMissile, GROUP_TYPE::MISSILE);
}
