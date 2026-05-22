/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_handle_link_status_period
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_table_handle_link_status_period(void)

{
  int iVar1;
  uint uVar2;
  nwk_route_t *route;
  int iVar3;
  
  iVar1 = core_globals_get();
  uVar2 = 0;
  while (uVar2 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar1 + 0xc5c),*(undefined2 *)(iVar1 + 0xc60),uVar2),
        uVar2 < *(ushort *)(iVar1 + 0xc60)) {
    iVar3 = *(int *)(iVar1 + 0xc58) + uVar2 * 0x10;
    if (((*(ushort *)(iVar3 + 0xe) & 7) == 0) && (*(char *)(iVar3 + 10) != '\0')) {
      *(char *)(iVar3 + 10) = *(char *)(iVar3 + 10) + -1;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

