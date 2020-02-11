#include "CController.h"
#include "CWorker.h"
#include "TaskFunctions.h"

#include <QDebug>

CController::CController(QObject *parent)
{
#if XXD_TEST
	CWorker *worker0 = new CWorker();
	worker0->setWorkerPlan(u8"+++>>sap_1_查工一拍照信号寄存器读5_1");
	worker0->setInterval(1000);
	worker0->addToTaskQueue(gl_queryRegister5_1_station1IsReady);
	worker0->moveTimerToThread(&m_workerThread);

	worker0->moveToThread(&m_workerThread);
	connect(&m_workerThread, &QThread::finished, worker0, &QObject::deleteLater);
	connect(this, &CController::sigStart, worker0, &CWorker::startWork);
	connect(worker0, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker01 = new CWorker();
	worker01->setWorkerPlan(u8"+++>>sap_2_寄存器写5_0");
	worker01->setInterval(10);
	worker01->addToTaskQueue(gl_resetRegister5_0_station1IsReady);
	worker01->moveTimerToThread(&m_workerThread);

	worker01->moveToThread(&m_workerThread);
	connect(&m_workerThread, &QThread::finished, worker01, &QObject::deleteLater);
	connect(worker01, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker1 = new CWorker();
	worker1->setWorkerPlan(u8"+++>>sap_3_线阵相机拍照");
	worker1->setInterval(10);
	worker1->addToTaskQueue(gl_lineCamerasGrab);
	worker1->moveTimerToThread(&m_workerThread);

	worker1->moveToThread(&m_workerThread);
	connect(&m_workerThread, &QThread::finished, worker1, &QObject::deleteLater);
	connect(worker1, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker2 = new CWorker();
	worker2->setWorkerPlan(u8"+++>>sap_4_线阵拍照数据回调完成");
	worker2->setInterval(100);
	worker2->addToTaskQueue(gl_lineCamerasGrab_isFinisedCallBack);
	worker2->moveTimerToThread(&m_workerThread);
	worker2->moveToThread(&m_workerThread);
	connect(&m_workerThread, &QThread::finished, worker2, &QObject::deleteLater);
	connect(worker2, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker3 = new CWorker();
	worker3->setWorkerPlan(u8"+++>>sap_5_拍照完成寄存器写6_1");
	worker3->setInterval(50);
	worker3->addToTaskQueue(gl_setRegister6_1_grabFinisedOnSation1);
	worker3->moveTimerToThread(&m_workerThread);

	worker3->moveToThread(&m_workerThread);
	connect(&m_workerThread, &QThread::finished, worker3, &QObject::deleteLater);
	connect(worker3, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	triggerBbyA(worker0, worker01);
	triggerBbyA(worker01, worker1);
	triggerBbyA(worker1, worker2);
	triggerBbyA(worker2, worker3);
	triggerBbyA(worker3, worker0);
	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	//CWorker *worker0 = new CWorker();
	//worker0->setWorkerPlan(u8"线阵_拍照");
	//worker0->setInterval(50);
	//worker0->addToTaskQueue(gl_lineCamerasGrab);
	//worker0->moveTimerToThread(&m_workerThread);
	//worker0->moveToThread(&m_workerThread);
	//connect(&m_workerThread, &QThread::finished, worker0, &QObject::deleteLater);
	//connect(this, &CController::sigStart, worker0, &CWorker::startWork);
	//connect(worker0, &CWorker::sigResultReady, this, &CController::slotHandleResults);


	//CWorker *worker1 = new CWorker();
	//worker1->setWorkerPlan(u8"线阵_CallBack");
	//worker1->setInterval(50);
	//worker1->addToTaskQueue(gl_lineCamerasGrab_isFinisedCallBack);
	//worker1->moveTimerToThread(&m_workerThread);
	//worker1->moveToThread(&m_workerThread);
	//connect(&m_workerThread, &QThread::finished, worker1, &QObject::deleteLater);
	//connect(worker1, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	///////////////////////////////////////////////////////////////
	//CWorker *worker2 = new CWorker();
	//worker2->setWorkerPlan(u8"线阵_等待");
	//worker2->setInterval(1000);
	//worker2->addToTaskQueue(gl_line_finished);
	//worker2->moveTimerToThread(&m_workerThread);
	//worker2->moveToThread(&m_workerThread);
	//connect(&m_workerThread, &QThread::finished, worker2, &QObject::deleteLater);
	//connect(worker2, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	//triggerBbyA(worker0, worker1);
	//triggerBbyA(worker1, worker2);
	//triggerBbyA(worker2, worker0);
	////////////////////////////////////////////////////////////////////////////////////////////////////////////
#else
	CWorker *worker0 = new CWorker();
	worker0->setWorkerPlan(u8"+++>>sap_1");//_查工一拍照信号寄存器读5_1
	worker0->setInterval(3000);
	worker0->addToTaskQueue(gl_queryRegister5_1_station1IsReady);
	worker0->moveTimerToThread(&m_workerThread);

	worker0->moveToThread(&m_workerThread);
	connect(&m_workerThread, &QThread::finished, worker0, &QObject::deleteLater);
	connect(this, &CController::sigStart, worker0, &CWorker::startWork);
	connect(this, &CController::sigStop, worker0, &CWorker::stop);
	connect(worker0, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker01 = new CWorker();
	worker01->setWorkerPlan(u8"+++>>sap_2");//_寄存器写5_0
	worker01->setInterval(1000);
	worker01->addToTaskQueue(gl_resetRegister5_0_station1IsReady);
	worker01->moveTimerToThread(&m_workerThread);
	worker01->moveToThread(&m_workerThread);

	connect(this, &CController::sigStop, worker01, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker01, &QObject::deleteLater);
	connect(worker01, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker1 = new CWorker();
	worker1->setWorkerPlan(u8"+++>>sap_3");//_线阵相机拍照
	worker1->setInterval(200);
	worker1->addToTaskQueue(gl_lineCamerasGrab);
	worker1->moveTimerToThread(&m_workerThread);

	worker1->moveToThread(&m_workerThread);
	connect(this, &CController::sigStop, worker1, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker1, &QObject::deleteLater);
	connect(worker1, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker2 = new CWorker();
	worker2->setWorkerPlan(u8"+++>>sap_4");//_线阵拍照数据回调完成
	worker2->setInterval(100);
	worker2->addToTaskQueue(gl_lineCamerasGrab_isFinisedCallBack);
	worker2->moveTimerToThread(&m_workerThread);
	worker2->moveToThread(&m_workerThread);
	connect(this, &CController::sigStop, worker2, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker2, &QObject::deleteLater);
	connect(worker2, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	CWorker *worker3 = new CWorker();
	worker3->setWorkerPlan(u8"+++>>sap_5");//_5_拍照完成寄存器写6_1
	worker3->setInterval(200);
	worker3->addToTaskQueue(gl_setRegister6_1_grabFinisedOnSation1);
	worker3->moveTimerToThread(&m_workerThread);

	worker3->moveToThread(&m_workerThread);
	connect(this, &CController::sigStop, worker3, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker3, &QObject::deleteLater);
	connect(worker3, &CWorker::sigResultReady, this, &CController::slotHandleResults);

	triggerBbyA(worker0, worker01);

	AStopB(worker0, worker01);
	AStopB(worker0, worker1);
	AStopB(worker0, worker2);
	AStopB(worker0, worker3);

	triggerBbyA(worker01, worker1);
	triggerBbyA(worker1, worker2);
	triggerBbyA(worker2, worker3);
	triggerBbyA(worker3, worker0);
#endif

	m_workerThread.start();
}

CController::~CController()
{
	m_workerThread.quit();
	m_workerThread.wait();
}

void CController::slotHandleResults(const QString & results)
{
	qDebug() << results;
}

void CController::triggerBbyA(CWorker* a, CWorker* b, int triggerCount)
{
	connect(a, &CWorker::sigFinishWork, b, &CWorker::startWork);
	b->setTriggerCount(triggerCount);
}

void CController::AStopB(CWorker* a, CWorker* b)
{
	connect(a, &CWorker::sigStop, b, &CWorker::stop/*,Qt::DirectConnection*/);
}