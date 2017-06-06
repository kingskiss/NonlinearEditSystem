#pragma once

#include <vector>
using namespace std;

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//˵������CH264CodecIOʵ�ֻ��ڹ����ڴ��MP4/AVC������Ƶ���롢��Ļ���ӡ����빦��

//      Ϊ�˱���DLL���ó�������޹�ͷ�ļ���������Decoder��Encoder������װ��CDecoderOper��CEncoderOper���С�
//      ��ˣ�DLL���ó���ֻ�����ͷ�ļ���H264CodecIO.h�����������������ͷ�ļ���
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */


class CDecoderOper;//����CDecoderOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�
class CEncoderOper;//����CEncoderOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�

class CAacDecOper;//����CAacDecOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�
class CAacEncOper;//����CAacEncOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�

#ifdef _MAGICODE_H264CODEC_
class _declspec(dllexport) CH264CodecIO  //������CH264CodecIO
#else
class _declspec(dllimport) CH264CodecIO  //������CH264CodecIO
#endif
{
public:
	CH264CodecIO();
	~CH264CodecIO();

public:

	//������������ط����h264��Ƶ�����룬��Ļ���ӣ����룬���������h264��Ƶ
	//������
	//2��szInH264VideoFileList ---- ��������������h264��Ƶ�ļ�ȫ��������·�����ļ������б�
	//3��szOutH264FileName ---- ���������������h264��Ƶ�ļ���������·�����ļ�����
	//����ֵ��
	// >=0 �ɹ� ; <0 ʧ��
	int Start(IN vector<TCHAR *> *szInH264VideoFileList, IN TCHAR *szOutH264FileName);


	//������Ƶ������룺���ط����AAC��Ƶ�����룬���룬���������AAC��Ƶ
	//������
	//1��szInH264VideoFileList ---- ��������������h264��Ƶ�ļ�ȫ��������·�����ļ������б�
	//2��szOutH264FileName ---- ���������������h264��Ƶ�ļ���������·�����ļ�����
	//����ֵ��
	// >=0 �ɹ� ; <0 ʧ��
	int StartAACDecEncoder(IN vector<TCHAR *> *szInAacFileList, IN TCHAR *szOutAacFileName);


	//ֹͣ���
	void Stop();

	//����Ƿ����
	BOOL isFinish();

private:

	CDecoderOper             *m_pDecoderOperObj; //����CDecoderOper�����ָ�룬�������ͷ�ļ�

	CEncoderOper             *m_pEncoderOperObj; //����CEncoderOper�����ָ�룬�������ͷ�ļ�

	CAacDecOper              *m_pAacDecoderOperObj; //����CAacDecOper�����ָ�룬�������ͷ�ļ�

	CAacEncOper              *m_pAacEncoderOperObj; //����CAacEncOper�����ָ�룬�������ͷ�ļ�

};

