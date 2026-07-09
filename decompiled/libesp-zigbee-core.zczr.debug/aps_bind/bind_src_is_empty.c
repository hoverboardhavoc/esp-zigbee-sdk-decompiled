/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_src_is_empty
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool bind_src_is_empty(int param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = core_globals_get();
  uVar1 = *(ushort *)(iVar2 + 0x97c);
  uVar3 = bitmap_find_first_bit(param_1 + 6,(uint)uVar1);
  return uVar1 <= uVar3;
}

