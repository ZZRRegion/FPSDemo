#pragma once
#include<iostream>
#include<math.h>

struct 朝向结构_2
{
	float 水平朝向;
	float 高低朝向;
};
struct 对象结构
{
	float X_j;
	float Y_j;
	float Z_j;
	float X_H;
	float Y_H;
	float Z_H;
	int Hp;
	BYTE 死亡标志位;
	BYTE 阵营;
	朝向结构_2 角度_j;
	朝向结构_2 角度_H;
	朝向结构_2 角度差_j;
	朝向结构_2 角度差_H;
};
class 周围对象
{
public:
	对象结构 对象列表[0x100];
	DWORD 对象数量;
public:
	void 刷新周围数据_Cs();
private:
	void 计算朝向_Cs(坐标结构_3 目标, 朝向结构_2& 角度, 朝向结构_2& 角度差);
};

