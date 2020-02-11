#ifndef ZZJH_THREAD_CWORKER_H
#define ZZJH_THREAD_CWORKER_H
#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QThread>

class CWorker :public QObject
{
	Q_OBJECT
public:
	CWorker(QObject *parent = Q_NULLPTR);
	~CWorker();
	typedef void(*Ptr_FuncTask)(const CWorker* worker);
	
	void setWorkerPlan(const QString& plan) { m_workerPlan = plan; }
	void setInterval(int msec);
	void moveTimerToThread(QThread* thread);
	// 设置回调函数的函数
	void addToTaskQueue(Ptr_FuncTask ptrFunc);

	void setTriggerCount(int triggerCount) {m_triggerCount = triggerCount; m_count = m_triggerCount;}
signals:
	void sigFinishWork();
	void sigResultReady(const QString&);
	void sigStop();

public slots:
	void slotTimer();
	void startWork();
	void stopWork();
	void stopNotEndWork();
	void stop();

protected:

private:
	QQueue<Ptr_FuncTask> m_taskQueue;
	QTimer* m_pTimer;
	QString m_workerPlan;
	int		m_triggerCount;
	int		m_count;
};
#endif  //ZZJH_THREAD_CWORKER_H