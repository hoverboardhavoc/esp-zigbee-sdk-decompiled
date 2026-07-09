/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_get_sampled_data_resp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_get_sampled_data_resp_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  void *__ptr;
  uint __nmemb;
  undefined4 uStack_38;
  uint uStack_34;
  undefined4 uStack_30;
  ushort uStack_2c;
  undefined2 uStack_2a;
  uint uStack_28;
  void *pvStack_24;
  
  pvStack_24 = (void *)0x0;
  uStack_38 = *param_1;
  uStack_34 = (uint)*(ushort *)(param_1 + 3);
  uStack_30 = param_1[4];
  _uStack_2c = CONCAT22(*(undefined2 *)((int)param_1 + 0x16),(ushort)*(byte *)(param_1 + 5));
  __nmemb = (uint)*(ushort *)(param_1 + 6);
  uStack_28 = (uint)*(ushort *)(param_1 + 6);
  __ptr = calloc(__nmemb,3);
  if (__nmemb != 0) {
    if (__ptr == (void *)0x0) {
      esp_log(0x11,"ZCL_CMD_COMPAT","no memory");
      return;
    }
    array_copy_u32_to_u24(param_1[7],__nmemb);
    pvStack_24 = __ptr;
  }
  if (param_2 != (code *)0x0) {
    (*param_2)(0x4a,&uStack_38);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 8) = uVar1;
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  return;
}

