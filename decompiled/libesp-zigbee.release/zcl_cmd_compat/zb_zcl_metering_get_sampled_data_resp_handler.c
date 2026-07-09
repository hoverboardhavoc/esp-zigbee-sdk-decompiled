/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_sampled_data_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_sampled_data_resp_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  void *__ptr;
  uint __nmemb;
  undefined2 uStack_28;
  undefined2 uStack_26;
  undefined2 uStack_24;
  undefined1 auStack_22 [2];
  undefined4 uStack_20;
  undefined1 uStack_1c;
  undefined2 uStack_1a;
  ushort uStack_18;
  void *pvStack_14;
  
  memset(auStack_22,0,0x12);
  uStack_26 = param_1[1];
  uStack_18 = param_1[0xc];
  __nmemb = (uint)uStack_18;
  uStack_28 = *param_1;
  uStack_24 = param_1[6];
  uStack_20 = *(undefined4 *)(param_1 + 8);
  uStack_1c = *(undefined1 *)(param_1 + 10);
  uStack_1a = param_1[0xb];
  __ptr = calloc(__nmemb,3);
  if (__nmemb == 0) {
    if (param_2 != (code *)0x0) goto _L0;
  }
  else {
    if (__ptr == (void *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
      return;
    }
    array_copy_u32_to_u24(*(undefined4 *)(param_1 + 0xe));
    pvStack_14 = __ptr;
    if (param_2 == (code *)0x0) goto _L0;
_L0:
    (*param_2)(0x4a,&uStack_28);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0x10) = uVar1;
  }
  if (__ptr == (void *)0x0) {
    return;
  }
_L0:
  free(__ptr);
  return;
}

