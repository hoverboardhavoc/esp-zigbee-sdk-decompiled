/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_do_attach_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_do_attach_done(ezb_err_t error,ezb_shortaddr_t alloc_shortaddr)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined2 *puVar6;
  ezb_err_t eVar7;
  undefined2 in_register_0000202e;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  short local_30;
  ushort uStack_2e;
  nwk_addr_ref_t parent_addr_ref;
  ezb_shortaddr_t parent_short;
  ezb_extaddr_t parent_extended;
  nwk_addr_ref_t addr_ref;
  
  iVar2 = core_globals_get();
  iVar2 = *(int *)(iVar2 + 0xac4);
  if (error == 0) {
    iVar3 = nwk_check_assigned_shortaddr(CONCAT22(in_register_0000202e,alloc_shortaddr));
    if (iVar3 != 0) {
      error = 0x1ec;
      goto _L0;
    }
    iVar3 = core_globals_get();
    *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) | 1;
    nwk_set_short_address(CONCAT22(in_register_0000202e,alloc_shortaddr));
    iVar3 = core_globals_get();
    nwk_set_extended_panid(iVar3 + 0xac8);
    iVar3 = core_globals_get();
    *(undefined1 *)(iVar3 + 0x9df) = *(undefined1 *)(iVar2 + 10);
    uVar10 = *(uint *)(iVar2 + 0x10) >> 0x14 & 0xf;
    if (uVar10 < 0xe) {
      cVar1 = (char)uVar10 + '\x01';
    }
    else {
      cVar1 = '\x0f';
    }
    iVar3 = core_globals_get();
    *(char *)(iVar3 + 0xa3c) = cVar1;
    uVar4 = nwk_get_extended_address();
    uVar5 = nwk_get_short_address();
    iVar3 = nwk_address_update(uVar4,uVar5,(undefined1 *)((int)&parent_extended.field_0 + 6));
    if (iVar3 == 0) {
      nwk_address_lock_ref(parent_extended.field_0.u64._6_2_);
      nwk_mm_get_pib_attr(*(byte *)(iVar2 + 0x13) & 0x1f,0x4b,&uStack_2e);
      nwk_mm_get_pib_attr(*(byte *)(iVar2 + 0x13) & 0x1f,0x4a,&parent_addr_ref,8);
      iVar3 = nwk_address_by_extended(&parent_addr_ref,1,0,&local_30);
      if (iVar3 != 0) goto _L0;
      if (uStack_2e < 0xfff8) {
        iVar3 = nwk_address_update(&parent_addr_ref,
                                   (undefined1 *)((int)&parent_extended.field_0 + 6));
        if (iVar3 != 0) goto _L0;
        if (parent_extended.field_0.u64._6_2_ == local_30) goto _L0;
        goto _L0;
      }
_L0:
      puVar6 = (undefined2 *)nwk_neighbor_table_get_by_addr_ref(parent_extended.field_0.u64._6_2_);
      if (puVar6 == (undefined2 *)0x0) goto _L0;
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
      puVar6 = (undefined2 *)nwk_neighbor_table_new(1);
      if (puVar6 == (undefined2 *)0x0) {
        __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_cli.c",0x157,
                      "nwk_do_attach_done","(nbr = nwk_neighbor_table_new(1)) != ((void *)0)");
        goto _L0;
      }
      nwk_address_lock_ref(parent_extended.field_0.u64._6_2_);
      *puVar6 = parent_extended.field_0.u64._6_2_;
    }
    uVar10 = (*(byte *)(iVar2 + 0x13) & 0x1f) << 0xd;
    uVar11 = *(uint *)(puVar6 + 6);
    *(uint *)(puVar6 + 6) = uVar11 & 0xfffc1fff | uVar10;
    uVar8 = (*(uint *)(iVar2 + 0x10) >> 0x14 & 0xf) << 2;
    *(uint *)(puVar6 + 6) = uVar11 & 0xfffc1fc3 | uVar10 | uVar8;
    uVar9 = *(uint *)(iVar2 + 0x10) >> 0x12 & 3;
    *(uint *)(puVar6 + 6) = uVar11 & 0xfffc1fc0 | uVar10 | uVar8 | uVar9;
    *(undefined1 *)(puVar6 + 1) = *(undefined1 *)(iVar2 + 9);
    puVar6[8] = *(undefined2 *)(iVar2 + 0xe);
    *(uint *)(puVar6 + 6) = uVar11 & 0xfffc1c00 | uVar10 | uVar8 | uVar9;
    iVar2 = core_globals_get();
    *(undefined2 **)(iVar2 + 0xac4) = puVar6;
  }
  else {
_L0:
    nwk_disc_table_delete_parent(iVar2);
    iVar2 = core_globals_get();
    *(undefined4 *)(iVar2 + 0xac4) = 0;
    iVar2 = core_globals_get();
    eVar7 = nwk_do_attach((nwk_join_req_t *)(iVar2 + 0xac8));
    if (eVar7 == 0) {
      return;
    }
  }
  if (error == 0xc) {
    return;
  }
_L0:
  iVar2 = core_globals_get();
  nwk_call_join_confirm(*(nwk_join_method_t *)(iVar2 + 0xad3),error);
  return;
}

