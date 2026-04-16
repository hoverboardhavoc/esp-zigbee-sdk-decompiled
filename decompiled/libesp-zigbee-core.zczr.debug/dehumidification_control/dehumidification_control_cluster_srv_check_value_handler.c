/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> dehumidification_control.o -> dehumidification_control_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
dehumidification_control_cluster_srv_check_value_handler
          (uint16_t attr_id,uint8_t endpoint,void *value)

{
  bool bVar1;
  undefined2 in_register_0000202a;
  uint uVar2;
  zcl_attr_desc_t *pzVar3;
  
  uVar2 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar2 == 0x13) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = 0x12 < (byte)(*value - 2U);
  }
  else if (uVar2 < 0x14) {
    if (uVar2 == 1) {
      pzVar3 = dehumidification_control_srv_get_attr_desc(endpoint,0x14);
      if (pzVar3 == (zcl_attr_desc_t *)0x0) {
        bVar1 = false;
      }
      else if ((byte *)pzVar3->data_p == (byte *)0x0) {
        bVar1 = false;
      }
      else {
                    /* WARNING: Load size is inaccurate */
                    /* WARNING: Load size is inaccurate */
        bVar1 = *pzVar3->data_p < *value;
      }
    }
    else if (uVar2 == 0x10) {
                    /* WARNING: Load size is inaccurate */
      bVar1 = 0x46 < (byte)(*value - 0x1eU);
    }
    else {
      bVar1 = false;
    }
  }
  else if (uVar2 == 0x14) {
                    /* WARNING: Load size is inaccurate */
    bVar1 = 0x50 < (byte)(*value - 0x14U);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

