/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_basic_value.o -> check_value_multi_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_multi_server(uint param_1,byte *param_2)

{
  bool bVar1;
  
  if (param_1 != 0x55) {
    if (0x55 < param_1) {
      if (param_1 != 0x6f) {
        return 0;
      }
      bVar1 = *param_2 < 0x10;
      goto _L0;
    }
    if (param_1 == 0x4a) {
      return -(uint)(*(short *)param_2 == 0);
    }
    if (param_1 != 0x51) {
      return 0;
    }
  }
  bVar1 = *param_2 < 2;
_L0:
  return bVar1 - 1;
}

