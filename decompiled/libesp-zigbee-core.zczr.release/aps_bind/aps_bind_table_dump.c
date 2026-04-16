/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_bind_table_dump(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  size_t sVar5;
  int iVar6;
  undefined2 *puVar7;
  aps_bind_dst_t *dst;
  undefined2 *puVar8;
  undefined4 uStack_40;
  ezb_extaddr_t src_addr;
  ezb_extaddr_t dst_addr;
  
  uVar1 = 0;
  log_write(3,"aps_bind.c","Dump APS Bind Table");
_L0:
  iVar4 = core_globals_get();
  uVar2 = *(undefined4 *)(iVar4 + 0x96c);
  iVar4 = core_globals_get();
  uVar1 = bitmap_find_next_bit(uVar2,*(undefined2 *)(iVar4 + 0x970),uVar1);
  iVar4 = core_globals_get();
  if (*(ushort *)(iVar4 + 0x970) <= uVar1) {
    return;
  }
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0x968);
  sVar5 = bind_src_size();
  puVar7 = (undefined2 *)(iVar4 + sVar5 * uVar1);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0x968);
  sVar5 = bind_src_size();
  uVar3 = ((int)puVar7 - iVar4) / (int)sVar5;
  iVar4 = nwk_address_extended_by_ref(*puVar7,&uStack_40);
  if (iVar4 == 0) goto _L0;
_L0:
  __assert_func(0,0,0,0);
_L0:
  log_write(3,"aps_bind.c","  - (%d)[0x%016llx:%d 0x%04x]",uVar3 & 0xffff,uStack_40,
            src_addr.field_0.u64._0_4_,*(undefined1 *)(puVar7 + 1),puVar7[2]);
  uVar3 = 0;
  puVar7 = puVar7 + 3;
  do {
    iVar4 = core_globals_get();
    uVar3 = bitmap_find_next_bit(puVar7,*(undefined2 *)(iVar4 + 0x97c),uVar3);
    iVar4 = core_globals_get();
    if (*(ushort *)(iVar4 + 0x97c) <= uVar3) {
      uVar1 = uVar1 + 1 & 0xffff;
      goto _L0;
    }
    iVar4 = core_globals_get();
    puVar8 = (undefined2 *)(*(int *)(iVar4 + 0x974) + uVar3 * 6);
    iVar4 = core_globals_get();
    iVar4 = *(int *)(iVar4 + 0x974);
    if ((*(byte *)((int)puVar8 + 5) & 1) == 0) {
      iVar6 = nwk_address_extended_by_ref(*puVar8,(undefined1 *)((int)&src_addr.field_0 + 4));
      if (iVar6 != 0) goto _L0;
      log_write(3,"aps_bind.c","    -> (%d)[0x%016llx:%d]",
                ((int)puVar8 - iVar4 >> 1) * -0x55555555 & 0xffff,src_addr.field_0.u64._4_4_,
                dst_addr.field_0.u64._0_4_,*(undefined1 *)(puVar8 + 1));
    }
    else {
      log_write(3,"aps_bind.c","    -> (%d)[0x%04x]");
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while( true );
}

