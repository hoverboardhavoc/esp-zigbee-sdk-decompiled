/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> test_utils.o -> mac_add_visible_device
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void mac_add_visible_device(ezb_extaddr_t *extaddr)

{
  int iVar1;
  
  mac_filter_set_mode(1);
  iVar1 = mac_filter_add_address(extaddr);
  if (iVar1 != 0) {
    log_write(1,"test_utils.c","Failed to add 0x%016llx to MAC filter allow list",
              *(undefined4 *)&extaddr->field_0,*(undefined4 *)((int)&extaddr->field_0 + 4));
    return;
  }
  return;
}

