/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_wind_speed_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_wind_speed_measurement_server(uint param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = zb_zcl_attr_get16(param_3);
  if (3 < param_1) {
    return 0;
  }
  if (uVar2 == 0xffff) {
    return 0;
  }
  if (param_1 == 3) {
    uVar4 = 0;
    uVar1 = 0x308;
  }
  else {
    uVar4 = 0;
    uVar1 = 0xfffe;
    if ((param_1 & 0xfffffffd) == 0) {
      iVar3 = zb_zcl_get_attr_desc_a(param_2,0x40b,1);
      if (**(ushort **)(iVar3 + 6) != 0xffff) {
        uVar4 = (uint)**(ushort **)(iVar3 + 6);
      }
      if (param_1 == 2) goto _L0;
    }
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x40b,1,2);
    if (**(ushort **)(iVar3 + 6) != 0xffff) {
      uVar1 = (uint)**(ushort **)(iVar3 + 6);
    }
  }
_L0:
  iVar3 = -1;
  if (uVar4 <= uVar2) {
    iVar3 = -(uint)(uVar1 < uVar2);
  }
  return iVar3;
}

