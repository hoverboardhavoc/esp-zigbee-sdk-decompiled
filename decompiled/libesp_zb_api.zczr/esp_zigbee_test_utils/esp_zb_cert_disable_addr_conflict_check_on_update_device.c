/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_test_utils.o -> esp_zb_cert_disable_addr_conflict_check_on_update_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cert_disable_addr_conflict_check_on_update_device(uint param_1)

{
  byte bVar1;
  
  bVar1 = (byte)((param_1 & 1) << 3);
  DAT_00010dfc = DAT_00010dfc & 0xf7 | bVar1;
  DAT_00010dfa = bVar1 | DAT_00010dfa & 0xf7;
  return 0;
}

