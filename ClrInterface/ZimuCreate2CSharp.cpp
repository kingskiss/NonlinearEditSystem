#include "stdafx.h"
#include"ZimuCreate2CSharp.h"
#include <msclr\marshal.h>
#include <string>
#include <io.h>
#include<iostream>
//#include "ximage.h"
#include<locale.h>
#include<Windows.h>


using namespace msclr::interop;
using namespace System::Runtime::InteropServices;
using namespace ClrInterfaceDll;

ZimuCreate2CSharp::ZimuCreate2CSharp()
{
	p_CZimuCreateIO = new  CZimuCreateIO;
}

////////////////////////////////////////////////////////////////////////////////////
///// ͼƬ��Ļ������
///////////////////////////////////////////////////////////////////////////////////
int ZimuCreate2CSharp::PictureZimu(String^ strFileName, clrZiMuModel::ZIMU ^mZiMu)
{
	int res = -1;
	//p_CZimuCreateIO = new  CZimuCreateIO;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strFileName)).ToPointer();
	ULONG width = 0, height = 0;

	if (p_CZimuCreateIO->PictureZimuIO(szFileName, NULL, width, height) >= 0)
	{
		RGBQUAD *pBuff = new RGBQUAD[width*height];
		if (NULL != pBuff)
		{
			res = p_CZimuCreateIO->PictureZimuIO(szFileName, (ULONG *)pBuff, width, height);

			mZiMu->height = height;
			mZiMu->width = width;
			mZiMu->RGBAList->Clear();
			for (ULONG i = 0; i < (width*height); i++)
			{
				RGBQUAD mRGBQUAD = pBuff[i];
				clrZiMuModel::RGBA ^cRGBA = gcnew clrZiMuModel::RGBA();
				cRGBA->rgbBlue = mRGBQUAD.rgbBlue;
				cRGBA->rgbRed = mRGBQUAD.rgbRed;
				cRGBA->rgbGreen = mRGBQUAD.rgbGreen;
				cRGBA->rgbReserved = mRGBQUAD.rgbReserved;
				mZiMu->RGBAList->Add(cRGBA);
				
			}

			delete[]pBuff;
			pBuff = NULL;
		}
	}
	return res;
}



////////////////////////////////////////////////////////////////////////////////////
/////�ı���Ļ������
////////////////////////////////////////////////////////////////////////////////////
int ZimuCreate2CSharp::TextZimu(String^ strTextName, clrZiMuModel::FILLATTRIBclr ^cFILLATTRIBclr, clrZiMuModel::WORDATTRIBclr^cWORDATTRIBclr, clrZiMuModel::ZIMU ^mZiMu)
{
	int res = -1;	
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strTextName)).ToPointer();

	

	TCHAR name[500];
	for (int i = 0; i <= strTextName->Length;i++)
	{
		name[i] = szFileName[i];
	}

	//2�������ı���Ļ����
	FILLATTRIB FillAttrib = CoverToFILLATTRIB(cFILLATTRIBclr);
	WORDATTRIB WordAttrib = CoverToWORDATTRIB(cWORDATTRIBclr);

	//3��������Ļ������
	CDirectWordObject *pObj = p_CZimuCreateIO->StartTxtZimuIO((BYTE *)(&FillAttrib), (BYTE *)(&WordAttrib), szFileName, 0, 0);
	if (NULL != pObj)
	{
		ULONG width = 0, height = 0;
		int irtn = p_CZimuCreateIO->GetTxtZimuSizeIO(pObj, width, height);
		if (irtn >= 0)
		{
			RGBQUAD *pBuff = new RGBQUAD[width*height];
			if (NULL != pBuff)
			{
				res = p_CZimuCreateIO->GetTxtZimuBuffIO(pObj, pBuff);

				mZiMu->height = height;
				mZiMu->width = width;
				mZiMu->RGBAList->Clear();
				for (ULONG i = 0; i < (width*height); i++)
				{
					RGBQUAD mRGBQUAD = pBuff[i];
					clrZiMuModel::RGBA ^cRGBA = gcnew clrZiMuModel::RGBA();
					cRGBA->rgbBlue = mRGBQUAD.rgbBlue;
					cRGBA->rgbRed = mRGBQUAD.rgbRed;
					cRGBA->rgbGreen = mRGBQUAD.rgbGreen;
					cRGBA->rgbReserved = mRGBQUAD.rgbReserved;
					mZiMu->RGBAList->Add(cRGBA);

				}

				delete[]pBuff;
				pBuff = NULL;
			}
		}
	}

	return res;
}

///////////////////////////////////////////////////
/////������תͼƬ
//////////////////////////////////////////////////
int ClrInterfaceDll::ZimuCreate2CSharp::ZimuFromPicRotateIO(String ^ strFileName, clrZiMuModel::ZIMU ^ mZiMu, float angle)
{
	int res = -1;
	//p_CZimuCreateIO = new  CZimuCreateIO;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strFileName)).ToPointer();
	ULONG width = 0, height = 0;	
	if (p_CZimuCreateIO->ZimuFromPicRotateIO(szFileName, angle, NULL, width, height) >= 0)
	{
		RGBQUAD *pBuff = new RGBQUAD[width*height];
		if (NULL != pBuff)
		{
			p_CZimuCreateIO->ZimuFromPicRotateIO(szFileName, angle, (ULONG *)pBuff, width, height);
			mZiMu->height = height;
			mZiMu->width = width;
			mZiMu->RGBAList->Clear();
			for (ULONG i = 0; i < (width*height); i++)
			{
				RGBQUAD mRGBQUAD = pBuff[i];
				clrZiMuModel::RGBA ^cRGBA = gcnew clrZiMuModel::RGBA();
				cRGBA->rgbBlue = mRGBQUAD.rgbBlue;
				cRGBA->rgbRed = mRGBQUAD.rgbRed;
				cRGBA->rgbGreen = mRGBQUAD.rgbGreen;
				cRGBA->rgbReserved = mRGBQUAD.rgbReserved;
				mZiMu->RGBAList->Add(cRGBA);

			}

			delete[]pBuff;
			pBuff = NULL;
		}
	}
	return res;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////ͼƬ��ת
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ClrInterfaceDll::ZimuCreate2CSharp::ZimuFromPicZoomIO(String ^ strFileName, clrZiMuModel::ZIMU ^ mZiMu, float factorX, float factorY)
{
	int res = -1;
	//p_CZimuCreateIO = new  CZimuCreateIO;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strFileName)).ToPointer();
	ULONG width = 0, height = 0;
	
	if (p_CZimuCreateIO->ZimuFromPicZoomIO(szFileName, factorX, factorY,NULL, width, height) >= 0)
	{
		RGBQUAD *pBuff = new RGBQUAD[width*height];
		if (NULL != pBuff)
		{
			p_CZimuCreateIO->ZimuFromPicZoomIO(szFileName, factorX, factorY,(ULONG *)pBuff, width, height);
			mZiMu->height = height;
			mZiMu->width = width;
			mZiMu->RGBAList->Clear();
			for (ULONG i = 0; i < (width*height); i++)
			{
				RGBQUAD mRGBQUAD = pBuff[i];
				clrZiMuModel::RGBA ^cRGBA = gcnew clrZiMuModel::RGBA();
				cRGBA->rgbBlue = mRGBQUAD.rgbBlue;
				cRGBA->rgbRed = mRGBQUAD.rgbRed;
				cRGBA->rgbGreen = mRGBQUAD.rgbGreen;
				cRGBA->rgbReserved = mRGBQUAD.rgbReserved;
				mZiMu->RGBAList->Add(cRGBA);

			}

			delete[]pBuff;
			pBuff = NULL;
		}
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////����ͼƬ��Ļ
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int ClrInterfaceDll::ZimuCreate2CSharp::ZimuFromPicMirrorIO(String ^ strFileName, clrZiMuModel::ZIMU ^ mZiMu)
{
	int res = -1;
	//p_CZimuCreateIO = new  CZimuCreateIO;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strFileName)).ToPointer();
	ULONG width = 0, height = 0;

	if (p_CZimuCreateIO->ZimuFromPicMirrorIO(szFileName, NULL, width, height) >= 0)
	{
		RGBQUAD *pBuff = new RGBQUAD[width*height];
		if (NULL != pBuff)
		{
			res = p_CZimuCreateIO->ZimuFromPicMirrorIO(szFileName, (ULONG *)pBuff, width, height);

			mZiMu->height = height;
			mZiMu->width = width;
			mZiMu->RGBAList->Clear();
			for (ULONG i = 0; i < (width*height); i++)
			{
				RGBQUAD mRGBQUAD = pBuff[i];
				clrZiMuModel::RGBA ^cRGBA = gcnew clrZiMuModel::RGBA();
				cRGBA->rgbBlue = mRGBQUAD.rgbBlue;
				cRGBA->rgbRed = mRGBQUAD.rgbRed;
				cRGBA->rgbGreen = mRGBQUAD.rgbGreen;
				cRGBA->rgbReserved = mRGBQUAD.rgbReserved;
				mZiMu->RGBAList->Add(cRGBA);

			}

			delete[]pBuff;
			pBuff = NULL;
		}
	}
	return res;
}

//////////////////////////////////////////////////////////////////////////////////
/////������Ļ
//////////////////////////////////////////////////////////////////////////////////
int ClrInterfaceDll::ZimuCreate2CSharp::CreateZimuFileIO(String ^ strTextName, clrZiMuModel::FILLATTRIBclr ^ cFILLATTRIBclr, clrZiMuModel::WORDATTRIBclr ^ cWORDATTRIBclr, clrZiMuModel::ZIMUEXTRAATTRIBclr ^ cZIMUEXTRAATTRIBclr, System::String ^ SavedFile, int imode)
{
	int res = -1;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strTextName)).ToPointer();
	FILLATTRIB FillAttrib = CoverToFILLATTRIB(cFILLATTRIBclr);
	WORDATTRIB WordAttrib = CoverToWORDATTRIB(cWORDATTRIBclr);
	ZIMUEXTRAATTRIB pZimuAttrib = CoverToZIMUEXTRAATTRIB(cZIMUEXTRAATTRIBclr);
	TCHAR *szSavedFile =(TCHAR*)(Marshal::StringToHGlobalUni(SavedFile)).ToPointer();
	
	res = p_CZimuCreateIO->CreateZimuFileIO(szFileName, (BYTE *)&FillAttrib, (BYTE*)&WordAttrib,(BYTE*)&pZimuAttrib, szSavedFile, imode);
	
	return res;

}

//////////////////////////////////////////////////////////////////////////////////////////////////
////����ͼ����Ļ
//////////////////////////////////////////////////////////////////////////////////////////////////
int ClrInterfaceDll::ZimuCreate2CSharp::CreateZimuFileFromPicIO(String ^ strTextName, clrZiMuModel::ZIMUEXTRAATTRIBclr ^ cZIMUEXTRAATTRIBclr, System::String ^ SavedFile, int imode)
{
	int res = -1;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strTextName)).ToPointer();
	ZIMUEXTRAATTRIB pZimuAttrib = CoverToZIMUEXTRAATTRIB(cZIMUEXTRAATTRIBclr);
	TCHAR *szSavedFile = (TCHAR*)(Marshal::StringToHGlobalUni(SavedFile)).ToPointer();

	//CreateZimuFileFromPicIO(newName, (BYTE *)&cZIMUEXTRAATTRIB, (TCHAR *)((LPCTSTR)csConst), 0);
	res = p_CZimuCreateIO->CreateZimuFileFromPicIO(szFileName, (BYTE*)&pZimuAttrib, szSavedFile, imode);
	return res;
}




int ClrInterfaceDll::ZimuCreate2CSharp::OpenZimuFileIO(String^ strTextName, clrZiMuModel::tagZIMUFILEHEADclr^headx, System::Collections::Generic::List<clrZiMuModel::ZIMU^>^ListZimu)
{
	int res = 0;

	ZIMUFILEHEAD head;
	std::vector<RGBQUAD *> FrameArr;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strTextName)).ToPointer();
	int irtn = p_CZimuCreateIO->OpenZimuFileIO(szFileName, (BYTE *)(&head), &FrameArr);
	if (irtn > 0)
	{
		//ѭ��ȡֵ
		for (std::vector<RGBQUAD *>::iterator it = FrameArr.begin(); it != FrameArr.end(); ++it)
		{
			//��ʾ��Ļ......
			clrZiMuModel::ZIMU^ czimu = gcnew clrZiMuModel::ZIMU();
			int h =  HDFRAME_HEIGHT;
			int w =  HDFRAME_WIDTH;
			czimu->height = h;
			czimu->width = w;
			czimu->RGBAList = gcnew System::Collections::Generic::List<clrZiMuModel::RGBA^>(h*w);
			int off1 = 0, off2 = 0;

			for (int i = 0; i < h; i++)
			{
				for (int j = 0; j < w; j++)
				{
					off1 = i * HDFRAME_WIDTH + j;
					RGBQUAD *rgb = (*it) + off1;	
					clrZiMuModel::RGBA ^cRGBA = gcnew clrZiMuModel::RGBA();
					cRGBA->rgbBlue = rgb->rgbBlue;
					cRGBA->rgbRed = rgb->rgbRed;
					cRGBA->rgbGreen = rgb->rgbGreen;
					cRGBA->rgbReserved = rgb->rgbReserved;
					czimu->RGBAList->Add(cRGBA);
					
				}
			}
			ListZimu->Add(czimu);

			
		}
	}

	//ͷ���ݵ�ת��
	headx = CoverTotagZIMUFILEHEADclr(head);
	p_CZimuCreateIO->ReleaseMemoryIO(&FrameArr);
	return irtn;

}

///ת��ͷ
clrZiMuModel::tagZIMUFILEHEADclr^ ClrInterfaceDll::ZimuCreate2CSharp::CoverTotagZIMUFILEHEADclr(ZIMUFILEHEAD head)
{
	clrZiMuModel::tagZIMUFILEHEADclr^ res = gcnew clrZiMuModel::tagZIMUFILEHEADclr();
	res->iFramesNum = head.iFramesNum;
	res->iMainVer = head.iMainVer;
	res->rect->bottom = head.rect.bottom;
	res->rect->left = head.rect.left;
	res->rect->right = head.rect.right;
	res->rect->top = head.rect.top;
	res->time = CoverToSYSTEMTIMECtr(head.time);

	return res;
}

clrZiMuModel::SYSTEMTIMECtr^ ClrInterfaceDll::ZimuCreate2CSharp::CoverToSYSTEMTIMECtr(SYSTEMTIME time)
{
	clrZiMuModel::SYSTEMTIMECtr ^ res = gcnew clrZiMuModel::SYSTEMTIMECtr();
	res->wDay = time.wDay;
	res->wDayOfWeek = time.wDayOfWeek;
	res->wHour = time.wHour;
	res->wMilliseconds = time.wMilliseconds;
	res->wMinute = time.wMinute;
	res->wMonth = time.wMonth;
	res->wSecond = time.wSecond;
	res->wYear = time.wYear;
	return res;
}

RECT ClrInterfaceDll::ZimuCreate2CSharp::CoverToRECT(clrZiMuModel::RECTclr ^ cRECTclr)
{
	RECT res;
	res.bottom = cRECTclr->bottom;
	res.left = cRECTclr->left;
	res.right = cRECTclr->right;
	res.top = cRECTclr->top;
	return res;
}

//////////////////////////////////////////////////////////////////////////////////
/////�ṹת��
//////////////////////////////////////////////////////////////////////////////////
ZIMUEXTRAATTRIB ClrInterfaceDll::ZimuCreate2CSharp::CoverToZIMUEXTRAATTRIB(clrZiMuModel::ZIMUEXTRAATTRIBclr ^ cZIMUEXTRAATTRIBclr)
{
	ZIMUEXTRAATTRIB res;

	/*res.Alpha = cZIMUEXTRAATTRIBclr->Alpha;
	res.BackColorType = cZIMUEXTRAATTRIBclr->BackColorType;*/
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(cZIMUEXTRAATTRIBclr->Backname)).ToPointer();
	/*for (int i = 0; i <= cZIMUEXTRAATTRIBclr->Backname->Length; i++)
	{
		res.Backname[i] = szFileName[1];
	}*/
	/*res.BackSingleColor = CoverToRGBQUAD(cZIMUEXTRAATTRIBclr->BackSingleColor);
	res.BackTransition = CoverToCOLORRECORDER(cZIMUEXTRAATTRIBclr->BackTransition);*/
	res.rect = CoverToRECT(cZIMUEXTRAATTRIBclr->rect);
	/*res.uSpan = cZIMUEXTRAATTRIBclr->uSpan;
	res.uSpeed = cZIMUEXTRAATTRIBclr->uSpeed;
	res.zmType = (ZIMU_TYPES)((int)cZIMUEXTRAATTRIBclr->zmType);*/
	return res;
}

FILLATTRIB ZimuCreate2CSharp::CoverToFILLATTRIB(clrZiMuModel::FILLATTRIBclr ^cFILLATTRIBclr)
{
	FILLATTRIB FillAttrib;

	FillAttrib.EdgeFillMode = CoverToFILLMODE(cFILLATTRIBclr->EdgeFillMode);//�߿����ģʽ
	FillAttrib.FaceFillMode = CoverToFILLMODE(cFILLATTRIBclr->FaceFillMode);//�������ģʽ
	FillAttrib.LitiFillMode = CoverToFILLMODE(cFILLATTRIBclr->LitiFillMode);//�������ģʽ
	FillAttrib.ShadeFillMode = CoverToFILLMODE(cFILLATTRIBclr->ShadeFillMode);//��Ӱ���ģʽ
	FillAttrib.FillScope = cFILLATTRIBclr->FillScope;				//�������
	FillAttrib.FaceType = cFILLATTRIBclr->FaceType;				//��������
	FillAttrib.EdgeType = cFILLATTRIBclr->EdgeType;				//�߿�����
	FillAttrib.LitiType = cFILLATTRIBclr->LitiType;				//��������
	FillAttrib.ShadeType = cFILLATTRIBclr->ShadeType;				//��Ӱ����
	FillAttrib.FaceFillType = cFILLATTRIBclr->FaceFillType;			//������ɫ����
	FillAttrib.EdgeFillType = cFILLATTRIBclr->EdgeFillType;			//�߿���ɫ����
	FillAttrib.LitiFillType = cFILLATTRIBclr->LitiFillType;			//�߿���ɫ����
	FillAttrib.ShadeFillType = cFILLATTRIBclr->ShadeFillType;			//��Ӱ��ɫ����
	FillAttrib.EdgeWidth = cFILLATTRIBclr->EdgeWidth;				//�߿���
	FillAttrib.LitiWidth = cFILLATTRIBclr->LitiWidth;				//������
	FillAttrib.ShadeHoffset = cFILLATTRIBclr->ShadeHoffset;			//��Ӱˮƽƫ��
	FillAttrib.ShadeVoffset = cFILLATTRIBclr->ShadeVoffset;			//��Ӱ��ֱƫ��
	FillAttrib.FaceTexture = cFILLATTRIBclr->FaceTexture;		//���������
	FillAttrib.EdgeTexture = cFILLATTRIBclr->EdgeTexture;		//�߿������
	FillAttrib.LitiTexture = cFILLATTRIBclr->LitiTexture;		//���������
	FillAttrib.ShadeTexture = cFILLATTRIBclr->ShadeTexture;		//��Ӱ�����
	FillAttrib.FaceLight = cFILLATTRIBclr->FaceLight;			//�����к�
	FillAttrib.EdgeLight = cFILLATTRIBclr->EdgeLight;			//�߿��к�
	FillAttrib.LitiLight = cFILLATTRIBclr->LitiLight;			//�����к�
	FillAttrib.ShadeLight = cFILLATTRIBclr->ShadeLight;			//��Ӱ��к�
	FillAttrib.Reserved = cFILLATTRIBclr->Reserved;			//����
;	//�������ģʽ
	//FillAttrib.EdgeFillMode.CurrentColor.rgbReserved = 255;
	return FillAttrib;
}

FILLMODE ZimuCreate2CSharp::CoverToFILLMODE(clrZiMuModel::tagFILLMODEclr ^ctagFILLMODEclr)
{
	FILLMODE cFILLMODE;	
	cFILLMODE.MaterialNo = ctagFILLMODEclr->MaterialNo;
	cFILLMODE.TransitionColor = CoverToCOLORRECORDER(ctagFILLMODEclr->TransitionColor);
	cFILLMODE.CurrentColor = CoverToRGBQUAD(ctagFILLMODEclr->CurrentColor);
	return cFILLMODE;
}

/////����ת��
COLORRECORDER ClrInterfaceDll::ZimuCreate2CSharp::CoverToCOLORRECORDER(clrZiMuModel::COLORRECORDERclr ^ cCOLORRECORDERclr)
{
	COLORRECORDER cCOLORRECORDER;
	cCOLORRECORDER.Color_Invert = cCOLORRECORDERclr->Color_Invert;
	cCOLORRECORDER.Color_Mode = cCOLORRECORDERclr->Color_Mode;
	cCOLORRECORDER.Color_Num = cCOLORRECORDERclr->Color_Num;
	cCOLORRECORDER.Color_Type = cCOLORRECORDERclr->Color_Type;
	for (int i = 0; i < cCOLORRECORDER.Color_Num; i++)
	{
		clrZiMuModel::RGBA ^ cRGBA = cCOLORRECORDERclr->Color_Data[i];
		cCOLORRECORDER.Color_Data[i] = CoverToRGBQUAD(cRGBA);
		cCOLORRECORDER.Color_Pos[i] = cCOLORRECORDERclr->Color_Pos[i];
	}
	return cCOLORRECORDER;
}

/////////////////////////////////////
////ɫ��ת��
////////////////////////////////////
RGBQUAD ClrInterfaceDll::ZimuCreate2CSharp::CoverToRGBQUAD(clrZiMuModel::RGBA ^ cRGBA)
{
	RGBQUAD cRGBQUAD;
	cRGBQUAD.rgbBlue = cRGBA->rgbBlue;
	cRGBQUAD.rgbGreen = cRGBA->rgbGreen;
	cRGBQUAD.rgbRed = cRGBA->rgbRed;
	cRGBQUAD.rgbReserved = cRGBA->rgbReserved;
	return cRGBQUAD;
}

LOG_FONT_METRIC ClrInterfaceDll::ZimuCreate2CSharp::CoverToLOG_FONT_METRIC(clrZiMuModel::LOG_FONT_METRICclr ^ cLOG_FONT_METRICclr)
{
	LOG_FONT_METRIC cLOG_FONT_METRIC;
	cLOG_FONT_METRIC.Lf = CoverToLOGFONT(cLOG_FONT_METRICclr->Lf);
	cLOG_FONT_METRIC.AveCharWidth = cLOG_FONT_METRICclr->AveCharWidth;
	cLOG_FONT_METRIC.MaxCharWidth= cLOG_FONT_METRICclr->MaxCharWidth;

	

	return cLOG_FONT_METRIC;
}

LOGFONT ClrInterfaceDll::ZimuCreate2CSharp::CoverToLOGFONT(clrZiMuModel::LOGFONTclr ^ LOGFONTclr)
{
	LOGFONT cLOGFONT;
	cLOGFONT.lfHeight = LOGFONTclr->lfHeight;
	cLOGFONT.lfWidth = LOGFONTclr->lfWidth;
	cLOGFONT.lfEscapement = LOGFONTclr->lfEscapement;
	cLOGFONT.lfOrientation = LOGFONTclr->lfOrientation;
	cLOGFONT.lfWeight = LOGFONTclr->lfWeight;
	cLOGFONT.lfItalic = LOGFONTclr->lfItalic;
	cLOGFONT.lfUnderline = LOGFONTclr->lfUnderline;
	cLOGFONT.lfStrikeOut = LOGFONTclr->lfStrikeOut;
	cLOGFONT.lfCharSet = LOGFONTclr->lfCharSet;
	cLOGFONT.lfOutPrecision = LOGFONTclr->lfOutPrecision;
	cLOGFONT.lfClipPrecision = LOGFONTclr->lfClipPrecision;
	cLOGFONT.lfQuality = LOGFONTclr->lfQuality;
	cLOGFONT.lfPitchAndFamily = LOGFONTclr->lfPitchAndFamily;
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(LOGFONTclr->lfFaceName)).ToPointer();
	for (int i = 0; (i <= LOGFONTclr->lfFaceName->Length) && (i < LF_FACESIZE); i++)
	{
		cLOGFONT.lfFaceName[i] = szFileName[i];
	}
	
	return cLOGFONT;
}

POINT ClrInterfaceDll::ZimuCreate2CSharp::CoverToPOINT(clrZiMuModel::POINTclr ^ POINTclr)
{
	POINT cPOINT;
	cPOINT.x = POINTclr->x;
	cPOINT.y = POINTclr->y;

	return cPOINT;
}

WORDATTRIB ZimuCreate2CSharp::CoverToWORDATTRIB(clrZiMuModel::WORDATTRIBclr^cWORDATTRIBclr)
{
	WORDATTRIB WordAttrib;
	WordAttrib.ChineseFont = CoverToLOG_FONT_METRIC(cWORDATTRIBclr->ChineseFont);	//��������
	WordAttrib.EnglishFont =CoverToLOG_FONT_METRIC(cWORDATTRIBclr->EnglishFont);	//Ӣ������
	WordAttrib.SymbolFont= CoverToLOG_FONT_METRIC(cWORDATTRIBclr->SymbolFont);    //ͼ�η�����
	WordAttrib.IsSymbol = cWORDATTRIBclr->IsSymbol;					//TRUE:Symbol,False:text
	WordAttrib.WordWidth = cWORDATTRIBclr->WordWidth;					//�ֿ�
	WordAttrib.WordHeight = cWORDATTRIBclr->WordHeight;				//�ָ�
	WordAttrib.WordColum = cWORDATTRIBclr->WordColum;				//�ּ��
	WordAttrib.WordRow = cWORDATTRIBclr->WordRow;					//�м��
	WordAttrib.WordRotate = cWORDATTRIBclr->WordRotate;				//����ת��	
	WordAttrib.WordSlant = cWORDATTRIBclr->WordSlant;				//����б��
	WordAttrib.WordAlign = cWORDATTRIBclr->WordAlign;					//�����з�ʽ
	WordAttrib.WordTab = cWORDATTRIBclr->WordTab;					//�ֶ��뷽ʽ
	WordAttrib.MorphType = cWORDATTRIBclr->MorphType;					//����
	WordAttrib.StartPoint = CoverToPOINT(cWORDATTRIBclr->StartPoint);				//��ʼ��
	//WordAttrib.WordCurve[4];	//����·��
	for (int i = 0; (i < 4)&&(i < cWORDATTRIBclr->WordCurve->Count); i++)
	{
		WordAttrib.WordCurve[i] = CoverToPOINT(cWORDATTRIBclr->WordCurve[i]);
	}
	WordAttrib.MorphKeyPoint = NULL;			//���ιؼ���

	return WordAttrib;
}