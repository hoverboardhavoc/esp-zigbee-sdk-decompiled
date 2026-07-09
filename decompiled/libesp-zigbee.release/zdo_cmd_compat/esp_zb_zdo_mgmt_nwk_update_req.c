/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_nwk_update_req(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined2 auStack_38 [2];
  undefined4 uStack_34;
  undefined2 uStack_30;
  undefined1 uStack_2e;
  undefined2 uStack_2c;
  code *pcStack_28;
  undefined4 *puStack_24;
  
  memset(auStack_38,0,0x18);
  if ((param_1 != (undefined4 *)0x0) &&
     (puStack_24 = (undefined4 *)calloc(1,0xc), puStack_24 != (undefined4 *)0x0)) {
    uStack_34 = *param_1;
    *puStack_24 = param_2;
    puStack_24[1] = param_3;
    uStack_30 = *(undefined2 *)(param_1 + 1);
    uStack_2e = ezb_nwk_get_update_id();
    uStack_2c = *(undefined2 *)((int)param_1 + 6);
    auStack_38[0] = *(undefined2 *)(param_1 + 2);
    pcStack_28 = esp_zb_zdo_mgmt_nwk_update_notify_wrapper;
    ezb_zdo_nwk_mgmt_nwk_update_req(auStack_38);
  }
  return;
}

