/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee.release -> zcl_dm_compat.o -> esp_zb_poll_control_cluster_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_zb_attribute_list_t * esp_zb_poll_control_cluster_create(esp_zb_poll_control_cluster_cfg_t *cfg)

{
  esp_zb_attribute_list_t *peVar1;
  uint16_t uStack_1a;
  uint32_t uStack_18;
  uint16_t fast_poll_timeout_max;
  uint32_t check_in_interval_min;
  uint32_t long_poll_interval_min;
  
  peVar1 = (esp_zb_attribute_list_t *)poll_control_cluster_create();
  if (peVar1 != (esp_zb_attribute_list_t *)0x0) {
    uStack_18 = 0;
    check_in_interval_min = 0;
    uStack_1a = 0;
    if (cfg != (esp_zb_poll_control_cluster_cfg_t *)0x0) {
      uStack_18 = cfg->check_in_interval_min;
      check_in_interval_min = cfg->long_poll_interval_min;
      uStack_1a = cfg->fast_poll_timeout_max;
    }
    poll_control_cluster_add_attr(peVar1,4,&stack0xffffffe8);
    poll_control_cluster_add_attr(peVar1,5,&check_in_interval_min);
    poll_control_cluster_add_attr(peVar1,6,&uStack_1a);
  }
  return peVar1;
}

