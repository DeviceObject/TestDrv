#ifndef __TEST_DRV_H__
#define __TEST_DRV_H__

#include <ntifs.h>
#include <ntddk.h>

typedef enum _KAPC_ENVIRONMENT {
	OriginalApcEnvironment,
	AttachedApcEnvironment,
	CurrentApcEnvironment,
	InsertApcEnvironment
} KAPC_ENVIRONMENT;

VOID KeInitializeApc(__out PRKAPC Apc,
                     __in PRKTHREAD Thread,
                     __in KAPC_ENVIRONMENT Environment,
                     __in PKKERNEL_ROUTINE KernelRoutine,
                     __in_opt PKRUNDOWN_ROUTINE RundownRoutine,
                     __in_opt PKNORMAL_ROUTINE NormalRoutine,
                     __in_opt KPROCESSOR_MODE ProcessorMode,
                     __in_opt PVOID NormalContext);
BOOLEAN KeInsertQueueApc(__inout PRKAPC Apc,
                         __in_opt PVOID SystemArgument1,
                         __in_opt PVOID SystemArgument2,
                         __in KPRIORITY Increment);
UCHAR *PsGetProcessImageFileName(IN PEPROCESS Process);

VOID InjectNotifyRoutine(PUNICODE_STRING FullImageName,HANDLE ProcessId,PIMAGE_INFO ImageInfo);
//////////////////////////////////////////////////////////////////////////
#define WATCHDOG_INTERNAL			3  //√Î
#define TERMINATE_PROCESS_TIMEOUT	20  //√Î
#define RUN_TARGET_INERVAL			72  //–° ±
#define WAIT_ONE_MINUTE				60
//////////////////////////////////////////////////////////////////////////

#define DELAY_ONE_MICROSECOND (-10)
#define DELAY_ONE_MILLISECOND (DELAY_ONE_MICROSECOND * 1000)
#define DELAY_ONE_SECOND      (DELAY_ONE_MILLISECOND * 1000)
#endif