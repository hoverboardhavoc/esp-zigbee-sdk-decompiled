/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
                           (*(undefined4 *)(iVar1 + 0xcc0),*(undefined2 *)(iVar1 + 0xcc4),uVar2),
        uVar2 < *(ushort *)(iVar1 + 0xcc4)) {
    iVar3 = *(int *)(iVar1 + 0xcbc) + uVar2 * 0x10;
    if (((*(ushort *)(iVar3 + 0xe) & 7) == 0) && (*(char *)(iVar3 + 10) != '\0')) {
      *(char *)(iVar3 + 10) = *(char *)(iVar3 + 10) + -1;
    }
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

