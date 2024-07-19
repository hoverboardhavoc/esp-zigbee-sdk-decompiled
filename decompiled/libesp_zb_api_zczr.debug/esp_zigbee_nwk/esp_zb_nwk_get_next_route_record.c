/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_route_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_route_record(ushort *param_1,int param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    return 0x102;
  }
  uVar1 = (uint)*param_1;
  if (uVar1 != 0xffff) {
    while( true ) {
      if (gc_nwk_max_source_routes <= uVar1) {
        *param_1 = 0xffff;
        return 0x105;
      }
      if ((*(byte *)(_DAT_000112ac + uVar1 * 0xe) & 1) != 0) break;
      uVar1 = uVar1 + 1 & 0xffff;
    }
    *param_1 = (short)uVar1 + 1;
    esp_zb_populate_route_record_info(param_2);
    return 0;
  }
  return 0x105;
}

