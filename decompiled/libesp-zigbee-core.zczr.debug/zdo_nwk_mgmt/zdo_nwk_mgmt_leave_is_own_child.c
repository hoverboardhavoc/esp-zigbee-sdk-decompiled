/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_leave_is_own_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool zdo_nwk_mgmt_leave_is_own_child(ezb_extaddr_t *device_address)

{
  int iVar1;
  
  if (device_address == (ezb_extaddr_t *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x271,
                  "zdo_nwk_mgmt_leave_is_own_child","device_address");
  }
  else {
    iVar1 = nwk_neighbor_table_get_by_extended();
    if (iVar1 == 0) {
      return false;
    }
    if ((*(uint *)(iVar1 + 0xc) & 0x3c0) != 0x40) {
      return false;
    }
  }
  return true;
}

