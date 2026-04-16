/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ota_upgrade_get_file_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ota_upgrade_file_table_t * ota_upgrade_get_file_table(uint8_t ep_id)

{
  undefined3 in_register_00002029;
  int iVar1;
  
  iVar1 = ezb_zcl_get_attr_desc(CONCAT31(in_register_00002029,ep_id),0x19,1,0xeff1,0x131b);
  if (iVar1 == 0) {
    iVar1 = __assert_func(0,0,0);
  }
  return *(ota_upgrade_file_table_t **)(iVar1 + 8);
}

