#pragma once

/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//˵������CZimuCreateIO����Ļ����DLL���ṩ����Ļ���ɽӿڡ�Ϊ�˱���DLL���ó�������޹�ͷ�ļ�����������Ļ���ɲ�����װ��CZimuCreateOper���С�
//      ��ˣ�DLL���ó���ֻ�����ͷ�ļ���ZimuCreateIO.h�����������������ͷ�ļ���
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// */

class CZimuCreateOper;//����CZimuCreateOper�࣬Ȼ���������ָ�룬�������ͷ�ļ�

class CDirectWordObject;

#include <vector>
using namespace std;

#ifdef _MAGICODE_ZIMUCREATE_
class _declspec(dllexport) CZimuCreateIO  //������CZimuCreateIO
#else
class _declspec(dllimport) CZimuCreateIO  //������CZimuCreateIO
#endif
{
public:
	CZimuCreateIO();
	~CZimuCreateIO();

public:
	
	//---- ͼƬ��Ļ�ӿ� Begin -----//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���ܣ�����ͼƬ��Ļ������ͼƬ�ļ�������Ļ
	//������
	//1��csPicFile --- ���������ͼƬ�ļ�����֧�ֵ�ͼƬ�ļ���ʽ������*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.wmf;*.emf;*.j2k;*.jp2;*.jbg;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf;*.psd��
	//2��pPicture --- ���ɵ���Ļ���ݿ飬�ɵ��ó���������ݿ��ڴ棬����������ͷ��ڴ�
	//3��bmw  --- ���������������Ļ�Ŀ��
	//4��bmh --- ���������������Ļ�ĸ߶�
	//����ֵ���ɹ����� >= 0������ʧ�ܷ���<0����
	//��������˵��������ͼƬ��Ļ��Ҫ����2�ε��ñ���������һ��pPicture����NULL����ȡbmw��bmhֵ��Ȼ��new��pPicture���ڶ��ε��øú�����������Ļ����
	int PictureZimuIO(IN const TCHAR *csPicFile, OUT ULONG *pPicture, OUT ULONG &bmw, OUT ULONG &bmh);

	//���ܣ�ԭʼͼƬ��ת������תԭʼͼƬ��������Ļ
	//������
	//1��csOrigPicFile --- ���������ԭʼͼƬ�ļ�����֧�ֵ�ͼƬ�ļ���ʽ������*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.wmf;*.emf;*.j2k;*.jp2;*.jbg;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf;*.psd��
	//2��angle --- �����������ת�Ƕȣ���λ���ȣ�������Ϊ��������������ʾ��ʱ����ת
	//3��pPicture --- ���ɵ���Ļ���ݿ飬�ɵ��ó���������ݿ��ڴ棬����������ͷ��ڴ�
	//4��bmw  --- ���������������Ļ�Ŀ��
	//5��bmh --- ���������������Ļ�ĸ߶�
	//����ֵ���ɹ����� >= 0������ʧ�ܷ���<0����
	//��������˵��������ͼƬ��Ļ��Ҫ����2�ε��ñ���������һ��pPicture����NULL����ȡbmw��bmhֵ��Ȼ��new��pPicture���ڶ��ε��øú�����������Ļ����
	int ZimuFromPicRotateIO(IN const TCHAR *csOrigPicFile, IN float angle, OUT ULONG *pPicture, OUT ULONG &bmw, OUT ULONG &bmh);

	//���ܣ�ԭʼͼƬ���ţ�����ԭʼͼƬ���ź�������Ļ
	//������
	//1��csOrigPicFile --- ���������ԭʼͼƬ�ļ�����֧�ֵ�ͼƬ�ļ���ʽ������*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.wmf;*.emf;*.j2k;*.jp2;*.jbg;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf;*.psd��
	//2��factorX --- ����������������ϵ������ˮƽ��������ϵ��������Ϊ��ֵ��0����
	//3��factorY --- ����������߶�����ϵ��������ֱ��������ϵ��������Ϊ��ֵ��0����
	//4��pPicture --- ���ɵ���Ļ���ݿ飬�ɵ��ó���������ݿ��ڴ棬����������ͷ��ڴ�
	//5��bmw  --- ���������������Ļ�Ŀ��
	//6��bmh --- ���������������Ļ�ĸ߶�
	//����ֵ���ɹ����� >= 0������ʧ�ܷ���<0����
	//��������˵��������ͼƬ��Ļ��Ҫ����2�ε��ñ���������һ��pPicture����NULL����ȡbmw��bmhֵ��Ȼ��new��pPicture���ڶ��ε��øú�����������Ļ����
	int ZimuFromPicZoomIO(IN const TCHAR *csOrigPicFile, IN float factorX, IN float factorY, OUT ULONG *pPicture, OUT ULONG &bmw, OUT ULONG &bmh);

	//���ܣ�ԭʼͼƬ���񣬼���ԭʼͼƬ�����������Ļ
	//������
	//1��csOrigPicFile --- ���������ԭʼͼƬ�ļ�����֧�ֵ�ͼƬ�ļ���ʽ������*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.wmf;*.emf;*.j2k;*.jp2;*.jbg;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf;*.psd��
	//2��pPicture --- ���ɵ���Ļ���ݿ飬�ɵ��ó���������ݿ��ڴ棬����������ͷ��ڴ�
	//3��bmw  --- ���������������Ļ�Ŀ��
	//4��bmh --- ���������������Ļ�ĸ߶�
	//����ֵ���ɹ����� >= 0������ʧ�ܷ���<0����
	//��������˵��������ͼƬ��Ļ��Ҫ����2�ε��ñ���������һ��pPicture����NULL����ȡbmw��bmhֵ��Ȼ��new��pPicture���ڶ��ε��øú�����������Ļ����
	int ZimuFromPicMirrorIO(IN const TCHAR *csOrigPicFile, OUT ULONG *pPicture, OUT ULONG &bmw, OUT ULONG &bmh);


	//���ܣ�ԭʼͼƬ�ü�������ȡԭʼͼƬ�и��������������Ļ
	//������
	//1��csOrigPicFile --- ���������ԭʼͼƬ�ļ�����֧�ֵ�ͼƬ�ļ���ʽ������*.bmp;*.gif;*.jpg;*.jpeg;*.png;*.ico;*.tif;*.tiff;*.tga;*.pcx;*.wbmp;*.wmf;*.emf;*.j2k;*.jp2;*.jbg;*.j2c;*.jpc;*.pgx;*.pnm;*.pgm;*.ppm;*.ras;*.mng;*.jng;*.ska;*.nef;*.crw;*.cr2;*.mrw;*.raf;*.erf;*.3fr;*.dcr;*.raw;*.dng;*.pef;*.x3f;*.arw;*.sr2;*.mef;*.orf;*.psd��
	//2��area --- ����������ü�����ע�⣺���ܳ���ԭʼͼƬ��С
	//3��pPicture --- ���ɵ���Ļ���ݿ飬�ɵ��ó���������ݿ��ڴ棬����������ͷ��ڴ�
	//4��bmw  --- ���������������Ļ�Ŀ��
	//5��bmh --- ���������������Ļ�ĸ߶�
	//����ֵ���ɹ����� >= 0������ʧ�ܷ���<0����
	//��������˵��������ͼƬ��Ļ��Ҫ����2�ε��ñ���������һ��pPicture����NULL����ȡbmw��bmhֵ��Ȼ��new��pPicture���ڶ��ε��øú�����������Ļ����
	int ZimuFromPicCropIO(IN const TCHAR *csOrigPicFile, IN RECT &area, OUT ULONG *pPicture, OUT ULONG &bmw, OUT ULONG &bmh);
	//---- ͼƬ��Ļ�ӿ� End -----////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//---- �ı���Ļ�����ӿ� Begin -----//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//˵����
	//1�����������ӿ�ʵ�ִ��ı�������Ļ���ܣ����������ı����ݣ�csContent�����ı����ԣ�FillAttrib��WordAttrib�����ɾ�̬���ı���Ļ�����������������˶�������ɡ��Ϲ�����Ч�ȣ�
	//2���ӿڵ��������裺��һ�������ȵ���StartTxtZimuIO�ӿ�������Ļ���ڶ�������һ���ɹ����غ��ٵ���GetTxtZimuSizeIO�ӿڻ�ȡ��Ļ��uWidth�����ߣ�uHeight����
	//   ���������ڶ����ɹ����غ󣬵���������uWidth*uHeight*4�ֽڵ��ڴ�飨ע�⣺���ڴ����ͷ�Ҳ�ɵ����߸��𣡣���Ȼ�����GetTxtZimuBuffIO�ӿڻ�ȡ��Ļ���ݣ����ص���Ļ���ݸ�ʽΪRGBQUAD��

	//�ӿ�1��������Ļ�ӿ�
	//���ܣ������ı���Ļ���ɣ�������Ļ���������ָ��(CDirectWordObject����ָ��)
	//������
	//1��pFillAttrib --- �����������Ļ���������ֵ��������FILLATTRIB�ṹ�����ݿ飡
	//2��pWordAttrib --- �����������Ļ����������ֵ��������WORDATTRIB�ṹ�����ݿ飡
	//3��csContent  --- �����������������Ļ���ı���
	//4��uDis  --- �������������������Ļ֮��ļ��
	//5��iFlag  --- �����������Ļ���ͱ�־��ȡֵΪ�� 0 = �����Ļ��1=�Ϲ���Ļ��2=������Ļ��
	//����ֵ���ɹ�����CDirectWordObject����ָ�룻ʧ�ܷ���NULL
	CDirectWordObject *StartTxtZimuIO(IN BYTE *pFillAttrib, IN BYTE *pWordAttrib, IN TCHAR *csContent, IN ULONG uDis = 0, IN int iFlag = 0);

	//�ӿ�2����ȡ������Ļ�ߴ�ӿ�
	//���ܣ���ȡ�Ѿ����ɵ���Ļ�����С
	//����ֵ��>=0���ɹ�; <0��ʧ��
	//������
	// 1��pZimuObj ---- �����������Ļ����ָ�룬������StartTxtZimuIO�ӿڷ���ָ�룡
	// 2��uWidth ---- �������,���ɵ���Ļ���
	// 3��uHeight ----- �������,���ɵ���Ļ�߶�
	int GetTxtZimuSizeIO(IN CDirectWordObject *pZimuObj, OUT ULONG &uWidth, OUT ULONG &uHeight);

	//�ӿ�3����ȡ������Ļ���ݽӿ�
	//���ܣ���ȡ�Ѿ����ɵ���Ļ����
	//����ֵ��>=0���ɹ�; <0��ʧ��
	//������
	// 1��pZimuObj ---- �����������Ļ����ָ�룬������StartTxtZimuIO�ӿڷ���ָ�룡
	// 2��pBuff ---- �������,������Ļ���棬��Ҫ�����߷�����ͷ��ڴ�
	int GetTxtZimuBuffIO(IN CDirectWordObject *pZimuObj, OUT RGBQUAD *pBuff);
	//---- �ı���Ļ�����ӿ� End -----////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//---- ��Ļ��չ�ӿ� Begin -----//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//���ܣ����������ı�������Ļ�����浽�����ļ���
	//������
	//1��csContentStr  --- �����������������Ļ���ı���
	//2��pFillAttrib --- �����������Ļ���������ֵ��������FILLATTRIB�ṹ�����ݿ飡
	//3��pWordAttrib --- �����������Ļ����������ֵ��������WORDATTRIB�ṹ�����ݿ飡
	//4��pZimuAttrib --- �����������Ļ��չ����ֵ��������ZIMUEXTRAATTRIB�ṹ�����ݿ飡
	//5��szSavedFile  --- ���������������Ļ�ı����ļ�ȫ����
	//6��iMode  --- ���������szSavedFile�ļ�������ʽ��0 = �½���1=׷�ӣ��������ļ�����������Ļ׷�ӵ����ļ�
	//����ֵ��>=0���ɹ�; <0��ʧ��
	int CreateZimuFileIO(IN const TCHAR *csContentStr, IN BYTE *pFillAttrib, IN BYTE *pWordAttrib, IN BYTE *pZimuAttrib, IN TCHAR *szSavedFile, IN int iMode = 0);

	//���ܣ���������ͼƬ������Ļ�����浽�����ļ���
	//������
	//1��csPicFileName  --- �����������������Ļ��ͼƬ�ļ�
	//2��pZimuAttrib --- �����������Ļ��չ����ֵ��������ZIMUEXTRAATTRIB�ṹ�����ݿ飡ע�⣺��������ֻ�в������͡�������Χ�Ȳ�����Ч����������������
	//3��szSavedFile  --- ���������������Ļ�ı����ļ�ȫ����
	//4��iMode  --- ���������szSavedFile�ļ�������ʽ��0 = �½���1=׷�ӣ��������ļ�����������Ļ׷�ӵ����ļ�
	//����ֵ��>=0���ɹ�; <0��ʧ��
	int CreateZimuFileFromPicIO(IN const TCHAR *csPicFileName, IN BYTE *pZimuAttrib, IN TCHAR *szSavedFile, IN int iMode = 0);

	//���ܣ�����Ļ�ļ�������ļ�ͷ��Ϣ��֡����
	//������
	//1��ZimuFileName  --- ������������򿪵���Ļ�ļ�
	//2��phead --- �����������Ļ�ļ�ͷ��Ϣ��������ZIMUFILEHEAD�ṹ�����ݿ飡
	//3��pFrameArr --- �����������Ļ�ļ�������֡�����б�һ֡һ���ڵ��֡�����б���
	//����ֵ��>=0���ɹ�; <0��ʧ��
	//ע�⣺�ú���������ɺ�������ReleaseMemoryIO�����ͷ���Դ�����򽫵����ڴ�й©��
	int OpenZimuFileIO(IN const TCHAR *ZimuFileName, OUT BYTE *phead, OUT std::vector<RGBQUAD *> *pFrameArr);

	//���ܣ��ͷ�OpenZimuFileIO�����ӿ���ʹ�õ���Դ��������OpenZimuFileIO�������ý�������ñ��ӿ��ͷ���Դ��
	//������OpenZimuFileIO�����ӿ��������֡�����б�
	void ReleaseMemoryIO(IN std::vector<RGBQUAD *> *pFrameArr);
	//---- ��Ļ��չ�ӿ� End -----////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
private:

	CZimuCreateOper             *m_pZimuCreateOperObj; //����CZimuCreateOper�����ָ�룬�������ͷ�ļ�
};

