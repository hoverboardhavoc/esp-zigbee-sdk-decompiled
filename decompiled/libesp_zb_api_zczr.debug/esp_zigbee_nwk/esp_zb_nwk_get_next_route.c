/*
 * Last changed at upstream commit b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * https://github.com/espressif/esp-zigbee-sdk/commit/b16fd900dd0b442e8e677ff001b10a2e9e95729b
 * Upstream date: 2024-11-01 15:37:53 +0800
 * Upstream subject: esp-zigbee-lib:(4f5d21fb)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_route
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

