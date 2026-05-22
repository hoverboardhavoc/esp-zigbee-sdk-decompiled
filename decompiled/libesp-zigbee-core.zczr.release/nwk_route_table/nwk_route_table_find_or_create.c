/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_t * nwk_route_table_find_or_create(ezb_shortaddr_t dst_addr)

{
  int iVar1;
  nwk_route_t *pnVar2;
  nwk_route_t *pnVar3;
  uint uVar4;
  uint uVar5;
  
  iVar1 = core_globals_get();
  pnVar2 = route_table_find((nwk_route_table_t *)(iVar1 + 0xc58),dst_addr);
  if (pnVar2 == (nwk_route_t *)0x0) {
    pnVar3 = (nwk_route_t *)
             mempool_alloc_ent(*(void **)(iVar1 + 0xc58),*(bitmap_t **)(iVar1 + 0xc5c),0x10,
                               *(uint16_t *)(iVar1 + 0xc60));
    pnVar2 = pnVar3;
    if (pnVar3 == (nwk_route_t *)0x0) {
      uVar4 = 0;
      while (uVar4 = bitmap_find_next_bit
                               (*(undefined4 *)(iVar1 + 0xc5c),*(undefined2 *)(iVar1 + 0xc60),uVar4)
            , uVar4 < *(ushort *)(iVar1 + 0xc60)) {
        pnVar2 = (nwk_route_t *)(*(int *)(iVar1 + 0xc58) + uVar4 * 0x10);
        if (pnVar2->ref == '\0') {
          uVar5._0_1_ = pnVar2->ref;
          uVar5._1_1_ = pnVar2->initiator;
          uVar5._2_2_ = *(undefined2 *)&pnVar2->field_0xe;
          if ((uVar5 & 0x500000) == 0x500000) goto _L0;
          if (pnVar3 != (nwk_route_t *)0x0) {
            if ((pnVar3->recent_activity <= pnVar2->recent_activity) &&
               ((pnVar2->recent_activity != pnVar3->recent_activity ||
                (pnVar3->total_usage <= pnVar2->total_usage)))) goto _L78;
          }
        }
        else {
_L78:
          pnVar2 = pnVar3;
        }
        pnVar3 = pnVar2;
        uVar4 = uVar4 + 1 & 0xffff;
      }
      pnVar2 = pnVar3;
      if (pnVar3 == (nwk_route_t *)0x0) {
        return (nwk_route_t *)0x0;
      }
    }
_L0:
    memset(&pnVar2->total_usage,0,0xc);
    pnVar2->next_hop = 0xffff;
    pnVar2->dst_addr = dst_addr;
    *(undefined2 *)&pnVar2->field_0xe = 3;
  }
  return pnVar2;
}

