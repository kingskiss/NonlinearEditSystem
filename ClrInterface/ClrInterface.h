// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� CLRINTERFACE_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// CLRINTERFACE_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef CLRINTERFACE_EXPORTS
#define CLRINTERFACE_API __declspec(dllexport)
#else
#define CLRINTERFACE_API __declspec(dllimport)
#endif

// �����Ǵ� ClrInterface.dll ������
class CLRINTERFACE_API CClrInterface {
public:
	CClrInterface(void);
	// TODO:  �ڴ�������ķ�����
};

extern CLRINTERFACE_API int nClrInterface;

CLRINTERFACE_API int fnClrInterface(void);
