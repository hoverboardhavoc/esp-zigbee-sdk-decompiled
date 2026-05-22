/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_device_add_green_power_proxy_endpoint
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t af_device_add_green_power_proxy_endpoint(af_device_desc_t *dev_desc)

{
  int iVar1;
  af_ep_desc_t *ep_desc;
  zcl_cluster_desc_t *cluster_desc;
  ezb_err_t eVar2;
  undefined1 auStack_28 [4];
  af_ep_config_t ep_config;
  
  auStack_28[0] = 0xf2;
  auStack_28[1] = 0;
  auStack_28._2_2_ = 0xa1e0;
  ep_config.ep_id = '`';
  ep_config._1_1_ = 0;
  ep_config.app_profile_id = 0;
  iVar1 = nwk_is_device_zczr();
  if (iVar1 == 0) {
    cluster_desc = (zcl_cluster_desc_t *)0x0;
    ep_desc = (af_ep_desc_t *)0x0;
    eVar2 = 0xd;
  }
  else if (dev_desc == (af_device_desc_t *)0x0) {
    eVar2 = 3;
    ep_desc = (af_ep_desc_t *)0x0;
    cluster_desc = (zcl_cluster_desc_t *)0x0;
  }
  else {
    ep_desc = af_create_endpoint_desc((af_ep_config_t *)auStack_28);
    cluster_desc = (zcl_cluster_desc_t *)zcl_create_cluster_desc(0x21,2,0);
    eVar2 = af_endpoint_add_cluster_desc(ep_desc,cluster_desc);
    if (eVar2 == 0) {
      eVar2 = af_device_add_endpoint_desc(dev_desc,ep_desc);
      if (eVar2 == 0) {
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
  return eVar2;
}

