/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr -> esp_zigbee_zcl_simple_meas.o -> check_value_temp_measurement_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_temp_measurement_server(uint param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = zb_zcl_attr_gets16(param_3);
  if (3 < param_1) {
    return 0;
  }
  if (param_1 == 3) {
    iVar2 = zb_zcl_attr_get16(param_3);
    if (iVar2 == 0xffff) {
      return 0;
    }
    if (-1 < iVar1) {
      return (iVar1 < 0x801) - 1;
    }
_L45:
    iVar1 = -1;
  }
  else {
    if (iVar1 == -0x8000) {
      return 0;
    }
    if ((param_1 & 0xfffffffd) == 0) {
      iVar2 = zb_zcl_get_attr_desc_a(param_2,0x402,1,1);
      iVar2 = (int)**(short **)(iVar2 + 6);
      if (iVar2 == -0x8000) {
        iVar2 = -0x6ab3;
      }
      if (param_1 != 2) goto _L0;
    }
    else {
      iVar2 = -0x6ab3;
_L0:
      iVar3 = zb_zcl_get_attr_desc_a(param_2,0x402,1,2);
      if (**(short **)(iVar3 + 6) != -0x8000) {
        if (iVar2 <= iVar1) {
          return -(uint)(**(short **)(iVar3 + 6) < iVar1);
        }
        goto _L45;
      }
    }
    iVar1 = -(uint)(iVar1 < iVar2);
  }
  return iVar1;
}

