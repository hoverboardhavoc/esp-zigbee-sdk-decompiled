/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
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
    esp_log(1,"ZB_ESP_SPINEL","E (%lu) %s: %s(%d): Fail to deinit rcp\n",uVar2,"ZB_ESP_SPINEL",
            "esp_zb_rcp_deinit",0x1b5);
  }
  return iVar1;
}

