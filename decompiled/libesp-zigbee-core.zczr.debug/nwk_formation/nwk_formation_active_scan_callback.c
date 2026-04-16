/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_formation_active_scan_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: start_req */
/* WARNING: Unknown calling convention */

void nwk_formation_active_scan_callback(active_scan_result_t *scan_result,void *user_ctx)

{
  code *pcVar1;
  nwk_disc_table_lite_ent_t *disc_lite;
  _Bool _Var2;
  byte bVar3;
  ezb_panid_t panid;
  int iVar4;
  nwk_disc_table_lite_ent_t *pnVar5;
  ezb_err_t eVar6;
  undefined3 extraout_var;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iStack_40;
  undefined4 uStack_3c;
  code *pcStack_38;
  undefined4 uStack_34;
  nwk_disc_table_lite_ent_t *pnStack_2c;
  undefined4 uStack_28;
  code *pcStack_24;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  nwk_addr_ref_t ref;
  mac_start_req_t start_req;
  
  iVar4 = core_globals_get();
  if (scan_result != (active_scan_result_t *)0x0) {
    nwk_disc_table_lite_add_pan(&scan_result->pan_descriptor);
    *(uint *)(iVar4 + 0xac8) =
         *(uint *)(iVar4 + 0xac8) & 0xf8000000 |
         *(uint *)(iVar4 + 0xac8) & 0x7ffffff &
         ~(1 << ((scan_result->pan_descriptor).channel_number & 0x1f));
    return;
  }
  pnVar5 = nwk_disc_table_lite_finish();
  if ((*(uint *)(iVar4 + 0xac8) & 0x7ffffff) == 0) {
_L0:
    panid = nwk_get_panid();
    _Var2 = nwk_check_assigned_panid(panid);
    if (CONCAT31(extraout_var,_Var2) != 0) goto _L0;
  }
  else {
    pnVar5->channel_page = (byte)((uint)*(undefined4 *)(iVar4 + 0xac8) >> 0x1b);
    pnVar5->channel_number = 0xff;
    eVar6 = channel_page_get_next_channel
                      (*(channel_page_t *)(iVar4 + 0xac8),&pnVar5->channel_number);
    if (eVar6 == 0) {
      pnVar5->pan_cnt = '\0';
      goto _L0;
    }
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_formation.c",0xd2,
                  "nwk_formation_active_scan_callback",
                  "(channel_page_get_next_channel(form->scan_channels, &disc_lite->channel_number)) == 0"
                 );
  }
  nwk_assign_panid();
  nwk_set_panid();
_L0:
  iVar4 = nwk_is_device_zc();
  if (iVar4 == 0) {
    uVar10 = nwk_get_short_address();
    if ((0xfff7 < uVar10) || (iVar4 = nwk_get_short_address(), iVar4 == 0)) {
      nwk_assign_shortaddr();
      nwk_set_short_address();
    }
  }
  else {
    nwk_set_short_address(0);
  }
  uVar7 = nwk_get_extended_address();
  uVar8 = nwk_get_short_address();
  iVar4 = nwk_address_update(uVar7,uVar8,&uStack_1a);
  if (iVar4 == 0) {
    nwk_address_lock_ref(uStack_1a);
    piVar9 = (int *)nwk_get_extended_panid();
    if ((*piVar9 == 0 && piVar9[1] == 0) || ((*piVar9 == -1 && (piVar9[1] == -1)))) {
      nwk_get_extended_address();
      nwk_set_extended_panid();
    }
    uStack_18 = nwk_get_panid();
    ref._0_1_ = pnVar5->channel_number;
    ref._1_1_ = pnVar5->channel_page;
    bVar3 = nwk_is_device_zc();
    start_req.pan_id._0_1_ = (byte)start_req.pan_id & 0xfe | bVar3 & 1;
    nwk_mm_start_request(0,&uStack_18);
    iVar4 = core_globals_get();
    *(byte *)(iVar4 + 0xb18) = *(byte *)(iVar4 + 0xb18) | 1;
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xac0) = 0;
    nwk_network_formation_confirm(0);
    return;
  }
  pcVar1 = nwk_network_formation_request;
  puVar11 = (undefined4 *)
            __assert_func("//build/esp-zigbee/src/core/nwk/nwk_formation.c",0xe6,
                          "nwk_formation_active_scan_callback",
                          "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &ref)) == 0"
                         );
  if (((((puVar11 != (undefined4 *)0x0) &&
        (pnStack_2c = pnVar5, uStack_28 = uVar7, pcStack_24 = pcVar1, iVar4 = core_globals_get(),
        *(char *)(iVar4 + 0xac0) == '\0')) && (iVar4 = nwk_is_joined(), iVar4 == 0)) &&
      (iVar4 = nwk_is_device_zczr(), iVar4 != 0)) &&
     ((((uint)puVar11[1] >> 0x19 & 1) != 0 || (iVar4 = nwk_is_device_zc(), iVar4 != 0)))) {
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xac0) = 3;
    iVar4 = core_globals_get();
    nwk_formation_reset_tmp_ctx((form_tmp_s *)(iVar4 + 0xac8));
    iVar4 = core_globals_get();
    *(undefined1 *)(iVar4 + 0xacc) = *(undefined1 *)(puVar11 + 1);
    iVar4 = core_globals_get();
    *(byte *)(iVar4 + 0xad1) =
         *(byte *)(iVar4 + 0xad1) & 0xfe | (byte)((uint)puVar11[1] >> 0x19) & 1;
    uStack_34 = 0;
    iStack_40 = (uint)*(byte *)(puVar11 + 1) << 8;
    uStack_3c = *puVar11;
    pcStack_38 = nwk_formation_ed_scan_callback;
    nwk_mm_scan_request(0,&iStack_40);
  }
  return;
}

