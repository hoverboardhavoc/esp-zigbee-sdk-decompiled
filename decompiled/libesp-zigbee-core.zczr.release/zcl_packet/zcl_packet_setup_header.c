/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_packet.o -> zcl_packet_setup_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_packet_setup_header
               (int param_1,byte param_2,int param_3,int param_4,int param_5,undefined2 param_6,
               undefined1 param_7)

{
  byte bVar1;
  byte bVar2;
  
  bVar2 = *(byte *)(param_1 + 0x1a) & 0xf8 | param_2 & 3;
  if (param_3 != 0) {
    bVar2 = *(byte *)(param_1 + 0x1a) & 0xfc | param_2 & 3 | 4;
  }
  bVar1 = bVar2 | 8;
  if (param_4 == 0) {
    bVar1 = bVar2 & 0xf7;
  }
  bVar2 = bVar1 & 0xef;
  if (param_5 != 0) {
    bVar2 = bVar1 | 0x10;
  }
  *(byte *)(param_1 + 0x1a) = bVar2;
  *(undefined1 *)(param_1 + 0x20) = param_7;
  *(undefined2 *)(param_1 + 0x1c) = param_6;
  return;
}

