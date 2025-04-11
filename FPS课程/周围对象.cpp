#include "pch.h"
#include "周围对象.h"
DWORD Cs_周围基地址 = (DWORD)GetModuleHandleA("hl.exe") + 0x1B5A5C4;
DWORD Cs_周围基地址2 = (DWORD)GetModuleHandleA("hl.exe") + 0x62565C;

void 周围对象::刷新周围数据_Cs()
{
	对象数量 = 0;
	for (int i = 1; i < 0x20; i++)//从1开始遍历,不遍历自己
	{
		if (*(DWORD*)(Cs_周围基地址 + 0x24C * i + 0) == 0)//直接结束遍历
			break;
		if (*(DWORD*)(Cs_周围基地址 + 0x24C * i + 0x190) == 0)//碰到空坐标,跳过
			continue;
		对象列表[i].X_j = *(FLOAT*)(Cs_周围基地址 + 0x24C * i + 0x188);
		对象列表[i].Y_j = *(FLOAT*)(Cs_周围基地址 + 0x24C * i + 0x18C);
		对象列表[i].Z_j = *(FLOAT*)(Cs_周围基地址 + 0x24C * i + 0x190) - 40;

		对象列表[i].X_H = *(FLOAT*)(Cs_周围基地址 + 0x24C * i + 0x188);
		对象列表[i].Y_H = *(FLOAT*)(Cs_周围基地址 + 0x24C * i + 0x18C);
		对象列表[i].Z_H = *(FLOAT*)(Cs_周围基地址 + 0x24C * i + 0x190) + 23;

		对象列表[i].阵营 = *(BYTE*)(Cs_周围基地址2 + 0x68 * i + 0x4E);
		对象列表[i].Hp = *(DWORD*)(Cs_周围基地址2 + 0x68 * i + 0x68);
		对象列表[i].死亡标志位 = *(BYTE*)(Cs_周围基地址2 + 0x68 * i + 0x60);

		坐标结构_3 目标;
		目标.x = 对象列表[i].X_j;
		目标.y = 对象列表[i].Y_j;
		目标.z = 对象列表[i].Z_j;

		计算朝向_Cs(目标, 对象列表[i].角度_j, 对象列表[i].角度差_j);

		目标.x = 对象列表[i].X_H;
		目标.y = 对象列表[i].Y_H;
		目标.z = 对象列表[i].Z_H;
		计算朝向_Cs(目标, 对象列表[i].角度_H, 对象列表[i].角度差_H);

		对象数量 += 1;
	}
}

void 周围对象::计算朝向_Cs(坐标结构_3 目标, 朝向结构_2& 角度, 朝向结构_2& 角度差)
{
	float FOV_x = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x195fe58);
	float FOV_y = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x195fe5c);
	float FOV_z = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x195fe60);

	float 水平朝向 = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x19E10C8);
	float 高低朝向 = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x19E10C4);

	if (目标.x >= FOV_x && 目标.y >= FOV_y) //第一象限
	{
		角度.水平朝向 = atan2(目标.y - FOV_y, 目标.x - FOV_x) * 180 / 3.14159;
	}
	if (目标.x <= FOV_x && 目标.y > FOV_y) //第二象限
	{
		角度.水平朝向 = 180 - atan2(目标.y - FOV_y, FOV_x - 目标.x) * 180 / 3.14159;
	}
	if (目标.x < FOV_x && 目标.y < FOV_y) //第三象限
	{
		角度.水平朝向 = 180 + atan2(目标.y - FOV_y, FOV_x - 目标.x) * 180 / 3.14159;
	}
	if (目标.x > FOV_x && 目标.y <= FOV_y) //第四象限
	{
		角度.水平朝向 = 360 - atan2(目标.y - FOV_y, FOV_x - 目标.x) * 180 / 3.14159;
	}
	float 平面距离 = sqrt((FOV_x - 目标.x) * (FOV_x - 目标.x) + (目标.y - FOV_y) * (目标.y - FOV_y));
	if (目标.z > FOV_z) //上方
	{
		角度.高低朝向 = -atan2(目标.z - FOV_z, 平面距离) * 180 / 3.14159;
	}
	if (目标.z <= FOV_z) //下方
	{
		角度.高低朝向 = atan2(目标.z - FOV_z, 平面距离) * 180 / 3.14159;
	}

	角度差.水平朝向 = 水平朝向 - 角度.水平朝向;
	if (角度差.水平朝向 < -180)
	{
		角度差.水平朝向 += 360;
	}
	if (角度差.水平朝向 >= 180)
	{
		角度差.水平朝向 -= 360;
	}
	角度差.高低朝向 = 角度.高低朝向 - 高低朝向;
}
