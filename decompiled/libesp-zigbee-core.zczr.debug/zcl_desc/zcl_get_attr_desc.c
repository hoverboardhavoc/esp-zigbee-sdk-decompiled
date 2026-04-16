/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_desc.o -> zcl_get_attr_desc
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zcl_attr_desc_t *
zcl_get_attr_desc(uint8_t ep_id,uint16_t cluster_id,uint8_t role,uint16_t attr_id,
                 uint16_t manuf_code)

{
  zcl_cluster_desc_t *pzVar1;
  undefined2 in_register_00002036;
  undefined2 in_register_0000203a;
  
  pzVar1 = zcl_get_cluster_desc(ep_id,cluster_id,role);
  if (pzVar1 != (zcl_cluster_desc_t *)0x0) {
    for (pzVar1 = (zcl_cluster_desc_t *)pzVar1->attr_list;
        (pzVar1 != (zcl_cluster_desc_t *)0x0 &&
        (((uint)pzVar1->cluster_id != CONCAT22(in_register_00002036,attr_id) ||
         ((CONCAT22(in_register_0000203a,manuf_code) != 0 &&
          (((pzVar1->field_0x3 & 0x20) == 0 ||
           ((uint)pzVar1->manuf_code != CONCAT22(in_register_0000203a,manuf_code)))))))));
        pzVar1 = (zcl_cluster_desc_t *)pzVar1->attr_list) {
    }
  }
  return (zcl_attr_desc_t *)pzVar1;
}

