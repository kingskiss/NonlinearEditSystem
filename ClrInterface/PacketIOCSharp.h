#pragma once

#include "PacketIO.h"
#include "BaseDefine.h"
#include <vcclr.h>

#using "ClrDataTypeChange.dll"
//#using "D:/szwb/Projects/NonlinearEditSystem/Bin/x64/Debug/ClrDataTypeChange.dll"

using namespace System;
using namespace ClrDataTypeChange;

//#define _MAGICODE_MP4FILESMUX_

namespace ClrInterfaceDll
{

	/// <summary>
	/// ��˵��������ۺ���
	/// ���ڣ�2017-07-20 15:02:11
	/// ���ߣ�szwb
	/// </summary>
	public ref class PacketIOCSharp
	{
	public:

		PacketIOCSharp();

		//��ȡ�ز���Ϣ�ӿ�
		//������
		//1��fileName ---- ����������ز��ļ���
		//2��fileInfo ---- ����������ز���Ϣ
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		int GetClipInfo(String^ fileName, tagClipInfoCLR^% fileInfo);

		//���ش����ɰٷֱȣ������ɽ��ȣ��������50%���򷵻�0.5�ȵȡ�
		double GetProgress();

		///////////////////////////////////////////////////////////////
		//�ز�����Ƶ����ӿ�   -- ��ʼ

		//�����ز��б��������Ƶ����
		//������
		//1��ClipList ---- �����������Ҫ������ز��б�
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		//ע�⣺ֻ�ܼ��ظ���MP4��H264����Ƶ�ز�
		//�ú���һֱ�ȵ�����Ƶ������ɻ���ǿ���˳�ʱ�ŷ��أ������سɹ������������Ѿ����
		int DemuxClips(DemuxClipInfoList^ ClipList);

		//ֹͣ����
		void StopDemux();

		//�ز�����Ƶ����ӿ�   -- ����
		///////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////
		//���롢��Ļ���ӡ�����ȴ���ӿ�   -- ��ʼ
		int PacketingInitial(ZimuMixInfoList^ ZimuList);//�����ʼ���������ڴ��ǰ����һ�Σ��ҽ�����һ�Σ�

							   //���
							   //����ֵ��
							   // >=0 �ɹ� ; <0 ʧ��
		int PacketStart();

		//ֹͣ���
		void PacketStop();

		//�жϴ���Ƿ����
		bool PacketIsFinish();

		//���롢��Ļ���ӡ�����ȴ���ӿ�   -- ����
		///////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////
		//����Ƶ�ļ���Ͻӿ�   -- ��ʼ
		//���������ɵ�����Ƶ�ļ����л��
		//������
		//szOutputFilename ---- �����������Ϻ󱣴��ļ���������·�����ļ�����
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		//ע�⣺
		//1��ֻ�ܼ����Ѿ�ѹ���ĸ���MP4��H264����ƵԴ�ļ���
		//2�����سɹ�����ϲ�һ���������Ƿ������Ҫ����MuxerFinished�����ж�
		//3�������ڱ�����ɺ�ſ��Խ��л�ϣ�
		int MuxerStart(String^ szOutputFilename);

		//ֹͣ���
		void MuxerStop();

		//�жϻ���Ƿ����
		bool MuxerIsFinish();

		//����Ƶ�ļ���Ͻӿ�   -- ����
		///////////////////////////////////////////////////////////////

		///////////////////////////////////////////////////////////////
		//��Ļ���ӽӿ�   -- ��ʼ

		//���ص��ӵ���Ļ
		//������
		//1��ZimuList ---- �����������Ҫ���ӵ���Ļ�б�
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		// int MixZimu(ZimuMixInfoList^ ZimuList);

		//��Ļ���ӽӿ�   -- ����
		///////////////////////////////////////////////////////////////

		//tagClipInfoCLR ConvertTotagClipInfoCLR(ClipInfo cClipInfo);

		ClipInfo ConvertToClipInfo(tagClipInfoCLR^ ctagClipInfoCLR);

		DemuxClipInfo ConvertToDemuxClipInfo(tagDemuxClipInfoCLR^ ctagDemuxClipInfoCLR);

		ZimuMixInfo ConvertToZimuMixInfo(tagZimuMixInfoCLR^ ctagZimuMixInfo);


	private:
		CPacketIO* m_CPacketIO;

	};
}