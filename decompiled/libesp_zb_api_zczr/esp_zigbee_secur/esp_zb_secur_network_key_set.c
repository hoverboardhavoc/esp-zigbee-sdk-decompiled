/*
 * Last changed at upstream commit f1369f27c0afa51d13986c066b316e6812865b18
 * https://github.com/espressif/esp-zigbee-sdk/commit/f1369f27c0afa51d13986c066b316e6812865b18
 * Upstream date: 2023-10-23 12:06:56 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.0.1(00d5cde0)
 * Source: libesp_zb_api_zczr -> esp_zigbee_secur.o -> esp_zb_secur_network_key_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_secur_network_key_set(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x103;
  }
  else {
    zb_secur_setup_nwk_key(0);
    uVar1 = 0;
  }
  return uVar1;
}

