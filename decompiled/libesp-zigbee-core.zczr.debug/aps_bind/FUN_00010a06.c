/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> FUN_00010a06
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void FUN_00010a06(int param_1)

{
  uint uVar1;
  int unaff_s1;
  int iVar2;
  int unaff_s2;
  int unaff_s3;
  
  uVar1 = (unaff_s1 - *(int *)(param_1 + unaff_s3 + -0x68c) >> 1) * -0x55555555;
  iVar2 = core_globals_get();
  if ((uVar1 & 0xffff) < (uint)*(ushort *)(iVar2 + unaff_s3 + -0x684)) {
    iVar2 = test_and_set_bitmap(uVar1 & 0xffff,unaff_s2 + 6);
    if (iVar2 != 0) {
      return;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_bind.c",0x76,"bind_table_bind"
                  ,&_LC10);
  }
  *(char *)(unaff_s1 + 4) = *(char *)(unaff_s1 + 4) + '\x01';
  iVar2 = core_globals_get();
  if ((*(uint *)(iVar2 + 0x980) & 1) == 0) {
    aps_bind_table_store_bind();
  }
  return;
}

