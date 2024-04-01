/*
 * Last changed at upstream commit 3128a1de3a8a176dac99e12775a60287e9d10fd7
 * https://github.com/espressif/esp-zigbee-sdk/commit/3128a1de3a8a176dac99e12775a60287e9d10fd7
 * Upstream date: 2024-04-01 17:59:07 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.2(4a0e02cc)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zed_config_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zed_config_set(undefined1 *param_1)

{
  uint uVar1;
  
  zb_set_ed_timeout(*param_1);
  uVar1 = *(uint *)(param_1 + 4) * 1000;
  __udivdi3((uint)(uVar1 + 0x3bff < uVar1) + (int)((ulonglong)*(uint *)(param_1 + 4) * 1000 >> 0x20)
            ,0x3c00,0);
  zb_set_keepalive_timeout();
  if (*(int *)(param_1 + 4) != 0) {
    esp_zb_set_default_long_poll_interval();
  }
  zb_set_nvram_erase_at_start(0);
  return;
}

