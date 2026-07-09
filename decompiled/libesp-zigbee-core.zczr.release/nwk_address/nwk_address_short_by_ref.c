/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_short_by_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Removing unreachable block (ram,0x000108c4) */

undefined4 nwk_address_short_by_ref(uint param_1,undefined2 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = core_globals_get();
  iVar2 = *(int *)(iVar1 + 0xc50) + param_1 * 0x12;
  if ((*(byte *)(iVar2 + 0x11) & 4) != 0) {
    param_1 = (uint)*(ushort *)(iVar2 + 0xe);
  }
  iVar2 = check_table_ref(param_1,*(undefined4 *)(iVar1 + 0xc4c),*(undefined2 *)(iVar1 + 0xc54));
  uVar3 = 5;
  if (iVar2 != 0) {
    if (param_2 != (undefined2 *)0x0) {
      *param_2 = *(undefined2 *)(*(int *)(iVar1 + 0xc50) + param_1 * 0x12 + 8);
    }
    uVar3 = 0;
  }
  return uVar3;
}

