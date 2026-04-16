/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> check_value_simple_u16_measurement_server
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
  zcl_attr_desc_t *pzVar4;
  undefined2 in_register_0000202e;
  uint uVar5;
  uint16_t uVar6;
  uint16_t uVar7;
  
  uVar5 = CONCAT22(in_register_0000202e,attr_id);
  uVar1 = *(ushort *)value;
  if (3 < uVar5) {
    return '\0';
  }
  if (uVar1 == 0xffff) {
    return '\0';
  }
  if (uVar5 == 3) {
    uVar6 = (attr_limits->tolerance).min;
    uVar7 = (attr_limits->tolerance).max;
    goto _L0;
  }
  uVar6 = (attr_limits->measurement_value).min;
  uVar7 = (attr_limits->measurement_value).max;
  if ((uVar5 == 0) || (uVar5 == 2)) {
    pzVar4 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,1);
    if ((pzVar4 != (zcl_attr_desc_t *)0x0) && ((uint16_t *)pzVar4->data_p != (uint16_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *pzVar4->data_p;
      if (uVar2 != 0xffff) {
        uVar6 = uVar2;
      }
      goto _L0;
    }
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",0x68,
                  "check_value_simple_u16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
  }
  else {
_L0:
    if (1 < uVar5) goto _L0;
  }
  pzVar4 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,2);
  if ((pzVar4 == (zcl_attr_desc_t *)0x0) || ((ushort *)pzVar4->data_p == (ushort *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",0x70,
                  "check_value_simple_u16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
    return '\x01';
  }
                    /* WARNING: Load size is inaccurate */
  uVar3 = *pzVar4->data_p;
  if (uVar3 != 0xffff) {
    uVar7 = uVar3;
  }
_L0:
  if (uVar1 < uVar6) {
    return '\x01';
  }
  if (uVar1 <= uVar7) {
    return '\0';
  }
  return '\x01';
}

