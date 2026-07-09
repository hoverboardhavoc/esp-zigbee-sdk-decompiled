/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_profile_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  void *__ptr;
  undefined4 *puVar2;
  void *pvVar3;
  uint __nmemb;
  undefined2 uStack_3c;
  undefined2 uStack_3a;
  undefined1 auStack_38 [4];
  undefined4 uStack_34;
  byte bStack_30;
  undefined4 uStack_2c;
  byte bStack_28;
  byte bStack_27;
  byte bStack_26;
  void *pvStack_24;
  
  memset(auStack_38,0,0x18);
  uStack_3a = param_1[1];
  uStack_3c = *param_1;
  bStack_30 = *(byte *)(param_1 + 10);
  auStack_38[0] = *(undefined1 *)(param_1 + 6);
  uStack_34 = *(undefined4 *)(param_1 + 8);
  __ptr = calloc((uint)bStack_30,3);
  if (__ptr == (void *)0x0) {
_L0:
    esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
    return;
  }
  pvStack_24 = __ptr;
  if (param_2 != (code *)0x0) {
    (*param_2)(0x43,&uStack_3c);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0xc) = uVar1;
  }
  if (*(char *)(param_1 + 0xc) == '\0') {
    puVar2 = (undefined4 *)calloc(1,0x14);
    *(undefined4 **)(param_1 + 0xe) = puVar2;
    if (puVar2 == (undefined4 *)0x0) goto _L0;
    __nmemb = (uint)bStack_26;
    *(byte *)(puVar2 + 3) = bStack_26;
    if (__nmemb != 0) {
      pvVar3 = calloc(__nmemb,4);
      if (pvVar3 == (void *)0x0) goto _L0;
      array_copy_u24_to_u32(__ptr,__nmemb);
      puVar2[4] = pvVar3;
      *puVar2 = uStack_2c;
      puVar2[1] = (uint)bStack_28;
      puVar2[2] = (uint)bStack_27;
    }
    *(code **)(param_1 + 0x10) = free_memory_for_get_profile;
    *(undefined4 **)(param_1 + 0x12) = puVar2;
  }
  free(__ptr);
  return;
}

