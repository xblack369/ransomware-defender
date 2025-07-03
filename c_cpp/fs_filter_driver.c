#include <ntddk.h>

NTSTATUS FsFilterOperation(PDEVICE_OBJECT DeviceObject, PIRP Irp) {
    PIO_STACK_LOCATION stack = IoGetCurrentIrpStackLocation(Irp);

    if(stack->MajorFunction == IRP_MJ_WRITE) {
        PFILE_OBJECT fileObject = stack->FileObject;
        if(is_sensitive_file(fileObject->FileName)) {
            if(is_encryption_attempt(Irp)) {
                Irp->IoStatus.Status = STATUS_ACCESS_DENIED;
                IoCompleteRequest(Irp, IO_NO_INCREMENT);
                return STATUS_ACCESS_DENIED;
            }
        }
    }

    return FsFilterDispatch(DeviceObject, Irp);
}