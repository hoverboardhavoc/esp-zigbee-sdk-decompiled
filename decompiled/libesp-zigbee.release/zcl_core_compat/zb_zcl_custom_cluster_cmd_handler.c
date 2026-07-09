/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_core_compat.o -> zb_zcl_custom_cluster_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zb_zcl_custom_cluster_cmd_handler(undefined1 *param_1,undefined4 param_2,undefined2 param_3)

{
  byte bVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_68 [10];
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [2];
  byte bStack_46;
  undefined2 uStack_44;
  undefined2 uStack_42;
  undefined1 uStack_40;
  undefined1 auStack_3c [10];
  undefined2 uStack_32;
  undefined2 uStack_30;
  undefined2 uStack_2e;
  undefined1 uStack_2c;
  byte bStack_2b;
  undefined1 uStack_2a;
  undefined2 uStack_28;
  undefined4 uStack_24;
  
  pcVar2 = s_core_action;
  uVar4 = 0x81;
  if (s_core_action != (code *)0x0) {
    memset(auStack_48,0,0x24);
    uStack_40 = *param_1;
    memcpy(auStack_3c,param_1 + 2,8);
    uStack_30 = *(undefined2 *)(param_1 + 0x16);
    uStack_2e = *(undefined2 *)(param_1 + 0x18);
    uStack_32 = *(undefined2 *)(param_1 + 0x14);
    uStack_44 = *(undefined2 *)(param_1 + 0x1c);
    bStack_46 = param_1[0x1a];
    uStack_42 = *(undefined2 *)(param_1 + 0x1e);
    uStack_2c = param_1[0x20];
    bStack_2b = bStack_46 >> 3 & 1;
    uStack_2a = (bStack_46 & 3) == 0;
    uStack_28 = param_3;
    uStack_24 = param_2;
    iVar3 = (*pcVar2)(0x61,auStack_48);
    uVar4 = 0;
    if ((((iVar3 != 0) && (uVar4 = 0x89, iVar3 != 0x101)) && (uVar4 = 0x87, iVar3 != 0x102)) &&
       ((uVar4 = 0x8b, iVar3 != 0x105 && (uVar4 = 0x94, iVar3 != 0x107)))) {
      uVar4 = 1;
    }
    bVar1 = param_1[0x1a];
    if ((bVar1 & 0x10) == 0) {
      uStack_58 = 0;
      uStack_54 = 0;
      uStack_50 = 0;
      uStack_4c = 0;
      memcpy(auStack_68,param_1,10);
      uStack_5c = *(undefined2 *)(param_1 + 0x16);
      uStack_5e = *(undefined2 *)(param_1 + 0x14);
      uStack_5a = *(undefined2 *)(param_1 + 0x1c);
      uStack_58 = CONCAT31(uStack_58._1_3_,
                           (byte)((bVar1 >> 3 & 1 ^ 1) << 1) | bVar1 >> 2 & 1 | 4 |
                           (byte)uStack_58 & 0xf8);
      ezb_zcl_default_rsp_cmd_req(auStack_68);
    }
  }
  return uVar4;
}

