#include "CBaslerController.h"
#include "CWorker.h"
#include "TaskFunctions.h"

#include <QDebug>

CBaslerController::CBaslerController(QObject *parent)
{

	CWorker *worker0 = new CWorker();
	worker0->setWorkerPlan(u8"===>>pylon_1");
	worker0->setInterval(6000);
	worker0->addToTaskQueue(gl_queryRegister2_1_station2IsReady);
	worker0->moveTimerToThread(&m_workerThread);
	worker0->moveToThread(&m_workerThread);
	connect(&m_workerThread, &QThread::finished, worker0, &QObject::deleteLater);
	connect(this, &CBaslerController::sigStart, worker0, &CWorker::startWork);
	connect(this, &CBaslerController::sigStop, worker0, &CWorker::stop);
	connect(worker0, &CWorker::sigResultReady, this, &CBaslerController::slotHandleResults);

	CWorker *worker01 = new CWorker();
	worker01->setWorkerPlan(u8"===>>pylon_2");
	worker01->setInterval(100);
	worker01->addToTaskQueue(gl_resetRegister2_0_station2IsReady);
	worker01->moveTimerToThread(&m_workerThread);
	worker01->moveToThread(&m_workerThread);
	connect(this, &CBaslerController::sigStop, worker01, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker01, &QObject::deleteLater);
	connect(worker01, &CWorker::sigResultReady, this, &CBaslerController::slotHandleResults);

	///////////////////////////////////////////////////////////////
	CWorker *worker1 = new CWorker();
	worker1->setWorkerPlan(u8"===>>pylon_3");
	worker1->setInterval(100);
	worker1->addToTaskQueue(gl_areaCamerasGrab);
	worker1->moveTimerToThread(&m_workerThread);
	worker1->moveToThread(&m_workerThread);
	connect(this, &CBaslerController::sigStop, worker1, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker1, &QObject::deleteLater);
	connect(worker1, &CWorker::sigResultReady, this, &CBaslerController::slotHandleResults);

	//////////////////////////////////////////////////////////////////
	CWorker *worker2 = new CWorker();
	worker2->setWorkerPlan(u8"===>>pylon_4");
	worker2->setInterval(200);
	worker2->addToTaskQueue(gl_setRegister3_1_startPLCRotate60);
	worker2->moveTimerToThread(&m_workerThread);
	worker2->moveToThread(&m_workerThread);
	connect(this, &CBaslerController::sigStop, worker2, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker2, &QObject::deleteLater);
	connect(worker2, &CWorker::sigResultReady, this, &CBaslerController::slotHandleResults);

	////////////////////////////////////////////////////////////////////////
	CWorker *worker3 = new CWorker();
	worker3->setWorkerPlan(u8"===>>pylon_5");
	worker3->setInterval(55);
	worker3->addToTaskQueue(gl_queryRegister4_1_PLCRotate60Finished);
	worker3->moveTimerToThread(&m_workerThread);
	worker3->moveToThread(&m_workerThread);
	connect(this, &CBaslerController::sigStop, worker3, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker3, &QObject::deleteLater);
	connect(worker3, &CWorker::sigResultReady, this, &CBaslerController::slotHandleResults);

	//////////////////////////////////////////////////////////////////////////////
	CWorker *worker04 = new CWorker();
	worker04->setWorkerPlan(u8"===>>pylon_6");
	worker04->setInterval(70);
	worker04->addToTaskQueue(gl_setRegister4_0_PLCRotate60Finished);
	worker04->moveTimerToThread(&m_workerThread);
	worker04->moveToThread(&m_workerThread);
	connect(this, &CBaslerController::sigStop, worker04, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker04, &QObject::deleteLater);
	connect(worker04, &CWorker::sigResultReady, this, &CBaslerController::slotHandleResults);

	//////////////////////////////////////////////////////////////////////////////
	CWorker *worker4 = new CWorker();
	worker4->setWorkerPlan(u8"===>>pylon_7");
	worker4->setInterval(10);
	worker4->addToTaskQueue(gl_areaCamerasGrab);
	worker4->moveTimerToThread(&m_workerThread);
	worker4->moveToThread(&m_workerThread);
	connect(this, &CBaslerController::sigStop, worker4, &CWorker::stop);
	connect(&m_workerThread, &QThread::finished, worker4, &QObject::deleteLater);
	connect(worker4, &CWorker::sigResultReady, this, &CBaslerController::slotHandleResults);


	triggerBbyA(worker0, worker01);

	AStopB(worker0, worker2);
	AStopB(worker0, worker3);
	AStopB(worker0, worker04);
	AStopB(worker0, worker4);

	triggerBbyA(worker01, worker1);
	triggerBbyA(worker1, worker2);
	triggerBbyA(worker2, worker3);
	triggerBbyA(worker3, worker04);
	triggerBbyA(worker04, worker4, 5);
	triggerBbyA(worker4, worker2);

	m_workerThread.start();
}

CBaslerController::~CBaslerController()
{
	m_workerThread.quit();
	m_workerThread.wait();
}

void CBaslerController::slotHandleResults(const QString & results)
{
	qDebug() << results;
}

void CBaslerController::triggerBbyA(CWorker* a, CWorker* b,int triggerCount)
{
	connect(a, &CWorker::sigFinishWork, b, &CWorker::startWork/*,Qt::DirectConnection*/);
	b->setTriggerCount(triggerCount);
}

void CBaslerController::AStopB(CWorker* a, CWorker* b)
{
	connect(a, &CWorker::sigStop, b, &CWorker::stop/*,Qt::DirectConnection*/);
}