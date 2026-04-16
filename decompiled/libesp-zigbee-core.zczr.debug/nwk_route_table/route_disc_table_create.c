/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> route_disc_table_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_disc_t *
route_disc_table_create(nwk_route_disc_table_t *tbl,ezb_shortaddr_t src_addr,uint8_t rreq_id)

{
  ushort blk_nr;
  nwk_route_disc_t *pnVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  
  pnVar1 = tbl->ents;
  blk_nr = tbl->ent_nr;
  uVar2 = mempool_alloc_idx(tbl->ent_in_use,blk_nr);
  if (CONCAT22(extraout_var,uVar2) < (uint)blk_nr) {
    pnVar1 = pnVar1 + CONCAT22(extraout_var,uVar2);
    if (pnVar1 != (nwk_route_disc_t *)0x0) {
      memset(pnVar1,0,0x10);
      pnVar1->rreq_id = rreq_id;
      pnVar1->src_addr = src_addr;
      pnVar1->sender_addr = 0xffff;
      pnVar1->forward_cost = 0xff;
      pnVar1->residual_cost = 0xff;
      pnVar1->expiry = 10;
    }
  }
  else {
    pnVar1 = (nwk_route_disc_t *)0x0;
  }
  return pnVar1;
}

