/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_response
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x00010530) */

undefined4 zcl_packet_setup_response(int param_1,undefined1 *param_2,undefined1 param_3)

{
  undefined1 uVar1;
  ushort uVar2;
  undefined4 uVar3;
  byte bVar4;
  byte bVar5;
  
  uVar2 = *(ushort *)(param_2 + 0x1a);
  if (param_1 != 0) {
    uVar3 = 0x87;
    if (param_2 != (undefined1 *)0x0) {
      uVar1 = param_2[0x1e];
      *(undefined1 *)(param_1 + 0x20) = param_3;
      *(undefined1 *)(param_1 + 0x1e) = uVar1;
      *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
      bVar5 = param_2[0x1a];
      bVar4 = bVar5 | 8;
      if ((bVar5 & 8) != 0) {
        bVar4 = bVar5 & 0xf7;
      }
      bVar5 = bVar4 & 0xef;
      if ((uVar2 >> 4 & 1) != 0) {
        bVar5 = bVar4 | 0x10;
      }
      *(byte *)(param_1 + 0x1a) = bVar5;
      zcl_packet_setup_stamp
                (param_1,param_2[0x15],param_2[0x14],*(undefined2 *)(param_2 + 0x16),
                 *(undefined2 *)(param_2 + 0x18),*param_2,param_2 + 2);
      *(undefined1 *)(param_1 + 0x1e) = param_2[0x1e];
      *(byte *)(param_1 + 0x1a) = bVar5 | 0x20;
      uVar3 = 0;
    }
    return uVar3;
  }
  return 0x87;
}

