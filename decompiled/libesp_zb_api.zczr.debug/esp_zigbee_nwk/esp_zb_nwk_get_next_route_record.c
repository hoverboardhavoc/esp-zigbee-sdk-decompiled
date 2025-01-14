/*
 * Last changed at upstream commit 5becf8b58fd0c6a13fec507be821364ad0ceba39
 * https://github.com/espressif/esp-zigbee-sdk/commit/5becf8b58fd0c6a13fec507be821364ad0ceba39
 * Upstream date: 2025-01-14 03:03:09 +0000
 * Upstream subject: esp-zigbee-sdk: (acad93d1)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_route_record
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_route_record(ushort *param_1,int param_2)

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
      for (; uVar2 < gc_nwk_max_source_routes; uVar2 = uVar2 + 1 & 0xffff) {
        if ((*(byte *)(_DAT_000112a8 + uVar2 * 0xe) & 1) != 0) {
          *param_1 = (short)uVar2 + 1;
          esp_zb_populate_route_record_info(param_2);
          return 0;
        }
      }
      *param_1 = 0xffff;
      uVar1 = 0x105;
    }
  }
  return uVar1;
}

