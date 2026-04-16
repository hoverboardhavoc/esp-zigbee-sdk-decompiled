/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_zone.o -> ias_zone_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_zone_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t ep_id,void *value)

{
  ezb_zcl_status_t eVar1;
  undefined2 in_register_0000202a;
  ias_zone_srv_zone_ctx_t *piVar2;
  zcl_attr_desc_t *pzVar3;
  ezb_extaddr_t cie_ieee_addr;
  
  if (CONCAT22(in_register_0000202a,attr_id) == 0x10) {
    piVar2 = ias_zone_srv_get_zone_ctx(ep_id);
    if (piVar2->cie_ieee_addr_is_set == false) {
      eVar1 = '\0';
    }
    else {
      pzVar3 = ias_zone_srv_get_attr_desc(ep_id,0x10);
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
      if ((*value == *pzVar3->data_p) &&
         (*(int *)((int)value + 4) == *(int *)((int)pzVar3->data_p + 4))) {
        eVar1 = '~';
      }
      else {
        eVar1 = '\0';
      }
    }
  }
  else if (CONCAT22(in_register_0000202a,attr_id) == 0x13) {
                    /* WARNING: Load size is inaccurate */
    if (*value < 2) {
      eVar1 = 0x87;
    }
    else {
      eVar1 = '\0';
    }
  }
  else {
    eVar1 = '\0';
  }
  return eVar1;
}

