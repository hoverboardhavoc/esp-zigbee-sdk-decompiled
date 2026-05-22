/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_disc_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_disc_t * nwk_route_disc_table_find(ezb_shortaddr_t src_addr,uint8_t rreq_id)

{
  nwk_route_disc_t *pnVar1;
  undefined2 in_register_0000202a;
  int iVar2;
  undefined3 in_register_0000202d;
  uint uVar3;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar2 + 0xc68),*(undefined2 *)(iVar2 + 0xc6c),uVar3);
    if (*(ushort *)(iVar2 + 0xc6c) <= uVar3) {
      return (nwk_route_disc_t *)0x0;
    }
    pnVar1 = (nwk_route_disc_t *)(*(int *)(iVar2 + 0xc64) + uVar3 * 0x10);
    if (((uint)pnVar1->src_addr == CONCAT22(in_register_0000202a,src_addr)) &&
       ((uint)pnVar1->rreq_id == CONCAT31(in_register_0000202d,rreq_id))) break;
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return pnVar1;
}

