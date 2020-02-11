#ifndef ZZJH_TASKFUNCTIONS_H
#define ZZJH_TASKFUNCTIONS_H

#include <string>

class CWorker;

/**********************************************************
工位一处理步骤
********************************************************/
void gl_queryRegister5_1_station1IsReady(const CWorker* worker);
void gl_resetRegister5_0_station1IsReady(const CWorker* worker);
void gl_lineCamerasGrab(const CWorker* worker);
void gl_lineCamerasGrab_isFinisedCallBack(const CWorker* worker);
void gl_setRegister6_1_grabFinisedOnSation1(const CWorker* worker);

/**********************************************************
工位二处理步骤
********************************************************/
void gl_queryRegister2_1_station2IsReady(const CWorker* worker);
void gl_resetRegister2_0_station2IsReady(const CWorker* worker);
void gl_areaCamerasGrab(const CWorker* worker);
void gl_areaCamerasGrab_oneGrab(const CWorker* worker);
void gl_setRegister3_1_startPLCRotate60(const CWorker* worker);
void gl_queryRegister4_1_PLCRotate60Finished(const CWorker* worker);
void gl_setRegister4_0_PLCRotate60Finished(const CWorker* worker);

#endif //ZZJH_TASKFUNCTIONS_H
