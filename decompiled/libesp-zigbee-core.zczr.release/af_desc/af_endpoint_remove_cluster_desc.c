/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> af_desc.o -> af_endpoint_remove_cluster_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_cluster_desc_t *
af_endpoint_remove_cluster_desc
          (af_ep_desc_t *ep_desc,uint16_t cluster_id,uint8_t role_mask,uint16_t manuf_code)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  undefined2 in_register_00002036;
  zcl_cluster_desc_t **ppzVar2;
  zcl_cluster_desc_t *pzVar3;
  
  _Var1 = af_device_desc_is_registered();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    if (ep_desc != (af_ep_desc_t *)0x0) {
      ppzVar2 = &ep_desc->cluster_list;
      ep_desc = (af_ep_desc_t *)ep_desc->cluster_list;
      while (ep_desc != (af_ep_desc_t *)0x0) {
        pzVar3 = *ppzVar2;
        if ((((pzVar3 != (zcl_cluster_desc_t *)0x0) &&
             ((uint)pzVar3->cluster_id == CONCAT22(in_register_0000202e,cluster_id))) &&
            ((uint)pzVar3->role_mask == CONCAT31(in_register_00002031,role_mask))) &&
           ((uint)pzVar3->manuf_code == CONCAT22(in_register_00002036,manuf_code))) {
          *ppzVar2 = *(zcl_cluster_desc_t **)&(ep_desc->simple_desc).app_device_id;
          (ep_desc->simple_desc).app_device_id = 0;
          (ep_desc->simple_desc).field_0x6 = 0;
          (ep_desc->simple_desc).app_input_cluster_count = '\0';
          return (zcl_cluster_desc_t *)ep_desc;
        }
        ppzVar2 = &pzVar3->next;
        ep_desc = (af_ep_desc_t *)pzVar3->next;
      }
    }
  }
  else {
    ep_desc = (af_ep_desc_t *)0x0;
  }
  return (zcl_cluster_desc_t *)ep_desc;
}

