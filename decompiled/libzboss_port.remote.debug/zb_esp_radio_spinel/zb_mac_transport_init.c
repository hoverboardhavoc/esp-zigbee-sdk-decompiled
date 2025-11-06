/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> zb_mac_transport_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_mac_transport_init(void)

{
  int iVar1;
  undefined4 uVar2;
  code *local_50;
  code *pcStack_4c;
  code *pcStack_48;
  code *pcStack_44;
  code *pcStack_40;
  undefined4 uStack_3c;
  undefined1 auStack_30 [8];
  code *pcStack_28;
  code *pcStack_24;
  code *pcStack_20;
  code *pcStack_1c;
  code *pcStack_18;
  undefined4 uStack_14;
  
  iVar1 = esp_zb_platform_config_get();
  pcStack_1c = zb_radio_spinel_energy_scan_done;
  pcStack_28 = zb_radio_spinel_receive_done;
  pcStack_24 = zb_radio_spinel_transmit_done;
  pcStack_20 = zb_radio_spinel_transmit_failed;
  pcStack_18 = zb_radio_spinel_tx_started;
  local_50 = zb_radio_spinel_receive_done;
  pcStack_4c = zb_radio_spinel_transmit_done;
  pcStack_48 = zb_radio_spinel_transmit_failed;
  pcStack_44 = zb_radio_spinel_energy_scan_done;
  pcStack_40 = zb_radio_spinel_tx_started;
  uStack_3c = uStack_14;
  esp_radio_spinel_set_callbacks(&local_50,0);
  esp_zb_radio_spinel_config_uart(iVar1 + 4);
  esp_radio_spinel_init(0);
  esp_radio_spinel_enable(0);
  esp_radio_spinel_set_pending_mode(3,0);
  zb_read_mac(auStack_30);
  zb_set_long_address(auStack_30);
  iVar1 = zb_esp_workflow_register(zb_esp_radio_update,zb_esp_radio_process,"radio");
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log(3,"ZB_ESP_SPINEL","I (%lu) %s: Radio spinel workflow register successfully\n",uVar2,
            "ZB_ESP_SPINEL");
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log(1,"ZB_ESP_SPINEL","E (%lu) %s: Radio spinel workflow register failed\n",uVar2,
            "ZB_ESP_SPINEL");
  }
  return;
}

