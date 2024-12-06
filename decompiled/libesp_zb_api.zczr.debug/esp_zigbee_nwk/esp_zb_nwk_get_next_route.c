/*
 * Last changed at upstream commit 0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * https://github.com/espressif/esp-zigbee-sdk/commit/0bff9367811bb8cb2d99200afddf6ceefe2628f8
 * Upstream date: 2024-12-06 13:11:49 +0800
 * Upstream subject: esp-zigbee-sdk: (e9475ff2)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_route(ushort *param_1,int param_2)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    uVar1 = 0x102;
  }
  else {
    uVar2 = (uint)*param_1;
    if (uVar2 == 0xffff) {
      uVar1 = 0x105;
    }
    else {
      for (; uVar2 < _gc_routing_table_size; uVar2 = uVar2 + 1 & 0xffff) {
        if ((*(byte *)(_DAT_0001123c + uVar2 * 5) & 1) != 0) {
          *param_1 = (short)uVar2 + 1;
          esp_zb_populate_route_info(param_2);
          return 0;
        }
      }
      *param_1 = 0xffff;
      uVar1 = 0x105;
    }
  }
  return uVar1;
}

