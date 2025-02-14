/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote.debug -> zb_esp_radio_spinel.o -> mac_esp_get_received_data_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_esp_get_received_data_status(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_28 [20];
  byte bStack_14;
  
  iVar1 = zb_parse_mhr_ptr(auStack_28,param_1);
  if ((bStack_14 & 7) == 3) {
    if (*(char *)(param_1 + iVar1) == '\x04') {
      if (param_2 == 0) {
        uVar2 = 0xeb;
      }
      else {
        uVar2 = 0;
      }
    }
    else {
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}

