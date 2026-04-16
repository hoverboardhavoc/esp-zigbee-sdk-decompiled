/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink_utility.o -> touchlink_assign_nwk_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_assign_nwk_info(void)

{
  byte bVar1;
  char *pcVar2;
  ezb_err_t eVar3;
  
  pcVar2 = (char *)touchlink_device_info_get();
  if (*pcVar2 != '\0') {
    touchlink_assign_short_addr();
    nwk_set_short_address();
    nwk_secur_set_key(0,0);
  }
  touchlink_assign_pan_id();
  nwk_set_panid();
  bVar1 = touchlink_get_logical_channel();
  eVar3 = nwk_set_pan_channel(1 << (bVar1 & 0x1f) & 0x7ffffff);
  return eVar3;
}

