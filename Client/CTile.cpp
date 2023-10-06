#include "pch.h"
#include "CTile.h"


CTile::CTile()
{
	SetScale(Vec2(TILE_SIZE, TILE_SIZE));
}

CTile::~CTile()
{
}

void CTile::render(HDC _dc)
{
	Vec2 vRectangle = CCamera::GetInst()->GetRenderPos(GetPos());
	Vec2 vScale = GetScale();
	
	Rectangle(_dc	
		, int(vRectangle.x)
		, int(vRectangle.y)
		, int(vRectangle.x + vScale.x)
		, int(vRectangle.y + vScale.y));
}