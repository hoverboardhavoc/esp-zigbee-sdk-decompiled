/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_route_disc_table_handle_tick(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = core_globals_get();
  uVar4 = 0;
  while (uVar4 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0xc68),*(undefined2 *)(iVar2 + 0xc6c),uVar4),
        uVar4 < *(ushort *)(iVar2 + 0xc6c)) {
    iVar3 = *(int *)(iVar2 + 0xc64) + uVar4 * 0x10;
    sVar1 = *(short *)(iVar3 + 8);
    if (sVar1 == 0) {
      nwk_route_disc_table_delete();
    }
    else {
      *(short *)(iVar3 + 8) = sVar1 + -1;
    }
    uVar4 = uVar4 + 1 & 0xffff;
  }
  return;
}

