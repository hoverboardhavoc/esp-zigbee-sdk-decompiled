/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_src_size__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

size_t bind_src_size(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = core_globals_get();
  iVar3 = *(int *)(iVar1 + 0x974);
  iVar1 = core_globals_get();
  iVar1 = *(int *)(iVar1 + 0x978);
  iVar2 = core_globals_get();
  if (((*(short *)(iVar2 + 0x97c) == 0) || (iVar3 == 0)) || (iVar1 == 0)) {
    bind_src_size();
  }
  iVar1 = core_globals_get();
  return (*(ushort *)(iVar1 + 0x97c) + 7 >> 3) + 6;
}

