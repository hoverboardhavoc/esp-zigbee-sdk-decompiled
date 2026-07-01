/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
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
    if (*pzVar2->data_p < uVar5) {
      return 0x87;
    }
                    /* WARNING: Load size is inaccurate */
    uVar4 = *pzVar3->data_p;
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

