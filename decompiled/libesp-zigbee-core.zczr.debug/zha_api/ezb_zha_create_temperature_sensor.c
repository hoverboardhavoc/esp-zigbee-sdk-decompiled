/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zha_api.o -> ezb_zha_create_temperature_sensor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_af_ep_desc_t
ezb_zha_create_temperature_sensor(uint8_t ep_id,ezb_zha_temperature_sensor_config_t *cfg)

{
  ezb_zcl_temperature_measurement_cluster_server_config_t *peVar1;
  ezb_af_ep_desc_t pvVar2;
  undefined4 uVar3;
  ezb_zcl_identify_cluster_server_config_t *peVar4;
  ushort uStack_28;
  undefined2 uStack_26;
  ezb_af_ep_config_t ep_config;
  
  if (cfg == (ezb_zha_temperature_sensor_config_t *)0x0) {
    peVar1 = (ezb_zcl_temperature_measurement_cluster_server_config_t *)0x0;
    peVar4 = (ezb_zcl_identify_cluster_server_config_t *)0x0;
  }
  else {
    peVar4 = &cfg->identify_cfg;
    peVar1 = &cfg->temp_meas_cfg;
  }
  _uStack_28 = CONCAT22(0x104,(ushort)ep_id);
  ep_config.ep_id = '\x02';
  ep_config._1_1_ = 3;
  ep_config.app_profile_id = 0;
  pvVar2 = (ezb_af_ep_desc_t)ezb_af_create_endpoint_desc(&uStack_28);
  uVar3 = ezb_zcl_basic_create_cluster_desc(cfg,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_identify_create_cluster_desc(peVar4,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_temperature_measurement_create_cluster_desc(peVar1,1);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  uVar3 = ezb_zcl_identify_create_cluster_desc(0,2);
  ezb_af_endpoint_add_cluster_desc(pvVar2,uVar3);
  return pvVar2;
}

