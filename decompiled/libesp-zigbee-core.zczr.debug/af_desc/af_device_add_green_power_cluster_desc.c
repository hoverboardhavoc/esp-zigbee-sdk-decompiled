/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_add_green_power_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_add_green_power_cluster_desc(af_device_desc_t *dev_desc)

{
  af_ep_desc_t *ep_desc;
  zcl_cluster_desc_t *cluster_desc;
  ezb_err_t eVar1;
  undefined1 auStack_28 [4];
  af_ep_config_t ep_config;
  
  auStack_28[0] = 0xf2;
  auStack_28[1] = 0;
  auStack_28._2_2_ = 0xa1e0;
  ep_config.ep_id = '`';
  ep_config._1_1_ = 0;
  ep_config.app_profile_id = 0;
  if (dev_desc == (af_device_desc_t *)0x0) {
    eVar1 = 3;
    ep_desc = (af_ep_desc_t *)0x0;
    cluster_desc = (zcl_cluster_desc_t *)0x0;
  }
  else {
    ep_desc = af_create_endpoint_desc((af_ep_config_t *)auStack_28);
    cluster_desc = (zcl_cluster_desc_t *)zcl_create_cluster_desc(0x21,2,0);
    eVar1 = af_endpoint_add_cluster_desc(ep_desc,cluster_desc);
    if (eVar1 == 0) {
      eVar1 = af_device_add_endpoint_desc(dev_desc,ep_desc);
      if (eVar1 == 0) {
        cluster_desc = (zcl_cluster_desc_t *)0x0;
        ep_desc = (af_ep_desc_t *)0x0;
      }
      else {
        cluster_desc = (zcl_cluster_desc_t *)0x0;
      }
    }
  }
  zcl_free_cluster_desc(cluster_desc);
  af_free_endpoint_desc(ep_desc);
  return eVar1;
}

