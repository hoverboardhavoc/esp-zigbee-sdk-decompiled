/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_mac_transport_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_mac_transport_init(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_50 [32];
  undefined1 auStack_30 [8];
  code *pcStack_28;
  code *pcStack_24;
  code *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  
  iVar1 = esp_zb_platform_config_get();
  uStack_1c = 0x10000;
  pcStack_28 = zb_radio_spinel_receive_done;
  pcStack_24 = zb_radio_spinel_transmit_done;
  pcStack_20 = zb_radio_spinel_transmit_failed;
  pcStack_18 = zb_radio_spinel_tx_started;
  memcpy(auStack_50,&pcStack_28,0x18);
  esp_radio_spinel_set_callbacks(auStack_50,0);
  esp_zb_radio_spinel_config_uart(iVar1 + 4);
  esp_radio_spinel_init(0);
  esp_radio_spinel_enable(0);
  esp_radio_spinel_set_pending_mode(3,0);
  zb_read_mac(auStack_30);
  zb_set_long_address(auStack_30);
  iVar1 = zb_esp_workflow_register(zb_esp_radio_update,zb_esp_radio_process,"radio");
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ZB_ESP_SPINEL",&_LC3,uVar2,"ZB_ESP_SPINEL");
  }
  return;
}

