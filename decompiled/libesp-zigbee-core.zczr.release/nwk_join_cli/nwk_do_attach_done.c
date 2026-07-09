/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_cli.o -> nwk_do_attach_done
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_do_attach_done(int param_1,undefined4 param_2)

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
  uint uVar10;
  short sStack_32;
  short sStack_30;
  ushort uStack_2e;
  undefined1 uStack_2c;
  undefined1 uStack_2b;
  undefined2 uStack_2a;
  undefined4 uStack_28;
  undefined4 uStack_24;
  
  iVar4 = core_globals_get();
  iVar4 = *(int *)(iVar4 + 0xac4);
  if (param_1 == 0) {
    iVar5 = nwk_check_assigned_shortaddr(param_2);
    param_1 = 0x1ec;
    if (iVar5 == 0) {
      iVar5 = core_globals_get();
      *(byte *)(iVar5 + 0xb18) = *(byte *)(iVar5 + 0xb18) | 1;
      nwk_set_short_address(param_2);
      iVar5 = core_globals_get();
      nwk_set_extended_panid(iVar5 + 0xac8);
      iVar5 = core_globals_get();
      *(undefined1 *)(iVar5 + 0x9df) = *(undefined1 *)(iVar4 + 10);
      cVar3 = '\x0f';
      uVar10 = *(uint *)(iVar4 + 0x10) >> 0x14 & 0xf;
      if (uVar10 < 0xe) {
        cVar3 = (char)uVar10 + '\x01';
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
          nwk_mm_get_pib_attr(*(byte *)(iVar4 + 0x13) & 0x1f,0x4b,&uStack_2e,2);
          nwk_mm_get_pib_attr(*(byte *)(iVar4 + 0x13) & 0x1f,0x4a,&uStack_2c,8);
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
      uVar10 = *(uint *)(iVar4 + 0x10);
      *(undefined1 *)(psVar8 + 1) = *(undefined1 *)(iVar4 + 9);
      sVar2 = *(short *)(iVar4 + 0xe);
      *(uint *)(psVar8 + 6) =
           uVar10 >> 0x12 & 0x3f | (uVar10 >> 0x18 & 0x1f) << 0xd |
           *(uint *)(psVar8 + 6) & 0xfffc1c00;
      psVar8[8] = sVar2;
      iVar4 = core_globals_get();
      *(short **)(iVar4 + 0xac4) = psVar8;
      param_1 = 0;
    }
  }
  else {
    nwk_disc_table_delete_parent(iVar4);
    iVar4 = core_globals_get();
    *(undefined4 *)(iVar4 + 0xac4) = 0;
    iVar4 = core_globals_get();
    iVar4 = nwk_do_attach(iVar4 + 0xac8);
    if (iVar4 == 0) {
      return;
    }
    if (param_1 == 0xc) {
      return;
    }
  }
  iVar4 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar4 + 0xad3);
  iVar4 = core_globals_get();
  *(undefined1 *)(iVar4 + 0xac0) = 0;
  uStack_2a = 0;
  uStack_28 = 0;
  uStack_24 = 0;
  uStack_2c = (undefined1)param_1;
  uStack_2b = uVar1;
  if (param_1 == 0) {
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

