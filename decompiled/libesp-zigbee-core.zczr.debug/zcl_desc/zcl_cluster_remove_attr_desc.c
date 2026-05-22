/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_cluster_remove_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_attr_desc_t *
zcl_cluster_remove_attr_desc(zcl_cluster_desc_t *cluster_desc,uint16_t attr_id,uint16_t manuf_code)

{
  int iVar1;
  undefined2 in_register_0000202e;
  undefined2 in_register_00002032;
  zcl_attr_desc_t **ppzVar2;
  zcl_attr_desc_s *pzVar3;
  zcl_attr_desc_t *pzVar4;
  
  iVar1 = af_device_desc_is_registered();
  if (iVar1 == 0) {
    if (cluster_desc == (zcl_cluster_desc_t *)0x0) {
      pzVar4 = (zcl_attr_desc_t *)0x0;
    }
    else {
      ppzVar2 = &cluster_desc->attr_list;
      pzVar3 = cluster_desc->attr_list;
      while ((pzVar3 != (zcl_attr_desc_s *)0x0 &&
             (((pzVar4 = *ppzVar2, pzVar4 == (zcl_attr_desc_t *)0x0 ||
               ((uint)pzVar4->id != CONCAT22(in_register_0000202e,attr_id))) ||
              ((uint)pzVar4->manuf_code != CONCAT22(in_register_00002032,manuf_code)))))) {
        ppzVar2 = &pzVar4->next;
        pzVar3 = pzVar4->next;
      }
      if (ppzVar2 == (zcl_attr_desc_t **)0x0) {
        pzVar4 = (zcl_attr_desc_t *)0x0;
      }
      else {
        pzVar4 = *ppzVar2;
        if (pzVar4 != (zcl_attr_desc_t *)0x0) {
          *ppzVar2 = pzVar4->next;
          pzVar4->next = (zcl_attr_desc_s *)0x0;
        }
      }
    }
  }
  else {
    pzVar4 = (zcl_attr_desc_t *)0x0;
  }
  return pzVar4;
}

