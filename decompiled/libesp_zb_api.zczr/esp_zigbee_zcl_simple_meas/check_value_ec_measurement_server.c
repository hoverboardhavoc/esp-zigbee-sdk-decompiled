/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_ec_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_ec_measurement_server(uint param_1,undefined4 param_2,undefined4 param_3)

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
    uVar1 = 100;
  }
  else {
    uVar4 = 0;
    uVar1 = 0xfffe;
    if ((param_1 & 0xfffffffd) == 0) {
      iVar3 = zb_zcl_get_attr_desc_a(param_2,0x40a,1,1);
      if (**(ushort **)(iVar3 + 6) != 0xffff) {
        uVar4 = (uint)**(ushort **)(iVar3 + 6);
      }
      if (param_1 == 2) goto _L0;
    }
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x40a,1,2);
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

