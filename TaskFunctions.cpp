#include "TaskFunctions.h"
#include "CWorker.h"
#include "log4z.h"

#include <QThread>
#include <QDebug>


using namespace std;
using namespace zsummer::log4z;

/**********************************************************
工位一处理步骤
********************************************************/
void gl_queryRegister5_1_station1IsReady(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//寄存器五写0
void gl_resetRegister5_0_station1IsReady(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//线阵相机拍照
void gl_lineCamerasGrab(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//线阵相机拍照
void gl_lineCamerasGrab_isFinisedCallBack(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//拍照完成,寄存器六写1,处理拍照结果
void gl_setRegister6_1_grabFinisedOnSation1(const CWorker* worker)
{
	LOGFMTA("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

/**********************************************************
工位二处理步骤
********************************************************/
//查询工位二拍照信号（查询寄存器二为1）
void gl_queryRegister2_1_station2IsReady(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->sigStop();
	const_cast<CWorker*>(worker)->stopNotEndWork();
}

//寄存器二写0,复位工位二就绪信号
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

//寄存器三写1，工控机发出启动旋转60度信号
void gl_setRegister3_1_startPLCRotate60(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//查询旋转完成信号（寄存器四为1）
void gl_queryRegister4_1_PLCRotate60Finished(const CWorker* worker)
{
	LOGFMTE("%lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	const_cast<CWorker*>(worker)->stopWork();
}

//寄存器四写0，复位旋转完成寄存器
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