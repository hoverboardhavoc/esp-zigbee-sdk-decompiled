/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr -> esp_zigbee_zcl_basic_value.o -> check_value_multi_server
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int check_value_multi_server(int param_1,byte *param_2)

{
  bool bVar1;
  
  if (param_1 == 0x51) {
    bVar1 = *param_2 < 2;
  }
  else {
    if (param_1 != 0x6f) {
      if (param_1 != 0x4a) {
        return 0;
      }
      return -(uint)(*(short *)param_2 == 0);
    }
    bVar1 = *param_2 < 0x10;
  }
  return bVar1 - 1;
}

