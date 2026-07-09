/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> convert_to_ezb_specific_cmd_ctrl
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void convert_to_ezb_specific_cmd_ctrl(undefined1 *param_1,void *param_2)

{
  undefined4 uVar1;
  
  memset(param_1,0,0x18);
  uVar1 = get_zcl_send_status_cb_handle();
  *(undefined4 *)(param_1 + 0x10) = uVar1;
  *param_1 = *(undefined1 *)((int)param_2 + 10);
  param_1[10] = *(undefined1 *)((int)param_2 + 8);
  param_1[0xb] = *(undefined1 *)((int)param_2 + 9);
  memcpy(param_1 + 2,param_2,8);
  return;
}

