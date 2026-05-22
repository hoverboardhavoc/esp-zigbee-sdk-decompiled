/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_address_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

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

