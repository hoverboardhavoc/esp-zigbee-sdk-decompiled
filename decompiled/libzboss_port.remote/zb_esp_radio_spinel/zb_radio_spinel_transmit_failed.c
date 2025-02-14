/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_radio_spinel.o -> zb_radio_spinel_transmit_failed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_radio_spinel_transmit_failed(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == 2) {
    param_1 = 1;
    iVar1 = param_1;
  }
  else if (param_1 == 3) {
    _zb_buf_begin_func = 4;
    param_1 = 1;
    iVar1 = _zb_buf_begin_func;
  }
  else {
    iVar1 = param_1;
    if (param_1 != 1) {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"ZB_ESP_SPINEL",&_LC1,uVar2,"ZB_ESP_SPINEL",param_1);
      DAT_00011001 = 1;
      _zb_buf_begin_func = 1;
      return;
    }
  }
  _zb_buf_begin_func = iVar1;
  DAT_00011001 = (char)param_1;
  return;
}

