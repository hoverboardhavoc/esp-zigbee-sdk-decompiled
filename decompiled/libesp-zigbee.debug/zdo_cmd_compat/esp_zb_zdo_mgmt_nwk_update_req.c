/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_mgmt_nwk_update_req(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  code *pcStack_28;
  undefined4 *puStack_24;
  
  uStack_38 = 0;
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  pcStack_28 = (code *)0x0;
  puStack_24 = (undefined4 *)0x0;
  if ((param_1 != (undefined4 *)0x0) &&
     (puVar2 = (undefined4 *)calloc(1,0xc), puVar2 != (undefined4 *)0x0)) {
    *puVar2 = param_2;
    puVar2[1] = param_3;
    uStack_34 = *param_1;
    uStack_30 = CONCAT22(uStack_30._2_2_,*(undefined2 *)(param_1 + 1));
    uVar1 = ezb_nwk_get_update_id();
    uStack_30._0_3_ = CONCAT12(uVar1,(undefined2)uStack_30);
    uStack_2c = CONCAT22(uStack_2c._2_2_,*(undefined2 *)((int)param_1 + 6));
    uStack_38 = CONCAT22(uStack_38._2_2_,*(undefined2 *)(param_1 + 2));
    pcStack_28 = esp_zb_zdo_mgmt_nwk_update_notify_wrapper;
    puStack_24 = puVar2;
    ezb_zdo_nwk_mgmt_nwk_update_req(&uStack_38);
  }
  return;
}

