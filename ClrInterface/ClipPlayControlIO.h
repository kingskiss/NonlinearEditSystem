#pragma once
#include <vector>
//#include "BaseDefine.h"
using namespace std;

//Ԥ����Ļ��Ϣ�ṹ����  --- ��ʼ
//˵����
//�ýṹ���ڷ����Ա༭�������ز�Ԥ��ʱ����Ļ����
//ע�⣺Ԥ���ز�ֻ��һ��������Ļ�����ж��������Ļ�����Ǳ�Ԥ���زĶ�����Ļ��Ҳ������������Ļ������һ��Ԥ���ز�δ������������Ԥ���زĵ���Ļ�����߱�Ԥ���زĲ�������Ҫ��������һ��Ԥ���زĵ���Ļ���ȡ�
//�ֶ�˵����
//1��rtStartPos��rtStopPos����Ļ�ڱ�Ԥ���ز��еĿ�ʼ�ͽ���ʱ�䣬���ǵĲο�ʱ��Ϊ����Ԥ���ز����ʱ��Ϊ0����Ҫ���ݲ�����Ҫ��ȷ������ֵ����֤��rtStopPos >= rtStartPos >= 0��  
//2��duration����Ļ�ܲ���ʱ����start����Ļ�ڱ�Ԥ���ز��еĿ�ʼʱ�̣�start������duration��Χ��ĳ��ʱ�䡣�������ֶ���������Ļ���Ӳ�����Ҫ���ֶΡ�
//typedef struct tagZimuPreviewInfo
//{
//	TCHAR       szZimuFile[MAX_PATH];//��Ļ�ļ���
//
//
//	LONGLONG    rtStartPos;//��Ԥ���ز��еĿ�ʼʱ�䣨��λ��ms��
//	LONGLONG    rtStopPos;//��Ԥ���ز��еĽ���ʱ�䣨��λ��ms��
//
//	LONGLONG    duration;//��Ļ�ܲ���ʱ������λ��ms��
//	LONGLONG    start;//��Ļ��Ԥ���ز��еĿ�ʼʱ�̣���λ��ms��
//
//	unsigned int Level;//��Ļ��Σ��������Ļʱ����һ����Ļ���ڵ���һ����Ļ������ԽС��ʾ���Խ�ߣ���0��ʾ��㣻1��ʾ�ڶ�//�㣬�Դ����ơ�
//}ZimuPreviewInfo;
//Ԥ����Ļ��Ϣ�ṹ����  --- ����

typedef struct tagZimuMixInfo
{
	TCHAR       szZimuFile[MAX_PATH];//��Ļ�ļ���
	LONGLONG    rtStartPos;//��ʼʱ�䣨��λ��ms��
	LONGLONG    rtStopPos;//����ʱ�䣨��λ��ms��

						  //unsigned int Type;//��Ļ���ͣ�0 = ��̬��Ļ��1=��ɣ�2=�Ϲ�
	unsigned int Level;//��Ļ��Σ��������Ļʱ����һ����Ļ���ڵ���һ����Ļ������ԽС��ʾ���Խ�ߣ���0��ʾ��㣻1��ʾ�ڶ��㣬�Դ����ơ�
}ZimuMixInfo;

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//˵������CClipPlayControlIO�ǲ��ز�������࣬�ṩ�����в��ؽӿڡ�Ϊ�˱���DLL���ó�������޹�ͷ�ļ���������Graph�Ĳ�����װ��CGraphOper���С�
//      ��CGraphOper��װ��DirectShow��Graph���в�����
//      ��ˣ�DLL���ó���ֻ�����ͷ�ļ���ClipPlayControlIO.h�������������DirectShow�й�ͷ�ļ���
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

class CGraphOper;//����CGraphOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�

#ifdef _MAGICODE_CLIPPLAYCONTROL_
class _declspec(dllexport) CClipPlayControlIO  //������CClipPlayControlIO
#else
class _declspec(dllimport) CClipPlayControlIO  //������CClipPlayControlIO
#endif
{
public:
	CClipPlayControlIO();
	~CClipPlayControlIO();

public:	
	
	//���ز����ز�
	//������
	//1��szClipFileName ---- ����������ز��ļ�ȫ��������·�����ļ�����
	//2��ZimuList ---- �����������Ҫ���ӵ���Ļ�б�
	//3��hWnd ---- ����������ز�Ԥ�����ھ��
	//����ֵ��
	// S_OK ----- ���سɹ����������ʧ��
	//ע�⣺
	//1��ֻ�ܼ��ظ���MP4��H264����Ƶ�ز�
	//2��CClipPlayControlIO�ṩ���������нӿڶ�����SetClip�ɹ����غ����Ч�ģ�
	HRESULT SetClip(IN TCHAR *szClipFileName, vector<ZimuMixInfo> &ZimuList, IN HWND hWnd);


	/////////////////////////////////////////////////////
	//�زĲ��ؽӿ�
	//����
	//����ֵ��S_OK = �ɹ������� ʧ��
	HRESULT Play();

	//��ͣ
	//����ֵ��S_OK = �ɹ������� ʧ��
	HRESULT Pause();

	//����ͣ�ָ�����
	//����ֵ��S_OK = �ɹ������� ʧ��
	HRESULT Continue();

	//ֹͣ
	//����ֵ��S_OK = �ɹ������� ʧ��
	HRESULT Stop() ;

	//�϶��زĵ�ָ��λ��
	//������
	//  rtPos ---- ���������ָ��λ�õ�ʱ�䣬��λ��100ns
	HRESULT SetGivenPosition(LONGLONG rtPos);
	/////////////////////////////////////////////////////


	/////////////////////////////////////////////////////
	//����״̬�ӿ�

	//��ȡ��ǰ����״̬
	//����ֵ��
	//	0 = �������У�1=��ͣ��2=ֹͣ��3=�رգ�
	// ����-1ʱ����ʾ�����ˣ�
	int GetCurState();

	//��ȡ�ز�ʱ��
	//����ֵ���ز�ʱ������λ��100ns;
	// ����-1ʱ����ʾ�����ˣ�
	LONGLONG GetDuration();

	//��ȡ��ǰ����λ��
	//����ֵ����ǰ����λ�ã���λ��100ns
	// ����-1ʱ����ʾ�����ˣ�
	LONGLONG	GetPosition();

	//������㡢�����ǰ����λ��
	//������
	//  rtPos ---- ����ǰ����λ�ã���λ��100ns
	//  rtEndPos --- ���㣬�������Ϊ�ز�ĩβ���������ã�ֱ��ʹ��ȱʡֵ0����λ��100ns
	//����ֵ��S_OK = �ɹ������� ʧ��
	HRESULT SetPosition(LONGLONG rtPos, LONGLONG rtEndPos = 0);

	/////////////////////////////////////////////////////

	//����ָ��֡ͼ��ΪBMP�ļ�
	//������
	//1��szBmpFileName ---- ���������Bmpͼ���ļ�ȫ��������·�����ļ�����
	//2��rtPos ---- ����������������֡ͼ������ʱ�̣���λ��100ns
	//˵���������ͼƬΪ24λ1920*1080��С��BMPͼ
	void SaveGivenFrameToBmp(TCHAR *szBmpFileName, LONGLONG rtPos = 0);

private:

	CGraphOper             *m_pGraphOperObj; //����CGraphOper�����ָ�룬�������ͷ�ļ�
};

