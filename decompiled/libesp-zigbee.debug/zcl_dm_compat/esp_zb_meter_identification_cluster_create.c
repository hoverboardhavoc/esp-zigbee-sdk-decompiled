/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.debug -> zcl_dm_compat.o -> esp_zb_meter_identification_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t *
esp_zb_meter_identification_cluster_create(esp_zb_meter_identification_cluster_cfg_t *cfg)

{
  esp_zb_attribute_list_t *peVar1;
  esp_zb_meter_identification_cluster_cfg_t *peStack_2c;
  char acStack_28 [4];
  char *pcStack_24;
  int32_t iStack_20;
  int32_t iStack_1c;
  esp_zb_int24_t eStack_18;
  esp_zb_int24_t aeStack_14 [4];
  
  peStack_2c = (esp_zb_meter_identification_cluster_cfg_t *)0x0;
  acStack_28[0] = '\0';
  acStack_28[1] = '\0';
  acStack_28[2] = '\0';
  acStack_28[3] = '\0';
  pcStack_24 = (char *)0x0;
  iStack_20 = 0;
  iStack_1c = 0;
  if (cfg != (esp_zb_meter_identification_cluster_cfg_t *)0x0) {
    acStack_28 = *(char (*) [4])&cfg->meter_type_id;
    pcStack_24 = cfg->pod;
    eStack_18.low =
         (ushort)*(byte *)((int)&(cfg->available_power).low + 1) << 8 |
         *(ushort *)(cfg->pod + 0x10) >> 8;
    eStack_18.high = (cfg->available_power).high;
    peStack_2c = cfg;
    iStack_20 = convert_int24_to_int32(&eStack_18);
    aeStack_14[0].low = (cfg->power_threshold).low;
    aeStack_14[0].high = (cfg->power_threshold).high;
    iStack_1c = convert_int24_to_int32(aeStack_14);
    cfg = (esp_zb_meter_identification_cluster_cfg_t *)&peStack_2c;
  }
  peVar1 = (esp_zb_attribute_list_t *)meter_identification_cluster_create(cfg);
  return peVar1;
}

