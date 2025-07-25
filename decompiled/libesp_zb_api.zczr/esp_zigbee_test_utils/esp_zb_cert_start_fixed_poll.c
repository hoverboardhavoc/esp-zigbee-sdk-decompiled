/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_test_utils.o -> esp_zb_cert_start_fixed_poll
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_cert_start_fixed_poll(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  DAT_00011501 = DAT_00011501 & 0xfb;
  zb_zdo_pim_stop_poll(0);
  zb_zdo_pim_set_long_poll_interval(param_1,param_2);
  zb_zdo_pim_permit_turbo_poll(param_3);
  zb_zdo_pim_start_poll(0);
  return 0;
}

