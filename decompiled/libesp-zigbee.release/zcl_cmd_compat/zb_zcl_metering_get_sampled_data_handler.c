/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_sampled_data_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_sampled_data_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  void *__ptr;
  undefined2 *puVar2;
  void *pvVar3;
  uint __nmemb;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined2 uStack_40;
  undefined1 auStack_3e [2];
  undefined4 uStack_3c;
  undefined1 uStack_38;
  ushort uStack_36;
  undefined2 uStack_34;
  undefined4 uStack_30;
  undefined1 uStack_2c;
  undefined2 uStack_2a;
  ushort uStack_28;
  void *pvStack_24;
  
  memset(auStack_3e,0,0x1e);
  uStack_42 = param_1[1];
  uStack_44 = *param_1;
  uStack_36 = param_1[0xb];
  uStack_40 = param_1[6];
  uStack_3c = *(undefined4 *)(param_1 + 8);
  uStack_38 = *(undefined1 *)(param_1 + 10);
  __ptr = calloc((uint)uStack_36,3);
  if (__ptr == (void *)0x0) {
_L0:
    esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
    return;
  }
  pvStack_24 = __ptr;
  if (param_2 != (code *)0x0) {
    (*param_2)(0x49,&uStack_44);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0xc) = uVar1;
  }
  if (*(char *)(param_1 + 0xc) == '\0') {
    puVar2 = (undefined2 *)calloc(1,0x14);
    *(undefined2 **)(param_1 + 0xe) = puVar2;
    if (puVar2 == (undefined2 *)0x0) goto _L0;
    __nmemb = (uint)uStack_28;
    puVar2[6] = uStack_28;
    if (__nmemb != 0) {
      pvVar3 = calloc(__nmemb,4);
      if (pvVar3 == (void *)0x0) goto _L0;
      array_copy_u24_to_u32(__ptr,__nmemb);
      *(code **)(param_1 + 0x10) = free_memory_for_get_sampled_data;
      *(undefined2 **)(param_1 + 0x12) = puVar2;
      *(void **)(puVar2 + 8) = pvVar3;
      *puVar2 = uStack_34;
      *(undefined4 *)(puVar2 + 2) = uStack_30;
      *(undefined1 *)(puVar2 + 4) = uStack_2c;
      puVar2[5] = uStack_2a;
    }
  }
  free(__ptr);
  return;
}

