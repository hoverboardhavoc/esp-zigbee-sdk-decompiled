/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> zdo_cmd_compat.o -> esp_zb_zdo_match_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zdo_match_cluster(ushort *param_1,undefined4 param_2,undefined4 param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = (code *)0x0;
  puStack_14 = (undefined4 *)0x0;
  if (param_1 == (ushort *)0x0) {
    uVar2 = 0x102;
  }
  else {
    puStack_14 = (undefined4 *)calloc(1,0xc);
    if (puStack_14 == (undefined4 *)0x0) {
      uVar2 = 0x101;
    }
    else {
      *puStack_14 = param_2;
      puStack_14[1] = param_3;
      uVar1 = *param_1;
      *(bool *)(puStack_14 + 2) = 0xfff7 < uVar1;
      *(undefined1 *)((int)puStack_14 + 9) = 0;
      uStack_24 = *(undefined4 *)(param_1 + 1);
      uStack_20 = CONCAT22(uStack_20._2_2_,param_1[3]);
      uStack_1c = *(undefined4 *)(param_1 + 4);
      uStack_28 = CONCAT22(uStack_28._2_2_,uVar1);
      pcStack_18 = esp_zb_zdo_match_desc_rsp_wrapper;
      ezb_zdo_match_desc_req(&uStack_28);
      uVar2 = 0;
    }
  }
  return uVar2;
}

