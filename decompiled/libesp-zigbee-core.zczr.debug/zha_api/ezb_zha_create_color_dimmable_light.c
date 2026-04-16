/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zha_api.o -> ezb_zha_create_color_dimmable_light
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_af_ep_desc_t
ezb_zha_create_color_dimmable_light(uint8_t ep_id,ezb_zha_color_dimmable_light_config_t *cfg)

{
  ezb_zcl_color_control_cluster_server_config_t *peVar1;
  ezb_af_ep_desc_t pvVar2;
  undefined4 uVar3;
  ezb_zcl_level_cluster_server_config_t *peVar4;
  ezb_zcl_on_off_cluster_server_config_t *peVar5;
  ezb_zcl_scenes_cluster_server_config_t *peVar6;
  ezb_zcl_groups_cluster_server_config_t *peVar7;
  ezb_zcl_identify_cluster_server_config_t *peVar8;
  ushort uStack_38;
  undefined2 uStack_36;
  ezb_af_ep_config_t ep_config;
  
  if (cfg == (ezb_zha_color_dimmable_light_config_t *)0x0) {
    peVar1 = (ezb_zcl_color_control_cluster_server_config_t *)0x0;
    peVar4 = (ezb_zcl_level_cluster_server_config_t *)0x0;
    peVar5 = (ezb_zcl_on_off_cluster_server_config_t *)0x0;
    peVar6 = (ezb_zcl_scenes_cluster_server_config_t *)0x0;
    peVar7 = (ezb_zcl_groups_cluster_server_config_t *)0x0;
    peVar8 = (ezb_zcl_identify_cluster_server_config_t *)0x0;
  }
  else {
    peVar8 = &cfg->identify_cfg;
    peVar7 = &cfg->groups_cfg;
    peVar6 = &cfg->scenes_cfg;
    peVar5 = &cfg->on_off_cfg;
    peVar4 = &cfg->level_cfg;
    peVar1 = &cfg->color_cfg;
  }
  _uStack_38 = CONCAT22(0x104,(ushort)ep_id);
  ep_config.ep_id = '\x02';
  ep_config._1_1_ = 1;
  ep_config.app_profile_id = 0;
  pvVar2 = (ezb_af_ep_desc_t)ezb_af_create_endpoint_desc(&uStack_38);
  uVar3 = ezb_zcl_basic_create_cluster_desc(cfg,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_identify_create_cluster_desc(peVar8,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_groups_create_cluster_desc(peVar7,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_scenes_create_cluster_desc(peVar6,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_on_off_create_cluster_desc(peVar5,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_level_create_cluster_desc(peVar4,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_color_control_create_cluster_desc(peVar1,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  return pvVar2;
}

