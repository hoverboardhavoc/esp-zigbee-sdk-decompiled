/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_disc_t * nwk_route_disc_table_find_or_create(ezb_shortaddr_t src_addr,uint8_t rreq_id)

{
  int iVar1;
  nwk_route_disc_t *pnVar2;
  
  iVar1 = core_globals_get();
  pnVar2 = route_disc_table_find((nwk_route_disc_table_t *)(iVar1 + 0xc64),src_addr,rreq_id);
  if ((pnVar2 == (nwk_route_disc_t *)0x0) &&
     (pnVar2 = (nwk_route_disc_t *)
               mempool_alloc_ent(*(void **)(iVar1 + 0xc64),*(bitmap_t **)(iVar1 + 0xc68),0x10,
                                 *(uint16_t *)(iVar1 + 0xc6c)), pnVar2 != (nwk_route_disc_t *)0x0))
  {
    memset(&pnVar2->route,0,0xc);
    pnVar2->sender_addr = 0xffff;
    pnVar2->forward_cost = 0xff;
    pnVar2->residual_cost = 0xff;
    pnVar2->rreq_id = rreq_id;
    pnVar2->src_addr = src_addr;
    pnVar2->expiry = 10;
  }
  return pnVar2;
}

