#pragma once

#include "H264CodecIO.h"
#include <vcclr.h>

#using "ClrDataTypeChange.dll"

using namespace System;
using namespace ClrDataTypeChange;


//#define _MAGICODE_H264CODEC_

namespace ClrInterfaceDll
{

	/// <summary>
	/// ��˵������Ƶ�������
	/// ���ڣ�2017-06-06 10:50:33
	/// ���ߣ�szwb
	/// </summary>
	public ref class H264CodecIOCSharp
	{
	public:
		H264CodecIOCSharp();

		//������������ط����h264��Ƶ�����룬��Ļ���ӣ����룬���������h264��Ƶ
		//������
		//2��szInH264VideoFileList ---- ��������������h264��Ƶ�ļ�ȫ��������·�����ļ������б�
		//3��szOutH264FileName ---- ���������������h264��Ƶ�ļ���������·�����ļ�����
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		//int Start(System::Collections::Generic::List<String^> strInH264VideoFileList, String^% strOutH264FileName);
		int Start(StringList^ strInH264VideoFileList, String^% strOutH264FileName);


		//������Ƶ������룺���ط����AAC��Ƶ�����룬���룬���������AAC��Ƶ
		//������
		//1��szInH264VideoFileList ---- ��������������h264��Ƶ�ļ�ȫ��������·�����ļ������б�
		//2��szOutH264FileName ---- ���������������h264��Ƶ�ļ���������·�����ļ�����
		//����ֵ��
		// >=0 �ɹ� ; <0 ʧ��
		//int StartAACDecEncoder(System::Collections::Generic::List<String^> strInAacFileList, String^% strOutAacFileName);
		int StartAACDecEncoder(StringList^ strInAacFileList, String^% strOutAacFileName);


		//ֹͣ���
		void Stop();


		//����Ƿ����
		bool isFinish();


	private:
		CH264CodecIO* m_H264CodecIOCSharp;
	};
}