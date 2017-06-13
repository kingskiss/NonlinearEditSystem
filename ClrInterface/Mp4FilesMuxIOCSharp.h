#pragma once

#include "Mp4FilesMuxIO.h"
#include <vcclr.h>

#using "ClrDataTypeChange.dll"

using namespace System;
using namespace ClrDataTypeChange;

//#define _MAGICODE_MP4FILESMUX_

namespace ClrInterfaceDll
{

	/// <summary>
	/// ��˵��������Ƶ�����
	/// ���ڣ�2017-06-06 15:02:11
	/// ���ߣ�szwb
	/// </summary>
	public ref class Mp4FilesMuxIOCSharp
	{
	public:

		Mp4FilesMuxIOCSharp();


		//���ش���ϵ�����Ƶ�ļ����л��
		//������
		//1��strInH264FileList ---- �������������ϵ�����Ƶ�ļ����б��ļ�������·�����ļ�������
		//2��stroutput_filename ---- �����������Ϻ󱣴��ļ���������·�����ļ�����
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		//ע�⣺
		//1��ֻ�ܼ����Ѿ�ѹ���ĸ���MP4��H264����ƵԴ�ļ���
		//2������ϵ�����Ƶ�ļ����������֧��MAX_INPUT_FILES������Ƶ�ļ�
		//3�����سɹ�����ϲ�һ���������Ƿ������Ҫ����MuxerFinished�����ж�
		//int StartMuxer(System::Collections::Generic::List<String^> strInH264FileList, String^% stroutput_filename);
		int StartMuxer(StringList^ strInH264FileList, String^ stroutput_filename);


		//ֹͣ���
		void StopMuxer();


		//����Ƿ��Ѿ�����
		bool MuxerFinished();

	private:
		CMp4FilesMuxIO* m_CMp4FilesMuxIO;
	};
}