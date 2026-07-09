/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_profile_resp_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  uint __nmemb;
  undefined2 uStack_20;
  undefined2 uStack_1e;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_17;
  byte bStack_16;
  undefined1 uStack_15;
  void *pvStack_14;
  
  uStack_1e = param_1[1];
  uStack_1c = *(undefined4 *)(param_1 + 6);
  bStack_16 = *(byte *)(param_1 + 0xc);
  __nmemb = (uint)bStack_16;
  uStack_20 = *param_1;
  uStack_18 = (undefined1)*(undefined4 *)(param_1 + 8);
  uStack_15 = 0;
  uStack_17 = (undefined1)*(undefined4 *)(param_1 + 10);
  pvStack_14 = calloc(__nmemb,3);
  if (__nmemb != 0) {
    if (pvStack_14 == (void *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
      return;
    }
    array_copy_u32_to_u24(*(undefined4 *)(param_1 + 0xe));
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(0x44,&uStack_20);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 0x10) = uVar1;
  }
  if (pvStack_14 != (void *)0x0) {
    free(pvStack_14);
  }
  return;
}

