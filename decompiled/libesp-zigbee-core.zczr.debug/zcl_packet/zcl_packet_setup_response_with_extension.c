/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_setup_response_with_extension
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
zcl_packet_setup_response_with_extension
          (int param_1,undefined1 *param_2,undefined1 param_3,int param_4,int param_5)

{
  byte bVar1;
  undefined4 uVar2;
  
  if (param_1 == 0) {
    uVar2 = 0x87;
  }
  else if (param_2 == (undefined1 *)0x0) {
    uVar2 = 0x87;
  }
  else {
    *(undefined1 *)(param_1 + 0x1e) = param_2[0x1e];
    *(undefined1 *)(param_1 + 0x20) = param_3;
    *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)(param_2 + 0x1c);
    bVar1 = param_2[0x1a];
    *(byte *)(param_1 + 0x1a) = bVar1;
    if ((bVar1 & 8) == 0) {
      *(byte *)(param_1 + 0x1a) = bVar1 | 8;
    }
    else {
      *(byte *)(param_1 + 0x1a) = bVar1 & 0xf7;
    }
    if (param_5 == 0) {
      *(byte *)(param_1 + 0x1a) = *(byte *)(param_1 + 0x1a) & 0xef;
    }
    else {
      *(byte *)(param_1 + 0x1a) = *(byte *)(param_1 + 0x1a) | 0x10;
    }
    zcl_packet_setup_stamp
              (param_1,param_2[0x15],param_2[0x14],*(undefined2 *)(param_2 + 0x16),
               *(undefined2 *)(param_2 + 0x18),*param_2,param_2 + 2);
    if (param_4 == 0) {
      *(undefined1 *)(param_1 + 0x1e) = param_2[0x1e];
      *(byte *)(param_1 + 0x1a) = *(byte *)(param_1 + 0x1a) | 0x20;
      uVar2 = 0;
    }
    else {
      *(undefined1 *)(param_1 + 0x1e) = 0xff;
      *(byte *)(param_1 + 0x1a) = *(byte *)(param_1 + 0x1a) & 0xdf;
      uVar2 = 0;
    }
  }
  return uVar2;
}

