/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_btt_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_btt_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = &s_nwk_fwd;
  memset(&s_nwk_fwd,0,0x2d0);
  do {
    iVar2 = nwk_neighbor_table_get_capacity();
    uVar3 = mm_calloc(iVar2 + 7U >> 3,1);
    puVar1[0x10] = uVar3;
    puVar1 = puVar1 + 2;
  } while (puVar1 != (undefined4 *)&DAT_000116c4);
  return;
}

