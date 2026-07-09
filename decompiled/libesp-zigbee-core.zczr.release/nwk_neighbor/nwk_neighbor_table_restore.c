/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_table_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_neighbor_table_restore(void)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined2 *__s;
  int iVar4;
  undefined1 auStack_38 [2];
  undefined2 uStack_36;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined2 uStack_2c;
  byte bStack_2a;
  undefined1 uStack_29;
  uint uStack_28;
  short sStack_24;
  char cStack_22;
  
  sStack_24 = 0;
  cStack_22 = '\0';
  bVar2 = false;
  ds_child_info_itor_read(auStack_38);
  iVar3 = 0;
  while (cStack_22 == '\0') {
    __s = (undefined2 *)nwk_neighbor_table_get_by_extended(&uStack_34);
    if (__s == (undefined2 *)0x0) {
      __s = (undefined2 *)nwk_neighbor_table_new();
      if (__s == (undefined2 *)0x0) goto _L0;
    }
    else {
      bVar2 = true;
    }
    memset(__s,0,0x1c);
    iVar3 = nwk_address_update(&uStack_34,uStack_36,__s);
    if (iVar3 == 0) {
      nwk_address_lock_ref(*__s);
      __s[6] = __s[6] & 0xfc3c | 0x42;
      iVar4 = core_globals_get();
      bVar1 = *(byte *)(iVar4 + 0xa3c);
      *(undefined1 *)((int)__s + 7) = uStack_29;
      *(uint *)(__s + 6) =
           (uStack_28 & 0x10) << 6 | (bVar1 + 1 & 0xf) << 2 | (bStack_2a & 0x1f) << 0xd |
           *(uint *)(__s + 6) & 0xfffc1bc3;
      __s[8] = uStack_2c;
      nwk_neighbor_zed_set_timeout(__s,uStack_28 & 0xf);
    }
    else {
      if (iVar3 != 0xd) goto _L0;
      log_write(1,"nwk_neighbor.c","Address conflicts on stored child 0x%016llx(0x%04hx)",uStack_34,
                uStack_30,uStack_36);
    }
    if (cStack_22 == '\0') {
      sStack_24 = sStack_24 + 1;
      ds_child_info_itor_read(auStack_38);
    }
  }
  if ((bVar2) || (iVar3 != 0)) {
_L0:
    iVar4 = ds_internal_remove_entry(4,0xffffffff,0);
    iVar3 = 0;
    while ((iVar4 == 0 && (iVar3 = nwk_child_table_next(iVar3), iVar3 != 0))) {
      iVar4 = nwk_neighbor_table_store_child();
    }
  }
  return;
}

