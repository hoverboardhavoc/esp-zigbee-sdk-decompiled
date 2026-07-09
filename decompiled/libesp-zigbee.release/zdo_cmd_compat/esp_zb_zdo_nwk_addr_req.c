/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_nwk_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_zb_zdo_nwk_addr_req(undefined2 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  code *pcStack_28;
  undefined4 *puStack_24;
  
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0;
  pcStack_28 = (code *)0x0;
  puStack_24 = (undefined4 *)0x0;
  if ((param_1 != (undefined2 *)0x0) &&
     (puVar1 = (undefined4 *)calloc(1,0xc), puVar1 != (undefined4 *)0x0)) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    memcpy((void *)((int)&uStack_34 + 2),param_1 + 1,8);
    uStack_2c = CONCAT22(param_1[5],(undefined2)uStack_2c);
    uStack_34 = CONCAT22(uStack_34._2_2_,*param_1);
    pcStack_28 = esp_zb_zdo_nwk_addr_rsp_wrapper;
    puStack_24 = puVar1;
    ezb_zdo_nwk_addr_req(&uStack_34);
  }
  return;
}

