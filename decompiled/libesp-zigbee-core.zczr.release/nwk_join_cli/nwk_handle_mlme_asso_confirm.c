/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_handle_mlme_asso_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_mlme_asso_confirm(uint8_t iface_id,mac_associate_cnf_t *cnf)

{
  undefined1 uVar1;
  short sVar2;
  ezb_shortaddr_t eVar3;
  char cVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  short *psVar8;
  undefined4 *puVar9;
  ezb_err_t eVar10;
  undefined3 in_register_00002029;
  int iVar11;
  uint uVar12;
  short sStack_32;
  short sStack_30;
  ushort uStack_2e;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar11 = core_globals_get();
  if ((*(byte *)(*(int *)(iVar11 + 0xac4) + 0x13) & 0x1f) != CONCAT31(in_register_00002029,iface_id)
     ) {
    __assert_func(0,0,0,0);
  }
  uVar12 = 0;
  if (cnf->status != 0) {
    uVar12 = cnf->status | 0x100;
  }
  eVar3 = cnf->asso_shortaddr;
  iVar11 = core_globals_get();
  iVar11 = *(int *)(iVar11 + 0xac4);
  if (uVar12 == 0) {
    iVar5 = nwk_check_assigned_shortaddr(eVar3);
    uVar12 = 0x1ec;
    if (iVar5 == 0) {
      iVar5 = core_globals_get();
      *(byte *)(iVar5 + 0xb18) = *(byte *)(iVar5 + 0xb18) | 1;
      nwk_set_short_address(eVar3);
      iVar5 = core_globals_get();
      nwk_set_extended_panid(iVar5 + 0xac8);
      iVar5 = core_globals_get();
      *(undefined1 *)(iVar5 + 0x9df) = *(undefined1 *)(iVar11 + 10);
      cVar4 = '\x0f';
      uVar12 = *(uint *)(iVar11 + 0x10) >> 0x14 & 0xf;
      if (uVar12 < 0xe) {
        cVar4 = (char)uVar12 + '\x01';
      }
      iVar5 = core_globals_get();
      *(char *)(iVar5 + 0xa3c) = cVar4;
      uVar6 = nwk_get_extended_address();
      uVar7 = nwk_get_short_address();
      iVar5 = nwk_address_update(uVar6,uVar7,&sStack_32);
      if (iVar5 == 0) goto _L0;
      do {
        do {
          __assert_func(0,0,0,0);
_L0:
          nwk_address_lock_ref(sStack_32);
          nwk_mm_get_pib_attr(*(byte *)(iVar11 + 0x13) & 0x1f,0x4b,&uStack_2e,2);
          nwk_mm_get_pib_attr(*(byte *)(iVar11 + 0x13) & 0x1f,0x4a,&uStack_2c,8);
          iVar5 = nwk_address_by_extended(&uStack_2c,1,0,&sStack_30);
        } while ((iVar5 != 0) ||
                ((uStack_2e < 0xfff8 &&
                 ((iVar5 = nwk_address_update(&uStack_2c,&sStack_32), iVar5 != 0 ||
                  (sStack_32 != sStack_30))))));
        psVar8 = (short *)nwk_neighbor_table_get_by_addr_ref(sStack_32);
        if (psVar8 != (short *)0x0) goto _L0;
        psVar8 = (short *)nwk_neighbor_table_new(1);
      } while (psVar8 == (short *)0x0);
      nwk_address_lock_ref(sStack_32);
      *psVar8 = sStack_32;
_L0:
      uVar12 = *(uint *)(iVar11 + 0x10);
      *(undefined1 *)(psVar8 + 1) = *(undefined1 *)(iVar11 + 9);
      sVar2 = *(short *)(iVar11 + 0xe);
      *(uint *)(psVar8 + 6) =
           uVar12 >> 0x12 & 0x3f | (uVar12 >> 0x18 & 0x1f) << 0xd |
           *(uint *)(psVar8 + 6) & 0xfffc1c00;
      psVar8[8] = sVar2;
      iVar11 = core_globals_get();
      *(short **)(iVar11 + 0xac4) = psVar8;
      uVar12 = 0;
    }
  }
  else {
    nwk_disc_table_delete_parent(iVar11);
    iVar11 = core_globals_get();
    *(undefined4 *)(iVar11 + 0xac4) = 0;
    iVar11 = core_globals_get();
    eVar10 = nwk_do_attach((nwk_join_req_t *)(iVar11 + 0xac8));
    if (eVar10 == 0) {
      return;
    }
    if (uVar12 == 0xc) {
      return;
    }
  }
  iVar11 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar11 + 0xad3);
  iVar11 = core_globals_get();
  *(undefined1 *)(iVar11 + 0xac0) = 0;
  uStack_2a = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_2c = (undefined1)uVar12;
  uStack_2b = uVar1;
  if (uVar12 == 0) {
    uStack_2a = nwk_get_short_address();
  }
  else {
    uStack_2a = 0xffff;
  }
  puVar9 = (undefined4 *)nwk_get_extended_panid();
  uStack_28 = *puVar9;
  uStack_24 = puVar9[1];
  nwk_join_confirm(&uStack_2c);
  return;
}

