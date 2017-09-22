#pragma once

#include <vector>
using namespace std;

class COptex
{
public:
	COptex() { InitializeCriticalSection(&cs); }
	~COptex() { DeleteCriticalSection(&cs); }
public:
	void Enter() { EnterCriticalSection(&cs); }
	void Leave() { LeaveCriticalSection(&cs); }
private:
	CRITICAL_SECTION cs;
};

class CObjectLock
{
public:
	CObjectLock(COptex& lock) : m_lock(lock) { m_lock.Enter(); }
	~CObjectLock() { m_lock.Leave(); }
private:
	COptex& m_lock;
};

//�ز���Ϣ�ṹ
typedef struct tagClipInfo
{
	TCHAR         szClipFile[MAX_PATH];//�ز��ļ���
	unsigned int  streamcount;//������������

	//��Ƶ����Ϣ
	unsigned int  Vsamplecount; //֡��
	double        Vduration;    //ʱ������λ��s��
	unsigned int  Vwidth;       //���
	unsigned int  Vheight;      //�߶�
	int/*majortypes_t*/  Vmajortype;   //�����ͣ�ֵ�μ�mcmediatypes.h��mcmajortypes_t����
	int/*mediatypes_t*/  Vmediatype;   //ý�����ͣ�ֵ�μ�mcmediatypes.h��mcmediatypes_t����

	//��Ƶ����Ϣ
	unsigned int  Asamplecount; //֡��
	double        Aduration;    //ʱ������λ��s��
	int/*majortypes_t*/  Amajortype;   //�����ͣ�ֵ�μ�mcmediatypes.h��mcmajortypes_t����
	int/*mediatypes_t*/  Amediatype;   //ý�����ͣ�ֵ�μ�mcmediatypes.h��mcmediatypes_t����
}ClipInfo;


//����Ƶ����ԭʼ�ز���Ϣ�ṹ
typedef struct tagDemuxClipInfo
{
	//��������Ϊ�������
	TCHAR       szClipFile[MAX_PATH];//�ز��ļ���
	LONGLONG    rtPos;//��㣨��λ��ms������������ã���ֵ0
	LONGLONG    rtEndPos;//���㣨��λ��ms������������ã���ֵ0

	//��������Ϊ�������������Ҫ��ֵ���ӿ�AddClipִ����ɺ󷵻�ֵ
	TCHAR       szDemuxedVFile[MAX_PATH];//�������Ƶ�ļ���
	TCHAR       szDemuxedAFile[MAX_PATH];//�������Ƶ�ļ���
	double      duration;//ʱ������λ��s��
} DemuxClipInfo;



//��Ļ��Ϣ�ṹ
//˵����
//1����ʼʱ��rtStartPos�ͽ���ʱ��rtStopPos���ڿ�����Ļ��ʱ���źͺ�ʱֹͣ�������Ҫ���ݲ�����Ҫ��ȷ������ֵ����֤��rtStopPos >= rtStartPos >= 0��  
//  ע�⣺rtStartPos��rtStopPos�����زĿ�ʼ����ʱ��Ϊ��㣨���˿�Ϊ0ms�������ʱ�䡣��������Ӷ���ز��б��еĵڶ����ز�10�봦��ʼ���ţ���Ļ��ֹʱ���Եڶ����ز�10�봦Ϊ0ʱ�̼���!!!
//2�������Ļ��Ҫ�ظ�����������Ҫ�ظ�������Ļ����Ϊ��һ������ʱ���ڣ�����rtStartPos��rtStopPos����Ļֻ�ܲ���һ�Σ������Ե�֡��Ļ����һ֡��Ļռ��ȫ������ʱ�䣻�Զ�֡��Ļ������Ļ����֡ƽ�����䲥��ʱ�䡣
//   �����Ϲ�����ɡ����������ʵȶ�̬��Ļ�������䲥���ٶ����ɶ�֡��Ļ����Ļ����֡ƽ������ȫ������ʱ�䣨������N֡�����Ļ������ʱ��ΪLen = rtStopPos - rtStartPos����ÿ֡����ʱ��Ϊ��Len/N����
//˵��������2���㷨���¶�̬��Ļ��ƽ�ȣ���˸�Ϊ����һ������ʱ������֡������ȫ��������ɺ��ͷ��ʼѭ���ظ�����!  --- 2018.8.18��
//3����Ļ���Ͳ���Type����Ҫ����Ϊ����������Ļ�������ɵ�����Ļ֡���ݣ�ֱ�ӿ��Բ�����������ʱ����Ҫ������Ļ�����ˣ�
typedef struct tagZimuMixInfo
{
	TCHAR       szZimuFile[MAX_PATH];//��Ļ�ļ���
	LONGLONG    rtStartPos;//��ʼʱ�䣨��λ��ms��
	LONGLONG    rtStopPos;//����ʱ�䣨��λ��ms��

						  //unsigned int Type;//��Ļ���ͣ�0 = ��̬��Ļ��1=��ɣ�2=�Ϲ�
	unsigned int Level;//��Ļ��Σ��������Ļʱ����һ����Ļ���ڵ���һ����Ļ������ԽС��ʾ���Խ�ߣ���0��ʾ��㣻1��ʾ�ڶ��㣬�Դ����ơ�

	tagZimuMixInfo()
	{
		ZeroMemory(szZimuFile, MAX_PATH);
		rtStartPos = 0;
		rtStopPos = 0;
		Level = 0;
	}
}ZimuMixInfo;



// ����Ƶ�ز���Ϣ�ṹ
typedef struct tagAVClipInfo
{
	TCHAR       szFile[MAX_PATH];//����Ƶ�ز��ļ���
	LONGLONG    rtInputPos;//��㣨��λ��ms��
	LONGLONG    rtOutputPos;//���㣨��λ��ms��

	tagAVClipInfo()
	{
		ZeroMemory(szFile, MAX_PATH);
		rtInputPos = 0;
		rtOutputPos = 0;
	}
}AVClipInfo;



//�����Ƶ����  --- ָ�����û����õ���Ƶ����
typedef struct tagVideoParameters
{
	int     bit_rate;//�����ʣ���λ��kbits/sec��ȱʡֵ��6000 (kbits/sec)
}VideoParameters;


//�����Ƶ���� --- ָ�����û����õ���Ƶ����
typedef struct tagAudioParameters
{
	double    sample_rate;//��Ƶ����Ƶ�ʣ���λ��kHz��������Ƶ����Ƶ����8kHz��11.025kHz��22.05kHz��16kHz��37.8kHz��44.1kHz��48kHz�ȣ�ȱʡֵ��44.1(kHz)

	int       bit_rate;//���ʣ���λ��kbits/sec����ѡ��ֵ�У�0, 6, 7, 8, 10, 12, 14, 16, 20, 24, 28, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 224, 256, 320, 384, 448, 512, 640, 768, 896, 1024�ȣ�ȱʡֵ��160(kbits/sec)
}AudioParameters;

