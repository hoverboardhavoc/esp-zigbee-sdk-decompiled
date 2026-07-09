/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_bind.o -> aps_bind_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_bind_table_dump(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined2 *puVar6;
  undefined2 *puVar7;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
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
  iVar5 = *(int *)(iVar4 + 0x968);
  iVar4 = bind_src_size();
  puVar6 = (undefined2 *)(iVar5 + iVar4 * uVar1);
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0x968);
  iVar5 = bind_src_size();
  uVar3 = ((int)puVar6 - iVar4) / iVar5;
  iVar4 = nwk_address_extended_by_ref(*puVar6,&uStack_40);
  if (iVar4 == 0) goto _L0;
_L0:
  __assert_func(0,0,0,0);
_L0:
  log_write(3,"aps_bind.c","  - (%d)[0x%016llx:%d 0x%04x]",uVar3 & 0xffff,uStack_40,uStack_3c,
            *(undefined1 *)(puVar6 + 1),puVar6[2]);
  uVar3 = 0;
  puVar6 = puVar6 + 3;
  do {
    iVar4 = core_globals_get();
    uVar3 = bitmap_find_next_bit(puVar6,*(undefined2 *)(iVar4 + 0x97c),uVar3);
    iVar4 = core_globals_get();
    if (*(ushort *)(iVar4 + 0x97c) <= uVar3) {
      uVar1 = uVar1 + 1 & 0xffff;
      goto _L0;
    }
    iVar4 = core_globals_get();
    puVar7 = (undefined2 *)(*(int *)(iVar4 + 0x974) + uVar3 * 6);
    iVar4 = core_globals_get();
    iVar4 = *(int *)(iVar4 + 0x974);
    if ((*(byte *)((int)puVar7 + 5) & 1) == 0) {
      iVar5 = nwk_address_extended_by_ref(*puVar7,&uStack_38);
      if (iVar5 != 0) goto _L0;
      log_write(3,"aps_bind.c","    -> (%d)[0x%016llx:%d]",
                ((int)puVar7 - iVar4 >> 1) * -0x55555555 & 0xffff,uStack_38,uStack_34,
                *(undefined1 *)(puVar7 + 1));
    }
    else {
      log_write(3,"aps_bind.c","    -> (%d)[0x%04x]");
    }
    uVar3 = uVar3 + 1 & 0xffff;
  } while( true );
}

