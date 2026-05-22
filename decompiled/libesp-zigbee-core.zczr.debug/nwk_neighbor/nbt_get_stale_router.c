/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nbt_get_stale_router
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_neighbor_t * nbt_get_stale_router(nwk_neighbor_table_t *tbl)

{
  uint uVar1;
  uint16_t uVar2;
  undefined2 extraout_var;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  nwk_neighbor_t *pnVar7;
  
  uVar1 = (uint)tbl->ent_nr - (uint)tbl->ed_capacity & 0xffff;
  uVar3 = 0;
  while (uVar3 = bitmap_find_next_bit(tbl->ent_in_use,uVar1,uVar3), uVar3 < uVar1) {
    pnVar7 = tbl->ents + uVar3;
    uVar5 = *(uint *)&pnVar7->field_0xc & 3;
    if (((uVar5 == 0) || (uVar5 == 1)) && ((*(uint *)&pnVar7->field_0xc & 0x1c0003c0) == 0x80))
    goto _L0;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  uVar5 = 0xffff;
  uVar4 = 0;
  uVar3 = uVar1;
  while (uVar4 = bitmap_find_next_bit(tbl->ent_in_use,uVar1,uVar4), uVar4 < uVar1) {
    pnVar7 = tbl->ents + uVar4;
    uVar6 = *(uint *)&pnVar7->field_0xc & 3;
    if (((uVar6 == 0) || (uVar6 == 1)) &&
       (((*(uint *)&pnVar7->field_0xc & 0x3c0) == 0x80 && (10 < (pnVar7->dev).r.router_age)))) {
      uVar2 = nwk_neighbor_get_router_rank(pnVar7);
      if (CONCAT22(extraout_var,uVar2) < uVar5) {
        uVar3 = uVar4;
        uVar5 = CONCAT22(extraout_var,uVar2);
      }
    }
    uVar4 = uVar4 + 1 & 0xffff;
  }
  if (uVar3 != uVar1) {
    pnVar7 = tbl->ents + uVar3;
_L0:
    if (pnVar7 == (nwk_neighbor_t *)0x0) {
      return (nwk_neighbor_t *)0x0;
    }
    if ((*(uint *)&pnVar7->field_0xc & 0x3c0) != 0x240) {
      return pnVar7;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_neighbor.c",0x153,
                  "nbt_get_stale_router",
                  "stale_router == ((void *)0) || stale_router->relationship != NWK_RELATIONSHIP_BACKBONE_SIBLING"
                 );
  }
  return (nwk_neighbor_t *)0x0;
}

