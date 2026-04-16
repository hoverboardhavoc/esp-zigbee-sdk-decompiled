/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zha_api.o -> ezb_zha_create_window_covering
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_af_ep_desc_t ezb_zha_create_window_covering(uint8_t ep_id,ezb_zha_window_covering_config_t *cfg)

{
  ezb_af_ep_desc_t pvVar1;
  undefined4 uVar2;
  ezb_zcl_scenes_cluster_server_config_t *peVar3;
  ezb_zcl_groups_cluster_server_config_t *peVar4;
  ezb_zcl_window_covering_cluster_server_config_t *peVar5;
  ezb_zcl_identify_cluster_server_config_t *peVar6;
  uint8_t uStack_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  ezb_af_ep_config_t ep_config;
  
  if (cfg == (ezb_zha_window_covering_config_t *)0x0) {
    peVar4 = (ezb_zcl_groups_cluster_server_config_t *)0x0;
    peVar5 = (ezb_zcl_window_covering_cluster_server_config_t *)0x0;
    peVar6 = (ezb_zcl_identify_cluster_server_config_t *)0x0;
    peVar3 = (ezb_zcl_scenes_cluster_server_config_t *)0x0;
  }
  else {
    peVar6 = &cfg->identify_cfg;
    peVar5 = &cfg->window_covering_cfg;
    peVar4 = &cfg->groups_cfg;
    peVar3 = &cfg->scenes_cfg;
  }
  memset(&uStack_27,0,7);
  uStack_26 = 0x104;
  ep_config.ep_id = '\x02';
  ep_config._1_1_ = 2;
  uStack_28 = ep_id;
  pvVar1 = (ezb_af_ep_desc_t)ezb_af_create_endpoint_desc(&uStack_28);
  uVar2 = ezb_zcl_basic_create_cluster_desc(cfg,1);
  ezb_af_endpoint_add_cluster_desc(pvVar1,uVar2);
  uVar2 = ezb_zcl_identify_create_cluster_desc(peVar6,1);
  ezb_af_endpoint_add_cluster_desc(pvVar1,uVar2);
  uVar2 = ezb_zcl_window_covering_create_cluster_desc(peVar5,1);
  ezb_af_endpoint_add_cluster_desc(pvVar1,uVar2);
  uVar2 = ezb_zcl_groups_create_cluster_desc(peVar4,1);
  ezb_af_endpoint_add_cluster_desc(pvVar1,uVar2);
  uVar2 = ezb_zcl_scenes_create_cluster_desc(peVar3,1);
  ezb_af_endpoint_add_cluster_desc(pvVar1,uVar2);
  return pvVar1;
}

