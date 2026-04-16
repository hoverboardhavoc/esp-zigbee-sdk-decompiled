/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_metering_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t * esp_zb_metering_cluster_create(esp_zb_metering_cluster_cfg_t *cfg)

{
  uint32_t extraout_a0;
  esp_zb_attribute_list_t *peVar1;
  undefined4 extraout_a1;
  undefined1 local_20 [8];
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  local_20._0_4_ = 0;
  local_20._4_2_ = 0;
  local_20[6] = '\0';
  local_20[7] = '\0';
  uStack_18 = 0;
  uStack_14 = 0;
  if (cfg != (esp_zb_metering_cluster_cfg_t *)0x0) {
    convert_uint48_to_uint64(&cfg->current_summation_delivered);
    uStack_18._0_1_ = cfg->status;
    uStack_18._1_1_ = cfg->uint_of_measure;
    uStack_18._2_1_ = cfg->summation_formatting;
    uStack_18._3_1_ = cfg->metering_device_type;
    cfg = (esp_zb_metering_cluster_cfg_t *)local_20;
    local_20._0_4_ = extraout_a0;
    local_20._4_4_ = extraout_a1;
  }
  peVar1 = (esp_zb_attribute_list_t *)metering_cluster_create(cfg);
  return peVar1;
}

