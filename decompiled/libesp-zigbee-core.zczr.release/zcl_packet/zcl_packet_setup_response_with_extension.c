/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_response_with_extension
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_packet_setup_response_with_extension
          (int param_1,undefined1 *param_2,undefined1 param_3,int param_4,int param_5)

{
  undefined1 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  
  if (param_1 != 0) {
    uVar2 = 0x87;
    if (param_2 != (undefined1 *)0x0) {
      uVar1 = param_2[0x1e];
      *(undefined1 *)(param_1 + 0x20) = param_3;
      *(undefined1 *)(param_1 + 0x1e) = uVar1;
      *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
      bVar4 = param_2[0x1a];
      bVar3 = bVar4 | 8;
      if ((bVar4 & 8) != 0) {
        bVar3 = bVar4 & 0xf7;
      }
      bVar4 = bVar3 & 0xef;
      if (param_5 != 0) {
        bVar4 = bVar3 | 0x10;
      }
      *(byte *)(param_1 + 0x1a) = bVar4;
      zcl_packet_setup_stamp
                (param_1,param_2[0x15],param_2[0x14],*(undefined2 *)(param_2 + 0x16),
                 *(undefined2 *)(param_2 + 0x18),*param_2,param_2 + 2);
      if (param_4 == 0) {
        bVar4 = bVar4 | 0x20;
        *(undefined1 *)(param_1 + 0x1e) = param_2[0x1e];
      }
      else {
        *(undefined1 *)(param_1 + 0x1e) = 0xff;
        bVar4 = bVar4 & 0xdf;
      }
      *(byte *)(param_1 + 0x1a) = bVar4;
      uVar2 = 0;
    }
    return uVar2;
  }
  return 0x87;
}

