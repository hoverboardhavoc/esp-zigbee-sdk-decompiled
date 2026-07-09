/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_address_dump(void)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  iVar1 = core_globals_get();
  log_write(3,"nwk_address.c","Dump NWK Address Table");
  uVar2 = 0;
  while (uVar2 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar1 + 0xc4c),*(undefined2 *)(iVar1 + 0xc54),uVar2),
        uVar2 < *(ushort *)(iVar1 + 0xc54)) {
    puVar3 = (undefined4 *)(*(int *)(iVar1 + 0xc50) + uVar2 * 0x12);
    log_write(3,"nwk_address.c","  - [%d] 0x%04hx <-> 0x%016llx",uVar2,*(undefined2 *)(puVar3 + 2),
              *puVar3,puVar3[1]);
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return;
}

