/*
 * Last changed at upstream commit e883f431f54d7744605c05ac3bc92898d04315c0
 * https://github.com/espressif/esp-zigbee-sdk/commit/e883f431f54d7744605c05ac3bc92898d04315c0
 * Upstream date: 2025-02-14 17:01:07 +0800
 * Upstream subject: esp-zigbee-sdk: (f9a23626)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_scheduler_queue_size_set
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_scheduler_queue_size_set(void)

{
  int iVar1;
  
  iVar1 = zb_config_scheduler_queue_size();
  if (iVar1 != 0) {
    if (iVar1 == -0x1c) {
      return 0x105;
    }
    if (iVar1 == -0x16) {
      return 0x101;
    }
    if ((iVar1 + 0xdU < 4) || (iVar1 == -0xf)) {
      return 0x102;
    }
    if (iVar1 == -6) {
      return 0x104;
    }
    if (iVar1 != -0x1e) {
      if (iVar1 == -2) {
        return 0x10c;
      }
      if (iVar1 == -0x23) {
        return 0x103;
      }
      iVar1 = -1;
    }
  }
  return iVar1;
}

