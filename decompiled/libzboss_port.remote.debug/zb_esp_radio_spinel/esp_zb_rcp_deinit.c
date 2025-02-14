/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> esp_zb_rcp_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_rcp_deinit(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = esp_radio_spinel_rcp_deinit(0);
  if (iVar1 == 0) {
    zb_esp_workflow_unregister("radio");
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"ZB_ESP_SPINEL",&_LC11,uVar2,"ZB_ESP_SPINEL","esp_zb_rcp_deinit",0x1b5);
  }
  return iVar1;
}

