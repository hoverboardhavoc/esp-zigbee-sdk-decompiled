/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_formation_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_formation_active_scan_callback(int param_1)

{
  undefined1 uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  byte bVar5;
  undefined2 uVar6;
  int iVar7;
  int iVar8;
  short *psVar9;
  int iVar10;
  byte *pbVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int *piVar14;
  short *psVar15;
  uint uVar16;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  byte bStack_26;
  byte bStack_25;
  byte bStack_24;
  
  iVar7 = core_globals_get();
  if (param_1 == 0) {
    iVar8 = core_globals_get();
    uVar1 = *(undefined1 *)(iVar8 + 0xba4);
    iVar8 = core_globals_get();
    cVar2 = *(char *)(iVar8 + 0xba4);
    iVar8 = nwk_disc_table_lite_get_slot(uVar1);
    bVar5 = cVar2 + 1U & 1;
    iVar10 = nwk_disc_table_lite_get_slot(bVar5);
    if (*(byte *)(iVar10 + 2) < *(byte *)(iVar8 + 2)) {
      iVar8 = core_globals_get();
      *(byte *)(iVar8 + 0xba4) = bVar5;
    }
    iVar8 = core_globals_get();
    pbVar11 = (byte *)nwk_disc_table_lite_get_slot(*(undefined1 *)(iVar8 + 0xba4));
    if ((*(uint *)(iVar7 + 0xac8) & 0x7ffffff) != 0) {
      *pbVar11 = (byte)(*(uint *)(iVar7 + 0xac8) >> 0x1b);
      pbVar11[1] = 0xff;
      iVar8 = 0;
      if (*(uint *)(iVar7 + 0xac8) < 0x8000000) {
        iVar8 = 10;
      }
      uVar16 = iVar8 + 1;
      while (((*(uint *)(iVar7 + 0xac8) & 0x7ffffff) >> (uVar16 & 0x1f) & 1) == 0) {
        uVar16 = uVar16 + 1;
        if ((uVar16 & 0xff) == 0x1b) goto _L0;
      }
      pbVar11[1] = (byte)uVar16;
      pbVar11[2] = 0;
    }
    nwk_get_panid();
    iVar7 = nwk_check_assigned_panid();
    if (iVar7 == 0) {
      do {
        uVar6 = random_noncrypto_get_u32();
        iVar7 = nwk_check_assigned_panid(uVar6);
      } while (iVar7 == 0);
      nwk_set_panid(uVar6);
    }
    iVar7 = nwk_is_device_zc();
    if (iVar7 == 0) goto _L0;
    uVar12 = 0;
    do {
      nwk_set_short_address(uVar12);
      do {
        uVar12 = nwk_get_extended_address();
        uVar13 = nwk_get_short_address();
        iVar7 = nwk_address_update(uVar12,uVar13,&uStack_2a);
        if (iVar7 == 0) {
          nwk_address_lock_ref(uStack_2a);
          piVar14 = (int *)nwk_get_extended_panid();
          if ((piVar14[1] + 1U == (uint)(*piVar14 == 0)) && (0xfffffffd < *piVar14 - 1U)) {
            nwk_get_extended_address();
            nwk_set_extended_panid();
          }
          uStack_28 = nwk_get_panid();
          bStack_26 = pbVar11[1];
          bStack_25 = *pbVar11;
          bVar5 = nwk_is_device_zc();
          bStack_24 = bStack_24 & 0xfe | bVar5 & 1;
          iVar7 = nwk_mm_start_request(0,&uStack_28);
          if (iVar7 == 0) {
            iVar7 = core_globals_get();
            uVar12 = 0;
            *(byte *)(iVar7 + 0xb18) = *(byte *)(iVar7 + 0xb18) | 1;
          }
          else {
            iVar7 = core_globals_get();
            uVar12 = 0xc4;
            *(byte *)(iVar7 + 0xb18) = *(byte *)(iVar7 + 0xb18) & 0xfe;
          }
          iVar7 = core_globals_get();
          *(undefined1 *)(iVar7 + 0xac0) = 0;
          nwk_network_formation_confirm(uVar12);
          return;
        }
_L0:
        __assert_func(0,0,0,0);
_L0:
        uVar16 = nwk_get_short_address();
      } while ((uVar16 < 0xfff8) && (iVar7 = nwk_get_short_address(), iVar7 != 0));
      uVar12 = nwk_assign_shortaddr();
    } while( true );
  }
  iVar8 = core_globals_get();
  uVar1 = *(undefined1 *)(iVar8 + 0xba4);
  iVar8 = core_globals_get();
  cVar2 = *(char *)(iVar8 + 0xba4);
  iVar8 = nwk_disc_table_lite_get_slot(uVar1);
  bVar5 = cVar2 + 1U & 1;
  psVar9 = (short *)nwk_disc_table_lite_get_slot(bVar5);
  if (*psVar9 != *(short *)(param_1 + 0x10)) {
    if (*(byte *)(psVar9 + 1) < *(byte *)(iVar8 + 2)) {
      iVar8 = core_globals_get();
      *(byte *)(iVar8 + 0xba4) = bVar5;
      psVar9 = (short *)nwk_disc_table_lite_get_slot(bVar5 ^ 1);
    }
    *(undefined1 *)(psVar9 + 1) = 0;
  }
  uVar1 = *(undefined1 *)(param_1 + 0x11);
  sVar3 = *(short *)(param_1 + 0xe);
  psVar15 = psVar9 + 2;
  *(undefined1 *)psVar9 = *(undefined1 *)(param_1 + 0x10);
  *(undefined1 *)((int)psVar9 + 1) = uVar1;
  for (uVar16 = 0; uVar16 != *(byte *)(psVar9 + 1); uVar16 = uVar16 + 1 & 0xff) {
    sVar4 = *psVar15;
    psVar15 = psVar15 + 1;
    if (sVar4 == sVar3) goto _L0;
  }
  if (uVar16 < 0x1c) {
    psVar9[uVar16 + 2] = sVar3;
    *(char *)(psVar9 + 1) = (char)uVar16 + '\x01';
  }
  else {
    log_write(2,"nwk_formation.c","Too many PANs on channel: %d:%d");
  }
_L0:
  *(uint *)(iVar7 + 0xac8) =
       *(uint *)(iVar7 + 0xac8) & 0xf8000000 |
       *(uint *)(iVar7 + 0xac8) & 0x7ffffff & ~(1 << (*(byte *)(param_1 + 0x11) & 0x1f));
  return;
}

