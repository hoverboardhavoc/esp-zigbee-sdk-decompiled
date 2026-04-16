/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> level.o -> level_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t level_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t ep_id,void *value)

{
  ezb_zcl_status_t eVar1;
  undefined2 in_register_0000202a;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  byte bVar4;
  byte bVar5;
  
  if (CONCAT22(in_register_0000202a,attr_id) == 0) {
    pzVar2 = level_srv_get_attr_desc(ep_id,2);
    pzVar3 = level_srv_get_attr_desc(ep_id,3);
    if (pzVar2 == (zcl_attr_desc_t *)0x0) {
      bVar5 = 0;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      bVar5 = *pzVar2->data_p;
    }
    if (pzVar3 == (zcl_attr_desc_t *)0x0) {
      bVar4 = 0xff;
    }
    else {
                    /* WARNING: Load size is inaccurate */
      bVar4 = *pzVar3->data_p;
    }
                    /* WARNING: Load size is inaccurate */
    if (*value < bVar5) {
      eVar1 = 0x87;
    }
    else if (bVar4 < *value) {
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

