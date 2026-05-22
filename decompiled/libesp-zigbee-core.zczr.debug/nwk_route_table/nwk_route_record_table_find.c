/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_record_t * nwk_route_record_table_find(ezb_shortaddr_t dst_addr)

{
  undefined2 in_register_0000202a;
  int iVar1;
  uint uVar2;
  nwk_route_record_t *pnVar3;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0xc74),*(undefined2 *)(iVar1 + 0xc78),uVar2);
    if (*(ushort *)(iVar1 + 0xc78) <= uVar2) {
      return (nwk_route_record_t *)0x0;
    }
    pnVar3 = (nwk_route_record_t *)(uVar2 * 0x1c + *(int *)(iVar1 + 0xc70));
    if ((uint)pnVar3->dst_addr == CONCAT22(in_register_0000202a,dst_addr)) break;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return pnVar3;
}

