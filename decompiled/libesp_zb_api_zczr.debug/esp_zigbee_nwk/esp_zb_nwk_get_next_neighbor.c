/*
 * Last changed at upstream commit 280ac146dc8285567eab4df113b3f6356493fe0b
 * https://github.com/espressif/esp-zigbee-sdk/commit/280ac146dc8285567eab4df113b3f6356493fe0b
 * Upstream date: 2024-07-19 11:49:15 +0800
 * Upstream subject: esp-zigbee-lib:(94bd7a1a)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_nwk.o -> esp_zb_nwk_get_next_neighbor
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_get_next_neighbor(ushort *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  byte *local_24 [4];
  
  local_24[0] = (byte *)0x0;
  if (param_2 == 0) {
    uVar2 = 0x102;
  }
  else {
    uVar1 = (uint)*param_1;
    if (uVar1 == 0xffff) {
      uVar2 = 0x105;
    }
    else {
      for (; uVar1 < _gc_neighbor_table_size; uVar1 = uVar1 + 1 & 0xffff) {
        iVar3 = zb_nwk_neighbor_get_by_idx(uVar1 & 0xff,local_24);
        if (((iVar3 == 0) && ((*local_24[0] & 2) == 0)) &&
           (((*local_24[0] & 0xc) == 8 || ((local_24[0][8] & 0x70) != 0)))) {
          *param_1 = (short)uVar1 + 1;
          esp_zb_populate_neighbor_info(param_2,local_24[0]);
          return 0;
        }
      }
      *param_1 = 0xffff;
      uVar2 = 0x105;
    }
  }
  return uVar2;
}

