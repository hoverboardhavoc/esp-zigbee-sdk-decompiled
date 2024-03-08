/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> zb_zed_config_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_zed_config_set(undefined1 *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  zb_set_ed_timeout(*param_1);
  uVar2 = *(uint *)(param_1 + 4) * 1000;
  uVar1 = uVar2 + 0x3bff;
  iVar3 = (uint)(uVar1 < uVar2) + (int)((ulonglong)*(uint *)(param_1 + 4) * 1000 >> 0x20);
  uVar2 = uVar1 + iVar3;
  uVar2 = uVar1 - (uVar2 + (uVar2 < uVar1)) % 0xf;
  zb_set_keepalive_timeout
            (uVar2 * -0x11111111 >> 10 |
             ((iVar3 - (uint)(uVar1 < uVar2)) * -0x11111111 + uVar2 * -0x11111112 +
             (int)((ulonglong)uVar2 * 0xeeeeeeef >> 0x20)) * 0x400000);
  if (*(int *)(param_1 + 4) != 0) {
    esp_zb_set_default_long_poll_interval();
  }
  zb_set_nvram_erase_at_start(0);
  return;
}

