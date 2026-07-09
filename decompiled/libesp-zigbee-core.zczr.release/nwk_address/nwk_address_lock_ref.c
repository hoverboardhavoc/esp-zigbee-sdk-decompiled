/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_lock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_lock_ref(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = core_globals_get();
  do_lock_ref(param_1);
  iVar4 = *(int *)(iVar1 + 0xc50) + param_1 * 0x12;
  if ((*(byte *)(iVar4 + 0x11) & 4) == 0) {
    return;
  }
  uVar2 = (uint)*(ushort *)(iVar4 + 0xe);
  iVar4 = check_table_ref(uVar2,*(undefined4 *)(iVar1 + 0xc4c),*(undefined2 *)(iVar1 + 0xc54));
  if (iVar4 != 0) {
    iVar4 = *(int *)(iVar1 + 0xc50) + uVar2 * 0x12;
    uVar3 = (uint)*(byte *)(iVar4 + 0x10);
    if (uVar3 == 0xff) {
      __assert_func(0,0,0,0);
    }
    if (uVar3 == 0) {
      addr_table_lru_remove((undefined4 *)(iVar1 + 0xc4c),uVar2);
    }
    *(char *)(iVar4 + 0x10) = *(char *)(iVar4 + 0x10) + '\x01';
  }
  return;
}

