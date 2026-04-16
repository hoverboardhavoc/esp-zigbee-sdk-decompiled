/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> simple_measurement.o -> check_value_simple_u16_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
check_value_simple_u16_measurement_server
          (uint16_t cluster_id,uint16_t attr_id,uint8_t endpoint,uint8_t *value,
          simple_measurement_ranges_t *attr_limits)

{
  ushort uVar1;
  uint16_t uVar2;
  ushort uVar3;
  bool bVar4;
  zcl_attr_desc_t *pzVar5;
  undefined2 in_register_0000202e;
  uint uVar6;
  uint16_t uVar7;
  uint16_t uVar8;
  
  uVar6 = CONCAT22(in_register_0000202e,attr_id);
  if (3 < uVar6) {
    return '\0';
  }
  uVar1 = *(ushort *)value;
  if (uVar1 == 0xffff) {
    bVar4 = false;
  }
  else {
    if (uVar6 == 3) {
      uVar8 = (attr_limits->tolerance).min;
      uVar7 = (attr_limits->tolerance).max;
    }
    else {
      uVar8 = (attr_limits->measurement_value).min;
      uVar7 = (attr_limits->measurement_value).max;
      if ((uVar6 & 0xfffffffd) != 0) goto _L0;
      pzVar5 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,1);
      if (pzVar5 != (zcl_attr_desc_t *)0x0) goto _L0;
      do {
        do {
          pzVar5 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L0:
        } while ((uint16_t *)pzVar5->data_p == (uint16_t *)0x0);
                    /* WARNING: Load size is inaccurate */
        uVar2 = *pzVar5->data_p;
        if (uVar2 != 0xffff) {
          uVar8 = uVar2;
        }
        if (uVar6 == 2) goto _L0;
_L0:
        pzVar5 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,2);
      } while ((pzVar5 == (zcl_attr_desc_t *)0x0) || ((ushort *)pzVar5->data_p == (ushort *)0x0));
                    /* WARNING: Load size is inaccurate */
      uVar3 = *pzVar5->data_p;
      if (uVar3 != 0xffff) {
        uVar7 = uVar3;
      }
    }
_L0:
    bVar4 = uVar1 < uVar8 || uVar7 < uVar1;
  }
  return bVar4;
}

