/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libzboss_port.remote -> zb_esp_osif.o -> zb_esp_clr_event.part.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zb_esp_clr_event_part_0(void)

{
  code *pcVar1;
  ssize_t sVar2;
  int iStack_28;
  int iStack_24;
  code *pcStack_14;
  
  pcVar1 = zb_esp_set_event;
  iStack_28 = __assert_func(0,0,0,0);
  iStack_24 = iStack_28 >> 0x1f;
  pcStack_14 = pcVar1;
  sVar2 = write(iStack_28,&iStack_28,8);
  if (sVar2 != 8) {
    zb_esp_clr_event_part_0();
  }
  return;
}

