/*
 * Last changed at upstream commit 9b2a25d84666d8bc8515f84abcf92271524d2896
 * https://github.com/espressif/esp-zigbee-sdk/commit/9b2a25d84666d8bc8515f84abcf92271524d2896
 * Upstream date: 2024-05-24 08:27:18 +0000
 * Upstream subject: esp-zigbee-lib:(73447d7e)
 * Source: libesp_zb_api_zczr -> esp_zigbee_core.o -> esp_zb_scheduler_queue_size_set
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
      iVar1 = -1;
    }
  }
  return iVar1;
}

