/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_disc_table.o -> nwk_disc_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_disc_table_dump(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar2 = core_globals_get();
  log_write(3,"nwk_disc_table.c","Dump NWK Discovery Table");
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit(iVar2 + 0xba4,6,uVar3);
    uVar3 = uVar3 & 0xff;
    if (5 < uVar3) break;
    iVar1 = uVar3 * 0x14 + iVar2 + 0xb2c;
    nwk_address_get_panid(*(undefined1 *)(iVar1 + 8),&uStack_2a);
    nwk_address_get_extpanid(*(undefined1 *)(iVar1 + 8),&uStack_28);
    log_write(3,"nwk_disc_table.c",
              "  - PAN[%d:0x%04x:0x%016llx] from 0x%04x channel(%d:%d), lqa(%d), permit_join(%d)",
              *(undefined1 *)(iVar1 + 8),uStack_2a,uStack_28,uStack_24);
    uVar3 = uVar3 + 1 & 0xff;
  }
  return;
}

