// ClrInterface.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "ClrInterface.h"


// ���ǵ���������һ��ʾ��
CLRINTERFACE_API int nClrInterface=0;

// ���ǵ���������һ��ʾ����
CLRINTERFACE_API int fnClrInterface(void)
{
    return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� ClrInterface.h
CClrInterface::CClrInterface()
{
    return;
}
