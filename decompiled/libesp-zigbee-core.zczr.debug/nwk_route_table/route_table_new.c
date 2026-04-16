/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> route_table_new
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_t * route_table_new(nwk_route_table_t *tbl)

{
  ushort blk_nr;
  nwk_route_t *pnVar1;
  nwk_route_t *pnVar2;
  uint16_t uVar3;
  undefined2 extraout_var;
  uint uVar4;
  uint uVar5;
  nwk_route_t *pnVar6;
  
  pnVar1 = tbl->ents;
  blk_nr = tbl->ent_nr;
  uVar3 = mempool_alloc_idx(tbl->ent_in_use,blk_nr);
  if (CONCAT22(extraout_var,uVar3) < (uint)blk_nr) {
    pnVar1 = pnVar1 + CONCAT22(extraout_var,uVar3);
  }
  else {
    pnVar1 = (nwk_route_t *)0x0;
  }
  if (pnVar1 == (nwk_route_t *)0x0) {
    uVar4 = 0;
    while (uVar4 = bitmap_find_next_bit(tbl->ent_in_use,tbl->ent_nr,uVar4), uVar4 < tbl->ent_nr) {
      pnVar6 = tbl->ents + uVar4;
      pnVar2 = pnVar1;
      if (pnVar6->ref == '\0') {
        uVar5._0_1_ = pnVar6->ref;
        uVar5._1_1_ = pnVar6->initiator;
        uVar5._2_2_ = *(undefined2 *)&pnVar6->field_0xe;
        if ((uVar5 & 0x500000) == 0x500000) {
          return pnVar6;
        }
        pnVar2 = pnVar6;
        if (pnVar1 != (nwk_route_t *)0x0) {
          if (((pnVar1->recent_activity <= pnVar6->recent_activity) &&
              (pnVar2 = pnVar1, pnVar6->recent_activity == pnVar1->recent_activity)) &&
             (pnVar6->total_usage < pnVar1->total_usage)) {
            pnVar2 = pnVar6;
          }
        }
      }
      uVar4 = uVar4 + 1 & 0xffff;
      pnVar1 = pnVar2;
    }
  }
  return pnVar1;
}

