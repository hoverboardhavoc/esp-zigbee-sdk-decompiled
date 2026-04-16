/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_disc_table_get_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

touchlink_disc_dev_info_t * touchlink_disc_table_get_entry(void)

{
  touchlink_disc_dev_info_t *ptVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = touchlink_transaction_get();
  ptVar1 = (touchlink_disc_dev_info_t *)0x0;
  if (*(byte *)(iVar2 + 8) < 8) {
    iVar2 = touchlink_transaction_get();
    iVar3 = touchlink_transaction_get();
    ptVar1 = (touchlink_disc_dev_info_t *)(iVar2 + (uint)*(byte *)(iVar3 + 8) * 0xc0 + 0xc);
    iVar2 = touchlink_transaction_get();
    *(char *)(iVar2 + 8) = *(char *)(iVar2 + 8) + '\x01';
  }
  return ptVar1;
}

