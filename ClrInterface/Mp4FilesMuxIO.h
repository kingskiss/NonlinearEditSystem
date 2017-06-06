#pragma once

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//˵������CMp4FilesMuxIO��MP4/AVC/AAC����Ƶ�ļ���ϲ�����ṩ���Ѿ�ѹ����MP4/AVC/AAC����Ƶ�ļ��Ļ�Ͻӿڡ�Ϊ�˱���DLL���ó�������޹�ͷ�ļ���������Muxer�Ĳ�����װ��CMuxerOper���С�
//      ��ˣ�DLL���ó���ֻ�����ͷ�ļ���Mp4EncoderIO.h�����������������ͷ�ļ���
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

#include <vector>
using namespace std;

class CMuxerOper;//����CMuxerOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�

#ifdef _MAGICODE_MP4FILESMUX_
class _declspec(dllexport) CMp4FilesMuxIO  //������CMp4FilesMuxIO
#else
class _declspec(dllimport) CMp4FilesMuxIO  //������CMp4FilesMuxIO
#endif
{
public:
	CMp4FilesMuxIO();
	~CMp4FilesMuxIO();

public:

	////���ش���ϵ�����Ƶ�ļ����л��
	////������
	////1��input_streams ---- �������������ϵ�����Ƶ�ļ����������֧��MAX_INPUT_FILES������Ƶ�ļ�
	////2��input_filenames ---- �������������ϵ�����Ƶ�ļ�ȫ��������·�����ļ�����
	////3��output_filename ---- �����������Ϻ󱣴��ļ���������·�����ļ�����
	////����ֵ��
	//// >=0 �ɹ� ; <0 ʧ��
	////ע�⣺ֻ�ܼ����Ѿ�ѹ���ĸ���MP4��H264����ƵԴ�ļ�
	//int StartMuxer(int input_streams,IN TCHAR(*input_filenames)[MAX_PATH], IN TCHAR *output_filename);

	//���ش���ϵ�����Ƶ�ļ����л��
	//������
	//1��szInH264FileList ---- �������������ϵ�����Ƶ�ļ����б��ļ�������·�����ļ�������
	//2��output_filename ---- �����������Ϻ󱣴��ļ���������·�����ļ�����
	//����ֵ��
	// >=0 �ɹ� ; <0 ʧ��
	//ע�⣺
	//1��ֻ�ܼ����Ѿ�ѹ���ĸ���MP4��H264����ƵԴ�ļ���
	//2������ϵ�����Ƶ�ļ����������֧��MAX_INPUT_FILES������Ƶ�ļ�
	//3�����سɹ�����ϲ�һ���������Ƿ������Ҫ����MuxerFinished�����ж�
	int StartMuxer(IN vector<TCHAR *> szInH264FileList, IN TCHAR *output_filename);

	//ֹͣ���
	void StopMuxer();

	BOOL MuxerFinished();//����Ƿ��Ѿ�����

private:

	CMuxerOper             *m_pMuxerOperObj; //����CMuxerOper�����ָ�룬�������ͷ�ļ�
};