/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zb_zcl_metering_request_fast_poll_mode_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_request_fast_poll_mode_handler(undefined2 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined2 local_20;
  undefined2 uStack_1e;
  undefined2 uStack_1c;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  undefined2 uStack_14;
  undefined2 uStack_12;
  
  uStack_1e = param_1[1];
  local_20 = *param_1;
  uStack_1c = param_1[6];
  uStack_1a = 0;
  uStack_18 = 0;
  uStack_16 = 0;
  uStack_14 = 0;
  uStack_12 = 0;
  if (param_2 != (code *)0x0) {
    (*param_2)(0x45,&local_20,param_2);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 8) = uVar1;
  }
  if (*(char *)(param_1 + 8) == '\0') {
    memcpy(param_1 + 10,&uStack_18,8);
  }
  return;
}

