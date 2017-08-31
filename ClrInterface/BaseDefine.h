#ifndef MAGICODE_PACKETED_BASEDEFINE
#define	MAGICODE_PACKETED_BASEDEFINE

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

//��Ļ����Ļ��Ϣ�ṹ
typedef struct tagZimuMixInfo
{
	TCHAR       szZimuFile[MAX_PATH];//��Ļ�ļ���
	LONGLONG    rtStartPos;//��ʼʱ�䣨��λ��ms��
	LONGLONG    rtStopPos;//����ʱ�䣨��λ��ms��

	//unsigned int Type;//��Ļ���ͣ�0 = ��̬��Ļ��1=��ɣ�2=�Ϲ�
	unsigned int Level;//��Ļ��Σ��������Ļʱ����һ����Ļ���ڵ���һ����Ļ������ԽС��ʾ���Խ�ߣ���0��ʾ��㣻1��ʾ�ڶ��㣬�Դ����ơ�
}ZimuMixInfo;


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

#endif