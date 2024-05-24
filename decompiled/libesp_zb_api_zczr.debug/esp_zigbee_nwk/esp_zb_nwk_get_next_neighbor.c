/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_neighbor(ushort *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  byte *local_24 [4];
  
  local_24[0] = (byte *)0x0;
  uVar1 = (uint)*param_1;
  if (uVar1 != 0xffff) {
    for (; uVar1 < _gc_neighbor_table_size; uVar1 = uVar1 + 1 & 0xffff) {
      iVar2 = zb_nwk_neighbor_get_by_idx(uVar1 & 0xff,local_24);
      if (((iVar2 == 0) && ((*local_24[0] & 2) == 0)) &&
         (((*local_24[0] & 0xc) == 8 || ((local_24[0][8] & 0x70) != 0)))) {
        *param_1 = (short)uVar1 + 1;
        esp_zb_set_neighbor_info(param_2,local_24[0]);
        return 0;
      }
    }
    *param_1 = 0xffff;
  }
  return 0x105;
}

