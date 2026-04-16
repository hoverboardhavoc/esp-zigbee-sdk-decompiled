/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_group.o -> aps_group_table_dump
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void aps_group_table_dump(void)

{
  ezb_shortaddr_t eVar1;
  int iVar2;
  aps_group_t *group;
  uint8_t uVar3;
  _Bool _Var4;
  int iVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar6;
  
  iVar5 = core_globals_get();
  log_write(3,"aps_group.c","Dump APS Group Table");
  uVar6 = 0;
  while (uVar6 = bitmap_find_next_bit
                           (*(undefined4 *)(iVar5 + 0x960),*(undefined2 *)(iVar5 + 0x964),uVar6),
        uVar6 < *(ushort *)(iVar5 + 0x964)) {
    group = (aps_group_t *)(*(int *)(iVar5 + 0x95c) + uVar6 * 0x22);
    eVar1 = group->group_addr;
    _Var4 = group_is_empty(group);
    if (CONCAT31(extraout_var_00,_Var4) == 0) {
      iVar2 = -0x4dc;
    }
    else {
      iVar2 = -0x4e4;
    }
    log_write(3,"aps_group.c","Group 0x%04x:%s",eVar1,core_globals_get + iVar2);
    iVar2 = 0xff;
    while( true ) {
      uVar3 = aps_group_next_endpoint(group,(char)iVar2 + '\x01');
      iVar2 = CONCAT31(extraout_var,uVar3);
      if (iVar2 == 0xff) break;
      log_write(3,"aps_group.c","  - Endpoint %d",iVar2);
    }
    uVar6 = uVar6 + 1 & 0xffff;
  }
  return;
}

