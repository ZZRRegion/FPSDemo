#include "pch.h"

����::����(HWND ���ھ��, DWORD �����ַ)
{
	m_���ھ�� = ���ھ��;
	m_�����ַ = �����ַ;
	memcpy(&m_����, (PBYTE*)m_�����ַ, sizeof(m_����));
	ȡ������Ϣ();
}

void ����::ȡ������Ϣ()
{
	GetClientRect(m_���ھ��, &m_����);
	m_�ֱ��ʿ� = m_����.right - m_����.left;
	m_�ֱ��ʸ� = m_����.bottom - m_����.top;
	GetWindowRect(m_���ھ��, &m_�ⴰ��);
	m_�ⴰ�ڿ� = m_�ⴰ��.right - m_�ⴰ��.left;
	m_�ⴰ�ڸ� = m_�ⴰ��.bottom - m_�ⴰ��.top;

}

void ����::���ƾ���(HDC HDC���, HBRUSH ��ˢ���, int x, int y, int w, int h)
{
	RECT ���� = {x, y, x + w, y + h};
	FillRect(HDC���, &����, ��ˢ���);
}

void ����::����(HDC HDC���, int x, int y)
{
	ȡ������Ϣ();
	MoveToEx(HDC���, m_�ֱ��ʿ� / 2, m_�ֱ��ʸ�, 0);
	LineTo(HDC���, x, y);
}

void ����::����(HDC HDC���, HBRUSH ��ˢ���, int x, int y, int w, int h, int ���)
{
	//����
	���ƾ���(HDC���, ��ˢ���, x, y, w, ���);
	//���
	���ƾ���(HDC���, ��ˢ���, x, y+���, ���, h - ���);
	//�ұ�
	���ƾ���(HDC���, ��ˢ���, x + w - ���, y+���, ���, h-���);
	//�ױ�
	���ƾ���(HDC���, ��ˢ���, x + ���, y + h - ���, w - 2*���, ���);
}
HFONT ��������;
void ����::�����ַ���(HDC HDC���, int x, int y, COLORREF color, const char* text)
{
	SetTextAlign(HDC���, TA_CENTER | TA_NOUPDATECP);
	SetBkColor(HDC���, RGB(0, 0, 0));
	SetBkMode(HDC���, TRANSPARENT);
	SetTextColor(HDC���, color);
	SelectObject(HDC���, ��������);
	TextOutA(HDC���, x, y, text, strlen(text));
	DeleteObject(��������);
}

bool ����::��������ת��Ļ����(����ṹ_3 ��Ϸ����, ����ṹ_2& ��Ļ����)
{
	ȡ������Ϣ();
	memcpy(&m_����, (PBYTE*)m_�����ַ, sizeof(m_����));
	����ṹ_4 ��������;
	��������.x = ��Ϸ����.x * m_����[0] + ��Ϸ����.y * m_����[4] + ��Ϸ����.z * m_����[8] + m_����[12];
	��������.y = ��Ϸ����.x * m_����[1] + ��Ϸ����.y * m_����[5] + ��Ϸ����.z * m_����[9] + m_����[13];
	��������.z = ��Ϸ����.x * m_����[2] + ��Ϸ����.y * m_����[6] + ��Ϸ����.z * m_����[10] + m_����[14];
	��������.w = ��Ϸ����.x * m_����[3] + ��Ϸ����.y * m_����[7] + ��Ϸ����.z * m_����[11] + m_����[15];

	if (��������.w < 0.0f)
	{
		return false;
	}
	����ṹ_3 NDC;
	NDC.x = ��������.x / ��������.w;
	NDC.y = ��������.y / ��������.w;
	NDC.z = ��������.z / ��������.w;

	��Ļ����.x = (m_�ֱ��ʿ� / 2) * NDC.x + m_�ֱ��ʿ� / 2;
	��Ļ����.y = -(m_�ֱ��ʸ� / 2) * NDC.y + m_�ֱ��ʸ� / 2;
	return true;
}

bool ����::��������ת��Ļ����_�Ǿ���(����ṹ_2& ��Ļ����, float ˮƽ�ǶȲ�, float �ߵͽǶȲ�)
{
	ȡ������Ϣ();
	FLOAT �ߵͿ��ӽǶ� = (FLOAT)((double)atan2(m_�ֱ��ʸ�, m_�ֱ��ʿ�) * 180 / 3.1416);
	if (fabs(ˮƽ�ǶȲ�) > 45 || fabs(�ߵͽǶȲ�) > �ߵͿ��ӽǶ�)
	{
		return false;//������Ļ��Χ��
	}

	int ˮƽ�� = (int)(tan(ˮƽ�ǶȲ� * 3.1416 / 180) * ((m_�ֱ��ʿ�) / 2));
	��Ļ����.x = (float)(m_�ֱ��ʿ� / 2 + ˮƽ��);

	int �߶Ȳ� = (int)(tan(�ߵͽǶȲ� * 3.1416 / 180) * ((m_�ֱ��ʿ�) / 2));
	��Ļ����.y = (float)(m_�ֱ��ʸ� / 2 + �߶Ȳ�);
	return true;
}
