#pragma once

#include "ClipPlayControlIO.h"
#include <vcclr.h>

#using "ClrDataTypeChange.dll"

using namespace System;
using namespace ClrDataTypeChange;

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
		//int SetClip(String^ strFileName, IntPtr hWnd);

		//int SetClip(String^ szClipFileName, ZimuMixInfoList^ ZimuList, IntPtr hWnd);


		/////////////////////////////////////////////////////
		//��Ļ�༭�����ӿ�  --- begin

		//���ܣ����һ����Ļ��������Ļ�ļ��ϵ������
		//������
		//szZimuFile ---- �����������ӵ���Ļ�ļ�ȫ����
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		//˵�����ýӿ���Ҫ����Ļ�ļ���ȡ��Ļ֡���ݣ�����ǵ�һ�δ򿪿�����Ҫһ��ʱ�䣬�����߱���ȴ��ú������ز��ܽ�����һ������
		int AddZimuIO(String^ szZimuFile);

		//���ܣ�ɾ��һ����Ļ�����ѹ���ϵ���Ļɾ��
		//������
		//szZimuFile ---- �����������ɾ������Ļ�ļ�ȫ����
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		int DeleteZimuIO(String^ szZimuFile);

		//���ܣ��޸�һ����Ļ�����ѹ����һ����Ļ��λ�á�����ʱ��Ƚ����޸�
		//������
		//szZimuFile ---- ������������޸ĵ���Ļ�ļ�ȫ����
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		int ModifyZimuIO(String^ szZimuFile);

		//��Ļ�༭�����ӿ�  --- end
		/////////////////////////////////////////////////////

		//���ض������Ƶ�ز�
		//������
		//1��AVClipList ---- �������������Ƶ�ز��б��б��е�����Ƶ��ǰ��˳����������
		//2��ZimuList ---- �����������Ҫ���ӵ���Ļ�б�
		//3��hWnd ---- ����������ز�Ԥ�����ھ��
		//����ֵ��
		// S_OK ----- ���سɹ����������ʧ��
		//ע�⣺
		//1��ֻ�ܼ��ظ���MP4��H264����Ƶ�ز�
		//2��CClipPlayControlIO�ṩ���������нӿڶ�����SetMultiClips�ɹ����غ����Ч�ģ�
		int SetMultiClipsIO(AVClipInfoList^ AVClipList, ZimuMixInfoList^ ZimuList, IntPtr hWnd);
		//int SetClip(String^ szClipFileName, ZimuMixInfoList^ ZimuList, IntPtr hWnd);


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

		//�϶��زĵ�ָ��λ��
		//������
		//  rtPos ---- ���������ָ��λ�õ�ʱ�䣬��λ��100ns
		int SetGivenPosition(long long rtPos);
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


		//����ָ��֡ͼ��ΪBMP�ļ�
		//������
		//1��szBmpFileName ---- ���������Bmpͼ���ļ�ȫ��������·�����ļ�����
		//2��rtPos ---- ����������������֡ͼ������ʱ�̣���λ��100ns
		//˵���������ͼƬΪ24λ1920*1080��С��BMPͼ
		void SaveGivenFrameToBmp(String^ szBmpFileName, long long rtPos);


		// ��Ƶ��Ϣ�ṹ��ת��
		AVClipInfo ConvertToAVClipInfoList(tagAVClipInfoCLR^ ctagAVClipInfoCLR);


		// ��Ļ��Ϣ�ṹ��ת��
		ZimuMixInfo ConvertToZimuPreviewInfo(tagZimuMixInfoCLR^ ctagZimuPreviewInfoCLR);


	private:
		CClipPlayControlIO* m_IClipPlayControl;

		String^ _strFileName;
	};
}