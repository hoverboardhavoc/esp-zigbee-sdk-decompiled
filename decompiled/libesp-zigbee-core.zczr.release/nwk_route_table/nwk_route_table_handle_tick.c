/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_handle_tick
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_route_table_handle_tick(void)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  nwk_route_t *route;
  int iVar4;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while (uVar3 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0xc5c),*(undefined2 *)(iVar2 + 0xc60),uVar3),
        uVar3 < *(ushort *)(iVar2 + 0xc60)) {
    iVar4 = *(int *)(iVar2 + 0xc58) + uVar3 * 0x10;
    if (((*(int *)(iVar4 + 0xc) << 0xb < 0) && (cVar1 = *(char *)(iVar4 + 0xb), cVar1 != '\0')) &&
       (*(char *)(iVar4 + 0xb) = cVar1 + -1, cVar1 == '\x01')) {
      *(ushort *)(iVar4 + 0xe) = *(ushort *)(iVar4 + 0xe) | 0x40;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return;
}

