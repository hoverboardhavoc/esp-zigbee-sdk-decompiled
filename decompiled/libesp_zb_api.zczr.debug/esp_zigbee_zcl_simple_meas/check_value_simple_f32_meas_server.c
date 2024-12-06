/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_zcl_simple_meas.o -> check_value_simple_f32_meas_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
check_value_simple_f32_meas_server
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = zb_zcl_attr_getsingle(param_4);
  if (param_2 < 4) {
    iVar3 = __unordsf2(uVar2);
    if (iVar3 == 0) {
      if ((param_2 == 0) || (param_2 == 2)) {
        iVar3 = zb_zcl_get_attr_desc_a(param_3,param_1,1,1);
        uVar4 = **(undefined4 **)(iVar3 + 6);
        iVar3 = __unordsf2(uVar4,uVar4);
        if (iVar3 != 0) {
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0;
      }
      if (param_2 < 2) {
        iVar3 = zb_zcl_get_attr_desc_a(param_3,param_1,1,2);
        uVar1 = **(undefined4 **)(iVar3 + 6);
        iVar3 = __unordsf2(uVar1,uVar1);
        if (iVar3 != 0) {
          uVar1 = 0x3f800000;
        }
      }
      else {
        uVar1 = 0x3f800000;
      }
      iVar3 = __lesf2(uVar4,uVar2);
      if (iVar3 < 1) {
        iVar3 = __gesf2(uVar1,uVar2);
        if (iVar3 < 0) {
          uVar2 = 0xffffffff;
        }
        else {
          uVar2 = 0;
        }
      }
      else {
        uVar2 = 0xffffffff;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

