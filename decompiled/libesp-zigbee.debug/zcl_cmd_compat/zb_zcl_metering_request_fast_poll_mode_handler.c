/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zcl_cmd_compat.o -> zb_zcl_metering_request_fast_poll_mode_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zcl_metering_request_fast_poll_mode_handler(undefined4 *param_1,code *param_2)

{
  undefined1 uVar1;
  undefined4 local_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_18 = 0;
  uStack_14 = 0;
  local_20 = *param_1;
  uStack_1c = (uint)*(ushort *)(param_1 + 3);
  if (param_2 != (code *)0x0) {
    (*param_2)(0x45,&local_20,param_2);
    uVar1 = esp_err_to_zcl_status();
    *(undefined1 *)(param_1 + 4) = uVar1;
  }
  if (*(char *)(param_1 + 4) == '\0') {
    *(undefined1 *)(param_1 + 5) = (undefined1)uStack_18;
    *(undefined1 *)((int)param_1 + 0x15) = uStack_18._1_1_;
    *(undefined1 *)((int)param_1 + 0x16) = uStack_18._2_1_;
    *(undefined1 *)((int)param_1 + 0x17) = uStack_18._3_1_;
    *(undefined1 *)(param_1 + 6) = (undefined1)uStack_14;
    *(undefined1 *)((int)param_1 + 0x19) = uStack_14._1_1_;
    *(undefined1 *)((int)param_1 + 0x1a) = uStack_14._2_1_;
    *(undefined1 *)((int)param_1 + 0x1b) = uStack_14._3_1_;
  }
  return;
}

