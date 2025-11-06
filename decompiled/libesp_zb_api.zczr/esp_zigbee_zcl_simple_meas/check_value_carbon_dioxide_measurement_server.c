/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_carbon_dioxide_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_carbon_dioxide_measurement_server
              (uint param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  uVar2 = zb_zcl_attr_getsingle(param_3);
  if (3 < param_1) {
    return 0;
  }
  iVar3 = __unordsf2(uVar2);
  if (iVar3 != 0) {
    return 0;
  }
  if ((param_1 & 0xfffffffd) == 0) {
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x40d,1);
    uVar1 = **(undefined4 **)(iVar3 + 6);
    iVar3 = __unordsf2(uVar1,uVar1);
    if (iVar3 != 0) goto _L0;
  }
  else {
_L0:
    uVar1 = 0;
  }
  if (param_1 < 2) {
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x40d,2);
    uVar5 = **(undefined4 **)(iVar3 + 6);
    iVar3 = __unordsf2(uVar5,uVar5);
    if (iVar3 == 0) goto _L0;
  }
  uVar5 = 0x3f800000;
_L0:
  iVar3 = __lesf2(uVar1,uVar2);
  iVar4 = -1;
  if (iVar3 < 1) {
    iVar4 = __gesf2(uVar5,uVar2);
    iVar4 = iVar4 >> 0x1f;
  }
  return iVar4;
}

