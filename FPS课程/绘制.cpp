#include "pch.h"
#include "绘制.h"

绘制::绘制(HWND 窗口句柄, DWORD 矩阵地址)
{
	m_窗口句柄 = 窗口句柄;
	m_矩阵地址 = 矩阵地址;
	memcpy(&m_矩阵, (PBYTE*)m_矩阵地址, sizeof(m_矩阵));
	取窗口信息();
}

void 绘制::取窗口信息()
{
	GetClientRect(m_窗口句柄, &m_窗口);
	m_分辨率宽 = m_窗口.right - m_窗口.left;
	m_分辨率高 = m_窗口.bottom - m_窗口.top;
	GetWindowRect(m_窗口句柄, &m_外窗口);
	m_外窗口宽 = m_外窗口.right - m_外窗口.left;
	m_外窗口高 = m_外窗口.bottom - m_外窗口.top;

}

void 绘制::绘制矩形(HDC HDC句柄, HBRUSH 画刷句柄, int x, int y, int w, int h)
{
	RECT 矩形 = {x, y, x + w, y + h};
	FillRect(HDC句柄, &矩形, 画刷句柄);
}

void 绘制::画线(HDC HDC句柄, int x, int y)
{
	取窗口信息();
	MoveToEx(HDC句柄, m_分辨率宽 / 2, m_分辨率高, 0);
	LineTo(HDC句柄, x, y);
}

void 绘制::画框(HDC HDC句柄, HBRUSH 画刷句柄, int x, int y, int w, int h, int 厚度)
{
	//顶边
	绘制矩形(HDC句柄, 画刷句柄, x, y, w, 厚度);
	//左边
	绘制矩形(HDC句柄, 画刷句柄, x, y+厚度, 厚度, h - 厚度);
	//右边
	绘制矩形(HDC句柄, 画刷句柄, x + w - 厚度, y+厚度, 厚度, h-厚度);
	//底边
	绘制矩形(HDC句柄, 画刷句柄, x + 厚度, y + h - 厚度, w - 2*厚度, 厚度);
}
HFONT 字体属性;
void 绘制::绘制字符串(HDC HDC句柄, int x, int y, COLORREF color, const char* text)
{
	SetTextAlign(HDC句柄, TA_CENTER | TA_NOUPDATECP);
	SetBkColor(HDC句柄, RGB(0, 0, 0));
	SetBkMode(HDC句柄, TRANSPARENT);
	SetTextColor(HDC句柄, color);
	SelectObject(HDC句柄, 字体属性);
	TextOutA(HDC句柄, x, y, text, strlen(text));
	DeleteObject(字体属性);
}

bool 绘制::世界坐标转屏幕坐标()
{
	取窗口信息();
	memcpy(&m_矩阵, (PBYTE*)m_矩阵地址, sizeof(m_矩阵));
	return false;
}

bool 绘制::世界坐标转屏幕坐标_非矩阵(坐标结构_2& 屏幕坐标, float 水平角度差, float 高低角度差)
{
	取窗口信息();
	FLOAT 高低可视角度 = (FLOAT)((double)atan2(m_分辨率高, m_分辨率宽) * 180 / 3.1416);
	if (fabs(水平角度差) > 45 || fabs(高低角度差) > 高低可视角度)
	{
		return false;//不在屏幕范围内
	}

	int 水平差 = (int)(tan(水平角度差 * 3.1416 / 180) * ((m_分辨率宽) / 2));
	屏幕坐标.x = (float)(m_分辨率宽 / 2 + 水平差);

	int 高度差 = (int)(tan(高低角度差 * 3.1416 / 180) * ((m_分辨率宽) / 2));
	屏幕坐标.y = (float)(m_分辨率高 / 2 + 高度差);
	return true;
}
