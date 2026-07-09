/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zdo_cmd_compat.o -> esp_zb_zdo_match_cluster
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_zdo_match_cluster(ushort *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  ushort auStack_28 [2];
  ushort uStack_24;
  ushort uStack_22;
  ushort uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 *puStack_14;
  
  memset(auStack_28,0,0x18);
  uVar1 = 0x102;
  if (param_1 != (ushort *)0x0) {
    puStack_14 = (undefined4 *)calloc(1,0xc);
    uVar1 = 0x101;
    if (puStack_14 != (undefined4 *)0x0) {
      auStack_28[0] = *param_1;
      *(bool *)(puStack_14 + 2) = 0xfff7 < auStack_28[0];
      uStack_22 = param_1[2];
      uStack_24 = param_1[1];
      *puStack_14 = param_2;
      uStack_20 = param_1[3];
      puStack_14[1] = param_3;
      *(undefined1 *)((int)puStack_14 + 9) = 0;
      uStack_1c = *(undefined4 *)(param_1 + 4);
      uStack_18 = 0x10000;
      ezb_zdo_match_desc_req(auStack_28);
      uVar1 = 0;
    }
  }
  return uVar1;
}

