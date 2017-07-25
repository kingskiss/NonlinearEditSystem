#pragma once
#include"ZimuCreateIO.h"
using namespace System;
#using "..\Bin\x64\Debug\clrZiMuModel.dll"
#include "CommDef.h"


namespace ClrInterfaceDll
{
	public ref class ZimuCreate2CSharp
	{
	public:
		//���캯��
		ZimuCreate2CSharp();

		//������Ļ����
		int PictureZimu(String^ strFileName, clrZiMuModel::ZIMU ^mZiMu);

		//������Ļ
		int TextZimu(String^ strTextName, clrZiMuModel::FILLATTRIBclr ^cFILLATTRIBclr, clrZiMuModel::WORDATTRIBclr^cWORDATTRIBclr, clrZiMuModel::ZIMU ^mZiMu);

		//ԭʼͼƬ��ת
		int ZimuFromPicRotateIO(String^ strFileName, clrZiMuModel::ZIMU ^mZiMu, float angle);

		//���ܣ�ԭʼͼƬ���ţ�����ԭʼͼƬ���ź�������Ļ
		//2��factorX --- ����������������ϵ������ˮƽ��������ϵ��������Ϊ��ֵ��0����
		//3��factorY --- ����������߶�����ϵ��������ֱ��������ϵ��������Ϊ��ֵ��0����
		int ZimuFromPicZoomIO(String^ strFileName, clrZiMuModel::ZIMU ^mZiMu, float factorX, float factorY);

		//ͼƬ����
		int ZimuFromPicMirrorIO(String^ strFileName, clrZiMuModel::ZIMU ^mZiMu);





		//���������ı�������Ļ�����浽�����ļ���
		//1��strTextName--- �����������������Ļ���ı���
		//2��cFILLATTRIBclr --- �����������Ļ���������ֵ��������FILLATTRIB�ṹ�����ݿ飡
		//3��cWORDATTRIBclr--- �����������Ļ����������ֵ��������WORDATTRIB�ṹ�����ݿ飡
		//4��cZIMUEXTRAATTRIBclr --- �����������Ļ��չ����ֵ��������ZIMUEXTRAATTRIB�ṹ�����ݿ飡
		//5��szSavedFile --- ���������������Ļ�ı����ļ�ȫ����
		//6��iMode  --- ���������szSavedFile�ļ�������ʽ��0 = �½���1=׷�ӣ��������ļ�����������Ļ׷�ӵ����ļ�
		//����ֵ��>=0���ɹ�; <0��ʧ��
		int CreateZimuFileIO(String^ strTextName, clrZiMuModel::FILLATTRIBclr ^cFILLATTRIBclr, clrZiMuModel::WORDATTRIBclr^cWORDATTRIBclr,clrZiMuModel::ZIMUEXTRAATTRIBclr^cZIMUEXTRAATTRIBclr,System::String^SavedFile,int imode);

		////���ܣ���������ͼƬ������Ļ�����浽�����ļ���
		////������
		////1��csPicFileName  --- �����������������Ļ��ͼƬ�ļ�
		////2��pZimuAttrib --- �����������Ļ��չ����ֵ��������ZIMUEXTRAATTRIB�ṹ�����ݿ飡ע�⣺��������ֻ�в������͡�������Χ�Ȳ�����Ч����������������
		////3��szSavedFile  --- ���������������Ļ�ı����ļ�ȫ����
		////4��iMode  --- ���������szSavedFile�ļ�������ʽ��0 = �½���1=׷�ӣ��������ļ�����������Ļ׷�ӵ����ļ�
		////����ֵ��>=0���ɹ�; <0��ʧ��
		int CreateZimuFileFromPicIO(String^ strTextName, clrZiMuModel::ZIMUEXTRAATTRIBclr^cZIMUEXTRAATTRIBclr, System::String^SavedFile, int imode);


		int OpenZimuFileIO(String^ strTextName, clrZiMuModel::tagZIMUFILEHEADclr^head, System::Collections::Generic::List<clrZiMuModel::ZIMU^>^ListZimu);




	private:

		clrZiMuModel::tagZIMUFILEHEADclr^ CoverTotagZIMUFILEHEADclr(ZIMUFILEHEAD head);

		clrZiMuModel::SYSTEMTIMECtr^   CoverToSYSTEMTIMECtr(SYSTEMTIME time);

		RECT CoverToRECT(clrZiMuModel::RECTclr ^cRECTclr);

		ZIMUEXTRAATTRIB  CoverToZIMUEXTRAATTRIB(clrZiMuModel::ZIMUEXTRAATTRIBclr^cZIMUEXTRAATTRIBclr);
		FILLATTRIB CoverToFILLATTRIB(clrZiMuModel::FILLATTRIBclr ^cFILLATTRIBclr);

		WORDATTRIB CoverToWORDATTRIB(clrZiMuModel::WORDATTRIBclr^cWORDATTRIBclr);

		FILLMODE CoverToFILLMODE(clrZiMuModel::tagFILLMODEclr ^ctagFILLMODEclr);

		COLORRECORDER CoverToCOLORRECORDER(clrZiMuModel::COLORRECORDERclr ^cCOLORRECORDERclr);

		RGBQUAD CoverToRGBQUAD(clrZiMuModel::RGBA^cRGBA);

		LOG_FONT_METRIC CoverToLOG_FONT_METRIC(clrZiMuModel::LOG_FONT_METRICclr ^cLOG_FONT_METRICclr);

		LOGFONT CoverToLOGFONT(clrZiMuModel::LOGFONTclr ^LOGFONTclr);

		POINT CoverToPOINT(clrZiMuModel::POINTclr ^POINTclr);

		CZimuCreateIO *p_CZimuCreateIO;
	};

}
