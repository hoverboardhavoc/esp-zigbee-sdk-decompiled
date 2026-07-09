/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_get_profile_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_profile_resp_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  uint __nmemb;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  void *pvStack_24;
  
  pvStack_24 = (void *)0x0;
  local_30 = *param_1;
  uStack_2c = param_1[3];
  __nmemb = (uint)*(byte *)(param_1 + 6);
  uStack_28 = (uint)CONCAT12(*(byte *)(param_1 + 6),CONCAT11((char)param_1[5],(char)param_1[4]));
  pvStack_24 = calloc(__nmemb,3);
  if (__nmemb != 0) {
    if (pvStack_24 == (void *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
      return;
    }
    array_copy_u32_to_u24(param_1[7],__nmemb);
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(0x44,&local_30);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 8) = uVar1;
  }
  if (pvStack_24 != (void *)0x0) {
    free(pvStack_24);
  }
  return;
}

