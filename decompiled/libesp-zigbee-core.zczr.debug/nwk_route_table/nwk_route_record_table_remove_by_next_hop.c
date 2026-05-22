/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_remove_by_next_hop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_route_record_table_remove_by_next_hop(ezb_shortaddr_t next_hop)

{
  undefined2 in_register_0000202a;
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while( true ) {
    uVar2 = bitmap_find_next_bit
                      (*(undefined4 *)(iVar1 + 0xc74),*(undefined2 *)(iVar1 + 0xc78),uVar2);
    if (*(ushort *)(iVar1 + 0xc78) <= uVar2) break;
    iVar3 = *(int *)(iVar1 + 0xc70) + uVar2 * 0x1c;
    if ((uint)*(ushort *)(iVar3 + (*(byte *)(iVar3 + 2) - 1) * 2 + 4) ==
        CONCAT22(in_register_0000202a,next_hop)) {
      mempool_free_idx(*(bitmap_t **)(iVar1 + 0xc74),*(ushort *)(iVar1 + 0xc78),(uint16_t)uVar2);
    }
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

