/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_meter_identification_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t *
esp_zb_meter_identification_cluster_create(esp_zb_meter_identification_cluster_cfg_t *cfg)

{
  esp_zb_meter_identification_cluster_cfg_t *peVar1;
  esp_zb_attribute_list_t *peVar2;
  int iVar3;
  esp_zb_meter_identification_cluster_cfg_t *peStack_24;
  char acStack_20 [4];
  char *pcStack_1c;
  uint uStack_18;
  uint uStack_14;
  
  peStack_24 = (esp_zb_meter_identification_cluster_cfg_t *)0x0;
  acStack_20[0] = '\0';
  acStack_20[1] = '\0';
  acStack_20[2] = '\0';
  acStack_20[3] = '\0';
  pcStack_1c = (char *)0x0;
  uStack_18 = 0;
  uStack_14 = 0;
  peVar1 = cfg;
  if (cfg != (esp_zb_meter_identification_cluster_cfg_t *)0x0) {
    iVar3 = (int)(char)(cfg->available_power).high;
    acStack_20 = *(char (*) [4])&cfg->meter_type_id;
    pcStack_1c = cfg->pod;
    uStack_18 = (uint)*(byte *)((int)&(cfg->available_power).low + 1) << 8 |
                (uint)(*(ushort *)(cfg->pod + 0x10) >> 8) | iVar3 << 0x10;
    if (iVar3 < 0) {
      uStack_18 = uStack_18 | 0xff000000;
    }
    uStack_14 = (uint)(int3)cfg->power_threshold;
    if ((char)(cfg->power_threshold).high < '\0') {
      uStack_14 = uStack_14 | 0xff000000;
    }
    peVar1 = (esp_zb_meter_identification_cluster_cfg_t *)&peStack_24;
    peStack_24 = cfg;
  }
  peVar2 = (esp_zb_attribute_list_t *)meter_identification_cluster_create(peVar1);
  return peVar2;
}

