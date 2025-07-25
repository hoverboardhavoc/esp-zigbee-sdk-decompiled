/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_test_utils.o -> esp_zb_nwk_set_short_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zb_nwk_set_short_address(undefined2 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = zb_zdo_joined();
  if (iVar1 == 0) {
    uVar2 = 0;
    _g_zb = param_1;
  }
  else {
    uVar2 = 0x103;
  }
  return uVar2;
}

