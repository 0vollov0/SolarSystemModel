
// SolarSystemModelDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SolarSystemModel.h"
#include "SolarSystemModelDlg.h"
#include "afxdialogex.h"
#include <math.h>
#include <stdlib.h>
#pragma comment(lib, "winmm")
#include <mmsystem.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSolarSystemModelDlg 대화 상자



CSolarSystemModelDlg::CSolarSystemModelDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SOLARSYSTEMMODEL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSolarSystemModelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSolarSystemModelDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_WM_GETMINMAXINFO()
	ON_WM_KEYDOWN()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSolarSystemModelDlg 메시지 처리기

BOOL CSolarSystemModelDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	srand(time(NULL));
	side_point = rand() % 4;
	Asteroid_size = rand() % 10 + 5;
	PI = 3.141592653589793238;
	rad = PI / 180.0;
	revol_i = 1.0;
	black_hole = false;
	SoundPath1 = "Wav\\Explosion.wav";
	SoundPath2 = "Wav\\Goalin.wav";
	SoundPath3 = "Wav\\BGM.wav";
	for (int i = 0; i < NEPTUNE + 1; i++)
	{
		Planet_Info[i].explosion = Planet_Info[i].express = false;
	}

	Planet_Info[MERCURY].dist = 66.0;
	Planet_Info[MERCURY].radius = 3.0;
	Planet_Info[MERCURY].revolution = 0.0;
	Planet_Info[MERCURY].flag = true;

	Planet_Info[VENUS].dist = 79.0;
	Planet_Info[VENUS].radius = 7.0;
	Planet_Info[VENUS].revolution = 90.0;
	Planet_Info[VENUS].flag = true;

	Planet_Info[EARTH].dist = 97.0;
	Planet_Info[EARTH].radius = 8.0;
	Planet_Info[EARTH].revolution = 180.0;
	Planet_Info[EARTH].flag = true;

	Planet_Info[MARS].dist = 114.0;
	Planet_Info[MARS].radius = 4.0;
	Planet_Info[MARS].revolution = 270.0;
	Planet_Info[MARS].flag = true;

	Planet_Info[JUPITER].dist = 168.0;
	Planet_Info[JUPITER].radius = 17.0;
	Planet_Info[JUPITER].revolution = 0.0;

	Planet_Info[SATURN].dist = 241.0;
	Planet_Info[SATURN].radius = 16.0;
	Planet_Info[SATURN].revolution = 90.0;

	Planet_Info[URANUS].dist = 352.0;
	Planet_Info[URANUS].radius = 12.0;
	Planet_Info[URANUS].revolution = 180.0;

	Planet_Info[NEPTUNE].dist = 455.0;
	Planet_Info[NEPTUNE].radius = 11.0;
	Planet_Info[NEPTUNE].revolution = 270.0;

	Moon_dist = 11.0;
	Moon_radius = 2.0;
	Moon_revolution = 0.0;

	Io_dist = 20.0;
	Io_radius = 2.0;
	Io_revolution = 0.0;

	Europa_dist = 26.0;
	Europa_radius = 2.0;
	Europa_revolution = 0.0;

	Ganymede_dist = 32.0;
	Ganymede_radius = 2.0;
	Ganymede_revolution = 0.0;

	Titan_dist = 25.0;
	Titan_radius = 2.0;
	Titan_revolution = 0.0;

	Enceladus_dist = 31.0;
	Enceladus_radius = 2.0;
	Enceladus_revolution = 0.0;

	Asteroid_x = 0;
	Asteroid_y = 0;
	Asteroid_incress = 0;
	flag = 0;
	start_point_flag = 0;

	Timer = 0;

	bh_incress = 1.0;


	SetTimer(365, 34, NULL);
	SetTimer(10, 1000, NULL);
	SetTimer(11, 120000, NULL);
	Space_bitmap.LoadBitmapA(IDB_BITMAP_SPACE);
	Sun_bitmap.LoadBitmapA(IDB_BITMAP_SUN);
	Mercury_bitmap.LoadBitmapA(IDB_BITMAP_MERCURY);
	Venus_bitmap.LoadBitmapA(IDB_BITMAP_VENUS);
	Earth_bitmap.LoadBitmapA(IDB_BITMAP_EARTH);
	Mars_bitmap.LoadBitmapA(IDB_BITMAP_MARS);
	Jupiter_bitmap.LoadBitmapA(IDB_BITMAP_JUPITER);
	Saturn_bitmap.LoadBitmapA(IDB_BITMAP_SATURN);
	Uranus_bitmap.LoadBitmapA(IDB_BITMAP_URANUS);
	Neptune_bitmap.LoadBitmapA(IDB_BITMAP_NEPTUNE);
	Moon_bitmap.LoadBitmapA(IDB_BITMAP_MOON);
	Io_bitmap.LoadBitmapA(IDB_BITMAP_IO);
	Europa_bitmap.LoadBitmapA(IDB_BITMAP_EUROPA);
	Ganymede_bitmap.LoadBitmapA(IDB_BITMAP_GANYMEDE);
	Titan_bitmap.LoadBitmapA(IDB_BITMAP_TITAN);
	Enceladus_bitmap.LoadBitmapA(IDB_BITMAP_ENCELADUS);
	Asteroid_bitmap.LoadBitmapA(IDB_BITMAP_ASTEROID);
	L90_Asteroid_bitmap.LoadBitmapA(IDB_BITMAP_L90_ASTEROID);
	L180_Asteroid_bitmap.LoadBitmapA(IDB_BITMAP_L180_ASTEROID);
	L270_Asteroid_bitmap.LoadBitmapA(IDB_BITMAP_L270_ASTEROID);
	Explosion_bitmap.LoadBitmapA(IDB_BITMAP_EXPLOSION);
	Saturn_Explosion_bitmap.LoadBitmapA(IDB_BITMAP_SATURN_EXPLOSION);
	Blackhole_bitmap.LoadBitmapA(IDB_BITMAP_BLACKHOLE);
	SpaceMan_bitmap.LoadBitmapA(IDB_BITMAP_SPACEMAN);
	Space_bitmap.GetObject(sizeof(BITMAP), (LPVOID)&m_Bitmap);
	//PlaySound(SoundPath3, AfxGetInstanceHandle(), SND_ASYNC);
	PlaySound(MAKEINTRESOURCE(IDR_WAVE_BGM), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSolarSystemModelDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSolarSystemModelDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
	CClientDC pDC(this);
	CRect rect;
	GetClientRect(rect);

	CDC Back;
	Back.CreateCompatibleDC(&pDC);
	CBitmap Back_bitmap;
	Back_bitmap.CreateCompatibleBitmap(&pDC, rect.right, rect.bottom);
	Back.SelectObject(Back_bitmap);

	CBitmap bmpOffScreen;
	bmpOffScreen.CreateCompatibleBitmap(&pDC, rect.right, rect.bottom);

	DrawBackGround(&Back, rect);

	if (Sun_express)CreateSun(&Back, wcp, rect);

	double tmp = sqrt((double)(hp.x - wcp.x)*(hp.x - wcp.x) + (hp.y - wcp.y)*(hp.y - wcp.y));
	if (black_hole)
	{
		double dist;
		CreateBlackhole(&Back, hp, rect);
		dist = sqrt((double)(hp.x - wcp.x)*(hp.x - wcp.x) + (hp.y - wcp.y)*(hp.y - wcp.y));
		if (dist > bh_radius&&Sun_express) {
			if (wcp.x < hp.x) wcp.x += (LONG)vx;
			if (wcp.y < hp.y) wcp.y += (LONG)vy;
		}
		for (int i = 0; i < NEPTUNE + 1; i++)
		{
			if (!Sun_express) {
				if (Planet_Info[i].dist <= 0 || !Planet_Info[i].TF_dist) {
					Planet_Info[i].dist += (0.2*rect.bottom / 1918.0)*bh_incress;
					Planet_Info[i].TF_dist = false;
				}
				else {
					if (Planet_Info[i].TF_dist) {
						Planet_Info[i].dist -= (0.2*rect.bottom / 1918.0)*bh_incress;
						bh_incress += 0.01;
					}
				}

			}

		}
	}
	else
	{
		wcp.x = rect.right / 2;
		wcp.y = rect.bottom / 2;
	}

	CreatePlanet(&Back, wcp, rect);
	SpaceMan(&Back, mp);
	if (revol_i > 0.0) {
		if (side_point == 0) T_CreateAsteroid(&Back, rect);
		else if (side_point == 1) L_CreateAsteroid(&Back, rect);
		else if (side_point == 2) B_CreateAsteroid(&Back, rect);
		else if (side_point == 3) R_CreateAsteroid(&Back, rect);
	}
	else {
		CreateAsteroid(&Back, rect);
	}

	for (int i = 0; i < NEPTUNE + 1; i++)
	{
		if (Planet_Info[i].express)	if (Explosion(&Back, i)) Timer++;
		if (Timer > 20) {
			Planet_Info[i].express = false;
			Timer = 0;
		}
	}
	
	pDC.BitBlt(0, 0, rect.right, rect.bottom, &Back, 0, 0, SRCCOPY);
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSolarSystemModelDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CSolarSystemModelDlg::DrawBackGround(CDC* dc, CRect rect)
{
	BITMAP bmpinfo;
	Space_bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Space_bitmap);

	dc->StretchBlt(0, 0, rect.right, rect.right, &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, SRCCOPY);
}
void CSolarSystemModelDlg::CreateSun(CDC* dc, CPoint cp, CRect rect)
{
	BITMAP Sun_bmpinfo;
	Sun_bitmap.GetBitmap(&Sun_bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Sun_bitmap);
	int size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	Sun_radius = int(60.0 * size / 950.0);
	dc->TransparentBlt(cp.x - Sun_radius, cp.y - Sun_radius, Sun_radius * 2, Sun_radius * 2, &memDC, 0, 0, Sun_bmpinfo.bmWidth, Sun_bmpinfo.bmHeight, RGB(0, 0, 0));
	if (sqrt(pow(hp.x - (cp.x), 2) + pow(hp.y + bh_radius - (cp.y), 2)) < bh_radius + Sun_radius / 2) {
		PlaySound(SoundPath2, AfxGetInstanceHandle(), SND_ASYNC);
		Sun_express = false;
	}


	if (sqrt(pow(cp.x - (Asteroid_x + Asteroid_size / 2), 2) + pow(cp.y - (Asteroid_y + Asteroid_size / 2), 2)) < Sun_radius + Asteroid_size) {
		start_point_flag = 0;
		Asteroid_incress = 0;
		Asteroid_size = rand() % 10 + 5;
		side_point = rand() % 4;
	}
}
void CSolarSystemModelDlg::CreateBlackhole(CDC* dc, CPoint cp, CRect rect)
{
	BITMAP Blackhole_bmpinfo;
	Blackhole_bitmap.GetBitmap(&Blackhole_bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Blackhole_bitmap);

	int size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	bh_radius = int(30.0 * size / 950.0);
	dc->TransparentBlt(cp.x - bh_radius, cp.y - bh_radius, bh_radius * 2, bh_radius * 2, &memDC, 0, 0, Blackhole_bmpinfo.bmWidth, Blackhole_bmpinfo.bmHeight, RGB(0, 0, 0));
}

void CSolarSystemModelDlg::CreateMoon(CDC* dc, CPoint cp, CRect rect)
{

	BITMAP bmpinfo;
	Moon_bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Moon_bitmap);
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	double dist = Moon_dist * size / 950.0;
	double radius = Moon_radius * size / 950.0;
	dc->TransparentBlt(int(cp.x + int(cos(rad*Moon_revolution)*dist - radius)), int(cp.y + sin(rad * Moon_revolution)*dist - radius), int(radius * 2), int(radius * 2), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
}

void CSolarSystemModelDlg::CreateIo(CDC* dc, CPoint cp, CRect rect)
{

	BITMAP bmpinfo;
	Io_bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Io_bitmap);
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	double dist = Io_dist * size / 950.0;
	double radius = Io_radius * size / 950.0;
	dc->TransparentBlt(int(cp.x + int(cos(rad*Io_revolution)*dist - radius)), int(cp.y + sin(rad * Io_revolution)*dist - radius), int(radius * 2), int(radius * 2), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
}
void CSolarSystemModelDlg::CreateEuropa(CDC* dc, CPoint cp, CRect rect)
{

	BITMAP bmpinfo;
	Europa_bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Europa_bitmap);
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	double dist = Europa_dist * size / 950.0;
	double radius = Europa_radius * size / 950.0;
	dc->TransparentBlt(int(cp.x + cos(rad*Europa_revolution)*dist - radius), int(cp.y + sin(rad * Europa_revolution)*dist - radius), int(radius * 2), int(radius * 2), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
}
void CSolarSystemModelDlg::CreateGanymede(CDC* dc, CPoint cp, CRect rect)
{

	BITMAP bmpinfo;
	Ganymede_bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Ganymede_bitmap);
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	double dist = Ganymede_dist * size / 950.0;
	double radius = Ganymede_radius * size / 950.0;
	dc->TransparentBlt(int(cp.x + cos(rad*Ganymede_revolution)*dist - radius), int(cp.y + sin(rad * Ganymede_revolution)*dist - radius), int(radius * 2), int(radius * 2), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
}

void CSolarSystemModelDlg::CreateTitan(CDC* dc, CPoint cp, CRect rect)
{

	BITMAP bmpinfo;
	Titan_bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Titan_bitmap);

	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	double dist = Titan_dist * size / 950.0;
	double radius = Titan_radius * size / 950.0;

	dc->TransparentBlt(int(cp.x + cos(rad*Titan_revolution)*dist - radius), int(cp.y + sin(rad * Titan_revolution)*dist - radius), int(radius * 2), int(radius * 2), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
}
void CSolarSystemModelDlg::CreateEnceladus(CDC* dc, CPoint cp, CRect rect)
{

	BITMAP bmpinfo;
	Enceladus_bitmap.GetBitmap(&bmpinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Enceladus_bitmap);

	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	double dist = Enceladus_dist * size / 950.0;
	double radius = Enceladus_radius * size / 950.0;

	dc->TransparentBlt(int(cp.x + cos(rad*Enceladus_revolution)*dist - radius), int(cp.y + sin(rad * Enceladus_revolution)*dist - radius), int(radius * 2), int(radius * 2), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
}

void CSolarSystemModelDlg::CreatePlanet(CDC *dc, CPoint cp, CRect rect) {
	for (int i = 0; i < NEPTUNE + 1; i++)
	{
		if (!Planet_Info[i].flag) continue;
		CDC memDC;
		memDC.CreateCompatibleDC(dc);
		if (Planet_Info[i].explosion)
		{
			Explosion_bitmap.GetBitmap(&bmpinfo[i]);
			memDC.SelectObject(Explosion_bitmap);
			if (i == SATURN) {
				Saturn_Explosion_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Saturn_Explosion_bitmap);
			}
		}
		else
		{
			switch (i)
			{
			case VENUS:
				Venus_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Venus_bitmap);
				break;
			case MERCURY:
				Mercury_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Mercury_bitmap);
				break;
			case EARTH:
				Earth_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Earth_bitmap);
				break;
			case MARS:
				Mars_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Mars_bitmap);
				break;
			case JUPITER:
				Jupiter_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Jupiter_bitmap);
				break;
			case SATURN:
				Saturn_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Saturn_bitmap);
				break;
			case URANUS:
				Uranus_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Uranus_bitmap);
				break;
			case NEPTUNE:
				Neptune_bitmap.GetBitmap(&bmpinfo[i]);
				memDC.SelectObject(Neptune_bitmap);
				break;
			default:
				break;
			}
		}
		double size;
		if (rect.right < rect.bottom) {
			size = rect.right;
		}
		else
		{
			size = rect.bottom;
		}
		double dist = Planet_Info[i].dist * size / 950.0;
		double radius = Planet_Info[i].radius * size / 950.0;
		PlanetPos[i].x = int(cp.x + cos(rad*Planet_Info[i].revolution)*dist);
		PlanetPos[i].y = int(cp.y + sin(rad * Planet_Info[i].revolution)*dist);

		dc->TransparentBlt(int(PlanetPos[i].x - radius), int(PlanetPos[i].y - radius), int(radius * 2), int(radius * 2), &memDC, 0, 0, bmpinfo[i].bmWidth, bmpinfo[i].bmHeight, RGB(0, 0, 0));
		if (sqrt(pow(hp.x - (PlanetPos[i].x + Planet_Info[i].radius), 2) + pow(hp.y - (PlanetPos[i].y + Planet_Info[i].radius), 2)) < bh_radius + Planet_Info[i].radius) {
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_GOALIN), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			Planet_Info[i].flag = false;
		}
		if (Sun_radius > Planet_Info[i].dist && Sun_express) {
			Planet_Info[i].flag = false;
			Planet_Info[i].express = true;
			Planet_Info[i].explosion = true;
		}
		if (sqrt(pow(PlanetPos[i].x - (Asteroid_x + rate_Asteroid / 2), 2) + pow(PlanetPos[i].y - (Asteroid_y + rate_Asteroid / 2), 2)) < radius + rate_Asteroid) {
			PlaySound(MAKEINTRESOURCE(IDR_WAVE_EXPLOSION), AfxGetInstanceHandle(), SND_RESOURCE | SND_ASYNC);
			if ((rate_Asteroid >= radius * 2) && i < 4) {
				Planet_Info[i].flag = false;
				Planet_Info[i].express = true;
			}
			start_point_flag = 0;
			Asteroid_incress = 0;
			Asteroid_size = rand() % 10 + 5;
			side_point = rand() % 4;
			Planet_Info[i].explosion = true;
		}
		switch (i)
		{
		case EARTH:
			CreateMoon(dc, PlanetPos[i], rect);
			break;
		case JUPITER:
			CreateIo(dc, PlanetPos[i], rect);
			CreateEuropa(dc, PlanetPos[i], rect);
			CreateGanymede(dc, PlanetPos[i], rect);
			break;
		case SATURN:
			CreateTitan(dc, PlanetPos[i], rect);
			CreateEnceladus(dc, PlanetPos[i], rect);
			break;
		default:
			break;
		}
	}
}

void CSolarSystemModelDlg::T_CreateAsteroid(CDC *dc, CRect rect)
{

	BITMAP bmpinfo;
	if (flag == 0) {
		Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 1) {
		L90_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 2) {
		L180_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 3) {
		L270_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}


	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Asteroid_bitmap);
	if (flag == 0) {
		memDC.SelectObject(Asteroid_bitmap);
		flag++;
	}
	else if (flag == 1) {
		memDC.SelectObject(L90_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 2) {
		memDC.SelectObject(L180_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 3) {
		memDC.SelectObject(L270_Asteroid_bitmap);
		flag = 0;
	}

	if (start_point_flag == 0) {
		x_start_point = rand() % rect.right;
		y_start_point = 0;
		start_point_flag = 1;
		if (rand() % 2 == 0) {
			Asteroid_incress = 1;
		}
		else
		{
			Asteroid_incress = -1;
		}
	}
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	rate_Asteroid = Asteroid_size * size / 950.0;

	Asteroid_x = x_start_point + Asteroid_incress;
	Asteroid_y = y_start_point + abs(Asteroid_incress);

	if (textcolor) {
		dc->SetTextColor(RGB(255, 0, 0));
	}
	else {
		dc->SetTextColor(RGB(255, 255, 0));
	}
	dc->SetBkMode(TRANSPARENT);
	dc->TextOutA(Asteroid_x + 15, Asteroid_y, _T("Warnning"));
	dc->TransparentBlt(Asteroid_x, Asteroid_y, int(rate_Asteroid), int(rate_Asteroid), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
	if (x_start_point + Asteroid_incress < 0 || x_start_point + Asteroid_incress > rect.right || y_start_point + abs(Asteroid_incress) > rect.bottom) {
		start_point_flag = 0;
		Asteroid_incress = 0;
		Asteroid_size = rand() % 10 + 5;
		side_point = rand() % 4;
	}
}
void CSolarSystemModelDlg::L_CreateAsteroid(CDC *dc, CRect rect)
{
	BITMAP bmpinfo;
	if (flag == 0) {
		Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 1) {
		L90_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 2) {
		L180_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 3) {
		L270_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}


	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Asteroid_bitmap);
	if (flag == 0) {
		memDC.SelectObject(Asteroid_bitmap);
		flag++;
	}
	else if (flag == 1) {
		memDC.SelectObject(L90_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 2) {
		memDC.SelectObject(L180_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 3) {
		memDC.SelectObject(L270_Asteroid_bitmap);
		flag = 0;
	}

	if (start_point_flag == 0) {
		x_start_point = 0;
		y_start_point = rand() % rect.bottom;
		start_point_flag = 1;
		if (rand() % 2 == 0) {
			Asteroid_incress = 1;
		}
		else
		{
			Asteroid_incress = -1;
		}
	}
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	rate_Asteroid = Asteroid_size * size / 950.0;
	Asteroid_x = x_start_point + abs(Asteroid_incress);
	Asteroid_y = y_start_point + Asteroid_incress;

	if (textcolor) {
		dc->SetTextColor(RGB(255, 0, 0));
	}
	else {
		dc->SetTextColor(RGB(255, 255, 0));
	}
	dc->SetBkMode(TRANSPARENT);
	dc->TextOutA(Asteroid_x + 15, Asteroid_y, _T("Warnning"));
	dc->TransparentBlt(Asteroid_x, Asteroid_y, int(rate_Asteroid), int(rate_Asteroid), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
	if (y_start_point + Asteroid_incress < 0 || y_start_point + Asteroid_incress > rect.bottom || x_start_point + abs(Asteroid_incress) > rect.right) {
		start_point_flag = 0;
		Asteroid_incress = 0;
		Asteroid_size = rand() % 10 + 5;
		side_point = rand() % 4;
	}
}
void CSolarSystemModelDlg::B_CreateAsteroid(CDC *dc, CRect rect)
{
	BITMAP bmpinfo;
	if (flag == 0) {
		Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 1) {
		L90_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 2) {
		L180_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 3) {
		L270_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}


	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Asteroid_bitmap);
	if (flag == 0) {
		memDC.SelectObject(Asteroid_bitmap);
		flag++;
	}
	else if (flag == 1) {
		memDC.SelectObject(L90_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 2) {
		memDC.SelectObject(L180_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 3) {
		memDC.SelectObject(L270_Asteroid_bitmap);
		flag = 0;
	}

	if (start_point_flag == 0) {
		x_start_point = rand() % rect.right;
		y_start_point = rect.bottom;
		start_point_flag = 1;
		if (rand() % 2 == 0) {
			Asteroid_incress = 1;
		}
		else
		{
			Asteroid_incress = -1;
		}
	}
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	rate_Asteroid = Asteroid_size * size / 950.0;
	Asteroid_x = x_start_point + Asteroid_incress;
	Asteroid_y = y_start_point - abs(Asteroid_incress);

	if (textcolor) {
		dc->SetTextColor(RGB(255, 0, 0));
	}
	else {
		dc->SetTextColor(RGB(255, 255, 0));
	}
	dc->SetBkMode(TRANSPARENT);
	dc->TextOutA(Asteroid_x + 15, Asteroid_y, _T("Warnning"));
	dc->TransparentBlt(Asteroid_x, Asteroid_y, int(rate_Asteroid), int(rate_Asteroid), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
	if (x_start_point + Asteroid_incress < 0 || x_start_point + Asteroid_incress > rect.right || y_start_point - abs(Asteroid_incress) < 0) {
		start_point_flag = 0;
		Asteroid_incress = 0;
		Asteroid_size = rand() % 10 + 5;
		side_point = rand() % 4;
	}
}
void CSolarSystemModelDlg::R_CreateAsteroid(CDC *dc, CRect rect)
{
	BITMAP bmpinfo;
	if (flag == 0) {
		Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 1) {
		L90_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 2) {
		L180_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}
	else if (flag == 3) {
		L270_Asteroid_bitmap.GetBitmap(&bmpinfo);
	}


	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Asteroid_bitmap);
	if (flag == 0) {
		memDC.SelectObject(Asteroid_bitmap);
		flag++;
	}
	else if (flag == 1) {
		memDC.SelectObject(L90_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 2) {
		memDC.SelectObject(L180_Asteroid_bitmap);
		flag++;
	}
	else if (flag == 3) {
		memDC.SelectObject(L270_Asteroid_bitmap);
		flag = 0;
	}

	if (start_point_flag == 0) {
		x_start_point = rect.right;
		y_start_point = rand() % rect.bottom;
		start_point_flag = 1;
		if (rand() % 2 == 0) {
			Asteroid_incress = 1;
		}
		else
		{
			Asteroid_incress = -1;
		}
	}
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}
	rate_Asteroid = Asteroid_size * size / 950.0;
	Asteroid_x = x_start_point - abs(Asteroid_incress);
	Asteroid_y = y_start_point + Asteroid_incress;

	if (textcolor) {
		dc->SetTextColor(RGB(255, 0, 0));
	}
	else {
		dc->SetTextColor(RGB(255, 255, 0));
	}
	dc->SetBkMode(TRANSPARENT);
	dc->TextOutA(Asteroid_x + 15, Asteroid_y, _T("Warnning"));
	dc->TransparentBlt(Asteroid_x, Asteroid_y, int(rate_Asteroid), int(rate_Asteroid), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
	if (y_start_point + Asteroid_incress < 0 || y_start_point + Asteroid_incress > rect.bottom || x_start_point - abs(Asteroid_incress) < 0) {
		start_point_flag = 0;
		Asteroid_incress = 0;
		Asteroid_size = rand() % 10 + 5;
		side_point = rand() % 4;
	}


}
void CSolarSystemModelDlg::CreateAsteroid(CDC *dc, CRect rect)
{
	BITMAP bmpinfo;
	Asteroid_bitmap.GetBitmap(&bmpinfo);
	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(Asteroid_bitmap);
	double size;
	if (rect.right < rect.bottom) {
		size = rect.right;
	}
	else
	{
		size = rect.bottom;
	}

	dc->SetTextColor(RGB(255, 0, 0));
	dc->SetBkMode(TRANSPARENT);
	dc->TextOutA(Asteroid_x + 15, Asteroid_y, _T("Warnning"));
	rate_Asteroid = Asteroid_size * size / 950.0;
	dc->TransparentBlt(Asteroid_x, Asteroid_y, int(rate_Asteroid), int(rate_Asteroid), &memDC, 0, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, RGB(0, 0, 0));
}

bool CSolarSystemModelDlg::Explosion(CDC *dc, int i)
{
	double dist;
	for (int r = int(PlanetPos[i].y - Planet_Info[i].radius); r < int(PlanetPos[i].y + Planet_Info[i].radius); r++)
	{
		for (int c = int(PlanetPos[i].x - Planet_Info[i].radius); c < int(PlanetPos[i].x + Planet_Info[i].radius); c++)
		{
			dist = sqrt((double)(PlanetPos[i].x - c)*(PlanetPos[i].x - c) + (PlanetPos[i].y - r)*(PlanetPos[i].y - r));
			if (dist <= Planet_Info[i].radius) dc->SetPixel(c, r, RGB(rand() % 255, rand() % 255, 0));
		}
	}
	return true;
}

void CSolarSystemModelDlg::SpaceMan(CDC *dc, CPoint cp) {
	BITMAP bitmapinfo;
	SpaceMan_bitmap.GetBitmap(&bitmapinfo);

	CDC memDC;
	memDC.CreateCompatibleDC(dc);
	memDC.SelectObject(SpaceMan_bitmap);
	int Mansize = 10;
	dc->TransparentBlt(cp.x - Mansize, cp.y - Mansize, Mansize * 2, Mansize * 2, &memDC, 0, 0, bitmapinfo.bmWidth, bitmapinfo.bmHeight, RGB(0, 0, 0));
}


BOOL CSolarSystemModelDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return CDialogEx::OnEraseBkgnd(pDC);
	return true;
}


void CSolarSystemModelDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	lpMMI->ptMinTrackSize.x = 800;
	lpMMI->ptMinTrackSize.y = 400;
	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


void CSolarSystemModelDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar) {
	case VK_UP:
		if (revol_i < 4.0)	revol_i += 1.0;
		break;
	case VK_DOWN:
		if (revol_i >= 1)	revol_i -= 1.0;
		break;
	case VK_PRIOR:
		if (revol_i < 4.0)	revol_i += 1.0;
		break;
	case VK_NEXT:
		if (revol_i >= 1)	revol_i -= 1.0;
		break;	
	case VK_BACK:
		black_hole = true;
		CRect rect;
		GetClientRect(rect);
		double size;
		if (rect.right < rect.bottom) {
			size = rect.right;
		}
		else
		{
			size = rect.bottom;
		}
		hp.x = rect.right - rect.right / 3;
		hp.y = rect.bottom - rect.bottom / 5;
		vx = (hp.x - wcp.x) / 100.0;
		vy = (hp.y - wcp.y) / 100.0;
		if (vx <= 1.0) {
			vx = 1.0;
		}
		if (vy <= 1.0) {
			vy = 1.0;
		}
		break;
	}
	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CSolarSystemModelDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	for (int i = 0; i < NEPTUNE + 1; i++)
	{
		if (sqrt(pow(point.x - PlanetPos[i].x, 2) + pow(point.y - PlanetPos[i].y, 2)) < Planet_Info[i].radius) {
			Planet_Info[i].explosion = false;
		}
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSolarSystemModelDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	mp = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CSolarSystemModelDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nIDEvent)
	{
	case 365:
		Planet_Info[MERCURY].revolution += 4.2 * revol_i;	if (Planet_Info[MERCURY].revolution >= 357.0)Planet_Info[MERCURY].revolution = 0.0;
		Planet_Info[VENUS].revolution += 1.6* revol_i;	if (Planet_Info[VENUS].revolution >= 360.0) Planet_Info[VENUS].revolution = 0.0;
		Planet_Info[EARTH].revolution += 1.0* revol_i;		if (Planet_Info[EARTH].revolution >= 360.0) Planet_Info[EARTH].revolution = 0.0;
		Moon_revolution += 0.6* revol_i;	if (Moon_revolution >= 360.0) Moon_revolution = 0.0;
		Planet_Info[MARS].revolution += 0.53* revol_i;	if (Planet_Info[MARS].revolution >= 359.87) Planet_Info[MARS].revolution = 0.0;
		Planet_Info[JUPITER].revolution += 0.08* revol_i;	if (Planet_Info[JUPITER].revolution >= 360.0) Planet_Info[JUPITER].revolution = 0.0;
		Io_revolution += 21.0* revol_i;		if (Io_revolution >= 357.0) Io_revolution = 0.0;
		Europa_revolution += 3.0* revol_i;	if (Europa_revolution >= 360.0) Europa_revolution = 0.0;
		Ganymede_revolution += 5.0* revol_i;	if (Ganymede_revolution >= 360.0) Ganymede_revolution = 0.0;
		Planet_Info[SATURN].revolution += 0.03* revol_i;	if (Planet_Info[SATURN].revolution >= 360.0) Planet_Info[SATURN].revolution = 0.0;
		Titan_revolution += 2.0* revol_i;		if (Titan_revolution >= 360.0) Titan_revolution = 0.0;
		Enceladus_revolution += 28.0* revol_i; if (Enceladus_revolution >= 336.0) Enceladus_revolution = 0.0;
		Planet_Info[URANUS].revolution += 0.01* revol_i;	if (Planet_Info[URANUS].revolution >= 360.0) Planet_Info[URANUS].revolution = 0.0;
		Planet_Info[NEPTUNE].revolution += 0.006* revol_i;	if (Planet_Info[NEPTUNE].revolution >= 360.0)Planet_Info[NEPTUNE].revolution = 0.0;
		Asteroid_incress += int(1 * revol_i);
		Invalidate();
		break;
	case 10:
		textcolor = !textcolor;
		break;
	}
	CDialogEx::OnTimer(nIDEvent);
}
