#pragma once
struct 坐标结构_2
{
	float x, y;
};
class 绘制
{
public:
	HWND m_窗口句柄;
	RECT m_窗口;
	int m_分辨率宽;
	int m_分辨率高;
	RECT m_外窗口;
	int m_外窗口宽;
	int m_外窗口高;
	float m_矩阵[16];
	DWORD m_矩阵地址;
public:
	绘制(HWND 窗口句柄, DWORD 矩阵地址);
	绘制()
	{

	}
private:
	void 取窗口信息();
public:
	void 绘制矩形(HDC HDC句柄, HBRUSH 画刷句柄, int x, int y, int w, int h);
	void 画线(HDC HDC句柄, int x, int y);
	void 画框(HDC HDC句柄, HBRUSH 画刷句柄, int x, int y, int w, int h, int 厚度);
	void 绘制字符串(HDC HDC句柄, int x, int y, COLORREF color, const char* text);
	bool 世界坐标转屏幕坐标();
	bool 世界坐标转屏幕坐标_非矩阵(坐标结构_2& 屏幕坐标, float 水平角度差,float 高低角度差);
};

