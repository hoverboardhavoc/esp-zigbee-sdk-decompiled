/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_packet.o -> zdo_packet_response_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

byte zdo_packet_response_init(undefined1 *param_1,undefined1 *param_2,undefined2 param_3)

{
  undefined1 uVar1;
  undefined2 uVar2;
  byte bVar3;
  int iVar4;
  
  if (param_1 != (undefined1 *)0x0) {
    bVar3 = 0x80;
    if (param_2 != (undefined1 *)0x0) {
      uVar2 = *(undefined2 *)(param_2 + 4);
      *(undefined2 *)(param_1 + 6) = param_3;
      *(undefined2 *)(param_1 + 2) = uVar2;
      *(undefined2 *)(param_1 + 4) = *(undefined2 *)(param_2 + 2);
      uVar1 = *param_2;
      param_1[8] = 0;
      *(undefined4 *)(param_1 + 0xc) = 0;
      *param_1 = uVar1;
      *(undefined4 *)(param_1 + 0x10) = 0;
      iVar4 = zmsg_alloc(1);
      *(int *)(param_1 + 0x14) = iVar4;
      bVar3 = -(iVar4 == 0) & 0x8a;
    }
    return bVar3;
  }
  return 0x80;
}

