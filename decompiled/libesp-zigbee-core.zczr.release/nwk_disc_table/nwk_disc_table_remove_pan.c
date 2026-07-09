/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_remove_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_remove_pan(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit(iVar1 + 0xba4,6,uVar2);
    uVar2 = uVar2 & 0xff;
    if (5 < uVar2) break;
    if (*(byte *)(iVar1 + uVar2 * 0x14 + 0xb34) == param_1) {
      disc_table_delete(iVar1 + 0xb2c,uVar2 * 0x14 + iVar1 + 0xb2c);
    }
    uVar2 = uVar2 + 1 & 0xff;
  }
  nwk_address_delete_panid(param_1);
  return;
}

