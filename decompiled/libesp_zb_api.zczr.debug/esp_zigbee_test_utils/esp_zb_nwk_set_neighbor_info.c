/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_test_utils.o -> esp_zb_nwk_set_neighbor_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_nwk_set_neighbor_info(uint param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_14;
  
  iVar1 = zb_nwk_neighbor_get_by_short(&iStack_14);
  if (iVar1 == 0) {
    if (iStack_14 == 0) {
      uVar2 = 0xffffffff;
    }
    else {
      *(byte *)(iStack_14 + 8) = *(byte *)(iStack_14 + 8) & 0x7f | (byte)((param_1 & 1) << 7);
      *(byte *)(iStack_14 + 9) = *(byte *)(iStack_14 + 9) & 0xf0 | (byte)(param_1 >> 1) & 0xf;
      *(byte *)(iStack_14 + 8) = *(byte *)(iStack_14 + 8) & 0x8f | (byte)((param_2 & 7) << 4);
      *(char *)(iStack_14 + 4) = (char)((7U - param_3 & 0xff) << 5);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffff;
  }
  return uVar2;
}

