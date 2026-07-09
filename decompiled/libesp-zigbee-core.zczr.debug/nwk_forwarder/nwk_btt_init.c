/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_btt_init(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  memset(&s_nwk_fwd,0,0x2d0);
  for (uVar1 = 0; uVar1 < 0x5a; uVar1 = uVar1 + 1 & 0xff) {
    iVar2 = nwk_neighbor_table_get_capacity();
    uVar3 = mm_calloc(iVar2 + 7U >> 3,1);
    *(undefined4 *)((uVar1 + 6) * 8 + 0x11a48) = uVar3;
  }
  return;
}

