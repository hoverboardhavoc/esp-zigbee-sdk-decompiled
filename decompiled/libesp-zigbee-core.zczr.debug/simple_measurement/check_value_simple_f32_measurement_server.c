/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> check_value_simple_f32_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: ret */
/* WARNING: Unknown calling convention */

ezb_zcl_status_t
check_value_simple_f32_measurement_server
          (uint16_t cluster_id,uint16_t attr_id,uint8_t endpoint,uint8_t *value)

{
  undefined4 uVar1;
  int iVar2;
  zcl_attr_desc_t *pzVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 in_register_0000202e;
  uint uVar6;
  undefined4 extraout_a1;
  undefined4 extraout_a1_00;
  undefined4 extraout_a1_01;
  undefined4 extraout_a1_02;
  undefined4 uVar7;
  undefined4 unaff_s8;
  float ret;
  
  uVar6 = CONCAT22(in_register_0000202e,attr_id);
  uVar7 = *(undefined4 *)value;
  if (3 < uVar6) {
    return '\0';
  }
  if ((uVar6 == 0) || (uVar6 == 2)) {
    pzVar3 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,1);
    if ((pzVar3 != (zcl_attr_desc_t *)0x0) && ((undefined4 *)pzVar3->data_p != (undefined4 *)0x0)) {
                    /* WARNING: Load size is inaccurate */
      unaff_s8 = *pzVar3->data_p;
      uVar1 = __extendsfdf2(unaff_s8);
      uVar4 = __divdf3(0,0);
      iVar2 = __nedf2(uVar1,extraout_a1,uVar4,extraout_a1_00);
      if (iVar2 == 0) {
        unaff_s8 = 0;
      }
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0xb2,"check_value_simple_f32_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
  }
  else {
    unaff_s8 = 0;
_L0:
    if (1 < uVar6) {
      uVar1 = 0x3f800000;
      goto _L0;
    }
  }
  pzVar3 = simple_measurement_srv_get_attr_desc(endpoint,cluster_id,2);
  if ((pzVar3 == (zcl_attr_desc_t *)0x0) || ((undefined4 *)pzVar3->data_p == (undefined4 *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0xb9,"check_value_simple_f32_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
    return '\x01';
  }
                    /* WARNING: Load size is inaccurate */
  uVar1 = *pzVar3->data_p;
  uVar4 = __extendsfdf2(uVar1);
  uVar5 = __divdf3(0,0);
  iVar2 = __nedf2(uVar4,extraout_a1_01,uVar5,extraout_a1_02);
  if (iVar2 == 0) {
    uVar1 = 0x3f800000;
  }
_L0:
  iVar2 = __lesf2(unaff_s8,uVar7);
  if (0 < iVar2) {
    return '\x01';
  }
  iVar2 = __gesf2(uVar1,uVar7);
  if (-1 < iVar2) {
    return '\0';
  }
  return '\x01';
}

