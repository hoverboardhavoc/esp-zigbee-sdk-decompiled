/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> bind_table_bind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void bind_table_bind(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = core_globals_get();
  uVar1 = (param_2 - *(int *)(iVar2 + 0x974) >> 1) * -0x55555555;
  iVar2 = core_globals_get();
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar2 + 0x97c)) {
    iVar2 = test_and_set_bitmap(uVar1 & 0xffff,param_1 + 6);
    if (iVar2 != 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x76,"bind_table_bind"
                  ,&_LC10);
  }
  *(char *)(param_2 + 4) = *(char *)(param_2 + 4) + '\x01';
  iVar2 = core_globals_get();
  if ((*(uint *)(iVar2 + 0x980) & 1) == 0) {
    aps_bind_table_store_bind(param_1,param_2);
  }
  return;
}

