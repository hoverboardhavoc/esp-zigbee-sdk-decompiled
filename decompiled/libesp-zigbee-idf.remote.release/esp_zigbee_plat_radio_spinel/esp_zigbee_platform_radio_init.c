/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-idf.remote.release -> esp_zigbee_plat_radio_spinel.o -> esp_zigbee_platform_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 esp_zigbee_platform_radio_init(int *param_1)

{
  undefined4 uVar1;
  undefined1 auStack_50 [40];
  code *pcStack_28;
  code *pcStack_24;
  code *pcStack_20;
  code *pcStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  if (*param_1 != 1) {
    param_1 = (int *)__assert_func(0,0,0,0);
  }
  if ((_DAT_00010608 & 1) == 0) {
    memset(&s_radio_ctx,0,0xb0);
    DAT_000105d8 = &s_radio_ctx;
    _DAT_00010608 = _DAT_00010608 | 1;
    pcStack_28 = radio_spinel_receive_done;
    pcStack_24 = radio_spinel_transmit_done;
    pcStack_20 = radio_spinel_transmit_failed;
    pcStack_1c = radio_spinel_energy_detect_done;
    pcStack_18 = radio_spinel_transmit_started;
    uStack_14 = 0;
    memcpy(auStack_50,&pcStack_28,0x18);
    esp_radio_spinel_set_callbacks(auStack_50,0);
    esp_zigbee_radio_spinel_config_uart(param_1 + 1);
    esp_radio_spinel_init(0);
    esp_radio_spinel_enable(0);
    _DAT_00010608 = _DAT_00010608 & 0xfffffffd;
    esp_radio_spinel_set_promiscuous_mode(0,0);
    esp_radio_spinel_set_pending_mode(0,0);
    esp_radio_spinel_sleep(0);
    uVar1 = esp_zigbee_platform_workflow_register("radio",esp_zigbee_platform_radio_update,0x10000);
    return uVar1;
  }
  return 0x103;
}

