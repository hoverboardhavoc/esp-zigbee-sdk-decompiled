/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_binding_table_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_binding_table_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  uStack_1c = 0;
  pcStack_18 = (code *)0x0;
  puStack_14 = (undefined4 *)0x0;
  if ((param_1 != (undefined1 *)0x0) &&
     (puStack_14 = (undefined4 *)calloc(1,0xc), puStack_14 != (undefined4 *)0x0)) {
    uVar1 = *param_1;
    *puStack_14 = param_2;
    puStack_14[1] = param_3;
    uStack_1c = CONCAT22(CONCAT11(uStack_1c._3_1_,uVar1),*(undefined2 *)(param_1 + 2));
    pcStack_18 = esp_zb_zdo_binding_table_rsp_wrapper;
    ezb_zdo_nwk_mgmt_bind_req(&uStack_1c);
  }
  return;
}

