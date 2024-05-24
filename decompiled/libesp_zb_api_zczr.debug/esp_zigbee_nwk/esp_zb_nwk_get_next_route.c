/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_route(ushort *param_1,undefined4 param_2)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1;
  if (uVar1 == 0xffff) {
    return 0x105;
  }
  while( true ) {
    if (_gc_routing_table_size <= uVar1) {
      *param_1 = 0xffff;
      return 0x105;
    }
    if ((*(byte *)(_DAT_0001123c + uVar1 * 5) & 1) != 0) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  *param_1 = (short)uVar1 + 1;
  esp_zb_set_route_info(param_2);
  return 0;
}

