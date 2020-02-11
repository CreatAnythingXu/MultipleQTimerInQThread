#include "TaskFunctions.h"
#include "CWorker.h"
#include "log4z.h"

#include <QThread>
#include <QDebug>


using namespace std;
using namespace zsummer::log4z;

/**********************************************************
��λһ������
********************************************************/
void gl_queryRegister5_1_station1IsReady(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//�Ĵ�����д0
void gl_resetRegister5_0_station1IsReady(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//�����������
void gl_lineCamerasGrab(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//�����������
void gl_lineCamerasGrab_isFinisedCallBack(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//�������,�Ĵ�����д1,�������ս��
void gl_setRegister6_1_grabFinisedOnSation1(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

/**********************************************************
��λ��������
********************************************************/
//��ѯ��λ�������źţ���ѯ�Ĵ�����Ϊ1��
void gl_queryRegister2_1_station2IsReady(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->sigStop();
	const_cast<CWorker*>(worker)->stopNotEndWork();
}

//�Ĵ�����д0,��λ��λ�������ź�
void gl_resetRegister2_0_station2IsReady(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

void gl_areaCamerasGrab(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

void gl_areaCamerasGrab_oneGrab(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//�Ĵ�����д1�����ػ�����������ת60���ź�
void gl_setRegister3_1_startPLCRotate60(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//��ѯ��ת����źţ��Ĵ�����Ϊ1��
void gl_queryRegister4_1_PLCRotate60Finished(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//�Ĵ�����д0����λ��ת��ɼĴ���
void gl_setRegister4_0_PLCRotate60Finished(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

void gl_line_finished(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

void gl_area_finished(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

void gl_queryOrderNum()
{

}