/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_set_mode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_filter_set_mode(uint8_t mode)

{
  undefined3 in_register_00002029;
  
  if (CONCAT31(in_register_00002029,mode) < 3) {
    s_filter_mode = mode;
    return;
  }
  __assert_func("//build/esp-zigbee/src/core/mac/mac_filter.c",0x9d,"mac_filter_set_mode",
                "mode <= MAC_FILTER_MODE_DENY_LIST");
  return;
}

