/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_btt_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_btt_init(void)

{
  nwk_fwd_s *pnVar1;
  int iVar2;
  bitmap_t *pbVar3;
  
  pnVar1 = &s_nwk_fwd;
  memset(&s_nwk_fwd,0,0x2d0);
  do {
    iVar2 = nwk_neighbor_table_get_capacity();
    pbVar3 = (bitmap_t *)mm_calloc(iVar2 + 7U >> 3,1);
    pnVar1->btt[0].passive_ack = pbVar3;
    pnVar1 = (nwk_fwd_s *)&(pnVar1->send_queue).length;
  } while (pnVar1 != (nwk_fwd_s *)0x116b8);
  return;
}

