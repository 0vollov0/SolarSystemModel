
// SolarSystemModel.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CSolarSystemModelApp:
// �� Ŭ������ ������ ���ؼ��� SolarSystemModel.cpp�� �����Ͻʽÿ�.
//

class CSolarSystemModelApp : public CWinApp
{
public:
	CSolarSystemModelApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CSolarSystemModelApp theApp;