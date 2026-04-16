/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> custom.o -> ezb_zcl_custom_cluster_desc_add_manuf_attr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ezb_zcl_custom_cluster_desc_add_manuf_attr
                    (ezb_zcl_cluster_desc_t cluster_desc,uint16_t attr_id,uint8_t attr_type,
                    uint8_t attr_access,uint16_t manuf_code,void *value)

{
  undefined4 uVar1;
  ezb_err_t eVar2;
  undefined2 in_register_0000202e;
  undefined3 in_register_00002031;
  undefined3 in_register_00002035;
  undefined2 in_register_0000203a;
  
  if (cluster_desc == (ezb_zcl_cluster_desc_t)0x0) {
    eVar2 = 2;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    if (*cluster_desc < 0) {
      uVar1 = ezb_zcl_create_attr_desc
                        (CONCAT22(in_register_0000202e,attr_id),
                         CONCAT31(in_register_00002031,attr_type),
                         CONCAT31(in_register_00002035,attr_access),
                         CONCAT22(in_register_0000203a,manuf_code),value);
      eVar2 = ezb_zcl_cluster_add_attr_desc(cluster_desc,uVar1);
    }
    else {
      eVar2 = 2;
    }
  }
  return eVar2;
}

