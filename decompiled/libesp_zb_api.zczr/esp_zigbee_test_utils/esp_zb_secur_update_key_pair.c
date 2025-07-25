/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_test_utils.o -> esp_zb_secur_update_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_secur_update_key_pair(int param_1)

{
  int iVar1;
  
  iVar1 = zb_secur_update_key_pair
                    (param_1 + 8,*(undefined1 *)(param_1 + 0x18),*(undefined1 *)(param_1 + 0x19),
                     *(undefined1 *)(param_1 + 0x1a));
  return -(uint)(iVar1 != 0);
}

