#include <QtCore/QCoreApplication>
#include <QDir>

#include "CController.h"
#include "CBaslerController.h"
#include "log4z.h"

using namespace zsummer::log4z;

bool isLogFileExist()
{
	QString qstrAppFilePath = QCoreApplication::instance()->applicationDirPath();
	QString qstrLog = qstrAppFilePath + "\\log";
	QDir dir(qstrLog);
	if (!dir.exists())
	{
		bool ok = dir.mkdir(qstrLog);
		if (!ok)
		{
			LOGI("创建Log文件夹失败！");
			return false;
		}
	}
	else
		LOGI("Log文件夹已存在！");

	ILog4zManager::GetInstance()->Start();
	ILog4zManager::GetInstance()->CreateLogger(LOG4Z_MAIN_LOGGER_NAME, qstrLog.toStdString().c_str(),
		LOG4Z_DEFAULT_LEVEL, LOG4Z_DEFAULT_DISPLAY, LOG4Z_DEFAULT_MONTHDIR, LOG4Z_DEFAULT_LIMITSIZE);
	return true;
}

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	if (!isLogFileExist())
		return -1;

	LOGFMTE("Main ==>> %lld %s", qint64(QThread::currentThreadId()), __FUNCTION__);
	CController* pController = new CController();
	CBaslerController* pBaslerController = new CBaslerController();
	emit pController->sigStart();
	emit pBaslerController->sigStart();

	return a.exec();
}
