/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_esp_set_event
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_set_event(int param_1)

{
  ssize_t sVar1;
  int iStack_18;
  int iStack_14;
  
  iStack_14 = param_1 >> 0x1f;
  iStack_18 = param_1;
  sVar1 = write(param_1,&iStack_18,8);
  if (sVar1 != 8) {
    zb_esp_clr_event_part_0();
  }
  return;
}

