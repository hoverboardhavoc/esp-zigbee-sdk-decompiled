/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_leave_is_own_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zdo_nwk_mgmt_leave_is_own_child(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x346,
                  "zdo_nwk_mgmt_leave_is_own_child","device_address");
  }
  else {
    iVar1 = nwk_neighbor_table_get_by_extended();
    if (iVar1 == 0) {
      return 0;
    }
    if ((*(uint *)(iVar1 + 0xc) & 0x3c0) != 0x40) {
      return 0;
    }
  }
  return 1;
}

