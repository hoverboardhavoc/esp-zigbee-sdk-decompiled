/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> simple_measurement.o -> check_value_simple_f32_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
check_value_simple_f32_measurement_server
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 extraout_a1;
  undefined4 extraout_a1_00;
  undefined4 extraout_a1_01;
  undefined4 extraout_a1_02;
  undefined4 uVar5;
  undefined4 unaff_s8;
  
  uVar5 = *param_4;
  if (3 < param_2) {
    return 0;
  }
  if ((param_2 == 0) || (param_2 == 2)) {
    iVar2 = simple_measurement_srv_get_attr_desc(param_3,param_1,1);
    if ((iVar2 != 0) && (*(undefined4 **)(iVar2 + 8) != (undefined4 *)0x0)) {
      unaff_s8 = **(undefined4 **)(iVar2 + 8);
      uVar1 = __extendsfdf2(unaff_s8);
      uVar3 = __divdf3(0,0);
      iVar2 = __nedf2(uVar1,extraout_a1,uVar3,extraout_a1_00);
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
    if (1 < param_2) {
      uVar1 = 0x3f800000;
      goto _L0;
    }
  }
  iVar2 = simple_measurement_srv_get_attr_desc(param_3,param_1,2);
  if ((iVar2 == 0) || (*(undefined4 **)(iVar2 + 8) == (undefined4 *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/simple_measurement.c",
                  0xb9,"check_value_simple_f32_measurement_server",
                  "attr_desc != ((void *)0) && attr_desc->data_p != ((void *)0)");
    return 1;
  }
  uVar1 = **(undefined4 **)(iVar2 + 8);
  uVar3 = __extendsfdf2(uVar1);
  uVar4 = __divdf3(0,0);
  iVar2 = __nedf2(uVar3,extraout_a1_01,uVar4,extraout_a1_02);
  if (iVar2 == 0) {
    uVar1 = 0x3f800000;
  }
_L0:
  iVar2 = __lesf2(unaff_s8,uVar5);
  if (0 < iVar2) {
    return 1;
  }
  iVar2 = __gesf2(uVar1,uVar5);
  if (-1 < iVar2) {
    return 0;
  }
  return 1;
}

