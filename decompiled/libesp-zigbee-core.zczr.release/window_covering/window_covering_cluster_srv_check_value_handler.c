/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> window_covering.o -> window_covering_cluster_srv_check_value_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
window_covering_cluster_srv_check_value_handler(uint16_t attr_id,uint8_t endpoint,void *value)

{
  undefined2 in_register_0000202a;
  uint uVar1;
  zcl_attr_desc_t *pzVar2;
  zcl_attr_desc_t *pzVar3;
  uint16_t attr_id_00;
  ushort uVar4;
  ushort uVar5;
  
  uVar1 = CONCAT22(in_register_0000202a,attr_id);
  if (uVar1 == 7) {
                    /* WARNING: Load size is inaccurate */
    if (-1 < *value) {
      return '\0';
    }
    return 0x87;
  }
  if (uVar1 < 8) {
    if (uVar1 == 3) {
      pzVar3 = window_covering_srv_get_attr_desc(endpoint,0x10);
      attr_id_00 = 0x11;
    }
    else {
      if (uVar1 != 4) {
        if (uVar1 != 0) {
          return '\0';
        }
                    /* WARNING: Load size is inaccurate */
        uVar4 = (ushort)*value;
        uVar5 = 9;
        goto _L44;
      }
      pzVar3 = window_covering_srv_get_attr_desc(endpoint,0x12);
      attr_id_00 = 0x13;
    }
    pzVar2 = window_covering_srv_get_attr_desc(endpoint,attr_id_00);
    if ((((pzVar3 == (zcl_attr_desc_t *)0x0) || ((ushort *)pzVar3->data_p == (ushort *)0x0)) ||
        (pzVar2 == (zcl_attr_desc_t *)0x0)) || ((ushort *)pzVar2->data_p == (ushort *)0x0)) {
      return 0x8b;
    }
                    /* WARNING: Load size is inaccurate */
    uVar5 = *value;
                    /* WARNING: Load size is inaccurate */
    if (*pzVar3->data_p < uVar5) {
      return 0x87;
    }
                    /* WARNING: Load size is inaccurate */
    uVar4 = *pzVar2->data_p;
  }
  else {
    if (1 < (uVar1 - 8 & 0xffff)) {
      return '\0';
    }
                    /* WARNING: Load size is inaccurate */
    uVar4 = (ushort)*value;
    uVar5 = 100;
  }
_L44:
  if (uVar5 < uVar4) {
    return 0x87;
  }
  return '\0';
}

