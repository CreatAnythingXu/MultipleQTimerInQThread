#ifndef ZZJH_CCONTROLLER_H
#define ZZJH_CCONTROLLER_H

#include <QThread>
#include <QObject>

class CWorker;

class CController :public QObject
{
	Q_OBJECT
	QThread m_workerThread;
public:
	CController(QObject *parent = Q_NULLPTR);
	~CController();

	public slots:
	void slotHandleResults(const QString &);

signals:
	void sigStart();
	void sigStop();

private:
	void triggerBbyA(CWorker* a, CWorker* b, int triggerCount = -1);
	void CController::AStopB(CWorker* a, CWorker* b);
};
#endif //ZZJH_CCONTROLLER_H
