/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_route_table.o -> nwk_route_table_handle_tick
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
  int iVar4;
  
  iVar2 = core_globals_get();
  uVar3 = 0;
  while (uVar3 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar2 + 0xcc0),*(undefined2 *)(iVar2 + 0xcc4),uVar3),
        uVar3 < *(ushort *)(iVar2 + 0xcc4)) {
    iVar4 = *(int *)(iVar2 + 0xcbc) + uVar3 * 0x10;
    if ((((*(uint *)(iVar4 + 0xc) >> 0x14 & 1) != 0) &&
        (cVar1 = *(char *)(iVar4 + 0xb), cVar1 != '\0')) &&
       (*(char *)(iVar4 + 0xb) = cVar1 + -1, cVar1 == '\x01')) {
      *(ushort *)(iVar4 + 0xe) = *(ushort *)(iVar4 + 0xe) | 0x40;
    }
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return;
}

