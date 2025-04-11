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
