#include "pch.h"
#include "��Χ����.h"
DWORD Cs_��Χ����ַ = (DWORD)GetModuleHandleA("hl.exe") + 0x1B5A5C4;
DWORD Cs_��Χ����ַ2 = (DWORD)GetModuleHandleA("hl.exe") + 0x62565C;

void ��Χ����::ˢ����Χ����_Cs()
{
	�������� = 0;
	for (int i = 1; i < 0x20; i++)//��1��ʼ����,�������Լ�
	{
		if (*(DWORD*)(Cs_��Χ����ַ + 0x24C * i + 0) == 0)//ֱ�ӽ�������
			break;
		if (*(DWORD*)(Cs_��Χ����ַ + 0x24C * i + 0x190) == 0)//����������,����
			continue;
		�����б�[i].X_j = *(FLOAT*)(Cs_��Χ����ַ + 0x24C * i + 0x188);
		�����б�[i].Y_j = *(FLOAT*)(Cs_��Χ����ַ + 0x24C * i + 0x18C);
		�����б�[i].Z_j = *(FLOAT*)(Cs_��Χ����ַ + 0x24C * i + 0x190) - 40;

		�����б�[i].X_H = *(FLOAT*)(Cs_��Χ����ַ + 0x24C * i + 0x188);
		�����б�[i].Y_H = *(FLOAT*)(Cs_��Χ����ַ + 0x24C * i + 0x18C);
		�����б�[i].Z_H = *(FLOAT*)(Cs_��Χ����ַ + 0x24C * i + 0x190) + 23;

		�����б�[i].��Ӫ = *(BYTE*)(Cs_��Χ����ַ2 + 0x68 * i + 0x4E);
		�����б�[i].Hp = *(DWORD*)(Cs_��Χ����ַ2 + 0x68 * i + 0x68);
		�����б�[i].������־λ = *(BYTE*)(Cs_��Χ����ַ2 + 0x68 * i + 0x60);

		����ṹ_3 Ŀ��;
		Ŀ��.x = �����б�[i].X_j;
		Ŀ��.y = �����б�[i].Y_j;
		Ŀ��.z = �����б�[i].Z_j;

		���㳯��_Cs(Ŀ��, �����б�[i].�Ƕ�_j, �����б�[i].�ǶȲ�_j);

		Ŀ��.x = �����б�[i].X_H;
		Ŀ��.y = �����б�[i].Y_H;
		Ŀ��.z = �����б�[i].Z_H;
		���㳯��_Cs(Ŀ��, �����б�[i].�Ƕ�_H, �����б�[i].�ǶȲ�_H);

		�������� += 1;
	}
}

void ��Χ����::���㳯��_Cs(����ṹ_3 Ŀ��, ����ṹ_2& �Ƕ�, ����ṹ_2& �ǶȲ�)
{
	float FOV_x = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x195fe58);
	float FOV_y = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x195fe5c);
	float FOV_z = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x195fe60);

	float ˮƽ���� = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x19E10C8);
	float �ߵͳ��� = *(float*)((DWORD)GetModuleHandleA("hl.exe") + 0x19E10C4);

	if (Ŀ��.x >= FOV_x && Ŀ��.y >= FOV_y) //��һ����
	{
		�Ƕ�.ˮƽ���� = atan2(Ŀ��.y - FOV_y, Ŀ��.x - FOV_x) * 180 / 3.14159;
	}
	if (Ŀ��.x <= FOV_x && Ŀ��.y > FOV_y) //�ڶ�����
	{
		�Ƕ�.ˮƽ���� = 180 - atan2(Ŀ��.y - FOV_y, FOV_x - Ŀ��.x) * 180 / 3.14159;
	}
	if (Ŀ��.x < FOV_x && Ŀ��.y < FOV_y) //��������
	{
		�Ƕ�.ˮƽ���� = 180 + atan2(Ŀ��.y - FOV_y, FOV_x - Ŀ��.x) * 180 / 3.14159;
	}
	if (Ŀ��.x > FOV_x && Ŀ��.y <= FOV_y) //��������
	{
		�Ƕ�.ˮƽ���� = 360 - atan2(Ŀ��.y - FOV_y, FOV_x - Ŀ��.x) * 180 / 3.14159;
	}
	float ƽ����� = sqrt((FOV_x - Ŀ��.x) * (FOV_x - Ŀ��.x) + (Ŀ��.y - FOV_y) * (Ŀ��.y - FOV_y));
	if (Ŀ��.z > FOV_z) //�Ϸ�
	{
		�Ƕ�.�ߵͳ��� = -atan2(Ŀ��.z - FOV_z, ƽ�����) * 180 / 3.14159;
	}
	if (Ŀ��.z <= FOV_z) //�·�
	{
		�Ƕ�.�ߵͳ��� = atan2(Ŀ��.z - FOV_z, ƽ�����) * 180 / 3.14159;
	}

	�ǶȲ�.ˮƽ���� = ˮƽ���� - �Ƕ�.ˮƽ����;
	if (�ǶȲ�.ˮƽ���� < -180)
	{
		�ǶȲ�.ˮƽ���� += 360;
	}
	if (�ǶȲ�.ˮƽ���� >= 180)
	{
		�ǶȲ�.ˮƽ���� -= 360;
	}
	�ǶȲ�.�ߵͳ��� = �Ƕ�.�ߵͳ��� - �ߵͳ���;
}
