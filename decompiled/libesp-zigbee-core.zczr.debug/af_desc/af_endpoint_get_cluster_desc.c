/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> af_desc.o -> af_endpoint_get_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_cluster_desc_t *
af_endpoint_get_cluster_desc(af_ep_desc_t *ep_desc,uint16_t cluster_id,uint8_t role)

{
  ushort uVar1;
  undefined2 in_register_0000202e;
  
  if (ep_desc != (af_ep_desc_t *)0x0) {
    ep_desc = (af_ep_desc_t *)ep_desc->cluster_list;
    while ((ep_desc != (af_ep_desc_t *)0x0 &&
           ((uVar1._0_1_ = ep_desc->ep_id, uVar1._1_1_ = ep_desc->ep_mask,
            (uint)uVar1 != CONCAT22(in_register_0000202e,cluster_id) ||
            (((byte)ep_desc->profile_id & role) == 0))))) {
      ep_desc = *(af_ep_desc_t **)&(ep_desc->simple_desc).app_device_id;
    }
  }
  return (zcl_cluster_desc_t *)ep_desc;
}

