/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_record_table_next
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_route_record_t * nwk_route_record_table_next(nwk_route_record_t *route_record)

{
  int iVar1;
  nwk_route_record_t *pnVar2;
  uint uVar3;
  
  iVar1 = core_globals_get();
  if (route_record == (nwk_route_record_t *)0x0) {
    uVar3 = 0xffff;
  }
  else {
    uVar3 = ((int)route_record - *(int *)(iVar1 + 0xc70) >> 2) * -0x49249249 & 0xffff;
  }
  uVar3 = bitmap_find_next_bit
                    (*(undefined4 *)(iVar1 + 0xc74),*(undefined2 *)(iVar1 + 0xc78),
                     uVar3 + 1 & 0xffff);
  if (uVar3 < *(ushort *)(iVar1 + 0xc78)) {
    pnVar2 = (nwk_route_record_t *)(*(int *)(iVar1 + 0xc70) + uVar3 * 0x1c);
  }
  else {
    pnVar2 = (nwk_route_record_t *)0x0;
  }
  return pnVar2;
}

