/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_file_table_get_empty_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ota_upgrade_file_t * ota_upgrade_file_table_get_empty_entry(ota_upgrade_file_table_t *file_table)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (file_table == (ota_upgrade_file_table_t *)0x0) {
      return (ota_upgrade_file_t *)0x0;
    }
    if (file_table->size <= uVar1) break;
    if (file_table->entry[uVar1].header.total_image_size == 0) {
      return file_table->entry + uVar1;
    }
    uVar1 = uVar1 + 1 & 0xff;
  }
  return (ota_upgrade_file_t *)0x0;
}

