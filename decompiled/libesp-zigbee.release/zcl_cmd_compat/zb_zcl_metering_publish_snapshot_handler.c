/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_publish_snapshot_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_publish_snapshot_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  void *__ptr;
  uint uVar2;
  size_t __nmemb;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  void *pvVar6;
  undefined2 uStack_58;
  undefined2 uStack_56;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined2 uStack_4c;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined4 uStack_48;
  byte bStack_44;
  undefined1 auStack_43 [6];
  byte bStack_3d;
  undefined4 uStack_3c;
  byte bStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  undefined1 uStack_31;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  undefined1 uStack_2e;
  undefined1 uStack_2d;
  byte bStack_2c;
  undefined1 uStack_2b;
  undefined1 uStack_2a;
  undefined1 uStack_29;
  undefined1 uStack_28;
  byte bStack_27;
  undefined2 uStack_26;
  undefined2 uStack_24;
  
  memset(&uStack_49,0,0x29);
  uStack_56 = param_1[1];
  uStack_58 = *param_1;
  uStack_54 = *(undefined4 *)(param_1 + 8);
  uStack_4a = *(undefined1 *)(param_1 + 0xd);
  uStack_50 = *(undefined4 *)(param_1 + 10);
  bStack_44 = *(byte *)(param_1 + 0x10);
  uStack_48 = *(undefined4 *)(param_1 + 0xe);
  uStack_4c = param_1[0xc];
  if (bStack_44 == 4) {
_L0:
    array_copy_u64_to_u48(auStack_43,param_1 + 0x14,1);
    bStack_3d = *(byte *)(param_1 + 0x18);
    uVar2 = (uint)bStack_3d;
    if ((uVar2 == 0) || (iVar4 = *(int *)(param_1 + 0x1a), iVar4 == 0)) {
_L0:
      if (param_2 == (code *)0x0) {
        return;
      }
      pvVar5 = (void *)0x0;
      __ptr = (void *)0x0;
_L0:
      (*param_2)(0x48,&uStack_58);
      uVar1 = esp_err_to_zcl_status();
      *(undefined1 *)(param_1 + 0x28) = uVar1;
      goto _L0;
    }
    __ptr = calloc(uVar2,6);
    if (__ptr == (void *)0x0) goto _L0;
    array_copy_u64_to_u48(iVar4,uVar2);
    uStack_3c = __ptr;
_L0:
    pvVar5 = (void *)0x0;
    if (param_2 != (code *)0x0) goto _L0;
  }
  else {
    if (bStack_44 < 5) {
      if ((bStack_44 != 2) && (bStack_44 != 3)) {
        array_copy_u64_to_u48(auStack_43,1);
        bStack_3d = (byte)*(undefined4 *)(param_1 + 0x18);
        uStack_3c._0_3_ = (undefined3)((uint)*(undefined4 *)(param_1 + 0x18) >> 8);
        uVar3 = *(undefined4 *)(param_1 + 0x1a);
        uStack_3c = (void *)CONCAT13((char)uVar3,(undefined3)uStack_3c);
        bStack_38 = (byte)((uint)uVar3 >> 8);
        uStack_37 = (undefined1)((uint)uVar3 >> 0x10);
        uStack_36 = (undefined1)((uint)uVar3 >> 0x18);
        uVar3 = *(undefined4 *)(param_1 + 0x1c);
        uStack_35 = (undefined1)uVar3;
        uStack_34 = (undefined1)((uint)uVar3 >> 8);
        uStack_33 = (undefined1)((uint)uVar3 >> 0x10);
        uStack_32 = (undefined1)((uint)uVar3 >> 0x18);
        uVar3 = *(undefined4 *)(param_1 + 0x1e);
        uStack_31 = (undefined1)uVar3;
        uStack_30 = (undefined1)((uint)uVar3 >> 8);
        uStack_2f = (undefined1)((uint)uVar3 >> 0x10);
        uStack_2e = (undefined1)((uint)uVar3 >> 0x18);
        uStack_2d = *(undefined1 *)(param_1 + 0x20);
        bStack_2c = *(byte *)((int)param_1 + 0x41);
        uVar2 = (uint)bStack_2c;
        if ((uVar2 == 0) || (iVar4 = *(int *)(param_1 + 0x22), iVar4 == 0)) goto _L0;
        __ptr = calloc(uVar2,6);
        if (__ptr == (void *)0x0) goto _L0;
        array_copy_u64_to_u48(iVar4,uVar2);
        uStack_2a = (undefined1)((uint)__ptr >> 8);
        uStack_29 = (undefined1)((uint)__ptr >> 0x10);
        uStack_2b = SUB41(__ptr,0);
        uStack_28 = (undefined1)((uint)__ptr >> 0x18);
        goto _L0;
      }
      array_copy_u64_to_u48(auStack_43,param_1 + 0x14,1);
      bStack_3d = (byte)*(undefined4 *)(param_1 + 0x18);
      uStack_3c._0_3_ = (undefined3)((uint)*(undefined4 *)(param_1 + 0x18) >> 8);
      uVar3 = *(undefined4 *)(param_1 + 0x1a);
      uStack_3c = (void *)CONCAT13((char)uVar3,(undefined3)uStack_3c);
      bStack_38 = (byte)((uint)uVar3 >> 8);
      uStack_37 = (undefined1)((uint)uVar3 >> 0x10);
      uStack_36 = (undefined1)((uint)uVar3 >> 0x18);
      uVar3 = *(undefined4 *)(param_1 + 0x1c);
      uStack_35 = (undefined1)uVar3;
      uStack_34 = (undefined1)((uint)uVar3 >> 8);
      uStack_33 = (undefined1)((uint)uVar3 >> 0x10);
      uStack_32 = (undefined1)((uint)uVar3 >> 0x18);
      uVar3 = *(undefined4 *)(param_1 + 0x1e);
      uStack_31 = (undefined1)uVar3;
      uStack_30 = (undefined1)((uint)uVar3 >> 8);
      uStack_2f = (undefined1)((uint)uVar3 >> 0x10);
      uStack_2e = (undefined1)((uint)uVar3 >> 0x18);
      uStack_2d = *(undefined1 *)(param_1 + 0x20);
      bStack_2c = *(byte *)((int)param_1 + 0x41);
      uVar2 = (uint)bStack_2c;
      if (uVar2 == 0) {
        __ptr = (void *)0x0;
      }
      else {
        pvVar5 = *(void **)(param_1 + 0x22);
        __ptr = pvVar5;
        if (pvVar5 != (void *)0x0) {
          __ptr = calloc(uVar2,6);
          if (__ptr == (void *)0x0) goto _L0;
          array_copy_u64_to_u48(pvVar5,uVar2);
          uStack_2a = (undefined1)((uint)__ptr >> 8);
          uStack_29 = (undefined1)((uint)__ptr >> 0x10);
          uStack_2b = SUB41(__ptr,0);
          uStack_28 = (undefined1)((uint)__ptr >> 0x18);
        }
      }
      bStack_27 = *(byte *)(param_1 + 0x24);
      uVar2 = (uint)bStack_27;
      if (uVar2 == 0) goto _L0;
      pvVar6 = *(void **)(param_1 + 0x26);
      pvVar5 = pvVar6;
      if (pvVar6 != (void *)0x0) {
        pvVar5 = calloc(uVar2,6);
        if (pvVar5 == (void *)0x0) goto _L0;
        array_copy_u64_to_u48(pvVar6,uVar2);
        uStack_26 = SUB42(pvVar5,0);
        uStack_24 = (undefined2)((uint)pvVar5 >> 0x10);
      }
    }
    else {
      if (bStack_44 == 6) {
        array_copy_u64_to_u48(auStack_43,param_1 + 0x14,1);
        bStack_3d = *(byte *)(param_1 + 0x18);
        __nmemb = (size_t)bStack_3d;
        if (__nmemb != 0) {
          pvVar5 = *(void **)(param_1 + 0x1a);
          goto joined_r0x00013332;
        }
_L0:
        __ptr = (void *)0x0;
      }
      else {
        if (bStack_44 != 7) {
          if (bStack_44 != 5) {
            *(undefined1 *)(param_1 + 0x28) = 0x87;
            return;
          }
          goto _L0;
        }
        array_copy_u64_to_u48(auStack_43,param_1 + 0x14,1);
        bStack_3d = *(byte *)(param_1 + 0x18);
        __nmemb = (size_t)bStack_3d;
        if (__nmemb == 0) goto _L0;
        pvVar5 = *(void **)(param_1 + 0x1a);
joined_r0x00013332:
        __ptr = pvVar5;
        if (pvVar5 != (void *)0x0) {
          __ptr = calloc(__nmemb,6);
          if (__ptr == (void *)0x0) goto _L0;
          array_copy_u64_to_u48(pvVar5,__nmemb);
          uStack_3c = __ptr;
        }
      }
      bStack_38 = *(byte *)(param_1 + 0x1c);
      uVar2 = (uint)bStack_38;
      if (uVar2 == 0) {
_L0:
        pvVar5 = (void *)0x0;
      }
      else {
        pvVar6 = *(void **)(param_1 + 0x1e);
        pvVar5 = pvVar6;
        if (pvVar6 != (void *)0x0) {
          pvVar5 = calloc(uVar2,6);
          if (pvVar5 == (void *)0x0) {
_L0:
            esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
            return;
          }
          array_copy_u64_to_u48(pvVar6,uVar2);
          uStack_36 = (undefined1)((uint)pvVar5 >> 8);
          uStack_35 = (undefined1)((uint)pvVar5 >> 0x10);
          uStack_37 = SUB41(pvVar5,0);
          uStack_34 = (undefined1)((uint)pvVar5 >> 0x18);
        }
      }
    }
    if (param_2 != (code *)0x0) goto _L0;
_L0:
    if (__ptr == (void *)0x0) goto _L0;
  }
  free(__ptr);
_L0:
  if (pvVar5 == (void *)0x0) {
    return;
  }
  free(pvVar5);
  return;
}

