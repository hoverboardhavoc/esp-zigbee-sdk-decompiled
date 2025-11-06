/*
 * Last changed at upstream commit ef60059b4d605d61a0103f81567229692f238007
 * https://github.com/espressif/esp-zigbee-sdk/commit/ef60059b4d605d61a0103f81567229692f238007
 * Upstream date: 2025-11-06 11:58:56 +0800
 * Upstream subject: esp-zigbee-sdk: (79cb709a)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> zb_radio_spinel_transmit_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void zb_radio_spinel_transmit_done(int param_1,int param_2)

{
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zboss/components/zboss_port/src/zb_esp_radio_spinel.c"
                  ,0x92,"zb_radio_spinel_transmit_done","frame != NULL");
  }
  else {
    DAT_00011001 = 1;
    _esp_log = 0;
    if ((*(byte *)(param_1 + 1) & 0x20) == 0) {
      DAT_00011001 = 1;
      _esp_log = 0;
      return;
    }
    if (param_2 == 0) {
      DAT_00011001 = 1;
      _esp_log = 0;
      return;
    }
    if ((*(byte *)(param_2 + 1) & 0x10) != 0) {
      DAT_00011001 = 1;
      _esp_log = 0;
      _memcpy = 3;
      return;
    }
  }
  _memcpy = 1;
  return;
}

