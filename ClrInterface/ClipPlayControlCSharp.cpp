#include "stdafx.h"
#include <msclr\marshal.h>
#include <string>
#include "ClipPlayControlCSharp.h"

using namespace msclr::interop;
using namespace System::Runtime::InteropServices;
using namespace ClrInterfaceDll;


ClipPlayControlCSharp::ClipPlayControlCSharp()
{
	m_IClipPlayControl = new CClipPlayControlIO();
}

//void IClipPlayControlCSharp::Release()
//{
//	return m_IClipPlayControl->Release();
//}

int ClipPlayControlCSharp::AddZimuIO(String^ szZimuFile)
{
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(szZimuFile)).ToPointer();
	return m_IClipPlayControl->AddZimuIO(szFileName);
}

//���ܣ�ɾ��һ����Ļ�����ѹ���ϵ���Ļɾ��
//������
//szZimuFile ---- �����������ɾ������Ļ�ļ�ȫ����
//����ֵ��
// >=0 �ɹ� ; <0 ʧ��
int ClipPlayControlCSharp::DeleteZimuIO(String^ szZimuFile)
{
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(szZimuFile)).ToPointer();
	return m_IClipPlayControl->DeleteZimuIO(szFileName);
}

//���ܣ��޸�һ����Ļ�����ѹ����һ����Ļ��λ�á�����ʱ��Ƚ����޸�
//������
//szZimuFile ---- ������������޸ĵ���Ļ�ļ�ȫ����
//����ֵ��
// >=0 �ɹ� ; <0 ʧ��
int ClipPlayControlCSharp::ModifyZimuIO(String^ szZimuFile)
{
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(szZimuFile)).ToPointer();
	return m_IClipPlayControl->ModifyZimuIO(szFileName);
}



int ClipPlayControlCSharp::SetMultiClipsIO(AVClipInfoList^ AVClipList, ZimuMixInfoList^ ZimuList, IntPtr hWnd)
{
	HWND iHwnd = (HWND)hWnd.ToPointer();

	vector<AVClipInfo> vAVClipInfo;

	int nClips = AVClipList->Count;

	for (int i = 0; i < nClips; i++)
	{	
		vAVClipInfo.push_back(ConvertToAVClipInfoList(AVClipList[i]));
	}


	vector<ZimuMixInfo> vZimuList;

	int nCount = ZimuList->Count;

	for (int i = 0; i < nCount; i++)
	{
		vZimuList.push_back(ConvertToZimuPreviewInfo(ZimuList[i]));
	}

	int res = m_IClipPlayControl->SetMultiClipsIO(vAVClipInfo, vZimuList, iHwnd);

	return res;
}


/*
int ClipPlayControlCSharp::SetClip(String^ strFileName, IntPtr hWnd)
{
	//void * phWnd = hWnd->ToPointer();

	//HWND iHwnd = (HWND)(hWnd.ToPointer());
	HWND iHwnd = (HWND)hWnd.ToPointer();
	//std::string FileName = marshal_as<std::string>(strFileName);

	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(strFileName)).ToPointer();

	_strFileName = strFileName;

	return m_IClipPlayControl->SetClip(szFileName, iHwnd);
}
*/

/*
int ClipPlayControlCSharp::SetClip(String^ szClipFileName, ZimuMixInfoList^ ZimuList, IntPtr hWnd)
{
	HWND iHwnd = (HWND)hWnd.ToPointer();

	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(szClipFileName)).ToPointer();

	_strFileName = szClipFileName;

	vector<ZimuMixInfo> vZimuList;
	
	int nCount = ZimuList->Count;

	for (int i = 0; i < nCount; i++)
	{
		vZimuList.push_back(ConvertToZimuPreviewInfo(ZimuList[i]));
	}

	int res = m_IClipPlayControl->SetClip(szFileName, vZimuList, iHwnd);
	return res;
}
*/


String^ ClipPlayControlCSharp::GetClip()
{
	return _strFileName;
}


int ClipPlayControlCSharp::Play()
{
	return m_IClipPlayControl->Play();
}


int ClipPlayControlCSharp::Pause()
{
	return m_IClipPlayControl->Pause();
}


int ClipPlayControlCSharp::Continue()
{
	return m_IClipPlayControl->Continue();
}


int ClipPlayControlCSharp::Stop()
{
	return m_IClipPlayControl->Stop();
}


int ClipPlayControlCSharp::SetGivenPosition(long long rtPos)
{
	return m_IClipPlayControl->SetGivenPosition(rtPos);
}


int ClipPlayControlCSharp::GetCurState()
{
	return m_IClipPlayControl->GetCurState();
}


long long ClipPlayControlCSharp::GetDuration()
{
	return m_IClipPlayControl->GetDuration();
}


long long ClipPlayControlCSharp::GetPosition()
{
	return m_IClipPlayControl->GetPosition();
}


int ClipPlayControlCSharp::SetPosition(long long rtPos, long long rtEndPos)
{
	return m_IClipPlayControl->SetPosition(rtPos, rtEndPos);
}


void ClipPlayControlCSharp::SaveGivenFrameToBmp(String^ szBmpFileName, long long rtPos)
{
	TCHAR *szFileName = (TCHAR*)(Marshal::StringToHGlobalUni(szBmpFileName)).ToPointer();

	return m_IClipPlayControl->SaveGivenFrameToBmp(szFileName, rtPos);
}


// ��Ƶ��Ϣ�ṹ��ת��
AVClipInfo  ClipPlayControlCSharp::ConvertToAVClipInfoList(tagAVClipInfoCLR^ ctagAVClipInfoCLR)
{
	AVClipInfo cAVClipInfo;
	ZeroMemory(&cAVClipInfo, sizeof(cAVClipInfo));

	TCHAR *szFile = (TCHAR*)(Marshal::StringToHGlobalUni(ctagAVClipInfoCLR->szFile)).ToPointer();

	memcpy(cAVClipInfo.szFile, szFile, sizeof(cAVClipInfo.szFile));

	cAVClipInfo.rtInputPos = ctagAVClipInfoCLR->rtInputPos;
	cAVClipInfo.rtOutputPos = ctagAVClipInfoCLR->rtOutputPos;

	return cAVClipInfo;
}


// ��Ļ��Ϣ�ṹ��ת��
ZimuMixInfo ClipPlayControlCSharp::ConvertToZimuPreviewInfo(tagZimuMixInfoCLR^ ctagZimuPreviewInfoCLR)
{
	ZimuMixInfo cZimuPreviewInfo;
	ZeroMemory(&cZimuPreviewInfo, sizeof(cZimuPreviewInfo));

	TCHAR *szZimuFile = (TCHAR*)(Marshal::StringToHGlobalUni(ctagZimuPreviewInfoCLR->szZimuFile)).ToPointer();

	memcpy(cZimuPreviewInfo.szZimuFile, szZimuFile, sizeof(cZimuPreviewInfo.szZimuFile));

	cZimuPreviewInfo.rtStartPos	= ctagZimuPreviewInfoCLR->rtStartPos;
	cZimuPreviewInfo.rtStopPos	= ctagZimuPreviewInfoCLR->rtStopPos	;
	//cZimuPreviewInfo.start		= ctagZimuPreviewInfoCLR->start		;
	//cZimuPreviewInfo.duration	= ctagZimuPreviewInfoCLR->duration	;
	cZimuPreviewInfo.Level		= ctagZimuPreviewInfoCLR->Level		;

	return cZimuPreviewInfo;
}
