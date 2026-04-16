/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink_utility.o -> touchlink_disc_table_find
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

touchlink_disc_dev_info_t * touchlink_disc_table_find(ezb_extaddr_t *ieee_addr)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    iVar2 = touchlink_transaction_get();
    if (*(byte *)(iVar2 + 8) <= uVar1) {
      return (touchlink_disc_dev_info_t *)0x0;
    }
    iVar2 = touchlink_transaction_get();
    iVar2 = iVar2 + uVar1 * 0xc0;
    if ((*(uint *)&ieee_addr->field_0 ==
         (*(uint *)(iVar2 + 0x1c) << 8 | (uint)*(byte *)(iVar2 + 0x1b))) &&
       (*(uint *)((int)&ieee_addr->field_0 + 4) ==
        (*(int *)(iVar2 + 0x20) << 8 | *(uint *)(iVar2 + 0x1c) >> 0x18))) break;
    uVar1 = uVar1 + 1 & 0xff;
  }
  iVar2 = touchlink_transaction_get();
  return (touchlink_disc_dev_info_t *)(iVar2 + uVar1 * 0xc0 + 0xc);
}

