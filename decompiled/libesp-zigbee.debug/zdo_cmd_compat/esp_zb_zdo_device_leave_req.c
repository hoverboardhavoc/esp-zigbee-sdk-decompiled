/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_device_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_leave_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  uint uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = (code *)0x0;
  puStack_14 = (undefined4 *)0x0;
  if ((param_1 != (undefined2 *)0x0) &&
     (puStack_14 = (undefined4 *)calloc(1,0xc), puStack_14 != (undefined4 *)0x0)) {
    *puStack_14 = param_2;
    puStack_14[1] = param_3;
    uStack_20 = *(undefined4 *)(param_1 + 1);
    uStack_1c = CONCAT13((char)(*(uint *)(param_1 + 4) >> 0x17),
                         CONCAT12((char)(*(uint *)(param_1 + 4) >> 0x16),param_1[3])) & 0x101ffff;
    uStack_24 = CONCAT22(*param_1,param_1[4]);
    pcStack_18 = esp_zb_zdo_leave_rsp_wrapper;
    ezb_zdo_nwk_mgmt_leave_req(&uStack_24);
  }
  return;
}

