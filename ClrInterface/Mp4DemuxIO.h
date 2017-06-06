#pragma once

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//˵������CMp4DemuxIO��MP4���زĵ�����Ƶ���������ṩ������Ƶ����Ľӿڡ�Ϊ�˱���DLL���ó�������޹�ͷ�ļ���������demux�Ĳ�����װ��CDemuxOper���С�
//      ��ˣ�DLL���ó���ֻ�����ͷ�ļ���Mp4DemuxIO.h�����������������ͷ�ļ���
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */


class CDemuxOper;//����CDemuxOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�

#ifdef _MAGICODE_MP4DEMUX_
class _declspec(dllexport) CMp4DemuxIO  //������CMp4DemuxIO
#else
class _declspec(dllimport) CMp4DemuxIO  //������CMp4DemuxIO
#endif
{
public:
	CMp4DemuxIO();
	~CMp4DemuxIO();

public:

	//�����زĽ�������Ƶ����
	//������
	//1��szDemuxVideoFile ---- ����������������Ƶ�������ļ����ļ���Ϊ����ǰ����Ŀ¼\\_��ǰʱ��.v
	//2��szDemuxAudioFile ---- ����������������Ƶ�������ļ����ļ���Ϊ����ǰ����Ŀ¼\\_��ǰʱ��.a
	//3��szClipFileName ---- ����������ز��ļ�ȫ��������·�����ļ�����
	//4��rtPos ---- ��㣬������Ϊ�زĿ�ʼ���������ã�ֱ��ʹ��ȱʡֵ0����λ��ms
	//5��rtEndPos --- ���㣬�������Ϊ�ز�ĩβ���������ã�ֱ��ʹ��ȱʡֵ0����λ��ms
	//����ֵ��
	// >=0 �ɹ� ; <0 ʧ��
	//ע�⣺ֻ�ܼ��ظ���MP4��H264����Ƶ�ز�
	//�ú���һֱ�ȵ�����Ƶ������ɻ���ǿ���˳�ʱ�ŷ��أ������سɹ������������Ѿ����
	int AddClip(OUT TCHAR *szDemuxVideoFile, OUT TCHAR *szDemuxAudioFile,IN TCHAR *szClipFileName, IN LONGLONG rtPos = 0, IN LONGLONG rtEndPos = 0);

	//ֹͣ����
	void Stop();

private:

	CDemuxOper             *m_pDemuxOperObj; //����CDemuxOper�����ָ�룬�������ͷ�ļ�
};

