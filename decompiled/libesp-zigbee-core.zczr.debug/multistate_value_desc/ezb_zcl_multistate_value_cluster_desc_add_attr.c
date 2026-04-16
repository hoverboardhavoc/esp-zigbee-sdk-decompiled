/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> multistate_value_desc.o -> ezb_zcl_multistate_value_cluster_desc_add_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: attr_access */
/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_multistate_value_cluster_desc_add_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,void *value)

{
  ezb_err_t eVar1;
  undefined2 in_register_0000202e;
  uint8_t local_12;
  uint8_t local_11 [3];
  uint8_t attr_access;
  uint8_t attr_type;
  
  local_11[0] = 0xff;
  local_12 = '\0';
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    eVar1 = 2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*cluster_desc == 0x14) {
      eVar1 = zcl_multistate_value_cluster_get_attr_properties
                        ((ushort)*(byte *)((int)cluster_desc + 2),attr_id,local_11,&local_12);
      if (eVar1 == 0) {
        eVar1 = ezb_zcl_cluster_desc_add_manuf_attr
                          (cluster_desc,CONCAT22(in_register_0000202e,attr_id),local_11[0],local_12,
                           0,value);
      }
    }
    else {
      eVar1 = 2;
    }
  }
  return eVar1;
}

