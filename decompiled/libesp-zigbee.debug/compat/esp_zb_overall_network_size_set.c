/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> compat.o -> esp_zb_overall_network_size_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_zb_overall_network_size_set(uint16_t size)

{
  esp_err_t eVar1;
  int iStack_24;
  ezb_mem_config_t mem_cfg;
  
  mem_cfg.aps_key_pair_set_size = 0;
  iStack_24 = (uint)size << 0x10;
  mem_cfg.address_table_size = size;
  mem_cfg.buffer_pool_size = size;
  mem_cfg._4_4_ = (uint)size << 0x10;
  mem_cfg.route_record_table_size = 0;
  mem_cfg.route_discovery_table_size = size;
  ezb_config_memory(&iStack_24);
  eVar1 = esp_zigbee_err_to_esp();
  return eVar1;
}

