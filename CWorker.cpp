#include "CWorker.h"
#include "log4z.h"

#include <QDebug>

using namespace zsummer::log4z;

CWorker::CWorker(QObject *parent) :QObject(parent)
, m_pTimer(new QTimer())
, m_triggerCount(-1)
, m_count(-1)
{
	LOGFMTE("------ %lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	m_pTimer->setTimerType(Qt::PreciseTimer);
}

CWorker::~CWorker()
{
	if (nullptr != m_pTimer)
	{
		m_pTimer->stop();
		delete m_pTimer;
		m_pTimer = nullptr;
	}
	m_taskQueue.clear();
}

void CWorker::moveTimerToThread(QThread* thread)
{
	if (m_pTimer)
	{
		m_pTimer->moveToThread(thread);
		connect(m_pTimer, &QTimer::timeout, this, &CWorker::slotTimer, Qt::DirectConnection);
	}
}

void CWorker::startWork()
{
	if (m_pTimer)
	{
		if (0 == m_count)
		{
			;
		}
		else
		{
			QString workerPlan = m_workerPlan + " Start";
			LOGI(workerPlan.toLocal8Bit().data());
			m_pTimer->start();
		}

		if (0 < m_count)
		{
			m_count--;
		}
	}
}

void CWorker::stopWork()
{
	if (m_pTimer)
	{
		m_pTimer->stop();
		//qDebug() << m_workerPlan + "	StopWork";
		QString workerPlan = m_workerPlan + " Stop";
		LOGI(workerPlan.toLocal8Bit().data());
		if (0 != m_count)
		{
			emit sigFinishWork();
		}
		else
			m_count = m_triggerCount;
	}
}

void CWorker::stop()
{
	if (m_pTimer)
	{
		m_pTimer->stop();
		m_count = m_triggerCount;
	}
}

void CWorker::stopNotEndWork()
{
	if (m_pTimer)
	{
		//m_pTimer->stop();
		//qDebug() << m_workerPlan + "	StopNotEndWork";
		QString workerPlan = m_workerPlan + " StopNotEndSelf";
		LOGI(workerPlan.toLocal8Bit().data());
		if (0 != m_count)
		{
			emit sigFinishWork();
		}
		else
			m_count = m_triggerCount;
	}
}

void CWorker::setInterval(int msec)
{
	if (m_pTimer)
		m_pTimer->setInterval(msec);
}

void CWorker::addToTaskQueue(Ptr_FuncTask funDeque)
{
	m_taskQueue.enqueue(funDeque);
}

void CWorker::slotTimer()
{

	for (Ptr_FuncTask task : m_taskQueue)
	{
		if (m_pTimer->isActive())
		{
			task(this);
		}
	}

}