/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> zcl_cmd_send_status_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cmd_send_status_handler(byte *param_1)

{
  code *pcVar1;
  undefined1 auStack_50 [44];
  uint uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  pcVar1 = s_cmd_send_status_cb;
  uStack_18 = 0;
  uStack_14 = 0;
  if (s_cmd_send_status_cb != (code *)0x0) {
    uStack_24 = (uint)*param_1;
    uStack_20 = (uint)CONCAT12(param_1[0xc],CONCAT11(param_1[0xd],param_1[1]));
    uStack_1c = (uint)param_1[2];
    memcpy(&uStack_18,param_1 + 4,8);
    memcpy(auStack_50,&uStack_24,0x14);
    (*pcVar1)(auStack_50);
  }
  return;
}

