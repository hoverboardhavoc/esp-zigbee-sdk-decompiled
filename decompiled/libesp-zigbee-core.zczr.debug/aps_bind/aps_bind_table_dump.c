/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_bind.o -> aps_bind_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_bind_table_dump(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  size_t sVar4;
  aps_bind_src_t *src;
  uint uVar5;
  
  log_write(3,"aps_bind.c","Dump APS Bind Table");
  uVar5 = 0;
  while( true ) {
    iVar3 = core_globals_get();
    uVar1 = *(undefined4 *)(iVar3 + 0x96c);
    iVar3 = core_globals_get();
    uVar5 = bitmap_find_next_bit(uVar1,*(undefined2 *)(iVar3 + 0x970),uVar5);
    iVar3 = core_globals_get();
    if (*(ushort *)(iVar3 + 0x970) <= uVar5) break;
    iVar3 = core_globals_get();
    iVar3 = *(int *)(iVar3 + 0x968);
    sVar4 = bind_src_size();
    src = (aps_bind_src_t *)(iVar3 + (sVar4 & 0xffff) * uVar5);
    bind_table_dump_src(src);
    uVar2 = 0;
    while( true ) {
      iVar3 = core_globals_get();
      uVar2 = bitmap_find_next_bit(src + 1,*(undefined2 *)(iVar3 + 0x97c),uVar2);
      iVar3 = core_globals_get();
      if (*(ushort *)(iVar3 + 0x97c) <= uVar2) break;
      iVar3 = core_globals_get();
      bind_table_dump_dst((aps_bind_dst_t *)(*(int *)(iVar3 + 0x974) + uVar2 * 6));
      uVar2 = uVar2 + 1 & 0xffff;
    }
    uVar5 = uVar5 + 1 & 0xffff;
  }
  return;
}

