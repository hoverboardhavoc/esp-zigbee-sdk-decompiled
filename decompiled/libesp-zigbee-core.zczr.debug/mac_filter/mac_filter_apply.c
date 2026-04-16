/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> mac_filter.o -> mac_filter_apply
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t mac_filter_apply(ezb_extaddr_t *extaddr,uint8_t *lqa)

{
  mac_filter_entry_t *pmVar1;
  char cVar2;
  
  pmVar1 = mac_filter_find_entry(extaddr);
  if (pmVar1 == (mac_filter_entry_t *)0x0) {
    cVar2 = '\0';
  }
  else {
    cVar2 = pmVar1->filtered;
    if ((_Bool)cVar2 != false) {
      cVar2 = '\x01';
    }
  }
  *lqa = '\0';
  if (s_filter_mode == '\x01') {
    if (cVar2 == '\0') {
      return 0x12;
    }
  }
  else if (s_filter_mode == '\x02') {
    if (cVar2 != '\0') {
      return 0x12;
    }
  }
  else if (s_filter_mode != '\0') {
    __assert_func("//build/esp-zigbee/src/core/mac/mac_filter.c",0x79,"mac_filter_apply",&_LC0);
    return 0;
  }
  if (pmVar1 == (mac_filter_entry_t *)0x0) {
    return 0;
  }
  if (pmVar1->lqa == '\0') {
    return 0;
  }
  *lqa = pmVar1->lqa;
  return 0;
}

