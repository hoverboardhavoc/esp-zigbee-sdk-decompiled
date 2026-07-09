/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_delete
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_delete(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = core_globals_get();
  iVar2 = check_table_ref(param_1,*(undefined4 *)(iVar1 + 0xc4c),*(undefined2 *)(iVar1 + 0xc54));
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar1 + 0xc50) + param_1 * 0x12;
    if (*(char *)(iVar2 + 0x10) == '\0') {
      test_and_clr_bitmap(param_1,*(undefined4 *)(iVar1 + 0xc4c));
      addr_table_lru_remove(iVar1 + 0xc4c,param_1);
      memset((void *)(*(int *)(iVar1 + 0xc50) + param_1 * 0x12),0,0x12);
      return;
    }
    *(byte *)(iVar2 + 0x11) = *(byte *)(iVar2 + 0x11) | 8;
  }
  return;
}

