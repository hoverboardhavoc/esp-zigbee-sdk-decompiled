/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> simple_measurement.o -> check_value_simple_s16_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
check_value_simple_s16_measurement_server
          (uint16_t cluster_id,uint16_t attr_id,uint8_t endpoint,uint8_t *value,
          simple_measurement_ranges_t *attr_limits)

{
  short sVar1;
  uint16_t uVar2;
  bool bVar3;
  zcl_attr_desc_t *pzVar4;
  undefined2 in_register_0000202e;
  uint uVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  
  uVar5 = CONCAT22(in_register_0000202e,attr_id);
  if (3 < uVar5) {
    return '\0';
  }
  sVar1 = *(short *)value;
  if (sVar1 == -0x8000) {
    bVar3 = false;
  }
  else {
    if (uVar5 == 3) {
      uVar7 = (attr_limits->tolerance).min;
      uVar6 = (attr_limits->tolerance).max;
    }
    else {
      uVar7 = (attr_limits->measurement_value).min;
      uVar6 = (attr_limits->measurement_value).max;
      if ((uVar5 & 0xfffffffd) != 0) goto _L0;
      pzVar4 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,1);
      if (pzVar4 != (zcl_attr_desc_t *)0x0) goto _L0;
      do {
        do {
          pzVar4 = (zcl_attr_desc_t *)__assert_func(0,0,0,0);
_L0:
        } while ((uint16_t *)pzVar4->data_p == (uint16_t *)0x0);
                    /* WARNING: Load size is inaccurate */
        uVar2 = *pzVar4->data_p;
        if (uVar2 != 0x8000) {
          uVar7 = uVar2;
        }
        if (uVar5 == 2) goto _L0;
_L0:
        pzVar4 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,2);
      } while ((pzVar4 == (zcl_attr_desc_t *)0x0) || ((uint16_t *)pzVar4->data_p == (uint16_t *)0x0)
              );
                    /* WARNING: Load size is inaccurate */
      uVar2 = *pzVar4->data_p;
      if (uVar2 != 0x8000) {
        uVar6 = uVar2;
      }
    }
_L0:
    bVar3 = sVar1 < (short)uVar7 || (short)uVar6 < sVar1;
  }
  return bVar3;
}

