/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_do_attach_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_do_attach_done(ezb_err_t error,ezb_shortaddr_t alloc_shortaddr)

{
  undefined1 uVar1;
  short sVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  short *psVar8;
  undefined4 *puVar9;
  ezb_err_t eVar10;
  undefined2 in_register_0000202e;
  uint uVar11;
  short sStack_32;
  short sStack_30;
  nwk_addr_ref_t addr_ref;
  nwk_addr_ref_t parent_addr_ref;
  ezb_shortaddr_t parent_short;
  ezb_extaddr_t parent_extended;
  
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xac4);
  if (error == 0) {
    iVar5 = nwk_check_assigned_shortaddr(CONCAT22(in_register_0000202e,alloc_shortaddr));
    error = 0x1ec;
    if (iVar5 == 0) {
      iVar5 = core_globals_get();
      cVar3 = '\x0f';
      *(byte *)(iVar5 + 0xb18) = *(byte *)(iVar5 + 0xb18) | 1;
      nwk_set_short_address(CONCAT22(in_register_0000202e,alloc_shortaddr));
      iVar5 = core_globals_get();
      nwk_set_extended_panid(iVar5 + 0xac8);
      iVar5 = core_globals_get();
      *(undefined1 *)(iVar5 + 0x9df) = *(undefined1 *)(iVar4 + 10);
      uVar11 = *(uint *)(iVar4 + 0x10) >> 0x14 & 0xf;
      if (uVar11 < 0xe) {
        cVar3 = (char)uVar11 + '\x01';
      }
      iVar5 = core_globals_get();
      *(char *)(iVar5 + 0xa3c) = cVar3;
      uVar6 = nwk_get_extended_address();
      uVar7 = nwk_get_short_address();
      iVar5 = nwk_address_update(uVar6,uVar7,&sStack_32);
      if (iVar5 == 0) goto _L0;
      do {
        do {
          __assert_func(0,0,0,0);
_L0:
          nwk_address_lock_ref(sStack_32);
          psVar8 = (short *)nwk_neighbor_table_new(1);
        } while (psVar8 == (short *)0x0);
        nwk_mm_get_pib_attr(*(byte *)(iVar4 + 0x13) & 0x1f,0x4b,&addr_ref,2);
        nwk_mm_get_pib_attr(*(byte *)(iVar4 + 0x13) & 0x1f,0x4a,&parent_addr_ref,8);
        iVar5 = nwk_address_by_extended(&parent_addr_ref,1,&sStack_30);
      } while ((iVar5 != 0) ||
              ((addr_ref < 0xfff8 &&
               ((iVar5 = nwk_address_update(&parent_addr_ref,&sStack_32), iVar5 != 0 ||
                (sStack_32 != sStack_30))))));
      uVar11 = *(uint *)(iVar4 + 0x10);
      *psVar8 = sStack_32;
      *(undefined1 *)(psVar8 + 1) = *(undefined1 *)(iVar4 + 9);
      sVar2 = *(short *)(iVar4 + 0xe);
      *(uint *)(psVar8 + 6) =
           uVar11 >> 0x12 & 0x3f | (uVar11 >> 0x18 & 0x1f) << 0xd |
           *(uint *)(psVar8 + 6) & 0xfffc1c00;
      psVar8[10] = sVar2;
      iVar4 = core_globals_get();
      *(short **)(iVar4 + 0xac4) = psVar8;
      error = 0;
    }
  }
  else {
    nwk_disc_table_delete_parent(iVar4);
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xac4) = 0;
    iVar4 = core_globals_get();
    eVar10 = nwk_do_attach((nwk_join_req_t *)(iVar4 + 0xac8));
    if (eVar10 == 0) {
      return;
    }
    if (error == 0xc) {
      return;
    }
  }
  iVar4 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar4 + 0xad3);
  iVar4 = core_globals_get();
  *(undefined1 *)(iVar4 + 0xac0) = 0;
  parent_short = 0;
  parent_extended.field_0.u64._0_4_ = 0;
  parent_extended.field_0.u64._4_4_ = 0;
  parent_addr_ref._0_1_ = (undefined1)error;
  parent_addr_ref._1_1_ = uVar1;
  if (error == 0) {
    parent_short = nwk_get_short_address();
  }
  else {
    parent_short = 0xffff;
  }
  puVar9 = (undefined4 *)nwk_get_extended_panid();
  parent_extended.field_0.u64._0_4_ = *puVar9;
  parent_extended.field_0.u64._4_4_ = puVar9[1];
  nwk_join_confirm(&parent_addr_ref);
  return;
}

