#pragma once
struct ����ṹ_2
{
	float x, y;
};
struct ����ṹ_3
{
	float x, y, z;
};
struct ����ṹ_4
{
	float x, y, z, w;
};
class ����
{
public:
	HWND m_���ھ��;
	RECT m_����;
	int m_�ֱ��ʿ�;
	int m_�ֱ��ʸ�;
	RECT m_�ⴰ��;
	int m_�ⴰ�ڿ�;
	int m_�ⴰ�ڸ�;
	float m_����[16];
	DWORD m_�����ַ;
public:
	����(HWND ���ھ��, DWORD �����ַ);
	����()
	{

	}
private:
	void ȡ������Ϣ();
public:
	void ���ƾ���(HDC HDC���, HBRUSH ��ˢ���, int x, int y, int w, int h);
	void ����(HDC HDC���, int x, int y);
	void ����(HDC HDC���, HBRUSH ��ˢ���, int x, int y, int w, int h, int ���);
	void �����ַ���(HDC HDC���, int x, int y, COLORREF color, const char* text);
	bool ��������ת��Ļ����(����ṹ_3 ��Ϸ����, ����ṹ_2& ��Ļ����);
	bool ��������ת��Ļ����_�Ǿ���(����ṹ_2& ��Ļ����, float ˮƽ�ǶȲ�,float �ߵͽǶȲ�);
};

