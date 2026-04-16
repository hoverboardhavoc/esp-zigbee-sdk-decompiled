/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_discovery.o -> nwk_handle_active_scan_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_handle_active_scan_result(active_scan_result_t *scan_result,void *user_ctx)

{
  nwk_beacon_info_t *zigbee_beacon;
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  active_scan_result_t *scan_result_00;
  void *user_ctx_00;
  undefined1 auStack_2c [4];
  nwk_potential_parent_t parent;
  ezb_extpanid_t extpanid;
  
  if (((((scan_result->beacon_type == '\0') &&
        (zigbee_beacon = (nwk_beacon_info_t *)scan_result->beacon_payload,
        0xe < scan_result->beacon_payload_length)) && (zigbee_beacon->protocol_id == '\0')) &&
      ((zigbee_beacon->field_0x1 == '\"' &&
       ((iVar2 = core_globals_get(), *(char *)(iVar2 + 0xac8) == '\0' ||
        ((short)(scan_result->pan_descriptor).superframe_spec < 0)))))) &&
     ((iVar2 = core_globals_get(), *(char *)(iVar2 + 0xac9) == '\0' ||
      ((char)zigbee_beacon->field_0x2 < '\0')))) {
    parent.field_7 =
         *(anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7 *)
          &(zigbee_beacon->extended_panid).field_0;
    iVar2 = *(int *)((int)&(zigbee_beacon->extended_panid).field_0 + 4);
    iVar3 = core_globals_get();
    if (*(int *)(iVar3 + 0x9ef) != 0 || *(int *)(iVar3 + 0x9f3) != 0) {
      iVar3 = core_globals_get();
      if (*(anon_union_4_2_657f631f_for_nwk_disc_table_ent_s_7 *)(iVar3 + 0x9ef) != parent.field_7)
      {
        return;
      }
      if (*(int *)(iVar3 + 0x9f3) != iVar2) {
        return;
      }
    }
    uVar4 = nwk_address_add_panid_mapping((scan_result->pan_descriptor).coord_panid,&parent.field_7)
    ;
    if (uVar4 == 0xff) {
      iVar2 = nwk_disc_table_find_weakest_pan((scan_result->pan_descriptor).lqi);
      if (iVar2 == 0xff) {
        return;
      }
      nwk_disc_table_remove_pan();
      uVar4 = nwk_address_add_panid_mapping
                        ((scan_result->pan_descriptor).coord_panid,&parent.field_7);
      if (uVar4 == 0xff) {
        scan_result_00 =
             (active_scan_result_t *)
             __assert_func("//build/esp-zigbee/src/core/nwk/nwk_discovery.c",0x6c,
                           "nwk_handle_active_scan_result","panid_ref != ((nwk_panid_ref_t)(-1))");
        if (scan_result_00 == (active_scan_result_t *)0x0) {
          iVar2 = core_globals_get();
          *(undefined1 *)(iVar2 + 0xac0) = 0;
          nwk_network_discovery_confirm(0);
        }
        else {
          nwk_handle_active_scan_result(scan_result_00,user_ctx_00);
        }
        return;
      }
    }
    parent.panid_ref = '\0';
    parent.lqa = '\0';
    parent.update_id = '\0';
    parent.kn_secrets = '\0';
    parent.addr._4_4_ = uVar4 & 0xff;
    auStack_2c = *(undefined1 (*) [4])&(scan_result->pan_descriptor).coord_addr.u.group_addr;
    parent.addr.group_addr =
         *(ezb_grpaddr_t *)((int)&(scan_result->pan_descriptor).coord_addr.u + 4);
    parent._12_4_ =
         (uint)((scan_result->pan_descriptor).coord_addr.addr_mode == '\x02') << 0x1d |
         (scan_result->iface_id & 0x1f) << 0x18;
    uVar1 = nwk_calculate_lqa_raw
                      ((scan_result->pan_descriptor).lqi,(int)(scan_result->pan_descriptor).rssi);
    parent.addr._5_1_ = uVar1;
    parent._12_4_ =
         parent._12_4_ & 0xbffff000 | (scan_result->pan_descriptor).channel_number & 0x7f |
         ((scan_result->pan_descriptor).channel_page & 0x1f) << 7 |
         (uint)((scan_result->pan_descriptor).superframe_spec >> 0xf) << 0x1e;
    convert_beacon_to_parent((nwk_potential_parent_t *)auStack_2c,zigbee_beacon);
    nwk_disc_table_add_parent((nwk_potential_parent_t *)auStack_2c);
  }
  return;
}

