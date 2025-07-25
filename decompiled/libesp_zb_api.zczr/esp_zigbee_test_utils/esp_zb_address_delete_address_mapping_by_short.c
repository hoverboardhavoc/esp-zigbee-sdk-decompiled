/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_test_utils.o -> esp_zb_address_delete_address_mapping_by_short
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_address_delete_address_mapping_by_short(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 auStack_11 [9];
  
  iVar2 = zb_address_by_short(0,0,auStack_11);
  uVar1 = 0xffffffff;
  if (iVar2 == 0) {
    zb_address_delete(auStack_11[0]);
    uVar1 = 0;
  }
  return uVar1;
}

