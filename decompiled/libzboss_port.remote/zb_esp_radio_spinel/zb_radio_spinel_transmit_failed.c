/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_radio_spinel_transmit_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_radio_spinel_transmit_failed(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 2) {
    if (param_1 == 3) {
      DAT_00011001 = 1;
      _zb_buf_begin_func = 4;
      return;
    }
    if (param_1 == 1) {
      DAT_00011001 = 1;
      _zb_buf_begin_func = 1;
      return;
    }
    uVar1 = esp_log_timestamp();
    esp_log(1,"ZB_ESP_SPINEL","E (%lu) %s: unsupported tx error: %d\n",uVar1,"ZB_ESP_SPINEL",param_1
           );
  }
  _zb_buf_begin_func = 1;
  DAT_00011001 = 1;
  return;
}

