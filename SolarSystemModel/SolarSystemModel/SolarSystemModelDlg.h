
// SolarSystemModelDlg.h : 헤더 파일
//

#pragma once
#define VENUS			0
#define MERCURY		1
#define  EARTH		2
#define  MARS			3
#define	JUPITER		4
#define	SATURN		5
#define	URANUS		6
#define	NEPTUNE	7
typedef struct Planet_info {
	double dist;
	double radius;
	double revolution;
	bool flag;
	bool explosion;
	bool express;
	bool TF_dist;
}Planet_info;
typedef struct Asteroid_info {
	int side_point;
	int x_start_point, y_start_point;
	double size;
	double pos;
	int start_point_flag;
	int speed_incress;
	int flag;
}Asteroid_info;


// CSolarSystemModelDlg 대화 상자
class CSolarSystemModelDlg : public CDialogEx
{
// 생성입니다.
public:
	CSolarSystemModelDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SOLARSYSTEMMODEL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	double PI;
	double rad;

	int Sun_radius;
	bool Sun_express;

	double Moon_dist;
	double Moon_radius;
	double Moon_revolution;

	double Io_dist;
	double Io_radius;
	double Io_revolution;

	double Europa_dist;
	double Europa_radius;
	double Europa_revolution;

	double Ganymede_dist;
	double Ganymede_radius;
	double Ganymede_revolution;

	double Titan_dist;
	double Titan_radius;
	double Titan_revolution;

	double Enceladus_dist;
	double Enceladus_radius;
	double Enceladus_revolution;

	int side_point;
	int x_start_point, y_start_point;
	int Asteroid_size, Asteroid_x, Asteroid_y;
	int start_point_flag;
	int Asteroid_incress;
	int flag;
	bool textcolor;
	double revol_i;
	bool black_hole;
	double rate_Asteroid;
	int Timer;

	double vx;
	double vy;
	CPoint hp;

	int bh_radius;
	double bh_incress;

	CPoint mp;

	CBitmap m_BackBitmap;
	CBitmap Sun_bitmap, Earth_bitmap, Space_bitmap, Venus_bitmap, Mercury_bitmap, Mars_bitmap, Jupiter_bitmap, Saturn_bitmap, Uranus_bitmap, Neptune_bitmap, Moon_bitmap, Io_bitmap, Europa_bitmap, Ganymede_bitmap, Titan_bitmap, Enceladus_bitmap;
	CBitmap Asteroid_bitmap, L90_Asteroid_bitmap, L180_Asteroid_bitmap, L270_Asteroid_bitmap;
	CBitmap Explosion_bitmap, Saturn_Explosion_bitmap;
	CBitmap Blackhole_bitmap;
	CBitmap SpaceMan_bitmap;
	BITMAP m_Bitmap;

	CPoint wcp;
	BITMAP bmpinfo[8];
	CDC memDC[8];
	Planet_info Planet_Info[8];
	CPoint PlanetPos[8];

	CString SoundPath1, SoundPath2, SoundPath3;
public:
	void DrawBackGround(CDC* dc, CRect rect);
	void CreateSun(CDC* dc, CPoint cp, CRect rect);
	void CreateMoon(CDC* dc, CPoint cp, CRect);
	void CreateIo(CDC* dc, CPoint cp, CRect);
	void CreateEuropa(CDC* dc, CPoint cp, CRect);
	void CreateGanymede(CDC* dc, CPoint cp, CRect);
	void CreateTitan(CDC* dc, CPoint cp, CRect);
	void CreateEnceladus(CDC* dc, CPoint cp, CRect);
	void T_CreateAsteroid(CDC *dc, CRect rect); // 각각 90도 씩 회전 된 소행성
	void L_CreateAsteroid(CDC *dc, CRect rect);
	void R_CreateAsteroid(CDC *dc, CRect rect);
	void B_CreateAsteroid(CDC *dc, CRect rect); 
	void CreateAsteroid(CDC *dc, CRect rect); // 멈춘 상태의 소행성
	void CreatePlanet(CDC *dc, CPoint cp, CRect);
	bool Explosion(CDC *dc, int i); // 소행성 충돌
	void CreateBlackhole(CDC *dc, CPoint cp, CRect rect);
	void SpaceMan(CDC *dc, CPoint cp);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
