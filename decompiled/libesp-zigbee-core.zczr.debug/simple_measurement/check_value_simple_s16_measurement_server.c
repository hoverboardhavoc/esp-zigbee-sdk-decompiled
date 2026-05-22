/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> check_value_simple_s16_measurement_server
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
  zcl_attr_desc_t *pzVar3;
  undefined2 in_register_0000202e;
  uint uVar4;
  uint16_t uVar5;
  uint16_t uVar6;
  
  uVar4 = CONCAT22(in_register_0000202e,attr_id);
  sVar1 = *(short *)value;
  if (3 < uVar4) {
    return '\0';
  }
  if (sVar1 == -0x8000) {
    return '\0';
  }
  if (uVar4 == 3) {
    uVar5 = (attr_limits->tolerance).min;
    uVar6 = (attr_limits->tolerance).max;
    goto _L0;
  }
  uVar5 = (attr_limits->measurement_value).min;
  uVar6 = (attr_limits->measurement_value).max;
  if ((uVar4 == 0) || (uVar4 == 2)) {
    pzVar3 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,1);
    if ((pzVar3 != (zcl_attr_desc_t *)0x0) && ((uint16_t *)pzVar3->data_p != (uint16_t *)0x0)) {
                    /* WARNING: Load size is inaccurate */
      uVar2 = *pzVar3->data_p;
      if (uVar2 != 0x8000) {
        uVar5 = uVar2;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0x91,"check_value_simple_s16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
  }
  else {
_L0:
    if (1 < uVar4) goto _L0;
  }
  pzVar3 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,2);
  if ((pzVar3 == (zcl_attr_desc_t *)0x0) || ((uint16_t *)pzVar3->data_p == (uint16_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0x99,"check_value_simple_s16_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
    return '\x01';
  }
                    /* WARNING: Load size is inaccurate */
  uVar2 = *pzVar3->data_p;
  if (uVar2 != 0x8000) {
    uVar6 = uVar2;
  }
_L0:
  if (sVar1 < (short)uVar5) {
    return '\x01';
  }
  if (sVar1 <= (short)uVar6) {
    return '\0';
  }
  return '\x01';
}

