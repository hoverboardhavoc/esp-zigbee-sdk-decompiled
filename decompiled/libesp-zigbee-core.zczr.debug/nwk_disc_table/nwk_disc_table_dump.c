/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_disc_table.o -> nwk_disc_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: extpanid */
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_disc_table_dump(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined2 uStack_1a;
  undefined4 uStack_18;
  ezb_panid_t panid;
  ezb_extpanid_t extpanid;
  
  iVar2 = core_globals_get();
  log_write(3,"nwk_disc_table.c","Dump NWK Discovery Table");
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit(iVar2 + 0xba4,6,uVar3);
    uVar3 = uVar3 & 0xff;
    if (5 < uVar3) break;
    iVar1 = iVar2 + 0xb2c + uVar3 * 0x14;
    nwk_address_get_panid(*(undefined1 *)(iVar1 + 8),&uStack_1a);
    nwk_address_get_extpanid(*(undefined1 *)(iVar1 + 8),&stack0xffffffe8);
    log_write(3,"nwk_disc_table.c",
              "  - PAN[%d:0x%04x:0x%016llx] from 0x%04x channel(%d:%d), lqa(%d), permit_join(%d)",
              *(undefined1 *)(iVar1 + 8),uStack_1a,uStack_18,extpanid.field_0.u64._0_4_);
    uVar3 = uVar3 + 1 & 0xff;
  }
  return;
}

