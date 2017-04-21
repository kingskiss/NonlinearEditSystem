#pragma once

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
	//2��hWnd ---- ����������ز�Ԥ�����ھ��
	//����ֵ��
	// S_OK ----- ���سɹ����������ʧ��
	//ע�⣺ֻ�ܼ��ظ���MP4��H264����Ƶ�ز�
	HRESULT SetClip(IN TCHAR *szClipFileName, IN HWND hWnd);


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



private:

	CGraphOper             *m_pGraphOperObj; //����CGraphOper�����ָ�룬�������ͷ�ļ�
};

