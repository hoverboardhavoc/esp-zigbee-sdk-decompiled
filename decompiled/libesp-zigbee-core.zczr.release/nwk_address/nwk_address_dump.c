/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_address_dump(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  
  iVar1 = core_globals_get();
  iVar2 = core_globals_get();
  log_write(3,"nwk_address.c",0x11110);
  uVar3 = 0;
  while( true ) {
    uVar3 = bitmap_find_next_bit(iVar2 + 0xcaa,0x20,uVar3);
    uVar3 = uVar3 & 0xff;
    if (0x1f < uVar3) break;
    puVar4 = (undefined1 *)(uVar3 * 3 + iVar2 + 0xc4a);
    log_write(3,"nwk_address.c","  - [%d] %02x:%02x:%02x",uVar3,*puVar4,puVar4[1],puVar4[2]);
    uVar3 = uVar3 + 1 & 0xff;
  }
  log_write(3,"nwk_address.c","Dump NWK Address Table");
  uVar3 = 0;
  while (uVar3 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar1 + 0xcb0),*(undefined2 *)(iVar1 + 0xcb8),uVar3),
        uVar3 < *(ushort *)(iVar1 + 0xcb8)) {
    puVar4 = (undefined1 *)(*(int *)(iVar1 + 0xcb4) + uVar3 * 0x10);
    log_write(3,"nwk_address.c","  - [%d] 0x%04hx <-> (%d)%02x:%02x:%02x:%02x:%02x",uVar3,
              *(undefined2 *)(puVar4 + 6),puVar4[5],*puVar4,puVar4[1]);
    uVar3 = uVar3 + 1 & 0xffff;
  }
  return;
}

