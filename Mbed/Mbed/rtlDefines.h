#pragma once
#include "stdafx.h"

typedef struct _DEVICE_OBJECT {
	CSHORT                      Type;
	USHORT                      Size;
	LONG                        ReferenceCount;
	struct _DRIVER_OBJECT  *DriverObject;
	struct _DEVICE_OBJECT  *NextDevice;
	struct _DEVICE_OBJECT  *AttachedDevice;
	struct _IRP  *CurrentIrp;
	PIO_TIMER                   Timer;
	ULONG                       Flags;
	ULONG                       Characteristics;
	__volatile PVPB             Vpb;
	PVOID                       DeviceExtension;
	DEVICE_TYPE                 DeviceType;
	CCHAR                       StackSize;
	union {
		LIST_ENTRY         ListEntry;
		WAIT_CONTEXT_BLOCK Wcb;
	} Queue;
	ULONG                       AlignmentRequirement;
	KDEVICE_QUEUE               DeviceQueue;
	KDPC                        Dpc;
	ULONG                       ActiveThreadCount;
	PSECURITY_DESCRIPTOR        SecurityDescriptor;
	KEVENT                      DeviceLock;
	USHORT                      SectorSize;
	USHORT                      Spare1;
	struct _DEVOBJ_EXTENSION  *  DeviceObjectExtension;
	PVOID                       Reserved;
} DEVICE_OBJECT, *PDEVICE_OBJECT;

NTSTATUS IoCreateDevice(
_In_     PDRIVER_OBJECT  DriverObject,
_In_     ULONG           DeviceExtensionSize,
_In_opt_ PUNICODE_STRING DeviceName,
_In_     DEVICE_TYPE     DeviceType,
_In_     ULONG           DeviceCharacteristics,
_In_     BOOLEAN         Exclusive,
_Out_    PDEVICE_OBJECT  *DeviceObjec,
);