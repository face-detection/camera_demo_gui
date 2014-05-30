
// CameraDemoDlg.h : ͷ�ļ�
//
#pragma once


struct frame_container{
	CRect m_VideoRect;
	HDC m_hVideoDC;
	CvvImage m_CvvImage;
};
#define FRAME_MAX		3

// CCameraDemoDlg �Ի���
class CCameraDemoDlg : public CDialogEx
{
// ����
public:
	CCameraDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_CAMERADEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
	virtual void OnOK() {}
	virtual void OnCancel() {}

// ʵ��
protected:
	HICON m_hIcon;
	// for playing main video:
	VideoCapture m_VideoCap;
	CRect m_VideoRect;
	HDC m_hVideoDC;
	UINT_PTR m_nTimer;
	// additional function:
	CString m_cstrVideoPath, m_cstrSavePath;
	BOOL m_bSaveVideo, m_bCamera;
	struct frame_container m_Frames[FRAME_MAX];
	int m_nFrameIndex;
	CvVideoWriter* m_pVideoWriter;
	// face detection helper:
	CascadeClassifier m_FaceFrontalCascade;
	CascadeClassifier m_FaceProfileCascade;
	Mat m_ImageFace[FRAME_MAX];
	int m_ImageFaceNumber;
	// initial routines:
	void Init();

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonPlay();
	afx_msg void OnClose();
	afx_msg void OnBnClickedRadioCamera();
	afx_msg void OnBnClickedRadioFile();
	afx_msg void OnBnClickedButtonCapture();
	afx_msg void OnBnClickedCheckSave();
};