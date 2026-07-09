/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> bind_table_unbind
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int bind_table_unbind(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0x974);
  iVar3 = core_globals_get();
  if ((uint)*(ushort *)(iVar3 + 0x97c) <= ((param_2 - iVar2 >> 1) * -0x55555555 & 0xffffU)) {
    __assert_func(0,0,0,0);
  }
  iVar2 = test_and_clr_bitmap(param_1 + 6);
  if (iVar2 != 0) {
    iVar3 = core_globals_get();
    if ((*(uint *)(iVar3 + 0x980) & 1) == 0) {
      aps_bind_table_remove_stored_bind(param_1,param_2);
    }
    iVar3 = bind_src_is_empty(param_1);
    if (iVar3 != 0) {
      bind_src_table_free(param_1);
    }
    cVar1 = *(char *)(param_2 + 4);
    *(char *)(param_2 + 4) = cVar1 + -1;
    if (cVar1 == '\x01') {
      bind_dst_table_free(param_2);
    }
  }
  return iVar2;
}

