#ifndef ZZJH_CBASLERCONTROLLER_H
#define ZZJH_CBASLERCONTROLLER_H

#include <QThread>
#include <QObject>

class CWorker;

class CBaslerController :public QObject
{
	Q_OBJECT
		QThread m_workerThread;
public:
	CBaslerController(QObject *parent = Q_NULLPTR);
	~CBaslerController();

	public slots:
	void slotHandleResults(const QString &);

signals:
	void sigStart();
	void sigStop();

private:
	void triggerBbyA(CWorker* a, CWorker* b, int triggerCount = -1);
	void AStopB(CWorker* a, CWorker* b);
};
#endif //ZZJH_CBASLERCONTROLLER_H