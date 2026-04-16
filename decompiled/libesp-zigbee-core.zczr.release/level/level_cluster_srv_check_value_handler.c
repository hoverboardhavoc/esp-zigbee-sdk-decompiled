/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> level.o -> level_cluster_srv_check_value_handler
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
  uint8_t min_level;
  byte bVar4;
  uint8_t max_level;
  byte bVar5;
  
  if (CONCAT22(in_register_0000202a,attr_id) != 0) {
    return '\0';
  }
  pzVar2 = level_srv_get_attr_desc(ep_id,2);
  pzVar3 = level_srv_get_attr_desc(ep_id,3);
  bVar4 = 0;
  if (pzVar2 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    bVar4 = *pzVar2->data_p;
  }
  bVar5 = 0xff;
  if (pzVar3 != (zcl_attr_desc_t *)0x0) {
                    /* WARNING: Load size is inaccurate */
    bVar5 = *pzVar3->data_p;
  }
                    /* WARNING: Load size is inaccurate */
  eVar1 = 0x87;
  if ((bVar4 <= *value) && (*value <= bVar5)) {
    eVar1 = '\0';
  }
  return eVar1;
}

