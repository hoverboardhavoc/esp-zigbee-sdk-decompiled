/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  nwk_disc_table_lite_ent_t *disc_lite;
  _Bool _Var1;
  byte bVar2;
  ezb_panid_t panid;
  int iVar3;
  nwk_disc_table_lite_ent_t *pnVar4;
  ezb_err_t eVar5;
  undefined3 extraout_var;
  undefined4 uVar6;
  undefined4 uVar7;
  int *piVar8;
  uint uVar9;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  nwk_addr_ref_t ref;
  mac_start_req_t start_req;
  
  iVar3 = core_globals_get();
  if (scan_result != (active_scan_result_t *)0x0) {
    nwk_disc_table_lite_add_pan(&scan_result->pan_descriptor);
    *(uint *)(iVar3 + 0xac8) =
         *(uint *)(iVar3 + 0xac8) & 0xf8000000 |
         *(uint *)(iVar3 + 0xac8) & 0x7ffffff &
         ~(1 << ((scan_result->pan_descriptor).channel_number & 0x1f));
    return;
  }
  pnVar4 = nwk_disc_table_lite_finish();
  if ((*(uint *)(iVar3 + 0xac8) & 0x7ffffff) == 0) {
_L0:
    panid = nwk_get_panid();
    _Var1 = nwk_check_assigned_panid(panid);
    if (CONCAT31(extraout_var,_Var1) == 0) goto _L0;
  }
  else {
    pnVar4->channel_page = (byte)((uint)*(undefined4 *)(iVar3 + 0xac8) >> 0x1b);
    pnVar4->channel_number = 0xff;
    eVar5 = channel_page_get_next_channel
                      (*(channel_page_t *)(iVar3 + 0xac8),&pnVar4->channel_number);
    if (eVar5 == 0) {
      pnVar4->pan_cnt = '\0';
      goto _L0;
    }
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_formation.c",0xd4,
                  "nwk_formation_active_scan_callback",
                  "(channel_page_get_next_channel(form->scan_channels, &disc_lite->channel_number)) == 0"
                 );
_L0:
    nwk_assign_panid();
    nwk_set_panid();
  }
  iVar3 = nwk_is_device_zc();
  if (iVar3 == 0) {
    uVar9 = nwk_get_short_address();
    if ((0xfff7 < uVar9) || (iVar3 = nwk_get_short_address(), iVar3 == 0)) {
      nwk_assign_shortaddr();
      nwk_set_short_address();
    }
  }
  else {
    nwk_set_short_address(0);
  }
  uVar6 = nwk_get_extended_address();
  uVar7 = nwk_get_short_address();
  iVar3 = nwk_address_update(uVar6,uVar7,&uStack_1a);
  if (iVar3 == 0) {
    nwk_address_lock_ref(uStack_1a);
    piVar8 = (int *)nwk_get_extended_panid();
    if ((*piVar8 == 0 && piVar8[1] == 0) || ((*piVar8 == -1 && (piVar8[1] == -1)))) {
      nwk_get_extended_address();
      nwk_set_extended_panid();
    }
    uStack_18 = nwk_get_panid();
    ref._0_1_ = pnVar4->channel_number;
    ref._1_1_ = pnVar4->channel_page;
    bVar2 = nwk_is_device_zc();
    start_req.pan_id._0_1_ = (byte)start_req.pan_id & 0xfe | bVar2 & 1;
    iVar3 = nwk_mm_start_request(0,&uStack_18);
    if (iVar3 == 0) {
      iVar3 = core_globals_get();
      *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) | 1;
      uVar6 = 0;
      goto _L0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_formation.c",0xe8,
                  "nwk_formation_active_scan_callback",
                  "(nwk_address_update(nwk_get_extended_address(), nwk_get_short_address(), &ref)) == 0"
                 );
  }
  iVar3 = core_globals_get();
  *(byte *)(iVar3 + 0xb18) = *(byte *)(iVar3 + 0xb18) & 0xfe;
  uVar6 = 0xc4;
_L0:
  iVar3 = core_globals_get();
  *(undefined1 *)(iVar3 + 0xac0) = 0;
  nwk_network_formation_confirm(uVar6);
  return;
}

