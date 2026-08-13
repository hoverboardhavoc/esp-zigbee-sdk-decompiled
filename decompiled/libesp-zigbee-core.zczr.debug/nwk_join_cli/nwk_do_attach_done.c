/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_do_attach_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_do_attach_done(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short *psVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  short local_20;
  ushort uStack_1e;
  undefined1 auStack_1c [10];
  short sStack_12;
  
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0xac4);
  if (param_1 == 0) {
    iVar3 = nwk_check_assigned_shortaddr(param_2);
    if (iVar3 != 0) {
      param_1 = 0x1ec;
      goto _L0;
    }
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) | 1;
    nwk_set_short_address(param_2);
    iVar3 = core_globals_get();
    nwk_set_extended_panid(iVar3 + 0xac8);
    nwk_set_update_id(*(undefined1 *)(iVar2 + 10));
    uVar9 = *(uint *)(iVar2 + 0x10) >> 0x14 & 0xf;
    if (uVar9 < 0xe) {
      cVar1 = (char)uVar9 + '\x01';
    }
    else {
      cVar1 = '\x0f';
    }
    iVar3 = core_globals_get();
    *(char *)(iVar3 + 0xa3c) = cVar1;
    uVar4 = nwk_get_extended_address();
    uVar5 = nwk_get_short_address();
    iVar3 = nwk_address_update(uVar4,uVar5,&sStack_12);
    if (iVar3 == 0) {
      nwk_address_lock_ref(sStack_12);
      nwk_mm_get_pib_attr(*(byte *)(iVar2 + 0x13) & 0x1f,0x4b,&uStack_1e);
      nwk_mm_get_pib_attr(*(byte *)(iVar2 + 0x13) & 0x1f,0x4a,auStack_1c,8);
      iVar3 = nwk_address_by_extended(auStack_1c,1,0,&local_20);
      if (iVar3 != 0) goto _L0;
      if (uStack_1e < 0xfff8) {
        iVar3 = nwk_address_update(auStack_1c,&sStack_12);
        if (iVar3 != 0) goto _L0;
        if (sStack_12 == local_20) goto _L0;
        goto _L0;
      }
_L0:
      psVar6 = (short *)nwk_neighbor_table_get_by_addr_ref(sStack_12);
      if (psVar6 == (short *)0x0) goto _L0;
    }
    else {
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x142,
                    "nwk_do_attach_done",
                    "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &addr_ref)) == 0"
                   );
_L0:
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x14d,
                    "nwk_do_attach_done",
                    "(nwk_address_by_extended(&parent_extended, 1, 0, &parent_addr_ref)) == 0");
_L0:
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x150,
                    "nwk_do_attach_done",
                    "(nwk_address_update(&parent_extended, parent_short, &addr_ref)) == 0");
_L0:
      __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x151,
                    "nwk_do_attach_done","addr_ref == parent_addr_ref");
_L0:
      psVar6 = (short *)nwk_neighbor_table_new(1);
      if (psVar6 == (short *)0x0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x157,
                      "nwk_do_attach_done","(nbr = nwk_neighbor_table_new(1)) != ((void *)0)");
        goto _L0;
      }
      nwk_address_lock_ref(sStack_12);
      *psVar6 = sStack_12;
    }
    uVar9 = (*(byte *)(iVar2 + 0x13) & 0x1f) << 0xd;
    uVar10 = *(uint *)(psVar6 + 6);
    *(uint *)(psVar6 + 6) = uVar10 & 0xfffc1fff | uVar9;
    uVar7 = (*(uint *)(iVar2 + 0x10) >> 0x14 & 0xf) << 2;
    *(uint *)(psVar6 + 6) = uVar10 & 0xfffc1fc3 | uVar9 | uVar7;
    uVar8 = *(uint *)(iVar2 + 0x10) >> 0x12 & 3;
    *(uint *)(psVar6 + 6) = uVar10 & 0xfffc1fc0 | uVar9 | uVar7 | uVar8;
    *(undefined1 *)(psVar6 + 1) = *(undefined1 *)(iVar2 + 9);
    psVar6[8] = *(short *)(iVar2 + 0xe);
    *(uint *)(psVar6 + 6) = uVar10 & 0xfffc1c00 | uVar9 | uVar7 | uVar8;
    iVar2 = core_globals_get();
    *(short **)(iVar2 + 0xac4) = psVar6;
  }
  else {
_L0:
    nwk_disc_table_delete_parent(iVar2);
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xac4) = 0;
    iVar2 = core_globals_get();
    iVar2 = nwk_do_attach(iVar2 + 0xac8);
    if (iVar2 == 0) {
      return;
    }
  }
  if (param_1 == 0xc) {
    return;
  }
_L0:
  iVar2 = core_globals_get();
  nwk_call_join_confirm(*(undefined1 *)(iVar2 + 0xad3),param_1);
  return;
}

