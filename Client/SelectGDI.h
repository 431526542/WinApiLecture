#pragma once


class SelectGDI
{
private:
	HDC		m_hDC;
	HPEN	m_hDefaultPen;
	HBRUSH	m_hDefaultBrush;
public:
	SelectGDI(HDC _dc, PEN_TYPE _ePenTypel);
	SelectGDI(HDC _dc, BRUSH_TYPE _eBrushTypel);
	~SelectGDI();
};

