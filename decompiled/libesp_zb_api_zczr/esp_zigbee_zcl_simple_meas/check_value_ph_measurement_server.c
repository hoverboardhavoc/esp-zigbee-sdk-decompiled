/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_ph_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_ph_measurement_server(uint param_1,undefined4 param_2,undefined4 param_3)

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
    uVar1 = 200;
  }
  else {
    uVar4 = 0;
    uVar1 = 0x578;
    if ((param_1 & 0xfffffffd) == 0) {
      iVar3 = zb_zcl_get_attr_desc_a(param_2,0x409,1,1);
      uVar4 = (uint)**(ushort **)(iVar3 + 6);
      if (**(ushort **)(iVar3 + 6) == 0xffff) {
        uVar4 = 0;
      }
      if (param_1 == 2) goto _L0;
    }
    iVar3 = zb_zcl_get_attr_desc_a(param_2,0x409,1,2);
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

