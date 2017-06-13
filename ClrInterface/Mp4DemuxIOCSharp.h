#pragma once

#include "Mp4DemuxIO.h"
#include <vcclr.h>

using namespace System;

//#define  _MAGICODE_MP4DEMUX_

namespace ClrInterfaceDll
{

	/// <summary>
	/// ��˵��������Ƶ������
	/// ���ڣ�2017-06-06 11:48:06
	/// ���ߣ�szwb
	/// </summary>
	public ref class Mp4DemuxIOCSharp
	{
	public:

		Mp4DemuxIOCSharp();


		//�����زĽ�������Ƶ����
		//������
		//1��strDemuxVideoFile ---- ����������������Ƶ�������ļ����ļ���Ϊ����ǰ����Ŀ¼\\_��ǰʱ��.v
		//2��strDemuxAudioFile ---- ����������������Ƶ�������ļ����ļ���Ϊ����ǰ����Ŀ¼\\_��ǰʱ��.a
		//3��strClipFileName ---- ����������ز��ļ�ȫ��������·�����ļ�����
		//4��rtPos ---- ��㣬������Ϊ�زĿ�ʼ���������ã�ֱ��ʹ��ȱʡֵ0����λ��ms
		//5��rtEndPos --- ���㣬�������Ϊ�ز�ĩβ���������ã�ֱ��ʹ��ȱʡֵ0����λ��ms
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		//ע�⣺ֻ�ܼ��ظ���MP4��H264����Ƶ�ز�
		//�ú���һֱ�ȵ�����Ƶ������ɻ���ǿ���˳�ʱ�ŷ��أ������سɹ������������Ѿ����
		int AddClip(String^% strDemuxVideoFile, String^% strDemuxAudioFile, String^ strClipFileName, long long  rtPos, long long  rtEndPos);


		//ֹͣ����
		void Stop();

	private:
		CMp4DemuxIO* m_CMp4DemuxIO;
	};
}