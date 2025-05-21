/*
 * Last changed at upstream commit d4fdccd9eea771602c7571d5f751435deed089e9
 * https://github.com/espressif/esp-zigbee-sdk/commit/d4fdccd9eea771602c7571d5f751435deed089e9
 * Upstream date: 2025-05-21 11:16:30 +0000
 * Upstream subject: esp-zigbee-sdk: (5d895722)
 * Source: libesp_zb_api.zczr -> esp_zigbee_core.o -> esp_zb_bdb_finding_binding_start_target
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_bdb_finding_binding_start_target(void)

{
  int iVar1;
  
  iVar1 = zb_bdb_finding_binding_target_ext();
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

