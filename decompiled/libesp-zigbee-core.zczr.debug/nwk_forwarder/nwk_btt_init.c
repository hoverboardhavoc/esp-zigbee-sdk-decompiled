/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_btt_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_btt_init(void)

{
  uint uVar1;
  int iVar2;
  bitmap_t *pbVar3;
  
  memset(&s_nwk_fwd,0,0x2d0);
  for (uVar1 = 0; uVar1 < 0x5a; uVar1 = uVar1 + 1 & 0xff) {
    iVar2 = nwk_neighbor_table_get_capacity();
    pbVar3 = (bitmap_t *)mm_calloc(iVar2 + 7U >> 3,1);
    s_nwk_fwd.btt[uVar1].passive_ack = pbVar3;
  }
  return;
}

