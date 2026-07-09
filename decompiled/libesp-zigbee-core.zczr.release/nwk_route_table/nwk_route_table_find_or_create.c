/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_route_table.o -> nwk_route_table_find_or_create
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined2 * nwk_route_table_find_or_create(undefined4 param_1)

{
  int iVar1;
  undefined2 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  
  iVar1 = core_globals_get();
  puVar2 = (undefined2 *)route_table_find(iVar1 + 0xc58,param_1);
  if (puVar2 == (undefined2 *)0x0) {
    puVar3 = (undefined2 *)
             mempool_alloc_ent(*(undefined4 *)(iVar1 + 0xc58),*(undefined4 *)(iVar1 + 0xc5c),0x10,
                               *(undefined2 *)(iVar1 + 0xc60));
    puVar2 = puVar3;
    if (puVar3 == (undefined2 *)0x0) {
      uVar4 = 0;
      while (uVar4 = bitmap_find_next_bit
                               (*(undefined4 *)(iVar1 + 0xc5c),*(undefined2 *)(iVar1 + 0xc60),uVar4)
            , uVar4 < *(ushort *)(iVar1 + 0xc60)) {
        puVar2 = (undefined2 *)(*(int *)(iVar1 + 0xc58) + uVar4 * 0x10);
        if (*(char *)(puVar2 + 6) == '\0') {
          if ((*(uint *)(puVar2 + 6) & 0x500000) == 0x500000) goto _L0;
          if (puVar3 != (undefined2 *)0x0) {
            if ((*(byte *)(puVar3 + 5) <= *(byte *)(puVar2 + 5)) &&
               ((*(byte *)(puVar2 + 5) != *(byte *)(puVar3 + 5) ||
                (*(uint *)(puVar3 + 2) <= *(uint *)(puVar2 + 2))))) goto _L78;
          }
        }
        else {
_L78:
          puVar2 = puVar3;
        }
        puVar3 = puVar2;
        uVar4 = uVar4 + 1 & 0xffff;
      }
      puVar2 = puVar3;
      if (puVar3 == (undefined2 *)0x0) {
        return (undefined2 *)0x0;
      }
    }
_L0:
    memset(puVar2 + 2,0,0xc);
    puVar2[1] = 0xffff;
    *puVar2 = (short)param_1;
    puVar2[7] = 3;
  }
  return puVar2;
}

