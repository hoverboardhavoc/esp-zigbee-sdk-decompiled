/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_init_with_intrp_ind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_packet_init_with_intrp_ind(undefined2 *param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  
  if (param_1 == (undefined2 *)0x0) {
    iVar5 = 0x87;
  }
  else if (param_2 == 0) {
    iVar5 = 0x87;
  }
  else {
    *(undefined4 *)(param_1 + 0x12) = *(undefined4 *)(param_2 + 0x20);
    iVar5 = zcl_packet_load_header();
    if (iVar5 == 0) {
      *(undefined1 *)(param_1 + 10) = 0;
      *(undefined1 *)((int)param_1 + 0x15) = 0;
      param_1[0xb] = *(undefined2 *)(param_2 + 0x1a);
      param_1[0xc] = *(undefined2 *)(param_2 + 0x18);
      uVar1 = *(undefined2 *)(param_2 + 4);
      uVar2 = *(undefined2 *)(param_2 + 6);
      uVar3 = *(undefined2 *)(param_2 + 8);
      uVar4 = *(undefined2 *)(param_2 + 10);
      *param_1 = *(undefined2 *)(param_2 + 2);
      param_1[1] = uVar1;
      param_1[2] = uVar2;
      param_1[3] = uVar3;
      param_1[4] = uVar4;
      uVar1 = *(undefined2 *)(param_2 + 0x10);
      uVar2 = *(undefined2 *)(param_2 + 0x12);
      uVar3 = *(undefined2 *)(param_2 + 0x14);
      uVar4 = *(undefined2 *)(param_2 + 0x16);
      param_1[5] = *(undefined2 *)(param_2 + 0xe);
      param_1[6] = uVar1;
      param_1[7] = uVar2;
      param_1[8] = uVar3;
      param_1[9] = uVar4;
      *(undefined1 *)((int)param_1 + 0x1f) = *(undefined1 *)(param_2 + 0x25);
    }
  }
  return iVar5;
}

