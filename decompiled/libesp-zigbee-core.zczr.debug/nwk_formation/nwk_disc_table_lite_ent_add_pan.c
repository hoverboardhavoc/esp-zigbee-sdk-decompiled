/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_ent_add_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_lite_ent_add_pan(undefined1 *param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  *param_1 = *(undefined1 *)(param_2 + 0xc);
  param_1[1] = *(undefined1 *)(param_2 + 0xd);
  uVar3 = 0;
  while( true ) {
    bVar1 = param_1[2];
    uVar2 = (uint)bVar1;
    if (uVar2 <= uVar3) {
      if (uVar2 < 0x1c) {
        *(undefined2 *)(param_1 + uVar2 * 2 + 4) = *(undefined2 *)(param_2 + 10);
        param_1[2] = bVar1 + 1;
      }
      else {
        log_write(2,"nwk_formation.c","Too many PANs on channel: %d:%d");
      }
      return;
    }
    if (*(short *)(param_1 + uVar3 * 2 + 4) == *(short *)(param_2 + 10)) break;
    uVar3 = uVar3 + 1 & 0xff;
  }
  return;
}

