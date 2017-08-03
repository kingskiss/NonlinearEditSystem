#pragma once

#include "ClipPlayControlIO.h"
#include <vcclr.h>

using namespace System;

//#define _MAGICODE_CLIPPLAYCONTROL_

namespace ClrInterfaceDll
{
	/// <summary>
	/// ��˵������Ƶ���ſؼ��й���
	/// ���ڣ�2017-04-19
	/// ���ߣ�szwb
	/// �޸ģ�2017-05-19		���ע��
	/// </summary>
	public ref class ClipPlayControlCSharp
	{
	public:
		ClipPlayControlCSharp();

		//void Release();

		//���ز����ز�
		//������
		//1��szClipFileName ---- ����������ز��ļ�ȫ��������·�����ļ�����
		//2��hWnd ---- ����������ز�Ԥ�����ھ��
		//����ֵ��
		// S_OK ----- ���سɹ����������ʧ��
		//ע�⣺ֻ�ܼ��ظ���MP4��H264����Ƶ�ز�
		int SetClip(String^ strFileName, IntPtr hWnd);

		// ����set���ز�
		String^ GetClip();

		/////////////////////////////////////////////////////
		//�زĲ��ؽӿ�
		//����
		//����ֵ��S_OK = �ɹ������� ʧ��
		int Play();

		//��ͣ
		//����ֵ��S_OK = �ɹ������� ʧ��
		int Pause();

		//����ͣ�ָ�����
		//����ֵ��S_OK = �ɹ������� ʧ��
		int Continue();

		//ֹͣ
		//����ֵ��S_OK = �ɹ������� ʧ��
		int Stop();
		/////////////////////////////////////////////////////

		//��ȡ��ǰ����״̬
		//����ֵ��
		//	0 = �������У�1=��ͣ��2=ֹͣ��3=�رգ�
		// ����-1ʱ����ʾ�����ˣ�
		int GetCurState();

		//��ȡ�ز�ʱ��
		//����ֵ���ز�ʱ������λ��100ns;
		// ����-1ʱ����ʾ�����ˣ�
		long long GetDuration();

		//��ȡ��ǰ����λ��
		//����ֵ����ǰ����λ�ã���λ��100ns
		// ����-1ʱ����ʾ�����ˣ�
		long long GetPosition();

		//������㡢�����ǰ����λ��
		//������
		//  rtPos ---- ����ǰ����λ�ã���λ��100ns
		//  rtEndPos --- ���㣬�������Ϊ�ز�ĩβ���������ã�ֱ��ʹ��ȱʡֵ0����λ��100ns
		//����ֵ��S_OK = �ɹ������� ʧ��
		int SetPosition(long long rtPos, long long rtEndPos);

	private:
		CClipPlayControlIO* m_IClipPlayControl;

		String^ _strFileName;
	};
}