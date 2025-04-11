// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "pch.h"
HBRUSH 画刷句柄;
HDC HDC句柄;
COLORREF 文本颜色_红 = RGB(255, 0, 0);
COLORREF 文本颜色_白 = RGB(255, 255, 255);
COLORREF 文本颜色_黑 = RGB(0, 0, 0);
COLORREF 文本颜色_常用 = RGB(158, 255, 0);


坐标结构_2 屏幕坐标_j;
坐标结构_2 屏幕坐标_H;
周围对象 周围;
static int mainThread()
{
    绘制 FPS_绘制(FindWindowA(nullptr, ""), (DWORD)GetModuleHandleA("hl.exe") + 0x1820100);
    while (true)
    {
        HDC句柄 = GetDC(FPS_绘制.m_窗口句柄);
        周围.刷新周围数据_Cs();

        for (int i = 0; i < 周围.对象数量; i++)
        {
            if (周围.对象列表[i].死亡标志位 == 1)
                continue;
            if (FPS_绘制.世界坐标转屏幕坐标_非矩阵(屏幕坐标_j, 周围.对象列表[i].角度差_j.水平朝向, 周围.对象列表[i].角度差_j.高低朝向))
            {
                if (FPS_绘制.世界坐标转屏幕坐标_非矩阵(屏幕坐标_H, 周围.对象列表[i].角度差_H.水平朝向, 周围.对象列表[i].角度差_H.高低朝向))
                {
                    if (周围.对象列表[i].阵营 == 2)
                    {
                        画刷句柄 = CreateSolidBrush(文本颜色_常用);
                    }
                    if (周围.对象列表[i].阵营 == 1)
                    {
                        画刷句柄 = CreateSolidBrush(文本颜色_红);
                    }
                    float a = 屏幕坐标_j.y - 屏幕坐标_H.y;
                    FPS_绘制.画框(HDC句柄, 画刷句柄, 屏幕坐标_j.x + a / 4, 屏幕坐标_j.y, -a / 2, -a, 1);
                    DeleteObject(画刷句柄);
                }
            }
        }
        DeleteObject(HDC句柄);
        Sleep(1);
    }
}
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)mainThread, 0, 0, 0);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

