/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_restore(void)

{
  bool bVar1;
  int iVar2;
  undefined2 *__s;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_28 [2];
  undefined2 uStack_26;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined2 uStack_1c;
  byte bStack_1a;
  undefined1 uStack_19;
  uint uStack_18;
  undefined2 uStack_14;
  char cStack_12;
  
  uStack_14 = 0;
  cStack_12 = '\0';
  ds_child_info_itor_read(auStack_28);
  bVar1 = false;
  iVar2 = 0;
  do {
    if (cStack_12 != '\0') {
_L0:
      if ((bVar1) || (iVar2 != 0)) {
        nbt_refresh_stored_children();
      }
      return;
    }
    __s = (undefined2 *)nwk_neighbor_table_get_by_extended(&uStack_24);
    if (__s == (undefined2 *)0x0) {
      __s = (undefined2 *)nwk_neighbor_table_new(0);
      if (__s == (undefined2 *)0x0) {
        iVar2 = 1;
        goto _L0;
      }
    }
    else {
      bVar1 = true;
    }
    memset(__s,0,0x1c);
    iVar2 = nwk_address_update(&uStack_24,uStack_26,__s);
    if (iVar2 == 0) {
      nwk_address_lock_ref(*__s);
      uVar5 = *(uint *)(__s + 6);
      *(uint *)(__s + 6) = uVar5 & 0xfffffffc | 2;
      *(uint *)(__s + 6) = uVar5 & 0xfffffc3c | 0x42;
      iVar3 = core_globals_get();
      uVar5 = (*(byte *)(iVar3 + 0xa3c) + 1 & 0xf) << 2;
      uVar6 = *(uint *)(__s + 6);
      *(uint *)(__s + 6) = uVar6 & 0xffffffc3 | uVar5;
      uVar4 = (bStack_1a & 0x1f) << 0xd;
      *(uint *)(__s + 6) = uVar6 & 0xfffc1fc3 | uVar5 | uVar4;
      *(undefined1 *)((int)__s + 7) = uStack_19;
      *(uint *)(__s + 6) = uVar6 & 0xfffc1bc3 | uVar5 | uVar4 | (uStack_18 >> 4 & 1) << 10;
      __s[8] = uStack_1c;
      nwk_neighbor_zed_set_timeout(__s,uStack_18 & 0xf);
    }
    else {
      if (iVar2 != 0xd) goto _L0;
      log_write(1,"nwk_neighbor.c","Address conflicts on stored child 0x%016llx(0x%04hx)",uStack_24,
                uStack_20,uStack_26);
    }
    ds_child_info_next(auStack_28);
  } while( true );
}

