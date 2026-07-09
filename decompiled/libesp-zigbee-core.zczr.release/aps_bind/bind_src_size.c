/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_src_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int bind_src_size(void)

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
    mempool_free_ent_part_0();
  }
  iVar1 = core_globals_get();
  return (*(ushort *)(iVar1 + 0x97c) + 7 >> 3) + 6;
}

