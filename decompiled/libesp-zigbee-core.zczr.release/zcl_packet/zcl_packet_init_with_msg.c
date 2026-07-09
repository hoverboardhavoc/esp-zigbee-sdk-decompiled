/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_init_with_msg
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zcl_packet_init_with_msg(undefined1 *param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 != (undefined1 *)0x0) {
    uVar4 = 0x87;
    if (param_2 != (undefined2 *)0x0) {
      *(undefined4 *)(param_1 + 0x24) = *(undefined4 *)(param_2 + 8);
      iVar3 = zcl_packet_load_header();
      if (iVar3 == 0) {
        param_1[0x14] = *(undefined1 *)(param_2 + 3);
        param_1[0x15] = *(undefined1 *)((int)param_2 + 7);
        *(undefined2 *)(param_1 + 0x16) = param_2[4];
        *(undefined2 *)(param_1 + 0x18) = param_2[5];
        *param_1 = 2;
        uVar1 = *param_2;
        param_1[10] = 2;
        uVar2 = param_2[1];
        *(undefined2 *)(param_1 + 2) = uVar1;
        *(undefined2 *)(param_1 + 0xc) = uVar2;
        param_1[0x1f] = *(undefined1 *)((int)param_2 + 0xd);
        uVar4 = 0;
      }
      else {
        uVar4 = 0x80;
      }
    }
    return uVar4;
  }
  return 0x87;
}

