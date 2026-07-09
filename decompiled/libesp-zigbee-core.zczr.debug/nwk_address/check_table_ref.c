/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> check_table_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool check_table_ref(uint param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  
  if ((param_1 < param_3) && (iVar1 = test_bitmap(), iVar1 != 0)) {
    if (param_3 <= param_1) {
      return false;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_address.c",0x46,
                  "check_table_ref","(ref < table_size) && test_bitmap(ref, table_map)");
  }
  iVar1 = test_bitmap(param_1,param_2);
  return iVar1 != 0;
}

