#pragma once
#include<iostream>
#include<math.h>

struct ����ṹ_2
{
	float ˮƽ����;
	float �ߵͳ���;
};
struct ����ṹ
{
	float X_j;
	float Y_j;
	float Z_j;
	float X_H;
	float Y_H;
	float Z_H;
	int Hp;
	BYTE ������־λ;
	BYTE ��Ӫ;
	����ṹ_2 �Ƕ�_j;
	����ṹ_2 �Ƕ�_H;
	����ṹ_2 �ǶȲ�_j;
	����ṹ_2 �ǶȲ�_H;
};
class ��Χ����
{
public:
	����ṹ �����б�[0x100];
	DWORD ��������;
public:
	void ˢ����Χ����_Cs();
private:
	void ���㳯��_Cs(����ṹ_3 Ŀ��, ����ṹ_2& �Ƕ�, ����ṹ_2& �ǶȲ�);
};

