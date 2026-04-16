/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
    while (((zcl_reporting_info_t *)ep_desc != (zcl_reporting_info_t *)0x0 &&
           ((uVar1._0_1_ = ((zcl_reporting_info_t *)ep_desc)->direction,
            uVar1._1_1_ = ((zcl_reporting_info_t *)ep_desc)->ep_id,
            (uint)uVar1 != CONCAT22(in_register_0000202e,cluster_id) ||
            (((byte)((zcl_reporting_info_t *)ep_desc)->profile_id & role) == 0))))) {
      ep_desc = *(af_ep_desc_t **)&((zcl_reporting_info_t *)ep_desc)->u;
    }
  }
  return (zcl_cluster_desc_t *)ep_desc;
}

