#include "pch.h"
#include "����.h"

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
