/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_formation.o -> nwk_formation_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_formation_active_scan_callback(active_scan_result_t *scan_result,void *user_ctx)

{
  uint8_t uVar1;
  char cVar2;
  short sVar3;
  short sVar4;
  ezb_panid_t eVar5;
  _Bool _Var6;
  byte bVar7;
  ezb_panid_t eVar8;
  int iVar9;
  int iVar10;
  nwk_disc_table_lite_ent_t *pnVar11;
  nwk_disc_table_lite_ent_t *pnVar12;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined4 uVar13;
  undefined4 uVar14;
  int *piVar15;
  ezb_panid_t *peVar16;
  uint uVar17;
  undefined2 uStack_2a;
  undefined2 uStack_28;
  nwk_addr_ref_t ref;
  mac_start_req_t start_req;
  
  iVar9 = core_globals_get();
  if (scan_result == (active_scan_result_t *)0x0) {
    iVar10 = core_globals_get();
    uVar1 = *(uint8_t *)(iVar10 + 0xba4);
    iVar10 = core_globals_get();
    cVar2 = *(char *)(iVar10 + 0xba4);
    pnVar11 = nwk_disc_table_lite_get_slot(uVar1);
    bVar7 = cVar2 + 1U & 1;
    pnVar12 = nwk_disc_table_lite_get_slot(bVar7);
    if (pnVar12->pan_cnt < pnVar11->pan_cnt) {
      iVar10 = core_globals_get();
      *(byte *)(iVar10 + 0xba4) = bVar7;
    }
    iVar10 = core_globals_get();
    pnVar11 = nwk_disc_table_lite_get_slot(*(uint8_t *)(iVar10 + 0xba4));
    if ((*(uint *)(iVar9 + 0xac8) & 0x7ffffff) != 0) {
      pnVar11->channel_page = (byte)(*(uint *)(iVar9 + 0xac8) >> 0x1b);
      pnVar11->channel_number = 0xff;
      iVar10 = 0;
      if (*(uint *)(iVar9 + 0xac8) < 0x8000000) {
        iVar10 = 10;
      }
      uVar17 = iVar10 + 1;
      while (((*(uint *)(iVar9 + 0xac8) & 0x7ffffff) >> (uVar17 & 0x1f) & 1) == 0) {
        uVar17 = uVar17 + 1;
        if ((uVar17 & 0xff) == 0x1b) goto _L0;
      }
      pnVar11->channel_number = (uint8_t)uVar17;
      pnVar11->pan_cnt = '\0';
    }
    eVar8 = nwk_get_panid();
    _Var6 = nwk_check_assigned_panid(eVar8);
    if (CONCAT31(extraout_var,_Var6) == 0) {
      do {
        eVar8 = random_noncrypto_get_u32();
        _Var6 = nwk_check_assigned_panid(eVar8);
      } while (CONCAT31(extraout_var_00,_Var6) == 0);
      nwk_set_panid(eVar8);
    }
    iVar9 = nwk_is_device_zc();
    if (iVar9 == 0) goto _L0;
    uVar13 = 0;
    do {
      nwk_set_short_address(uVar13);
      do {
        uVar13 = nwk_get_extended_address();
        uVar14 = nwk_get_short_address();
        iVar9 = nwk_address_update(uVar13,uVar14,&uStack_2a);
        if (iVar9 == 0) {
          nwk_address_lock_ref(uStack_2a);
          piVar15 = (int *)nwk_get_extended_panid();
          if ((piVar15[1] + 1U == (uint)(*piVar15 == 0)) && (0xfffffffd < *piVar15 - 1U)) {
            nwk_get_extended_address();
            nwk_set_extended_panid();
          }
          uStack_28 = nwk_get_panid();
          ref._0_1_ = pnVar11->channel_number;
          ref._1_1_ = pnVar11->channel_page;
          bVar7 = nwk_is_device_zc();
          start_req.pan_id._0_1_ = (byte)start_req.pan_id & 0xfe | bVar7 & 1;
          nwk_mm_start_request(0,&uStack_28);
          iVar9 = core_globals_get();
          *(byte *)(iVar9 + 0xb18) = *(byte *)(iVar9 + 0xb18) | 1;
          iVar9 = core_globals_get();
          *(undefined1 *)(iVar9 + 0xac0) = 0;
          nwk_network_formation_confirm(0);
          return;
        }
_L0:
        __assert_func(0,0,0,0);
_L0:
        uVar17 = nwk_get_short_address();
      } while ((uVar17 < 0xfff8) && (iVar9 = nwk_get_short_address(), iVar9 != 0));
      uVar13 = nwk_assign_shortaddr();
    } while( true );
  }
  iVar10 = core_globals_get();
  uVar1 = *(uint8_t *)(iVar10 + 0xba4);
  iVar10 = core_globals_get();
  cVar2 = *(char *)(iVar10 + 0xba4);
  pnVar11 = nwk_disc_table_lite_get_slot(uVar1);
  bVar7 = cVar2 + 1U & 1;
  pnVar12 = nwk_disc_table_lite_get_slot(bVar7);
  sVar3._0_1_ = pnVar12->channel_page;
  sVar3._1_1_ = pnVar12->channel_number;
  sVar4._0_1_ = (scan_result->pan_descriptor).channel_page;
  sVar4._1_1_ = (scan_result->pan_descriptor).channel_number;
  if (sVar3 != sVar4) {
    if (pnVar12->pan_cnt < pnVar11->pan_cnt) {
      iVar10 = core_globals_get();
      *(byte *)(iVar10 + 0xba4) = bVar7;
      pnVar12 = nwk_disc_table_lite_get_slot(bVar7 ^ 1);
    }
    pnVar12->pan_cnt = '\0';
  }
  uVar1 = (scan_result->pan_descriptor).channel_number;
  eVar8 = (scan_result->pan_descriptor).coord_panid;
  peVar16 = pnVar12->panids;
  pnVar12->channel_page = (scan_result->pan_descriptor).channel_page;
  pnVar12->channel_number = uVar1;
  for (uVar17 = 0; uVar17 != pnVar12->pan_cnt; uVar17 = uVar17 + 1 & 0xff) {
    eVar5 = *peVar16;
    peVar16 = peVar16 + 1;
    if (eVar5 == eVar8) goto _L0;
  }
  if (uVar17 < 0x1c) {
    pnVar12->panids[uVar17] = eVar8;
    pnVar12->pan_cnt = (char)uVar17 + '\x01';
  }
  else {
    log_write(2,"nwk_formation.c","Too many PANs on channel: %d:%d");
  }
_L0:
  *(uint *)(iVar9 + 0xac8) =
       *(uint *)(iVar9 + 0xac8) & 0xf8000000 |
       *(uint *)(iVar9 + 0xac8) & 0x7ffffff &
       ~(1 << ((scan_result->pan_descriptor).channel_number & 0x1f));
  return;
}

