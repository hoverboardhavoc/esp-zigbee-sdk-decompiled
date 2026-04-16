/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x240,
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

