/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> FUN_00010726
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void FUN_00010726(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  __assert_func();
  nwk_address_unlock_ref();
  iVar1 = core_globals_get();
  uVar2 = *(undefined4 *)(iVar1 + 0x974);
  iVar1 = core_globals_get();
  uVar3 = *(undefined4 *)(iVar1 + 0x978);
  iVar1 = core_globals_get();
  mempool_free_ent(uVar2,uVar3,6,*(undefined2 *)(iVar1 + 0x97c));
  return;
}

