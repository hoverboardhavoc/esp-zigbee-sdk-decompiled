/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_device_unbind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_device_unbind_req(undefined1 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = (code *)0x0;
  puStack_14 = (undefined4 *)0x0;
  if ((param_1 != (undefined1 *)0x0) &&
     (puStack_14 = (undefined4 *)calloc(1,0xc), puStack_14 != (undefined4 *)0x0)) {
    *puStack_14 = param_2;
    puStack_14[1] = param_3;
    uStack_30 = *(undefined4 *)(param_1 + 2);
    uStack_34 = CONCAT13(param_1[1],CONCAT12(*param_1,*(undefined2 *)(param_1 + 0x18)));
    uStack_2c = CONCAT13(uStack_2c._3_1_,*(undefined3 *)(param_1 + 6));
    if (param_1[0xc] == '\x01') {
      uStack_24 = CONCAT22(uStack_24._2_2_,*(undefined2 *)(param_1 + 0xe));
    }
    else {
      uStack_24 = *(undefined4 *)(param_1 + 0xe);
      uStack_20 = *(undefined4 *)(param_1 + 0x12);
    }
    uStack_28._0_3_ = CONCAT12(param_1[0xc],*(undefined2 *)(param_1 + 10));
    uStack_1c = CONCAT31(uStack_1c._1_3_,param_1[0x16]);
    pcStack_18 = esp_zb_zdo_bind_rsp_wrapper;
    ezb_zdo_unbind_req(&uStack_34);
  }
  return;
}

